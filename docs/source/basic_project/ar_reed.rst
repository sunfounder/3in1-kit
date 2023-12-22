.. _ar_reed:

3.2 Ressentir le Magnétisme
===============================

Le type le plus courant d'interrupteur à lames souples contient une paire de lames métalliques flexibles magnétisables, dont les extrémités sont séparées par un petit espace lorsque l'interrupteur est ouvert.

Un champ magnétique provenant d'un électroaimant ou d'un aimant permanent fera s'attirer les lames, complétant ainsi un circuit électrique.
La force de rappel des lames les amène à se séparer et à ouvrir le circuit, lorsque le champ magnétique cesse.

Un exemple courant d'application d'un interrupteur à lames souples est de détecter l'ouverture d'une porte ou d'une fenêtre, pour une alarme de sécurité.

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
    *   - :ref:`cpn_reed`
        - \-

**Schéma**

.. image:: img/circuit_3.2_reed.png

Par défaut, la broche 2 est basse ; et deviendra haute lorsque l'aimant est près de l'interrupteur à lames.

Le but de la résistance de 10K est de maintenir la broche 2 à un niveau bas stable lorsqu'aucun aimant n'est à proximité.

**Câblage**

.. image:: img/feel_the_magnetism_bb.jpg
    :width: 600
    :align: center

**Code**

.. note::

   * Vous pouvez ouvrir le fichier ``3.2.feel_the_magnetism.ino`` dans le chemin ``3in1-kit\basic_project\3.2.feel_the_magnetism``. 
   * Ou copiez ce code dans **Arduino IDE**.
   
   * Ou téléchargez le code via l'`Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/d28c942e-5144-44a1-85d8-d5e6894fc5df/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Après le téléchargement réussi du code, lorsque un aimant est près de l'interrupteur à lames, le moniteur série affichera 1.


