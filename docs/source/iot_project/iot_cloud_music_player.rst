.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _iot_music:

4. Cloud-Musikplayer
=====================================

Das Ziel dieses Projekts ist es, einen Musikplayer mit Blynk zu erstellen.
Die Musik wird genauso abgespielt wie in :ref:`ar_passive_buzzer`, indem man das Lied im Programm schreibt und es mit einem passiven Buzzer abspielt.
In diesem Beispiel können wir jedoch den Schalter klicken, um die Wiedergabe zu starten/anhalten und den Schieberegler verschieben, um den Wiedergabefortschritt zu ändern.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist definitiv praktisch, ein ganzes Set zu kaufen, hier ist der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ARTIKEL IN DIESEM KIT
        - LINK
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

Sie können sie auch einzeln über die untenstehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - KOMPONENTENBESCHREIBUNG
        - KAUF-LINK

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_esp8266`
        - |link_esp8266_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_buzzer`
        - |link_passive_buzzer_buy|

**1. Schaltung aufbauen**

.. note::

    Das ESP8266-Modul benötigt einen hohen Strom, um eine stabile Betriebsumgebung zu gewährleisten. Stellen Sie daher sicher, dass die 9V-Batterie angeschlossen ist.

.. image:: img/wiring_buzzer.jpg

**2. Dashboard bearbeiten**

#. Erstellen Sie einen **Datastream** des Typs **Virtual Pin** auf der **Datastream**-Seite als den später vom Slider-Widget oder Code geänderten Wert. Setzen Sie den DATENTYP auf **Integer** und MIN und MAX auf **0** und **30**.

    .. image:: img/sp220610_104330.png

#. Erstellen Sie auch einen weiteren **Datastream** des Typs **Virtual Pin**, um den Musiknamen anzuzeigen, und setzen Sie den DATENTYP auf ``String``.

    .. image:: img/sp220610_105932.png

#. Gehen Sie zur **Wed Dashboard**-Seite, ziehen Sie ein **Switch**-Widget und setzen Sie **Datastream** auf V0 (V0 ist bereits in :ref:`iot_blink` gesetzt); ziehen Sie ein **Label**-Widget und setzen Sie es auf V3; ziehen Sie ein **Slider**-Widget und setzen Sie es auf V2.

    .. image:: img/sp220610_110105.png

.. note::

    Ihre virtuellen Pins könnten sich von meinen unterscheiden, Ihre gelten. Sie müssen jedoch die entsprechende Pinnummer im Code ändern.

**3. Den Code ausführen**

#. Öffnen Sie die Datei ``4.cloud_music_player.ino`` unter dem Pfad ``3in1-kit\iot_project\4.cloud_music_player``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/34a49c4b-9eb4-4d03-bd78-fe1daefc9f5c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Ersetzen Sie die ``Template ID``, den ``Device Name`` und den ``Auth Token`` durch Ihre eigenen Daten. Sie müssen auch die ``ssid`` und das ``password`` Ihres verwendeten WLANs eingeben. Für detaillierte Anleitungen verweisen wir auf :ref:`connect_blynk`.
#. Nachdem Sie das richtige Board und den Port ausgewählt haben, klicken Sie auf den **Upoad**-Button.

#. Öffnen Sie den Seriellen Monitor (Baudrate auf 115200 einstellen) und warten Sie auf eine Meldung wie eine erfolgreiche Verbindung.

    .. image:: img/2_ready.png

    .. note::

        Wenn die Nachricht ``ESP reagiert nicht`` beim Verbinden erscheint, folgen Sie bitte diesen Schritten.

        * Stellen Sie sicher, dass die 9V-Batterie angeschlossen ist.
        * Setzen Sie das ESP8266-Modul zurück, indem Sie den Pin RST für 1 Sekunde mit GND verbinden und dann trennen.
        * Drücken Sie den Reset-Button auf dem R3-Board.

        Manchmal müssen Sie den obigen Vorgang 3-5 Mal wiederholen, bitte haben Sie Geduld.

#. Nun können Sie mit Blynks Button-Steuerwidget die Musik starten/anhalten und mit dem Schieberegler den Wiedergabefortschritt anpassen, und Sie sehen auch den Namen des Musikstücks.

    .. image:: img/sp220610_110105.png

#. Wenn Sie Blynk auf mobilen Geräten nutzen möchten, verweisen wir auf :ref:`blynk_mobile`.

**Wie funktioniert es?**

Der Datenstrom **V0** wird verwendet, um den Status des Switch-Widgets zu erhalten und der Variablen **musicPlayFlag** zuzuweisen, die das Pausieren und Abspielen der Musik steuert.

.. code-block:: arduino

    int musicPlayFlag=0;

    BLYNK_WRITE(V0)
    {
        musicPlayFlag = param.asInt(); // MUSIK STARTEN/PAUSIEREN
    }

Der Datenstrom **V2** wird verwendet, um den Wert des Schieberegler-Widgets zu erhalten und ihn der Variablen **scrubBar** zuzuweisen, wenn der Schieberegler verschoben wird.

.. code-block:: arduino

    int scrubBar=0;

    BLYNK_WRITE(V2)
    {
        scrubBar=param.asInt();
    }

Wenn das Gerät mit dem **Blynk Cloud** verbunden ist, schreiben Sie den Musiknamen für den **V3** Datenstrom und zeigen Sie ihn dann mit dem **Label**-Widget an.

.. code-block:: arduino

    BLYNK_CONNECTED() {
        String songName = "Ode an die Freude";
        Blynk.virtualWrite(V3, songName);
    }

Der **Blynk Timer** wird jede Sekunde ausgeführt. Die Musik wird abgespielt, wenn **musicPlayFlag** nicht 0 ist, d.h. das **Switch**-Widget ist EIN.
Sobald zwei Noten gespielt werden, wird die Fortschrittsbalkenvariable ``scrubBar`` um 2 erhöht, und der Wert wird dann an die **Blynk Cloud** geschrieben, die den Wert des **Slider**-Widgets synchronisiert.


.. code-block:: arduino

    void myTimerEvent()
    {
        if(musicPlayFlag!=0)
        {
            tone(buzzerPin,melody[scrubBar],250);
            scrubBar=(scrubBar+1)%(sizeof(melody)/sizeof(int));
            delay(500);
            tone(buzzerPin,melody[scrubBar],250);
            scrubBar=(scrubBar+1)%(sizeof(melody)/sizeof(int));
            Serial.println(scrubBar);    
            Blynk.virtualWrite(V2, scrubBar);
        }
    }