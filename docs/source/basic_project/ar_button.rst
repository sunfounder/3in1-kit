.. _ar_button:

3.1 Lecture de la Valeur du Bouton
==============================================

Dans les projets précédents, nous avons utilisé la fonction de sortie, dans ce chapitre, nous utiliserons la fonction d'entrée pour lire la valeur du bouton.

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
    *   - :ref:`cpn_button`
        - |link_button_buy|

**Schéma**

.. image:: img/circuit_3.1_button.png

Un côté de la broche du bouton est connecté à 5V, 
et l'autre côté de la broche est connecté à la broche 2, 
donc lorsque le bouton est pressé, 
la broche 2 sera haute. Cependant, 
lorsque le bouton n'est pas pressé, 
la broche 2 est dans un état suspendu et peut être haute ou basse. 
Afin d'obtenir un niveau bas stable lorsque le bouton n'est pas pressé, 
la broche 2 doit être reconnectée à GND via une résistance de pull-down de 10K.

**Câblage**

.. image:: img/read_the_button_value_bb.jpg
    :width: 600
    :align: center

**Code**

.. note::

   * Vous pouvez ouvrir le fichier ``3.1.read_button_value.ino`` dans le chemin ``3in1-kit\basic_project\3.1.read_button_value``. 
   * Ou copiez ce code dans **Arduino IDE**.
   
   * Ou téléchargez le code via l'`Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.


.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/b456ff57-4dfb-4231-9d91-f1e9a5777de2/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Après le téléchargement réussi du code, cliquez sur l'icône de la loupe dans le coin supérieur droit de l'IDE Arduino (Moniteur Série).

.. image:: img/sp220614_152922.png

Lorsque vous appuyez sur le bouton, le Moniteur Série affichera "1".



