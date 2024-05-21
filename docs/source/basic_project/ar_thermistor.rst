.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _ar_temp:

4.5 Thermometer
===========================

Ein Thermometer ist ein Gerät, das die Temperatur oder einen Temperaturgradienten misst (das Maß für die Hitze oder Kälte eines Objekts).
Ein Thermometer hat zwei wichtige Elemente: (1) einen Temperatursensor (z.B. die Glühbirne eines Quecksilber-Thermometers oder den pyrometrischen Sensor in einem Infrarot-Thermometer), bei dem eine Änderung mit einer Temperaturänderung eintritt; 
und (2) eine Möglichkeit, diese Änderung in einen Zahlenwert umzuwandeln (z.B. die sichtbare Skala, die auf einem Quecksilber-Thermometer markiert ist, oder die digitale Anzeige bei einem Infrarot-Modell). 
Thermometer werden in Technologie und Industrie zur Prozessüberwachung, in der Meteorologie, in der Medizin und in der wissenschaftlichen Forschung weit verbreitet verwendet.

Ein Thermistor ist eine Art Temperatursensor, dessen Widerstand stark temperaturabhängig ist und er hat zwei Typen: 
Negativer Temperaturkoeffizient (NTC) und Positiver Temperaturkoeffizient (PTC), 
auch bekannt als NTC und PTC. Der Widerstand des PTC-Thermistors steigt mit der Temperatur, während der Zustand des NTC dem des PTC entgegengesetzt ist.

In diesem Experiment verwenden wir einen **NTC-Thermistor**, um ein Thermometer zu bauen.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist definitiv praktisch, ein komplettes Set zu kaufen, hier ist der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ARTIKEL IN DIESEM KIT
        - LINK
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

Sie können sie auch separat über die untenstehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - KOMPONENTENBESCHREIBUNG
        - KAUF-LINK

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_thermistor`
        - |link_thermistor_buy|

**Schaltplan**

.. image:: img/circuit_5.5_thermistor.png

Jeder Thermistor hat einen normalen Widerstand. Hier beträgt er 10k Ohm, gemessen bei 25 Grad Celsius.

Wenn die Temperatur steigt, verringert sich der Widerstand des Thermistors. Dann werden die Spannungsdaten vom A/D-Wandler in digitale Werte umgewandelt.

Die Temperatur in Celsius oder Fahrenheit wird mittels Programmierung ausgegeben.

Hier ist die Beziehung zwischen Widerstand und Temperatur:

    **RT =RN expB(1/TK – 1/TN)** 

    * **RT** ist der Widerstand des NTC-Thermistors bei der Temperatur **TK**. 
    * **RN** ist der Widerstand des NTC-Thermistors bei der Nenn-Temperatur TN. Hier beträgt der Wert von RN 10k.
    * **TK** ist eine Kelvin-Temperatur und die Einheit ist K. Der Wert von **TK** beträgt hier ``273,15 + Grad Celsius``.
    * **TN** ist eine bewertete Kelvin-Temperatur; die Einheit ist auch K. Hier beträgt der Wert von TN ``273,15+25``.
    * Und **B(beta)**, die Materialkonstante des NTC-Thermistors, wird auch als Wärmeempfindlichkeitsindex bezeichnet und hat einen Wert von ``3950``.
    * **exp** steht für Exponentialfunktion, und die Basiszahl ``e`` ist eine natürliche Zahl und beträgt ungefähr 2,7.

    Wandeln Sie diese Formel ``TK=1/(ln(RT/RN)/B+1/TN)`` um, um die Kelvin-Temperatur zu erhalten, die minus 273,15 Grad Celsius entspricht.

    Diese Beziehung ist eine empirische Formel. Sie ist nur dann genau, wenn Temperatur und Widerstand im effektiven Bereich liegen.

**Verkabelung**

.. note::
    * Der Thermistor ist schwarz oder grün und mit 103 gekennzeichnet.

.. image:: img/thermistor_bb.png
    :width: 600
    :align: center

**Code**

.. note::

   * Sie können die Datei ``4.5_thermometer.ino`` im Pfad ``euler-kit/arduino/4.5_thermometer`` öffnen.
   * Oder kopieren Sie diesen Code in die **Arduino IDE**.
   
   * Oder laden Sie den Code über den `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_ hoch.

    Vergessen Sie nicht, das Raspberry Pi Pico Board und den richtigen Port auszuwählen, bevor Sie auf den Upload-Button klicken.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/1ceb0ea2-a330-4052-824d-bd6762c6f0e0/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    

Nach erfolgreichem Hochladen des Codes wird der Serial Monitor die Temperaturen in Celsius und Fahrenheit ausgeben.
