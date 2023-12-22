.. _ar_ir_obstacle:

3.3 Détecter l'Obstacle
===================================

Ce module est couramment installé sur les voitures et les robots pour juger
de l'existence d'obstacles devant eux. Il est également largement utilisé dans les appareils portatifs, les robinets d'eau, etc.

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
    *   - :ref:`cpn_avoid`
        - |link_obstacle_avoidance_buy|

**Schéma**

.. image:: img/circuit_3.3_obstacle.png

La broche numérique 2 est utilisée pour lire le
signal du Module d'Évitement d'Obstacles IR. Nous connectons le VCC du
Module Capteur IR à 5V, GND à GND, OUT à la broche numérique 2.

**Câblage**

.. image:: img/detect_the_obstacle_bb.jpg
    :width: 800
    :align: center

**Code**

.. note::

   * Vous pouvez ouvrir le fichier ``3.3.detect_the_obstacle.ino`` dans le chemin ``3in1-kit\basic_project\3.3.detect_the_obstacle``. 
   * Ou copiez ce code dans **Arduino IDE**.
   
   * Ou téléchargez le code via l'`Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.


.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/535a0304-684e-481d-b85d-403911b3a4e2/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Lorsque le module d'évitement d'obstacles IR détecte quelque chose bloquant devant lui, [0] apparaîtra sur le moniteur série, sinon [1] sera affiché.
