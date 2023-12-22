.. _ar_segment:

5.10 ShiftOut(Affichage à segments)
===================================

Précédemment, nous avons utilisé la fonction ``shiftout()`` pour allumer huit LED ; ici, nous l'utilisons pour afficher les chiffres 0 à 9 sur l'affichage à 7 segments.

L'affichage à 7 segments est essentiellement un dispositif composé de 8 LED, dont 7 LED en forme de bande formant un "8" et une LED pointillée légèrement plus petite servant de point décimal. Ces LED sont marquées a, b, c, d, e, f, g et dp. Elles ont leurs propres broches d'anode et partagent des cathodes. Leurs emplacements de broches sont indiqués dans la figure ci-dessous.

.. image:: img/segment_cathode.png
    :width: 600
    :align: center

**Composants requis**

Pour ce projet, nous avons besoin des composants suivants.

Il est certainement pratique d'acheter un kit complet, voici le lien :

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nom	
        - ARTICLES DANS CE KIT
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
    *   - :ref:`cpn_7_segment`
        - |link_7segment_buy|
    *   - :ref:`cpn_74hc595`
        - |link_74hc595_buy|

**Schéma**

.. image:: img/circuit_6.5_segment.png

**Câblage**

.. list-table:: Wiring
    :widths: 15 25
    :header-rows: 1

    *   - 74HC595
        - LED Segment Display
    *   - Q0
        - a
    *   - Q1
        - b
    *   - Q2
        - c
    *   - Q3
        - d
    *   - Q4
        - e
    *   - Q5
        - f
    *   - Q6
        - g
    *   - Q7
        - dp

.. image:: img/segment_bb.jpg
    :width: 600
    :align: center

**Code**

.. note::

    * Ouvrez le fichier ``5.10.shiftout_segment.ino`` situé dans ``3in1-kit\basic_project\5.10.shiftout_segment``.
    * Ou copiez ce code dans **Arduino IDE**.
    
    * Ou téléchargez le code via `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.


.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/23b9a3ea-c648-4f33-8622-e279d94ee507/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Après le téléchargement réussi du code, vous pourrez voir l'Afficheur à Segments LED afficher les chiffres 0 à 9 séquentiellement.

**Comment ça fonctionne ?**

``shiftOut()`` permet au 74HC595 de produire 8 signaux numériques.
Il envoie le dernier bit du nombre binaire à Q0,
et le premier bit à Q7. Autrement dit, 
écrire le nombre binaire "00000001" amènera Q0 à produire un niveau haut et Q1 à Q7 un niveau bas.

Supposons que l'afficheur à 7 segments affiche le chiffre "2", 
nous devons écrire un niveau haut pour a, b, d, e et g, et un niveau bas pour c, f et dp.
Cela signifie qu'il faut écrire le nombre binaire "01011011".
Pour plus de lisibilité, nous utiliserons la notation hexadécimale "0x5b".

.. image:: img/7_segment2.png

* `Hexadécimal <https://en.wikipedia.org/wiki/Hexadecimal>`_

* `Convertisseur Binaire-Hexadécimal <https://www.binaryhexconverter.com/binary-to-hex-converter>`_

De manière similaire, nous pouvons également faire afficher d'autres chiffres à l'afficheur à 7 segments de la même manière.
Le tableau suivant montre les codes correspondant à ces chiffres.

.. list-table:: Glyph Code
    :widths: 20 20 20
    :header-rows: 1

    *   - Numbers	
        - Binary Code
        - Hex Code  
    *   - 0	
        - 00111111	
        - 0x3f
    *   - 1	
        - 00000110	
        - 0x06
    *   - 2	
        - 01011011	
        - 0x5b
    *   - 3	
        - 01001111	
        - 0x4f
    *   - 4	
        - 01100110	
        - 0x66
    *   - 5	
        - 01101101	
        - 0x6d
    *   - 6	
        - 01111101	
        - 0x7d
    *   - 7	
        - 00000111	
        - 0x07
    *   - 8	
        - 01111111	
        - 0x7f
    *   - 9	
        - 01101111	
        - 0x6f

Écrivez ces codes dans ``shiftOut()`` pour faire afficher les nombres correspondants sur l'Afficheur à Segments LED.
