## 3. Descripción funcional

| Subsistema | Componentes | Función en el kit |
|---|---|---|
| Control | UNIT DualMCU ONE con ESP32 y RP2040 | Ejecuta el firmware del kit y coordina la aplicación móvil con los módulos. |
| Entradas ambientales | AHT10, KY-018, FC-37, KY-026, HC-SR505 | Miden temperatura, humedad, luz, lluvia, flama y movimiento. |
| Entradas de usuario | KY-040, TTP223B, RC522, HX1838 | Permiten la interacción mediante encoder, tacto, RFID e infrarrojo. |
| Salidas | SG90, motor DC, buzzer, tres WS2812, OLED | Generan movimiento, avisos sonoros, iluminación y visualización. |
| Expansión y control | Sensor Shield V5.0, Hub I²C, PCA9685, MX1508 | Distribuyen las conexiones y proporcionan el bus I²C, las salidas PWM y el control del motor. |
| Aplicación | App SmartHome para Android | Muestra las lecturas de los sensores y permite controlar los actuadores. |

![Conjunto montado con electrónica visible](assets/manual/image-198.png){width=4.4in}

Con este kit se practica el control PWM, la comunicación I²C y la lectura de señales analógicas y digitales. Las funciones disponibles en la app dependen del firmware cargado en ambos microcontroladores.
