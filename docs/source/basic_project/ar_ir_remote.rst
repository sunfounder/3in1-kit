.. note::

    Bonjour et bienvenue dans la Communauté Facebook des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez [|link_sf_facebook|] et rejoignez-nous aujourd'hui !

.. _ar_receiver:

5.11.2 Récepteur IR
===================

Dans ce projet, vous apprendrez à utiliser un récepteur infrarouge (IR).

Un récepteur infrarouge est un composant qui reçoit des signaux infrarouges et peut recevoir indépendamment des rayons infrarouges et sortir des signaux compatibles avec le niveau TTL. 
Il est similaire en taille à un transistor classique emballé dans du plastique et convient à toutes sortes de télécommandes infrarouges et de transmissions infrarouges.

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
    *   - :ref:`cpn_receiver`
        - \-

**Schéma**

.. image:: img/circuit_7.2_receiver.png

**Câblage**

Dans cet exemple, nous connectons la broche gauche du récepteur IR à la broche 11, 
la broche centrale à GND, et la broche droite à 5V.

.. image:: img/ir_remote_control_bb.jpg


**Code**

.. note::

    * Ouvrez le fichier ``5.11.ir_receiver.ino`` situé dans le dossier ``3in1-kit\basic_project\5.11.ir_receiver``.
    * Ou copiez ce code dans **Arduino IDE**.
    * La bibliothèque ``IRremote`` est utilisée ici, vous pouvez l'installer depuis le **Library Manager**.
  
        .. image:: ../img/lib_irremote.png


.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/1141d808-cc26-4589-ae5c-d1834033ac3d/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    

Après avoir téléversé les codes sur la carte R3, vous pouvez constater que la
valeur actuelle du bouton pressé de la télécommande IR s'affiche sur
le moniteur série.

**Comment ça fonctionne ?**

Ce code est conçu pour fonctionner avec une télécommande infrarouge (IR) en utilisant la bibliothèque ``IRremote``. Voici le détail :

#. Inclusion des bibliothèques : Cela inclut la bibliothèque ``IRremote``, qui fournit des fonctions pour travailler avec les télécommandes IR.

    .. code-block:: arduino

        #include <IRremote.h>

#. Définit le pin Arduino auquel est connecté le pin de signal du capteur IR.

    .. code-block:: arduino

        const int IR_RECEIVE_PIN = 11;  // Define the pin number for the IR Sensor

#. Initialise la communication série à une vitesse de 9600 bauds. Initialise le récepteur IR sur le pin spécifié (``IR_RECEIVE_PIN``) et active le retour LED (si applicable).

    .. code-block:: arduino

        void setup() {
            Serial.begin(9600);                                     // Start serial communication at 9600 baud rate
            IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);  // Start the IR receiver
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
                IrReceiver.resume();  // Enable receiving of the next value
            }
        }
    
    * Vérifie si un signal IR est reçu et décodé avec succès.
    * Décode la commande IR et la stocke dans ``decodedValue`` à l'aide d'une fonction personnalisée ``decodeKeyValue()``.
    * Vérifie si la valeur décodée n'est pas une erreur.
    * Affiche la valeur IR décodée sur le moniteur série.
    * Reprend la réception du signal IR pour le prochain signal.
