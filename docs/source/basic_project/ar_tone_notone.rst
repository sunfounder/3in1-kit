.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions festives et cadeaux** : Participez à des promotions et à des cadeaux festifs.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _ar_passive_buzzer:

5.7 ``Tone()`` ou ``noTone()``
==================================

La fonction ``tone()`` génère une onde carrée d'une fréquence spécifiée (avec un cycle de service de 50 %) sur une broche. Une durée peut être spécifiée, sinon l'onde continue jusqu'à ce que ``noTone()`` soit appelé.

Dans ce projet, nous utilisons ces deux fonctions pour faire vibrer un buzzer passif afin 
de produire un son. Comme le buzzer actif, le buzzer passif fonctionne grâce au phénomène 
d'induction électromagnétique. Cependant, un buzzer passif ne possède pas de source 
d'oscillation, il ne produira donc aucun son avec des signaux continus (DC). Cela lui 
permet d'ajuster sa fréquence d'oscillation et d'émettre différentes notes comme « do, ré, mi, fa, sol, la, si ».

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
    *   - :ref:`cpn_buzzer`
        - |link_passive_buzzer_buy|

**Schéma**

.. image:: img/circuit_6.1_passive.png

Connectez la cathode du buzzer à GND, et l'anode à la broche numérique 9.

**Câblage**

.. image:: img/5.7_tone_bb.png
    :width: 600
    :align: center

**Code**

.. note::

    * Ouvrez le fichier ``5.7.tone_notone.ino`` dans le chemin ``3in1-kit\learning_project\5.7.tone_notone``.
    * Ou copiez ce code dans **Arduino IDE**.
    
    

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/9212e985-1f31-4bd9-bee6-f29357035aae/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Après avoir téléversé le code sur la carte R4, vous entendrez une mélodie composée de sept notes.

**Comment ça fonctionne ?**

Voici deux points importants à noter :

1. ``tone()`` & ``noTone()``: Ces fonctions contrôlent directement le son du buzzer passif.

   **Syntaxe**
       void tone(int pin, unsigned int frequency)

       void tone(int pin, unsigned int frequency, unsigned long duration)

   **Paramètres**
       * ``pin`` : La broche Arduino sur laquelle générer le son.
       * ``frequency`` : La fréquence du son en hertz.
       * ``duration`` : La durée du son en millisecondes (optionnelle).

Génère une onde carrée de la fréquence spécifiée (et avec un cycle de service de 50 %) sur une broche (ce qui fait vibrer le buzzer passif pour produire un son). Une durée peut être spécifiée, sinon l'onde continue jusqu'à ce que ``noTone()`` soit appelée. 
La broche peut être connectée à un buzzer piézoélectrique ou à un autre haut-parleur pour jouer des sons.

Un seul son peut être généré à la fois. Si un son est déjà joué sur une autre broche, l'appel de ``tone()`` n'aura aucun effet. Si le son est joué sur la même broche, l'appel définira sa fréquence.

L'utilisation de la fonction ``tone()`` interfère avec la sortie PWM sur les broches 3 et 11.

Il n'est pas possible de générer des sons inférieurs à 31 Hz.


**Syntaxe**
    void noTone(int pin)

**Paramètres**
    ``pin`` : La broche Arduino sur laquelle générer le son.

Arrête la génération d'une onde carrée déclenchée par ``tone()``. N'a aucun effet si aucun son n'est en cours de génération.

En comprenant ces deux fonctions, vous pouvez saisir le code : l'installation des tableaux ``melody[]`` et ``noteDurations[]`` prépare les appels successifs de la fonction ``tone()`` et la modification des sons et des durées dans la boucle pour un meilleur effet musical.

2. ``pitches.h`` : Le code utilise un fichier supplémentaire, ``pitches.h``. Ce fichier contient toutes les valeurs de hauteur pour les notes musicales typiques. Par exemple, NOTE_C4 correspond au « do » médian, NOTE_FS4 est le fa dièse, etc. Cette table des notes a été initialement écrite par Brett Hagman, dont les travaux ont inspiré la commande ``tone()``. Vous pouvez la trouver utile chaque fois que vous souhaitez produire des notes musicales.

.. code-block:: arduino

    #include "pitches.h"

.. note::
    Un fichier ``pitches.h`` est déjà inclus dans ce programme exemple. Si vous le placez avec le code principal dans un même dossier, les étapes supplémentaires pour installer ``pitches.h`` peuvent être ignorées.

.. image:: img/image123.png

Si vous ne pouvez pas ouvrir le fichier ``pitches.h``, vous pouvez le créer manuellement en 
suivant les étapes suivantes :

Pour créer le fichier ``pitches.h``, cliquez sur le bouton en dessous de l'icône du moniteur 
série et choisissez **Nouvel Onglet**, ou utilisez **Ctrl+Shift+N**.

.. image:: img/image124.png

Ensuite, collez le code suivant et enregistrez-le sous le nom ``pitches.h`` :

.. code-block:: arduino

    /*****************
    Constantes Publiques
    *****************/
    #define NOTE_B0  31
    #define NOTE_C1  33
    #define NOTE_CS1 35
    #define NOTE_D1  37
    #define NOTE_DS1 39
    #define NOTE_E1  41
    #define NOTE_F1  44
    #define NOTE_FS1 46
    #define NOTE_G1  49
    #define NOTE_GS1 52
    #define NOTE_A1  55
    #define NOTE_AS1 58
    #define NOTE_B1  62
    #define NOTE_C2  65
    #define NOTE_CS2 69
    #define NOTE_D2  73
    #define NOTE_DS2 78
    #define NOTE_E2  82
    #define NOTE_F2  87
    #define NOTE_FS2 93
    #define NOTE_G2  98
    #define NOTE_GS2 104
    #define NOTE_A2  110
    #define NOTE_AS2 117
    #define NOTE_B2  123
    #define NOTE_C3  131
    #define NOTE_CS3 139
    #define NOTE_D3  147
    #define NOTE_DS3 156
    #define NOTE_E3  165
    #define NOTE_F3  175
    #define NOTE_FS3 185
    #define NOTE_G3  196
    #define NOTE_GS3 208
    #define NOTE_A3  220
    #define NOTE_AS3 233
    #define NOTE_B3  247
    #define NOTE_C4  262
    #define NOTE_CS4 277
    #define NOTE_D4  294
    #define NOTE_DS4 311
    #define NOTE_E4  330
    #define NOTE_F4  349
    #define NOTE_FS4 370
    #define NOTE_G4  392
    #define NOTE_GS4 415
    #define NOTE_A4  440
    #define NOTE_AS4 466
    #define NOTE_B4  494
    #define NOTE_C5  523
    #define NOTE_CS5 554
    #define NOTE_D5  587
    #define NOTE_DS5 622
    #define NOTE_E5  659
    #define NOTE_F5  698
    #define NOTE_FS5 740
    #define NOTE_G5  784
    #define NOTE_GS5 831
    #define NOTE_A5  880
    #define NOTE_AS5 932
    #define NOTE_B5  988
    #define NOTE_C6  1047
    #define NOTE_CS6 1109
    #define NOTE_D6  1175
    #define NOTE_DS6 1245
    #define NOTE_E6  1319
    #define NOTE_F6  1397
    #define NOTE_FS6 1480
    #define NOTE_G6  1568
    #define NOTE_GS6 1661
    #define NOTE_A6  1760
    #define NOTE_AS6 1865
    #define NOTE_B6  1976
    #define NOTE_C7  2093
    #define NOTE_CS7 2217
    #define NOTE_D7  2349
    #define NOTE_DS7 2489
    #define NOTE_E7  2637
    #define NOTE_F7  2794
    #define NOTE_FS7 2960
    #define NOTE_G7  3136
    #define NOTE_GS7 3322
    #define NOTE_A7  3520
    #define NOTE_AS7 3729
    #define NOTE_B7  3951
    #define NOTE_C8  4186
    #define NOTE_CS8 4435
    #define NOTE_D8  4699
    #define NOTE_DS8 49
