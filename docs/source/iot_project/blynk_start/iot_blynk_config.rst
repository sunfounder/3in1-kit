.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _config_blynk:

1.2 Blynk konfigurieren
==========================

#. Besuchen Sie die `BLYNK <https://blynk.io/>`_-Seite und klicken Sie auf **START FREE**.

    .. image:: img/sp220607_142551.png

#. Geben Sie Ihre E-Mail-Adresse ein, um ein Konto zu registrieren.

    .. image:: img/sp220607_142807.png

#. Überprüfen Sie Ihre E-Mail, um die Konto-Registrierung abzuschließen.

    .. image:: img/sp220607_142936.png

#. Danach erscheint die **Blynk Tour**. Sie können sie lesen, um grundlegende Informationen über Blynk zu erhalten.

    .. image:: img/sp220607_143244.png

#. Als nächstes müssen wir mit diesem **Quick Start** eine Vorlage und ein Gerät erstellen. Klicken Sie auf **Let's go**.

    .. image:: img/sp220607_143608.png

#. Wählen Sie die Hardware und den Verbindungstyp aus.

    .. image:: img/sp20220614173218.png

#. Ihnen wird mitgeteilt, welche IDE Sie benötigen. Wir empfehlen die **Arduino IDE**.

    .. image:: img/sp20220614173454.png

#. Hier ist die benötigte Bibliothek aufgeführt. Die hier empfohlene Bibliothek ist jedoch etwas problematisch. Wir müssen andere Bibliotheken manuell hinzufügen (dazu später mehr). Klicken Sie hier auf **Next** und eine neue Vorlage sowie ein Gerät werden erstellt.

    .. image:: img/sp20220614173629.png

#. Die nächsten Schritte wären, den relevanten Code hochzuladen und Ihr Board mit Blynk zu verbinden. Da es jedoch ein Problem mit der zuvor bereitgestellten Bibliothek gibt, müssen Sie erneut andere Bibliotheken hinzufügen. Klicken Sie also hier auf **Cancel**, um den **Quick Start** zu beenden.

    .. image:: img/sp20220614174006.png

#. Klicken Sie auf den **Search**-Button und Sie sehen das Gerät, das Sie gerade erstellt haben.

    .. image:: img/sp20220614174410.png

#. Gehen Sie zu diesem **Quickstart Device** und auf der **Device info**-Seite sehen Sie ``TEMPLATE_ID``, ``DEVICE_NAME`` und ``AUTH_TOKEN``. Diese Informationen werden Sie später benötigen und müssen sie kopieren.

    .. image:: img/sp20220614174721.png
