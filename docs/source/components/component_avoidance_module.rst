.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _cpn_avoid:

Hindernisvermeidungsmodul
===========================================

.. image:: img/IR_Obstacle.png
   :width: 400
   :align: center

* **VCC**: Stromversorgung, 3,3 ~ 5V DC.
* **GND**: Masse
* **OUT**: Signalausgang, normalerweise im hohen Zustand, schaltet auf niedrig, wenn ein Hindernis erkannt wird.

Das IR-Hindernisvermeidungsmodul passt sich stark dem Umgebungslicht an und verfügt über ein Paar Infrarot-Sende- und Empfangsröhren.

Die Sendetube gibt eine Infrarotfrequenz ab. Trifft die Erkennungsrichtung auf ein Hindernis, wird die Infrarotstrahlung von der Empfangsröhre aufgenommen. 
Nach der Verarbeitung im Komparator-Schaltkreis leuchtet die Anzeige auf und gibt ein niedriges Signal aus.

Die Erkennungsentfernung kann mit einem Potentiometer angepasst werden, wobei der effektive Entfernungsbereich zwischen 2-30 cm liegt.

.. image:: img/IR_module.png
    :width: 600
    :align: center

**Beispiel**

* :ref:`ar_ir_obstacle` (Grundlegendes Projekt)
* :ref:`car_ir_obstacle` (Auto-Projekt)
* :ref:`self_driving` (Auto-Projekt)
* :ref:`iot_gate` (IoT-Projekt)

.. * :ref:`sh_shooting` (Scratch-Projekt)
.. * :ref:`sh_tap_tile` (Scratch-Projekt)

