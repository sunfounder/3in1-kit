.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _cpn_potentiometer:

Potentiometer
===============

.. image:: img/potentiometer.png
    :align: center
    :width: 150

Ein Potentiometer ist ebenfalls ein Widerstandsbauelement mit drei Anschlüssen, dessen Widerstandswert nach einer bestimmten Regelung variiert werden kann.

Potentiometer gibt es in verschiedenen Formen, Größen und Werten, sie haben jedoch alle folgende Merkmale gemeinsam:

* Sie haben drei Anschlüsse (oder Verbindungspunkte).
* Sie verfügen über einen Drehknopf, eine Schraube oder einen Schieber, um den Widerstand zwischen dem mittleren und einem der äußeren Anschlüsse zu variieren.
* Der Widerstand zwischen dem mittleren Anschluss und einem der äußeren Anschlüsse variiert von 0 Ω bis zum maximalen Widerstand des Potentiometers, wenn der Knopf, die Schraube oder der Schieber bewegt wird.

Hier ist das Schaltsymbol des Potentiometers.

.. image:: img/potentiometer_symbol.png
    :align: center
    :width: 400

Die Funktionen des Potentiometers im Schaltkreis sind:

#. Als Spannungsteiler dienen:

    Ein Potentiometer ist ein kontinuierlich einstellbarer Widerstand. Beim Verstellen der Welle oder des Schiebegriffs des Potentiometers gleitet der bewegliche Kontakt über den Widerstand. Zu diesem Zeitpunkt kann, abhängig von der am Potentiometer angelegten Spannung und dem Winkel, um den sich der bewegliche Arm gedreht hat oder der zurückgelegten Strecke, eine Spannung ausgegeben werden.

#. Als Rheostat dienen:

    Wenn das Potentiometer als Rheostat verwendet wird, verbinden Sie den mittleren Pin und einen der anderen beiden Pins im Schaltkreis. So erhalten Sie einen sanft und kontinuierlich veränderten Widerstandswert innerhalb des Fahrwegs des beweglichen Kontakts.

#. Als Stromregler dienen:

    Wenn das Potentiometer als Stromregler fungiert, muss der Schiebekontaktanschluss als einer der Ausgangsanschlüsse verbunden werden.

Wenn Sie mehr über Potentiometer erfahren möchten, verweisen Sie auf: `Potentiometer – Wikipedia <https://en.wikipedia.org/wiki/Potentiometer>`_

**Beispiel**

* :ref:`ar_potentiometer` (Grundlegendes Projekt)

.. * :ref:`sh_moving_mouse` (Scratch-Projekt)
.. * :ref:`sh_breakout_clone` (Scratch-Projekt)
