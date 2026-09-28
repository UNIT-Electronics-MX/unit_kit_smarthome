## 5. Ensamble y puesta en marcha

### 5.1 Secuencia de ensamble

1. Inventariar las piezas y reunir desarmadores, pinzas y cautín. Colocar la pila de botón en el control IR y soldar los pines de los módulos que lo requieren.
2. Energizar el SG90 para ubicar su posición inicial; después montar la puerta y la base MDF-A.
3. Montar las paredes, los techos y los módulos. El manual desglosa esta etapa en los ensambles 1.1 a 1.9.
4. Atornillar la DualMCU ONE y conectar su cable Qwiic al Hub I²C antes de instalar la Sensor Shield.
5. Conectar sensores, OLED, servo, Neopixel y motor a la shield, Hub I²C, PCA9685 o MX1508 conforme a los diagramas del capítulo 4.
6. Cerrar la estructura y revisar que ningún cable quede pellizcado. Verificar polaridad y ausencia de cortocircuitos antes de alimentar con el adaptador.

![Ensamble final de la casa](assets/manual/image-274.png){width=4.2in}

El capítulo 10 incluye todas las páginas del manual migradas a esta referencia, con las vistas y la posición de cada tornillo. También puede abrir cada figura desde la [galería de imágenes](manual-figures.html).

### 5.2 Firmware

La DualMCU ONE se entrega con firmware pregrabado. Si requiere reinstalarlo, abra en Arduino IDE los programas del repositorio:

| Procesador | Programa local | Acción |
|---|---|---|
| ESP32 | `software/ESP32/Smart_Home_App_ESP_COMV4/Smart_Home_App_ESP_COMV4.ino` | Cargar primero los datos LittleFS con el complemento indicado en el manual y luego subir el sketch. |
| RP2040 | `software/RP2040/Smart_Home_RP_V1/Smart_Home_RP_V1.ino` | Compilar y cargar el sketch para la placa correspondiente. |

El complemento LittleFS y la configuración de placa dependen de la versión del IDE. El manual explica el proceso de carga y el uso del botón BOOT cuando la conexión no ocurre automáticamente.

### 5.3 Aplicación móvil

El APK está en `software/App/smartHomeApp.apk`. Instálelo en Android desde la fuente oficial del repositorio. Al abrir la app, el botón **Ayuda** describe sus funciones. El manual muestra la visualización de sensores y los controles de actuadores, pero deja sin instrucciones desarrolladas las secciones «Primera conexión», «Uso de la app» y «Modo Offline»; no se deben inferir pasos de emparejamiento a partir de esos títulos.

![Vista de sensores en la aplicación](assets/manual/image-283.jpg){width=2.2in}
