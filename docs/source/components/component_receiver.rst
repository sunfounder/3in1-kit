.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _cpn_receiver:

IR-Empfänger
===========================

**IR-Empfänger**

.. image:: img/ir_receiver_hs0038b.jpg
    :align: center

* OUT: Signal-Ausgang
* GND：GND
* VCC: Stromversorgung, 3.3v~5V

Ein Infrarot-Empfänger ist eine Komponente, die Infrarotsignale empfängt und eigenständig Infrarotstrahlen empfangen sowie Signale ausgeben kann, die mit TTL-Pegel kompatibel sind. Er ist in Größe und Form einem gewöhnlichen Transistor im Plastikgehäuse ähnlich und eignet sich für alle Arten von Infrarot-Fernbedienungen und Infrarot-Übertragungen.

Infrarot, oder kurz IR, ist eine beliebte, kostengünstige und einfach zu verwendende drahtlose Kommunikationstechnologie. Infrarotlicht hat eine etwas längere Wellenlänge als sichtbares Licht und ist daher für das menschliche Auge nicht wahrnehmbar - ideal für die drahtlose Kommunikation. Ein gängiges Modulationsschema für Infrarotkommunikation ist die 38KHz-Modulation.

* Verwendet den `HS0038B <https://pdf1.alldatasheet.com/datasheet-pdf/view/103034/VISHAY/HS0038B.html>`_ IR-Empfänger-Sensor mit hoher Empfindlichkeit
* Kann für Fernbedienungen genutzt werden
* Stromversorgung: 5V
* Schnittstelle: Digital
* Modulationsfrequenz: 38Khz
* Pin-Belegung: (1) Ausgang (2) Vcc (3) GND
* Größe: 23.5mm x 21.5mm


**Fernbedienung**

.. image:: img/image186.jpeg
    :width: 400

Hierbei handelt es sich um eine schlanke Infrarot-Fernbedienung mit 21 Funktionstasten und einer Übertragungsreichweite von bis zu 8 Metern, die sich ideal für den Einsatz in einem Kinderzimmer eignet.

* Größe: 85x39x6mm
* Reichweite der Fernbedienung: 8-10m
* Batterie: 3V Knopfzellen-Lithium-Mangan-Batterie
* Infrarot-Trägerfrequenz: 38KHz
* Oberflächenklebematerial: 0.125mm PET
* Effektive Lebensdauer: mehr als 20.000 Betätigungen


**Beispiel**

* :ref:`ar_receiver` (Grundlegendes Projekt)
* :ref:`car_remote` (Auto-Projekt)
* :ref:`car_remote_plus` (Auto-Projekt)

