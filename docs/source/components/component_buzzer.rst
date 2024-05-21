.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _cpn_buzzer:

Summer
=======

.. image:: img/buzzer.png
    :width: 600

Als eine Art von elektronischem Summer mit integrierter Struktur, die mit Gleichstrom versorgt werden, werden Summer häufig in Computern, Druckern, Fotokopierern, Alarmen, elektronischen Spielzeugen, automobilen Elektronikgeräten, Telefonen, Timern und anderen elektronischen Produkten oder Sprachgeräten verwendet.

Man kann Summer in aktive und passive unterteilen (siehe folgendes Bild). Wenn man den Summer so dreht, dass seine Pins nach oben zeigen, dann ist der Summer mit einer grünen Platine ein passiver Summer, während der mit schwarzem Klebeband umwickelte ein aktiver Summer ist.

Der Unterschied zwischen einem aktiven und einem passiven Summer: 

Ein aktiver Summer hat eine eingebaute Oszillationsquelle, daher gibt er Töne von sich, wenn er elektrifiziert wird. Ein passiver Summer hat jedoch keine solche Quelle und gibt daher keinen Ton von sich, wenn Gleichstromsignale verwendet werden. Stattdessen müssen Sie ihn mit Rechteckwellen antreiben, deren Frequenz zwischen 2K und 5K liegt. Der aktive Summer ist oft teurer als der passive aufgrund der eingebauten Oszillationskreise.

Das Folgende ist das elektrische Symbol eines Summers. Er hat zwei Pins, einen positiven und einen negativen Pol. Ein + auf der Oberfläche stellt die Anode dar, und der andere ist die Kathode.

.. image:: img/buzzer_symbol.png
    :width: 150

Sie können die Pins des Summers überprüfen: der längere ist die Anode und der kürzere die Kathode. Bitte verwechseln Sie sie nicht beim Anschließen, sonst gibt der Summer keinen Ton von sich.

`Summer - Wikipedia <https://en.wikipedia.org/wiki/Buzzer>`_

**Beispiel**

* :ref:`ar_beep` (Grundlegendes Projekt)
* :ref:`ar_passive_buzzer` (Grundlegendes Projekt)
* :ref:`iot_music` (IoT-Projekt)
