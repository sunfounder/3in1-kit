.. note::

    Bonjour et bienvenue dans la Communauté Facebook des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez [|link_sf_facebook|] et rejoignez-nous aujourd'hui !

.. _car_remote:

9. Télécommande
=================================

Ce kit est livré avec un récepteur IR, qui vous permet d'utiliser une télécommande IR pour contrôler le mouvement de la voiture.

**Composants requis**

Pour ce projet, nous avons besoin des composants suivants.

Il est certainement pratique d'acheter un kit complet, voici le lien :

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nom	
        - ÉLÉMENTS DANS CE KIT
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
    *   - :ref:`cpn_l9110`
        - \-
    *   - :ref:`cpn_tt_motor`
        - \-
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_receiver`
        - \-

**Câblage**

.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/M8buGWCkYcI?si=spLK2KP363rkN6sl" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

Construisez maintenant le circuit selon le schéma ci-dessous.

.. list-table:: 
    :header-rows: 1

    * - Récepteur IR
      - Carte R3
    * - OUT
      - 12
    * - GND
      - GND
    * - VCC
      - 5V

.. image:: img/car_9.png
    :width: 800

**Code**

.. note::

    * Ouvrez le fichier ``9.remote_control.ino`` situé dans le dossier ``3in1-kit\car_project\9.remote_control``.
    * Ou copiez ce code dans **Arduino IDE**.
    * La bibliothèque ``IRremote`` est utilisée ici, vous pouvez l'installer depuis le **Library Manager**.
  
        .. image:: ../img/lib_irremote.png

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/7c78450d-fcd2-4288-a00d-499c71ad2d52/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Après le téléchargement réussi du code, appuyez sur le bouton de la télécommande, la LED clignotera une fois pour indiquer que le signal a été reçu, et la voiture se déplacera selon le bouton que vous avez pressé. Vous pouvez appuyer sur les touches suivantes pour contrôler la voiture.

* **+** : Accélérer
* **-** : Ralentir
* **1** : Avancer à gauche
* **2** : Avancer
* **3** : Avancer à droite
* **4** : Tourner à gauche
* **6** : Tourner à droite
* **7** : Reculer à gauche
* **8** : Reculer
* **9** : Reculer à droite


**Comment ça fonctionne ?**

L'effet de ce projet est de faire bouger la voiture en lisant la valeur clé de la télécommande IR. De plus, la LED sur la broche 13 clignotera pour indiquer la réception réussie du signal IR.

#. Importez la bibliothèque ``IRremote``, vous pouvez l'installer depuis le **Library Manager**.


    .. code-block:: arduino

        #include <IRremote.h>

        const int IR_RECEIVE_PIN = 12;  // Define the pin number for the IR Sensor

#. Initialise la communication série à un débit de 9600 bauds. Initialise le récepteur IR sur la broche spécifiée (``IR_RECEIVE_PIN``) et active le retour LED (si applicable).

    .. code-block:: arduino

        ...

        void setup() {

            ...
            //IR remote
            IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);  // Start the receiver
            Serial.println("REMOTE CONTROL START");

        }


#. Lorsque vous appuyez sur les touches de la télécommande, le récepteur infrarouge saura quelle touche est pressée, puis la voiture se déplacera en fonction de la valeur clé correspondante.


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
                    IrReceiver.resume();  // Enable receiving of the next value

            }
        }

    * Vérifie si un signal IR est reçu et décodé avec succès.
    * Décode la commande IR et la stocke dans ``key`` à l'aide d'une fonction ``decodeKeyValue()`` personnalisée.
    * Vérifie si la valeur décodée n'est pas une erreur.
    * Imprime la valeur IR décodée sur le moniteur série.
    * Reprend la réception du signal IR pour le signal suivant.


