.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et à des promotions festives.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

6.5 Jeu de Réaction
==========================

Notre corps réagit à différents types de stimuli tels que les sons (RT audio), les images (RT visuel), ou le toucher (RT tactile).

Les temps de réaction jouent un rôle clé dans notre vie quotidienne. Par exemple, un temps de réaction plus lent que la normale lors de la conduite peut avoir des conséquences graves.

Dans ce projet, nous utilisons 3 boutons et 2 LEDs pour mesurer le temps de réaction visuel.

Le moniteur série de l'Arduino affiche le message "waiting...".
Après avoir appuyé sur le bouton Ready, l'une des deux LEDs s'allume de manière aléatoire après un intervalle de temps aléatoire. Le participant doit appuyer sur le bouton correspondant le plus rapidement possible.
L'Arduino enregistre la différence de temps entre le moment où la LED s'allume et celui où le bouton correspondant est pressé, et affiche le temps de réaction mesuré sur le moniteur série.

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
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|

**Schéma**

.. image:: img/wiring_reaction_game.png
    :align: center

**Câblage**

.. image:: img/6.5_reaction_game_bb.png
    :width: 600
    :align: center

**Code**

.. note::

    * Ouvrez le fichier ``6.5.reaction_time.ino`` dans le répertoire ``3in1-kit\learning_project\6.5_reversingAid``.
    * Ou copiez ce code dans l'IDE Arduino.
    * Assurez-vous d'avoir ajouté la bibliothèque ``LiquidCrystal_I2C``, les tutoriels détaillés sont disponibles ici : :ref:`install_libraries_ar`.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/4313dd1c-e1d2-4939-ae20-0a5b82a12390/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

**Comment ça marche ?**

#. Initialisez les boutons et LEDs. Deux interruptions sont utilisées ici pour lire l'état des boutons.

    .. code-block:: arduino

        void setup()
        {

            ...

            attachInterrupt(digitalPinToInterrupt(buttonPin1), pressed1, FALLING);
            attachInterrupt(digitalPinToInterrupt(buttonPin2), pressed2, FALLING);
            ...
        }

#. Si le bouton ``rstBtn`` est pressé, le jeu recommence. Après un délai aléatoire compris entre 2 et 5ms, l'une des LEDs s'allume.

    .. code-block:: arduino

        void loop()
        {
            if (flag == -1 && digitalRead(rstBtn) == LOW) {
                digitalWrite(ledPin1, LOW);
                digitalWrite(ledPin2, LOW);
                Serial.println("Waiting...");
                int randomTime = random(2000, 5000);
                delay(randomTime);

                timer = millis();
                flag = randomTime % 2;
                Serial.println("Light!");

                if (flag == 0) {
                    digitalWrite(ledPin1, HIGH);
                } else if (flag == 1) {
                    digitalWrite(ledPin2, HIGH);
                }
            }
            delay(200);
        }

    * Lorsque flag vaut -1 et que le bouton ``rstBtn`` est pressé, utilisez la fonction ``random()`` pour générer un délai aléatoire de 2 à 5 secondes.
    * Ce délai est utilisé pour contrôler l'allumage des LEDs.
    * L'allumage des 2 LEDs est généré aléatoirement par ``randomTime % 2``, soit 0 pour la LED1, soit 1 pour la LED2.

#. À propos de la fonction ``pressed1()``

    .. code-block:: arduino

        void pressed1() {
            if (flag == -1) {
                return;
            }
            if (flag == 0) {
                int currentTime = millis();
                Serial.print("Correct! You reaction time is : ");
                Serial.print(currentTime - timer);
                Serial.println(" ms");
            } else if (flag == 1) {
                Serial.println("Wrong Click!");
            }
            flag = -1;
        }

    Cette fonction est déclenchée lorsque le bouton 1 est pressé. Si flag vaut 0 à ce moment-là, le temps de réaction est affiché ; sinon, une erreur de clic est signalée.

#. À propos de la fonction ``pressed2()``

    .. code-block:: arduino

        void pressed2() {
            if (flag == -1) {
                return;
            }
            if (flag == 1) {
                int currentTime =millis();
                Serial.print("Correct! You reaction time is : ");
                Serial.print(currentTime - timer);
                Serial.println(" ms");
            } else if (flag == 0) {
                Serial.println("Wrong Click!");
            }
            flag = -1;
        }

    Cette fonction est déclenchée lorsque le bouton 2 est pressé. Si flag vaut 1 à ce moment-là, le temps de réaction est affiché ; sinon, une erreur de clic est signalée.
