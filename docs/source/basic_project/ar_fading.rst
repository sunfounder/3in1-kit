.. _ar_fading:

2.1 Estompage
=================

Ce projet est similaire à :ref:`ar_blink`, la différence réside dans le type de signal.
Le premier consiste à allumer ou éteindre la LED en émettant un signal numérique (0&1), tandis que ce projet contrôle la luminosité de la LED en émettant un signal analogique.

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
    *   - :ref:`cpn_led`
        - |link_led_buy|

**Schéma**

.. image:: img/circuit_1.1_led.png

**Câblage**

.. image:: img/wiring_led.png
    :width: 500
    :align: center

**Code**

.. note::

   * Vous pouvez ouvrir le fichier ``2.1.fading.ino`` dans le chemin ``3in1-kit\basic_project\2.analogWrite\2.1.fading``. 
   * Ou copiez ce code dans **Arduino IDE**.
   
   * Ou téléchargez le code via l'`Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.



.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/8a7e52a4-fcb3-4c3b-98ff-f3f657822d72/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Après le téléchargement réussi du code, vous pouvez voir la LED respirer.
