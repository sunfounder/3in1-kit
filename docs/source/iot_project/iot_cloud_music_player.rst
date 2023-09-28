.. _iot_music:

4. Cloud-Musikspieler
=====================================

Das Ziel dieses Projekts ist es, einen Musikspieler mit Blynk zu erstellen.
Die Musik wird auf dieselbe Weise wie in :ref:`ar_passive_buzzer` abgespielt, indem das Lied im Programm geschrieben und mit einem passiven Summer abgespielt wird.
In diesem Beispiel können wir jedoch den Schalter klicken, um die Wiedergabe zu starten/anhalten und den Schieberegler verschieben, um den Wiedergabefortschritt zu ändern.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist definitiv praktisch, ein ganzes Kit zu kaufen, hier ist der Link:

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
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_esp8266`
        - |link_esp8266_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_buzzer`
        - |link_passive_buzzer_buy|

**1. Schaltkreis aufbauen**

.. note::

    Das ESP8266-Modul erfordert einen hohen Strom, um eine stabile Betriebsumgebung zu gewährleisten. Stellen Sie daher sicher, dass die 9V-Batterie angeschlossen ist.

.. image:: img/iot_4_bb.png

**2. Dashboard bearbeiten**

#. Erstellen Sie einen **Datastream** vom Typ **Virtual Pin** auf der **Datastream**-Seite als den vom später hinzugefügten Slider-Widget oder Code geänderten Wert. Setzen Sie den DATENTYP auf **Integer** und MIN und MAX auf **0** und **30**.

    .. image:: img/sp220610_104330.png

#. Erstellen Sie auch einen anderen **Datastream** vom Typ **Virtual Pin**, um den Musiknamen anzuzeigen, und setzen Sie den DATENTYP auf ``String``.

    .. image:: img/sp220610_105932.png

#. Gehen Sie zur **Wed Dashboard**-Seite, ziehen Sie ein **Switch**-Widget und setzen Sie **Datastream** auf V0 (V0 ist bereits in :ref:`iot_blink` eingestellt); ziehen Sie ein **Label**-Widget und setzen Sie es auf V3; ziehen Sie ein **Slider**-Widget und setzen Sie es auf V2.

    .. image:: img/sp220610_110105.png

.. note::

    Ihre virtuellen Pins könnten sich von meinen unterscheiden, Ihre haben Vorrang, aber Sie müssen die entsprechende Pin-Nummer im Code ändern.




**3. Code ausführen**

#. Öffnen Sie die Datei ``4.cloud_music_player.ino`` unter dem Pfad ``3in1-kit\iot_project\4.cloud_music_player``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/34a49c4b-9eb4-4d03-bd78-fe1daefc9f5c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Ersetzen Sie die ``Template ID``, ``Device Name`` und ``Auth Token`` durch Ihre eigenen Angaben. Sie müssen auch die ``ssid`` und das ``password`` des von Ihnen verwendeten WLANs eingeben. Für detaillierte Anleitungen verweisen Sie bitte auf :ref:`connect_blynk`.
#. Wählen Sie das richtige Board und den Port aus und klicken Sie auf die **Upoad**-Taste.

#. Öffnen Sie den Seriellen Monitor (Baudrate auf 115200 einstellen) und warten Sie auf eine Meldung, wie eine erfolgreiche Verbindung.

    .. image:: img/2_ready.png

    .. note::

        Wenn die Meldung ``ESP is not responding`` beim Verbinden erscheint, befolgen Sie bitte diese Schritte.

        * Stellen Sie sicher, dass die 9V-Batterie angeschlossen ist.
        * Setzen Sie das ESP8266-Modul zurück, indem Sie den Pin RST 1 Sekunde lang auf GND legen und dann abziehen.
        * Drücken Sie die Reset-Taste auf dem R4-Board.

        Manchmal müssen Sie den obigen Vorgang 3-5 Mal wiederholen. Bitte haben Sie Geduld.

#. Nun können Sie Blynks Button Control Widget verwenden, um die Musik zu starten/pausieren und den Slider, um den Wiedergabefortschritt anzupassen. Sie sehen auch den Namen des Musikstücks.

    .. image:: img/sp220610_110105.png

#. Wenn Sie Blynk auf mobilen Geräten verwenden möchten, verweisen Sie bitte auf :ref:`blynk_mobile`.


**Wie funktioniert das?**

Der Datenstrom **V0** wird verwendet, um den Status des Switch-Widgets abzurufen und der Variable **musicPlayFlag** zuzuweisen, die das Pausieren und Abspielen der Musik steuert.

.. code-block:: arduino

    int musicPlayFlag=0;

    BLYNK_WRITE(V0)
    {
        musicPlayFlag = param.asInt(); // START/PAUSE MUSIC
    }

Der Datenstrom **V2** wird verwendet, um den Wert des Slider-Widgets abzurufen und ihn der Variable **scrubBar** zuzuweisen, wenn der Slider verschoben wird.

.. code-block:: arduino

    int scrubBar=0;

    BLYNK_WRITE(V2)
    {
        scrubBar=param.asInt();
    }

Wenn das Gerät mit der **Blynk Cloud** verbunden ist, schreiben Sie den Musiknamen für den Datenstrom **V3** und zeigen Sie ihn dann mit dem **Label**-Widget an.

.. code-block:: arduino

    BLYNK_CONNECTED() {
        String songName = "Ode to Joy";
        Blynk.virtualWrite(V3, songName);
    }

Der **Blynk Timer** wird jede Sekunde ausgeführt. Die Musik wird abgespielt, wenn **musicPlayFlag** nicht 0 ist, d.h. das **Switch**-Widget ist EIN.
Sobald zwei Noten gespielt werden, wird die Variable für die Fortschrittsleiste ``scrubBar`` um 2 erhöht, und der Wert wird dann in die **Blynk Cloud** geschrieben, die den Wert des **Slider**-Widgets synchronisiert.


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