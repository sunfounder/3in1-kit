.. note:: 

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez plus profondément dans Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprenez et partagez** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aperçus exclusifs.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et promotions de vacances.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _car_ultrasonic:

6. Jouer avec le module ultrason
===================================

Dans le projet :ref:`car_ir_obstacle`, les deux modules de détection d'obstacles infrarouges sont utilisés pour éviter les obstacles, mais leur portée de détection est limitée, ce qui peut rendre l'évitement des obstacles tardif.

Dans ce projet, nous utilisons un module ultrason pour effectuer une détection à longue distance, permettant ainsi à la voiture de détecter les obstacles à une distance plus grande et de prendre une décision appropriée.

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
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_l9110`
        - \-
    *   - :ref:`cpn_tt_motor`
        - \-
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|

**Câblage**

Un module capteur ultrason est un instrument qui mesure la distance d'un objet en utilisant des ondes sonores ultrasoniques. 
Il possède deux sondes : une pour émettre les ondes ultrasoniques et une autre pour les recevoir, transformant ainsi le temps d'envoi et de réception en une distance, détectant ainsi la distance entre l'appareil et un obstacle.

Construisez maintenant le circuit selon le schéma suivant.

.. list-table:: 
    :header-rows: 1

    * - Module Ultrason
      - Carte R4
    * - Vcc
      - 5V
    * - Trig
      - 3
    * - Echo
      - 4
    * - Gnd
      - GND

.. image:: img/car_6.png
    :width: 800

**Code**

.. note::

    * Ouvrez le fichier ``6.ultrasonic_module.ino`` dans le chemin ``3in1-kit\car_project\6.ultrasonic_module``.
    * Ou copiez ce code dans **Arduino IDE**.
    * Ou téléchargez le code via l'`Éditeur Web Arduino <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/ae97f966-9d72-40e6-aa9f-e0767ddf5bd5/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Une fois le code téléchargé avec succès, dirigez la voiture vers un mur. Si la distance est trop grande, elle avancera ; si elle est trop proche, elle reculera ; si elle est à une distance sécurisée, elle s'arrêtera.

**Comment cela fonctionne-t-il ?**

Ce projet repose sur la distance lue par le module ultrason pour faire bouger la voiture en conséquence.

#. Ajoutez la définition des broches pour le module ultrason : ``trigPin`` est utilisé pour transmettre les ondes ultrasoniques, donc réglez-le sur ``OUTPUT`` ; ``echoPin`` est réglé sur ``INPUT`` pour recevoir les ondes ultrasoniques.

    .. code-block:: arduino

        ...
        const int trigPin = 3;
        const int echoPin = 4;

        void setup() {
        ...

        //ultrasonic
            pinMode(echoPin, INPUT);
            pinMode(trigPin, OUTPUT);
        }

#. Lisez d'abord la valeur de distance obtenue à partir du module ultrasonique. Si la distance est supérieure à 25 cm, laissez la voiture avancer ; si la distance est comprise entre 2 et 10 cm, laissez la voiture reculer, sinon (entre 10 et 25 cm), arrêtez-la.

    .. code-block:: arduino

        void loop() {
            float distance = readSensorData();
            if (distance > 25) {
                moveForward(200);
            }
            else if (distance < 10 && distance > 2) {
                moveBackward(200);
            } else {
                stopMove();
            }
        }

#. À propos de la fonction ``readSensorData()``.

    L'émetteur du module ultrasonique transmet un signal d'onde carrée de 10 µs toutes les 2 µs, et le récepteur reçoit un signal de niveau haut s'il y a un obstacle dans la portée. Utilisez la fonction ``pulseIn()`` pour enregistrer le temps entre l'envoi et la réception, divisez par la vitesse du son (340 m/s), puis divisez encore par 2. Le résultat est la distance entre ce module et l'obstacle, en cm.

    .. code-block:: arduino

        float readSensorData() {
            digitalWrite(trigPin, LOW);
            delayMicroseconds(2);
            digitalWrite(trigPin, HIGH);
            delayMicroseconds(10);
            digitalWrite(trigPin, LOW);
            float distance = pulseIn(echoPin, HIGH) / 58.00; // Équivalent à (340m/s*1µs)/2
            return distance;
        }

* `pulseIn(pin, value) <https://www.arduino.cc/reference/en/language/functions/advanced-io/pulsein/>`_

    * ``pin`` : le numéro de la broche Arduino sur laquelle vous souhaitez lire l'impulsion. Types de données autorisés : int.
    * ``value`` : type d'impulsion à lire : soit HIGH, soit LOW. Types de données autorisés : int.

    Lit une impulsion (soit HIGH, soit LOW) sur une broche. Par exemple, si la valeur est HIGH, ``pulseIn()`` attend que la broche passe de LOW à HIGH, commence le chronométrage, puis attend que la broche passe à LOW et arrête le chronométrage.
