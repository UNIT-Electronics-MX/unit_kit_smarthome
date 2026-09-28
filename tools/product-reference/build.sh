#!/usr/bin/env bash
set -euo pipefail

PROJECT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
SOURCE_DIR="$PROJECT_DIR/tools/product-reference"
SOURCE_PDF="$SOURCE_DIR/assets/I2D-Manual de usuario - Kit SmartHome-280926-171843.pdf"
OUTPUT_DIR="${1:-$PROJECT_DIR/build/product-reference}"
OUTPUT_BASENAME="unit_product_reference_v_1_1_0_kit_smarthome"

for command in pdftoppm pdftotext python3; do
  if ! command -v "$command" >/dev/null 2>&1; then
    echo "Error: required command not found: $command" >&2
    exit 1
  fi
done
if [[ ! -s "$SOURCE_PDF" ]]; then
  echo "Error: source user manual not found: $SOURCE_PDF" >&2
  exit 1
fi

mkdir -p "$OUTPUT_DIR/assets"
TEMP_DIR="$(mktemp -d)"
trap 'rm -rf "$TEMP_DIR"' EXIT

pdftoppm -jpeg -jpegopt quality=90 -r 150 "$SOURCE_PDF" "$TEMP_DIR/manual"
pdftotext -layout "$SOURCE_PDF" "$TEMP_DIR/manual.txt"
python3 "$SOURCE_DIR/prepare-manual-html.py" \
  "$TEMP_DIR" "$TEMP_DIR/manual.txt" "$OUTPUT_DIR/$OUTPUT_BASENAME.html"
cp "$SOURCE_PDF" "$OUTPUT_DIR/$OUTPUT_BASENAME.pdf"
cp -R "$SOURCE_DIR/assets/manual" "$OUTPUT_DIR/assets/"

# Remove outputs from the superseded reference build on repeated local builds.
rm -f "$OUTPUT_DIR/$OUTPUT_BASENAME.docx" \
  "$OUTPUT_DIR/$OUTPUT_BASENAME.md" \
  "$OUTPUT_DIR/manual-figures.html" \
  "$OUTPUT_DIR/product-reference.css"

echo "Kit SmartHome user manual built successfully:"
echo "  HTML: $OUTPUT_DIR/$OUTPUT_BASENAME.html"
echo "  PDF:  $OUTPUT_DIR/$OUTPUT_BASENAME.pdf"
echo "  Page images: $OUTPUT_DIR/assets/pages/"
echo "  Extracted figures: $OUTPUT_DIR/assets/manual/"
