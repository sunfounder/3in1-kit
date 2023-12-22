.. _self_driving:

8. Voiture Autonome
=========================

Ce projet est une combinaison des deux projets :ref:`car_ultrasonic` et :ref:`car_ir_obstacle`. 
2 modules infrarouges d'évitement d'obstacles effectuent une détection à courte distance ou de bord, 
et les modules ultrasoniques effectuent une détection à longue distance pour confirmer que la voiture ne heurte pas d'obstacle pendant le processus de conduite libre.

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

    * Ouvrez le fichier ``8.self_driving_car.ino`` situé dans le dossier ``3in1-kit\car_project\8.self_driving_car``.
    * Ou copiez ce code dans **Arduino IDE**.
    
    * Ou téléchargez le code via `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/0a74a7b1-ead6-4bea-ab5a-4da71f27f82f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Une fois le code téléchargé avec succès, la voiture se déplacera librement. Lorsque le module d'obstruction IR des deux côtés détecte un obstacle, elle se déplacera dans la direction opposée pour une évasion d'urgence ; si un obstacle se trouve à 2~10cm directement devant la voiture, elle reculera vers la gauche, ajustera sa direction, puis avancera.


**Comment ça fonctionne ?**

Le déroulement de ce projet est le suivant.

* Lisez d'abord la valeur du module d'évitement d'obstacles IR gauche et droit.
* Si le module IR gauche est à 0 (obstacle détecté), le module IR droit est à 1, laissez la voiture reculer à gauche.
* Si le module IR droit est à 0 (obstacle détecté), laissez la voiture reculer à droite.
* Si les 2 modules IR détectent l'obstacle en même temps, la voiture reculera.
* Sinon, lisez la distance détectée par le module ultrasonique.
* Si la distance est supérieure à 50cm, laissez la voiture avancer.
* Si la distance est entre 2-10cm, laissez la voiture reculer avant de tourner.
* Si la distance est entre 10-50cm, laissez la voiture avancer à faible vitesse.

.. code-block:: arduino

    void loop() {

        int left = digitalRead(leftIR);   // 0: Obstructed  1: Empty
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
            if (distance > 50) { // Safe
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

