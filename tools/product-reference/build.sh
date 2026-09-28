#!/usr/bin/env bash
set -euo pipefail

PROJECT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
SOURCE_DIR="$PROJECT_DIR/tools/product-reference"
BOOK_FILE="$SOURCE_DIR/book.yml"
REFERENCE_DOC="$SOURCE_DIR/reference-a4.docx"
HTML_TEMPLATE="$SOURCE_DIR/templates/product-reference.html"
HTML_STYLESHEET="$SOURCE_DIR/styles/product-reference.css"
OUTPUT_DIR="${1:-$PROJECT_DIR/build/product-reference}"
OUTPUT_BASENAME="unit_product_reference_v_1_1_0_kit_smarthome"

BROWSER=""
for candidate in google-chrome chromium chromium-browser; do
  if command -v "$candidate" >/dev/null 2>&1; then
    BROWSER="$candidate"
    break
  fi
done
if [[ -z "$BROWSER" ]]; then
  echo "Error: Google Chrome or Chromium is required to render the PDF." >&2
  exit 1
fi
for command in pandoc python3 pdfinfo; do
  if ! command -v "$command" >/dev/null 2>&1; then
    echo "Error: required command not found: $command" >&2
    exit 1
  fi
done
for source in "$BOOK_FILE" "$REFERENCE_DOC" "$HTML_TEMPLATE" "$HTML_STYLESHEET"; do
  if [[ ! -s "$source" ]]; then
    echo "Error: required manual source not found: $source" >&2
    exit 1
  fi
done

mapfile -t CHAPTERS < <(
  awk '
    /^chapters:/ { in_chapters=1; next }
    in_chapters && /^---/ { exit }
    in_chapters && /^  - / { sub(/^  - /, ""); print }
  ' "$BOOK_FILE"
)
if [[ "${#CHAPTERS[@]}" -eq 0 ]]; then
  echo "Error: book.yml does not list any manual chapters." >&2
  exit 1
fi
CHAPTER_PATHS=()
for chapter in "${CHAPTERS[@]}"; do
  if [[ ! -s "$PROJECT_DIR/$chapter" ]]; then
    echo "Error: manual chapter not found: $chapter" >&2
    exit 1
  fi
  CHAPTER_PATHS+=("$PROJECT_DIR/$chapter")
done

mkdir -p "$OUTPUT_DIR/assets"
cp -R "$SOURCE_DIR/assets/manual" "$OUTPUT_DIR/assets/"
cp "$HTML_STYLESHEET" "$OUTPUT_DIR/manual-editable.css"

HTML_FILE="$OUTPUT_DIR/$OUTPUT_BASENAME.html"
PDF_FILE="$OUTPUT_DIR/$OUTPUT_BASENAME.pdf"
DOCX_FILE="$OUTPUT_DIR/manual-editable.docx"
pandoc --from=markdown --to=html5 --standalone \
  --metadata-file="$BOOK_FILE" --template="$HTML_TEMPLATE" \
  --css=manual-editable.css --resource-path="$SOURCE_DIR" \
  "${CHAPTER_PATHS[@]}" --output="$HTML_FILE"
pandoc --from=markdown --to=docx --standalone \
  --metadata-file="$BOOK_FILE" --reference-doc="$REFERENCE_DOC" \
  --resource-path="$SOURCE_DIR" "${CHAPTER_PATHS[@]}" \
  --output="$DOCX_FILE"
python3 "$SOURCE_DIR/normalize-docx.py" "$DOCX_FILE" "$BOOK_FILE"

# Keep the earlier editable URL working; the main page now uses the same source.
cp "$HTML_FILE" "$OUTPUT_DIR/manual-editable.html"

BROWSER_LOG="$(mktemp)"
trap 'rm -f "$BROWSER_LOG"' EXIT
"$BROWSER" --headless --no-sandbox --disable-gpu --disable-dev-shm-usage \
  --no-pdf-header-footer --print-to-pdf="$PDF_FILE" \
  "file://$(realpath "$HTML_FILE")" >"$BROWSER_LOG" 2>&1 || {
    cat "$BROWSER_LOG" >&2
    exit 1
  }
if [[ ! -s "$PDF_FILE" ]]; then
  cat "$BROWSER_LOG" >&2
  echo "Error: the browser did not render the manual PDF." >&2
  exit 1
fi
python3 "$SOURCE_DIR/normalize-pdf.py" "$PDF_FILE" "$BOOK_FILE"

# Remove files from previous builds so they cannot be published accidentally.
rm -rf "$OUTPUT_DIR/assets/pages"
rm -f "$OUTPUT_DIR/$OUTPUT_BASENAME.docx" \
  "$OUTPUT_DIR/$OUTPUT_BASENAME.md" \
  "$OUTPUT_DIR/manual-figures.html" \
  "$OUTPUT_DIR/product-reference.css"

echo "Kit SmartHome user manual built from ${#CHAPTERS[@]} chapter(s):"
echo "  HTML: $HTML_FILE"
echo "  PDF:  $PDF_FILE"
echo "  DOCX: $DOCX_FILE"
echo "  Images: $OUTPUT_DIR/assets/manual/"
