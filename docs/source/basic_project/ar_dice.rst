.. _ar_eeprom:

6.2 Dé de Numérique
===================

Ici, nous utilisons un bouton, un afficheur 7 segments et un 74hc595 pour créer un dé électronique.
Chaque fois que le bouton est pressé, un nombre aléatoire compris entre 1 et 6 est généré et affiché sur l'afficheur 7 segments.

**Composants requis**

Pour ce projet, nous aurons besoin des composants suivants.

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
    *   - :ref:`cpn_74hc595`
        - |link_74hc595_buy|
    *   - :ref:`cpn_7_segment`
        - |link_7segment_buy|

**Schéma**

.. image:: img/circuit_8.9_eeprom.png

**Câblage**

.. image:: img/wiring_electronic_dice.png
    :width: 800
    :align: center

**Code**

.. note::

    * Ouvrez le fichier ``6.2.electronic_dice.ino`` situé dans le dossier ``3in1-kit\basic_project\6.2.electronic_dice``.
    * Ou copiez ce code dans **Arduino IDE**.
    
    * Ou téléversez le code via l'`Éditeur Web Arduino <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/8d8ad340-b1de-4518-917b-caaf07e4baf4/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Lorsque le code est téléversé avec succès, l'afficheur 7 segments affichera 0-7 dans un défilement rapide, et lorsque vous appuierez sur le bouton, il affichera un nombre aléatoire et arrêtera de défiler. L'affichage défilant recommence lorsque vous appuyez à nouveau sur le bouton.

**Comment ça fonctionne ?**

Ce projet est basé sur :ref:`ar_segment` avec un bouton pour démarrer/pauser l'affichage défilant sur l'afficheur 7 segments.

#. Initialisez chaque broche et lisez la valeur du bouton.

    .. code-block:: arduino

        void setup ()
        {

            ...
            attachInterrupt(digitalPinToInterrupt(buttonPin), rollDice, FALLING);
        }

    * L'interruption est utilisée ici pour lire l'état du bouton. La valeur par défaut de ``buttonPin`` est basse, qui change de bas à haut lorsque le bouton est pressé.
    * ``rollDice`` représente la fonction à appeler lorsque l'interruption est déclenchée, elle est utilisée pour basculer la valeur de la variable ``state``.
    * ``FALLING`` signifie que l'interruption est déclenchée lorsque le ``buttonPin`` passe de bas à haut.

#. Lorsque la variable ``state`` est à 0, la fonction ``showNumber()`` est appelée pour faire afficher aléatoirement un nombre entre 1 et 7 sur l'afficheur 7 segments.

    .. code-block:: arduino

        void loop()
        {
            if (state == 0) {
                showNumber((int)random(1, 7));
                delay(50);
            }
        }

#. À propos de la fonction ``rollDice()``.

    .. code-block:: arduino

        void rollDice() {
            state = !state;
        }
    
    Lorsque cette fonction est appelée, elle bascule la valeur de state, par exemple 1 la dernière fois et 0 cette fois.

#. À propos de la fonction ``showNumber()``.

    .. code-block:: arduino

        void showNumber(int num) {
            digitalWrite(STcp, LOW); //ground ST_CP and hold low for as long as you are transmitting
            shiftOut(DS, SHcp, MSBFIRST, datArray[num]);
            //return the latch pin high to signal chip that it
            //no longer needs to listen for information
            digitalWrite(STcp, HIGH); //pull the ST_CPST_CP to save the data
        }
    
    Ceci est le code à l'intérieur de ``loop()`` dans le projet :ref:`ar_segment` intégré dans la fonction ``showNumber()``.
