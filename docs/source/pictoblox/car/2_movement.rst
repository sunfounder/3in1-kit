.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _sh_move:

3.2 Bewegung
==================

Dieses Projekt basiert auf :ref:`sh_test`, um das Auto in alle Richtungen bewegen zu lassen.

Bevor wir mit der Programmierung beginnen, lassen Sie uns das Arbeitsprinzip des L9110-Moduls überprüfen.

Hier ist die Wahrheitstabelle für den Motor B:

.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - B-1A
      - B-1B(B-2A)
      - Zustand des Motor B
    * - 1
      - 0
      - Dreht im Uhrzeigersinn
    * - 0
      - 1
      - Dreht gegen den Uhrzeigersinn
    * - 0
      - 0
      - Bremse
    * - 1
      - 1
      - Stopp

Hier ist die Wahrheitstabelle für den Motor A:

.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - A-1A
      - A-1B
      - Zustand des Motor A
    * - 1
      - 0
      - Dreht im Uhrzeigersinn
    * - 0
      - 1
      - Dreht gegen den Uhrzeigersinn
    * - 0
      - 0
      - Bremse
    * - 1
      - 1
      - Stopp

Programmierung
-------------------

Nun erstellen Sie Blöcke, um das Auto vorwärts, rückwärts, links und rechts zu bewegen und es jeweils anzuhalten.

**1. Vorwärts bewegen**

Der rechte Motor dreht im Uhrzeigersinn und der linke Motor gegen den Uhrzeigersinn, um das Auto vorwärts zu bewegen.

.. image:: img/2_forward.png

**2. Rückwärts bewegen**

Rückwärts ist genau das Gegenteil, der rechte Motor muss gegen den Uhrzeigersinn drehen, der linke Motor im Uhrzeigersinn.

.. image:: img/2_backward.png

**3. Links drehen**

Die linken und rechten Motoren drehen gleichzeitig im Uhrzeigersinn, um das Auto nach links zu drehen.

.. image:: img/2_turn_left.png

**4. Rechts drehen**

Drehen Sie die linken und rechten Motoren in entgegengesetzter Richtung, um das Auto nach rechts zu drehen.

.. image:: img/2_turn_right.png

**5. Stopp**

Stoppen Sie das Auto, indem Sie alle Motoren auf 0 setzen.

.. image:: img/2_stop.png

**6. Das Auto bewegen**

Lassen Sie das Auto vorwärts, rückwärts, links und rechts für 1 Sekunde bewegen, dann stoppen. Da alle Blöcke im [Forever]-Block platziert sind, werden Sie sehen, dass das Auto die obigen Aktionen wiederholt.

.. image:: img/2_move.png
