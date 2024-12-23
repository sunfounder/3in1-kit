.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions spéciales.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _car_remote:

9. Télécommande
==========================

Ce kit est équipé d'un récepteur IR, qui vous permet d'utiliser une télécommande infrarouge pour contrôler les mouvements de la voiture.

**Composants nécessaires**

Dans ce projet, nous aurons besoin des composants suivants.

Il est pratique d'acheter un kit complet, voici le lien :

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nom
        - Éléments dans ce kit
        - Lien
    *   - Kit de démarrage 3 en 1
        - 380+
        - |link_3IN1_kit|

Vous pouvez également les acheter séparément via les liens ci-dessous.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Présentation des composants
        - Lien d'achat

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_l9110`
        - \-
    *   - :ref:`cpn_tt_motor`
        - \-
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_receiver`
        - \-

**Câblage**

Assemblez le circuit selon le schéma ci-dessous.

.. list-table::
    :header-rows: 1

    * - Récepteur IR
      - Carte R4
    * - OUT
      - 12
    * - GND
      - GND
    * - VCC
      - 5V

.. list-table::
    :header-rows: 1

    * - LED
      - Carte R4
    * - Anode (la broche la plus longue)
      - 13
    * - Cathode
      - GND

.. image:: img/car_9.png
    :width: 800

**Code**

.. note::

    * Ouvrez le fichier ``9.remote_control.ino`` dans le répertoire ``3in1-kit\car_project\9.remote_control``.
    * Ou copiez ce code dans **Arduino IDE**.
    * La bibliothèque ``IRremote`` est utilisée ici, vous pouvez l'installer depuis le **Gestionnaire de bibliothèques**.

        .. image:: ../img/lib_irremote.png

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/7c78450d-fcd2-4288-a00d-499c71ad2d52/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Après avoir téléversé le code avec succès, appuyez sur un bouton de la télécommande. La LED clignotera une fois pour indiquer que le signal a été reçu, et la voiture se déplacera selon le bouton que vous avez pressé. Vous pouvez utiliser les touches suivantes pour contrôler la voiture :

* **+** : Accélérer
* **-** : Décélérer
* **1** : Avancer vers la gauche
* **2** : Avancer
* **3** : Avancer vers la droite
* **4** : Tourner à gauche
* **6** : Tourner à droite
* **7** : Reculer vers la gauche
* **8** : Reculer
* **9** : Reculer vers la droite

**Comment ça fonctionne ?**

L'effet de ce projet est de faire bouger la voiture en lisant la valeur des touches de la télécommande IR. De plus, une LED est ajoutée pour indiquer que le signal IR a été reçu avec succès.

#. Importez la bibliothèque ``IRremote``. Installez-la via le **Gestionnaire de bibliothèques**.

    .. code-block:: arduino

        #include <IRremote.h>

        const int IR_RECEIVE_PIN = 12;  // Définir le numéro de broche pour le capteur IR

#. Initialisez la communication série avec un débit en bauds de 9600. Activez le récepteur IR sur la broche spécifiée (``IR_RECEIVE_PIN``) et activez le retour LED (si applicable).

    .. code-block:: arduino

        ...

        void setup() {

            ...
            // Télécommande IR
            IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);  // Démarrer le récepteur IR
            Serial.println("REMOTE CONTROL START");

        }


#. Lorsque vous appuyez sur les touches de la télécommande, le récepteur infrarouge identifie la touche appuyée, et la voiture agit en fonction de la valeur correspondante.

    .. code-block:: arduino

        void loop() {

            if (IrReceiver.decode()) {
                //    Serial.println(results.value,HEX);
                String key = decodeKeyValue(IrReceiver.decodedIRData.command);
                if (key != "ERROR") {
                    Serial.println(key);

                    if (key == "+") {
                        speed += 50;
                    } else if (key == "-") {
                        speed -= 50;
                    } else if (key == "2") {
                        moveForward(speed);
                        delay(1000);
                    ...
                    }
                    IrReceiver.resume();  // Réactiver la réception pour la prochaine commande
            }
        }

    * Vérifie si un signal IR est reçu et décodé avec succès.
    * Décode la commande IR et la stocke dans ``key`` en utilisant une fonction personnalisée ``decodeKeyValue()``.
    * Vérifie si la valeur décodée n'est pas une erreur.
    * Affiche la valeur IR décodée sur le moniteur série.
    * Réactive la réception du signal IR pour le prochain signal.

