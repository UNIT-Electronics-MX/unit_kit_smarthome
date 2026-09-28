# Product Reference build

The Kit SmartHome user manual is maintained in Markdown under `chapters/`.
Document metadata and chapter order are defined in `book.yml`. The images in
`assets/manual/` are referenced relative to this directory.

## Local validation build

Requirements:

- Pandoc
- Python 3 with Pillow
- WeasyPrint

Run from the repository root and direct validation output outside the
repository:

```bash
./tools/product-reference/build.sh /tmp/smarthome-product-reference
```

The build produces:

```text
unit_product_reference_v_1_1_0_kit_smarthome.md
unit_product_reference_v_1_1_0_kit_smarthome.docx
unit_product_reference_v_1_1_0_kit_smarthome.html
unit_product_reference_v_1_1_0_kit_smarthome.pdf
```

The build prepares temporary PNG/JPEG copies with a maximum dimension of
2400 pixels for DOCX, HTML, and PDF output. This prevents oversized hardware
exports from exceeding Pillow's image-loading limit in WeasyPrint. Original
files in `assets/manual/` remain unchanged. The preprocessing step accepts
source images up to 200 million pixels and reports the asset path if an image
cannot be read. WeasyPrint rendering errors fail the build so incomplete PDFs
are not published.

GitHub Actions publishes the PDF and DOCX under `docs/hardware/`. Do not edit
generated documents or `docs/` manually.

The Markdown chapters are the source of truth for the manual. The HTML/PDF
cover and contents page come from `templates/product-reference.html`, following
the PULSAR RP2350A Product Reference layout. `chapters/00-portada.md` provides
the equivalent opening content for the editable Markdown and DOCX outputs.
