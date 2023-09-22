.. _sh_move:

3.2 Bewegung
==================

Dieses Projekt basiert auf :ref:`sh_test`, um das Auto in alle Richtungen bewegen zu lassen.

Bevor wir mit der Programmierung beginnen, lassen Sie uns das Arbeitsprinzip von L298N überprüfen.

Die Arbeitsbeziehung zwischen ENA und IN1, IN2 ist wie folgt:

.. list-table:: 
    :widths: 25 25 25 50
    :header-rows: 1

    * - ENA
      - IN1
      - IN2
      - Zustand des rechten Motors(A)
    * - 0
      - X
      - X
      - Stopp
    * - 1
      - 0
      - 0
      - Bremsen
    * - 1
      - 0
      - 1
      - Drehung im Uhrzeigersinn
    * - 1
      - 1
      - 0
      - Drehung gegen den Uhrzeigersinn
    * - 1
      - 1
      - 1
      - Bremsen

Die Arbeitsbeziehung zwischen ENB und IN3, IN4 ist wie folgt:

.. list-table:: 
    :widths: 25 25 25 50
    :header-rows: 1

    * - ENB
      - IN3
      - IN4
      - Zustand des linken Motors(B)
    * - 0
      - X
      - X
      - Stopp
    * - 1
      - 0
      - 0
      - Bremsen
    * - 1
      - 0
      - 1
      - Drehung im Uhrzeigersinn
    * - 1
      - 1
      - 0
      - Drehung gegen den Uhrzeigersinn
    * - 1
      - 1
      - 1
      - Bremsen


Programmierung
-------------------

Erstellen Sie nun Blöcke, um das Auto vorwärts, rückwärts, links und rechts drehen und stoppen zu lassen.

**1. Vorwärts fahren**

Der rechte Motor dreht sich im Uhrzeigersinn und der linke Motor gegen den Uhrzeigersinn, um das Auto vorwärts zu bewegen.

.. image:: img/2_forward.png

**2. Rückwärts fahren**

Rückwärts ist genau das Gegenteil: Der rechte Motor muss sich gegen den Uhrzeigersinn drehen, der linke Motor im Uhrzeigersinn.

.. image:: img/2_backward.png

**3. Links abbiegen**

Die linken und rechten Motoren drehen sich gleichzeitig im Uhrzeigersinn, um das Auto nach links zu drehen.

.. image:: img/2_turn_left.png

**4. Rechts abbiegen**

Drehen Sie die linken und rechten Motoren in entgegengesetzter Richtung, um das Auto nach rechts zu drehen.

.. image:: img/2_turn_right.png

**5. Stoppen**

Stoppen Sie das Auto, indem Sie alle Motoren auf 0 setzen.

.. image:: img/2_stop.png

**6. Das Auto bewegen**

Lassen Sie das Auto vorwärts, rückwärts, links und rechts für 1 Sekunde fahren, dann stoppen. Da alle Blöcke im [Forever]-Block platziert sind, werden Sie sehen, dass das Auto die oben genannten Aktionen wiederholt.

.. image:: img/2_move.png
