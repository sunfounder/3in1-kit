.. note:: 

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions spéciales.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _follow_your_hand:

7. Suivez Votre Main
========================

Considérez cette voiture comme votre animal de compagnie : lorsque vous lui faites signe, elle vient vers vous.

**Composants Requis**

Dans ce projet, nous avons besoin des composants suivants :

Il est certainement pratique d'acheter un kit complet, voici le lien :

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nom	
        - ARTICLES DANS CE KIT
        - LIEN
    *   - Kit de démarrage 3 en 1
        - 380+
        - |link_3IN1_kit|

Vous pouvez également les acheter séparément via les liens ci-dessous.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUCTION DU COMPOSANT
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

Connectez simultanément le module ultrasonique et les 2 modules infrarouges d'évitement d'obstacles.

Câblez le module ultrasonique à la carte R4 comme suit :

.. list-table:: 
    :header-rows: 1

    * - Module Ultrasonique
      - Carte R4
    * - Vcc
      - 5V
    * - Trig
      - 3
    * - Echo
      - 4
    * - Gnd
      - GND

Le câblage des 2 modules infrarouges à la carte R4 est le suivant :

.. list-table:: 
    :header-rows: 1

    * - Module IR Gauche
      - Carte R4
    * - OUT
      - 8
    * - GND
      - GND
    * - VCC
      - 5V

.. list-table:: 
    :header-rows: 1

    * - Module IR Droit
      - Carte R4
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

    * Ouvrez le fichier ``7.follow_your_hand.ino`` sous le chemin ``3in1-kit\car_project\7.follow_your_hand``.
    * Ou copiez ce code dans **Arduino IDE**.
    
    * Ou téléversez le code via l'`Éditeur Web Arduino <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/584e42c8-8842-4db0-93b5-f6f949b6ffca/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Placez la voiture sur le sol après avoir téléversé le code avec succès. Approchez votre main à une distance de 5 à 10 cm devant la voiture, et elle suivra votre main en avant. Si vous placez votre main près du module infrarouge sur l'un des côtés, la voiture tournera dans la direction correspondante.

**Comment ça marche ?**

Ce projet combine les deux projets précédents :ref:`car_ultrasonic` et :ref:`car_ir_obstacle`, mais l'effet implémenté est différent. Les deux projets précédents détectaient un obstacle pour reculer, tandis qu'ici, la détection de votre main permet à la voiture de suivre en avant ou de tourner.

Le flux de travail de ce projet est le suivant :

* Lire la distance détectée par le module ultrasonique et les valeurs des deux modules infrarouges.
* Si la distance est de 5 à 10 cm, la voiture se déplace avec votre main.
* Si le module IR gauche détecte votre main, tourner à gauche.
* Si le module IR droit détecte votre main, tourner à droite.
* Si aucun des modules infrarouges ni le module ultrasonique ne détectent votre main, la voiture s'arrête.

.. code-block:: arduino

    void loop() {

        float distance = readSensorData();

        int left = digitalRead(leftIR);   // 0 : Obstrué  1 : Libre
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