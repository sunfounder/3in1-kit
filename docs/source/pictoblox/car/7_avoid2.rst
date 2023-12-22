.. _sh_avoid2:

3.7 Évitement d'obstacles 2
==================================

Dans le projet :ref:`sh_avoid1`, seuls 2 modules d'évitement d'obstacles IR sont utilisés pour éviter les obstacles, mais la distance de détection du module d'évitement d'obstacles IR est courte, ce qui peut rendre la voiture trop tardive pour éviter les obstacles.

Dans ce projet, nous ajoutons également un module ultrasonique pour effectuer une détection à longue distance, afin que la voiture puisse détecter les obstacles à une plus grande distance pour prendre une décision.

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

Connectez le module ultrasonique et les 2 modules d'évitement d'obstacles IR en même temps.

Câblez l'ultrasonique à la carte R3 comme suit.

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

**1. Créer une fonction**

Faites avancer et reculer la voiture.

.. image:: img/7_avoid2_1.png

Faites reculer la voiture vers la gauche et vers la droite.

.. image:: img/7_avoid2_2.png

Faites s'arrêter la voiture.

.. image:: img/7_avoid2_3.png

**2. Évitement d'obstacles d'urgence**

Les 2 modules d'évitement d'obstacles infrarouges sur la voiture sont utilisés pour un évitement d'obstacles d'urgence, détectant les obstacles à courte distance, dans les coins ou les obstacles relativement petits.

* Si le module infrarouge gauche détecte un obstacle, la voiture recule vers la gauche.
* Si le module IR droit détecte un obstacle, la voiture recule vers l'arrière droit.
* Si les 2 modules détectent l'obstacle en même temps, la voiture recule directement.

.. image:: img/7_avoid2_4.png

**3. Évitement d'obstacles à longue portée**

Lisez la valeur du module ultrasonique, lorsque la valeur détectée est inférieure à 10, la voiture recule ; sinon elle continue d'avancer.

.. image:: img/7_avoid2_5.png
