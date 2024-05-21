.. note::

    Bonjour et bienvenue dans la Communauté Facebook des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez [|link_sf_facebook|] et rejoignez-nous aujourd'hui !

.. _ar_potentiometer:

4.1 Tournez le Bouton
========================

Le potentiomètre est un composant résistif à 3 bornes dont la valeur de résistance peut être ajustée selon une variation régulière.

**Composants requis**

Pour ce projet, nous avons besoin des composants suivants.

Il est certainement pratique d'acheter un kit complet, voici le lien :

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nom	
        - ÉLÉMENTS DE CE KIT
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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_potentiometer`
        - |link_potentiometer_buy|


**Schéma**

.. image:: img/circuit_5.1_potentiometer.png

Dans cet exemple, nous utilisons la broche analogique (A0) pour lire la valeur du potentiomètre. En tournant l'axe du potentiomètre, vous pouvez changer la répartition de la résistance entre ces trois broches, modifiant ainsi la tension sur la broche du milieu. Lorsque la résistance entre la broche du milieu et une broche extérieure connectée à 5V est proche de zéro (et la résistance entre la broche du milieu et l'autre broche extérieure est proche de 10kΩ), la tension à la broche du milieu est proche de 5V. L'opération inverse (la résistance entre la broche du milieu et une broche extérieure connectée à 5V est proche de 10kΩ) rendra la tension à la broche du milieu proche de 0V.


**Câblage**

.. image:: img/turn_thek_knob_bb.jpg
    :width: 600
    :align: center

**Code**


.. note::

   * Vous pouvez ouvrir le fichier ``4.1.turn_the_knob.ino`` dans le chemin ``3in1-kit\basic_project\4.1.turn_the_knob``. 
   * Ou copiez ce code dans **Arduino IDE**.
   
   * Ou téléchargez le code via l'`Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/d931f2c9-74bc-4a53-8531-39a21a07dbaf/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
    
Après avoir téléchargé les codes sur la carte, vous pouvez ouvrir le moniteur série pour voir la valeur lue de la broche. En tournant l'axe du potentiomètre, le moniteur série affichera la valeur 「0」~「1023」. 
