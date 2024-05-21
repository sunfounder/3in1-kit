.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _sh_test:

3.1 Das Auto testen
======================

Hier erfahren Sie, wie Sie Skripte schreiben, um das Auto vorwärts zu bewegen. Dennoch sollten Sie sich auf :ref:`car_projects` beziehen, um das Auto zusammenzubauen und ein grundlegendes Verständnis dafür zu erlangen.

Bevor Sie mit dem Projekt beginnen, sollten Sie sich mit den Schritten vertraut machen, um PictoBlox im :ref:`upload_mode` zu verwenden.

Benötigte Komponenten
------------------------

Für dieses Projekt benötigen Sie folgende Komponenten:

Ein komplettes Set zu erwerben, ist sicherlich praktisch. Hier ist der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name
        - ARTIKEL IM SET
        - LINK
    *   - 3-in-1 Starter Set
        - 380+
        - |link_3IN1_kit|

Alternativ können Sie die Teile einzeln über die folgenden Links erwerben:

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - KOMPONENTENBESCHREIBUNG
        - KAUF-LINK

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_l9110` 
        - \-
    *   - :ref:`cpn_tt_motor`
        - \-

Schaltkreis aufbauen
-----------------------

Das L9110 Motortreibermodul ist ein Hochleistungsmotortreiber für Gleichstrom- und Schrittmotoren. Mit dem L9110-Modul können bis zu 4 Gleichstrommotoren oder 2 Gleichstrommotoren mit Richtungs- und Geschwindigkeitskontrolle gesteuert werden.

Verbinden Sie die Drähte zwischen dem L9110-Modul und dem R3-Board gemäß dem untenstehenden Diagramm.

.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - L9110 Modul
      - R3 Board
      - Motor
    * - A-1B
      - 5
      - 
    * - A-1A
      - 6
      - 
    * - B-1B(B-2A)
      - 9
      - 
    * - B-1A
      - 10
      - 
    * - OB(B)
      - 
      - Schwarzes Kabel des rechten Motors
    * - OA(B)
      - 
      - Rotes Kabel des rechten Motors
    * - OB(A)
      - 
      - Schwarzes Kabel des linken Motors
    * - OA(A)
      - 
      - Rotes Kabel des linken Motors

.. image:: img/car_2.png
    :width: 800

Programmierung
-------------------

**1. Das Auto vorwärts bewegen**

Aufgrund der obigen Verkabelung wissen wir, dass die Pins 5 und 6 zur Steuerung der rechten Motorrotation und die Pins 9 und 10 für die linke Motorrotation verwendet werden. Schreiben Sie jetzt ein Skript, damit das Auto vorwärts fährt.

Nachdem Sie das Board als Arduino Uno ausgewählt haben, wechseln Sie in den :ref:`upload_mode` und schreiben das Skript entsprechend dem folgenden Diagramm.

.. image:: img/1_test1.png

Klicken Sie auf die Schaltfläche **Upload Code**, um den Code auf das R3-Board hochzuladen. Sobald dies erledigt ist, werden die beiden Motoren des Autos vorwärts bewegt (wenn Sie das Auto auf den Boden setzen, wird es in einer geraden Linie vorwärts fahren. Es kann jedoch sein, dass das Auto eine Kurve fährt, da die Geschwindigkeit der beiden Motoren leicht unterschiedlich ist).

Wenn nicht beide Motoren vorwärts drehen, sondern die folgenden Situationen auftreten, müssen Sie die Verkabelung der beiden Motoren neu anpassen.

* Wenn beide Motoren gleichzeitig rückwärts drehen (linker Motor dreht im Uhrzeigersinn, rechter Motor gegen den Uhrzeigersinn), tauschen Sie die Verkabelung der linken und rechten Motoren gleichzeitig, OA(A) und OB(A) tauschen, OA(B) und OB(B) tauschen.
* Wenn der linke Motor rückwärts dreht (im Uhrzeigersinn), tauschen Sie die Verkabelung von OA(B) und OB(B) des linken Motors.
* Wenn der rechte Motor rückwärts dreht (gegen den Uhrzeigersinn), tauschen Sie die Verkabelung von OA(A) und OB(A) des rechten Motors.

**2. Block erstellen**

Um das Skript übersichtlicher und einfacher zu gestalten, fügen wir hier alle Blöcke, die die Vorwärtsbewegung steuern, in einen Block ein. Wenn Sie ihn verwenden möchten, rufen Sie diesen Block direkt auf.

Klicken Sie in der **My Blocks**-Palette auf **My Blocks**.

.. image:: img/1_test31.png

Geben Sie den Namen des Blocks - **forward** ein und aktivieren Sie **Add an input**, setzen Sie den Eingabenamen auf **speed**.

.. image:: img/1_test32.png

Ziehen Sie die Blöcke, die die Vorwärtsbewegung des Autos steuern, in **forward**. Beachten Sie, dass Sie den Parameter - **speed** zu den Pins 6 und 9 hinzufügen müssen.

.. image:: img/1_test33.png

Rufen Sie den erstellten Block im [Forward]-Block - **forward** auf. Im Upload-Modus muss am Anfang der Block [When Arduino Uno starts up] hinzugefügt werden.

* Der Geschwindigkeitsbereich der Motorrotation liegt zwischen 100 und 255.

.. image:: img/1_test3.png
    
**3. Geschwindigkeit der Motoren anpassen**

Da es möglicherweise einen leichten Unterschied in der Geschwindigkeit der 2 Motoren gibt, wodurch das Auto nicht in einer geraden Linie fahren kann, können wir den linken und rechten Motoren unterschiedliche Geschwindigkeiten geben, um das Auto so weit wie möglich in einer geraden Linie zu bewegen.

Da mein Auto langsam nach rechts vorne fährt, reduziere ich hier die Geschwindigkeit des linken Motors.

.. image:: img/1_test2.png

