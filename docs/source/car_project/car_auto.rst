.. note:: 

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions spéciales.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _self_driving:

8. Voiture Autonome
=======================

Ce projet est une combinaison des deux projets :ref:`car_ultrasonic` et :ref:`car_ir_obstacle`. 
Deux modules infrarouges d'évitement d'obstacles effectuent une détection à courte distance ou des 
bords, tandis que les modules ultrasoniques effectuent une détection à longue distance pour garantir que la voiture ne heurte aucun obstacle pendant son processus de conduite autonome.

**Composants requis**

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

Vous pouvez également les acheter séparément à partir des liens ci-dessous.

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

Câblez le module ultrasonique à la carte R4 comme suit.

.. list-table:: 
    :header-rows: 1

    * - Ultrasonic Module
      - R4 Board
    * - Vcc
      - 5V
    * - Trig
      - 3
    * - Echo
      - 4
    * - Gnd
      - GND

Le câblage des 2 modules infrarouges à la carte R4 est le suivant.

.. list-table:: 
    :header-rows: 1

    * - Left IR Module
      - R4 Board
    * - OUT
      - 8
    * - GND
      - GND
    * - VCC
      - 5V

.. list-table:: 
    :header-rows: 1

    * - Right IR Module
      - R4 Board
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

    * Ouvrez le fichier ``8.self_driving_car.ino`` sous le chemin ``3in1-kit\car_project\8.self_driving_car``.
    * Ou copiez ce code dans **Arduino IDE**.
    
    * Ou téléversez le code via l'`Éditeur Web Arduino <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/0a74a7b1-ead6-4bea-ab5a-4da71f27f82f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

La voiture roulera librement une fois le code téléversé avec succès. Lorsque le module IR d'obstruction des deux côtés détecte un obstacle, elle se déplacera dans la direction opposée pour une évitement d'urgence. Si un obstacle est détecté à une distance de 2 à 10 cm directement devant la voiture, elle reculera vers la gauche, ajustera sa direction, puis avancera.

**Comment ça marche ?**

Le flux de travail de ce projet est le suivant :

* Lire en priorité la valeur des modules IR gauche et droit.
* Si le module IR gauche est à 0 (obstacle détecté) et le droit à 1, la voiture recule vers la gauche.
* Si le module IR droit est à 0 (obstacle détecté), la voiture recule vers la droite.
* Si les 2 modules IR détectent un obstacle en même temps, la voiture recule.
* Sinon, lire la distance détectée par le module ultrasonique.
* Si la distance est supérieure à 50 cm, la voiture avance.
* Si la distance est comprise entre 2 et 10 cm, la voiture recule avant de tourner.
* Si la distance est comprise entre 10 et 50 cm, la voiture avance à basse vitesse.

.. code-block:: arduino

    void loop() {

        int left = digitalRead(leftIR);   // 0: Obstrué  1: Libre
        int right = digitalRead(rightIR);

        if (!left && right) {
            backLeft(150);
        } else if (left && !right) {
            backRight(150);
        } else if (!left && !right) {
            moveBackward(150);
        } else {
            float distance = readSensorData();
            Serial.println(distance);
            if (distance > 50) { // Sécurisé
                moveForward(200);
            } else if (distance < 10 && distance > 2) { // Attention
                moveBackward(200);
                delay(1000);
                backLeft(150);
                delay(500);
            } else {
                moveForward(150);
            }
        }
    }

