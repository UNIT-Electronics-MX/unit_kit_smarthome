#!/usr/bin/env python3
"""Publish the original PDF pages as a readable web manual with local assets."""

import argparse
from html import escape
from pathlib import Path
import re
import shutil

PAGE_COUNT = 80
PAGE_WIDTH = 1275
PAGE_HEIGHT = 1650
PDF_NAME = "unit_product_reference_v_1_1_0_kit_smarthome.pdf"


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("source_images", type=Path)
    parser.add_argument("source_text", type=Path)
    parser.add_argument("output_html", type=Path)
    args = parser.parse_args()

    images = sorted(args.source_images.glob("manual-*.jpg"))
    if len(images) != PAGE_COUNT:
        raise ValueError(f"expected {PAGE_COUNT} PDF pages, found {len(images)}")
    image_numbers = [int(re.search(r"manual-(\d+)\.jpg$", image.name).group(1)) for image in images]
    if image_numbers != list(range(1, PAGE_COUNT + 1)):
        raise ValueError("PDF page images are missing or out of order")

    pages_text = args.source_text.read_text(encoding="utf-8").split("\f")
    if pages_text[-1].strip() == "":
        pages_text.pop()
    if len(pages_text) != PAGE_COUNT:
        raise ValueError(f"expected text for {PAGE_COUNT} PDF pages, found {len(pages_text)}")

    asset_dir = args.output_html.parent / "assets" / "pages"
    if asset_dir.exists():
        shutil.rmtree(asset_dir)
    asset_dir.mkdir(parents=True)

    pages = []
    for number, (image, page_text) in enumerate(zip(images, pages_text), 1):
        filename = f"page-{number:03d}.jpg"
        shutil.copy2(image, asset_dir / filename)
        pages.append(
            f'<section class="page" id="pagina-{number}" aria-label="Página {number}">'
            f'<img src="assets/pages/{filename}" width="{PAGE_WIDTH}" height="{PAGE_HEIGHT}" '
            f'alt="Página {number} del Manual de usuario - Kit SmartHome" loading="lazy" decoding="async">'
            f'<span class="page-text">{escape(page_text.strip())}</span>'
            '</section>'
        )

    title = "Manual de usuario - Kit SmartHome"
    html = f'''<!doctype html>
<html lang="es-MX">
<head>
<meta charset="utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>{title}</title>
<style>
  * {{ box-sizing: border-box; }}
  html {{ scroll-behavior: smooth; }}
  body {{ margin: 0; background: #e9edf0; color: #172536; font: 16px/1.4 Arial, sans-serif; }}
  .toolbar {{ position: sticky; top: 0; z-index: 2; display: flex; align-items: center;
    justify-content: space-between; gap: 12px; padding: 12px 20px; background: white;
    box-shadow: 0 1px 6px #0002; }}
  .toolbar nav {{ display: flex; gap: 16px; flex-wrap: wrap; }}
  .toolbar a {{ color: #a93f0b; }}
  main {{ padding: 20px 16px; }}
  .page {{ position: relative; width: min(100%, {PAGE_WIDTH}px); margin: 0 auto 22px;
    background: white; box-shadow: 0 2px 12px #0002; scroll-margin-top: 68px; }}
  .page img {{ display: block; width: 100%; height: auto; }}
  .page-text {{ position: absolute; width: 1px; height: 1px; padding: 0; margin: -1px;
    overflow: hidden; clip: rect(0, 0, 0, 0); white-space: pre-wrap; border: 0; }}
  @media (max-width: 560px) {{ .toolbar {{ font-size: 14px; padding: 10px 12px; }}
    main {{ padding: 12px 8px; }} .page {{ margin-bottom: 12px; }} }}
  @media print {{ body {{ background: white; }} .toolbar {{ display: none; }}
    main {{ padding: 0; }} .page {{ width: 100%; margin: 0; box-shadow: none;
      break-after: page; }} .page:last-child {{ break-after: auto; }} }}
</style>
</head>
<body>
<header class="toolbar"><strong>{title}</strong><nav><a href="manual-editable.html">Versión editable</a> <a href="{PDF_NAME}">Descargar PDF</a></nav></header>
<main aria-label="Manual de usuario completo">
{chr(10).join(pages)}
</main>
</body>
</html>
'''
    args.output_html.write_text(html, encoding="utf-8")
    print(f"Prepared {PAGE_COUNT} original-layout pages with local images: {args.output_html}")


if __name__ == "__main__":
    main()
