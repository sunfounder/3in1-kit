.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions festives et cadeaux** : Participez à des promotions et à des cadeaux festifs.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _ar_segment:


5.10 ShiftOut (Affichage à segment)
=======================================

La fonction ``shiftOut()`` permet au 74HC595 de produire 8 signaux numériques. Elle envoie le dernier bit du nombre binaire vers Q0 et le premier bit vers Q7. Dans ce projet, nous utilisons cette fonction pour afficher les chiffres de 0 à 9 sur un affichage à 7 segments.

L'affichage à 7 segments est essentiellement un dispositif regroupant 8 LED, dont 7 LED en forme de bandes forment un "8" et une LED plus petite représente un point décimal. Ces LED sont marquées par les lettres a, b, c, d, e, f, g et dp. Elles ont leurs propres broches anodiques et partagent des cathodes. Le schéma des broches est illustré ci-dessous.

.. image:: img/segment_cathode.png
    :width: 600
    :align: center

**Composants nécessaires**

Dans ce projet, nous avons besoin des composants suivants.

Il est vraiment pratique d'acheter un kit complet, voici le lien :

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nom
        - ÉLÉMENTS DANS CE KIT
        - LIEN
    *   - Kit de démarrage 3 en 1
        - 380+
        - |link_3IN1_kit|

Vous pouvez également les acheter séparément via les liens ci-dessous.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUCTION AUX COMPOSANTS
        - LIEN D'ACHAT

    *   - :ref:`cpn_uno`
        - \-
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
        - Affichage à 7 segments
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

.. image:: img/5.10_segment_bb.png
    :width: 600
    :align: center

**Code**

.. note::

    * Ouvrez le fichier ``5.10.shiftout_segment.ino`` dans le chemin ``3in1-kit\learning_project\5.10.shiftout_segment``.
    * Ou copiez ce code dans **Arduino IDE**.
    
    

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/23b9a3ea-c648-4f33-8622-e279d94ee507/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Après avoir téléversé le code, l'affichage à 7 segments montrera les chiffres de 0 à 9 séquentiellement.

**Comment cela fonctionne-t-il ?**

La fonction ``shiftOut()`` permet au 74HC595 de produire 8 signaux numériques. 
Elle envoie le dernier bit du nombre binaire vers Q0 et le premier bit vers Q7. 
Par exemple, écrire le nombre binaire "00000001" allumera Q0 et éteindra Q1~Q7.

Si nous voulons afficher le chiffre "2" sur l'affichage à 7 segments, nous devons 
activer les segments a, b, d, e et g (niveau haut) et désactiver les segments c, 
f et dp (niveau bas). Le code binaire correspondant est "01011011", que nous pouvons 
noter en hexadécimal comme "0x5b".

.. image:: img/7_segment2.png

* `Hexadécimal <https://fr.wikipedia.org/wiki/Hexad%C3%A9cimal>`_

* `Convertisseur Binaire-Hexadécimal <https://www.binaryhexconverter.com/binary-to-hex-converter>`_

De même, nous pouvons afficher d'autres chiffres en utilisant les codes correspondants. 
Le tableau ci-dessous montre les codes pour chaque chiffre.

.. list-table:: Glyph Code
    :widths: 20 20 20
    :header-rows: 1

    *   - Chiffres
        - Code Binaire
        - Code Hexadécimal
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

Insérez ces codes dans ``shiftOut()`` pour afficher les chiffres correspondants sur l'affichage à 7 segments.
