# Manual de usuario - Kit SmartHome

The source of this manual page is the supplied 80-page user manual PDF in `assets/`.
The build retains its portrait pages, sections, tables, images, and page order.
The HTML displays each complete page image with extracted text for accessibility; the downloadable
PDF is an exact copy of the source manual.

Build from the repository root:

```bash
./tools/product-reference/build.sh /tmp/smarthome-user-manual
```

Requirements: Python 3 plus `pdftoppm` and `pdftotext` from poppler-utils. The output contains
HTML, PDF, and local images under `assets/pages/` and `assets/manual/`. Publish
the whole output directory to preserve relative image links. The workflow places
it under `docs/hardware/product-reference/` and links the HTML and PDF from the
hardware resources page.

`assets/manual/` contains all 304 image objects extracted from the PDF with
`pdfimages -all`, including two transparency masks. `manifest.tsv` records the
original page and image number. The HTML uses locally generated page images to
preserve the manual's table layout and the orientation of the original pages.
