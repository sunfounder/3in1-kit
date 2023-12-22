.. _ar_threshold:

5.2 Seuil
=======================

Dans de nombreux projets, vous rencontrerez ce besoin.
"Lorsque xxx atteint un certain niveau, alors..."

Par exemple, dans une maison intelligente, lorsque l'intensité lumineuse est inférieure à 50Lux, allumez la lumière ;
Un autre exemple est sur la carte mère d'un ordinateur, si la température de fonctionnement du CPU est supérieure à 65 degrés Celsius, allumez le ventilateur, et ainsi de suite.

Dans ces exigences, le mot-clé "seuil" est reflété.

Nous pouvons ajuster la valeur du seuil pour que le circuit fonctionne plus en adéquation avec les besoins individuels.
Par exemple, si j'aime un environnement de vie plus lumineux, je peux augmenter le seuil des lumières automatiques de la maison intelligente à 80Lux.
Un autre exemple est que l'environnement de ventilation de mon studio n'est pas très bon, et la demande de dissipation thermique est plus élevée, donc la valeur seuil de l'ouverture automatique du ventilateur peut être ajustée à 50 degrés Celsius.

Ici, nous utilisons un capteur d'humidité du sol et 2 LED pour fabriquer un moniteur de pot. Si le sol est trop sec, la LED rouge s'allumera ; si le sol est suffisamment humide, la LED verte s'allumera. Vous devez ajuster manuellement les seuils pour déterminer la sécheresse et l'humidité du sol.

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
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_soil_moisture`
        - |link_soil_moisture_buy|

**Schéma**

.. image:: img/circuit_8.2_threshold.png

**Câblage**

.. image:: img/threshold_bb.png
    :width: 600
    :align: center

**Code**

.. note::

    * Ouvrez le fichier ``5.2.threshold.ino`` sous le chemin ``3in1-kit\basic_project\5.2.threshold``.
    * Ou copiez ce code dans **Arduino IDE**.
    

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/9936413a-6e6c-4e57-b0c6-5df58dd48a3c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Après le téléchargement réussi du code, si votre seuil est correctement défini, vous verrez la LED rouge s'allumer lorsque le sol est sec pour vous rappeler que vous devez arroser ; après l'arrosage, la LED verte s'allumera.

**Fonctionnement**

.. code-block:: Arduino

    ...

    void loop() {
        int sensorValue = analogRead(soilMoisture);
        Serial.println(sensorValue);
        if (sensorValue > threshold) {
            digitalWrite(redPin, HIGH); // Turn the red LED
            digitalWrite(greenPin, LOW); // green
        } else {
            digitalWrite(greenPin, HIGH); // Turn on the green LED
            digitalWrite(redPin, LOW); // red
        }
    }
    ...

Définissez d'abord une valeur de ``threshold`` puis lisez la valeur du module d'humidité du sol, sa valeur diminue à mesure que le niveau d'humidité augmente. Si la valeur actuellement lue est supérieure au ``threshold`` défini, alors laissez la LED rouge s'allumer, sinon allumez la LED verte.

Cette valeur de ``threshold`` doit être ajustée en fonction de la situation réelle, vous pouvez d'abord télécharger le code, puis ouvrir le moniteur série pour vérifier la valeur, enregistrer la valeur dans des conditions humides et sèches, puis choisir une valeur médiane comme valeur de ``threshold``.



