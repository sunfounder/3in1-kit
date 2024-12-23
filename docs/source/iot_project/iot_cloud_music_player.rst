.. note:: 

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour perfectionner vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus exclusifs.
    - **Réductions spéciales** : Profitez de remises exclusives sur nos nouveaux produits.
    - **Promotions festives et cadeaux** : Participez à des promotions et des concours pendant les fêtes.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _iot_music:

4. Lecteur de musique en ligne
=====================================

Le but de ce projet est de créer un lecteur de musique en utilisant Blynk.
La musique est jouée de la même manière que dans :ref:`ar_passive_buzzer`, en écrivant la chanson dans le programme et en la jouant avec un buzzer passif. 
Cependant, dans cet exemple, nous pouvons cliquer sur un interrupteur pour jouer/mettre en pause et déplacer un curseur pour modifier la progression de la lecture.

**Composants requis**

Pour ce projet, nous avons besoin des composants suivants. 

Il est bien sûr pratique d'acheter un kit complet. Voici le lien : 

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nom	
        - ÉLÉMENTS DANS CE KIT
        - LIEN
    *   - Kit de démarrage 3 en 1
        - 380+
        - |link_3IN1_kit|

Vous pouvez également les acheter séparément à partir des liens ci-dessous.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUCTION DES COMPOSANTS
        - LIEN D'ACHAT

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

**1. Construire le circuit**

.. note::

    Le module ESP8266 nécessite un courant élevé pour assurer un environnement de fonctionnement stable. Assurez-vous que la batterie 9V est connectée.

.. image:: img/iot_4_bb.png
    :width: 600
    :align: center

**2. Modifier le tableau de bord**

#. Créez un **Datastream** de type **Virtual Pin** sur la page **Datastream** comme valeur modifiée par le widget curseur ajouté ou par le code. Réglez le TYPE DE DONNÉES sur **Integer** et les valeurs MIN et MAX sur **0** et **30**.

    .. image:: img/sp220610_104330.png

#. Créez également un autre **Datastream** de type **Virtual Pin** pour afficher le nom de la musique, et définissez le TYPE DE DONNÉES sur ``String``.

    .. image:: img/sp220610_105932.png

#. Accédez à la page **Web Dashboard**, faites glisser un widget **Switch** et définissez **Datastream** sur V0 (V0 est déjà configuré dans :ref:`iot_blink`), faites glisser un widget **Label** et définissez-le sur V3, puis faites glisser un widget **Slider** et définissez-le sur V2.

    .. image:: img/blynk_music_cloud.png

.. note::

    Vos broches virtuelles peuvent être différentes des miennes. Vous devrez ajuster les numéros de broches correspondants dans le code.



**3. Exécuter le code**

#. Ouvrez le fichier ``4.cloud_music_player.ino`` situé dans ``3in1-kit\iot_project\4.cloud_music_player``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/34a49c4b-9eb4-4d03-bd78-fe1daefc9f5c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Remplacez les valeurs ``Template ID``, ``Device Name``, et ``Auth Token`` par vos informations personnelles. Entrez également le ``ssid`` et le ``password`` de votre réseau WiFi. Pour des tutoriels détaillés, reportez-vous à :ref:`connect_blynk`.
#. Après avoir sélectionné la carte et le port appropriés, cliquez sur le bouton **Téléverser**.

#. Ouvrez le Moniteur Série (réglez le débit en bauds à 115200) et attendez qu'un message de connexion réussie apparaisse.

    .. image:: img/2_ready.png

    .. note::

        Si le message ``ESP is not responding`` s'affiche lors de la connexion, suivez ces étapes.

        * Assurez-vous que la batterie 9V est branchée.
        * Réinitialisez le module ESP8266 en connectant la broche RST à GND pendant 1 seconde, puis débranchez-la.
        * Appuyez sur le bouton de réinitialisation sur la carte R4.

        Vous devrez peut-être répéter ces étapes 3 à 5 fois. Soyez patient.

#. Vous pouvez maintenant utiliser le widget de contrôle Bouton de Blynk pour démarrer/mettre en pause la musique et le curseur pour ajuster la progression de la lecture. Le nom de la musique s'affichera également.

    .. image:: img/blynk_music_cloud.png

#. Si vous souhaitez utiliser Blynk sur des appareils mobiles, reportez-vous à :ref:`blynk_mobile`.


**Comment cela fonctionne-t-il ?**

Le datastream **V0** est utilisé pour obtenir l'état du widget Switch et l'assigner à la variable **musicPlayFlag**, qui contrôle la pause et la lecture de la musique.

.. code-block:: arduino

    int musicPlayFlag=0;

    BLYNK_WRITE(V0)
    {
        musicPlayFlag = param.asInt(); // DÉMARRER/PAUSE MUSIQUE
    }

Le datastream **V2** est utilisé pour obtenir la valeur du widget curseur et l'assigner à la variable **scrubBar** lorsque le curseur est déplacé.

.. code-block:: arduino

    int scrubBar=0;

    BLYNK_WRITE(V2)
    {
        scrubBar=param.asInt();
    }

Lorsque l'appareil est connecté au **Blynk Cloud**, écrivez le nom de la musique dans le datastream **V3** et affichez-le à l'aide du widget **Label**.

.. code-block:: arduino

    BLYNK_CONNECTED() {
        String songName = "Ode to Joy";
        Blynk.virtualWrite(V3, songName);
    }

Le **Blynk Timer** s'exécutera chaque seconde. La musique est jouée si **musicPlayFlag** n'est pas égal à 0, c'est-à-dire si le widget **Switch** est activé.
Après que deux notes ont été jouées, la variable de la barre de progression ``scrubBar`` est incrémentée de 2, et la valeur est ensuite écrite dans le **Blynk Cloud**, qui synchronise la valeur du widget **Slider**.

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