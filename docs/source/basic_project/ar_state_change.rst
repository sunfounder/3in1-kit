.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions festives et cadeaux** : Participez à des promotions et à des cadeaux festifs.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _ar_state_change:

5.3 Détection de changement d'état
=======================================

Lorsque le bouton contrôle d'autres dispositifs, il peut non seulement fonctionner 
lorsqu'il est pressé, mais aussi s'arrêter lorsqu'il est relâché. Il est également 
possible de changer l'état de fonctionnement à chaque pression sur le bouton.

Pour obtenir cet effet, il faut savoir comment basculer l'état de fonctionnement entre 
éteint et allumé à chaque pression sur le bouton, ce qu'on appelle la "détection de changement d'état".

Dans ce projet, nous allons utiliser un bouton pour contrôler un moteur.

.. **Schematic**

.. .. image:: img/circuit_8.3_statechange.png

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|
    *   - :ref:`cpn_tt_motor`
        - \-
    *   - :ref:`cpn_l9110`
        - \-

**Schéma**

.. image:: img/circuit_8.3_statechange.png

**Câblage**

.. image:: img/5.3_state_change_bb.png
    :width: 800
    :align: center

**Code**

.. note::

    * Ouvrez le fichier ``5.3.state_change_detection.ino`` dans le chemin ``3in1-kit\learning_project\5.3.state_change_detection``.
    * Ou copiez ce code dans **Arduino IDE**.
    
    

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/67a62a3d-46d3-4f5f-889c-364cbdf9b66f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Après avoir téléversé le code, vous pouvez appuyer sur le bouton pour démarrer le moteur ; une nouvelle pression sur le bouton arrêtera le moteur.


**Comment ça marche ?**

#. Créez des variables et définissez les broches pour le moteur et le bouton.

    .. code-block:: arduino

        ...
        int detectionState = 0;   
        int buttonState = 0;         
        int lastButtonState = 0;    

    * ``detectionState`` est un indicateur dont la valeur change à chaque pression sur le bouton, par exemple, 0 cette fois, 1 la suivante, et ainsi de suite en alternance.
    * ``buttonState`` et ``lastButtonState`` sont utilisés pour enregistrer l'état actuel et précédent du bouton afin de comparer s'il a été pressé ou relâché.

#. Initialisez chaque broche et définissez le débit en bauds du moniteur série.

    .. code-block:: arduino

        void setup() {
            pinMode(buttonPin, INPUT);
            Serial.begin(9600);
            pinMode(A_1A,OUTPUT);
            pinMode(A_1B,OUTPUT);
        }

#. Lisez l'état du bouton, et si le bouton est pressé, la variable ``detectionState`` alternera entre 0 et 1. Lorsque ``detectionState`` est 1, le moteur se met en marche.

    .. code-block:: arduino

        void loop() {
            // Alterne l'état de détection à chaque pression sur le bouton
            buttonState = digitalRead(buttonPin);
            if (buttonState != lastButtonState) {
                if (buttonState == HIGH) {
                detectionState=(detectionState+1)%2;
                Serial.print("The detection state is: ");
                Serial.println(detectionState);
                } 
                delay(50);
            }
            lastButtonState = buttonState;
            
            // Selon l'état de détection, démarre ou arrête le moteur
            if(detectionState==1){
                digitalWrite(A_1A,HIGH);
                digitalWrite(A_1B,LOW);
            }else{
                digitalWrite(A_1A,LOW);
                digitalWrite(A_1B,LOW);
            }
        }

    Le fonctionnement global est comme suit.

    * Lisez la valeur du bouton.

    .. code-block:: arduino

        buttonState = digitalRead(buttonPin);

    * Si ``buttonState`` et ``lastButtonState`` ne sont pas égaux, cela signifie que l'état du bouton a changé. Mettez à jour ``lastButtonState`` et utilisez ``delay(50)`` pour éviter les rebonds.

    .. code-block:: arduino

        if (buttonState != lastButtonState) {
        ...
            delay(50);
        }
        lastButtonState = buttonState;

    * Lorsque le bouton est pressé, sa valeur est HIGH. Dans ce cas, alternez la valeur de ``detectionState`` entre 0 et 1.

    .. code-block:: arduino

        if (buttonState == HIGH) {
            detectionState=(detectionState+1)%2;
            Serial.print("The detection state is: ");
            Serial.println(detectionState);
            }

    * Si ``detectionState`` est 1, faites tourner le moteur, sinon arrêtez-le.

    .. code-block:: arduino

        if(detectionState==1){
            digitalWrite(A_1A,HIGH);
            digitalWrite(A_1B,LOW);
        }else{
            digitalWrite(A_1A,LOW);
            digitalWrite(A_1B,LOW);
        }

