.. note::

    Bonjour et bienvenue dans la Communauté Facebook des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez [|link_sf_facebook|] et rejoignez-nous aujourd'hui !

.. _iot_plant:

6. Moniteur de Plantes
==========================

L'objectif de ce projet est de créer un système d'arrosage intelligent qui détecte la température actuelle, l'humidité, l'intensité de la lumière et l'humidité du sol et les affiche sur Blynk.

Dès que vous activez le basculeur Switch dans Blynk Cloud, la pompe commencera à fonctionner et les plantes seront hydratées.

**Composants Requis**

Pour ce projet, nous avons besoin des composants suivants.

Il est certainement pratique d'acheter un kit complet, voici le lien :

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nom	
        - ÉLÉMENTS DANS CE KIT
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
    *   - :ref:`cpn_esp8266`
        - |link_esp8266_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_buy|
    *   - :ref:`cpn_dht11`
        - \-
    *   - :ref:`cpn_soil_moisture`
        - |link_soil_moisture_buy|
    *   - :ref:`cpn_l9110`
        - \-
    *   - :ref:`cpn_pump`
        - \-

**1. Construire le Circuit**

.. note::

    Le module ESP8266 nécessite un courant élevé pour fournir un environnement de fonctionnement stable, donc assurez-vous que la batterie 9V est branchée.

.. image:: img/wiring_6_plant_monitor_bb.png
    :width: 800

**2. Éditer le Tableau de Bord**

#. Les data streams créés dans les projets précédents doivent être conservés, et ils seront utilisés dans ce projet également.

#. Pour enregistrer l'humidité du sol, créez un autre **Datastream** de type **Virtual Pin** sur la page **Datastream**. Réglez le TYPE DE DONNÉES sur ``Integer`` et MIN et MAX sur ``0`` et ``1024``.

    .. image:: img/sp220610_155221.png

#. Maintenant, allez sur la page **Wed Dashboard**, faites glisser 2 widgets **Label** et réglez leurs data streams respectivement sur **V4** et **V5**; faites glisser 2 widgets **Gauge** et réglez leurs data streams pour afficher **V6** et **V7** respectivement; et enfin faites glisser un widget **Switch** et réglez son data stream sur **V0**.

    .. image:: img/sp220610_155350.png


**3. Exécutez le Code**

Ouvrez le fichier ``6.plant_monitoring.ino`` situé dans le dossier ``3in1-kit\iot_project\6.plant_monitoring``, ou copiez ce code dans **Arduino IDE**.

    .. note::

        * La ``DHT sensor library`` est utilisée ici, vous pouvez l'installer depuis le **Library Manager**.

            .. image:: ../img/lib_dht11.png

    .. raw:: html
        
        <iframe src=https://create.arduino.cc/editor/sunfounder01/f738bcb5-4ee2-475b-b683-759e6b2041b0/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Remplacez le ``Template ID``, ``Device Name`` et ``Auth Token`` par les vôtres. Vous devez également entrer le ``ssid`` et le ``mot de passe`` du WiFi que vous utilisez. Pour des tutoriels détaillés, veuillez vous référer à :ref:`connect_blynk`.
#. Après avoir sélectionné la bonne carte et le bon port, cliquez sur le bouton **Upoad**.

#. Ouvrez le moniteur série (réglez le débit en bauds sur 115200) et attendez qu'un message tel qu'une connexion réussie apparaisse.

    .. image:: img/2_ready.png

    .. note::

        Si le message ``ESP is not responding`` apparaît lorsque vous vous connectez, veuillez suivre ces étapes.

        * Assurez-vous que la batterie 9V est branchée.
        * Réinitialisez le module ESP8266 en connectant la broche RST à GND pendant 1 seconde, puis débranchez-la.
        * Appuyez sur le bouton de réinitialisation de la carte R3.

        Parfois, il peut être nécessaire de répéter l'opération ci-dessus 3 à 5 fois, veuillez être patient.

#. De retour sur Blynk, vous verrez la température actuelle, l'humidité, l'intensité lumineuse et l'humidité du sol. Vous pouvez laisser la pompe arroser les plantes si nécessaire en cliquant sur le widget Bouton de Contrôle.

    .. image:: img/sp220610_155350.png

#. Si vous souhaitez utiliser Blynk sur des appareils mobiles, veuillez vous référer à :ref:`blynk_mobile`.

    .. image:: img/mobile_plant.jpg

**Comment ça fonctionne ?**

Ce ``BLYNK_WRITE`` permet au widget **Switch** de Blynk de démarrer la pompe lorsqu'il est ON et de l'éteindre lorsqu'il est OFF.

.. code-block:: arduino

    BLYNK_WRITE(V0)
    {
        if(param.asInt()==1){
            digitalWrite(pumpA,HIGH);
        }else{
            digitalWrite(pumpA,LOW); 
        }
    }


Ces trois fonctions sont utilisées pour obtenir la température ambiante actuelle, l'humidité, l'intensité lumineuse et l'humidité du sol.

.. code-block:: arduino

    int readMoisture(){
        return analogRead(moisturePin);
    }

    int readLight(){
        return analogRead(lightPin);
    }

    bool readDHT() {

        // Reading temperature or humidity takes about 250 milliseconds!
        // Sensor readings may also be up to 2 seconds 'old' (it's a very slow sensor)
        humidity = dht.readHumidity();
        // Read temperature as Celsius (the default)
        temperature = dht.readTemperature();

        // Check if any reads failed and exit early (to try again).
        if (isnan(humidity) || isnan(temperature)) {
            Serial.println("Failed to read from DHT sensor!");
            return false;
        }
        return true;
    }

Avec le ``Timer`` de Blynk, la température ambiante, l'humidité, l'intensité lumineuse et l'humidité du sol sont obtenues chaque seconde et envoyées au data stream sur le **Blynk Cloud**, à partir duquel les widgets affichent les données.

.. code-block:: arduino

    void myTimerEvent()
    {
        bool chk = readDHT();
        int light = readLight();
        int moisture = readMoisture();
        if(chk){
            Blynk.virtualWrite(V4,humidity);
            Blynk.virtualWrite(V5,temperature);
        }
        Blynk.virtualWrite(V6,light);
        Blynk.virtualWrite(V7,moisture);
    }
