## Contents

- <span class="toc-entry">Descripción</span>
- <span class="toc-entry">1. Contenido del kit</span>
  - <span class="toc-entry">1.1 Electrónica y alimentación</span>
  - <span class="toc-entry">1.2 Cables, estructura y tornillería</span>
- <span class="toc-entry">2. Alimentación y precauciones</span>
- <span class="toc-entry">3. Funciones del sistema</span>
- <span class="toc-entry">4. Conexiones de referencia</span>
  - <span class="toc-entry">4.1 Shield y módulos</span>
  - <span class="toc-entry">4.2 DualMCU ONE, Hub I²C y PCA9685</span>
  - <span class="toc-entry">4.3 Conexión completa</span>
- <span class="toc-entry">5. Ensamble y puesta en marcha</span>
  - <span class="toc-entry">5.1 Secuencia de ensamble</span>
  - <span class="toc-entry">5.2 Firmware</span>
  - <span class="toc-entry">5.3 Aplicación móvil</span>
- <span class="toc-entry">6. Información mecánica</span>
- <span class="toc-entry">7. Fabricante</span>
- <span class="toc-entry">8. Documentación y recursos</span>
- <span class="toc-entry">9. Control del documento</span>
  - <span class="toc-entry">Datos por confirmar</span>
- <span class="toc-entry">10. Atlas de imágenes del manual</span>
  - <span class="toc-entry">Vistas e inventario</span>
  - <span class="toc-entry">Ensamble mecánico y electrónico</span>
  - <span class="toc-entry">Cableado y diagramas</span>
  - <span class="toc-entry">Firmware y aplicación</span>
  - <span class="toc-entry">Recursos y dimensiones</span>

## Descripción

El **Kit SmartHome de UNIT Electronics** (AR4623) es una casa didáctica
para aprender ensamble, electrónica y programación. La tarjeta **UNIT
DualMCU ONE** combina ESP32 y RP2040; el kit añade sensores, actuadores,
comunicación I²C y una aplicación móvil para Android. Esta referencia
resume el manual de usuario **V1.1.0 del 16 de febrero de 2026**. Para
el montaje paso a paso y la orientación de cada cable, consulte el
[manual
completo](assets/I2D-Manual%20de%20usuario%20-%20Kit%20SmartHome-280926-171843.pdf).

<figure>
<img src="assets/manual/image-002.png" style="width:4.3in"
alt="Kit SmartHome ensamblado, vista isométrica" />
<figcaption aria-hidden="true">Kit SmartHome ensamblado, vista
isométrica</figcaption>
</figure>

| Dato                      | Referencia                                              |
|---------------------------|---------------------------------------------------------|
| Producto                  | Kit SmartHome, AR4623                                   |
| Plataforma                | UNIT DualMCU ONE: ESP32 + RP2040                        |
| Alimentación del conjunto | Adaptador de 12 V, 2 A mediante jack                    |
| Comunicación              | Wi-Fi para la app, bus I²C Qwiic, USB para programación |
| Materiales                | MDF, acrílico y piezas impresas en PLA                  |
| Tamaño ensamblado         | 18 × 15 × 19 cm, según el manual V1.1.0                 |
| Tiempo estimado           | 4 h de ensamble y 1 h de puesta en marcha               |
| Aplicación                | Android; APK incluido en `software/App/`                |

**Alcance.** Esta hoja es una referencia rápida del kit. Las imágenes
extraídas del PDF original están disponibles en la [galería local de
figuras](manual-figures.html), organizada por página del manual.

## 1. Contenido del kit

La lista siguiente conserva las cantidades indicadas en el manual
V1.1.0. Antes del ensamble, clasifique las piezas y compruebe que las
conexiones y la tornillería correspondan a cada módulo.

### 1.1 Electrónica y alimentación

| Componente                            | Cantidad | Componente                | Cantidad |
|---------------------------------------|---------:|---------------------------|---------:|
| UNIT DualMCU ONE                      |        1 | Sensor Shield V5.0 UNO R3 |        1 |
| Hub I²C QW/ST                         |        1 | PCA9685                   |        1 |
| Puente H MX1508                       |        1 | Adaptador 12 V / 2 A      |        1 |
| Servomotor SG90                       |        1 | Motor DC con hélice       |        1 |
| Buzzer KY-006                         |        1 | Pantalla OLED SSD1315     |        1 |
| Sensor de flama KY-026                |        1 | Sensor de lluvia FC-37    |        1 |
| Sensor AHT10 de temperatura y humedad |        1 | Fotorresistor KY-018      |        1 |
| Neopixel WS2812                       |        3 | Lector RFID RC522         |        1 |
| Receptor IR HX1838                    |        1 | Botón capacitivo TTP223B  |        1 |
| Encoder KY-040                        |        1 | Sensor PIR HC-SR505       |        1 |

### 1.2 Cables, estructura y tornillería

| Elemento                            | Cantidad | Elemento                             |         Cantidad |
|-------------------------------------|---------:|--------------------------------------|-----------------:|
| Cable Qwiic a Qwiic de 10 cm        |        1 | Cable Qwiic a Dupont hembra de 20 cm |                3 |
| Cable Dupont hembra-hembra de 20 cm |       16 | Cable Dupont macho-hembra de 20 cm   |                2 |
| Dupont fijo de 2 vías               |        3 | Dupont fijo de 3 vías                |                8 |
| Tira header macho de 40 pines       |        1 | Pila de botón de 3 V                 |                1 |
| Tornillo M2×8                       |       12 | Tuerca M2                            |               16 |
| Tornillo M2.5×8                     |       23 | Tuerca M2.5                          |               41 |
| Tornillo M3×6                       |        6 | Tornillo M3×8                        |               18 |
| Tornillo M3×10                      |        5 | Tuerca M3                            |               33 |
| Separador de latón M3×5+6           |        4 | Piezas de MDF e impresas en 3D       | 1 juego cada una |

El manual también muestra las piezas acrílicas y los tornillos propios
de algunos módulos durante el montaje. La lista de inventario completa
con folios KSH01–KSH39 está en el PDF original.

## 2. Alimentación y precauciones

El kit se alimenta con el **adaptador de 12 V, 2 A con jack** incluido.
Esa cifra describe el adaptador del conjunto; no establece por sí sola
los límites eléctricos de cada sensor, del ESP32, del RP2040 ni de los
conectores de la shield. Consulte la documentación de cada módulo antes
de usar otra fuente o agregar cargas externas.

| Punto de revisión                 | Indicación del manual                                                          |
|-----------------------------------|--------------------------------------------------------------------------------|
| Antes de energizar                | Corroborar polaridad, alimentación y posición de todos los conectores.         |
| Neopixel                          | Respetar la polaridad: una conexión invertida puede dañar el módulo.           |
| Cableado de sensores y actuadores | Una mala conexión puede dañar los módulos.                                     |
| Bus I²C                           | Conectar DualMCU ONE al Hub I²C por Qwiic antes de colocar la Sensor Shield.   |
| Motor DC                          | Disponer los cables de modo que el MDF no los corte ni los presione.           |
| Servomotor                        | Energizarlo y colocarlo en la posición inicial antes del montaje de la puerta. |

El manual no aporta una tabla de corriente máxima por puerto ni los
límites de tensión de las señales individuales. Para el cableado use los
diagramas del capítulo 4 y las marcas impresas en cada placa.

## 3. Funciones del sistema

| Subsistema           | Componentes                                  | Función en el kit                                                       |
|----------------------|----------------------------------------------|-------------------------------------------------------------------------|
| Control              | UNIT DualMCU ONE con ESP32 y RP2040          | Ejecuta el firmware del kit y coordina la interfaz móvil y los módulos. |
| Entradas ambientales | AHT10, KY-018, FC-37, KY-026, HC-SR505       | Lectura de temperatura, humedad, luz, lluvia, flama y movimiento.       |
| Entradas de usuario  | KY-040, TTP223B, RC522, HX1838               | Interacción por encoder, tacto, RFID e infrarrojo.                      |
| Salidas              | SG90, motor DC, buzzer, tres WS2812, OLED    | Movimiento, aviso, iluminación y visualización.                         |
| Expansión y control  | Sensor Shield V5.0, Hub I²C, PCA9685, MX1508 | Distribución de conexiones, bus I²C, PWM y manejo del motor.            |
| Aplicación           | App SmartHome para Android                   | Presenta lecturas de sensores y controles de actuadores.                |

<figure>
<img src="assets/manual/image-198.png" style="width:4.4in"
alt="Conjunto montado con electrónica visible" />
<figcaption aria-hidden="true">Conjunto montado con electrónica
visible</figcaption>
</figure>

El aprendizaje práctico incluye control PWM, comunicación I²C y lectura
de señales analógicas y digitales. Las funciones disponibles en la app
dependen del firmware instalado en ambos microcontroladores.

## 4. Conexiones de referencia

La **Sensor Shield** concentra conexiones directas de encoder, buzzer,
RFID, sensor de flama, PIR, botón capacitivo, lluvia, infrarrojo,
fotorresistor y Neopixel. El **Hub I²C** conecta la pantalla OLED y el
AHT10; el manual indica que estos cables pueden ocupar cualquiera de sus
posiciones equivalentes. El **PCA9685** se usa con el servomotor y el
**MX1508** con el motor DC.

### 4.1 Shield y módulos

<figure>
<img src="assets/manual/image-275.png" style="width:6.2in"
alt="Diagrama resumido de conexiones a la Sensor Shield" />
<figcaption aria-hidden="true">Diagrama resumido de conexiones a la
Sensor Shield</figcaption>
</figure>

<figure>
<img src="assets/manual/image-276.png" style="width:6.2in"
alt="Segundo diagrama resumido de conexiones a la Sensor Shield" />
<figcaption aria-hidden="true">Segundo diagrama resumido de conexiones a
la Sensor Shield</figcaption>
</figure>

### 4.2 DualMCU ONE, Hub I²C y PCA9685

<figure>
<img src="assets/manual/image-277.png" style="width:6.2in"
alt="Conexión de DualMCU ONE, Hub I2C y PCA9685" />
<figcaption aria-hidden="true">Conexión de DualMCU ONE, Hub I2C y
PCA9685</figcaption>
</figure>

### 4.3 Conexión completa

<figure>
<img src="assets/manual/image-278.png" style="width:6.2in"
alt="Diagrama completo de conexiones del kit" />
<figcaption aria-hidden="true">Diagrama completo de conexiones del
kit</figcaption>
</figure>

El segundo diagrama completo del manual está disponible como [figura
adicional](assets/manual/image-279.png). Revise la orientación de VCC,
GND y señal en cada conector antes de aplicar energía. Los diagramas son
la fuente visual de asignaciones específicas; esta referencia no
sustituye la comprobación física del cableado.

## 5. Ensamble y puesta en marcha

### 5.1 Secuencia de ensamble

1.  Inventariar las piezas y reunir desarmadores, pinzas y cautín.
    Colocar la pila de botón en el control IR y soldar los pines de los
    módulos que lo requieren.
2.  Energizar el SG90 para ubicar su posición inicial; después montar la
    puerta y la base MDF-A.
3.  Montar las paredes, los techos y los módulos. El manual desglosa
    esta etapa en los ensambles 1.1 a 1.9.
4.  Atornillar la DualMCU ONE y conectar su cable Qwiic al Hub I²C antes
    de instalar la Sensor Shield.
5.  Conectar sensores, OLED, servo, Neopixel y motor a la shield, Hub
    I²C, PCA9685 o MX1508 conforme a los diagramas del capítulo 4.
6.  Cerrar la estructura y revisar que ningún cable quede pellizcado.
    Verificar polaridad y ausencia de cortocircuitos antes de alimentar
    con el adaptador.

<figure>
<img src="assets/manual/image-274.png" style="width:4.2in"
alt="Ensamble final de la casa" />
<figcaption aria-hidden="true">Ensamble final de la casa</figcaption>
</figure>

El manual de 80 páginas conserva las vistas y la posición de cada
tornillo. Para pasos con orientación difícil, como el Neopixel de la
pared P y el motor en la pared N, consulte su [galería de
figuras](manual-figures.html).

### 5.2 Firmware

La DualMCU ONE se entrega con firmware pregrabado. Si requiere
reinstalarlo, abra en Arduino IDE los programas del repositorio:

| Procesador | Programa local                                                         | Acción                                                                                              |
|------------|------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------|
| ESP32      | `software/ESP32/Smart_Home_App_ESP_COMV4/Smart_Home_App_ESP_COMV4.ino` | Cargar primero los datos LittleFS con el complemento indicado en el manual y luego subir el sketch. |
| RP2040     | `software/RP2040/Smart_Home_RP_V1/Smart_Home_RP_V1.ino`                | Compilar y cargar el sketch para la placa correspondiente.                                          |

El complemento LittleFS y la configuración de placa dependen de la
versión del IDE. El manual explica el proceso de carga y el uso del
botón BOOT cuando la conexión no ocurre automáticamente.

### 5.3 Aplicación móvil

El APK está en `software/App/smartHomeApp.apk`. Instálelo en Android
desde la fuente oficial del repositorio. Al abrir la app, el botón
**Ayuda** describe sus funciones. El manual muestra la visualización de
sensores y los controles de actuadores, pero deja sin instrucciones
desarrolladas las secciones «Primera conexión», «Uso de la app» y «Modo
Offline»; no se deben inferir pasos de emparejamiento a partir de esos
títulos.

<figure>
<img src="assets/manual/image-283.jpg" style="width:2.2in"
alt="Vista de sensores en la aplicación" />
<figcaption aria-hidden="true">Vista de sensores en la
aplicación</figcaption>
</figure>

## 6. Información mecánica

| Parámetro                      | Valor del manual V1.1.0                            |
|--------------------------------|----------------------------------------------------|
| Dimensiones del kit ensamblado | 18 × 15 × 19 cm                                    |
| Dimensiones del empaque        | 27 × 17 × 15 cm                                    |
| Materiales principales         | MDF, acrílico y PLA                                |
| Tornillería                    | Tornillos milimétricos de cabeza de queso ranurada |
| Peso total                     | No indicado                                        |

<figure>
<img src="assets/manual/image-303.png" style="width:6.2in"
alt="Vistas dimensionales del kit" />
<figcaption aria-hidden="true">Vistas dimensionales del kit</figcaption>
</figure>

Estas medidas corresponden al documento V1.1.0. La portada del
repositorio da una medida distinta para el conjunto (16 × 15 × 19 cm);
para fabricación de envolventes o embalaje debe confirmarse la dimensión
con una medición controlada del kit físico.

## 7. Fabricante

| Campo      | Información                                   |
|------------|-----------------------------------------------|
| Fabricante | UNIT Electronics                              |
| Sitio web  | [uelectronics.com](https://uelectronics.com/) |
| Plataforma | UNIT DevLab / Kit SmartHome                   |

Para asistencia y actualizaciones de software, consulte el repositorio
del producto en el capítulo 8.

## 8. Documentación y recursos

| Recurso                                 | Ubicación                                                                                           |
|-----------------------------------------|-----------------------------------------------------------------------------------------------------|
| Manual de usuario V1.1.0, PDF original  | [Descargar manual PDF](assets/I2D-Manual%20de%20usuario%20-%20Kit%20SmartHome-280926-171843.pdf)    |
| Figuras del manual extraídas localmente | [Galería de figuras](manual-figures.html)                                                           |
| Repositorio del producto                | [UNIT-Electronics-MX/unit_kit_smarthome](https://github.com/UNIT-Electronics-MX/unit_kit_smarthome) |
| Firmware ESP32                          | `software/ESP32/Smart_Home_App_ESP_COMV4/`                                                          |
| Firmware RP2040                         | `software/RP2040/Smart_Home_RP_V1/`                                                                 |
| Aplicación Android                      | `software/App/smartHomeApp.apk`                                                                     |
| Arduino IDE                             | [Documentación oficial](https://docs.arduino.cc/software/ide/)                                      |

Los enlaces de archivos locales se refieren a las rutas del repositorio.
La galería publica todas las imágenes extraídas para su consulta desde
la página web.

## 9. Control del documento

| Campo                     | Valor                                                           |
|---------------------------|-----------------------------------------------------------------|
| Producto                  | Kit SmartHome, AR4623                                           |
| Versión del manual fuente | 1.1.0                                                           |
| Fecha del manual fuente   | 16 de febrero de 2026                                           |
| Autores del manual fuente | Juan Luis Ballesteros y José Carlos Serrato                     |
| Documento derivado        | Product Reference V1.1.0                                        |
| Fuente de las imágenes    | PDF de 80 páginas incluido en `tools/product-reference/assets/` |

Las imágenes se extrajeron sin depender de servidores externos. El
archivo `assets/manual/manifest.tsv` relaciona cada imagen con su página
de origen y su número dentro del PDF. Los objetos `smask` son máscaras
de transparencia extraídas junto con las imágenes; también se conservan
en `assets`.

### Datos por confirmar

- El manual deja sin valor el peso total.
- La dimensión ensamblada del manual (18 × 15 × 19 cm) difiere de la
  portada del repositorio (16 × 15 × 19 cm).
- El manual no incluye instrucciones desarrolladas para primera
  conexión, uso de la app ni modo sin conexión.
- No se especifican límites eléctricos por puerto ni un pinout numérico
  completo en texto; para el cableado se deben usar los diagramas
  visuales del manual.

## 10. Atlas de imágenes del manual

Las 302 imágenes del manual se reproducen a continuación en el orden de
sus páginas originales. Las figuras principales también aparecen a mayor
tamaño en los capítulos anteriores. Abra la [galería de
figuras](manual-figures.html) para consultar cada archivo por separado.

El PDF contiene además 2 máscaras de transparencia; se conservan en
`assets/manual/` pero no son ilustraciones independientes.

### Vistas e inventario

#### Página 1 del manual

<figure>
<img src="assets/manual/image-000.png" style="width:3.3in"
alt="Manual de usuario, página 1, imagen 0" />
<figcaption aria-hidden="true">Manual de usuario, página 1, imagen
0</figcaption>
</figure>

<figure>
<img src="assets/manual/image-002.png" style="width:3.3in"
alt="Manual de usuario, página 1, imagen 2" />
<figcaption aria-hidden="true">Manual de usuario, página 1, imagen
2</figcaption>
</figure>

#### Página 5 del manual

<figure>
<img src="assets/manual/image-003.png" style="width:3.3in"
alt="Manual de usuario, página 5, imagen 3" />
<figcaption aria-hidden="true">Manual de usuario, página 5, imagen
3</figcaption>
</figure>

<figure>
<img src="assets/manual/image-004.png" style="width:0.65in"
alt="Manual de usuario, página 5, imagen 4" />
<figcaption aria-hidden="true">Manual de usuario, página 5, imagen
4</figcaption>
</figure>

<figure>
<img src="assets/manual/image-005.png" style="width:0.65in"
alt="Manual de usuario, página 5, imagen 5" />
<figcaption aria-hidden="true">Manual de usuario, página 5, imagen
5</figcaption>
</figure>

<figure>
<img src="assets/manual/image-006.png" style="width:0.65in"
alt="Manual de usuario, página 5, imagen 6" />
<figcaption aria-hidden="true">Manual de usuario, página 5, imagen
6</figcaption>
</figure>

<figure>
<img src="assets/manual/image-007.png" style="width:0.65in"
alt="Manual de usuario, página 5, imagen 7" />
<figcaption aria-hidden="true">Manual de usuario, página 5, imagen
7</figcaption>
</figure>

<figure>
<img src="assets/manual/image-008.png" style="width:0.65in"
alt="Manual de usuario, página 5, imagen 8" />
<figcaption aria-hidden="true">Manual de usuario, página 5, imagen
8</figcaption>
</figure>

<figure>
<img src="assets/manual/image-009.png" style="width:0.65in"
alt="Manual de usuario, página 5, imagen 9" />
<figcaption aria-hidden="true">Manual de usuario, página 5, imagen
9</figcaption>
</figure>

#### Página 6 del manual

<figure>
<img src="assets/manual/image-010.png" style="width:0.65in"
alt="Manual de usuario, página 6, imagen 10" />
<figcaption aria-hidden="true">Manual de usuario, página 6, imagen
10</figcaption>
</figure>

<figure>
<img src="assets/manual/image-011.png" style="width:0.65in"
alt="Manual de usuario, página 6, imagen 11" />
<figcaption aria-hidden="true">Manual de usuario, página 6, imagen
11</figcaption>
</figure>

<figure>
<img src="assets/manual/image-012.png" style="width:0.65in"
alt="Manual de usuario, página 6, imagen 12" />
<figcaption aria-hidden="true">Manual de usuario, página 6, imagen
12</figcaption>
</figure>

<figure>
<img src="assets/manual/image-013.png" style="width:1.1in"
alt="Manual de usuario, página 6, imagen 13" />
<figcaption aria-hidden="true">Manual de usuario, página 6, imagen
13</figcaption>
</figure>

<figure>
<img src="assets/manual/image-014.png" style="width:1.1in"
alt="Manual de usuario, página 6, imagen 14" />
<figcaption aria-hidden="true">Manual de usuario, página 6, imagen
14</figcaption>
</figure>

<figure>
<img src="assets/manual/image-015.png" style="width:1.1in"
alt="Manual de usuario, página 6, imagen 15" />
<figcaption aria-hidden="true">Manual de usuario, página 6, imagen
15</figcaption>
</figure>

<figure>
<img src="assets/manual/image-016.png" style="width:1.1in"
alt="Manual de usuario, página 6, imagen 16" />
<figcaption aria-hidden="true">Manual de usuario, página 6, imagen
16</figcaption>
</figure>

<figure>
<img src="assets/manual/image-017.png" style="width:1.1in"
alt="Manual de usuario, página 6, imagen 17" />
<figcaption aria-hidden="true">Manual de usuario, página 6, imagen
17</figcaption>
</figure>

<figure>
<img src="assets/manual/image-018.png" style="width:1.1in"
alt="Manual de usuario, página 6, imagen 18" />
<figcaption aria-hidden="true">Manual de usuario, página 6, imagen
18</figcaption>
</figure>

#### Página 7 del manual

<figure>
<img src="assets/manual/image-019.png" style="width:1.1in"
alt="Manual de usuario, página 7, imagen 19" />
<figcaption aria-hidden="true">Manual de usuario, página 7, imagen
19</figcaption>
</figure>

<figure>
<img src="assets/manual/image-020.png" style="width:1.1in"
alt="Manual de usuario, página 7, imagen 20" />
<figcaption aria-hidden="true">Manual de usuario, página 7, imagen
20</figcaption>
</figure>

<figure>
<img src="assets/manual/image-021.png" style="width:1.1in"
alt="Manual de usuario, página 7, imagen 21" />
<figcaption aria-hidden="true">Manual de usuario, página 7, imagen
21</figcaption>
</figure>

<figure>
<img src="assets/manual/image-022.png" style="width:1.1in"
alt="Manual de usuario, página 7, imagen 22" />
<figcaption aria-hidden="true">Manual de usuario, página 7, imagen
22</figcaption>
</figure>

<figure>
<img src="assets/manual/image-023.png" style="width:0.65in"
alt="Manual de usuario, página 7, imagen 23" />
<figcaption aria-hidden="true">Manual de usuario, página 7, imagen
23</figcaption>
</figure>

<figure>
<img src="assets/manual/image-024.png" style="width:1.1in"
alt="Manual de usuario, página 7, imagen 24" />
<figcaption aria-hidden="true">Manual de usuario, página 7, imagen
24</figcaption>
</figure>

<figure>
<img src="assets/manual/image-025.png" style="width:1.1in"
alt="Manual de usuario, página 7, imagen 25" />
<figcaption aria-hidden="true">Manual de usuario, página 7, imagen
25</figcaption>
</figure>

<figure>
<img src="assets/manual/image-026.png" style="width:1.1in"
alt="Manual de usuario, página 7, imagen 26" />
<figcaption aria-hidden="true">Manual de usuario, página 7, imagen
26</figcaption>
</figure>

<figure>
<img src="assets/manual/image-027.png" style="width:0.65in"
alt="Manual de usuario, página 7, imagen 27" />
<figcaption aria-hidden="true">Manual de usuario, página 7, imagen
27</figcaption>
</figure>

<figure>
<img src="assets/manual/image-028.png" style="width:1.1in"
alt="Manual de usuario, página 7, imagen 28" />
<figcaption aria-hidden="true">Manual de usuario, página 7, imagen
28</figcaption>
</figure>

#### Página 8 del manual

<figure>
<img src="assets/manual/image-029.png" style="width:1.1in"
alt="Manual de usuario, página 8, imagen 29" />
<figcaption aria-hidden="true">Manual de usuario, página 8, imagen
29</figcaption>
</figure>

<figure>
<img src="assets/manual/image-030.png" style="width:1.1in"
alt="Manual de usuario, página 8, imagen 30" />
<figcaption aria-hidden="true">Manual de usuario, página 8, imagen
30</figcaption>
</figure>

<figure>
<img src="assets/manual/image-031.png" style="width:2in"
alt="Manual de usuario, página 8, imagen 31" />
<figcaption aria-hidden="true">Manual de usuario, página 8, imagen
31</figcaption>
</figure>

<figure>
<img src="assets/manual/image-032.png" style="width:1.1in"
alt="Manual de usuario, página 8, imagen 32" />
<figcaption aria-hidden="true">Manual de usuario, página 8, imagen
32</figcaption>
</figure>

<figure>
<img src="assets/manual/image-033.png" style="width:2in"
alt="Manual de usuario, página 8, imagen 33" />
<figcaption aria-hidden="true">Manual de usuario, página 8, imagen
33</figcaption>
</figure>

<figure>
<img src="assets/manual/image-034.png" style="width:1.1in"
alt="Manual de usuario, página 8, imagen 34" />
<figcaption aria-hidden="true">Manual de usuario, página 8, imagen
34</figcaption>
</figure>

<figure>
<img src="assets/manual/image-035.png" style="width:1.1in"
alt="Manual de usuario, página 8, imagen 35" />
<figcaption aria-hidden="true">Manual de usuario, página 8, imagen
35</figcaption>
</figure>

#### Página 9 del manual

<figure>
<img src="assets/manual/image-036.png" style="width:1.1in"
alt="Manual de usuario, página 9, imagen 36" />
<figcaption aria-hidden="true">Manual de usuario, página 9, imagen
36</figcaption>
</figure>

<figure>
<img src="assets/manual/image-037.png" style="width:1.1in"
alt="Manual de usuario, página 9, imagen 37" />
<figcaption aria-hidden="true">Manual de usuario, página 9, imagen
37</figcaption>
</figure>

<figure>
<img src="assets/manual/image-038.png" style="width:1.1in"
alt="Manual de usuario, página 9, imagen 38" />
<figcaption aria-hidden="true">Manual de usuario, página 9, imagen
38</figcaption>
</figure>

<figure>
<img src="assets/manual/image-039.png" style="width:1.1in"
alt="Manual de usuario, página 9, imagen 39" />
<figcaption aria-hidden="true">Manual de usuario, página 9, imagen
39</figcaption>
</figure>

<figure>
<img src="assets/manual/image-040.png" style="width:1.1in"
alt="Manual de usuario, página 9, imagen 40" />
<figcaption aria-hidden="true">Manual de usuario, página 9, imagen
40</figcaption>
</figure>

<figure>
<img src="assets/manual/image-041.png" style="width:1.1in"
alt="Manual de usuario, página 9, imagen 41" />
<figcaption aria-hidden="true">Manual de usuario, página 9, imagen
41</figcaption>
</figure>

<figure>
<img src="assets/manual/image-042.png" style="width:1.1in"
alt="Manual de usuario, página 9, imagen 42" />
<figcaption aria-hidden="true">Manual de usuario, página 9, imagen
42</figcaption>
</figure>

#### Página 10 del manual

<figure>
<img src="assets/manual/image-043.png" style="width:2in"
alt="Manual de usuario, página 10, imagen 43" />
<figcaption aria-hidden="true">Manual de usuario, página 10, imagen
43</figcaption>
</figure>

<figure>
<img src="assets/manual/image-044.png" style="width:2in"
alt="Manual de usuario, página 10, imagen 44" />
<figcaption aria-hidden="true">Manual de usuario, página 10, imagen
44</figcaption>
</figure>

<figure>
<img src="assets/manual/image-045.png" style="width:2in"
alt="Manual de usuario, página 10, imagen 45" />
<figcaption aria-hidden="true">Manual de usuario, página 10, imagen
45</figcaption>
</figure>

<figure>
<img src="assets/manual/image-046.png" style="width:2in"
alt="Manual de usuario, página 10, imagen 46" />
<figcaption aria-hidden="true">Manual de usuario, página 10, imagen
46</figcaption>
</figure>

<figure>
<img src="assets/manual/image-047.png" style="width:2in"
alt="Manual de usuario, página 10, imagen 47" />
<figcaption aria-hidden="true">Manual de usuario, página 10, imagen
47</figcaption>
</figure>

<figure>
<img src="assets/manual/image-048.png" style="width:2in"
alt="Manual de usuario, página 10, imagen 48" />
<figcaption aria-hidden="true">Manual de usuario, página 10, imagen
48</figcaption>
</figure>

#### Página 11 del manual

<figure>
<img src="assets/manual/image-049.png" style="width:1.1in"
alt="Manual de usuario, página 11, imagen 49" />
<figcaption aria-hidden="true">Manual de usuario, página 11, imagen
49</figcaption>
</figure>

<figure>
<img src="assets/manual/image-050.png" style="width:2in"
alt="Manual de usuario, página 11, imagen 50" />
<figcaption aria-hidden="true">Manual de usuario, página 11, imagen
50</figcaption>
</figure>

<figure>
<img src="assets/manual/image-051.png" style="width:2in"
alt="Manual de usuario, página 11, imagen 51" />
<figcaption aria-hidden="true">Manual de usuario, página 11, imagen
51</figcaption>
</figure>

<figure>
<img src="assets/manual/image-052.png" style="width:2in"
alt="Manual de usuario, página 11, imagen 52" />
<figcaption aria-hidden="true">Manual de usuario, página 11, imagen
52</figcaption>
</figure>

<figure>
<img src="assets/manual/image-053.png" style="width:2in"
alt="Manual de usuario, página 11, imagen 53" />
<figcaption aria-hidden="true">Manual de usuario, página 11, imagen
53</figcaption>
</figure>

### Ensamble mecánico y electrónico

#### Página 12 del manual

<figure>
<img src="assets/manual/image-054.png" style="width:3.3in"
alt="Manual de usuario, página 12, imagen 54" />
<figcaption aria-hidden="true">Manual de usuario, página 12, imagen
54</figcaption>
</figure>

#### Página 13 del manual

<figure>
<img src="assets/manual/image-055.png" style="width:2in"
alt="Manual de usuario, página 13, imagen 55" />
<figcaption aria-hidden="true">Manual de usuario, página 13, imagen
55</figcaption>
</figure>

<figure>
<img src="assets/manual/image-056.png" style="width:0.65in"
alt="Manual de usuario, página 13, imagen 56" />
<figcaption aria-hidden="true">Manual de usuario, página 13, imagen
56</figcaption>
</figure>

<figure>
<img src="assets/manual/image-057.png" style="width:1.1in"
alt="Manual de usuario, página 13, imagen 57" />
<figcaption aria-hidden="true">Manual de usuario, página 13, imagen
57</figcaption>
</figure>

<figure>
<img src="assets/manual/image-058.png" style="width:1.1in"
alt="Manual de usuario, página 13, imagen 58" />
<figcaption aria-hidden="true">Manual de usuario, página 13, imagen
58</figcaption>
</figure>

<figure>
<img src="assets/manual/image-059.png" style="width:1.1in"
alt="Manual de usuario, página 13, imagen 59" />
<figcaption aria-hidden="true">Manual de usuario, página 13, imagen
59</figcaption>
</figure>

<figure>
<img src="assets/manual/image-060.png" style="width:1.1in"
alt="Manual de usuario, página 13, imagen 60" />
<figcaption aria-hidden="true">Manual de usuario, página 13, imagen
60</figcaption>
</figure>

<figure>
<img src="assets/manual/image-061.png" style="width:1.1in"
alt="Manual de usuario, página 13, imagen 61" />
<figcaption aria-hidden="true">Manual de usuario, página 13, imagen
61</figcaption>
</figure>

<figure>
<img src="assets/manual/image-062.png" style="width:1.1in"
alt="Manual de usuario, página 13, imagen 62" />
<figcaption aria-hidden="true">Manual de usuario, página 13, imagen
62</figcaption>
</figure>

<figure>
<img src="assets/manual/image-063.png" style="width:1.1in"
alt="Manual de usuario, página 13, imagen 63" />
<figcaption aria-hidden="true">Manual de usuario, página 13, imagen
63</figcaption>
</figure>

<figure>
<img src="assets/manual/image-064.png" style="width:1.1in"
alt="Manual de usuario, página 13, imagen 64" />
<figcaption aria-hidden="true">Manual de usuario, página 13, imagen
64</figcaption>
</figure>

<figure>
<img src="assets/manual/image-065.png" style="width:1.1in"
alt="Manual de usuario, página 13, imagen 65" />
<figcaption aria-hidden="true">Manual de usuario, página 13, imagen
65</figcaption>
</figure>

<figure>
<img src="assets/manual/image-066.png" style="width:1.1in"
alt="Manual de usuario, página 13, imagen 66" />
<figcaption aria-hidden="true">Manual de usuario, página 13, imagen
66</figcaption>
</figure>

<figure>
<img src="assets/manual/image-067.png" style="width:1.1in"
alt="Manual de usuario, página 13, imagen 67" />
<figcaption aria-hidden="true">Manual de usuario, página 13, imagen
67</figcaption>
</figure>

<figure>
<img src="assets/manual/image-068.png" style="width:3.3in"
alt="Manual de usuario, página 13, imagen 68" />
<figcaption aria-hidden="true">Manual de usuario, página 13, imagen
68</figcaption>
</figure>

#### Página 14 del manual

<figure>
<img src="assets/manual/image-069.png" style="width:3.3in"
alt="Manual de usuario, página 14, imagen 69" />
<figcaption aria-hidden="true">Manual de usuario, página 14, imagen
69</figcaption>
</figure>

<figure>
<img src="assets/manual/image-070.png" style="width:3.3in"
alt="Manual de usuario, página 14, imagen 70" />
<figcaption aria-hidden="true">Manual de usuario, página 14, imagen
70</figcaption>
</figure>

#### Página 15 del manual

<figure>
<img src="assets/manual/image-071.png" style="width:3.3in"
alt="Manual de usuario, página 15, imagen 71" />
<figcaption aria-hidden="true">Manual de usuario, página 15, imagen
71</figcaption>
</figure>

<figure>
<img src="assets/manual/image-072.png" style="width:3.3in"
alt="Manual de usuario, página 15, imagen 72" />
<figcaption aria-hidden="true">Manual de usuario, página 15, imagen
72</figcaption>
</figure>

#### Página 16 del manual

<figure>
<img src="assets/manual/image-073.png" style="width:3.3in"
alt="Manual de usuario, página 16, imagen 73" />
<figcaption aria-hidden="true">Manual de usuario, página 16, imagen
73</figcaption>
</figure>

<figure>
<img src="assets/manual/image-074.png" style="width:3.3in"
alt="Manual de usuario, página 16, imagen 74" />
<figcaption aria-hidden="true">Manual de usuario, página 16, imagen
74</figcaption>
</figure>

<figure>
<img src="assets/manual/image-075.png" style="width:1.1in"
alt="Manual de usuario, página 16, imagen 75" />
<figcaption aria-hidden="true">Manual de usuario, página 16, imagen
75</figcaption>
</figure>

<figure>
<img src="assets/manual/image-076.png" style="width:1.1in"
alt="Manual de usuario, página 16, imagen 76" />
<figcaption aria-hidden="true">Manual de usuario, página 16, imagen
76</figcaption>
</figure>

<figure>
<img src="assets/manual/image-077.png" style="width:1.1in"
alt="Manual de usuario, página 16, imagen 77" />
<figcaption aria-hidden="true">Manual de usuario, página 16, imagen
77</figcaption>
</figure>

<figure>
<img src="assets/manual/image-078.png" style="width:1.1in"
alt="Manual de usuario, página 16, imagen 78" />
<figcaption aria-hidden="true">Manual de usuario, página 16, imagen
78</figcaption>
</figure>

<figure>
<img src="assets/manual/image-079.png" style="width:1.1in"
alt="Manual de usuario, página 16, imagen 79" />
<figcaption aria-hidden="true">Manual de usuario, página 16, imagen
79</figcaption>
</figure>

<figure>
<img src="assets/manual/image-080.png" style="width:1.1in"
alt="Manual de usuario, página 16, imagen 80" />
<figcaption aria-hidden="true">Manual de usuario, página 16, imagen
80</figcaption>
</figure>

<figure>
<img src="assets/manual/image-081.png" style="width:0.65in"
alt="Manual de usuario, página 16, imagen 81" />
<figcaption aria-hidden="true">Manual de usuario, página 16, imagen
81</figcaption>
</figure>

<figure>
<img src="assets/manual/image-082.png" style="width:1.1in"
alt="Manual de usuario, página 16, imagen 82" />
<figcaption aria-hidden="true">Manual de usuario, página 16, imagen
82</figcaption>
</figure>

<figure>
<img src="assets/manual/image-083.png" style="width:0.65in"
alt="Manual de usuario, página 16, imagen 83" />
<figcaption aria-hidden="true">Manual de usuario, página 16, imagen
83</figcaption>
</figure>

<figure>
<img src="assets/manual/image-084.png" style="width:1.1in"
alt="Manual de usuario, página 16, imagen 84" />
<figcaption aria-hidden="true">Manual de usuario, página 16, imagen
84</figcaption>
</figure>

#### Página 17 del manual

<figure>
<img src="assets/manual/image-085.png" style="width:1.1in"
alt="Manual de usuario, página 17, imagen 85" />
<figcaption aria-hidden="true">Manual de usuario, página 17, imagen
85</figcaption>
</figure>

<figure>
<img src="assets/manual/image-086.png" style="width:3.3in"
alt="Manual de usuario, página 17, imagen 86" />
<figcaption aria-hidden="true">Manual de usuario, página 17, imagen
86</figcaption>
</figure>

<figure>
<img src="assets/manual/image-087.png" style="width:3.3in"
alt="Manual de usuario, página 17, imagen 87" />
<figcaption aria-hidden="true">Manual de usuario, página 17, imagen
87</figcaption>
</figure>

#### Página 18 del manual

<figure>
<img src="assets/manual/image-088.png" style="width:3.3in"
alt="Manual de usuario, página 18, imagen 88" />
<figcaption aria-hidden="true">Manual de usuario, página 18, imagen
88</figcaption>
</figure>

<figure>
<img src="assets/manual/image-089.png" style="width:2in"
alt="Manual de usuario, página 18, imagen 89" />
<figcaption aria-hidden="true">Manual de usuario, página 18, imagen
89</figcaption>
</figure>

<figure>
<img src="assets/manual/image-090.png" style="width:3.3in"
alt="Manual de usuario, página 18, imagen 90" />
<figcaption aria-hidden="true">Manual de usuario, página 18, imagen
90</figcaption>
</figure>

#### Página 19 del manual

<figure>
<img src="assets/manual/image-091.png" style="width:3.3in"
alt="Manual de usuario, página 19, imagen 91" />
<figcaption aria-hidden="true">Manual de usuario, página 19, imagen
91</figcaption>
</figure>

<figure>
<img src="assets/manual/image-092.png" style="width:3.3in"
alt="Manual de usuario, página 19, imagen 92" />
<figcaption aria-hidden="true">Manual de usuario, página 19, imagen
92</figcaption>
</figure>

<figure>
<img src="assets/manual/image-093.png" style="width:3.3in"
alt="Manual de usuario, página 19, imagen 93" />
<figcaption aria-hidden="true">Manual de usuario, página 19, imagen
93</figcaption>
</figure>

#### Página 20 del manual

<figure>
<img src="assets/manual/image-094.png" style="width:3.3in"
alt="Manual de usuario, página 20, imagen 94" />
<figcaption aria-hidden="true">Manual de usuario, página 20, imagen
94</figcaption>
</figure>

<figure>
<img src="assets/manual/image-095.png" style="width:0.65in"
alt="Manual de usuario, página 20, imagen 95" />
<figcaption aria-hidden="true">Manual de usuario, página 20, imagen
95</figcaption>
</figure>

<figure>
<img src="assets/manual/image-096.png" style="width:1.1in"
alt="Manual de usuario, página 20, imagen 96" />
<figcaption aria-hidden="true">Manual de usuario, página 20, imagen
96</figcaption>
</figure>

<figure>
<img src="assets/manual/image-097.png" style="width:1.1in"
alt="Manual de usuario, página 20, imagen 97" />
<figcaption aria-hidden="true">Manual de usuario, página 20, imagen
97</figcaption>
</figure>

<figure>
<img src="assets/manual/image-098.png" style="width:1.1in"
alt="Manual de usuario, página 20, imagen 98" />
<figcaption aria-hidden="true">Manual de usuario, página 20, imagen
98</figcaption>
</figure>

<figure>
<img src="assets/manual/image-099.png" style="width:1.1in"
alt="Manual de usuario, página 20, imagen 99" />
<figcaption aria-hidden="true">Manual de usuario, página 20, imagen
99</figcaption>
</figure>

<figure>
<img src="assets/manual/image-100.png" style="width:1.1in"
alt="Manual de usuario, página 20, imagen 100" />
<figcaption aria-hidden="true">Manual de usuario, página 20, imagen
100</figcaption>
</figure>

<figure>
<img src="assets/manual/image-101.png" style="width:1.1in"
alt="Manual de usuario, página 20, imagen 101" />
<figcaption aria-hidden="true">Manual de usuario, página 20, imagen
101</figcaption>
</figure>

<figure>
<img src="assets/manual/image-102.png" style="width:1.1in"
alt="Manual de usuario, página 20, imagen 102" />
<figcaption aria-hidden="true">Manual de usuario, página 20, imagen
102</figcaption>
</figure>

<figure>
<img src="assets/manual/image-103.png" style="width:3.3in"
alt="Manual de usuario, página 20, imagen 103" />
<figcaption aria-hidden="true">Manual de usuario, página 20, imagen
103</figcaption>
</figure>

<figure>
<img src="assets/manual/image-104.png" style="width:3.3in"
alt="Manual de usuario, página 20, imagen 104" />
<figcaption aria-hidden="true">Manual de usuario, página 20, imagen
104</figcaption>
</figure>

#### Página 21 del manual

<figure>
<img src="assets/manual/image-105.png" style="width:3.3in"
alt="Manual de usuario, página 21, imagen 105" />
<figcaption aria-hidden="true">Manual de usuario, página 21, imagen
105</figcaption>
</figure>

<figure>
<img src="assets/manual/image-106.png" style="width:3.3in"
alt="Manual de usuario, página 21, imagen 106" />
<figcaption aria-hidden="true">Manual de usuario, página 21, imagen
106</figcaption>
</figure>

#### Página 22 del manual

<figure>
<img src="assets/manual/image-107.png" style="width:3.3in"
alt="Manual de usuario, página 22, imagen 107" />
<figcaption aria-hidden="true">Manual de usuario, página 22, imagen
107</figcaption>
</figure>

<figure>
<img src="assets/manual/image-108.png" style="width:3.3in"
alt="Manual de usuario, página 22, imagen 108" />
<figcaption aria-hidden="true">Manual de usuario, página 22, imagen
108</figcaption>
</figure>

#### Página 23 del manual

<figure>
<img src="assets/manual/image-109.png" style="width:2in"
alt="Manual de usuario, página 23, imagen 109" />
<figcaption aria-hidden="true">Manual de usuario, página 23, imagen
109</figcaption>
</figure>

<figure>
<img src="assets/manual/image-110.png" style="width:2in"
alt="Manual de usuario, página 23, imagen 110" />
<figcaption aria-hidden="true">Manual de usuario, página 23, imagen
110</figcaption>
</figure>

<figure>
<img src="assets/manual/image-111.png" style="width:3.3in"
alt="Manual de usuario, página 23, imagen 111" />
<figcaption aria-hidden="true">Manual de usuario, página 23, imagen
111</figcaption>
</figure>

<figure>
<img src="assets/manual/image-112.png" style="width:1.1in"
alt="Manual de usuario, página 23, imagen 112" />
<figcaption aria-hidden="true">Manual de usuario, página 23, imagen
112</figcaption>
</figure>

<figure>
<img src="assets/manual/image-113.png" style="width:0.65in"
alt="Manual de usuario, página 23, imagen 113" />
<figcaption aria-hidden="true">Manual de usuario, página 23, imagen
113</figcaption>
</figure>

<figure>
<img src="assets/manual/image-114.png" style="width:1.1in"
alt="Manual de usuario, página 23, imagen 114" />
<figcaption aria-hidden="true">Manual de usuario, página 23, imagen
114</figcaption>
</figure>

<figure>
<img src="assets/manual/image-115.png" style="width:0.65in"
alt="Manual de usuario, página 23, imagen 115" />
<figcaption aria-hidden="true">Manual de usuario, página 23, imagen
115</figcaption>
</figure>

<figure>
<img src="assets/manual/image-116.png" style="width:0.65in"
alt="Manual de usuario, página 23, imagen 116" />
<figcaption aria-hidden="true">Manual de usuario, página 23, imagen
116</figcaption>
</figure>

#### Página 24 del manual

<figure>
<img src="assets/manual/image-117.png" style="width:1.1in"
alt="Manual de usuario, página 24, imagen 117" />
<figcaption aria-hidden="true">Manual de usuario, página 24, imagen
117</figcaption>
</figure>

<figure>
<img src="assets/manual/image-118.png" style="width:0.65in"
alt="Manual de usuario, página 24, imagen 118" />
<figcaption aria-hidden="true">Manual de usuario, página 24, imagen
118</figcaption>
</figure>

<figure>
<img src="assets/manual/image-119.png" style="width:1.1in"
alt="Manual de usuario, página 24, imagen 119" />
<figcaption aria-hidden="true">Manual de usuario, página 24, imagen
119</figcaption>
</figure>

<figure>
<img src="assets/manual/image-120.png" style="width:1.1in"
alt="Manual de usuario, página 24, imagen 120" />
<figcaption aria-hidden="true">Manual de usuario, página 24, imagen
120</figcaption>
</figure>

<figure>
<img src="assets/manual/image-121.png" style="width:1.1in"
alt="Manual de usuario, página 24, imagen 121" />
<figcaption aria-hidden="true">Manual de usuario, página 24, imagen
121</figcaption>
</figure>

<figure>
<img src="assets/manual/image-122.png" style="width:3.3in"
alt="Manual de usuario, página 24, imagen 122" />
<figcaption aria-hidden="true">Manual de usuario, página 24, imagen
122</figcaption>
</figure>

<figure>
<img src="assets/manual/image-123.png" style="width:3.3in"
alt="Manual de usuario, página 24, imagen 123" />
<figcaption aria-hidden="true">Manual de usuario, página 24, imagen
123</figcaption>
</figure>

#### Página 25 del manual

<figure>
<img src="assets/manual/image-124.png" style="width:3.3in"
alt="Manual de usuario, página 25, imagen 124" />
<figcaption aria-hidden="true">Manual de usuario, página 25, imagen
124</figcaption>
</figure>

#### Página 26 del manual

<figure>
<img src="assets/manual/image-125.png" style="width:3.3in"
alt="Manual de usuario, página 26, imagen 125" />
<figcaption aria-hidden="true">Manual de usuario, página 26, imagen
125</figcaption>
</figure>

#### Página 27 del manual

<figure>
<img src="assets/manual/image-126.png" style="width:3.3in"
alt="Manual de usuario, página 27, imagen 126" />
<figcaption aria-hidden="true">Manual de usuario, página 27, imagen
126</figcaption>
</figure>

<figure>
<img src="assets/manual/image-127.png" style="width:1.1in"
alt="Manual de usuario, página 27, imagen 127" />
<figcaption aria-hidden="true">Manual de usuario, página 27, imagen
127</figcaption>
</figure>

<figure>
<img src="assets/manual/image-128.png" style="width:0.65in"
alt="Manual de usuario, página 27, imagen 128" />
<figcaption aria-hidden="true">Manual de usuario, página 27, imagen
128</figcaption>
</figure>

<figure>
<img src="assets/manual/image-129.png" style="width:1.1in"
alt="Manual de usuario, página 27, imagen 129" />
<figcaption aria-hidden="true">Manual de usuario, página 27, imagen
129</figcaption>
</figure>

<figure>
<img src="assets/manual/image-130.png" style="width:1.1in"
alt="Manual de usuario, página 27, imagen 130" />
<figcaption aria-hidden="true">Manual de usuario, página 27, imagen
130</figcaption>
</figure>

<figure>
<img src="assets/manual/image-131.png" style="width:1.1in"
alt="Manual de usuario, página 27, imagen 131" />
<figcaption aria-hidden="true">Manual de usuario, página 27, imagen
131</figcaption>
</figure>

<figure>
<img src="assets/manual/image-132.png" style="width:0.65in"
alt="Manual de usuario, página 27, imagen 132" />
<figcaption aria-hidden="true">Manual de usuario, página 27, imagen
132</figcaption>
</figure>

<figure>
<img src="assets/manual/image-133.png" style="width:1.1in"
alt="Manual de usuario, página 27, imagen 133" />
<figcaption aria-hidden="true">Manual de usuario, página 27, imagen
133</figcaption>
</figure>

<figure>
<img src="assets/manual/image-134.png" style="width:0.65in"
alt="Manual de usuario, página 27, imagen 134" />
<figcaption aria-hidden="true">Manual de usuario, página 27, imagen
134</figcaption>
</figure>

<figure>
<img src="assets/manual/image-135.png" style="width:1.1in"
alt="Manual de usuario, página 27, imagen 135" />
<figcaption aria-hidden="true">Manual de usuario, página 27, imagen
135</figcaption>
</figure>

<figure>
<img src="assets/manual/image-136.png" style="width:1.1in"
alt="Manual de usuario, página 27, imagen 136" />
<figcaption aria-hidden="true">Manual de usuario, página 27, imagen
136</figcaption>
</figure>

#### Página 28 del manual

<figure>
<img src="assets/manual/image-137.png" style="width:3.3in"
alt="Manual de usuario, página 28, imagen 137" />
<figcaption aria-hidden="true">Manual de usuario, página 28, imagen
137</figcaption>
</figure>

<figure>
<img src="assets/manual/image-138.png" style="width:3.3in"
alt="Manual de usuario, página 28, imagen 138" />
<figcaption aria-hidden="true">Manual de usuario, página 28, imagen
138</figcaption>
</figure>

#### Página 29 del manual

<figure>
<img src="assets/manual/image-139.png" style="width:3.3in"
alt="Manual de usuario, página 29, imagen 139" />
<figcaption aria-hidden="true">Manual de usuario, página 29, imagen
139</figcaption>
</figure>

<figure>
<img src="assets/manual/image-140.png" style="width:3.3in"
alt="Manual de usuario, página 29, imagen 140" />
<figcaption aria-hidden="true">Manual de usuario, página 29, imagen
140</figcaption>
</figure>

#### Página 30 del manual

<figure>
<img src="assets/manual/image-141.png" style="width:2in"
alt="Manual de usuario, página 30, imagen 141" />
<figcaption aria-hidden="true">Manual de usuario, página 30, imagen
141</figcaption>
</figure>

<figure>
<img src="assets/manual/image-142.png" style="width:1.1in"
alt="Manual de usuario, página 30, imagen 142" />
<figcaption aria-hidden="true">Manual de usuario, página 30, imagen
142</figcaption>
</figure>

<figure>
<img src="assets/manual/image-143.png" style="width:0.65in"
alt="Manual de usuario, página 30, imagen 143" />
<figcaption aria-hidden="true">Manual de usuario, página 30, imagen
143</figcaption>
</figure>

<figure>
<img src="assets/manual/image-144.png" style="width:1.1in"
alt="Manual de usuario, página 30, imagen 144" />
<figcaption aria-hidden="true">Manual de usuario, página 30, imagen
144</figcaption>
</figure>

<figure>
<img src="assets/manual/image-145.png" style="width:1.1in"
alt="Manual de usuario, página 30, imagen 145" />
<figcaption aria-hidden="true">Manual de usuario, página 30, imagen
145</figcaption>
</figure>

<figure>
<img src="assets/manual/image-146.png" style="width:0.65in"
alt="Manual de usuario, página 30, imagen 146" />
<figcaption aria-hidden="true">Manual de usuario, página 30, imagen
146</figcaption>
</figure>

<figure>
<img src="assets/manual/image-147.png" style="width:1.1in"
alt="Manual de usuario, página 30, imagen 147" />
<figcaption aria-hidden="true">Manual de usuario, página 30, imagen
147</figcaption>
</figure>

<figure>
<img src="assets/manual/image-148.png" style="width:1.1in"
alt="Manual de usuario, página 30, imagen 148" />
<figcaption aria-hidden="true">Manual de usuario, página 30, imagen
148</figcaption>
</figure>

<figure>
<img src="assets/manual/image-149.png" style="width:0.65in"
alt="Manual de usuario, página 30, imagen 149" />
<figcaption aria-hidden="true">Manual de usuario, página 30, imagen
149</figcaption>
</figure>

<figure>
<img src="assets/manual/image-150.png" style="width:1.1in"
alt="Manual de usuario, página 30, imagen 150" />
<figcaption aria-hidden="true">Manual de usuario, página 30, imagen
150</figcaption>
</figure>

<figure>
<img src="assets/manual/image-151.png" style="width:1.1in"
alt="Manual de usuario, página 30, imagen 151" />
<figcaption aria-hidden="true">Manual de usuario, página 30, imagen
151</figcaption>
</figure>

<figure>
<img src="assets/manual/image-152.png" style="width:1.1in"
alt="Manual de usuario, página 30, imagen 152" />
<figcaption aria-hidden="true">Manual de usuario, página 30, imagen
152</figcaption>
</figure>

<figure>
<img src="assets/manual/image-153.png" style="width:1.1in"
alt="Manual de usuario, página 30, imagen 153" />
<figcaption aria-hidden="true">Manual de usuario, página 30, imagen
153</figcaption>
</figure>

<figure>
<img src="assets/manual/image-154.png" style="width:1.1in"
alt="Manual de usuario, página 30, imagen 154" />
<figcaption aria-hidden="true">Manual de usuario, página 30, imagen
154</figcaption>
</figure>

<figure>
<img src="assets/manual/image-155.png" style="width:1.1in"
alt="Manual de usuario, página 30, imagen 155" />
<figcaption aria-hidden="true">Manual de usuario, página 30, imagen
155</figcaption>
</figure>

<figure>
<img src="assets/manual/image-156.png" style="width:3.3in"
alt="Manual de usuario, página 30, imagen 156" />
<figcaption aria-hidden="true">Manual de usuario, página 30, imagen
156</figcaption>
</figure>

#### Página 31 del manual

<figure>
<img src="assets/manual/image-157.png" style="width:3.3in"
alt="Manual de usuario, página 31, imagen 157" />
<figcaption aria-hidden="true">Manual de usuario, página 31, imagen
157</figcaption>
</figure>

<figure>
<img src="assets/manual/image-158.png" style="width:3.3in"
alt="Manual de usuario, página 31, imagen 158" />
<figcaption aria-hidden="true">Manual de usuario, página 31, imagen
158</figcaption>
</figure>

#### Página 32 del manual

<figure>
<img src="assets/manual/image-159.png" style="width:3.3in"
alt="Manual de usuario, página 32, imagen 159" />
<figcaption aria-hidden="true">Manual de usuario, página 32, imagen
159</figcaption>
</figure>

<figure>
<img src="assets/manual/image-160.png" style="width:3.3in"
alt="Manual de usuario, página 32, imagen 160" />
<figcaption aria-hidden="true">Manual de usuario, página 32, imagen
160</figcaption>
</figure>

#### Página 33 del manual

<figure>
<img src="assets/manual/image-161.png" style="width:3.3in"
alt="Manual de usuario, página 33, imagen 161" />
<figcaption aria-hidden="true">Manual de usuario, página 33, imagen
161</figcaption>
</figure>

<figure>
<img src="assets/manual/image-162.png" style="width:3.3in"
alt="Manual de usuario, página 33, imagen 162" />
<figcaption aria-hidden="true">Manual de usuario, página 33, imagen
162</figcaption>
</figure>

<figure>
<img src="assets/manual/image-163.png" style="width:3.3in"
alt="Manual de usuario, página 33, imagen 163" />
<figcaption aria-hidden="true">Manual de usuario, página 33, imagen
163</figcaption>
</figure>

#### Página 34 del manual

<figure>
<img src="assets/manual/image-164.png" style="width:3.3in"
alt="Manual de usuario, página 34, imagen 164" />
<figcaption aria-hidden="true">Manual de usuario, página 34, imagen
164</figcaption>
</figure>

<figure>
<img src="assets/manual/image-165.png" style="width:3.3in"
alt="Manual de usuario, página 34, imagen 165" />
<figcaption aria-hidden="true">Manual de usuario, página 34, imagen
165</figcaption>
</figure>

#### Página 35 del manual

<figure>
<img src="assets/manual/image-166.png" style="width:3.3in"
alt="Manual de usuario, página 35, imagen 166" />
<figcaption aria-hidden="true">Manual de usuario, página 35, imagen
166</figcaption>
</figure>

<figure>
<img src="assets/manual/image-167.png" style="width:1.1in"
alt="Manual de usuario, página 35, imagen 167" />
<figcaption aria-hidden="true">Manual de usuario, página 35, imagen
167</figcaption>
</figure>

<figure>
<img src="assets/manual/image-168.png" style="width:1.1in"
alt="Manual de usuario, página 35, imagen 168" />
<figcaption aria-hidden="true">Manual de usuario, página 35, imagen
168</figcaption>
</figure>

<figure>
<img src="assets/manual/image-169.png" style="width:1.1in"
alt="Manual de usuario, página 35, imagen 169" />
<figcaption aria-hidden="true">Manual de usuario, página 35, imagen
169</figcaption>
</figure>

<figure>
<img src="assets/manual/image-170.png" style="width:1.1in"
alt="Manual de usuario, página 35, imagen 170" />
<figcaption aria-hidden="true">Manual de usuario, página 35, imagen
170</figcaption>
</figure>

<figure>
<img src="assets/manual/image-171.png" style="width:1.1in"
alt="Manual de usuario, página 35, imagen 171" />
<figcaption aria-hidden="true">Manual de usuario, página 35, imagen
171</figcaption>
</figure>

<figure>
<img src="assets/manual/image-172.png" style="width:1.1in"
alt="Manual de usuario, página 35, imagen 172" />
<figcaption aria-hidden="true">Manual de usuario, página 35, imagen
172</figcaption>
</figure>

<figure>
<img src="assets/manual/image-173.png" style="width:1.1in"
alt="Manual de usuario, página 35, imagen 173" />
<figcaption aria-hidden="true">Manual de usuario, página 35, imagen
173</figcaption>
</figure>

<figure>
<img src="assets/manual/image-174.png" style="width:1.1in"
alt="Manual de usuario, página 35, imagen 174" />
<figcaption aria-hidden="true">Manual de usuario, página 35, imagen
174</figcaption>
</figure>

<figure>
<img src="assets/manual/image-175.png" style="width:0.65in"
alt="Manual de usuario, página 35, imagen 175" />
<figcaption aria-hidden="true">Manual de usuario, página 35, imagen
175</figcaption>
</figure>

<figure>
<img src="assets/manual/image-176.png" style="width:1.1in"
alt="Manual de usuario, página 35, imagen 176" />
<figcaption aria-hidden="true">Manual de usuario, página 35, imagen
176</figcaption>
</figure>

<figure>
<img src="assets/manual/image-177.png" style="width:0.65in"
alt="Manual de usuario, página 35, imagen 177" />
<figcaption aria-hidden="true">Manual de usuario, página 35, imagen
177</figcaption>
</figure>

<figure>
<img src="assets/manual/image-178.png" style="width:1.1in"
alt="Manual de usuario, página 35, imagen 178" />
<figcaption aria-hidden="true">Manual de usuario, página 35, imagen
178</figcaption>
</figure>

<figure>
<img src="assets/manual/image-179.png" style="width:1.1in"
alt="Manual de usuario, página 35, imagen 179" />
<figcaption aria-hidden="true">Manual de usuario, página 35, imagen
179</figcaption>
</figure>

<figure>
<img src="assets/manual/image-180.png" style="width:1.1in"
alt="Manual de usuario, página 35, imagen 180" />
<figcaption aria-hidden="true">Manual de usuario, página 35, imagen
180</figcaption>
</figure>

#### Página 36 del manual

<figure>
<img src="assets/manual/image-181.png" style="width:3.3in"
alt="Manual de usuario, página 36, imagen 181" />
<figcaption aria-hidden="true">Manual de usuario, página 36, imagen
181</figcaption>
</figure>

<figure>
<img src="assets/manual/image-182.png" style="width:3.3in"
alt="Manual de usuario, página 36, imagen 182" />
<figcaption aria-hidden="true">Manual de usuario, página 36, imagen
182</figcaption>
</figure>

<figure>
<img src="assets/manual/image-183.png" style="width:3.3in"
alt="Manual de usuario, página 36, imagen 183" />
<figcaption aria-hidden="true">Manual de usuario, página 36, imagen
183</figcaption>
</figure>

#### Página 37 del manual

<figure>
<img src="assets/manual/image-184.png" style="width:3.3in"
alt="Manual de usuario, página 37, imagen 184" />
<figcaption aria-hidden="true">Manual de usuario, página 37, imagen
184</figcaption>
</figure>

<figure>
<img src="assets/manual/image-185.png" style="width:3.3in"
alt="Manual de usuario, página 37, imagen 185" />
<figcaption aria-hidden="true">Manual de usuario, página 37, imagen
185</figcaption>
</figure>

<figure>
<img src="assets/manual/image-186.png" style="width:3.3in"
alt="Manual de usuario, página 37, imagen 186" />
<figcaption aria-hidden="true">Manual de usuario, página 37, imagen
186</figcaption>
</figure>

#### Página 38 del manual

<figure>
<img src="assets/manual/image-187.png" style="width:3.3in"
alt="Manual de usuario, página 38, imagen 187" />
<figcaption aria-hidden="true">Manual de usuario, página 38, imagen
187</figcaption>
</figure>

<figure>
<img src="assets/manual/image-188.png" style="width:3.3in"
alt="Manual de usuario, página 38, imagen 188" />
<figcaption aria-hidden="true">Manual de usuario, página 38, imagen
188</figcaption>
</figure>

<figure>
<img src="assets/manual/image-189.png" style="width:3.3in"
alt="Manual de usuario, página 38, imagen 189" />
<figcaption aria-hidden="true">Manual de usuario, página 38, imagen
189</figcaption>
</figure>

<figure>
<img src="assets/manual/image-190.png" style="width:3.3in"
alt="Manual de usuario, página 38, imagen 190" />
<figcaption aria-hidden="true">Manual de usuario, página 38, imagen
190</figcaption>
</figure>

<figure>
<img src="assets/manual/image-191.png" style="width:3.3in"
alt="Manual de usuario, página 38, imagen 191" />
<figcaption aria-hidden="true">Manual de usuario, página 38, imagen
191</figcaption>
</figure>

<figure>
<img src="assets/manual/image-192.png" style="width:3.3in"
alt="Manual de usuario, página 38, imagen 192" />
<figcaption aria-hidden="true">Manual de usuario, página 38, imagen
192</figcaption>
</figure>

<figure>
<img src="assets/manual/image-193.png" style="width:3.3in"
alt="Manual de usuario, página 38, imagen 193" />
<figcaption aria-hidden="true">Manual de usuario, página 38, imagen
193</figcaption>
</figure>

<figure>
<img src="assets/manual/image-194.png" style="width:3.3in"
alt="Manual de usuario, página 38, imagen 194" />
<figcaption aria-hidden="true">Manual de usuario, página 38, imagen
194</figcaption>
</figure>

#### Página 39 del manual

<figure>
<img src="assets/manual/image-195.png" style="width:3.3in"
alt="Manual de usuario, página 39, imagen 195" />
<figcaption aria-hidden="true">Manual de usuario, página 39, imagen
195</figcaption>
</figure>

<figure>
<img src="assets/manual/image-196.png" style="width:3.3in"
alt="Manual de usuario, página 39, imagen 196" />
<figcaption aria-hidden="true">Manual de usuario, página 39, imagen
196</figcaption>
</figure>

<figure>
<img src="assets/manual/image-197.png" style="width:3.3in"
alt="Manual de usuario, página 39, imagen 197" />
<figcaption aria-hidden="true">Manual de usuario, página 39, imagen
197</figcaption>
</figure>

#### Página 40 del manual

<figure>
<img src="assets/manual/image-198.png" style="width:3.3in"
alt="Manual de usuario, página 40, imagen 198" />
<figcaption aria-hidden="true">Manual de usuario, página 40, imagen
198</figcaption>
</figure>

<figure>
<img src="assets/manual/image-199.png" style="width:1.1in"
alt="Manual de usuario, página 40, imagen 199" />
<figcaption aria-hidden="true">Manual de usuario, página 40, imagen
199</figcaption>
</figure>

<figure>
<img src="assets/manual/image-200.png" style="width:1.1in"
alt="Manual de usuario, página 40, imagen 200" />
<figcaption aria-hidden="true">Manual de usuario, página 40, imagen
200</figcaption>
</figure>

<figure>
<img src="assets/manual/image-201.png" style="width:1.1in"
alt="Manual de usuario, página 40, imagen 201" />
<figcaption aria-hidden="true">Manual de usuario, página 40, imagen
201</figcaption>
</figure>

<figure>
<img src="assets/manual/image-202.png" style="width:1.1in"
alt="Manual de usuario, página 40, imagen 202" />
<figcaption aria-hidden="true">Manual de usuario, página 40, imagen
202</figcaption>
</figure>

<figure>
<img src="assets/manual/image-203.png" style="width:1.1in"
alt="Manual de usuario, página 40, imagen 203" />
<figcaption aria-hidden="true">Manual de usuario, página 40, imagen
203</figcaption>
</figure>

<figure>
<img src="assets/manual/image-204.png" style="width:1.1in"
alt="Manual de usuario, página 40, imagen 204" />
<figcaption aria-hidden="true">Manual de usuario, página 40, imagen
204</figcaption>
</figure>

<figure>
<img src="assets/manual/image-205.png" style="width:1.1in"
alt="Manual de usuario, página 40, imagen 205" />
<figcaption aria-hidden="true">Manual de usuario, página 40, imagen
205</figcaption>
</figure>

<figure>
<img src="assets/manual/image-206.png" style="width:1.1in"
alt="Manual de usuario, página 40, imagen 206" />
<figcaption aria-hidden="true">Manual de usuario, página 40, imagen
206</figcaption>
</figure>

<figure>
<img src="assets/manual/image-207.png" style="width:1.1in"
alt="Manual de usuario, página 40, imagen 207" />
<figcaption aria-hidden="true">Manual de usuario, página 40, imagen
207</figcaption>
</figure>

<figure>
<img src="assets/manual/image-208.png" style="width:0.65in"
alt="Manual de usuario, página 40, imagen 208" />
<figcaption aria-hidden="true">Manual de usuario, página 40, imagen
208</figcaption>
</figure>

<figure>
<img src="assets/manual/image-209.png" style="width:0.65in"
alt="Manual de usuario, página 40, imagen 209" />
<figcaption aria-hidden="true">Manual de usuario, página 40, imagen
209</figcaption>
</figure>

<figure>
<img src="assets/manual/image-210.png" style="width:1.1in"
alt="Manual de usuario, página 40, imagen 210" />
<figcaption aria-hidden="true">Manual de usuario, página 40, imagen
210</figcaption>
</figure>

<figure>
<img src="assets/manual/image-211.png" style="width:1.1in"
alt="Manual de usuario, página 40, imagen 211" />
<figcaption aria-hidden="true">Manual de usuario, página 40, imagen
211</figcaption>
</figure>

<figure>
<img src="assets/manual/image-212.png" style="width:1.1in"
alt="Manual de usuario, página 40, imagen 212" />
<figcaption aria-hidden="true">Manual de usuario, página 40, imagen
212</figcaption>
</figure>

<figure>
<img src="assets/manual/image-213.png" style="width:1.1in"
alt="Manual de usuario, página 40, imagen 213" />
<figcaption aria-hidden="true">Manual de usuario, página 40, imagen
213</figcaption>
</figure>

<figure>
<img src="assets/manual/image-214.png" style="width:1.1in"
alt="Manual de usuario, página 40, imagen 214" />
<figcaption aria-hidden="true">Manual de usuario, página 40, imagen
214</figcaption>
</figure>

<figure>
<img src="assets/manual/image-215.png" style="width:1.1in"
alt="Manual de usuario, página 40, imagen 215" />
<figcaption aria-hidden="true">Manual de usuario, página 40, imagen
215</figcaption>
</figure>

<figure>
<img src="assets/manual/image-216.png" style="width:1.1in"
alt="Manual de usuario, página 40, imagen 216" />
<figcaption aria-hidden="true">Manual de usuario, página 40, imagen
216</figcaption>
</figure>

<figure>
<img src="assets/manual/image-217.png" style="width:1.1in"
alt="Manual de usuario, página 40, imagen 217" />
<figcaption aria-hidden="true">Manual de usuario, página 40, imagen
217</figcaption>
</figure>

#### Página 41 del manual

<figure>
<img src="assets/manual/image-218.png" style="width:3.3in"
alt="Manual de usuario, página 41, imagen 218" />
<figcaption aria-hidden="true">Manual de usuario, página 41, imagen
218</figcaption>
</figure>

<figure>
<img src="assets/manual/image-219.png" style="width:3.3in"
alt="Manual de usuario, página 41, imagen 219" />
<figcaption aria-hidden="true">Manual de usuario, página 41, imagen
219</figcaption>
</figure>

#### Página 42 del manual

<figure>
<img src="assets/manual/image-220.png" style="width:2in"
alt="Manual de usuario, página 42, imagen 220" />
<figcaption aria-hidden="true">Manual de usuario, página 42, imagen
220</figcaption>
</figure>

<figure>
<img src="assets/manual/image-221.png" style="width:3.3in"
alt="Manual de usuario, página 42, imagen 221" />
<figcaption aria-hidden="true">Manual de usuario, página 42, imagen
221</figcaption>
</figure>

#### Página 43 del manual

<figure>
<img src="assets/manual/image-222.png" style="width:3.3in"
alt="Manual de usuario, página 43, imagen 222" />
<figcaption aria-hidden="true">Manual de usuario, página 43, imagen
222</figcaption>
</figure>

<figure>
<img src="assets/manual/image-223.png" style="width:3.3in"
alt="Manual de usuario, página 43, imagen 223" />
<figcaption aria-hidden="true">Manual de usuario, página 43, imagen
223</figcaption>
</figure>

<figure>
<img src="assets/manual/image-224.png" style="width:3.3in"
alt="Manual de usuario, página 43, imagen 224" />
<figcaption aria-hidden="true">Manual de usuario, página 43, imagen
224</figcaption>
</figure>

#### Página 44 del manual

<figure>
<img src="assets/manual/image-225.png" style="width:3.3in"
alt="Manual de usuario, página 44, imagen 225" />
<figcaption aria-hidden="true">Manual de usuario, página 44, imagen
225</figcaption>
</figure>

<figure>
<img src="assets/manual/image-226.png" style="width:3.3in"
alt="Manual de usuario, página 44, imagen 226" />
<figcaption aria-hidden="true">Manual de usuario, página 44, imagen
226</figcaption>
</figure>

#### Página 45 del manual

<figure>
<img src="assets/manual/image-227.png" style="width:3.3in"
alt="Manual de usuario, página 45, imagen 227" />
<figcaption aria-hidden="true">Manual de usuario, página 45, imagen
227</figcaption>
</figure>

<figure>
<img src="assets/manual/image-228.png" style="width:3.3in"
alt="Manual de usuario, página 45, imagen 228" />
<figcaption aria-hidden="true">Manual de usuario, página 45, imagen
228</figcaption>
</figure>

<figure>
<img src="assets/manual/image-229.png" style="width:3.3in"
alt="Manual de usuario, página 45, imagen 229" />
<figcaption aria-hidden="true">Manual de usuario, página 45, imagen
229</figcaption>
</figure>

#### Página 46 del manual

<figure>
<img src="assets/manual/image-230.png" style="width:3.3in"
alt="Manual de usuario, página 46, imagen 230" />
<figcaption aria-hidden="true">Manual de usuario, página 46, imagen
230</figcaption>
</figure>

<figure>
<img src="assets/manual/image-231.png" style="width:3.3in"
alt="Manual de usuario, página 46, imagen 231" />
<figcaption aria-hidden="true">Manual de usuario, página 46, imagen
231</figcaption>
</figure>

### Cableado y diagramas

#### Página 47 del manual

<figure>
<img src="assets/manual/image-232.png" style="width:3.3in"
alt="Manual de usuario, página 47, imagen 232" />
<figcaption aria-hidden="true">Manual de usuario, página 47, imagen
232</figcaption>
</figure>

#### Página 48 del manual

<figure>
<img src="assets/manual/image-233.png" style="width:3.3in"
alt="Manual de usuario, página 48, imagen 233" />
<figcaption aria-hidden="true">Manual de usuario, página 48, imagen
233</figcaption>
</figure>

<figure>
<img src="assets/manual/image-234.png" style="width:3.3in"
alt="Manual de usuario, página 48, imagen 234" />
<figcaption aria-hidden="true">Manual de usuario, página 48, imagen
234</figcaption>
</figure>

#### Página 49 del manual

<figure>
<img src="assets/manual/image-235.png" style="width:3.3in"
alt="Manual de usuario, página 49, imagen 235" />
<figcaption aria-hidden="true">Manual de usuario, página 49, imagen
235</figcaption>
</figure>

<figure>
<img src="assets/manual/image-236.png" style="width:3.3in"
alt="Manual de usuario, página 49, imagen 236" />
<figcaption aria-hidden="true">Manual de usuario, página 49, imagen
236</figcaption>
</figure>

#### Página 50 del manual

<figure>
<img src="assets/manual/image-237.png" style="width:3.3in"
alt="Manual de usuario, página 50, imagen 237" />
<figcaption aria-hidden="true">Manual de usuario, página 50, imagen
237</figcaption>
</figure>

<figure>
<img src="assets/manual/image-238.png" style="width:3.3in"
alt="Manual de usuario, página 50, imagen 238" />
<figcaption aria-hidden="true">Manual de usuario, página 50, imagen
238</figcaption>
</figure>

#### Página 51 del manual

<figure>
<img src="assets/manual/image-239.png" style="width:3.3in"
alt="Manual de usuario, página 51, imagen 239" />
<figcaption aria-hidden="true">Manual de usuario, página 51, imagen
239</figcaption>
</figure>

<figure>
<img src="assets/manual/image-240.png" style="width:3.3in"
alt="Manual de usuario, página 51, imagen 240" />
<figcaption aria-hidden="true">Manual de usuario, página 51, imagen
240</figcaption>
</figure>

#### Página 52 del manual

<figure>
<img src="assets/manual/image-241.png" style="width:3.3in"
alt="Manual de usuario, página 52, imagen 241" />
<figcaption aria-hidden="true">Manual de usuario, página 52, imagen
241</figcaption>
</figure>

<figure>
<img src="assets/manual/image-242.png" style="width:3.3in"
alt="Manual de usuario, página 52, imagen 242" />
<figcaption aria-hidden="true">Manual de usuario, página 52, imagen
242</figcaption>
</figure>

#### Página 53 del manual

<figure>
<img src="assets/manual/image-243.png" style="width:3.3in"
alt="Manual de usuario, página 53, imagen 243" />
<figcaption aria-hidden="true">Manual de usuario, página 53, imagen
243</figcaption>
</figure>

<figure>
<img src="assets/manual/image-244.png" style="width:3.3in"
alt="Manual de usuario, página 53, imagen 244" />
<figcaption aria-hidden="true">Manual de usuario, página 53, imagen
244</figcaption>
</figure>

<figure>
<img src="assets/manual/image-245.png" style="width:3.3in"
alt="Manual de usuario, página 53, imagen 245" />
<figcaption aria-hidden="true">Manual de usuario, página 53, imagen
245</figcaption>
</figure>

#### Página 54 del manual

<figure>
<img src="assets/manual/image-246.png" style="width:3.3in"
alt="Manual de usuario, página 54, imagen 246" />
<figcaption aria-hidden="true">Manual de usuario, página 54, imagen
246</figcaption>
</figure>

<figure>
<img src="assets/manual/image-247.png" style="width:3.3in"
alt="Manual de usuario, página 54, imagen 247" />
<figcaption aria-hidden="true">Manual de usuario, página 54, imagen
247</figcaption>
</figure>

<figure>
<img src="assets/manual/image-248.png" style="width:3.3in"
alt="Manual de usuario, página 54, imagen 248" />
<figcaption aria-hidden="true">Manual de usuario, página 54, imagen
248</figcaption>
</figure>

<figure>
<img src="assets/manual/image-249.png" style="width:3.3in"
alt="Manual de usuario, página 54, imagen 249" />
<figcaption aria-hidden="true">Manual de usuario, página 54, imagen
249</figcaption>
</figure>

#### Página 55 del manual

<figure>
<img src="assets/manual/image-250.png" style="width:3.3in"
alt="Manual de usuario, página 55, imagen 250" />
<figcaption aria-hidden="true">Manual de usuario, página 55, imagen
250</figcaption>
</figure>

<figure>
<img src="assets/manual/image-251.png" style="width:3.3in"
alt="Manual de usuario, página 55, imagen 251" />
<figcaption aria-hidden="true">Manual de usuario, página 55, imagen
251</figcaption>
</figure>

<figure>
<img src="assets/manual/image-252.png" style="width:3.3in"
alt="Manual de usuario, página 55, imagen 252" />
<figcaption aria-hidden="true">Manual de usuario, página 55, imagen
252</figcaption>
</figure>

#### Página 56 del manual

<figure>
<img src="assets/manual/image-253.png" style="width:3.3in"
alt="Manual de usuario, página 56, imagen 253" />
<figcaption aria-hidden="true">Manual de usuario, página 56, imagen
253</figcaption>
</figure>

<figure>
<img src="assets/manual/image-254.png" style="width:3.3in"
alt="Manual de usuario, página 56, imagen 254" />
<figcaption aria-hidden="true">Manual de usuario, página 56, imagen
254</figcaption>
</figure>

<figure>
<img src="assets/manual/image-255.png" style="width:3.3in"
alt="Manual de usuario, página 56, imagen 255" />
<figcaption aria-hidden="true">Manual de usuario, página 56, imagen
255</figcaption>
</figure>

#### Página 57 del manual

<figure>
<img src="assets/manual/image-256.png" style="width:3.3in"
alt="Manual de usuario, página 57, imagen 256" />
<figcaption aria-hidden="true">Manual de usuario, página 57, imagen
256</figcaption>
</figure>

<figure>
<img src="assets/manual/image-257.png" style="width:3.3in"
alt="Manual de usuario, página 57, imagen 257" />
<figcaption aria-hidden="true">Manual de usuario, página 57, imagen
257</figcaption>
</figure>

<figure>
<img src="assets/manual/image-258.png" style="width:1.1in"
alt="Manual de usuario, página 57, imagen 258" />
<figcaption aria-hidden="true">Manual de usuario, página 57, imagen
258</figcaption>
</figure>

#### Página 58 del manual

<figure>
<img src="assets/manual/image-259.png" style="width:3.3in"
alt="Manual de usuario, página 58, imagen 259" />
<figcaption aria-hidden="true">Manual de usuario, página 58, imagen
259</figcaption>
</figure>

<figure>
<img src="assets/manual/image-260.png" style="width:2in"
alt="Manual de usuario, página 58, imagen 260" />
<figcaption aria-hidden="true">Manual de usuario, página 58, imagen
260</figcaption>
</figure>

#### Página 59 del manual

<figure>
<img src="assets/manual/image-261.png" style="width:3.3in"
alt="Manual de usuario, página 59, imagen 261" />
<figcaption aria-hidden="true">Manual de usuario, página 59, imagen
261</figcaption>
</figure>

<figure>
<img src="assets/manual/image-262.png" style="width:3.3in"
alt="Manual de usuario, página 59, imagen 262" />
<figcaption aria-hidden="true">Manual de usuario, página 59, imagen
262</figcaption>
</figure>

#### Página 60 del manual

<figure>
<img src="assets/manual/image-263.png" style="width:3.3in"
alt="Manual de usuario, página 60, imagen 263" />
<figcaption aria-hidden="true">Manual de usuario, página 60, imagen
263</figcaption>
</figure>

<figure>
<img src="assets/manual/image-264.png" style="width:3.3in"
alt="Manual de usuario, página 60, imagen 264" />
<figcaption aria-hidden="true">Manual de usuario, página 60, imagen
264</figcaption>
</figure>

#### Página 61 del manual

<figure>
<img src="assets/manual/image-265.png" style="width:3.3in"
alt="Manual de usuario, página 61, imagen 265" />
<figcaption aria-hidden="true">Manual de usuario, página 61, imagen
265</figcaption>
</figure>

<figure>
<img src="assets/manual/image-266.png" style="width:3.3in"
alt="Manual de usuario, página 61, imagen 266" />
<figcaption aria-hidden="true">Manual de usuario, página 61, imagen
266</figcaption>
</figure>

#### Página 62 del manual

<figure>
<img src="assets/manual/image-267.png" style="width:3.3in"
alt="Manual de usuario, página 62, imagen 267" />
<figcaption aria-hidden="true">Manual de usuario, página 62, imagen
267</figcaption>
</figure>

<figure>
<img src="assets/manual/image-268.png" style="width:3.3in"
alt="Manual de usuario, página 62, imagen 268" />
<figcaption aria-hidden="true">Manual de usuario, página 62, imagen
268</figcaption>
</figure>

#### Página 63 del manual

<figure>
<img src="assets/manual/image-269.png" style="width:3.3in"
alt="Manual de usuario, página 63, imagen 269" />
<figcaption aria-hidden="true">Manual de usuario, página 63, imagen
269</figcaption>
</figure>

<figure>
<img src="assets/manual/image-270.png" style="width:3.3in"
alt="Manual de usuario, página 63, imagen 270" />
<figcaption aria-hidden="true">Manual de usuario, página 63, imagen
270</figcaption>
</figure>

#### Página 64 del manual

<figure>
<img src="assets/manual/image-271.png" style="width:3.3in"
alt="Manual de usuario, página 64, imagen 271" />
<figcaption aria-hidden="true">Manual de usuario, página 64, imagen
271</figcaption>
</figure>

<figure>
<img src="assets/manual/image-272.png" style="width:3.3in"
alt="Manual de usuario, página 64, imagen 272" />
<figcaption aria-hidden="true">Manual de usuario, página 64, imagen
272</figcaption>
</figure>

#### Página 65 del manual

<figure>
<img src="assets/manual/image-273.png" style="width:3.3in"
alt="Manual de usuario, página 65, imagen 273" />
<figcaption aria-hidden="true">Manual de usuario, página 65, imagen
273</figcaption>
</figure>

<figure>
<img src="assets/manual/image-274.png" style="width:3.3in"
alt="Manual de usuario, página 65, imagen 274" />
<figcaption aria-hidden="true">Manual de usuario, página 65, imagen
274</figcaption>
</figure>

#### Página 66 del manual

<figure>
<img src="assets/manual/image-275.png" style="width:5.8in"
alt="Manual de usuario, página 66, imagen 275" />
<figcaption aria-hidden="true">Manual de usuario, página 66, imagen
275</figcaption>
</figure>

#### Página 67 del manual

<figure>
<img src="assets/manual/image-276.png" style="width:5.8in"
alt="Manual de usuario, página 67, imagen 276" />
<figcaption aria-hidden="true">Manual de usuario, página 67, imagen
276</figcaption>
</figure>

#### Página 68 del manual

<figure>
<img src="assets/manual/image-277.png" style="width:5.8in"
alt="Manual de usuario, página 68, imagen 277" />
<figcaption aria-hidden="true">Manual de usuario, página 68, imagen
277</figcaption>
</figure>

<figure>
<img src="assets/manual/image-278.png" style="width:5.8in"
alt="Manual de usuario, página 68, imagen 278" />
<figcaption aria-hidden="true">Manual de usuario, página 68, imagen
278</figcaption>
</figure>

<figure>
<img src="assets/manual/image-279.png" style="width:5.8in"
alt="Manual de usuario, página 68, imagen 279" />
<figcaption aria-hidden="true">Manual de usuario, página 68, imagen
279</figcaption>
</figure>

#### Página 69 del manual

<figure>
<img src="assets/manual/image-280.png" style="width:2in"
alt="Manual de usuario, página 69, imagen 280" />
<figcaption aria-hidden="true">Manual de usuario, página 69, imagen
280</figcaption>
</figure>

<figure>
<img src="assets/manual/image-281.png" style="width:2in"
alt="Manual de usuario, página 69, imagen 281" />
<figcaption aria-hidden="true">Manual de usuario, página 69, imagen
281</figcaption>
</figure>

<figure>
<img src="assets/manual/image-282.png" style="width:0.65in"
alt="Manual de usuario, página 69, imagen 282" />
<figcaption aria-hidden="true">Manual de usuario, página 69, imagen
282</figcaption>
</figure>

### Firmware y aplicación

#### Página 70 del manual

<figure>
<img src="assets/manual/image-283.jpg" style="width:3.3in"
alt="Manual de usuario, página 70, imagen 283" />
<figcaption aria-hidden="true">Manual de usuario, página 70, imagen
283</figcaption>
</figure>

<figure>
<img src="assets/manual/image-284.jpg" style="width:3.3in"
alt="Manual de usuario, página 70, imagen 284" />
<figcaption aria-hidden="true">Manual de usuario, página 70, imagen
284</figcaption>
</figure>

#### Página 71 del manual

<figure>
<img src="assets/manual/image-285.png" style="width:3.3in"
alt="Manual de usuario, página 71, imagen 285" />
<figcaption aria-hidden="true">Manual de usuario, página 71, imagen
285</figcaption>
</figure>

<figure>
<img src="assets/manual/image-286.png" style="width:3.3in"
alt="Manual de usuario, página 71, imagen 286" />
<figcaption aria-hidden="true">Manual de usuario, página 71, imagen
286</figcaption>
</figure>

<figure>
<img src="assets/manual/image-287.png" style="width:5.8in"
alt="Manual de usuario, página 71, imagen 287" />
<figcaption aria-hidden="true">Manual de usuario, página 71, imagen
287</figcaption>
</figure>

#### Página 72 del manual

<figure>
<img src="assets/manual/image-288.png" style="width:5.8in"
alt="Manual de usuario, página 72, imagen 288" />
<figcaption aria-hidden="true">Manual de usuario, página 72, imagen
288</figcaption>
</figure>

<figure>
<img src="assets/manual/image-289.png" style="width:5.8in"
alt="Manual de usuario, página 72, imagen 289" />
<figcaption aria-hidden="true">Manual de usuario, página 72, imagen
289</figcaption>
</figure>

#### Página 73 del manual

<figure>
<img src="assets/manual/image-290.png" style="width:5.8in"
alt="Manual de usuario, página 73, imagen 290" />
<figcaption aria-hidden="true">Manual de usuario, página 73, imagen
290</figcaption>
</figure>

<figure>
<img src="assets/manual/image-291.png" style="width:5.8in"
alt="Manual de usuario, página 73, imagen 291" />
<figcaption aria-hidden="true">Manual de usuario, página 73, imagen
291</figcaption>
</figure>

#### Página 74 del manual

<figure>
<img src="assets/manual/image-292.png" style="width:5.8in"
alt="Manual de usuario, página 74, imagen 292" />
<figcaption aria-hidden="true">Manual de usuario, página 74, imagen
292</figcaption>
</figure>

<figure>
<img src="assets/manual/image-293.png" style="width:3.3in"
alt="Manual de usuario, página 74, imagen 293" />
<figcaption aria-hidden="true">Manual de usuario, página 74, imagen
293</figcaption>
</figure>

#### Página 75 del manual

<figure>
<img src="assets/manual/image-294.png" style="width:3.3in"
alt="Manual de usuario, página 75, imagen 294" />
<figcaption aria-hidden="true">Manual de usuario, página 75, imagen
294</figcaption>
</figure>

<figure>
<img src="assets/manual/image-295.png" style="width:3.3in"
alt="Manual de usuario, página 75, imagen 295" />
<figcaption aria-hidden="true">Manual de usuario, página 75, imagen
295</figcaption>
</figure>

#### Página 76 del manual

<figure>
<img src="assets/manual/image-296.png" style="width:3.3in"
alt="Manual de usuario, página 76, imagen 296" />
<figcaption aria-hidden="true">Manual de usuario, página 76, imagen
296</figcaption>
</figure>

<figure>
<img src="assets/manual/image-297.png" style="width:3.3in"
alt="Manual de usuario, página 76, imagen 297" />
<figcaption aria-hidden="true">Manual de usuario, página 76, imagen
297</figcaption>
</figure>

<figure>
<img src="assets/manual/image-298.png" style="width:3.3in"
alt="Manual de usuario, página 76, imagen 298" />
<figcaption aria-hidden="true">Manual de usuario, página 76, imagen
298</figcaption>
</figure>

#### Página 77 del manual

<figure>
<img src="assets/manual/image-299.png" style="width:3.3in"
alt="Manual de usuario, página 77, imagen 299" />
<figcaption aria-hidden="true">Manual de usuario, página 77, imagen
299</figcaption>
</figure>

#### Página 78 del manual

<figure>
<img src="assets/manual/image-300.png" style="width:3.3in"
alt="Manual de usuario, página 78, imagen 300" />
<figcaption aria-hidden="true">Manual de usuario, página 78, imagen
300</figcaption>
</figure>

### Recursos y dimensiones

#### Página 79 del manual

<figure>
<img src="assets/manual/image-301.png" style="width:0.65in"
alt="Manual de usuario, página 79, imagen 301" />
<figcaption aria-hidden="true">Manual de usuario, página 79, imagen
301</figcaption>
</figure>

#### Página 80 del manual

<figure>
<img src="assets/manual/image-303.png" style="width:5.8in"
alt="Manual de usuario, página 80, imagen 303" />
<figcaption aria-hidden="true">Manual de usuario, página 80, imagen
303</figcaption>
</figure>
