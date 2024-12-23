.. note:: 

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes post-vente et techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprenez & partagez** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces et aperçus de nouveaux produits.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _ar_74hc_7seg:

5.15 EEPROM
==============

`EEPROM <https://docs.arduino.cc/learn/built-in-libraries/eeprom>`_ est une mémoire non volatile, ce qui signifie que les données qu'elle stocke ne sont pas effacées lorsque la carte de contrôle principale est éteinte. Vous pouvez l'utiliser pour enregistrer des données et les lire lors de la prochaine mise sous tension.

Par exemple, vous pouvez créer un compteur de sport qui suit le nombre de sauts à la corde effectués chaque jour.

Vous pouvez également écrire des données dans un programme et les lire dans un autre. Par exemple, lorsque vous travaillez sur un projet de voiture, les vitesses des deux moteurs peuvent être incohérentes. Vous pouvez écrire un programme de calibration pour enregistrer la valeur de compensation de la vitesse des moteurs.

**Composants nécessaires**

Dans ce projet, nous aurons besoin des composants suivants. 

Il est très pratique d'acheter un kit complet, voici le lien : 

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nom
        - ARTICLES DANS CE KIT
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
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_servo`
        - |link_servo_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|
    *   - :ref:`cpn_potentiometer`
        - |link_potentiometer_buy|

**Schéma**

.. image:: img/circuit_515_eeprom.png

**Câblage**

.. image:: img/5.15_eeprom_bb.png

**Code**


.. note::

    * Ouvrez le fichier ``5.15.eeproom.ino`` sous le chemin ``3in1-kit\learning_project\5.15.eeproom``.
    * Ou copiez ce code dans **Arduino IDE**.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/7378341f-9c1a-4171-814f-c76c109e1e67/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Pour utiliser ce circuit, appuyez simplement sur le bouton pour commencer l'enregistrement et saisissez les informations souhaitées via un potentiomètre. Ensuite, la carte répétera vos actions en boucle (et fera clignoter une LED à chaque itération) jusqu'à ce que vous appuyiez à nouveau sur le bouton pour enregistrer de nouvelles actions. Vous pouvez également modifier le temps d'enregistrement en ajustant les valeurs de ``resolution`` et ``recordTime``.


**Comment ça fonctionne ?**

#. Importez la bibliothèque ``EEPROM.h`` et initialisez la mémoire EEPROM. 

    .. code-block:: arduino

        ...
        #include <EEPROM.h>//utilisée pour stocker les valeurs enregistrées

        ...
        float resolution = 1000;//DOIT être inférieur à EEPROM.length()
        float recordTime = 5; //temps de délai
        bool recording = false;
        ...
    
    Notez que ``DOIT être inférieur à EEPROM.length()``. Dans ``setup()``, la mémoire de l'EEPROM de votre carte sera imprimée, qui devrait être de 1024 pour votre carte. Si vous utilisez une carte différente, vous pouvez modifier la valeur de la variable ``resolution``.

#. Imprimez la mémoire EEPROM de votre carte.

    .. code-block:: arduino

        void setup() {
            ...
            Serial.begin(9600);
            //Serial.println(EEPROM.length());
        }

    Pour connaître la taille de la mémoire EEPROM de votre carte, décommentez la ligne ``Serial.println(EEPROM.read(i))``. La taille de l'EEPROM sera imprimée dans le moniteur série, et vous pourrez ajuster la valeur de ``resolution`` en conséquence.

#. Lorsqu'une pression sur le bouton est détectée, l'enregistrement commence et les informations requises sont saisies via un potentiomètre. La carte répète ensuite vos actions en boucle (et fait clignoter une LED pour chaque répétition) jusqu'à ce que vous appuyiez à nouveau sur le bouton pour enregistrer une nouvelle action.

    .. code-block:: arduino

        void loop() {
            if (recording == true) {//enregistrer
                for (int i = 1; i <= resolution; i++) {
                    digitalWrite(ledPin, HIGH); //allumer la LED de statut
                    int val = map(analogRead(A0), 0, 1023, 0, 180);
                    EEPROM.write(i, val);
                    //Serial.println(EEPROM.read(i));
                    myServo.write(val);
                    delay(recordTime);
                }
                digitalWrite(ledPin, LOW); //éteindre la LED de statut
                delay(1000);//donner du temps à la personne
                recording = false;
            }
            else {
                for (int i = 1; i <= resolution; i++) {//relecture
                    if (digitalRead(buttonPin) == 0) {//arrêter la relecture et enregistrer de nouvelles valeurs
                        recording = true;
                        break;
                    }
                    int readval = EEPROM.read(i);
                    myServo.write(readval);
                    //Serial.println(readval);
                    delay(recordTime);
                }
                digitalWrite(ledPin, HIGH); //montrer une nouvelle répétition
                delay(100);
                digitalWrite(ledPin, LOW);
            }
        }

    * Passez la variable ``recording`` à ``true`` lorsque le bouton est pressé.
    * Lorsque la variable ``recording`` est ``true``, commencez à enregistrer l'action dans la plage de mémoire.
    * Lisez la valeur du potentiomètre et mappez-la de 0-180 pour la stocker dans l'EEPROM et contrôler la rotation du servo.
    * La LED s'allume au début de l'enregistrement et s'éteint à la fin.
    * Répétez l'action enregistrée avec un clignotement rapide de la LED pour signaler une nouvelle répétition.


#. À propos de la bibliothèque ``EEPROM`` 

    Voici quelques-unes de ses fonctions :
        
    * ``write(address,value)`` : Écrit un octet dans l'EEPROM.

        * ``address`` : l'emplacement où écrire, à partir de 0 (int)
        * ``value`` : la valeur à écrire, de 0 à 255 (byte)
        * Une écriture dans l'EEPROM prend 3,3 ms pour s'achever. La mémoire EEPROM a une durée de vie spécifiée de 100 000 cycles d'écriture/effacement, donc il est conseillé de limiter la fréquence des écritures.

    * ``Read(address)`` : Lit un octet depuis l'EEPROM. Les emplacements qui n'ont jamais été écrits contiennent la valeur 255.

    * ``update(address,value)`` : Écrit un octet dans l'EEPROM uniquement si la valeur diffère de celle déjà enregistrée à la même adresse.

        * Une écriture dans l'EEPROM prend 3,3 ms pour s'achever. La mémoire EEPROM a une durée de vie spécifiée de 100 000 cycles d'écriture/effacement, donc utiliser cette fonction au lieu de write() peut économiser des cycles si les données écrites ne changent pas souvent.

    * ``EEPROM.put(address, data)`` : Écrit tout type de données ou d'objet dans l'EEPROM.

        * ``address`` : l'emplacement où écrire, à partir de 0 (int).
        * ``data`` : les données à écrire, pouvant être un type primitif (par exemple : float) ou une structure personnalisée.
        * Cette fonction utilise ``EEPROM.update()`` pour effectuer l'écriture, ce qui évite de réécrire la valeur si elle n'a pas changé.

    * ``EEPROM.get(address, data)`` : Lit tout type de données ou d'objet depuis l'EEPROM.

        * ``address`` : l'emplacement où lire, à partir de 0 (int).
        * ``data`` : les données à lire, pouvant être un type primitif (par exemple : float) ou une structure personnalisée.
