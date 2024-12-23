.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions festives et cadeaux** : Participez à des promotions et à des cadeaux festifs.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _ar_threshold:

5.2 Seuil
=============

Dans de nombreux projets, vous rencontrerez ce type de besoin :
"Quand xxx atteint un certain niveau, alors..."

Par exemple, dans une maison intelligente, lorsque l'intensité lumineuse est inférieure à 50 Lux, allumer la lumière ;
Un autre exemple est la carte mère d'un ordinateur : si la température de fonctionnement du processeur dépasse 65 degrés Celsius, activer le ventilateur, et ainsi de suite.

Dans ces exigences, le mot-clé "seuil" est mis en avant.

Nous pouvons ajuster la valeur du seuil pour que le circuit fonctionne davantage en fonction des besoins individuels.
Par exemple, si j'aime un environnement de vie plus lumineux, je peux augmenter le seuil des lumières automatiques de la maison intelligente à 80 Lux.
De même, si l'environnement de ventilation de mon atelier est insuffisant et que les besoins de dissipation thermique sont plus importants, alors la valeur du seuil d'activation automatique du ventilateur peut être ajustée à 50 degrés Celsius.


Ici, nous utilisons un capteur d'humidité du sol et 2 LEDs pour créer un moniteur de pot. Si le sol est trop sec, la LED rouge s'allume ; si le sol est suffisamment humide, la LED verte s'allume. Vous devez ajuster manuellement les seuils pour déterminer la sécheresse et l'humidité du sol.

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
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_soil_moisture`
        - |link_soil_moisture_buy|

**Schéma**

.. image:: img/circuit_8.2_threshold.png

**Câblage**

.. image:: img/5.2_threshold_bb.png
    :width: 600
    :align: center

**Code**

.. note::

    * Ouvrez le fichier ``5.2.threshold.ino`` dans le chemin ``3in1-kit\learning_project\5.2.threshold``.
    * Ou copiez ce code dans **Arduino IDE**.
    

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/9936413a-6e6c-4e57-b0c6-5df58dd48a3c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Après avoir téléversé le code avec succès, si votre seuil est correctement réglé, vous verrez la LED rouge s'allumer lorsque le sol est sec pour vous rappeler qu'il faut arroser ; après l'arrosage, la LED verte s'allumera.

**Comment cela fonctionne**

.. code-block:: Arduino

    ...

    void loop() {
        int sensorValue = analogRead(soilMoisture);
        Serial.println(sensorValue);
        if (sensorValue > threshold) {
            digitalWrite(redPin, HIGH); // Allume la LED rouge
            digitalWrite(greenPin, LOW); // Éteint la LED verte
        } else {
            digitalWrite(greenPin, HIGH); // Allume la LED verte
            digitalWrite(redPin, LOW); // Éteint la LED rouge
        }
    }
    ...

Commencez par définir une valeur de ``threshold`` (seuil), puis lisez la valeur du module d'humidité du sol. Cette valeur diminue à mesure que le niveau d'humidité augmente. Si la valeur actuellement lue est supérieure à la valeur définie pour le ``threshold``, alors la LED rouge s'allume, sinon la LED verte s'allume.

Cette valeur de ``threshold`` doit être ajustée en fonction de la situation réelle. Vous pouvez téléverser le code, puis ouvrir le Moniteur Série pour vérifier les valeurs, enregistrer les valeurs dans des conditions sèches et humides, et ensuite choisir une valeur intermédiaire comme valeur de ``threshold``.
