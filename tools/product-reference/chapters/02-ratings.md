## 2. Alimentación y precauciones

El kit se alimenta con el **adaptador de 12 V, 2 A con jack** incluido. Este valor corresponde únicamente al adaptador; no define por sí solo los límites eléctricos de cada sensor, del ESP32, del RP2040 ni de los conectores de la shield. Antes de usar otra fuente de alimentación o de agregar cargas externas, consulta la documentación de cada módulo.

| Punto de revisión | Indicación |
|---|---|
| Antes de energizar | Verifica la polaridad, la alimentación y la posición de todos los conectores. |
| Neopixel | Respeta la polaridad: una conexión invertida puede dañar el módulo. |
| Cableado de sensores y actuadores | Una conexión incorrecta puede dañar los módulos. |
| Bus I²C | Conecta la DualMCU ONE al Hub I²C mediante el cable Qwiic antes de colocar la Sensor Shield. |
| Motor DC | Acomoda los cables de modo que el MDF no los corte ni los presione. |
| Servomotor | Energízalo y llévalo a su posición inicial antes de montar la puerta. |

Este documento no especifica la corriente máxima por puerto ni los límites de tensión de cada señal. Para el cableado, sigue los diagramas del capítulo 4 y las marcas impresas en cada placa.
