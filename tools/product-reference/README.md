# Kit SmartHome Product Reference

The source is the 80-page `I2D-Manual de usuario - Kit SmartHome-280926-171843.pdf`
under `assets/`. The condensed Spanish reference is maintained in `chapters/`;
`book.yml` controls its title, version, and chapter order.

## Build

Requirements: Pandoc, Python 3 with Pillow, and WeasyPrint (or Chromium).
From the repository root:

```bash
./tools/product-reference/build.sh /tmp/smarthome-product-reference
```

The output directory contains Markdown, DOCX, HTML, PDF, `manual-figures.html`,
`product-reference.css`, and `assets/`. The HTML and gallery load local assets.
Publish the entire output directory so their relative links continue to work.
The publishing script places it under `docs/hardware/product-reference/` and
adds links to the hardware resources page.

## Image sources

`assets/manual/` contains all 304 image objects extracted from the source PDF
with `pdfimages -all`, including two transparency masks. `manifest.tsv` maps
each filename to its PDF page and image number. When replacing the source PDF,
regenerate both images and manifest in the same order; then check the selected
figure references in the chapters and cover. The gallery is generated at build
time from this manifest.

The manual states an assembled size of 18 × 15 × 19 cm, while the repository
README states 16 × 15 × 19 cm. The reference reports this discrepancy instead
of silently choosing a manufacturing dimension.
