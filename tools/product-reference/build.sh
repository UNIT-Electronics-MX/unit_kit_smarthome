#!/usr/bin/env bash
set -euo pipefail

PROJECT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
SOURCE_DIR="$PROJECT_DIR/tools/product-reference"
SOURCE_PDF="$SOURCE_DIR/assets/I2D-Manual de usuario - Kit SmartHome-280926-171843.pdf"
BOOK_FILE="$SOURCE_DIR/book.yml"
REFERENCE_DOC="$SOURCE_DIR/reference-a4.docx"
HTML_TEMPLATE="$SOURCE_DIR/templates/product-reference.html"
HTML_STYLESHEET="$SOURCE_DIR/styles/product-reference.css"
OUTPUT_DIR="${1:-$PROJECT_DIR/build/product-reference}"
OUTPUT_BASENAME="unit_product_reference_v_1_1_0_kit_smarthome"

for command in pdftoppm pdftotext pandoc python3; do
  if ! command -v "$command" >/dev/null 2>&1; then
    echo "Error: required command not found: $command" >&2
    exit 1
  fi
done
for source in "$SOURCE_PDF" "$BOOK_FILE" "$REFERENCE_DOC" "$HTML_TEMPLATE" "$HTML_STYLESHEET"; do
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
  echo "Error: book.yml does not list any editable chapters." >&2
  exit 1
fi
CHAPTER_PATHS=()
for chapter in "${CHAPTERS[@]}"; do
  if [[ ! -s "$PROJECT_DIR/$chapter" ]]; then
    echo "Error: editable chapter not found: $chapter" >&2
    exit 1
  fi
  CHAPTER_PATHS+=("$PROJECT_DIR/$chapter")
done

mkdir -p "$OUTPUT_DIR/assets"
TEMP_DIR="$(mktemp -d)"
trap 'rm -rf "$TEMP_DIR"' EXIT

# The original PDF remains visually unchanged in the main web view.
pdftoppm -jpeg -jpegopt quality=90 -r 150 "$SOURCE_PDF" "$TEMP_DIR/manual"
pdftotext -layout "$SOURCE_PDF" "$TEMP_DIR/manual.txt"
python3 "$SOURCE_DIR/prepare-manual-html.py" \
  "$TEMP_DIR" "$TEMP_DIR/manual.txt" "$OUTPUT_DIR/$OUTPUT_BASENAME.html"
cp "$SOURCE_PDF" "$OUTPUT_DIR/$OUTPUT_BASENAME.pdf"
cp -R "$SOURCE_DIR/assets/manual" "$OUTPUT_DIR/assets/"

# The Markdown chapters and DOCX template provide an editable manual.
cp "$HTML_STYLESHEET" "$OUTPUT_DIR/manual-editable.css"
pandoc --from=markdown --to=html5 --standalone --toc --toc-depth=2 \
  --metadata-file="$BOOK_FILE" --template="$HTML_TEMPLATE" \
  --css=manual-editable.css --resource-path="$SOURCE_DIR" \
  "${CHAPTER_PATHS[@]}" --output="$OUTPUT_DIR/manual-editable.html"
pandoc --from=markdown --to=docx --standalone \
  --metadata-file="$BOOK_FILE" --reference-doc="$REFERENCE_DOC" \
  --resource-path="$SOURCE_DIR" "${CHAPTER_PATHS[@]}" \
  --output="$OUTPUT_DIR/manual-editable.docx"

# Remove files from the superseded reference build on repeated local builds.
rm -f "$OUTPUT_DIR/$OUTPUT_BASENAME.docx" \
  "$OUTPUT_DIR/$OUTPUT_BASENAME.md" \
  "$OUTPUT_DIR/manual-figures.html" \
  "$OUTPUT_DIR/product-reference.css"

echo "Kit SmartHome user manual built successfully:"
echo "  Original layout: $OUTPUT_DIR/$OUTPUT_BASENAME.html"
echo "  Editable HTML:  $OUTPUT_DIR/manual-editable.html"
echo "  Editable DOCX:  $OUTPUT_DIR/manual-editable.docx"
echo "  Original PDF:   $OUTPUT_DIR/$OUTPUT_BASENAME.pdf"
