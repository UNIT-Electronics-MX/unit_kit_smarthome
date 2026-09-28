## 2. Alimentación y precauciones

El kit se alimenta con el **adaptador de 12 V, 2 A con jack** incluido. Esa cifra describe el adaptador del conjunto; no establece por sí sola los límites eléctricos de cada sensor, del ESP32, del RP2040 ni de los conectores de la shield. Consulte la documentación de cada módulo antes de usar otra fuente o agregar cargas externas.

| Punto de revisión | Indicación del manual |
|---|---|
| Antes de energizar | Corroborar polaridad, alimentación y posición de todos los conectores. |
| Neopixel | Respetar la polaridad: una conexión invertida puede dañar el módulo. |
| Cableado de sensores y actuadores | Una mala conexión puede dañar los módulos. |
| Bus I²C | Conectar DualMCU ONE al Hub I²C por Qwiic antes de colocar la Sensor Shield. |
| Motor DC | Disponer los cables de modo que el MDF no los corte ni los presione. |
| Servomotor | Energizarlo y colocarlo en la posición inicial antes del montaje de la puerta. |

El manual no aporta una tabla de corriente máxima por puerto ni los límites de tensión de las señales individuales. Para el cableado use los diagramas del capítulo 4 y las marcas impresas en cada placa.
