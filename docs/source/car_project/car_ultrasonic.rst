.. note::

    Bonjour et bienvenue dans la Communauté Facebook des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez [|link_sf_facebook|] et rejoignez-nous aujourd'hui !

.. _car_ultrasonic:

6. Jouer avec le module ultrasonique
=====================================

Dans le projet :ref:`car_ir_obstacle`, les 2 modules infrarouges d'évitement d'obstacles sont utilisés pour éviter les obstacles, mais la distance de détection du module d'évitement d'obstacle IR est courte, ce qui peut rendre la voiture trop tardive pour éviter les obstacles.

Dans ce projet, nous utilisons un module ultrasonique pour effectuer une détection à longue distance, afin que la voiture puisse détecter les obstacles à une distance plus éloignée et prendre une décision.

**Composants requis**

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
    *   - :ref:`cpn_l9110`
        - \-
    *   - :ref:`cpn_tt_motor`
        - \-
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|

**Câblage**

Un module de capteur ultrasonique est un instrument qui mesure la distance à un objet à l'aide d'ondes sonores ultrasoniques.
Il possède deux sondes. L'une est pour envoyer des ondes ultrasoniques et l'autre pour recevoir les ondes et transformer le temps d'envoi et de réception en une distance, détectant ainsi la distance entre l'appareil et un obstacle.

.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/qx9ZH-YnAkg?si=wfrsDrmGCPa2nYPD" title="Lecteur vidéo YouTube" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

Construisez maintenant le circuit selon le schéma suivant.

.. list-table:: 
    :header-rows: 1

    * - Ultrasonic Module
      - R3 Board
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

    * Ouvrez le fichier ``6.ultrasonic_module.ino`` situé dans le dossier ``3in1-kit\car_project\6.ultrasonic_module``.
    * Ou copiez ce code dans **Arduino IDE**.
    
    * Ou téléchargez le code via `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/ae97f966-9d72-40e6-aa9f-e0767ddf5bd5/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Après le téléchargement réussi du code, orientez la voiture vers un mur. Si la distance est trop grande, elle avancera ; si elle est trop proche, elle reculera ; si elle est à une distance sûre, elle s'arrêtera.

**Comment ça fonctionne ?**

Ce projet se base sur la distance lue par le module ultrasonique pour faire bouger la voiture en conséquence.

#. Ajoutez la définition de pin pour le module ultrasonique, ``trigPin`` est utilisé pour transmettre l'onde ultrasonique, réglez-le sur ``OUTPUT`` ; ``echoPin`` est réglé sur ``INPUT`` pour recevoir l'onde ultrasonique.

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

#. Lisez d'abord la valeur de distance obtenue à partir du module ultrasonique, si la distance est supérieure à 25, laissez la voiture avancer ; si la distance est entre 2-10cm, laissez la voiture reculer, sinon (entre 10~25) arrêtez.

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

    L'émetteur du module ultrasonique transmet un signal carré de 10us toutes les 2us, et le récepteur reçoit un signal de niveau haut s'il y a un obstacle dans la portée. Utilisez la fonction ``pulseIn()`` pour enregistrer le temps de l'envoi à la réception, divisez par la vitesse du son 340m/s, puis divisez par 2, le résultat est la distance entre ce module et l'obstacle en unités : cm.

    .. code-block:: arduino

        float readSensorData() {
            digitalWrite(trigPin, LOW);
            delayMicroseconds(2);
            digitalWrite(trigPin, HIGH);
            delayMicroseconds(10);
            digitalWrite(trigPin, LOW);
            float distance = pulseIn(echoPin, HIGH) / 58.00; //Equivalent to (340m/s*1us)/2
            return distance;
        }

* `pulseIn(pin, value) <https://www.arduino.cc/reference/en/language/functions/advanced-io/pulsein/>`_

    * ``pin`` : le numéro du pin Arduino sur lequel vous voulez lire l'impulsion. Types de données autorisés : int.
    * ``value`` : type d'impulsion à lire : soit HIGH, soit LOW. Types de données autorisés : int.

    Lit une impulsion (soit HIGH, soit LOW) sur un pin. Par exemple, si la valeur est HIGH, ``pulseIn()`` attend que le pin passe de LOW à HIGH, commence à chronométrer, puis attend que le pin redevienne LOW et arrête le chronométrage.

