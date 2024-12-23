.. note:: 

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes post-vente et techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprenez & partagez** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces et aperçus de nouveaux produits.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _ar_dht11:

5.11.3 Température - Humidité
=======================================

L'humidité et la température sont étroitement liées, tant dans leur nature physique que 
dans leur impact sur la vie quotidienne. La température et l'humidité de l'environnement 
affectent directement la fonction thermorégulatrice et les échanges de chaleur du corps 
humain, influençant ainsi l'activité mentale, l'état d'esprit et, par conséquent, 
l'efficacité de nos études et de notre travail.

La température est l'une des sept grandeurs fondamentales du Système international d'unités, 
utilisée pour mesurer le degré de chaleur ou de froid d'un objet. La température en degrés 
Celsius, exprimée par le symbole "℃", est largement utilisée dans le monde.

L'humidité désigne la concentration de vapeur d'eau présente dans l'air. L'humidité relative 
de l'air est souvent utilisée au quotidien et s'exprime en %HR. Elle est étroitement liée à la température : pour un volume de gaz fermé, une température plus élevée entraîne une humidité relative plus faible, tandis qu'une température plus basse augmente l'humidité relative.

.. image:: img/Dht11.png

Le DHT11, un capteur numérique de température et d'humidité, est inclus dans ce kit. Il utilise un capteur d'humidité capacitif et une thermistance pour mesurer l'air ambiant et envoie un signal numérique sur sa broche de données.

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
    *   - :ref:`cpn_dht11`
        - \-

**Schéma**

.. image:: img/circuit_7.3_dht11.png

**Câblage**

.. image:: img/5.11_dht11_bb.png

**Code**

.. note::

    * Ouvrez le fichier ``5.11.temperature_humidity.ino`` sous le chemin ``3in1-kit\learning_project\5.11.temperature_humidity``.
    * Ou copiez ce code dans **Arduino IDE**.
    * La bibliothèque ``DHT sensor library`` est utilisée ici. Vous pouvez l'installer via le **Gestionnaire de bibliothèques**.

        .. image:: ../img/lib_dht11.png

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/c5b4c902-f39d-45a6-9a17-1308056041a8/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Après avoir téléversé le code, vous verrez le moniteur série afficher en continu la température et l'humidité. À mesure que le programme se stabilise, ces deux valeurs deviendront de plus en plus précises.

**Comment ça fonctionne ?**

#. Inclure la bibliothèque ``DHT.h`` qui fournit les fonctions nécessaires pour interagir avec les capteurs DHT. Ensuite, configurez la broche et le type de capteur.

    .. code-block:: arduino

        #include "DHT.h"

        #define DHTPIN 11  // Définir la broche connectée à la broche de données du DHT11
        #define DHTTYPE DHT11 // DHT 11 

        DHT dht(DHTPIN, DHTTYPE);

#. Initialiser la communication série à un débit de 115200 bauds et le capteur DHT.

    .. code-block:: arduino

        void setup() {
            Serial.begin(115200);
            Serial.println("DHT11 test!");
            dht.begin();
        }

#. Dans la fonction ``loop()``, lire les valeurs de température et d'humidité du capteur DHT11 et les afficher sur le moniteur série.

    .. code-block:: arduino

        void loop() {
            // Attendre quelques secondes entre chaque mesure.
            delay(2000);

            // La lecture de la température ou de l'humidité prend environ 250 millisecondes.
            float humidity = dht.readHumidity();
            // Lire la température en Celsius (par défaut)
            float temperture = dht.readTemperature();

            // Vérifier si des lectures ont échoué et sortir immédiatement (pour réessayer plus tard).
            if (isnan(humidity) || isnan(temperture)) {
                Serial.println("Failed to read from DHT sensor!");
                return;
            }
            // Afficher l'humidité et la température
            Serial.print("Humidity: "); 
            Serial.print(humidity);
            Serial.print(" %\t");
            Serial.print("Temperature: "); 
            Serial.print(temperture);
            Serial.println(" *C");
        }

    * La fonction ``dht.readHumidity()`` est utilisée pour lire la valeur d'humidité du capteur DHT.
    * La fonction ``dht.readTemperature()`` est utilisée pour lire la valeur de température du capteur DHT.
    * La fonction ``isnan()`` vérifie si les lectures sont valides. Si l'humidité ou la température est NaN (non défini), cela indique une lecture défaillante, et un message d'erreur est affiché.
