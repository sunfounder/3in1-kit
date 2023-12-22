.. _sh_follow1:

3.4 Suivez Votre Main
===========================

Pensez à cette voiture comme à votre animal de compagnie ici, et quand vous lui ferez signe, elle viendra en courant vers vous.

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

Construire le Circuit
-----------------------

Un module de capteur ultrasonique est un instrument qui mesure la distance jusqu'à un objet à l'aide d'ondes sonores ultrasoniques.
Il possède deux sondes. L'une envoie des ondes ultrasoniques et l'autre reçoit les ondes et transforme le temps d'envoi et de réception en une distance, détectant ainsi la distance entre l'appareil et un obstacle.

Construisez le circuit selon le schéma suivant.

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

.. image:: img/car_6.png
    :width: 800

Programmation
----------------

Créez des blocs pour faire avancer et arrêter la voiture.

.. image:: img/4_hand1.png

Mettez votre main devant la voiture, puis lisez la valeur du module ultrasonique, si la distance détectée de votre main est de 5-10 cm, alors faites avancer la voiture, sinon arrêtez.

.. image:: img/4_hand2.png
