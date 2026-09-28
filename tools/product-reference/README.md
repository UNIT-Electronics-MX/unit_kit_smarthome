# Manual de usuario - Kit SmartHome

## Dónde editar

- [`chapters/00-portada.md`](chapters/00-portada.md) contiene la portada.
- [`chapters/10-manual-migrado.md`](chapters/10-manual-migrado.md) contiene las secciones, tablas e imágenes del manual completo. Edite esos archivos Markdown para cambiar también el PDF publicado.
- Para agregar un apartado, cree otro `.md` en `chapters/` y añada su ruta a la lista `chapters:` de [`book.yml`](book.yml). El orden de esa lista determina el orden en HTML, PDF y DOCX.
- Los antiguos `chapters/00-description.md` a `09-appendix.md` están conservados como borradores. No se publican hasta añadir su ruta a `book.yml`.
- [`styles/product-reference.css`](styles/product-reference.css) y [`templates/product-reference.html`](templates/product-reference.html) controlan el diseño del HTML y PDF A4. [`reference-a4.docx`](reference-a4.docx) controla el estilo del DOCX.
- Las figuras están en `assets/manual/`; en Markdown use rutas como `assets/manual/image-002.png`.

## Compilar

Desde la raíz del repositorio:

```bash
./tools/product-reference/build.sh
```

Se necesitan Python 3, Pandoc, Google Chrome o Chromium, y `pdfinfo` de poppler-utils. El resultado en `build/product-reference/` contiene HTML, PDF y DOCX **generados de los capítulos listados en `book.yml`**, más sus imágenes locales. La publicación copia el resultado a `docs/hardware/product-reference/`.
