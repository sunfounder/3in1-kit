.. note::

    Bonjour et bienvenue dans la Communauté Facebook des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez [|link_sf_facebook|] et rejoignez-nous aujourd'hui !

.. _iot_home:

5. Surveillance de l'Environnement Domestique
==================================================

Dans ce chapitre, nous utiliserons Blynk pour créer un moniteur d'environnement domestique.
Vous pouvez mesurer la température, l'humidité et l'intensité lumineuse d'une pièce à l'aide du DHT11 et d'une photorésistance.
En envoyant ces valeurs à Blynk, vous pourrez connaître l'environnement de votre maison via Internet.

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

**1. Construire le Circuit**

.. note::

    Le module ESP8266 nécessite un courant élevé pour fournir un environnement de fonctionnement stable, donc assurez-vous que la batterie 9V est branchée.

.. image:: img/wiring_dht11.jpg

**2. Éditer le Tableau de Bord**


#. Pour enregistrer les valeurs d'humidité, créez un **Datastream** de type **Virtual Pin** sur la page **Datastream**. Réglez le TYPE DE DONNÉES sur **Double** et MIN et MAX sur **0** et **100**. Réglez également les unités sur **Percentage, %**.

    .. image:: img/sp220610_145748.png

#. Ensuite, créez un **Datastream** de type **Virtual Pin** pour enregistrer la température. Réglez le TYPE DE DONNÉES sur ``Double``, MIN et MAX sur ``-30`` et ``50``, et les unités sur **Celsius, °C**.

    .. image:: img/sp220610_145811.png

#. Créez également un **Datastream** de type **Virtual Pin** pour enregistrer l'intensité lumineuse. Utilisez le type de données par défaut - **Integer**, avec MIN et MAX réglés sur ``0`` et ``1024``.

    .. image:: img/sp220610_145834.png

#. Allez sur la page **Wed Dashboard**, faites glisser deux widgets **Label** et réglez leurs data streams respectivement sur **V4** et **V5**, et faites glisser un widget **Gauge** et réglez le data stream sur **V6**. De plus, dans le réglage du widget, vous pouvez activer **Changer de couleur selon la valeur** et sélectionner la couleur appropriée pour rendre le widget plus attrayant et intuitif.

.. image:: img/sp220610_150400.png
    :align: center


**3. Exécutez le Code**

#. Ouvrez le fichier ``5.home_environment_monitoring.ino`` situé dans le dossier ``3in1-kit\iot_project\5.home_environment_monitoring``, ou copiez ce code dans **Arduino IDE**.

    .. note::

        * La ``DHT sensor library`` est utilisée ici, vous pouvez l'installer depuis le **Library Manager**.

            .. image:: ../img/lib_dht11.png

    .. raw:: html
        
        <iframe src=https://create.arduino.cc/editor/sunfounder01/4f0ad85e-8aff-4df9-99dd-c6741aed8219/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Remplacez le ``Template ID``, ``Device Name`` et ``Auth Token`` par les vôtres. Vous devez également entrer le ``ssid`` et le ``password`` du WiFi que vous utilisez. Pour des tutoriels détaillés, veuillez vous référer à :ref:`connect_blynk`.
#. Après avoir sélectionné la bonne carte et le bon port, cliquez sur le bouton **Upoad**.

#. Ouvrez le moniteur série (réglez le débit en bauds sur 115200) et attendez qu'un message tel qu'une connexion réussie apparaisse.

    .. image:: img/2_ready.png

    .. note::

        Si le message ``ESP is not responding`` apparaît lorsque vous vous connectez, veuillez suivre ces étapes.

        * Assurez-vous que la batterie 9V est branchée.
        * Réinitialisez le module ESP8266 en connectant la broche RST à GND pendant 1 seconde, puis débranchez-la.
        * Appuyez sur le bouton de réinitialisation de la carte R3.

        Parfois, il peut être nécessaire de répéter l'opération ci-dessus 3 à 5 fois, veuillez être patient.

#. Maintenant, vous verrez la température ambiante actuelle, l'humidité et l'intensité lumineuse sur Blynk.

    .. image:: img/sp220610_150400.png
        :align: center

#. Si vous souhaitez utiliser Blynk sur des appareils mobiles, veuillez vous référer à :ref:`blynk_mobile`.

    .. image:: img/mobile_home.jpg

**Comment ça fonctionne ?**

Ces deux fonctions sont utilisées pour obtenir la température, l'humidité et l'intensité lumineuse de la pièce.


.. code-block:: arduino

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


Avec le ``Timer`` de Blynk, la température ambiante, l'humidité et l'intensité lumineuse sont obtenues chaque seconde et envoyées au data stream sur le Blynk Cloud, à partir duquel les widgets affichent les données.

.. code-block:: arduino

    void myTimerEvent()
    {
        bool chk = readDHT();
        int light = readLight();
        if(chk){
            Blynk.virtualWrite(V4,humidity);
            Blynk.virtualWrite(V5,temperature);
        }
        Blynk.virtualWrite(V6,light);
    }