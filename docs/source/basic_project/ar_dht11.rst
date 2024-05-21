.. note::

    Bonjour et bienvenue dans la Communauté Facebook des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez [|link_sf_facebook|] et rejoignez-nous aujourd'hui !

.. _ar_dht11:


5.11.3 Température - Humidité
=============================

L'humidité et la température sont étroitement liées, de la quantité physique elle-même à la vie quotidienne des gens.
La température et l'humidité de l'environnement humain affectent directement la fonction de thermorégulation et l'effet de transfert de chaleur du corps humain.
Cela peut également influencer l'activité de pensée et l'état mental, affectant ainsi l'efficacité de nos études et de notre travail.

La température est l'une des sept quantités physiques de base dans le Système international d'unités, utilisée pour mesurer le degré de chaud et de froid d'un objet.
Le degré Celsius est l'une des échelles de température les plus utilisées dans le monde, exprimée par le symbole "℃".

L'humidité est la concentration de vapeur d'eau présente dans l'air.
L'humidité relative de l'air est couramment utilisée dans la vie quotidienne et est exprimée en %HR. L'humidité relative est étroitement liée à la température.
Pour un certain volume de gaz scellé, plus la température est élevée, plus l'humidité relative est basse, et inversement.

.. image:: img/Dht11.png

Le dht11, un capteur numérique de température et d'humidité, est fourni dans ce kit. Il utilise un capteur d'humidité capacitif et un thermistor pour mesurer l'air ambiant et produit un signal numérique sur la broche de données.

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
    *   - :ref:`cpn_dht11`
        - \-


**Schéma**

.. image:: img/circuit_7.3_dht11.png

**Câblage**

.. image:: img/dht11_bb.jpg

**Code**

.. note::

    * Ouvrez le fichier ``5.11.temperature_humidity.ino`` situé dans le dossier ``3in1-kit\basic_project\5.11.temperature_humidity``.
    * Ou copiez ce code dans **Arduino IDE**.
    * La bibliothèque ``DHT sensor library`` est utilisée ici, vous pouvez l'installer depuis le **Library Manager**.

        .. image:: ../img/lib_dht11.png

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/c5b4c902-f39d-45a6-9a17-1308056041a8/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Après le téléversement réussi du code, vous verrez que le moniteur série affiche en continu la température et l'humidité. Au fur et à mesure que le programme fonctionne de manière stable, ces deux valeurs deviendront de plus en plus précises.

**Comment ça fonctionne ?**

#.  Inclut la bibliothèque ``DHT.h``, qui offre des fonctions pour interagir avec les capteurs DHT. Ensuite, définit le pin et le type pour le capteur DHT.

    .. code-block:: arduino

        #include "DHT.h"

        #define DHTPIN 11  // Set the pin connected to the DHT11 data pin
        #define DHTTYPE DHT11 // DHT 11 

        DHT dht(DHTPIN, DHTTYPE);

#. Initialise la communication série à une vitesse de 115200 bauds et initialise le capteur DHT.

    .. code-block:: arduino

        void setup() {
            Serial.begin(115200);
            Serial.println("DHT11 test!");
            dht.begin();
        }

#. Dans la fonction ``loop()``, lire les valeurs de température et d'humidité du capteur DHT11, et les afficher sur le moniteur série.

    .. code-block:: arduino

        void loop() {
            // Wait a few seconds between measurements.
            delay(2000);

            // Reading temperature or humidity takes about 250 milliseconds!
            // Sensor readings may also be up to 2 seconds 'old' (it's a very slow sensor)
            float humidity = dht.readHumidity();
            // Read temperature as Celsius (the default)
            float temperture = dht.readTemperature();

            // Check if any reads failed and exit early (to try again).
            if (isnan(humidity) || isnan(temperture)) {
                Serial.println("Failed to read from DHT sensor!");
                return;
            }
            // Print the humidity and temperature
            Serial.print("Humidity: "); 
            Serial.print(humidity);
            Serial.print(" %\t");
            Serial.print("Temperature: "); 
            Serial.print(temperture);
            Serial.println(" *C");
        }

    * La fonction ``dht.readHumidity()`` est appelée pour lire la valeur d'humidité du capteur DHT.
    * La fonction ``dht.readTemperature()`` est appelée pour lire la valeur de température du capteur DHT.
    * La fonction ``isnan()`` est utilisée pour vérifier si les lectures sont valides. Si la valeur d'humidité ou de température est NaN (non un nombre), cela indique une lecture échouée du capteur, et un message d'erreur est imprimé.

