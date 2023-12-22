.. _ar_pump:

1.4 Pompage
===================

La pompe à eau est également un moteur, qui convertit l'énergie mécanique du moteur ou d'une autre source externe grâce à une structure spéciale pour transporter le liquide.

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_l9110`
        - \-
    *   - :ref:`cpn_pump`
        - \-

**Schéma**

.. image:: img/circuit_1.3_wheel_l9110.png

**Câblage**


.. image:: img/1.4_pumping_l9110_bb.png
    :width: 800
    :align: center


**Code**

.. note::

   * Vous pouvez ouvrir le fichier ``1.4.pumping.ino`` dans le chemin ``3in1-kit\basic_project\1.4.pumping``. 
   * Ou copiez ce code dans **Arduino IDE**.
   
   * Ou téléchargez le code via l'`Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/f829508f-2475-4de6-bc2f-ab0a68d707b1/preview?F=undefined?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Ajoutez le tuyau à la pompe et placez-la dans le bassin. Après le téléchargement réussi du code, vous pouvez constater que l'eau dans le bassin est évacuée au bout d'un moment.
Lors de cette expérimentation, veuillez tenir le circuit éloigné de l'eau pour éviter un court-circuit !
