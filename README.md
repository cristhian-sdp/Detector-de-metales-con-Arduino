# Detector de metales con Arduino

🙌 Hola, en este repositorio encontrarás el código del proyecto "Detector de metales con Arduino"

## Introducción

En la actualidad, la detección de metales es esencial para una variedad de tareas, desde la seguridad de los aeropuertos hasta la investigación arqueológica. Este proyecto tiene como objetivo "Diseñar y construir un detector de metales que pueda identificar objetos metálicos en su entorno utilizando Arduino".

## Materiales

- Arduino uno
- 2 Capacitores 470uf 50V
- 2 Capacitores 2.2uf 50V
- 2 Capacitores 100nf (104 polyester)
- Capacitor 10uf 25V
- Capacitor 100uf
- 2 Resistencias 2.2kΩ 1V
- 2 Resistencias 3kΩ 1V
- Resistencia 47kΩ
- Socalo de 8 pines (para el TIMER N555)
- TIMER N555
- Inductor 6800uH
- Placa de cobre PCB 7x5 + 1/2 litro de ácido férrico
- 3 Diodos 1N4007
- Reóstato TRIMMER 20k
- Conector de alimentación macho y hembra dc 5.5mm
- Batería de 9V
- Enchufe de batería de 9V
- Mini interruptor 6 pines
- Regulador LM317 1Amp
- Regleta de pines
- Bobina 20 vueltas calibre 15 o 20

## Diseño del Proyecto

El proyecto utiliza componentes electrónicos como capacitores, resistencias, inductores y diodos para crear un campo magnético alterno y registrar las variaciones en la inductancia provocadas por la presencia de metales. La programación de Arduino gestiona y procesa las señales capturadas.

![Diseño en Proteus](/proteus-diseño.jpeg)

El proyecto es capaz de detectar la presencia de objetos metálicos en su entorno. La sensibilidad del detector se ajustó para detectar tanto objetos metálicos pequeños como grandes, lo que lo hace apropiado para una variedad de aplicaciones. El dispositivo es portátil y puede operar de forma independiente con una batería de 9V.
