.. note:: 

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour perfectionner vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus exclusifs.
    - **Réductions spéciales** : Profitez de remises exclusives sur nos nouveaux produits.
    - **Promotions festives et cadeaux** : Participez à des promotions et des concours pendant les fêtes.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _iot_plant:

6. Surveillance des plantes
===============================

Le but de ce projet est de créer un système intelligent d'arrosage qui détecte la température actuelle, l'humidité, l'intensité lumineuse et l'humidité du sol, et affiche ces données sur Blynk.

Dès que vous activez le commutateur dans le Blynk Cloud, la pompe commence à fonctionner et les plantes sont arrosées.

**Composants requis**

Pour ce projet, nous avons besoin des composants suivants. 

Il est bien sûr pratique d'acheter un kit complet. Voici le lien : 

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nom	
        - ÉLÉMENTS DANS CE KIT
        - LIEN
    *   - Kit de démarrage 3 en 1
        - 380+
        - |link_3IN1_kit|

Vous pouvez également les acheter séparément à partir des liens ci-dessous.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUCTION DES COMPOSANTS
        - LIEN D'ACHAT

    *   - :ref:`cpn_uno`
        - \-
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

**1. Construire le circuit**

.. note::

    Le module ESP8266 nécessite un courant élevé pour assurer un environnement de fonctionnement stable. Assurez-vous que la batterie 9V est connectée.

.. image:: img/iot_6_bb.png
    :width: 800
    :align: center

**2. Modifier le tableau de bord**

#. Les flux de données créés dans les projets précédents doivent être sauvegardés, car ils seront également utilisés dans ce projet.

#. Pour enregistrer l'humidité du sol, créez un autre **Datastream** de type **Virtual Pin** sur la page **Datastream**. Réglez le TYPE DE DONNÉES sur ``Integer`` et les MIN et MAX sur ``0`` et ``1024``.

    .. image:: img/sp220610_155221.png

#. Accédez maintenant à la page **Web Dashboard**, faites glisser 2 widgets **Label** et réglez leurs flux de données sur **V4** et **V5** respectivement ; faites glisser 2 widgets **Gauge** et réglez leurs flux de données pour afficher **V6** et **V7** respectivement ; et enfin, faites glisser un widget **Switch** et réglez son flux de données sur **V0**.

    .. image:: img/sp220610_155350.png


**3. Exécuter le code**

Ouvrez le fichier ``6.plant_monitoring.ino`` situé dans le chemin ``3in1-kit\iot_project\6.plant_monitoring``, ou copiez ce code dans **Arduino IDE**.

    .. note::

            * La bibliothèque ``DHT sensor library`` est utilisée ici. Vous pouvez l'installer depuis le **Gestionnaire de Bibliothèque**.

                .. image:: ../img/lib_dht11.png


    .. raw:: html
        
        <iframe src=https://create.arduino.cc/editor/sunfounder01/f738bcb5-4ee2-475b-b683-759e6b2041b0/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Remplacez les valeurs ``Template ID``, ``Device Name``, et ``Auth Token`` par les vôtres. Entrez également le ``ssid`` et le ``password`` de votre réseau WiFi. Pour des tutoriels détaillés, reportez-vous à :ref:`connect_blynk`.
#. Après avoir sélectionné la carte et le port appropriés, cliquez sur le bouton **Téléverser**.

#. Ouvrez le Moniteur Série (réglez le débit en bauds à 115200) et attendez qu'un message de connexion réussie apparaisse.

    .. image:: img/2_ready.png

    .. note::

        Si le message ``ESP is not responding`` s'affiche lors de la connexion, suivez ces étapes.

        * Assurez-vous que la batterie 9V est branchée.
        * Réinitialisez le module ESP8266 en connectant la broche RST à GND pendant 1 seconde, puis débranchez-la.
        * Appuyez sur le bouton de réinitialisation sur la carte R4.

        Vous devrez peut-être répéter ces étapes 3 à 5 fois. Soyez patient.

#. Retournez sur Blynk, vous verrez la température, l'humidité, l'intensité lumineuse et l'humidité du sol actuelles. Vous pouvez activer la pompe pour arroser les plantes en cliquant sur le widget Bouton Contrôle.

    .. image:: img/sp220610_155350.png

#. Si vous souhaitez utiliser Blynk sur des appareils mobiles, reportez-vous à :ref:`blynk_mobile`.

    .. image:: img/mobile_plant.jpg

**Comment cela fonctionne-t-il ?**

Ce ``BLYNK_WRITE`` permet au widget **Switch** de Blynk d'activer la pompe lorsqu'il est activé et de la désactiver lorsqu'il est désactivé.

.. code-block:: arduino

    BLYNK_WRITE(V0)
    {
        if(param.asInt()==1){
            digitalWrite(pumpA,HIGH);
        }else{
            digitalWrite(pumpA,LOW); 
        }
    }

Ces trois fonctions permettent de mesurer la température ambiante, l'humidité, l'intensité lumineuse et l'humidité du sol.

.. code-block:: arduino

    int readMoisture(){
        return analogRead(moisturePin);
    }

    int readLight(){
        return analogRead(lightPin);
    }

    bool readDHT() {

        // La lecture de la température ou de l'humidité prend environ 250 millisecondes !
        // Les relevés du capteur peuvent également être vieux de 2 secondes (le capteur est très lent)
        humidity = dht.readHumidity();
        // Lire la température en Celsius (par défaut)
        temperature = dht.readTemperature();

        // Vérifiez si une lecture a échoué et quittez tôt (pour réessayer).
        if (isnan(humidity) || isnan(temperature)) {
            Serial.println("Failed to read from DHT sensor!");
            return false;
        }
        return true;
    }

Avec le ``Timer`` de Blynk, la température ambiante, l'humidité, l'intensité lumineuse et l'humidité du sol sont mesurées chaque seconde et envoyées au flux de données sur le **Blynk Cloud**, à partir duquel les widgets affichent les données.


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
