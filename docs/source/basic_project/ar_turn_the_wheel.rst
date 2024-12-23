.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Explorez en profondeur Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Assistance d'experts** : Résolvez les problèmes après-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits.
    - **Réductions spéciales** : Profitez de remises exclusives sur nos derniers produits.
    - **Promotions et concours festifs** : Participez à des concours et des promotions spéciales.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _ar_motor:

1.3 Faites tourner la roue
=============================

Un moteur est un dispositif de sortie numérique typique, et il est utilisé de la même manière qu'une LED.
Cependant, le moteur nécessite un courant élevé pour fonctionner, 
et ce courant élevé pourrait endommager la carte principale, comme la carte R4.
C'est pourquoi un module de commande moteur est utilisé dans ce cas, 
offrant une solution fiable pour que la carte R4 contrôle le moteur en toute sécurité.

.. **Schéma**

.. .. image:: img/circuit_1.3_wheel.png

.. IN1~IN4 sont les entrées du module L298N, et OUT1~OUT4 en sont les sorties.

.. Une méthode simple consiste à entrer un niveau haut pour INx, OUTx produira un niveau haut ; entrez un niveau bas pour INx, OUTx produira un niveau bas.
.. En connectant les deux extrémités du moteur à OUT1 et OUT2, en entrant des signaux de niveau opposés pour IN1 et IN2, le moteur commencera à tourner. OUT3 et OUT4 peuvent être utilisés de la même manière.

**Composants requis**

Pour ce projet, nous avons besoin des composants suivants :

Il est très pratique d’acheter un kit complet. Voici le lien :

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nom
        - ÉLÉMENTS DANS CE KIT
        - LIEN
    *   - Kit de démarrage 3 en 1
        - 380+
        - |link_3IN1_kit|

Vous pouvez également les acheter séparément via les liens ci-dessous.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUCTION AUX COMPOSANTS
        - LIEN D'ACHAT
    *   - :ref:`cpn_uno`
        - \-
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_tt_motor`
        - \-
    *   - :ref:`cpn_l9110`
        - \-

**Schéma**

.. image:: img/circuit_1.3_wheel_l9110.png

**Câblage**

.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - L9110S
      - Carte R4
      - Moteur
    * - VCC
      - 5V
      - 
    * - GND
      - GND
      - 
    * - B-1B(B-2A)
      - 9
      -
    * - B-1A
      - 10
      - 
    * - OA
      - 
      - un fil du moteur
    * - OB
      - 
      - un fil du moteur

.. image:: img/1.3_turn_the_wheel_bb.png
    :width: 800
    :align: center

**Code**

.. note::

   * Vous pouvez ouvrir le fichier ``1.3.turn_the_wheel.ino`` dans le chemin ``3in1-kit\learning_project\1.3.turn_the_wheel``. 
   * Ou copiez ce code dans **Arduino IDE**.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/5f8e4f33-883b-4c06-9516-f1754ea2121d/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
