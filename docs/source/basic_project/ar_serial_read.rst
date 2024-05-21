.. note::

    Bonjour et bienvenue dans la Communauté Facebook des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez [|link_sf_facebook|] et rejoignez-nous aujourd'hui !

.. _ar_serial_read:

5.12 Lecture Série
===================

Vous l'avez peut-être remarqué en utilisant la fonction ``Serial.print()``.
Puisqu'il y a impression, y a-t-il lecture ? À quoi sert la boîte de texte sur le moniteur série ?
Oui, vous l'avez deviné, il existe des moyens de contrôler des programmes et des circuits en entrant des informations via la boîte de texte sur le moniteur série.

Dans ce projet, nous utiliserons le LCD1602 I2C pour afficher le texte entré dans le moniteur série afin d'expérimenter l'utilisation de ``Serial.read()``.

**Composants Nécessaires**

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|


**Schéma**

.. image:: img/circuit_7.1_lcd1602.png

**Câblage**

.. image:: img/lcd_bb.jpg
    :width: 800
    :align: center

**Code**

.. note::

    * Ouvrez le fichier ``5.12.serial_read.ino`` situé dans le dossier ``3in1-kit\basic_project\5.12.serial_read``.
    * Ou copiez ce code dans **Arduino IDE**.
    * La bibliothèque ``LiquidCrystal I2C`` est utilisée ici, vous pouvez l'installer depuis le **Library Manager**.

        .. image:: ../img/lib_liquidcrystal_i2c.png

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/a6197c53-6969-402e-8930-84a9165397b9/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Après le téléversement réussi du code, vous pouvez entrer du texte dans la boîte de texte sur le moniteur série, et le LCD affichera les informations.


**Comment ça fonctionne ?**

    .. code-block:: arduino

        void loop()
        {
        // when characters arrive over the serial port...
            if (Serial.available()) {
                // wait a bit for the entire message to arrive
                delay(100);
                // clear the screen
                lcd.clear();
                // read all the available characters
                while (Serial.available() > 0) {
                    // display each character to the LCD
                    lcd.write(Serial.read());
                }
            }
        }

* ``Serial.available()`` peut obtenir le nombre de caractères disponibles dans le flux entrant lorsque vous tapez quelque chose depuis la boîte de texte. Comme il y a deux terminateurs dans l'entrée, vous avez en fait 3 caractères lorsque vous tapez ``A``, et 4 caractères lorsque vous tapez ``AB``.
* ``Serial.read()`` prendra le premier caractère du flux entrant. Par exemple, si vous avez tapé ``AB``, en appelant ``Serial.read()`` une seule fois, vous obtiendrez le caractère ``A``; au deuxième appel, vous obtiendrez ``B``; au troisième et quatrième appel, vous obtiendrez deux symboles de fin; appeler cette fonction lorsque le flux entrant n'a pas de caractères disponibles résultera en une erreur.

En résumé, il est courant de combiner les deux ci-dessus, en utilisant une boucle ``while`` pour lire tous les caractères entrés à chaque fois.

    .. code-block:: arduino

        while (Serial.available() > 0) {
            Serial.print(Serial.read());
        }

D'ailleurs, si vous n'utilisez pas ``Serial.read()`` pour obtenir des caractères du flux entrant, les caractères du flux entrant s'empileront.
Par exemple, si vous tapez ``A`` suivi de ``AB``, le flux entrant accumulera 7 caractères.
