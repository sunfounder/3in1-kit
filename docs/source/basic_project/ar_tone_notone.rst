.. _ar_passive_buzzer:

5.7 ``Tone()`` ou ``noTone()``
===============================

La fonction ``Tone()`` est utilisée pour générer une onde carrée de la fréquence spécifiée (et un cycle de travail de 50 %) sur une broche. Une durée peut être spécifiée, sinon l'onde continue jusqu'à un appel à ``noTone()``. 

Dans ce projet, utilisez ces deux fonctions pour faire vibrer le buzzer passif afin de produire un son. 
Comme le buzzer actif, le buzzer passif utilise également le phénomène d'induction électromagnétique pour fonctionner. 
La différence est qu'un buzzer passif n'a pas de source oscillante, donc il ne bipera pas si des signaux DC sont utilisés. 
Mais cela permet au buzzer passif d'ajuster sa propre fréquence d'oscillation et peut émettre différentes notes telles que "do, ré, mi, fa, sol, la, si".

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
    *   - :ref:`cpn_buzzer`
        - |link_passive_buzzer_buy|


**Schéma**

.. image:: img/circuit_6.1_passive.png

Connectez la cathode du Buzzer à GND, et l'anode à la broche numérique 9.


**Câblage**

.. image:: img/custom_tone_bb.jpg

**Code**

.. note::

    * Ouvrez le fichier ``5.7.tone_notone.ino`` sous le chemin ``3in1-kit\basic_project\5.7.tone_notone``.
    * Ou copiez ce code dans **Arduino IDE**.
    
    * Ou téléchargez le code via l'`Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.


.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/9212e985-1f31-4bd9-bee6-f29357035aae/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Lorsque vous aurez fini de télécharger les codes sur la carte R3, vous pourrez entendre une mélodie contenant sept notes. 

**Comment ça fonctionne ?**

Il y a deux points à noter :

1. ``tone()`` & ``noTone()`` : Cette fonction est utilisée pour contrôler directement le son du buzzer passif et son prototype est comme suit :

**Syntaxe**
    void tone(int pin, unsigned int frequency)

    void tone(int pin, unsigned int frequency, unsigned long duration)

**Paramètres**
    * ``pin`` : La broche Arduino sur laquelle générer le ton.
    * ``frequency`` : La fréquence du ton en hertz.
    * ``duration`` : La durée du ton en millisecondes (optionnel)

Génère une onde carrée de la fréquence spécifiée (et un cycle de travail de 50 %) sur une broche (afin de faire vibrer le buzzer passif pour produire un son). Une durée peut être spécifiée, sinon l'onde continue jusqu'à un appel à ``noTone()``. 
La broche peut être connectée à un buzzer piézo ou à un autre haut-parleur pour jouer des tons.

Un seul ton peut être généré à la fois. Si un ton est déjà en train de jouer sur une broche différente, l'appel à ``tone()`` n'aura aucun effet. Si le ton est joué sur la même broche, l'appel définira sa fréquence.

L'utilisation de la fonction ``tone()`` interférera avec la sortie PWM sur les broches 3 et 11.

Il n'est pas possible de générer des tons inférieurs à 31 Hz.

**Syntaxe**
    void noTone(int pin)

**Paramètres**
    ``pin`` : La broche Arduino sur laquelle générer le ton.

Arrête la génération d'une onde carrée déclenchée par ``tone()``. N'a aucun effet si aucun ton n'est généré.

Après avoir connu les deux fonctions, vous pouvez comprendre les codes - l'installation des tableaux ``melody[]`` et ``noteDurations[]`` est la préparation des appels successifs de la fonction ``tone()`` et le changement de ton et de durée dans la boucle pour un meilleur effet de lecture de musique.

2. ``pitches.h`` : Le code utilise un fichier supplémentaire, ``pitches.h``. Ce fichier contient toutes les valeurs de tonalité pour les notes typiques. Par exemple, NOTE_C4 est le do médian. NOTE_FS4 est le fa dièse, et ainsi de suite. Ce tableau de notes a été initialement écrit par Brett Hagman, sur lequel le commande ``tone()`` a été basée. Vous pouvez le trouver utile chaque fois que vous voulez faire des notes musicales.

.. code-block:: arduino

    #include "pitches.h"

.. note::
    Il y a déjà un fichier ``pitches.h`` dans ce programme d'exemple. Si nous le mettons avec le code principal dans un dossier, les étapes d'installation de ``pitches.h`` peuvent être omises.

.. image:: img/image123.png

Après avoir ouvert le fichier de code, si vous ne pouvez pas ouvrir le
code ``pitches.h``, vous pouvez simplement en créer un manuellement. Les étapes sont les suivantes :

Pour créer le fichier ``pitches.h``, cliquez soit sur le bouton juste en dessous de l'icône du moniteur série et choisissez **New Tab**, soit utilisez **Ctrl+Shift+N**.

.. image:: img/image124.png

Ensuite, collez le code suivant et enregistrez-le en tant que ``pitches.h`` :

.. code-block:: arduino

    /*****************
    Public Constants
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
