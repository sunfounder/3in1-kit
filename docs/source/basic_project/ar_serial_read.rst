.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions festives et cadeaux** : Participez à des promotions et à des cadeaux festifs.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _ar_serial_read:

5.12 Lecture Série
======================

Vous avez peut-être remarqué, en utilisant la fonction ``Serial.print()``, qu'il existe 
aussi une possibilité de lecture. À quoi sert la boîte de texte dans le Moniteur Série ? 
Oui, vous avez deviné, il existe des moyens de contrôler les programmes et les circuits 
en entrant des informations dans cette boîte de texte.

Dans ce projet, nous allons utiliser l'I2C LCD1602 pour afficher le texte saisi dans le 
Moniteur Série afin de découvrir l'utilisation de ``Serial.read()``.

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|

**Schéma**

.. image:: img/circuit_7.1_lcd1602.png

**Câblage**

.. image:: img/5.11_lcd_bb.png
    :width: 800
    :align: center

**Code**

.. note::

    * Ouvrez le fichier ``5.12.serial_read.ino`` dans le chemin ``3in1-kit\learning_project\5.12.serial_read``.
    * Ou copiez ce code dans **Arduino IDE**.
    * La bibliothèque ``LiquidCrystal I2C`` est utilisée ici, vous pouvez l'installer depuis le **Gestionnaire de bibliothèques**.

        .. image:: ../img/lib_liquidcrystal_i2c.png

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/a6197c53-6969-402e-8930-84a9165397b9/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Une fois le code téléversé avec succès, vous pouvez saisir du texte dans la boîte de texte du Moniteur Série, et l'écran LCD affichera les informations.

**Comment cela fonctionne-t-il ?**

    .. code-block:: arduino

        void loop()
        {
        // quand des caractères arrivent sur le port série...
            if (Serial.available()) {
                // attendre un peu pour que le message complet arrive
                delay(100);
                // effacer l'écran
                lcd.clear();
                // lire tous les caractères disponibles
                while (Serial.available() > 0) {
                    // afficher chaque caractère sur le LCD
                    lcd.write(Serial.read());
                }
            }
        }

* ``Serial.available()`` permet de connaître le nombre de caractères disponibles dans le flux entrant lorsque vous tapez quelque chose dans la boîte de texte. Étant donné qu'il existe deux terminateurs dans l'entrée, vous avez en fait 3 caractères lorsque vous tapez ``A``, et 4 caractères lorsque vous tapez ``AB``.
* ``Serial.read()`` lit le premier caractère du flux entrant. Par exemple, si vous tapez ``AB``, appeler ``Serial.read()`` une seule fois récupérera le caractère ``A`` ; la deuxième fois, vous obtiendrez ``B`` ; et les troisième et quatrième appels récupéreront deux caractères de fin. Appeler cette fonction lorsque le flux entrant ne contient aucun caractère disponible entraînera une erreur.

Pour résumer, il est courant de combiner les deux fonctions ci-dessus, en utilisant une boucle ``while`` pour lire tous les caractères saisis à chaque fois.

    .. code-block:: arduino

        while (Serial.available() > 0) {
            Serial.print(Serial.read());
        }

D'ailleurs, si vous n'utilisez pas ``Serial.read()`` pour lire les caractères du flux entrant, 
les caractères du flux entrant seront empilés ensemble. Par exemple, si vous tapez ``A`` suivi de ``AB``, le flux entrant accumulera 7 caractères.
