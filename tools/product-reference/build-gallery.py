#!/usr/bin/env python3
"""Build a local HTML index of every image object extracted from the manual."""

import csv
from html import escape
from pathlib import Path
import sys


def main() -> None:
    manifest, output, reference_name = map(Path, sys.argv[1:4])
    rows = list(csv.DictReader(manifest.open(encoding="utf-8"), delimiter="\t"))
    cards = []
    previous_page = None
    for row in rows:
        page = int(row["pdf_page"])
        if page != previous_page:
            if previous_page is not None:
                cards.append("</div></section>")
            cards.append(f'<section id="pagina-{page}"><h2>Página {page}</h2><div class="grid">')
            previous_page = page
        name = row["filename"]
        kind = row["type"]
        label = f'Página {page}, imagen {row["image_number"]}'
        if kind == "smask":
            label += " (máscara de transparencia)"
        url = f"assets/manual/{name}"
        cards.append(
            '<figure><a href="{url}"><img loading="lazy" src="{url}" alt="{label}"></a>'
            '<figcaption>{label}</figcaption></figure>'.format(
                url=escape(url, quote=True), label=escape(label)
            )
        )
    if previous_page is not None:
        cards.append("</div></section>")
    title = "Figuras del manual de usuario — Kit SmartHome"
    page = f'''<!doctype html>
<html lang="es"><head><meta charset="utf-8"><meta name="viewport" content="width=device-width,initial-scale=1">
<title>{title}</title><style>
:root {{color-scheme:light; font-family:system-ui,sans-serif; color:#172536; background:#f3f6f8}}
body {{margin:0 auto; max-width:1200px; padding:24px}}
a {{color:#a93f0b}} h1 {{font-size:2rem}} h2 {{border-bottom:2px solid #ee6c22; padding-bottom:8px}}
.grid {{display:grid;grid-template-columns:repeat(auto-fill,minmax(180px,1fr));gap:16px}}
figure {{margin:0;background:white;border:1px solid #d8dee6;border-radius:6px;padding:10px}}
img {{display:block;width:100%;height:160px;object-fit:contain}}
figcaption {{font-size:.8rem;color:#5a6573;margin-top:8px}}
</style></head><body><p><a href="{escape(reference_name.name, quote=True)}">← Referencia del producto</a></p>
<h1>{title}</h1><p>{len(rows)} objetos de imagen extraídos del PDF original de 80 páginas.
Las máscaras de transparencia se conservan para que el inventario sea completo.</p>
{''.join(cards)}
</body></html>'''
    output.write_text(page, encoding="utf-8")


if __name__ == "__main__":
    main()
