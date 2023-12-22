.. _ar_reaction_game:

6.5 Jeu de Réaction
===================

Notre corps a de nombreux temps de réaction, tels que le temps de réaction auditif, visuel, tactile, etc.

Les temps de réaction ont de nombreux effets sur notre vie quotidienne, par exemple, des temps de réaction plus lents que la normale en conduisant peuvent entraîner de graves conséquences.

Dans ce projet, nous utilisons 3 boutons et 2 LED pour mesurer notre temps de réaction visuel.

Le moniteur série de l'Arduino affiche le message "en attente..."
Après avoir appuyé sur le bouton Prêt, l'une des deux LED doit s'allumer aléatoirement après un intervalle de temps aléatoire. Il est important que la personne testée appuie sur le bouton correspondant le plus rapidement possible.
L'Arduino enregistre la différence de temps entre le moment où la LED s'allume et lorsque la personne appuie sur le bouton correspondant, et imprime le temps de réponse mesuré sur le moniteur série de l'Arduino.

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
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|

**Schéma**

.. image:: img/wiring_reaction_game.png
    :align: center

**Câblage**

.. image:: img/reaction_game.png
    :align: center

**Code**

.. note::

    * Vous pouvez ouvrir le fichier ``6.5_reaction_time.ino`` sous le chemin de ``3in1-kit\basic_project\6.5_reversingAid`` directement.
    * Ou copiez ce code dans Arduino IDE .
    
    * Assurez-vous d'avoir ajouté la bibliothèque ``LiquidCrystal_I2C``, les tutoriels détaillés se réfèrent à :ref:`install_libraries_ar`.


.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/4313dd1c-e1d2-4939-ae20-0a5b82a12390/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

**Comment ça fonctionne ?**

#. Initialisez les boutons et les LED, 2 interruptions sont utilisées ici pour lire l'état des boutons.

    .. code-block:: arduino

        void setup()
        {

            ...

            attachInterrupt(digitalPinToInterrupt(buttonPin1), pressed1, FALLING);
            attachInterrupt(digitalPinToInterrupt(buttonPin2), pressed2, FALLING);
            ...
        }



#. Si le bouton ``rstBtn`` est pressé, le jeu recommence. À un moment aléatoire entre 2 et 5ms, faites s'allumer l'une des LED.

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

    * Lorsque flag est -1 et que le bouton ``rstBtn`` est pressé, utilisez la fonction ``random()`` pour générer un temps aléatoire de 2-5s.
    * Ce temps est ensuite utilisé pour contrôler l'allumage des LED.
    * Aussi, l'allumage de 2 LED est généré aléatoirement par ``randomTime % 2`` avec 0 et 1. Si flag est 0, alors LED1 est allumée ; si 1, alors LED2 est allumée.

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

    C'est la fonction qui sera déclenchée lorsque le bouton 1 est pressé. Lorsque le bouton 1 est pressé, si le flag est 0 à ce moment, le temps de réponse sera imprimé, sinon une erreur de pression sera indiquée.

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

    C'est la fonction qui sera déclenchée lorsque le bouton 2 est pressé. Lorsque le bouton 2 est pressé, si le flag est 1 à ce moment, le temps de réponse sera imprimé, sinon une erreur de pression sera indiquée.


