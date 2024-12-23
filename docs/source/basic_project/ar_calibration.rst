.. note:: 

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez plus profondément dans Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprenez et partagez** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aperçus exclusifs.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et promotions de vacances.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _ar_calibration:

5.14 Calibration
==========================

Lorsque vous utilisez des composants d'entrée analogiques, tels que des photo-résistances ou des capteurs d'humidité du sol, vous pouvez constater que leur plage de lecture n'est pas de 0 à 1023, mais plutôt une plage comme 0 à 800 ou 600 à 1000, car il est impossible d'atteindre les limites de ces dispositifs dans des conditions normales d'utilisation.

Dans ce cas, une technique de calibration des entrées du capteur peut être utilisée. Pendant le démarrage, demandez à la carte de contrôle de mesurer les lectures des capteurs pendant cinq secondes et d'enregistrer les lectures les plus hautes et les plus basses. Ces cinq secondes définissent les valeurs minimales et maximales attendues des lectures effectuées pendant le cycle.

Dans ce projet, nous utilisons une photo-résistance et un buzzer passif pour créer un jeu ressemblant à un `theremin <https://en.wikipedia.org/wiki/Theremine>`_, en utilisant la technique de calibration décrite ci-dessus.

.. note::
    Le `theremin <https://en.wikipedia.org/wiki/Theremine>`_ est un instrument de musique électronique qui ne nécessite aucun contact physique. Il génère des tons différents en détectant la position des mains du joueur.

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
    *   - :ref:`cpn_buzzer`
        - |link_passive_buzzer_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_buy|

**Schéma**

.. image:: img/circuit_8.8_calibration.png

**Câblage**

.. image:: img/5.14_calibration_bb.png
    :width: 600
    :align: center

**Code**

.. note::

    * Ouvrez le fichier ``5.14.calibration.ino`` sous le chemin ``3in1-kit\learning_project\5.14.calibration``.
    * Ou copiez ce code dans **Arduino IDE**.
    
.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/9cbcaae0-3c9d-4e33-9957-548f92a9aab7/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Après avoir téléchargé le code avec succès, la LED s'allumera, et vous aurez cinq secondes pour calibrer la plage de détection de la photo-résistance. Cela est nécessaire car nous pouvons être dans des environnements lumineux différents à chaque utilisation (par exemple, l'intensité lumineuse varie entre le milieu de journée et le crépuscule).

Pendant ce temps, déplacez vos mains de haut en bas au-dessus de la photo-résistance. La plage de mouvement de la main sera calibrée pour correspondre à la plage de jeu de cet instrument.

Après cinq secondes, la LED s'éteindra et vous pourrez agiter vos mains au-dessus de la photo-résistance pour jouer.



**Comment ça fonctionne ?**

#. Définissez les valeurs initiales et les broches de tous les composants.

    .. code-block:: arduino

        const int buzzerPin = 9;
        const int ledPin = 8;
        const int photocellPin = A0;  // La photo-résistance est connectée à A2
    
        int lightLow = 1023;
        int lightHigh = 0;
    
        int sensorValue = 0;        // Valeur lue par le capteur
        int pitch = 0;           // Valeur convertie pour la fréquence sonore
    
        unsigned long previousMillis = 0;
        const long interval = 5000;

#. Configurez un processus de calibration dans la fonction ``setup()``.

    .. code-block:: arduino

        void setup()
        {
            pinMode(buzzerPin, OUTPUT); // Configurez la broche du buzzer en sortie
            pinMode(ledPin, OUTPUT); // Configurez la broche de la LED en sortie

            /* Calibrez les valeurs max et min de la photo-résistance */
            previousMillis = millis();
            digitalWrite(ledPin, HIGH);
            while (millis() - previousMillis <= interval) {
                sensorValue = analogRead(photocellPin);
                if (sensorValue > lightHigh) {
                    lightHigh = sensorValue;
                }
                if (sensorValue < lightLow) {
                    lightLow = sensorValue;
                }
            }
            digitalWrite(ledPin, LOW);
        }

    Le flux de travail est le suivant :

    * Utilisez ``millis()`` pour chronométrer un intervalle de 5000 ms.

    .. code-block:: arduino

        previousMillis = millis();
        ...
        while (millis() - previousMillis <= interval) {
        ...
        }

    * Pendant ces cinq secondes, agitez une main autour de la photo-résistance. Les valeurs maximales et minimales de la lumière détectée sont enregistrées et affectées à ``lightHigh`` et ``lightLow``.

    .. code-block:: arduino
        
        sensorValue = analogRead(photocellPin);
        if (sensorValue > lightHigh) {
            lightHigh = sensorValue;
        }
        if (sensorValue < lightLow) {
            lightLow = sensorValue;
        }

#. Maintenant, vous pouvez commencer à jouer avec ce thérémine. Lisez la valeur de la photo-résistance dans ``sensorValue`` et mappez-la à une plage plus grande pour l'utiliser comme fréquence du buzzer.

    .. code-block:: arduino

        void loop()
        {
        /* Jouez */
        sensorValue = analogRead(photocellPin); // Lisez la valeur sur A0
        pitch = map(sensorValue, lightLow, lightHigh, 50, 6000);  // Mappez à la fréquence du buzzer
        if (pitch > 50) {
            tone(buzzerPin, pitch, 20);
        }
        delay(10);
        }
