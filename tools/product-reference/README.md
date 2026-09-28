# Manual de usuario - Kit SmartHome

## Dónde editar

- El contenido completo que se puede editar está en [`chapters/10-manual-migrado.md`](chapters/10-manual-migrado.md). Es Markdown: edite texto, encabezados, tablas y referencias a imágenes allí.
- Los apartados de la plantilla anterior (`chapters/00-` a `chapters/09-`) se recuperaron como borradores. No se publican hasta que se agregue su ruta a la lista `chapters:` de [`book.yml`](book.yml). Así puede revisar su contenido antes de incorporarlo al manual.
- Para crear un apartado, cree otro `.md` en `chapters/` y agregue su ruta a `book.yml` en el orden deseado.
- La plantilla para el DOCX es [`reference-a4.docx`](reference-a4.docx); el diseño de la página HTML editable está en [`templates/product-reference.html`](templates/product-reference.html) y [`styles/product-reference.css`](styles/product-reference.css).
- Las imágenes del manual están en `assets/manual/`. Use rutas como `assets/manual/image-002.png` en Markdown.

## Compilar

Desde la raíz del repositorio:

```bash
./tools/product-reference/build.sh
```

Se necesitan Python 3, Pandoc y `pdftoppm`/`pdftotext` de poppler-utils. El resultado en `build/product-reference/` contiene:

- `manual-editable.html` y `manual-editable.docx`, generados de los archivos listados en `book.yml`.
- `unit_product_reference_v_1_1_0_kit_smarthome.html`, una vista fiel de las 80 páginas del PDF original.
- `unit_product_reference_v_1_1_0_kit_smarthome.pdf`, copia exacta del PDF original.
- Las imágenes locales bajo `assets/`.

El flujo de publicación copia esos archivos a `docs/hardware/product-reference/`. Los cambios en capítulos aparecen en la **versión editable** del sitio y en el DOCX. La **vista original** y el PDF muestran el archivo fuente sin cambios; para actualizar también esas dos salidas, exporte la versión revisada a PDF y sustituya el PDF fuente en `assets/`.
