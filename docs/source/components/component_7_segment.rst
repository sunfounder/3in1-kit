.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _cpn_7_segment:

7-Segment-Anzeige
======================

.. image:: img/7_segment.png
    :width: 200
    :align: center

Eine 7-Segment-Anzeige ist eine Komponente in der Form einer 8, die aus 7 LEDs besteht. Jede LED wird als Segment bezeichnet - wenn sie mit Energie versorgt wird, bildet ein Segment einen Teil einer darzustellenden Zahl.

Es gibt zwei Arten von Pin-Verbindungen: Gemeinsame Kathode (CC) und Gemeinsame Anode (CA). Wie der Name schon sagt, hat eine CC-Anzeige alle Kathoden der 7 LEDs verbunden, während eine CA-Anzeige alle Anoden der 7 Segmente verbunden hat.

In diesem Bausatz verwenden wir die 7-Segment-Anzeige mit gemeinsamer Kathode, hier ist das elektronische Symbol dazu.

.. image:: img/segment_cathode.png
    :width: 800

Jede LED in der Anzeige erhält ein positionelles Segment, von dem einer ihrer Anschlusspins aus dem rechteckigen Kunststoffgehäuse herausgeführt wird. Diese LED-Pins sind von "a" bis "g" beschriftet und repräsentieren jede einzelne LED. Die anderen LED-Pins sind miteinander verbunden und bilden einen gemeinsamen Pin. Durch Vorwärtsbiasierung der entsprechenden Pins der LED-Segmente in einer bestimmten Reihenfolge leuchten einige Segmente auf, während andere dunkel bleiben, wodurch der entsprechende Charakter auf der Anzeige dargestellt wird.

**Anzeigecodes**

Um Ihnen zu helfen zu verstehen, wie 7-Segment-Anzeigen (Gemeinsame Kathode) Zahlen darstellen, haben wir die folgende Tabelle gezeichnet. Zahlen sind die Zahlen 0-F, die auf der 7-Segment-Anzeige dargestellt werden; (DP) GFEDCBA bezieht sich auf die entsprechende LED, die auf 0 oder 1 eingestellt ist. Zum Beispiel bedeutet 00111111, dass DP und G auf 0 eingestellt sind, während die anderen auf 1 eingestellt sind. Daher wird die Zahl 0 auf der 7-Segment-Anzeige angezeigt, während HEX-Code der entsprechenden Hexadezimalzahl entspricht.

.. image:: img/segment_code.png

**Beispiel**

* :ref:`ar_segment` (Grundlegendes Projekt)
* :ref:`iot_gate` (IoT-Projekt)
