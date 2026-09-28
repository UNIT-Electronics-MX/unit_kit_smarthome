#!/usr/bin/env python3
"""Add every manual illustration to the product reference in PDF page order."""

import csv
from pathlib import Path
import sys

from PIL import Image


SECTIONS = (
    (1, 11, "Vistas e inventario"),
    (12, 46, "Ensamble mecánico y electrónico"),
    (47, 69, "Cableado y diagramas"),
    (70, 78, "Firmware y aplicación"),
    (79, 80, "Recursos y dimensiones"),
)


def figure_width(width: int, page: int) -> str:
    if width >= 500 and page >= 66:
        return "5.8in"
    if width >= 350:
        return "3.3in"
    if width >= 200:
        return "2.0in"
    if width >= 100:
        return "1.1in"
    return "0.65in"


def main() -> None:
    manifest = Path(sys.argv[1])
    output = Path(sys.argv[2])
    rows = list(csv.DictReader(manifest.open(encoding="utf-8"), delimiter="\t"))
    source_dir = manifest.parent
    sections = []
    current_section = None
    current_page = None
    image_count = 0
    mask_count = 0
    for row in rows:
        page = int(row["pdf_page"])
        number = int(row["image_number"])
        kind = row["type"]
        image_path = source_dir / row["filename"]
        if not image_path.is_file():
            raise FileNotFoundError(image_path)
        if kind == "smask":
            mask_count += 1
            continue
        group = next((title for start, end, title in SECTIONS if start <= page <= end), None)
        if group is None:
            raise ValueError(f"page {page} is outside the section map")
        if group != current_section:
            sections.extend((f"### {group}", ""))
            current_section = group
        if page != current_page:
            sections.extend((f"#### Página {page} del manual", ""))
            current_page = page
        with Image.open(image_path) as image:
            width = figure_width(image.width, page)
        relative_path = f"assets/manual/{row['filename']}"
        caption = f"Manual de usuario, página {page}, imagen {number}"
        sections.extend((f"![{caption}]({relative_path}){{width={width}}}", ""))
        image_count += 1
    if image_count + mask_count != len(rows):
        raise ValueError("the image manifest contains unsupported rows")
    preface = [
        "## 10. Atlas de imágenes del manual",
        "",
        f"Las {image_count} imágenes del manual se reproducen a continuación en el orden de sus páginas originales. "
        "Las figuras principales también aparecen a mayor tamaño en los capítulos anteriores. "
        "Abra la [galería de figuras](manual-figures.html) para consultar cada archivo por separado.",
        "",
        f"El PDF contiene además {mask_count} máscaras de transparencia; se conservan en `assets/manual/` "
        "pero no son ilustraciones independientes.",
        "",
    ]
    output.write_text("\n".join(preface + sections), encoding="utf-8")
    print(f"Added {image_count} manual images to the reference atlas ({mask_count} masks retained as assets).")


if __name__ == "__main__":
    main()
