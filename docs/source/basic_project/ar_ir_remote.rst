.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et à des promotions festives.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _ar_receiver:

5.11.2 Récepteur IR
=========================

Dans ce projet, vous apprendrez à utiliser un récepteur IR.

Un récepteur infrarouge est un composant qui reçoit des signaux infrarouges et peut 
indépendamment recevoir des rayons infrarouges et émettre des signaux compatibles 
avec le niveau TTL. Il est de taille similaire à un transistor classique emballé dans 
du plastique et convient à tous types de télécommandes infrarouges et de transmissions infrarouges.

**Composants nécessaires**

Dans ce projet, nous avons besoin des composants suivants :

C'est pratique d'acheter un kit complet, voici le lien :

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nom
        - ARTICLES DANS CE KIT
        - LIEN
    *   - Kit de démarrage 3 en 1
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
    *   - :ref:`cpn_receiver`
        - \-

**Schéma**

.. image:: img/circuit_7.2_receiver.png

**Câblage**

Dans cet exemple, connectez la broche gauche du récepteur IR à la broche 11, 
la broche du milieu à GND, et la broche droite à 5V.

.. image:: img/5.11_ir_recv_bb.png

**Code**

.. note::

    * Ouvrez le fichier ``5.11.ir_receiver.ino`` dans le répertoire ``3in1-kit\learning_project\5.11.ir_receiver``.
    * Ou copiez ce code dans l'IDE Arduino.
    * La bibliothèque ``IRremote`` est utilisée ici, vous pouvez l'installer via le **Library Manager**.
  
        .. image:: ../img/lib_irremote.png



.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/1141d808-cc26-4589-ae5c-d1834033ac3d/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    

Après avoir téléversé le code sur la carte R4, vous verrez que la valeur actuelle du 
bouton pressé de la télécommande IR s'affiche sur le moniteur série.

**Comment ça fonctionne ?**

Ce code est conçu pour fonctionner avec une télécommande infrarouge (IR) en utilisant la 
bibliothèque ``IRremote``. Voici les étapes :

#. Inclure les bibliothèques : Cela inclut la bibliothèque ``IRremote``, qui fournit des 
fonctions pour travailler avec des télécommandes IR.

    .. code-block:: arduino

        #include <IRremote.h>

#. Définir la broche Arduino à laquelle est connectée la broche signal du capteur IR.

    .. code-block:: arduino

        const int IR_RECEIVE_PIN = 11;  // Définir le numéro de broche pour le capteur IR


#. Initialiser la communication série à un débit de 9600 bauds. Initialiser le récepteur IR sur la broche spécifiée (``IR_RECEIVE_PIN``) et activer le retour LED (si applicable).

    .. code-block:: arduino

        void setup() {
            Serial.begin(9600);                                     // Démarrer la communication série à 9600 bauds
            IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);  // Démarrer le récepteur IR
        }

#. La boucle s'exécute continuellement pour traiter les signaux entrants de la télécommande IR.

    .. code-block:: arduino

        void loop() {
            if (IrReceiver.decode()) {
                String decodedValue = decodeKeyValue(IrReceiver.decodedIRData.command);
                if (decodedValue != "ERROR") {
                    Serial.println(decodedValue);
                    delay(100);
                }
                IrReceiver.resume();  // Activer la réception du prochain signal
            }
        }
    
    * Vérifie si un signal IR est reçu et correctement décodé.
    * Décode la commande IR et la stocke dans ``decodedValue`` à l'aide d'une fonction personnalisée ``decodeKeyValue()``.
    * Vérifie si la valeur décodée n'est pas une erreur.
    * Affiche la valeur IR décodée sur le moniteur série.
    * Reprend la réception des signaux IR pour le prochain signal.
