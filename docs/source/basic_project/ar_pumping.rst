.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et à des promotions festives.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _ar_pump:

1.4 Pompage
==================

La pompe à eau est également un moteur, qui convertit l'énergie mécanique du moteur ou une autre source d'énergie externe, via une structure spéciale, pour transporter un liquide.

.. **Schéma**

.. .. image:: img/circuit_1.3_wheel.png

.. IN1~IN4 sont les entrées du module L298N, et OUT1~OUT4 sont les sorties.

.. Une utilisation simple consiste à fournir un signal haut à INx, ce qui fait que OUTx produit un signal haut ; fournir un signal bas à INx fait que OUTx produit un signal bas.
.. En connectant les deux bornes du moteur à OUT1 et OUT2, et en envoyant des signaux opposés à IN1 et IN2, le moteur tourne. OUT3 et OUT4 peuvent être utilisés de la même manière.

**Composants nécessaires**

Dans ce projet, nous avons besoin des composants suivants :

C'est pratique d'acheter un kit complet, voici le lien :

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

    *   - INTRODUCTION DES COMPOSANTS
        - LIEN D'ACHAT

    *   - :ref:`cpn_uno`
        - \-
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_l9110`
        - \-
    *   - :ref:`cpn_pump`
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
      
.. image:: img/1.4_pumping_bb.png
    :width: 800
    :align: center

**Code**

.. note::

   * Ouvrez le fichier ``1.4.pumping.ino`` dans le répertoire ``3in1-kit\learning_project\1.4.pumping``. 
   * Ou copiez ce code dans l'IDE Arduino.
   
.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/f829508f-2475-4de6-bc2f-ab0a68d707b1/preview?F=undefined?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Ajoutez le tuyau à la pompe et placez-la dans le bassin. Après avoir téléchargé le code avec succès, vous verrez que l'eau du bassin est évacuée après un certain temps.
Lors de cet exercice, veillez à garder le circuit éloigné de l'eau pour éviter tout court-circuit !
