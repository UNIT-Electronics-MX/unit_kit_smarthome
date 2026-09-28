# Kit SmartHome Product Reference

`chapters/10-manual-migrado.md` contains the complete text and 302 illustrations
from the 80-page Kit SmartHome user manual V1.1.0. Text and figures follow their
original PDF page order. Chapters 1–9 provide topic-based reference tables and
entry points into that migrated content. The source PDF remains under `assets/`
for traceability; it is not required to read the migrated manual on the site.

The document title, version, and chapter order are defined in `book.yml`.

## Build

Requirements: Pandoc, Python 3 with Pillow, and WeasyPrint (or Chromium).
From the repository root:

```bash
./tools/product-reference/build.sh /tmp/smarthome-product-reference
```

The output directory contains Markdown, DOCX, HTML, PDF, `manual-figures.html`,
`product-reference.css`, and `assets/`. Publish the entire output directory so
the HTML and gallery can load their local images. The publishing workflow places
it under `docs/hardware/product-reference/` and links it from the hardware page.

## Source and image maintenance

`assets/manual/` contains all 304 image objects extracted from the source PDF
with `pdfimages -all`. Two are transparency masks; the remaining 302 appear in
the migrated chapter. `manifest.tsv` maps each filename to its PDF page and
image number.

To regenerate the migrated chapter after changing the source PDF, install
`poppler-utils` and Pillow, re-extract the images and manifest, then run:

```bash
python3 tools/product-reference/migrate-manual.py \
  'tools/product-reference/assets/I2D-Manual de usuario - Kit SmartHome-280926-171843.pdf' \
  tools/product-reference/assets/manual/manifest.tsv \
  tools/product-reference/chapters/10-manual-migrado.md
```

Review the regenerated Markdown before publishing. The extraction preserves
page order and all text blocks, but a PDF's table line breaks can require
editorial cleanup. The standalone figure gallery is generated at build time.

The manual states an assembled size of 18 × 15 × 19 cm, while the repository
README states 16 × 15 × 19 cm. The reference reports this discrepancy instead
of silently choosing a manufacturing dimension.
