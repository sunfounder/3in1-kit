.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions festives et cadeaux** : Participez à des promotions et à des cadeaux festifs.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _ard_serial_monitor:

3.0 Moniteur Série
=============================

Dans l'IDE Arduino, il existe un moniteur série qui vous permet d'envoyer des messages de votre ordinateur à la carte Arduino (via USB) et également de recevoir des messages de l'Arduino.

Dans ce projet, nous allons apprendre à recevoir des données de la carte Arduino.

.. note::

    Sur les cartes Uno, Nano, Mini et Mega, les broches 0 et 1 sont utilisées pour la communication avec l'ordinateur. Toute connexion à ces broches peut perturber cette communication, y compris entraîner l'échec des téléversements vers la carte.


**Utilisation du Moniteur Série**

1. Ouvrez l'IDE Arduino, et collez le code suivant :

    .. code-block:: arduino

        // La routine setup s'exécute une fois au démarrage ou après un reset :
        void setup() {
            // initialise la communication série à 9600 bits par seconde :
            Serial.begin(9600);
        }

        // La routine loop s'exécute en continu :
        void loop() {
            int number = 100;
            Serial.println(number);
            Serial.println("Hello world");
            delay(100);         // délai entre les lectures pour la stabilité
        }

   * `Serial.begin() <https://www.arduino.cc/reference/en/language/functions/communication/serial/begin/>`_ : Définit le débit en bits par seconde (baud) pour la transmission de données série, ici défini à 9600.
   * `Serial.println() <https://www.arduino.cc/reference/en/language/functions/communication/serial/println/>`_ : Envoie des données au port série sous forme de texte ASCII lisible suivi d'un caractère de retour chariot (ASCII 13, ou '\r') et d'un saut de ligne (ASCII 10, ou '\n'). Cette commande accepte les mêmes formats que `Serial.print() <https://www.arduino.cc/reference/en/language/functions/communication/serial/print/>`_.

2. Sélectionnez la carte et le port corrects pour téléverser le code.
3. Dans la barre d'outils, cliquez sur l'icône en forme de loupe pour activer le Moniteur Série.

.. image:: img/serial1.png
    :align: center

4. Voici le Moniteur Série.

.. image:: img/serial2.png
    :align: center

* **1** : Option pour sélectionner le défilement automatique ou non.
* **2** : Option pour afficher un horodatage avant les données affichées sur le Moniteur Série.
* **3** : Choix de terminaison, sélection des caractères de fin ajoutés aux données envoyées à l'Arduino. Les choix incluent :

        * **Pas de fin de ligne** : envoie uniquement ce que vous tapez ;
        * **Nouvelle ligne** est ``\n`` et envoie un code ASCII de nouvelle ligne après ce que vous tapez ;
        * **Retour chariot** est ``\r``, qui envoie un caractère ASCII de retour chariot après ce que vous tapez ;
        * **NL et CR** est ``\r\n``, qui envoie à la fois un retour chariot et un saut de ligne après ce que vous tapez.

* **4** : Sélectionnez la vitesse de communication entre la carte Arduino et le PC. Cette valeur DOIT être identique à celle définie dans ``Serial.begin()``.
* **5** : Efface tout le texte de la console de sortie.
* **6** : Une zone de texte pour envoyer des caractères à la carte Arduino, voir :ref:`ar_serial_read` pour un tutoriel.
