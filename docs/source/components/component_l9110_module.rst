.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _cpn_l9110:

L9110 Motortreibermodul
=============================

Das L9110 Motortreibermodul eignet sich hervorragend zum Ansteuern von zwei Motoren gleichzeitig. Es beherbergt ein Paar unabhängiger L9110S-Treiberchips, wobei jeder Kanal einen konstanten Stromausgang von bis zu 800mA bietet.

Mit einem Spannungsbereich von 2,5V bis 12V harmoniert das Modul problemlos sowohl mit 3,3V als auch mit 5V Mikrocontrollern.

Als kompakte Lösung erleichtert das L9110 Motortreibermodul die Motorsteuerung in einer Vielzahl von Anwendungen. Dank seiner Dual-Kanal-Architektur ermöglicht es die unabhängige Steuerung von zwei Motoren – ideal für Projekte, bei denen der Betrieb von zwei Motoren im Vordergrund steht.

Angesichts seiner starken Dauerstromausgabe versorgt dieses Modul sicher Motoren von klein bis mittelgroß und ebnet den Weg für vielfältige robotische, automatisierungsbezogene und motorzentrierte Vorhaben. Sein weitreichender Spannungsbereich erhöht die Anpassungsfähigkeit und passt sich verschiedenen Stromversorgungskonzepten an.

Mit Blick auf Benutzerfreundlichkeit konzipiert, bietet das Modul intuitive Ein- und Ausgabeterminals, die den Anschluss an Mikrocontroller oder ähnliche Steuergeräte vereinfachen. Zudem wurde nicht an Sicherheit gespart – integrierte Überstrom- und Übertemperaturschutzmaßnahmen erhöhen die Zuverlässigkeit und Sicherheit des Motorbetriebs.

.. image:: img/l9110_module.jpg
    :width: 600
    :align: center
    
* **B-1A & B-1B(B-2A)**: Eingangspins zur Steuerung der Drehrichtung von Motor B.
* **A-1A & A-1B**: Eingangspins zur Steuerung der Drehrichtung von Motor A.
* **0A & OB(A)**: Ausgangspins von Motor A.
* **0A & OB(B)**: Ausgangspins von Motor B.
* **VCC**: Stromversorgungspin (2,5V-12V).
* **GND**: Massepin.

**Merkmale**

* On-Board 2 L9110S Motorsteuerchips
* Dual-Kanal-Motorsteuerung.
* Unabhängige Steuerung der Motordrehrichtung.
* Hoher Stromausgang (800mA pro Kanal).
* Weiter Spannungsbereich (2,5V-12V).
* Kompaktes Design.
* Praktische Ein- und Ausgabeterminals.
* Integrierte Schutzfunktionen.
* Vielseitige Anwendungsmöglichkeiten.
* PCB-Größe: 29,2mm x 23mm
* Betriebstemperatur: -20°C ~ 80°C
* LED-Anzeige bei eingeschaltetem Zustand

**Funktionsprinzip**

Hier ist die Wahrheitstabelle für Motor B:

Diese WahrheitstabelleB-1B(B-2A)gt die verschiedenen Zustände von Motor B basierend auf den Werten der Eingangspins B-1A und B-1B. Sie gibt die Drehrichtung (im Uhrzeigersinn oder gegen den Uhrzeigersinn), Bremsen oder Anhalten von Motor B an.

.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - B-1A
      - B-1B(B-2A)
      - Zustand von Motor B
    * - 1
      - 0
      - Drehen im Uhrzeigersinn
    * - 0
      - 1
      - Drehen gegen den Uhrzeigersinn
    * - 0
      - 0
      - Bremsen
    * - 1
      - 1
      - Anhalten

Hier ist die Wahrheitstabelle für Motor A:

Diese Wahrheitstabelle zeigt die verschiedenen Zustände von Motor A basierend auf den Werten der Eingangspins A-1A und A-1B. Sie gibt die Drehrichtung (im Uhrzeigersinn oder gegen den Uhrzeigersinn), Bremsen oder Anhalten von Motor A an.

.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - A-1A
      - A-1B
      - Zustand von Motor A
    * - 1
      - 0
      - Drehen im Uhrzeigersinn
    * - 0
      - 1
      - Drehen gegen den Uhrzeigersinn
    * - 0
      - 0
      - Bremsen
    * - 1
      - 1
      - Anhalten

* :ref:`ar_motor` (Grundprojekt)
* :ref:`car_move` (Auto-Projekt)
* :ref:`car_speed` (Auto-Projekt)
* :ref:`iot_car` (IoT-Projekt)