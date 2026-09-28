## 3. Funciones del sistema

| Subsistema | Componentes | Función en el kit |
|---|---|---|
| Control | UNIT DualMCU ONE con ESP32 y RP2040 | Ejecuta el firmware del kit y coordina la interfaz móvil y los módulos. |
| Entradas ambientales | AHT10, KY-018, FC-37, KY-026, HC-SR505 | Lectura de temperatura, humedad, luz, lluvia, flama y movimiento. |
| Entradas de usuario | KY-040, TTP223B, RC522, HX1838 | Interacción por encoder, tacto, RFID e infrarrojo. |
| Salidas | SG90, motor DC, buzzer, tres WS2812, OLED | Movimiento, aviso, iluminación y visualización. |
| Expansión y control | Sensor Shield V5.0, Hub I²C, PCA9685, MX1508 | Distribución de conexiones, bus I²C, PWM y manejo del motor. |
| Aplicación | App SmartHome para Android | Presenta lecturas de sensores y controles de actuadores. |

![Conjunto montado con electrónica visible](assets/manual/image-198.png){width=4.4in}

El aprendizaje práctico incluye control PWM, comunicación I²C y lectura de señales analógicas y digitales. Las funciones disponibles en la app dependen del firmware instalado en ambos microcontroladores.
