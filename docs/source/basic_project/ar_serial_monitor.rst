.. note::

    Bonjour et bienvenue dans la Communauté Facebook des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez [|link_sf_facebook|] et rejoignez-nous aujourd'hui !

.. _ard_serial_monitor:

3.0 Moniteur Série
=============================

Dans l'IDE Arduino, il y a un moniteur série qui vous permet d'envoyer des messages de votre ordinateur vers la carte Arduino (via USB) et également de recevoir des messages de l'Arduino.

Dans ce projet, nous apprendrons donc à recevoir des données de la carte Arduino.

.. note::

    Sur les Uno, Nano, Mini et Mega, les broches 0 et 1 sont utilisées pour la communication avec l'ordinateur. Connecter quelque chose à ces broches peut interférer avec cette communication, y compris provoquer des échecs de téléchargement vers la carte.


**Utilisation du Moniteur Série**

1. Ouvrez l'IDE Arduino et collez le code suivant.

    .. code-block:: arduino

        // the setup routine runs once when you press reset:
        void setup() {
            // initialize serial communication at 9600 bits per second:
            Serial.begin(9600);
        }

        // the loop routine runs over and over again forever:
        void loop() {
            int number = 100;
            Serial.println(number);
            Serial.println("Hello world");
            delay(100);         // delay in between reads for stability
        }

   * `Serial.begin() <https://www.arduino.cc/reference/en/language/functions/communication/serial/begin/>`_ : Définit le débit de données en bits par seconde (baud) pour la transmission de données série, ici réglé sur 9600.
   * `Serial.println() <https://www.arduino.cc/reference/en/language/functions/communication/serial/println/>`_.

2. Sélectionnez la bonne carte et le bon port pour télécharger le code.
3. Dans la barre d'outils, cliquez sur l'icône de la loupe pour activer le Moniteur Série.

.. image:: img/serial1.png
    :align: center

4. Voici le Moniteur Série.

.. image:: img/serial2.png
    :align: center

* **1** : Option pour choisir entre défilement automatique ou non.
* **2** : Option pour afficher l'horodatage avant les données affichées sur le Moniteur Série.
* **3** : Sélection de fin, sélectionnez les caractères de fin ajoutés aux données envoyées à l'Arduino. Les sélections comprennent :

        * **No line Ending** envoie juste ce que vous tapez ; 
        * **Newline** est ``\n`` et envoie un code ASCII de nouvelle ligne après ce que vous tapez ;
        * **Carriage Return** est ``\r``, qui enverra un caractère de retour chariot ASCII après ce que vous tapez ; 
        * **Both NL & CR** est ``\r\n`` qui enverra à la fois un retour chariot et un caractère de nouvelle ligne après ce que vous tapez.
* **4** : Sélectionnez la vitesse de communication entre la carte Arduino et le PC. Cette valeur DOIT être la même que celle définie dans ``Serial.begin()``.
* **5** : Effacez tout le texte sur la console de sortie.
* **6** : Une zone de texte pour envoyer des caractères à la carte Arduino, voir :ref:`ar_serial_read` pour un tutoriel.


