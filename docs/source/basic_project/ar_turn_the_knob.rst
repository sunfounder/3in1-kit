.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Explorez en profondeur Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Assistance d'experts** : Résolvez les problèmes après-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits.
    - **Réductions spéciales** : Profitez de remises exclusives sur nos derniers produits.
    - **Promotions et concours festifs** : Participez à des concours et des promotions spéciales.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _ar_potentiometer:

4.1 Tournez le bouton
=========================

Le potentiomètre est un composant résistif à 3 terminaux dont la valeur de résistance peut être ajustée selon une variation régulière.

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_potentiometer`
        - |link_potentiometer_buy|

**Schéma**

.. image:: img/circuit_5.1_potentiometer.png

Dans cet exemple, nous utilisons la broche analogique (A0) pour lire la valeur du 
potentiomètre. En tournant l'axe du potentiomètre, vous pouvez modifier la répartition 
de la résistance entre ses trois bornes, ce qui change la tension sur la borne centrale. 
Lorsque la résistance entre la borne centrale et une borne extérieure connectée à 5V est 
proche de zéro (et que la résistance entre la borne centrale et l'autre borne extérieure 
est proche de 10 kΩ), la tension à la borne centrale est proche de 5V. L'opération inverse 
(la résistance entre la borne centrale et une borne extérieure connectée à 5V est proche 
de 10 kΩ) rendra la tension à la borne centrale proche de 0V.

**Câblage**

.. image:: img/4.1_turn_thek_knob_bb.png
    :width: 600
    :align: center

**Code**

.. note::

   * Vous pouvez ouvrir le fichier ``4.1.turn_the_knob.ino`` dans le chemin ``3in1-kit\learning_project\4.1.turn_the_knob``. 
   * Ou copiez ce code dans **Arduino IDE**.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/d931f2c9-74bc-4a53-8531-39a21a07dbaf/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Après avoir téléversé le code sur la carte, vous pouvez ouvrir le moniteur série pour voir 
la valeur lue par la broche. En tournant l'axe du potentiomètre, le moniteur série affichera 
une valeur comprise entre 「0」 et 「1023」.
