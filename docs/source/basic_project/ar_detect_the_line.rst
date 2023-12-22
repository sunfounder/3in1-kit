.. _ar_line_track:

3.4 Détecter la Ligne
===================================

Le module de suivi de ligne est utilisé pour détecter s'il y a des zones noires sur le sol, comme des lignes noires collées avec du ruban électrique.

L'une de ses LED émet une lumière infrarouge appropriée vers le sol, et la surface noire a une capacité relativement forte à absorber la lumière et une capacité de réflexion plus faible. Les surfaces blanches sont l'inverse.
S'il détecte de la lumière réfléchie, cela signifie que le sol est actuellement blanc. Si elle n'est pas détectée, cela signifie noir.

C'est ainsi que cela fonctionne.

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
    *   - :ref:`cpn_track`
        - |link_track_buy|

**Schéma**

.. image:: img/circuit_3.4_line.png

La broche numérique 2 est utilisée pour lire le
signal du module de suivi de ligne. Nous connectons le VCC du module à 5V, 
GND à GND, OUT à la broche numérique 2.

**Câblage**

.. image:: img/detect_the_line_bb.jpg
    :width: 500
    :align: center

**Code**

.. note::

   * Vous pouvez ouvrir le fichier ``3.4.detect_the_line.ino`` dans le chemin ``3in1-kit\basic_project\3.4.detect_the_line``. 
   * Ou copiez ce code dans **Arduino IDE**.
   
   * Ou téléchargez le code via l'`Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.


.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/9795add6-c838-4a66-b484-0c39f252a7b4/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Lorsque le module de suivi de ligne détecte qu'il y a une ligne noire, il apparaît [1] sur le Moniteur Série ; sinon, [0] est affiché.

