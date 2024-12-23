.. note:: 

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes post-vente et techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprenez & partagez** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces et aperçus de nouveaux produits.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _ar_eeprom:

6.2 Dé électronique
=============================

Dans ce projet, nous utilisons un bouton, un afficheur 7 segments et un 74hc595 pour 
créer un dé électronique. À chaque pression sur le bouton, un nombre aléatoire compris 
entre 1 et 6 est généré et affiché sur l'afficheur 7 segments.

**Composants nécessaires**

Dans ce projet, nous aurons besoin des composants suivants. 

Il est très pratique d'acheter un kit complet, voici le lien : 

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
        - \-
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

.. image:: img/6.2_electronic_dice_bb.png
    :width: 800
    :align: center

**Code**

.. note::

    * Ouvrez le fichier ``6.2.electronic_dice.ino`` sous le chemin ``3in1-kit\learning_project\6.2.electronic_dice``.
    * Ou copiez ce code dans **Arduino IDE**.



.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/8d8ad340-b1de-4518-917b-caaf07e4baf4/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Lorsque le code est téléversé avec succès, l'afficheur 7 segments affiche un défilement rapide de 0 à 7. Lorsque vous appuyez sur le bouton, il affiche un nombre aléatoire et arrête le défilement. Le défilement redémarre lorsque vous appuyez à nouveau sur le bouton.

**Comment ça fonctionne ?**

Ce projet est basé sur :ref:`ar_segment` avec un bouton pour démarrer/mettre en pause le défilement sur l'afficheur 7 segments.

#. Initialisez chaque broche et lisez la valeur du bouton.

    .. code-block:: arduino

        void setup ()
        {

            ...
            attachInterrupt(digitalPinToInterrupt(buttonPin), rollDice, FALLING);
        }

    * Une interruption est utilisée ici pour lire l'état du bouton. La valeur par défaut de ``buttonPin`` est LOW, qui passe de LOW à HIGH lorsqu'on appuie sur le bouton.
    * ``rollDice`` représente la fonction appelée lorsque l'interruption est déclenchée. Elle permet de basculer la valeur de la variable ``state``.
    * ``FALLING`` signifie que l'interruption est déclenchée lorsque ``buttonPin`` passe de LOW à HIGH.

#. Lorsque la variable ``state`` est à 0, la fonction ``showNumber()`` est appelée pour afficher aléatoirement un nombre entre 1 et 7 sur l'afficheur 7 segments.

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
    
    Lorsque cette fonction est appelée, elle bascule la valeur de ``state``, par exemple de 1 à 0 ou inversement.

#. À propos de la fonction ``showNumber()``.

    .. code-block:: arduino

        void showNumber(int num) {
            digitalWrite(STcp, LOW); // Mettez ST_CP à LOW et maintenez-le tant que vous transmettez
            shiftOut(DS, SHcp, MSBFIRST, datArray[num]);
            //return the latch pin high to signal chip that it
            //no longer needs to listen for information
            digitalWrite(STcp, HIGH); // Tirez ST_CP à HIGH pour enregistrer les données
        }
    
    Ce code est tiré du projet :ref:`ar_segment` et encapsulé dans la fonction ``showNumber()``.
