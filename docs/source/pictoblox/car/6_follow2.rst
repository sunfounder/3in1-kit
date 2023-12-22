.. _sh_follow2:

3.6 Suivez Votre Main 2
==============================

Dans le projet :ref:`sh_follow1`, seul le module ultrasonique est utilisé, il ne peut que suivre votre main vers l'avant.

Dans ce projet, nous utilisons 2 modules d'évitement d'obstacles IR en même temps, afin que la voiture puisse suivre votre main à gauche ou à droite.

Composants requis
---------------------

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

Construire le Circuit
-----------------------

Connectez le module ultrasonique et les deux modules d'évitement d'obstacles IR en même temps.

Le câblage entre l'ultrasonique et la carte R3 est le suivant.

.. list-table:: 

    * - Module Ultrasonique
      - Carte R3
    * - Vcc
      - 5V
    * - Trig
      - 3
    * - Echo
      - 4
    * - Gnd
      - GND

Le câblage des 2 modules d'évitement d'obstacles IR vers la carte R3 est le suivant.

.. list-table:: 

    * - Module IR Gauche
      - Carte R3
    * - OUT
      - 8
    * - GND
      - GND
    * - VCC
      - 5V

.. list-table:: 

    * - Module IR Droit
      - Carte R3
    * - OUT
      - 7
    * - GND
      - GND
    * - VCC
      - 5V

.. image:: img/car_7_8.png
    :width: 800

Programmation
---------------

L'effet à atteindre par ce projet est le suivant

* L'ultrason détecte votre main à environ 5-10 cm devant et laisse la voiture suivre.
* Le module infrarouge à gauche détecte votre main et tourne à gauche.
* Le module IR droit détecte votre main et tourne à droite.

**1. Créer un bloc**

Créez des blocs qui permettent à la voiture d'avancer, de tourner à gauche, de tourner à droite et de s'arrêter.

.. image:: img/6_follow2_1.png

**2. Suivre pour avancer**

Lisez la valeur de l'ultrasonique et si votre main est détectée à une distance de 5-10 cm, laissez la voiture suivre.

.. image:: img/6_follow2_2.png

**3. Suivre pour tourner à gauche et à droite**

Lisez les valeurs des modules IR gauche et droit.

* Si le module IR gauche détecte votre main, tournez à gauche.
* Si le module IR droit détecte votre main, tournez à droite.
* Si aucun des modules IR et ultrasonique ne détecte votre main, faites s'arrêter la voiture.

.. image:: img/6_follow2_3.png
