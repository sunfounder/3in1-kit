.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _cpn_reed:

Reedschalter
======================

.. image:: img/reed.png

Der Reedschalter ist ein elektrischer Schalter, der mittels eines angelegten Magnetfeldes funktioniert. Er wurde 1936 von Walter B. Ellwood von den Bell Telephone Laboratories erfunden und am 27. Juni 1940 in den USA unter der Patentnummer 2264746 patentiert.

Das Funktionsprinzip eines Reedschalters ist sehr einfach. Zwei Reed-Kontakte (normalerweise aus Eisen und Nickel gefertigt, zwei Metallen), die an den Endpunkten überlappen, sind in einem Glasröhrchen versiegelt. Die beiden Reeds überlappen und sind durch eine kleine Lücke (nur einige Mikrometer) voneinander getrennt. Das Glasröhrchen ist mit einem hochreinen Inertgas (wie Stickstoff) gefüllt, und einige Reedschalter werden so hergestellt, dass sie im Inneren ein Vakuum aufweisen, um ihre Hochspannungsleistung zu verbessern.

Das Reed fungiert als Magnetflussleiter. Die beiden Reeds sind im Ruhezustand nicht in Kontakt; wenn sie durch ein von einem Permanentmagneten oder einer elektromagnetischen Spule erzeugtes Magnetfeld hindurchgehen, führt das angelegte Magnetfeld dazu, dass die beiden Reeds an ihren Endpunkten unterschiedliche Polaritäten aufweisen. Wenn die magnetische Kraft die Federkraft der Reeds selbst übersteigt, werden die beiden Reeds zusammengezogen, um den Schaltkreis zu leiten. Wenn das Magnetfeld schwächer wird oder verschwindet, werden die Reeds aufgrund ihrer eigenen Elastizität freigegeben und die Kontaktflächen trennen sich, um den Schaltkreis zu öffnen.

.. image:: img/reed_sche.png

* `Reedschalter – Wikipedia <https://en.wikipedia.org/wiki/Reed_switch>`_

**Beispiel**

* :ref:`ar_reed` (Grundlegendes Projekt)
* :ref:`iot_gate` (IoT-Projekt)
