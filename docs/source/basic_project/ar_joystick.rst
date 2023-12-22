.. _ar_joystick:

4.3 Manipuler le Joystick
================================

Le joystick devrait être très familier à quiconque joue régulièrement à des jeux vidéo.
Il est généralement utilisé pour déplacer des personnages ou faire pivoter l'écran.

Nos mouvements peuvent être lus par le joystick, qui fonctionne sur un principe très simple.
Il se compose de deux potentiomètres perpendiculaires l'un à l'autre.
Ces deux potentiomètres mesurent la valeur analogique du joystick dans les directions verticale et horizontale, produisant une valeur (x,y) dans un système de coordonnées plan en angle droit.


Ce kit comprend également un joystick avec une entrée numérique. Il est activé lorsque le joystick est pressé.


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
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_joystick`
        - \-

**Schéma**

.. image:: img/circuit_5.3_joystick.png

.. note::
    La broche SW est connectée à une résistance de pull-up de 10K,
    la raison est de pouvoir obtenir un niveau haut stable sur la broche SW (axe Z) lorsque le joystick n'est pas pressé;
    sinon le SW est dans un état suspendu et la valeur de sortie peut varier entre 0/1.

**Câblage**

.. image:: img/toggle_the_joystick_bb.jpg
    :width: 800
    :align: center

**Code**

.. note::

    * Ouvrez le fichier ``4.3.toggle_the_joystick.ino`` sous le chemin ``3in1-kit\basic_project\4.3.toggle_the_joystick``.
    * Ou copiez ce code dans **Arduino IDE**.
    
    * Ou téléchargez le code via l'`Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/f678a03f-546c-42ed-bfae-b8c7daa5eec9/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Ouvrez le moniteur série après le téléchargement réussi du code pour voir les valeurs x,y,z du joystick.

* Les valeurs des axes x et y sont des valeurs analogiques variant de 0 à 1023.
* L'axe Z est une valeur numérique avec un état de 1 ou 0 (lorsqu'il est pressé, il est 0).
