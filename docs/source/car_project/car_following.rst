.. note::

    Bonjour et bienvenue dans la Communauté Facebook des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez [|link_sf_facebook|] et rejoignez-nous aujourd'hui !

.. _follow_your_hand:

7. Suivez Votre Main
=========================

Considérez cette voiture comme votre animal de compagnie ici, et lorsqu'elle vous verra lui faire signe, elle viendra en courant vers vous.

**Composants requis**

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
    *   - :ref:`cpn_l9110`
        - \-
    *   - :ref:`cpn_tt_motor`
        - \-
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|
    *   - :ref:`cpn_avoid`
        - |link_obstacle_avoidance_buy|

**Câblage**

Connectez le module ultrasonique et les 2 modules d'évitement d'obstacles IR en même temps.

Connectez l'ultrasonique à la carte R3 comme suit.

.. list-table:: 
    :header-rows: 1

    * - Module ultrasonique
      - Carte R3
    * - Vcc
      - 5V
    * - Trig
      - 3
    * - Echo
      - 4
    * - Gnd
      - GND

Le câblage des 2 modules d'évitement d'obstacles IR à la carte R3 est le suivant.

.. list-table:: 
    :header-rows: 1

    * - Left IR Module
      - R3 Board
    * - OUT
      - 8
    * - GND
      - GND
    * - VCC
      - 5V

.. list-table:: 
    :header-rows: 1

    * - Right IR Module
      - R3 Board
    * - OUT
      - 7
    * - GND
      - GND
    * - VCC
      - 5V

.. image:: img/car_7_8.png
    :width: 800

**Code**

.. note::

    * Ouvrez le fichier ``7.follow_your_hand.ino`` situé dans le dossier ``3in1-kit\car_project\7.follow_your_hand``.
    * Ou copiez ce code dans **Arduino IDE**.
    
    * Ou téléchargez le code via `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/584e42c8-8842-4db0-93b5-f6f949b6ffca/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Placez la voiture sur le sol après le téléchargement réussi du code. Placez votre main à environ 5*10cm devant la voiture, et elle suivra votre main vers l'avant. Si vous placez votre main près du module d'obstacle IR de chaque côté, elle tournera également dans la direction correspondante.

**Comment ça fonctionne ?**

Ce projet est une combinaison des deux projets précédents :ref:`car_ultrasonic` et :ref:`car_ir_obstacle`, mais l'effet implémenté est différent. Les 2 projets précédents détectent un obstacle en arrière, mais ici, il détecte que votre main suivra la direction avant ou tournera.
Le déroulement de ce projet est le suivant.

* Lisez la distance détectée par le module ultrasonique et la valeur des deux modules infrarouges.
* Si la distance est de 5~10cm, laissez la voiture se déplacer avec votre main.
* Si le module IR gauche détecte votre main, tournez à gauche.
* Si le module IR droit détecte votre main, tournez à droite.
* Si ni le module infrarouge ni le module ultrasonique ne détectent votre main, laissez la voiture s'arrêter.

.. code-block:: arduino

    void loop() {

        float distance = readSensorData();

        int left = digitalRead(leftIR);   // 0: Obstructed  1: Empty
        int right = digitalRead(rightIR);
        int speed = 150;

        if (distance>5 && distance<10){
            moveForward(speed);
        }
        if(!left&&right){
            turnLeft(speed);
        }else if(left&&!right){
            turnRight(speed);
        }else{
            stopMove();
        }
    }