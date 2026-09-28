## Presentación, componentes e inventario

<!-- Página 1 del PDF original -->

Manual de usuario - Kit SmartHome

Manual de usuario

![Manual de usuario, página 1, imagen 0](assets/manual/image-000-alpha.png){width=3.3in}

![Manual de usuario, página 1, imagen 2](assets/manual/image-002.png){width=3.3in}

Área: I2D

Producto: AR4623 - Kit SmartHome

Versión: 1.1.0

Fecha: 16/02/2026

Autores: Juan Luis Ballesteros, José Carlos Serrato

Tiempo estimado de lectura: 12 minutos

Tiempo estimado de ensamble: 4 horas

<!-- Página 2 del PDF original -->

Tiempo estimado de puesta en funcionamiento: 1 hora

Control de versiones

| Versión | Fecha | Nombre | Cambios realizados |
|---|---|---|---|
| V1.1.0 | 16/02/2026 | José Serrato | Cambio de motor, mejora de ensamble (electrónica y espacio asignado) y plantillas de corte mejoradas. |
| V1.0.1 | — | José Serrato | Corrección de puentes en corte láser. |
| V1.0.0 | — | José Serrato | Creación del proyecto, primer borrador. |

Introducción  
El Kit SmartHome de UNIT Electronics es una plataforma didáctica diseñada para el aprendizaje  
práctica de electrónica y programación mediante la construcción de una casa inteligente  
funcional.

El usuario ensamblará piezas mecánicas, integrará electrónica modular, hará uso del control  
PWM, el protocolo de comunicación I2C y realizará lectura de sensores tanto digitales como  
analógicos, todo con apoyo de una aplicación móvil.

El kit integra múltiples sensores y actuadores, controlados por la tarjeta de desarrollo UNIT  
DualMCU ONE, que incorpora los microcontroladores:

ESP32  
RP2040

La UNIT DualMCU ONE permite trabajar con:

Arduino IDE  
MicroPython  
CircuitPython  
Raspberry Pi C/C++ SDK

Materiales:

MDF  
Acrílico  
PLA (Impresiones 3D)

<!-- Página 3 del PDF original -->

Fuente de alimentación:

Eliminador 12V 2A mediante Jack.

Sensores:

Sensor de flama KY-026  
Sensor de lluvia FC-37  
Sensor de temperatura y humedad AHT10  
Sensor fotorresistor KY-018  
Neopixel  
RFID RC522 (con tarjeta y llavero)  
IR HX1838  
Botón capacitivo TTP223B  
Encoder KY-040  
Sensor de movimiento PIR HC-SR505

Actuadores:

Servomotor SG90  
Buzzer pasivo KY-006  
Display Oled 0.96” SSD1306  
Motor DC (con hélice)

Módulos y electrónica:

Tarjeta de desarrollo UNIT DualMCU ONE ESP32 + RP2040  
Hub I2C QW/ST  
Puente H MX1508  
PCA9685  
Sensor Shield V5  
Eliminador 12V 2A Jack

Cables:

Qwiic a Qwiic  
Qwiic a Dupont (M-H)  
Dupont - Dupont (H-H)  
Dupont - Dupont (H-M)  
Dupont - Dupont (H-H Fijo 2 vías)

<!-- Página 4 del PDF original -->

Dupont - Dupont (H-H Fijo 3 vías)

Tornillería:

M2x8  
M2.5x8  
M3x6  
M3x8  
M3x10  
Separador de latón  
Tuercas M2  
Tuercas M2.5  
Tuercas M3

Herramientas recomendadas para el ensamble:

Desarmador plano  
Desarmador de cruz  
Pinzas de punta delgada o pinzas SMD (te serán útil al momento de cablear)  
Cautín

Herramientas no incluidas

<!-- Página 5 del PDF original -->

![Manual de usuario, página 5, imagen 3](assets/manual/image-003.png){width=3.3in}

Lista de materiales

| Folio | Descripción | Imagen | Cantidad |
|---|---|---|---:|
| KSH01 | M2x8 queso ranurada | ![KSH01: M2x8 queso ranurada](assets/manual/image-004.png){width=0.7in} | 12 |
| KSH02 | M2.5x8 queso ranurada | ![KSH02: M2.5x8 queso ranurada](assets/manual/image-005.png){width=0.7in} | 23 |
| KSH03 | M3x6 queso ranurada | ![KSH03: M3x6 queso ranurada](assets/manual/image-006.png){width=0.7in} | 6 |
| KSH04 | M3x8 queso ranurada | ![KSH04: M3x8 queso ranurada](assets/manual/image-007.png){width=0.7in} | 18 |
| KSH05 | M3x10 queso ranurada | ![KSH05: M3x10 queso ranurada](assets/manual/image-008.png){width=0.7in} | 5 |
| KSH06 | M3x5+6 separador latón | ![KSH06: M3x5+6 separador latón](assets/manual/image-009.png){width=0.7in} | 4 |

<!-- Página 6 del PDF original -->

| Folio | Descripción | Imagen | Cantidad |
|---|---|---|---:|
| KSH07 | M2 tuerca | ![KSH07: M2 tuerca](assets/manual/image-010.png){width=0.7in} | 16 |
| KSH08 | M2.5 tuerca | ![KSH08: M2.5 tuerca](assets/manual/image-011.png){width=0.7in} | 41 |
| KSH09 | M3 tuerca | ![KSH09: M3 tuerca](assets/manual/image-012.png){width=0.7in} | 33 |
| KSH10 | UNIT DualMCU ONE | ![KSH10: UNIT DualMCU ONE](assets/manual/image-013.png){width=0.7in} | 1 |
| KSH11 | SG90 Servomotor | ![KSH11: SG90 Servomotor](assets/manual/image-014.png){width=0.7in} | 1 |
| KSH12 | KY-006 Buzzer | ![KSH12: KY-006 Buzzer](assets/manual/image-015.png){width=0.7in} | 1 |
| KSH13 | KY-026 Sensor de flama | ![KSH13: KY-026 Sensor de flama](assets/manual/image-016.png){width=0.7in} | 1 |
| KSH14 | FC-37 Sensor de lluvia | ![KSH14: FC-37 Sensor de lluvia](assets/manual/image-017.png){width=0.7in} | 1 |
| KSH15 | AHT10 Sensor de temperatura y humedad | ![KSH15: AHT10 Sensor de temperatura y humedad](assets/manual/image-018.png){width=0.7in} | 1 |

<!-- Página 7 del PDF original -->

| Folio | Descripción | Imagen | Cantidad |
|---|---|---|---:|
| KSH16 | SSD1315 Pantalla OLED | ![KSH16: SSD1315 Pantalla OLED](assets/manual/image-019.png){width=0.7in} | 1 |
| KSH17 | KY-018 Fotorresistor | ![KSH17: KY-018 Fotorresistor](assets/manual/image-020.png){width=0.7in} | 1 |
| KSH18 | WS2812 Neopixel | ![KSH18: WS2812 Neopixel](assets/manual/image-021.png){width=0.7in} | 3 |
| KSH19 | RC522 Sensor RFID | ![KSH19: RC522 Sensor RFID](assets/manual/image-022.png){width=0.7in} | 1 |
| KSH20 | HX1838 Sensor IR | ![KSH20: HX1838 Sensor IR](assets/manual/image-023.png){width=0.7in} | 1 |
| KSH21 | TTP223B Botón Capacitivo | ![KSH21: TTP223B Botón Capacitivo](assets/manual/image-024.png){width=0.7in} | 1 |
| KSH22 | KY-040 Encoder | ![KSH22: KY-040 Encoder](assets/manual/image-025.png){width=0.7in} | 1 |
| KSH23 | UNIT Módulo Hub I2C QW/ST | ![KSH23: UNIT Módulo Hub I2C QW/ST](assets/manual/image-026.png){width=0.7in} | 1 |
| KSH24 | HC-SR505 PIR | ![KSH24: HC-SR505 PIR](assets/manual/image-027.png){width=0.7in} | 1 |
| KSH25 | Motor DC con Hélice | ![KSH25: Motor DC con Hélice](assets/manual/image-028.png){width=0.7in} | 1 |

<!-- Página 8 del PDF original -->

| Folio | Descripción | Imagen | Cantidad |
|---|---|---|---:|
| KSH26 | MX1508 Puente H | ![KSH26: MX1508 Puente H](assets/manual/image-029.png){width=0.7in} | 1 |
| KSH27 | PCA9685 | ![KSH27: PCA9685](assets/manual/image-030.png){width=0.7in} | 1 |
| KSH28 | Sensor Shield V5.0 UNO R3 | ![KSH28: Sensor Shield V5.0 UNO R3](assets/manual/image-031.png){width=0.7in} | 1 |
| KSH29 | Eliminador 12V 2A Jack | ![KSH29: Eliminador 12V 2A Jack](assets/manual/image-032.png){width=0.7in} | 1 |
| KSH30 | Cable Qwiic - Qwiic 10 cm | ![KSH30: Cable Qwiic - Qwiic 10 cm](assets/manual/image-033.png){width=0.7in} | 1 |
| KSH31 | Cable Qwiic - Dupont Hembra 20 cm | ![KSH31: Cable Qwiic - Dupont Hembra 20 cm](assets/manual/image-034.png){width=0.7in} | 3 |
| KSH32 | Cable Dupont H-H 20 cm | ![KSH32: Cable Dupont H-H 20 cm](assets/manual/image-035.png){width=0.7in} | 16 |

<!-- Página 9 del PDF original -->

| Folio | Descripción | Imagen | Cantidad |
|---|---|---|---:|
| KSH33 | Cable Dupont M-H 20 cm | ![KSH33: Cable Dupont M-H 20 cm](assets/manual/image-036.png){width=0.7in} | 2 |
| KSH34 | Cable Dupont H-H Fijo 2 vías | ![KSH34: Cable Dupont H-H Fijo 2 vías](assets/manual/image-037.png){width=0.7in} | 3 |
| KSH35 | Cable Dupont H-H Fijo 3 vías | ![KSH35: Cable Dupont H-H Fijo 3 vías](assets/manual/image-038.png){width=0.7in} | 8 |
| KSH36 | Tira Header Macho 40 pines | ![KSH36: Tira Header Macho 40 pines](assets/manual/image-039.png){width=0.7in} | 1 |
| KSH37 | Pila de Botón 3V | ![KSH37: Pila de Botón 3V](assets/manual/image-040.png){width=0.7in} | 1 |
| KSH38 | Juego de impresiones | ![KSH38: Juego de impresiones](assets/manual/image-041.png){width=0.7in} | 1 juego |
| KSH39 | Juego de cortes en MDF | ![KSH39: Juego de cortes en MDF](assets/manual/image-042.png){width=0.7in} | 1 juego |

1.- Ensamble

Objetivo:

## Ensamble

<!-- Página 10 del PDF original -->

Guiar al usuario en el ensamble de los componentes del Kit SmartHome, asegurando la correcta  
instalación de la estructura como de la electrónica, así como conexiones de cables a los  
módulos.

Resultado esperado:

Estructura de la casa ensamblada con la electrónica atornillada y cableado preparado para su  
conexión con la shield.

![Manual de usuario, página 10, imagen 43](assets/manual/image-043.png){width=2.0in}

![Manual de usuario, página 10, imagen 44](assets/manual/image-044.png){width=2.0in}

![Manual de usuario, página 10, imagen 45](assets/manual/image-045.png){width=2.0in}

Vista frontal

Vista lateral Derecha

Vista lateral Izquierda

![Manual de usuario, página 10, imagen 48](assets/manual/image-048.png){width=2.0in}

![Manual de usuario, página 10, imagen 46](assets/manual/image-046.png){width=2.0in}

![Manual de usuario, página 10, imagen 47](assets/manual/image-047.png){width=2.0in}

Vista superior

Vista Isométrica

Vista posterior

Resultado final esperado terminada la sección Ensamble.

Desarrollo:

Recomendaciones:

Ubica todas las piezas del apartado previo al ensamble  
Reúne las herramientas mencionadas en la introducción  
Retira los cortes de MDF de su marco conforme se utilicen, con la intención de tener un  
ensamble más organizado  
Coloca la pila de botón CR2025 al control infrarrojo  
Suelda los pines de los módulos previo a su ensamble

<!-- Página 11 del PDF original -->

![Manual de usuario, página 11, imagen 49](assets/manual/image-049.png){width=1.1in}

![Manual de usuario, página 11, imagen 50](assets/manual/image-050.png){width=2.0in}

Pines en cara superior (1  
módulo)

Pines en cara posterior (2  
módulos)

Pines módulos Neopixel

![Manual de usuario, página 11, imagen 51](assets/manual/image-051.png){width=2.0in}

Pines soldados Puente H

![Manual de usuario, página 11, imagen 52](assets/manual/image-052.png){width=2.0in}

Pines soldados AHT10

![Manual de usuario, página 11, imagen 53](assets/manual/image-053.png){width=2.0in}

Pines soldados RC522

<!-- Página 12 del PDF original -->

Procedimiento de ensamble:

Ubicación de componentes de la sección  
Ensamble de módulos  
Cableado del módulo

Precaución: Una mala conexión puede provocar daño en los módulos

1.0 - Preparación

Para evitar problemas de ensamble, se requiere energizar el servomotor para dejar la posición  
inicial correcta. Sigue el siguiente diagrama y realiza las conexiones necesarias.

Nota: Es necesario montar la shield a la DualONE. En el diagrama se muestran separadas  
para un mejor entendimiento.

![Manual de usuario, página 12, imagen 54](assets/manual/image-054.png){width=3.3in}

Conexi

1.1 - Base (A)

<!-- Página 13 del PDF original -->

![Manual de usuario, página 13, imagen 55](assets/manual/image-055.png){width=2.0in}

![Manual de usuario, página 13, imagen 58](assets/manual/image-058.png){width=1.1in}

![Manual de usuario, página 13, imagen 56](assets/manual/image-056.png){width=0.65in}

![Manual de usuario, página 13, imagen 57](assets/manual/image-057.png){width=1.1in}

![Manual de usuario, página 13, imagen 59](assets/manual/image-059.png){width=1.1in}

Brazo Servomotor

Regatones (4  
pzs)

MDF - A

Base Servomotor

Puerta

![Manual de usuario, página 13, imagen 60](assets/manual/image-060.png){width=1.1in}

![Manual de usuario, página 13, imagen 62](assets/manual/image-062.png){width=1.1in}

![Manual de usuario, página 13, imagen 63](assets/manual/image-063.png){width=1.1in}

![Manual de usuario, página 13, imagen 61](assets/manual/image-061.png){width=1.1in}

![Manual de usuario, página 13, imagen 64](assets/manual/image-064.png){width=1.1in}

M3x10 (2 pzs)

Pija M2.8

M3x8 (4 pzs)

Tornillo  
Servomotor

Servomotor

![Manual de usuario, página 13, imagen 65](assets/manual/image-065.png){width=1.1in}

![Manual de usuario, página 13, imagen 66](assets/manual/image-066.png){width=1.1in}

![Manual de usuario, página 13, imagen 67](assets/manual/image-067.png){width=1.1in}

M2x8 (2 pzs)

M3 (6 pzs)

M2 (2pzs)

![Manual de usuario, página 13, imagen 68](assets/manual/image-068.png){width=3.3in}

<!-- Página 14 del PDF original -->

![Manual de usuario, página 14, imagen 69](assets/manual/image-069.png){width=3.3in}

MDF-A + 4x tornillos M3x8 + 4x tuercas M3 +  
4x regatones  
Repite el paso en las 4 esquinas.

![Manual de usuario, página 14, imagen 70](assets/manual/image-070.png){width=3.3in}

<!-- Página 15 del PDF original -->

![Manual de usuario, página 15, imagen 71](assets/manual/image-071.png){width=3.3in}

Puerta + Base servomotor + 2x tornillos M2x8 + 2x tuercas M2 +  
tornillo y pija servomotor (estos últimos se ubican junto con el  
servomotor)

![Manual de usuario, página 15, imagen 72](assets/manual/image-072.png){width=3.3in}

<!-- Página 16 del PDF original -->

![Manual de usuario, página 16, imagen 73](assets/manual/image-073.png){width=3.3in}

2x tornillos M3x10 + 2x tuercas M3

![Manual de usuario, página 16, imagen 74](assets/manual/image-074.png){width=3.3in}

Ensamble 1.1

1.2 - Pared (C) + Techo (J)

![Manual de usuario, página 16, imagen 78](assets/manual/image-078.png){width=1.1in}

![Manual de usuario, página 16, imagen 75](assets/manual/image-075.png){width=1.1in}

![Manual de usuario, página 16, imagen 76](assets/manual/image-076.png){width=1.1in}

![Manual de usuario, página 16, imagen 77](assets/manual/image-077.png){width=1.1in}

![Manual de usuario, página 16, imagen 79](assets/manual/image-079.png){width=1.1in}

Impresión  
anclaje J

M3x8 (4 pzs)

MDF - J

MDF - C

Acrílico inferior

![Manual de usuario, página 16, imagen 81](assets/manual/image-081.png){width=0.65in}

![Manual de usuario, página 16, imagen 80](assets/manual/image-080.png){width=1.1in}

![Manual de usuario, página 16, imagen 83](assets/manual/image-083.png){width=0.65in}

![Manual de usuario, página 16, imagen 84](assets/manual/image-084.png){width=1.1in}

![Manual de usuario, página 16, imagen 82](assets/manual/image-082.png){width=1.1in}

Dupont fijo 3  
vías

M2.5x8 (2 pzs)

M3x6 (2 pzs)

M3 (6 pzs)

M2.5 (2  
pzs)

<!-- Página 17 del PDF original -->

![Manual de usuario, página 17, imagen 85](assets/manual/image-085.png){width=1.1in}

Neopixel

Precaución: Cuida la polaridad de los Neopixel, una mala conexión puede quemar los  
Neopixel.

![Manual de usuario, página 17, imagen 86](assets/manual/image-086.png){width=3.3in}

![Manual de usuario, página 17, imagen 87](assets/manual/image-087.png){width=3.3in}

MDF-C + Acrílico Inferior + 2x tornillos M3x8 + 2x  
tuercas M3

<!-- Página 18 del PDF original -->

![Manual de usuario, página 18, imagen 88](assets/manual/image-088.png){width=3.3in}

Impresión anclaje J + 2x tornillos M3x8 + 2x tuercas  
M3

![Manual de usuario, página 18, imagen 89](assets/manual/image-089.png){width=2.0in}

MDF-J + Neopixel + 2x tornillos M2.5 +  
2x tuercas M2.5

![Manual de usuario, página 18, imagen 90](assets/manual/image-090.png){width=3.3in}

<!-- Página 19 del PDF original -->

![Manual de usuario, página 19, imagen 91](assets/manual/image-091.png){width=3.3in}

2x tornillos M3x6 + 2x tuercas M3

![Manual de usuario, página 19, imagen 92](assets/manual/image-092.png){width=3.3in}

![Manual de usuario, página 19, imagen 93](assets/manual/image-093.png){width=3.3in}

\+ Dupont fijo 3 vías  
Ensamble 1.2

Conecta los cables por los espacios designados para agilizar el proceso

1.3 - Paredes (H) + Pared (I) + Base (G) + Ensamble 1.2

<!-- Página 20 del PDF original -->

![Manual de usuario, página 20, imagen 96](assets/manual/image-096.png){width=1.1in}

![Manual de usuario, página 20, imagen 94](assets/manual/image-094.png){width=3.3in}

![Manual de usuario, página 20, imagen 95](assets/manual/image-095.png){width=0.65in}

![Manual de usuario, página 20, imagen 97](assets/manual/image-097.png){width=1.1in}

![Manual de usuario, página 20, imagen 98](assets/manual/image-098.png){width=1.1in}

MDF - Llave (4  
pzs)

MDF - G

MDF - I

MDF - H  
(2 pzs)

Ensamble 1.2

![Manual de usuario, página 20, imagen 99](assets/manual/image-099.png){width=1.1in}

![Manual de usuario, página 20, imagen 100](assets/manual/image-100.png){width=1.1in}

![Manual de usuario, página 20, imagen 101](assets/manual/image-101.png){width=1.1in}

![Manual de usuario, página 20, imagen 102](assets/manual/image-102.png){width=1.1in}

M2x8 (4 pzs)

M2 (4 pzs)

Cable Qwiic a  
Dupont

Pantalla OLED

![Manual de usuario, página 20, imagen 103](assets/manual/image-103.png){width=3.3in}

2x MDF-H + MDF-G

![Manual de usuario, página 20, imagen 104](assets/manual/image-104.png){width=3.3in}

\+ MDF-I

<!-- Página 21 del PDF original -->

![Manual de usuario, página 21, imagen 105](assets/manual/image-105.png){width=3.3in}

Pantalla OLED + 4x tornillos M2x8 + 4x tuercas M2

![Manual de usuario, página 21, imagen 106](assets/manual/image-106.png){width=3.3in}

<!-- Página 22 del PDF original -->

![Manual de usuario, página 22, imagen 107](assets/manual/image-107.png){width=3.3in}

\+ Cable Qwiic a dupont

![Manual de usuario, página 22, imagen 108](assets/manual/image-108.png){width=3.3in}

<!-- Página 23 del PDF original -->

![Manual de usuario, página 23, imagen 110](assets/manual/image-110.png){width=2.0in}

![Manual de usuario, página 23, imagen 109](assets/manual/image-109.png){width=2.0in}

\+ 4x MDF-Llave

![Manual de usuario, página 23, imagen 111](assets/manual/image-111.png){width=3.3in}

Ensamble 1.3

1.4 - Pared (D)

![Manual de usuario, página 23, imagen 116](assets/manual/image-116.png){width=0.65in}

![Manual de usuario, página 23, imagen 112](assets/manual/image-112.png){width=1.1in}

![Manual de usuario, página 23, imagen 113](assets/manual/image-113.png){width=0.65in}

![Manual de usuario, página 23, imagen 114](assets/manual/image-114.png){width=1.1in}

![Manual de usuario, página 23, imagen 115](assets/manual/image-115.png){width=0.65in}

Lector RFID

Encoder

Buzzer

MDF - D

Sensor  
de  
flama

<!-- Página 24 del PDF original -->

![Manual de usuario, página 24, imagen 117](assets/manual/image-117.png){width=1.1in}

![Manual de usuario, página 24, imagen 118](assets/manual/image-118.png){width=0.65in}

![Manual de usuario, página 24, imagen 119](assets/manual/image-119.png){width=1.1in}

![Manual de usuario, página 24, imagen 120](assets/manual/image-120.png){width=1.1in}

![Manual de usuario, página 24, imagen 121](assets/manual/image-121.png){width=1.1in}

Dupont fijo 2  
vías

Dupont fijo 3  
vías

M2.5x8 (9 pzs)

Dupont H-H (7  
pzs)

M2.5 (18  
pzs)

![Manual de usuario, página 24, imagen 122](assets/manual/image-122.png){width=3.3in}

![Manual de usuario, página 24, imagen 123](assets/manual/image-123.png){width=3.3in}

9 tornillos M2.5x8 + 18 tuercas M2.5 + Encoder + Lector RFID +  
Buzzer + Sensor de flama

<!-- Página 25 del PDF original -->

Orden de ensamble. Tornillo, módulo, tuerca (funciona como separador y mantiene en su  
lugar al módulo), MDF y tuerca.

![Manual de usuario, página 25, imagen 124](assets/manual/image-124.png){width=3.3in}

Imagen lateral MDF-D con módulos ensamblados

<!-- Página 26 del PDF original -->

![Manual de usuario, página 26, imagen 125](assets/manual/image-125.png){width=3.3in}

Coloca los cables correspondientes a los módulos + 3x Dupont fijo 3  
vías + Dupont fijo 2 vías + 7x cables dupont H-H

Encoder: Dupont fijo 3 vías + Dupont fijo 2 vías  
Buzzer: Dupont fijo 3 vías  
Flama: Dupont fijo 3 vías  
RFID: 7 cables dupont H-H

<!-- Página 27 del PDF original -->

![Manual de usuario, página 27, imagen 126](assets/manual/image-126.png){width=3.3in}

Ensamble MDF - D con módulos y cables, organizados.  
Ensamble 1.4

1.5 - Pared (D)

![Manual de usuario, página 27, imagen 127](assets/manual/image-127.png){width=1.1in}

![Manual de usuario, página 27, imagen 128](assets/manual/image-128.png){width=0.65in}

![Manual de usuario, página 27, imagen 129](assets/manual/image-129.png){width=1.1in}

![Manual de usuario, página 27, imagen 130](assets/manual/image-130.png){width=1.1in}

![Manual de usuario, página 27, imagen 131](assets/manual/image-131.png){width=1.1in}

M3x8 (2 pzs)

PIR

MDF - E

Botón  
Capacitivo

Soporte  
PIR

![Manual de usuario, página 27, imagen 132](assets/manual/image-132.png){width=0.65in}

![Manual de usuario, página 27, imagen 133](assets/manual/image-133.png){width=1.1in}

![Manual de usuario, página 27, imagen 134](assets/manual/image-134.png){width=0.65in}

![Manual de usuario, página 27, imagen 135](assets/manual/image-135.png){width=1.1in}

![Manual de usuario, página 27, imagen 136](assets/manual/image-136.png){width=1.1in}

Dupont fijo 3  
vías

M2x8 (4 pzs)

M3 (2 pzs)

Dupont H-H (3  
pzs)

M2 (8 pzs)

<!-- Página 28 del PDF original -->

![Manual de usuario, página 28, imagen 137](assets/manual/image-137.png){width=3.3in}

MDF-E

![Manual de usuario, página 28, imagen 138](assets/manual/image-138.png){width=3.3in}

2x tornillos M3x8 + 2x tuercas M3 + Soporte PIR + PIR

<!-- Página 29 del PDF original -->

![Manual de usuario, página 29, imagen 139](assets/manual/image-139.png){width=3.3in}

4x tornillos M2x8 + 8x tuercas M2 + Botón capacitivo

Recuerda el orden correcto. Tornillo, módulo, tuerca, MDF, tuerca.

![Manual de usuario, página 29, imagen 140](assets/manual/image-140.png){width=3.3in}

3x Dupont H-H + Dupont fijo 3 vías  
Ensamble 1.5

<!-- Página 30 del PDF original -->

PIR: 3x Dupont H-H  
Botón Capacitivo: Dupont Fijo 3 vías

1.6 - Techo (F)

![Manual de usuario, página 30, imagen 141](assets/manual/image-141.png){width=2.0in}

![Manual de usuario, página 30, imagen 142](assets/manual/image-142.png){width=1.1in}

![Manual de usuario, página 30, imagen 144](assets/manual/image-144.png){width=1.1in}

![Manual de usuario, página 30, imagen 145](assets/manual/image-145.png){width=1.1in}

![Manual de usuario, página 30, imagen 143](assets/manual/image-143.png){width=0.65in}

Sensor de  
lluvia (2)

Sensor de  
lluvia (1)

Fotorres  
istor

Puente H

MDF - F

![Manual de usuario, página 30, imagen 147](assets/manual/image-147.png){width=1.1in}

![Manual de usuario, página 30, imagen 148](assets/manual/image-148.png){width=1.1in}

![Manual de usuario, página 30, imagen 150](assets/manual/image-150.png){width=1.1in}

![Manual de usuario, página 30, imagen 149](assets/manual/image-149.png){width=0.65in}

![Manual de usuario, página 30, imagen 146](assets/manual/image-146.png){width=0.65in}

M3x10

M3x8 (4 pzs)

M2.5x8 (3 pzs)

M3 (6 pzs)

Sensor IR

![Manual de usuario, página 30, imagen 151](assets/manual/image-151.png){width=1.1in}

![Manual de usuario, página 30, imagen 152](assets/manual/image-152.png){width=1.1in}

![Manual de usuario, página 30, imagen 153](assets/manual/image-153.png){width=1.1in}

![Manual de usuario, página 30, imagen 154](assets/manual/image-154.png){width=1.1in}

![Manual de usuario, página 30, imagen 155](assets/manual/image-155.png){width=1.1in}

Dupont fijo 3  
vías (2 pzs)

M2x8 (2 pzs)

Dupont H-H (5  
pzs)

M2.5 (6 pzs)

M2 (4 pzs)

2 de los 5 cables Dupont H-H vienen embolsados con el sensor de lluvia.

![Manual de usuario, página 30, imagen 156](assets/manual/image-156.png){width=3.3in}

MDF-F

<!-- Página 31 del PDF original -->

![Manual de usuario, página 31, imagen 157](assets/manual/image-157.png){width=3.3in}

Sensor de lluvia (1) + 4x tornillos M3x8 + 4x tuerca M3

![Manual de usuario, página 31, imagen 158](assets/manual/image-158.png){width=3.3in}

Sensor IR + 2x tornillos M2x8 + 4x tuercas M2

<!-- Página 32 del PDF original -->

![Manual de usuario, página 32, imagen 159](assets/manual/image-159.png){width=3.3in}

Fotorresistor + 2x tornillos M2.5x8 + 4x tuercas M2.5

![Manual de usuario, página 32, imagen 160](assets/manual/image-160.png){width=3.3in}

Sensor de lluvia (2) + tornillo M3x10 + 2x tuercas M3

<!-- Página 33 del PDF original -->

![Manual de usuario, página 33, imagen 161](assets/manual/image-161.png){width=3.3in}

Puente H + tornillo M2.5x8 + 2x tuercas M2.5

![Manual de usuario, página 33, imagen 162](assets/manual/image-162.png){width=3.3in}

\+ 2x Dupont H-H  
Conecta las dos partes del sensor de lluvia

![Manual de usuario, página 33, imagen 163](assets/manual/image-163.png){width=3.3in}

\+ Cable Dupont H-H

<!-- Página 34 del PDF original -->

![Manual de usuario, página 34, imagen 164](assets/manual/image-164.png){width=3.3in}

2x Cables dupont fijo de 3 vías (Conectar Sensor IR y Fotorresitor)

![Manual de usuario, página 34, imagen 165](assets/manual/image-165.png){width=3.3in}

Ensamble 1.6

<!-- Página 35 del PDF original -->

![Manual de usuario, página 35, imagen 166](assets/manual/image-166.png){width=3.3in}

Ensamble 1.6

1.7 - Pared (Q)

![Manual de usuario, página 35, imagen 167](assets/manual/image-167.png){width=1.1in}

![Manual de usuario, página 35, imagen 168](assets/manual/image-168.png){width=1.1in}

![Manual de usuario, página 35, imagen 169](assets/manual/image-169.png){width=1.1in}

![Manual de usuario, página 35, imagen 170](assets/manual/image-170.png){width=1.1in}

![Manual de usuario, página 35, imagen 171](assets/manual/image-171.png){width=1.1in}

PCA9685

Hub I2C  
QW/ST

Pared Q

DualONE

Sensor shield

![Manual de usuario, página 35, imagen 174](assets/manual/image-174.png){width=1.1in}

![Manual de usuario, página 35, imagen 173](assets/manual/image-173.png){width=1.1in}

![Manual de usuario, página 35, imagen 175](assets/manual/image-175.png){width=0.65in}

![Manual de usuario, página 35, imagen 176](assets/manual/image-176.png){width=1.1in}

![Manual de usuario, página 35, imagen 172](assets/manual/image-172.png){width=1.1in}

M3x10 (2 pzs)

Separador de  
latón (4 pzs)

M3x6 (4 pzs)

M2.5x8 (4 pzs)

M3 (8 pzs)

![Manual de usuario, página 35, imagen 177](assets/manual/image-177.png){width=0.65in}

![Manual de usuario, página 35, imagen 178](assets/manual/image-178.png){width=1.1in}

![Manual de usuario, página 35, imagen 179](assets/manual/image-179.png){width=1.1in}

![Manual de usuario, página 35, imagen 180](assets/manual/image-180.png){width=1.1in}

Cable Qwiic -  
Qwiic

Cable Dupont  
M-H (2 pzs)

Cable Qwicc -  
Dupont

M2.5 (8 pzs)

<!-- Página 36 del PDF original -->

![Manual de usuario, página 36, imagen 181](assets/manual/image-181.png){width=3.3in}

MDF-Q

![Manual de usuario, página 36, imagen 182](assets/manual/image-182.png){width=3.3in}

Dual ONE + 4x Separadores de latón + 3x tornillos M3x6 + 4x  
tuercas M3

![Manual de usuario, página 36, imagen 183](assets/manual/image-183.png){width=3.3in}

Hub I2C QW/ST + 2x tornillos M3x10 + 4x tuercas M3

<!-- Página 37 del PDF original -->

![Manual de usuario, página 37, imagen 184](assets/manual/image-184.png){width=3.3in}

PCA9685 + 4x tornillos M2.5x8 + 8x tuercas M2.5

![Manual de usuario, página 37, imagen 185](assets/manual/image-185.png){width=3.3in}

\+ Cable Qwiic - Qwiic

Precaución: Conecta el cable Qwiic - Qwiic de la tarjeta de desarrollo DualONE al Hub I2C  
previo a colocar el Sensor shield.

![Manual de usuario, página 37, imagen 186](assets/manual/image-186.png){width=3.3in}

\+ Sensor shield  
Ensamble 1.7

<!-- Página 38 del PDF original -->

1.8 - Ensamble piso inferior

![Manual de usuario, página 38, imagen 187](assets/manual/image-187.png){width=3.3in}

![Manual de usuario, página 38, imagen 188](assets/manual/image-188.png){width=3.3in}

![Manual de usuario, página 38, imagen 189](assets/manual/image-189.png){width=3.3in}

![Manual de usuario, página 38, imagen 190](assets/manual/image-190.png){width=3.3in}

![Manual de usuario, página 38, imagen 191](assets/manual/image-191.png){width=3.3in}

![Manual de usuario, página 38, imagen 192](assets/manual/image-192.png){width=3.3in}

Ensamble 1.1

Ensamble 1.7

Ensamble 1.3

Ensamble 1.6

Ensamble 1.5

Ensamble 1.4

Haremos uso de las secciones previamente ensambladas

![Manual de usuario, página 38, imagen 193](assets/manual/image-193.png){width=3.3in}

Ensamble 1.7

![Manual de usuario, página 38, imagen 194](assets/manual/image-194.png){width=3.3in}

Ensamble 1.7 + Ensamble 4

<!-- Página 39 del PDF original -->

![Manual de usuario, página 39, imagen 195](assets/manual/image-195.png){width=3.3in}

\+ Ensamble 1.5

![Manual de usuario, página 39, imagen 196](assets/manual/image-196.png){width=3.3in}

\+ Ensamble 1.3

![Manual de usuario, página 39, imagen 197](assets/manual/image-197.png){width=3.3in}

\+ Ensamble 1.1

Este paso requiere de fuerza en el ensamble, debido a que el Ensamble 1.1 entra a presión

<!-- Página 40 del PDF original -->

![Manual de usuario, página 40, imagen 198](assets/manual/image-198.png){width=3.3in}

\+ Ensamble 1.6  
Resultado: Ensamble 1.8

De ser necesario, al realizar las conexiones, podrás retirar el Ensamble 1.6

1.9 - Ensamble piso superior

![Manual de usuario, página 40, imagen 199](assets/manual/image-199.png){width=1.1in}

![Manual de usuario, página 40, imagen 200](assets/manual/image-200.png){width=1.1in}

![Manual de usuario, página 40, imagen 201](assets/manual/image-201.png){width=1.1in}

![Manual de usuario, página 40, imagen 202](assets/manual/image-202.png){width=1.1in}

![Manual de usuario, página 40, imagen 203](assets/manual/image-203.png){width=1.1in}

MDF - O

MDF - P

MDF - N

MDF - L

MDF - M

![Manual de usuario, página 40, imagen 208](assets/manual/image-208.png){width=0.65in}

![Manual de usuario, página 40, imagen 204](assets/manual/image-204.png){width=1.1in}

![Manual de usuario, página 40, imagen 205](assets/manual/image-205.png){width=1.1in}

![Manual de usuario, página 40, imagen 206](assets/manual/image-206.png){width=1.1in}

![Manual de usuario, página 40, imagen 207](assets/manual/image-207.png){width=1.1in}

Soporte Motor  
DC

Acrílico  
Superior

Motor DC

Neopixel

Hélice

![Manual de usuario, página 40, imagen 213](assets/manual/image-213.png){width=1.1in}

![Manual de usuario, página 40, imagen 210](assets/manual/image-210.png){width=1.1in}

![Manual de usuario, página 40, imagen 209](assets/manual/image-209.png){width=0.65in}

![Manual de usuario, página 40, imagen 211](assets/manual/image-211.png){width=1.1in}

![Manual de usuario, página 40, imagen 212](assets/manual/image-212.png){width=1.1in}

M3x8 (4 pzs)

M2.5x8 (5 pzs)

M3 (4 pzs)

M2.5 (7 pzs)

Sensor  
Temperatur  
a y  
Humedad

![Manual de usuario, página 40, imagen 214](assets/manual/image-214.png){width=1.1in}

![Manual de usuario, página 40, imagen 216](assets/manual/image-216.png){width=1.1in}

![Manual de usuario, página 40, imagen 217](assets/manual/image-217.png){width=1.1in}

![Manual de usuario, página 40, imagen 215](assets/manual/image-215.png){width=1.1in}

Dupont fijo 2  
vías

Dupont fijo 3  
vías

Dupont H-H (3)

Cable Qwiic -  
Qwiic

<!-- Página 41 del PDF original -->

Modelo de la Hélice puede cambiar.

![Manual de usuario, página 41, imagen 218](assets/manual/image-218.png){width=3.3in}

MDF-O + Acrílico Superior + 2x tornillos M3x8 + 2x tuercas M3

![Manual de usuario, página 41, imagen 219](assets/manual/image-219.png){width=3.3in}

MDF-M + Sensor Temperatura y Humedad + tornillo  
M2.5x8 + tuerca M2.5

<!-- Página 42 del PDF original -->

![Manual de usuario, página 42, imagen 220](assets/manual/image-220.png){width=2.0in}

\+ Cable Qwiic-Dupont

![Manual de usuario, página 42, imagen 221](assets/manual/image-221.png){width=3.3in}

MDF-P + 2x Neopixel + 4x tornillos M2.5 + 6x tuercas M2.5

Precaución: El Neopixel que apunta al exterior (donde está marcada la letra P) requiere 4  
tuercas. Se recomienda ajustar los tornillos con cautela, en especial la tornillería del  
Neopixel interior (el que se encuentra apuntando en sentido contrario a la cara con la letra  
P) para evitar que el Neopixel se encuentre torcido.

<!-- Página 43 del PDF original -->

![Manual de usuario, página 43, imagen 222](assets/manual/image-222.png){width=3.3in}

Ensamble P

![Manual de usuario, página 43, imagen 223](assets/manual/image-223.png){width=3.3in}

\+ Cable dupont fijo 3 vías

![Manual de usuario, página 43, imagen 224](assets/manual/image-224.png){width=3.3in}

\+ Cable dupont H-H

<!-- Página 44 del PDF original -->

![Manual de usuario, página 44, imagen 225](assets/manual/image-225.png){width=3.3in}

MDF-N + 2x tornillos M3x8 + 2x tuercas M3 + Motor DC + Hélice +  
Soporte Motor DC

![Manual de usuario, página 44, imagen 226](assets/manual/image-226.png){width=3.3in}

Referencia montaje motor

Precaución: Verifique la correcta instalación de la pared N, la cara con la letra N es la cara  
donde se coloca el motor. Asegúrate de colocar las conexiones del motor DC de tal forma  
que no se dañen con el MDF.

<!-- Página 45 del PDF original -->

![Manual de usuario, página 45, imagen 227](assets/manual/image-227.png){width=3.3in}

Ensamble N

![Manual de usuario, página 45, imagen 228](assets/manual/image-228.png){width=3.3in}

Ensamble paredes piso superior

![Manual de usuario, página 45, imagen 229](assets/manual/image-229.png){width=3.3in}

Paredes ensambladas

<!-- Página 46 del PDF original -->

![Manual de usuario, página 46, imagen 230](assets/manual/image-230.png){width=3.3in}

Ensamble techo piso superior

![Manual de usuario, página 46, imagen 231](assets/manual/image-231.png){width=3.3in}

Ensamble 1.9

2.- Conexiones + Ensamble Final

Objetivo:

Realizar la integración electrónica completa del kit, conectando los módulos previamente  
ensamblados a la Shield, Hub I2C, PCA9685, Puente H y UNIT DualMCU ONE, considerando  
conexiones de comunicación, alimentación, así como su polaridad.

Resultado esperado:

## Conexiones y ensamble final

<!-- Página 47 del PDF original -->

Al finalizar esta sección el usuario deberá tener los sensores conectados al Shield, actuadores  
conectados a PCA9685 y Puente H según corresponda, Bus I2C correctamente enlazado,  
alimentación sin cortocircuitos.

![Manual de usuario, página 47, imagen 232](assets/manual/image-232.png){width=3.3in}

Ilustración del ensamble al terminar las conexiones

2.1 - Conexiones paso a paso

<!-- Página 48 del PDF original -->

![Manual de usuario, página 48, imagen 233](assets/manual/image-233.png){width=3.3in}

![Manual de usuario, página 48, imagen 234](assets/manual/image-234.png){width=3.3in}

Encoder - Shield

Precaución: Una mala conexión puede provocar daños en los módulos.

<!-- Página 49 del PDF original -->

![Manual de usuario, página 49, imagen 235](assets/manual/image-235.png){width=3.3in}

![Manual de usuario, página 49, imagen 236](assets/manual/image-236.png){width=3.3in}

Buzzer - Shield

<!-- Página 50 del PDF original -->

![Manual de usuario, página 50, imagen 237](assets/manual/image-237.png){width=3.3in}

![Manual de usuario, página 50, imagen 238](assets/manual/image-238.png){width=3.3in}

RFID - Shield

<!-- Página 51 del PDF original -->

![Manual de usuario, página 51, imagen 239](assets/manual/image-239.png){width=3.3in}

![Manual de usuario, página 51, imagen 240](assets/manual/image-240.png){width=3.3in}

Sensor de llama - Shield

<!-- Página 52 del PDF original -->

![Manual de usuario, página 52, imagen 241](assets/manual/image-241.png){width=3.3in}

![Manual de usuario, página 52, imagen 242](assets/manual/image-242.png){width=3.3in}

PIR - Shield

<!-- Página 53 del PDF original -->

![Manual de usuario, página 53, imagen 243](assets/manual/image-243.png){width=3.3in}

![Manual de usuario, página 53, imagen 244](assets/manual/image-244.png){width=3.3in}

Botón capacitivo - Shield

![Manual de usuario, página 53, imagen 245](assets/manual/image-245.png){width=3.3in}

<!-- Página 54 del PDF original -->

![Manual de usuario, página 54, imagen 246](assets/manual/image-246.png){width=3.3in}

Servomotor - PCA9685

![Manual de usuario, página 54, imagen 247](assets/manual/image-247.png){width=3.3in}

![Manual de usuario, página 54, imagen 248](assets/manual/image-248.png){width=3.3in}

![Manual de usuario, página 54, imagen 249](assets/manual/image-249.png){width=3.3in}

PCA9685 - Shield - Hub I2C

<!-- Página 55 del PDF original -->

![Manual de usuario, página 55, imagen 250](assets/manual/image-250.png){width=3.3in}

![Manual de usuario, página 55, imagen 251](assets/manual/image-251.png){width=3.3in}

Pantalla OLED - Hub I2C

![Manual de usuario, página 55, imagen 252](assets/manual/image-252.png){width=3.3in}

Pantalla OLED - Hub I2C

El Hub I2C no tiene una posición designada, puedes conectar los cables en cualquiera de  
las posiciones.

<!-- Página 56 del PDF original -->

![Manual de usuario, página 56, imagen 253](assets/manual/image-253.png){width=3.3in}

Ensamble 1.8

Coloca el Ensamble 1.6 para continuar.

![Manual de usuario, página 56, imagen 254](assets/manual/image-254.png){width=3.3in}

Ensamble 1.8 + 4x MDF-Llaves

![Manual de usuario, página 56, imagen 255](assets/manual/image-255.png){width=3.3in}

<!-- Página 57 del PDF original -->

![Manual de usuario, página 57, imagen 256](assets/manual/image-256.png){width=3.3in}

Sensor de lluvia - Shield

![Manual de usuario, página 57, imagen 257](assets/manual/image-257.png){width=3.3in}

![Manual de usuario, página 57, imagen 258](assets/manual/image-258.png){width=1.1in}

Infrarrojo - Shield

<!-- Página 58 del PDF original -->

![Manual de usuario, página 58, imagen 259](assets/manual/image-259.png){width=3.3in}

![Manual de usuario, página 58, imagen 260](assets/manual/image-260.png){width=2.0in}

Fotorresistor - Shield

<!-- Página 59 del PDF original -->

![Manual de usuario, página 59, imagen 261](assets/manual/image-261.png){width=3.3in}

Sensor Temperatura y Humedad - Hub I2C

![Manual de usuario, página 59, imagen 262](assets/manual/image-262.png){width=3.3in}

Sensor Temperatura y Humedad - Hub I2C

<!-- Página 60 del PDF original -->

![Manual de usuario, página 60, imagen 263](assets/manual/image-263.png){width=3.3in}

Sensor Temperatura y Humedad - Hub I2C

![Manual de usuario, página 60, imagen 264](assets/manual/image-264.png){width=3.3in}

Ensamble 1.9

Coloca el Ensamble 1.9 para continuar

<!-- Página 61 del PDF original -->

![Manual de usuario, página 61, imagen 265](assets/manual/image-265.png){width=3.3in}

Neopixel (dentro del piso superior) - Neopixel (sobre la puerta)

![Manual de usuario, página 61, imagen 266](assets/manual/image-266.png){width=3.3in}

<!-- Página 62 del PDF original -->

![Manual de usuario, página 62, imagen 267](assets/manual/image-267.png){width=3.3in}

Neopixel (fuera del piso superior) - Shield

![Manual de usuario, página 62, imagen 268](assets/manual/image-268.png){width=3.3in}

<!-- Página 63 del PDF original -->

![Manual de usuario, página 63, imagen 269](assets/manual/image-269.png){width=3.3in}

Motor DC - Puente H

![Manual de usuario, página 63, imagen 270](assets/manual/image-270.png){width=3.3in}

(Puente H - PCA9685) + 2x cable dupont fijo 2 vías

2.2 - Ensamble Final

<!-- Página 64 del PDF original -->

![Manual de usuario, página 64, imagen 271](assets/manual/image-271.png){width=3.3in}

\+ 4x MDF - Llaves

![Manual de usuario, página 64, imagen 272](assets/manual/image-272.png){width=3.3in}

\+ MDF-B

<!-- Página 65 del PDF original -->

![Manual de usuario, página 65, imagen 273](assets/manual/image-273.png){width=3.3in}

\+ 2x MDF-Llaves

![Manual de usuario, página 65, imagen 274](assets/manual/image-274.png){width=3.3in}

Ensamble Final

2.3 - Diagramas

2.3.1 - Diagramas Shield Resumido

<!-- Página 66 del PDF original -->

![Manual de usuario, página 66, imagen 275](assets/manual/image-275.png){width=5.8in}

Diagrama Shield simplificado (1)

<!-- Página 67 del PDF original -->

![Manual de usuario, página 67, imagen 276](assets/manual/image-276.png){width=5.8in}

Diagrama Shield simplificado (2)

Diagrama de las conexiones simplificadas de los sensores y actuadores conectados  
directamente a la Shield; este diagrama muestra la fila de pines a la que se debe conectar cada  
sensor y actuador considerando alimentación y comunicación.

Precaución: Previo a energizar, corrobore la correcta conexión de los componentes  
electrónicos.

2.3.2 - Diagrama DualONE, Hub I2C, PCA9685

<!-- Página 68 del PDF original -->

![Manual de usuario, página 68, imagen 277](assets/manual/image-277.png){width=5.8in}

Diagrama DualONE, Hub I2C y PCA9685

2.3.3 - Diagrama completo

![Manual de usuario, página 68, imagen 278](assets/manual/image-278.png){width=5.8in}

Diagrama completo (1)

![Manual de usuario, página 68, imagen 279](assets/manual/image-279.png){width=5.8in}

Diagrama completo (2)

## Puesta en marcha

<!-- Página 69 del PDF original -->

Este diagrama muestra todas las conexiones a realizar.

3.- Puesta en marcha

Objetivo:

Activación funcional del Kit SmartHome mediante la instalación de la aplicación móvil oficial,  
emparejamiento con la aplicación, correcta respuesta del kit. Esta sección convierten el  
ensamble físico en un sistema inteligente operativo.

Instalacion:

Una vez descargado el archivo apk seleccionar el archivo, se mostrara el siguiente mensaje

![Manual de usuario, página 69, imagen 280](assets/manual/image-280.png){width=2.0in}

Al seleccionar Instalar se iniciara el proceso de instalacion en el dispositivo

Al no ser una aplicacion nativa de Play Store se mostrara un mensaje de proteccion, se tendra  
que seleccionar “Instalar de todas formas“

![Manual de usuario, página 69, imagen 281](assets/manual/image-281.png){width=2.0in}

Tras la instalación se podra encontrar el icono como una aplicacion mas en el sistema

![Manual de usuario, página 69, imagen 282](assets/manual/image-282.png){width=0.65in}

Resultado esperado:

<!-- Página 70 del PDF original -->

Aplicación funcional con visualización de la información recibida por los sensores y control de  
los actuadores. Ejecución de eventos.

Actualmente la aplicación solo está disponible para Android, descargando el.apk desde  
nuestras fuentes oficiales.

![Manual de usuario, página 70, imagen 283](assets/manual/image-283.jpg){width=3.3in}

![Manual de usuario, página 70, imagen 284](assets/manual/image-284.jpg){width=3.3in}

Aplicación: Sensores

Aplicación: Control actuadores

Vista de la aplicación

3.1 - Carga de firmware

El firmware viene previamente programado en la UNIT DualONE

De ser necesaria la instalación del firmware sigue estos pasos.

3.1.1 - ESP32

Debes tener Arduino IDE instalado en tu computadora.

<!-- Página 71 del PDF original -->

1. Descarga el archivo arduino-littlefs-upload-X.X.X.vsix del último release del repositorio de

GitHub.

![Manual de usuario, página 71, imagen 285](assets/manual/image-285.png){width=3.3in}

Última versión del archivo en Febrero de 2026

2. Dirígete al directorio de arduino de tu computadora: C:\\Users\\&lt;username&gt;\\.arduinoIDE\\.

![Manual de usuario, página 71, imagen 286](assets/manual/image-286.png){width=3.3in}

Directorio Arduino

3. Abre la carpeta plugins y pega el archivo descargado.

De no existir la carpeta, debes crear la carpeta plugins.

![Manual de usuario, página 71, imagen 287](assets/manual/image-287.png){width=5.8in}

Carpeta plugins

4. Reinicia y abre el Arduino IDE. Utiliza el atajo \[Ctrl\] + \[Shift\] + \[P\] y verifica que exista la

instrucción Upload Little FS to Pico/ESP8266/ESP32

<!-- Página 72 del PDF original -->

![Manual de usuario, página 72, imagen 288](assets/manual/image-288.png){width=5.8in}

Verificación de la correcta instalación del plugin

5. Descarga el repositorio del proyecto en GitHub. En la ubicación:

\\software\\ESP32\\Smart_Home_App_ESP_COMV4 esta ubicado el programa.ino que se  
deberá cargar a la ESP32. Abre el archivo Smart_Home_App_ESP_COMV4

![Manual de usuario, página 72, imagen 289](assets/manual/image-289.png){width=5.8in}

Directorio programa ESP32

6. Sube la información a la ESP32 desde el IDE de Arduino conecta la DualONE con el monitor

serial cerrado y el programa a cargar abierto, se presiona \[Ctrl\] + \[Shift\] + \[P\] y se selecciona  
‘Upload Little FS to Pico/ESP8266/ESP32‘. Aparecerá la siguiente ventana.

<!-- Página 73 del PDF original -->

![Manual de usuario, página 73, imagen 290](assets/manual/image-290.png){width=5.8in}

Ventana: KittleFS Upload

Nota: Una vez aparezca el mensaje “Connecting………” puede ser necesario presionar el  
botón de boot de la DualONE si la carga no se hace en automático.

7. Espera a que se muestre el mensaje que confirme la correcta descarga de información.

![Manual de usuario, página 73, imagen 291](assets/manual/image-291.png){width=5.8in}

Mensaje de confirmación

8. Carga el archivo.ino a la ESP32.

Nota: Te sugerimos revisar la Guía de inicio rápido, así como la Wiki y datasheet del  
producto.

3.1.2 - RP2040

<!-- Página 74 del PDF original -->

Debes tener Arduino IDE instalado en tu computadora.

1. Descarga el repositorio del proyecto en GitHub. En la ubicación:

software\\RP2040\\Smart_Home_RP_V1 esta ubicado el programa.ino que se deberá cargar a  
la RP2040. Smart_Home_RP_V1

![Manual de usuario, página 74, imagen 292](assets/manual/image-292.png){width=5.8in}

Directorio programa RP2040

2. Carga el archivo.ino a la RP2040

Nota: Te sugerimos revisar la Guía de inicio rápido, así como la Wiki y datasheet del  
producto.

3.2 - Instalación de la app

Actualmente la aplicación solo está disponible para Android, descargando el.apk desde  
nuestras fuentes oficiales.

Dirígete al repositorio de GitHub, descarga el archivo.apk de la dirección:  
\\unit_kit_smarthome\\software\\App

Descarga el archivo.apk en tu dispositivo Android, aparecerá una ventana emergente  
preguntando por la instalación.

![Manual de usuario, página 74, imagen 293](assets/manual/image-293.png){width=3.3in}

Ventana emergente: Validar instalación de app

Presiona el botón “Instalar”

<!-- Página 75 del PDF original -->

![Manual de usuario, página 75, imagen 294](assets/manual/image-294.png){width=3.3in}

Ventana emergente: Instalación de app

Google Play Proyect analizará la seguridad de la app. Presiona “Analizar app”

![Manual de usuario, página 75, imagen 295](assets/manual/image-295.png){width=3.3in}

Ventana emergente: Revisión App (Google Play  
Protect)

Terminado el análisis, Google Play Protect avisará que la app es segura. Presiona “Instalar”

<!-- Página 76 del PDF original -->

![Manual de usuario, página 76, imagen 296](assets/manual/image-296.png){width=3.3in}

Ventana emergente: Validación de seguridad  
de la App (Google Play Protect)

Regresaremos a la ventana emergente de instalación. Espera un momento en lo que finaliza la  
instalación.

![Manual de usuario, página 76, imagen 297](assets/manual/image-297.png){width=3.3in}

Ventana emergente: Continuación de instalación

Terminada la aplicación aparecerá la siguiente ventana.

![Manual de usuario, página 76, imagen 298](assets/manual/image-298.png){width=3.3in}

Ventana emergente: Finalización de instalación

Podrás visualizar la aplicación en tu dispositivo Android.

<!-- Página 77 del PDF original -->

![Manual de usuario, página 77, imagen 299](assets/manual/image-299.png){width=3.3in}

Aplicación SmartHome instalada

Al abrir la app, podrás dar clic al ícono de Ayuda para revisar las funciones de la aplicación.

<!-- Página 78 del PDF original -->

![Manual de usuario, página 78, imagen 300](assets/manual/image-300.png){width=3.3in}

Botón ayuda

3.3 - Primera conexión

3.4 - Uso de la app, lectura de sensores, actuadores

3.5 - Modo Offline

4.- Recursos y documentación Oficial

Recurso

Descripción

URL

Wiki Platform

Wiki oficial

Documentación  
técnica completa

UNIT-Electronics-M  
X/unit_kit_smarthome

GitHub

Código fuente /  
firmware

## Recursos y dimensiones

<!-- Página 79 del PDF original -->

UNIT-Electronics-M  
unit_kit_smarthome /sof X/unit_kit_smarthome  
tware/App

Aplicación Móvil

Descarga oficial

IDE Arduino

Software programación https://docs.arduino.cc  
/software/ide/

Thonny, Python IDE  
for beginners  
https://code.visualstudi  
o.com/

Thonny

MicroPython

![Manual de usuario, página 79, imagen 301](assets/manual/image-301-alpha.png){width=0.65in}

Visual Studio Code

Entorno avanzado

https://code.visualstudi  
o.com/

5.- Información Mecánica y Dimensional

5.1 - Dimensiones ensamble:

18 x 15 x 19 \[cm\]

5.2 - Dimensiones del empaquetado:

27 x 17 x 15 \[cm\]

5.3 -Peso total:

5.4 - Materiales de construcción:

MDF, acrílico y PLA.

5.5 - Tipo de tornillería:

Tornillos milimétricos cabeza de queso ranurado

5.6 -Diagrama dimensional acotado:

<!-- Página 80 del PDF original -->

![Manual de usuario, página 80, imagen 303](assets/manual/image-303.png){width=5.8in}

Diagrama dimensional UNIT Smart Home
