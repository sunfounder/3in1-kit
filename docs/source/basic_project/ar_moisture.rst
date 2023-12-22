.. _ar_moisture:

4.4 Mesurer l'Humidité du Sol
===============================

Dans l'industrie de la plantation, les cultures elles-mêmes ne peuvent pas obtenir directement les éléments inorganiques du sol,
l'eau dans le sol agit comme un solvant pour dissoudre ces éléments inorganiques.

Les cultures absorbent l'humidité du sol par le système racinaire, obtiennent des nutriments et favorisent la croissance.

Au cours de la croissance et du développement des cultures, les exigences pour la température du sol sont également différentes.
Par conséquent, un capteur d'humidité du sol est nécessaire.

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
    *   - :ref:`cpn_soil_moisture`
        - |link_soil_moisture_buy|

**Schéma**

.. image:: img/circuit_5.4_soil.png

**Câblage**

.. image:: img/measure_the_moisture_bb.jpg
    :width: 800
    :align: center

**Code**

.. note::

    * Ouvrez le fichier ``4.4.measure_soil_moisture.ino`` sous le chemin ``3in1-kit\basic_project\4.4.measure_soil_moisture``.
    * Ou copiez ce code dans **Arduino IDE**.
    
    * Ou téléchargez le code via l'`Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/b6f7e756-0f14-4117-9bb2-ee5083b6445f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Une fois le code téléchargé avec succès, le moniteur série imprimera la valeur de l'humidité du sol.

En insérant le module dans le sol et en l'arrosant, la valeur du capteur d'humidité du sol deviendra plus petite.
