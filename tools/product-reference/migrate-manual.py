#!/usr/bin/env python3
"""Migrate every PDF text block and illustration into editable Markdown."""

import argparse
from collections import defaultdict
import csv
from hashlib import sha256
from html import unescape
from pathlib import Path
import re
import subprocess
import tempfile
import xml.etree.ElementTree as ET

from PIL import Image


XHTML = "{http://www.w3.org/1999/xhtml}"
GROUPS = (
    (1, 9, "Presentación, componentes e inventario"),
    (10, 46, "Ensamble"),
    (47, 68, "Conexiones y ensamble final"),
    (69, 78, "Puesta en marcha"),
    (79, 80, "Recursos y dimensiones"),
)

# The PDF breaks folio numbers and table cells across text blocks. Rebuild these
# rows from the visible source table; image N+3 is the picture for folio KSHN.
INVENTORY = (
    ("M2x8 queso ranurada", "12"),
    ("M2.5x8 queso ranurada", "23"),
    ("M3x6 queso ranurada", "6"),
    ("M3x8 queso ranurada", "18"),
    ("M3x10 queso ranurada", "5"),
    ("M3x5+6 separador latón", "4"),
    ("M2 tuerca", "16"),
    ("M2.5 tuerca", "41"),
    ("M3 tuerca", "33"),
    ("UNIT DualMCU ONE", "1"),
    ("SG90 Servomotor", "1"),
    ("KY-006 Buzzer", "1"),
    ("KY-026 Sensor de flama", "1"),
    ("FC-37 Sensor de lluvia", "1"),
    ("AHT10 Sensor de temperatura y humedad", "1"),
    ("SSD1315 Pantalla OLED", "1"),
    ("KY-018 Fotorresistor", "1"),
    ("WS2812 Neopixel", "3"),
    ("RC522 Sensor RFID", "1"),
    ("HX1838 Sensor IR", "1"),
    ("TTP223B Botón Capacitivo", "1"),
    ("KY-040 Encoder", "1"),
    ("UNIT Módulo Hub I2C QW/ST", "1"),
    ("HC-SR505 PIR", "1"),
    ("Motor DC con Hélice", "1"),
    ("MX1508 Puente H", "1"),
    ("PCA9685", "1"),
    ("Sensor Shield V5.0 UNO R3", "1"),
    ("Eliminador 12V 2A Jack", "1"),
    ("Cable Qwiic - Qwiic 10 cm", "1"),
    ("Cable Qwiic - Dupont Hembra 20 cm", "3"),
    ("Cable Dupont H-H 20 cm", "16"),
    ("Cable Dupont M-H 20 cm", "2"),
    ("Cable Dupont H-H Fijo 2 vías", "3"),
    ("Cable Dupont H-H Fijo 3 vías", "8"),
    ("Tira Header Macho 40 pines", "1"),
    ("Pila de Botón 3V", "1"),
    ("Juego de impresiones", "1 juego"),
    ("Juego de cortes en MDF", "1 juego"),
)
INVENTORY_RANGES = {5: (1, 6), 6: (7, 15), 7: (16, 25), 8: (26, 32), 9: (33, 39)}


def image_key(path: Path) -> tuple[tuple[int, int], bytes]:
    with Image.open(path) as image:
        return image.size, sha256(image.convert("RGB").tobytes()).digest()


def image_width(pixels: int, page: int) -> str:
    if pixels >= 500 and page >= 66:
        return "5.8in"
    if pixels >= 350:
        return "3.3in"
    if pixels >= 200:
        return "2.0in"
    if pixels >= 100:
        return "1.1in"
    return "0.65in"


def markdown_text(text: str) -> str:
    text = unescape(text).strip()
    text = re.sub(r"\s+([,.;:!?%)])", r"\1", text)
    text = re.sub(r"([¿¡(])\s+", r"\1", text)
    for char in ("\\", "`", "*", "[", "]", "<", ">"):
        replacement = "&lt;" if char == "<" else "&gt;" if char == ">" else "\\" + char
        text = text.replace(char, replacement)
    if text.startswith(("#", "|", "-", "+")):
        text = "\\" + text
    return text


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("pdf", type=Path)
    parser.add_argument("manifest", type=Path)
    parser.add_argument("output", type=Path)
    args = parser.parse_args()

    assets = args.manifest.parent
    manifest = list(csv.DictReader(args.manifest.open(encoding="utf-8"), delimiter="\t"))
    image_pool = defaultdict(list)
    image_by_number = {}
    for row in manifest:
        if row["type"] == "image":
            image_by_number[int(row["image_number"])] = row
            path = assets / row["filename"]
            image_pool[int(row["pdf_page"])].append((row, image_key(path)))

    with tempfile.TemporaryDirectory() as temporary:
        temp = Path(temporary)
        xml_base = temp / "manual"
        text_html = temp / "text.html"
        subprocess.run(
            ["pdftohtml", "-xml", "-hidden", "-noroundcoord", "-q", str(args.pdf), str(xml_base)],
            check=True,
        )
        subprocess.run(["pdftotext", "-bbox-layout", str(args.pdf), str(text_html)], check=True)
        image_pages = ET.parse(xml_base.with_suffix(".xml")).getroot().findall("page")
        text_pages = ET.parse(text_html).getroot().findall(f".//{XHTML}page")
        if len(image_pages) != len(text_pages):
            raise ValueError("PDF image and text page counts differ")

        lines = [
            "## Manual de usuario migrado",
            "",
            "Contenido del manual V1.1.0 incorporado en esta referencia. "
            "El texto y las ilustraciones aparecen por página de origen; "
            "los saltos de línea y las tablas se adaptaron a Markdown para consulta en la web.",
            "",
        ]
        images_written = 0
        text_blocks_written = 0
        current_group = None
        for index, (image_page, text_page) in enumerate(zip(image_pages, text_pages), 1):
            pdf_page = int(image_page.attrib["number"])
            if pdf_page != index:
                raise ValueError(f"unexpected PDF page order: {pdf_page}")
            group = next((title for first, last, title in GROUPS if first <= index <= last), None)
            if group is None:
                raise ValueError(f"page {index} is outside the migration sections")
            if group != current_group:
                lines.extend((f"### {group}", ""))
                current_group = group
            lines.extend((f"#### Página {index} del manual", ""))
            scale = float(image_page.attrib["width"]) / float(text_page.attrib["width"])
            events = []
            for block in text_page.findall(f".//{XHTML}block"):
                block_lines = []
                for line in block.findall(f"{XHTML}line"):
                    words = [word.text or "" for word in line.findall(f"{XHTML}word")]
                    if words:
                        block_lines.append(markdown_text(" ".join(words)))
                content = "  \n".join(block_lines)
                if content:
                    events.append((float(block.attrib["yMin"]), float(block.attrib["xMin"]), "text", content))
            pool = image_pool[index].copy()
            for image in image_page.findall("image"):
                key = image_key(Path(image.attrib["src"]))
                match = next((i for i, (_, value) in enumerate(pool) if value == key), None)
                if match is None:
                    raise ValueError(f"unmatched image on page {index}: {image.attrib['src']}")
                row, _ = pool.pop(match)
                filename = row["filename"]
                number = row["image_number"]
                with Image.open(assets / filename) as source:
                    width = image_width(source.width, index)
                caption = f"Manual de usuario, página {index}, imagen {number}"
                figure = f"![{caption}](assets/manual/{filename}){{width={width}}}"
                events.append((float(image.attrib["top"]) / scale,
                               float(image.attrib["left"]) / scale,
                               "image", figure))
            if pool:
                raise ValueError(f"{len(pool)} images on page {index} were not placed")
            if index == 2:
                # The source version table is split into separate PDF text blocks.
                events = [event for event in events
                          if event[2] != "text" or not 60 <= event[0] < 300]
                table = "\n".join((
                    "Control de versiones", "",
                    "| Versión | Fecha | Nombre | Cambios realizados |",
                    "|---|---|---|---|",
                    "| V1.1.0 | 16/02/2026 | José Serrato | Cambio de motor, mejora de ensamble (electrónica y espacio asignado) y plantillas de corte mejoradas. |",
                    "| V1.0.1 | — | José Serrato | Corrección de puentes en corte láser. |",
                    "| V1.0.0 | — | José Serrato | Creación del proyecto, primer borrador. |",
                ))
                events.append((64.0, 0.0, "text", table))
            if index in INVENTORY_RANGES:
                # Keep the source overview image, then present each folio as a
                # proper row with its extracted local image and exact quantity.
                images_written += sum(event[2] == "image" for event in events)
                text_blocks_written += sum(event[2] == "text" for event in events)
                if index == 5:
                    overview = next(event[3] for event in events
                                    if event[2] == "image" and "image-003.png" in event[3])
                    lines.extend((overview, "", "Lista de materiales", ""))
                lines.extend(("| Folio | Descripción | Imagen | Cantidad |",
                              "|---|---|---|---:|"))
                first, last = INVENTORY_RANGES[index]
                for folio in range(first, last + 1):
                    description, quantity = INVENTORY[folio - 1]
                    row = image_by_number[folio + 3]
                    if int(row["pdf_page"]) != index:
                        raise ValueError(f"folio KSH{folio:02d} image page mismatch")
                    figure = (f"![KSH{folio:02d}: {description}]"
                              f"(assets/manual/{row['filename']}){{width=0.7in}}")
                    lines.append(f"| KSH{folio:02d} | {description} | {figure} | {quantity} |")
                lines.append("")
                if index == 9:
                    for top, _, kind, content in sorted(events):
                        if kind == "text" and top >= 690:
                            lines.extend((content, ""))
                continue
            for _, _, kind, content in sorted(events):
                lines.extend((content, ""))
                if kind == "image":
                    images_written += 1
                else:
                    text_blocks_written += 1
        args.output.write_text("\n".join(lines).rstrip() + "\n", encoding="utf-8")
        print(f"Migrated {len(image_pages)} pages, {text_blocks_written} text blocks, "
              f"and {images_written} images to {args.output}")


if __name__ == "__main__":
    main()
