.. _ar_state_change:

5.3 Détection de Changement d'État
=====================================

Lorsque le bouton contrôle d'autres dispositifs, il peut non seulement fonctionner lorsqu'il est pressé, mais aussi s'arrêter lorsqu'il est relâché.
Il est également possible de basculer l'état de fonctionnement à chaque fois que le bouton est pressé.

Pour réaliser cet effet, vous devez savoir comment basculer l'état de fonctionnement entre éteint et allumé lorsque le bouton est pressé,
C'est la "détection de changement d'état".

Dans ce projet, nous utiliserons le bouton pour contrôler le moteur.

**Composants requis**

Pour ce projet, nous avons besoin des composants suivants.

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
    *   - :ref:`cpn_button`
        - |link_button_buy|
    *   - :ref:`cpn_tt_motor`
        - \-
    *   - :ref:`cpn_l9110`
        - \-

**Schéma**

.. image:: img/circuit_8.3_statechange.png

**Câblage**

.. image:: img/5.3_state_change_l9110_bb.png
    :width: 800
    :align: center

**Code**

.. note::

    * Ouvrez le fichier ``5.3.state_change_detection.ino`` sous le chemin ``3in1-kit\basic_project\5.3.state_change_detection``.
    * Ou copiez ce code dans **Arduino IDE**.
    
    * Ou téléchargez le code via l'`Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/67a62a3d-46d3-4f5f-889c-364cbdf9b66f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Après le téléchargement réussi du code, vous appuyez sur le bouton et le moteur tourne ; jusqu'à ce que vous appuyiez à nouveau sur le bouton, le moteur s'arrête.


**Comment ça fonctionne ?**

#. Créez des variables et définissez les broches pour le moteur et le bouton.

    .. code-block:: arduino

        ...
        int detectionState = 0;   
        int buttonState = 0;         
        int lastButtonState = 0;    

    * ``detectionState`` est un indicateur dont la valeur change à chaque fois que le bouton est pressé, par exemple, 0 cette fois, 1 la prochaine, et ainsi de suite alternativement.
    * ``buttonState`` et ``lastButtonState`` sont utilisés pour enregistrer l'état du bouton cette fois et la dernière fois, pour comparer si le bouton a été pressé ou relâché.

#. Initialisez chaque broche et réglez le taux de baud du moniteur série.

    .. code-block:: arduino

        void setup() {
            pinMode(buttonPin, INPUT);
            Serial.begin(9600);
            pinMode(B_1A, OUTPUT);
            pinMode(B_1B, OUTPUT);
        }


#. Commencez par lire l'état du bouton, et si le bouton est pressé, la variable ``detectionState`` changera sa valeur de 0 à 1 ou de 1 à 0. Lorsque ``detectionState`` est à 1, le moteur sera activé. Cela a pour effet que lorsque le bouton est pressé cette fois-ci, le moteur tourne, la prochaine fois que le bouton est pressé, le moteur s'arrête, et ainsi de suite alternativement.

    .. code-block:: arduino

        void loop() {
            // Toggle the detectionState each time the button is pressed
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
            
            // According to the detectionState, start the motor
            if(detectionState==1){
                digitalWrite(B_1A,HIGH);
                digitalWrite(B_1B,LOW);
            }else{
                digitalWrite(B_1A,LOW);
                digitalWrite(B_1B,LOW);
            }
        }

    Le flux de travail complet est le suivant.

    * Lire la valeur du bouton.

    .. code-block:: arduino

        buttonState = digitalRead(buttonPin);

    * Si ``buttonState`` et ``lastButtonState`` ne sont pas égaux, cela signifie que l'état du bouton a changé, continuez avec le jugement suivant, et stockez l'état du bouton à ce moment dans la variable ``lastButtonState``. ``delay(50)`` est utilisé pour éliminer le jitter.
    
    .. code-block:: arduino

        if (buttonState != lastButtonState) {
        ...
            delay(50);
        }
        lastButtonState = buttonState;

    * Lorsque le bouton est pressé, sa valeur est HIGH. Ici, lorsque le bouton est pressé, la valeur de la variable ``detectionState`` est modifiée, par exemple, de 0 à 1 après une opération.

    .. code-block:: arduino

        if (buttonState == HIGH) {
            detectionState=(detectionState+1)%2;
            Serial.print("The detection state is: ");
            Serial.println(detectionState);
        }

    * Lorsque la variable ``detectionState`` est à 1, faire tourner le moteur, sinon l'arrêter.

    .. code-block:: arduino

        if(detectionState==1){
            digitalWrite(B_1A,HIGH);
            digitalWrite(B_1B,LOW);
        }else{
            digitalWrite(B_1A,LOW);
            digitalWrite(B_1B,LOW);
        }

