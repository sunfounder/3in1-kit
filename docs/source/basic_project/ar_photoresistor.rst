.. _ar_photoresistor:

4.2 Ressentir la Lumière
===========================

Le photo-résistor est un dispositif typique pour les entrées analogiques et il est utilisé de manière très similaire à un potentiomètre. Sa valeur de résistance dépend de l'intensité de la lumière, plus la lumière irradiée est forte, plus sa valeur de résistance est petite ; inversement, elle augmente.

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
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_buy|

**Schéma**

.. image:: img/circuit_5.2_light.png

Dans ce circuit, la résistance de 10K et le photo-résistor sont connectés en série, et le courant les traversant est le même. La résistance de 10K agit comme une protection, et la broche A0 lit la valeur après la conversion de tension du photo-résistor.

Lorsque la lumière est renforcée, la résistance du photo-résistor diminue, alors sa tension diminue, donc la valeur de la broche A0 augmentera ; 
si la lumière est suffisamment forte, la résistance du photo-résistor sera proche de 0, et la valeur de la broche A0 sera proche de 1023. 
À ce moment, la résistance de 10K joue un rôle protecteur, afin que 5V et GND ne soient pas connectés ensemble, entraînant un court-circuit.

Si vous placez le photo-résistor dans une situation sombre, la valeur de la broche A0 diminuera. 
Dans une situation suffisamment sombre, la résistance du photo-résistor sera infinie, et sa tension sera proche de 5V (la résistance de 10K est négligeable), et la valeur de la broche A0 sera proche de 0.


**Câblage**

.. image:: img/feel_the_light_bb.jpg
    :width: 600
    :align: center


**Code**

.. note::

    * Ouvrez le fichier ``4.2.feel_the_light.ino`` sous le chemin ``3in1-kit\basic_project\4.2.feel_the_light``.
    * Ou copiez ce code dans **Arduino IDE**.
    
    * Ou téléchargez le code via l'`Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/e1bc4c8b-788e-4bfe-a0a1-532d4fdc7753/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Après le téléchargement réussi du code, le moniteur série affiche les valeurs du photo-résistor. 
Plus la luminosité ambiante actuelle est forte, plus la valeur affichée sur le moniteur série est grande.
