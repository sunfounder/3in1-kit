.. _iot_music:

4. Lecteur de Musique Cloud
=====================================

L'objectif de ce projet est de créer un lecteur de musique en utilisant Blynk.
La musique est jouée de la même manière que dans :ref:`ar_passive_buzzer`, en écrivant la chanson dans le programme et en la jouant avec un buzzer passif.
Cependant, dans cet exemple, nous pouvons cliquer sur l'interrupteur pour jouer/mettre en pause et faire glisser le curseur pour changer le progrès de la lecture.

**Composants Requis**

Pour ce projet, nous avons besoin des composants suivants.

Il est certainement pratique d'acheter un kit complet, voici le lien :

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nom	
        - ÉLÉMENTS DANS CE KIT
        - LIEN
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

Vous pouvez également les acheter séparément via les liens ci-dessous.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUCTION DES COMPOSANTS
        - LIEN D'ACHAT

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

**1. Construire le Circuit**

.. note::

    Le module ESP8266 nécessite un courant élevé pour fournir un environnement de fonctionnement stable, donc assurez-vous que la batterie 9V est branchée.

.. image:: img/wiring_buzzer.jpg

**2. Éditer le Tableau de Bord**

#. Créez un **Datastream** de type **Virtual Pin** sur la page **Datastream** comme la valeur modifiée par le widget Curseur ajouté plus tard ou le code. Réglez le TYPE DE DONNÉES sur **Integer** et MIN et MAX sur **0** et **30**.

    .. image:: img/sp220610_104330.png

#. Créez également un autre **Datastream** de type **Virtual Pin** pour afficher le nom de la musique, et réglez le TYPE DE DONNÉES sur ``String``.

    .. image:: img/sp220610_105932.png

#. Allez sur la page **Wed Dashboard**, faites glisser un widget **Switch** et réglez **Datastream** sur V0 (V0 est déjà réglé dans :ref:`iot_blink`); faites glisser un widget **Label** et réglez-le sur V3; faites glisser un widget **Slider** et réglez-le sur V2.

    .. image:: img/sp220610_110105.png

.. note::

    Vos pins virtuels peuvent être différents des miens, les vôtres prévaudront, mais vous devrez modifier le numéro de pin correspondant dans le code.

**3. Exécutez le Code**

#. Ouvrez le fichier ``4.cloud_music_player.ino`` situé dans le dossier ``3in1-kit\iot_project\4.cloud_music_player``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/34a49c4b-9eb4-4d03-bd78-fe1daefc9f5c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Remplacez le ``Template ID``, ``Device Name`` et ``Auth Token`` par les vôtres. Vous devez également entrer le ``ssid`` et le ``password`` du WiFi que vous utilisez. Pour des tutoriels détaillés, veuillez vous référer à :ref:`connect_blynk`.
#. Après avoir sélectionné la bonne carte et le bon port, cliquez sur le bouton **Upoad**.

#. Ouvrez le moniteur série (réglez le débit en bauds sur 115200) et attendez qu'un message tel qu'une connexion réussie apparaisse.


    .. image:: img/2_ready.png

    .. note::

        Si le message ``ESP is not responding`` apparaît lorsque vous vous connectez, veuillez suivre ces étapes.

        * Assurez-vous que la batterie 9V est branchée.
        * Réinitialisez le module ESP8266 en connectant la broche RST à GND pendant 1 seconde, puis débranchez-la.
        * Appuyez sur le bouton de réinitialisation de la carte R3.

        Parfois, il peut être nécessaire de répéter l'opération ci-dessus 3 à 5 fois, veuillez être patient.

#. Maintenant, vous pouvez utiliser le widget Bouton de Contrôle de Blynk pour démarrer/mettre en pause la musique et le Curseur pour ajuster le progrès de la lecture, et vous verrez également le nom de la musique.

    .. image:: img/sp220610_110105.png

#. Si vous souhaitez utiliser Blynk sur des appareils mobiles, veuillez vous référer à :ref:`blynk_mobile`.


**Comment ça fonctionne ?**

 Le datastream **V0** est utilisé pour obtenir l'état du widget Interrupteur et l'assigner à la variable **musicPlayFlag**, qui contrôle la pause et la lecture de la musique.

.. code-block:: arduino

    int musicPlayFlag=0;

    BLYNK_WRITE(V0)
    {
        musicPlayFlag = param.asInt(); // START/PAUSE MUSIC
    }

Le datastream **V2** est utilisé pour obtenir la valeur du widget Curseur et l'assigner à la variable **scrubBar** lorsque le curseur est déplacé.

.. code-block:: arduino

    int scrubBar=0;

    BLYNK_WRITE(V2)
    {
        scrubBar=param.asInt();
    }

Lorsque le dispositif est connecté au **Blynk Cloud**, écrivez le nom de la musique pour le datastream **V3** puis affichez-le avec le widget **Label**.

.. code-block:: arduino

    BLYNK_CONNECTED() {
        String songName = "Ode to Joy";
        Blynk.virtualWrite(V3, songName);
    }

**Blynk Timer** s'exécutera toutes les secondes. La musique est jouée si **musicPlayFlag** n'est pas 0, c'est-à-dire que le widget **Switch** est ON.
Dès que deux notes sont jouées, la variable de la barre de progression ``scrubBar`` est incrémentée de 2, et la valeur est ensuite écrite dans le **Blynk Cloud**, ce qui synchronise la valeur du widget **Slider**.

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