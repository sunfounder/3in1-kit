.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Explorez en profondeur Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Assistance d'experts** : Résolvez les problèmes après-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits.
    - **Réductions spéciales** : Profitez de remises exclusives sur nos derniers produits.
    - **Promotions et concours festifs** : Participez à des concours et des promotions spéciales.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _ar_analog_read:

4. Lecture analogique
==========================

L'Arduino peut lire les capteurs analogiques connectés via les broches analogiques.

La carte R4 contient un convertisseur analogique-numérique à plusieurs canaux, 10 bits. Cela signifie qu'elle convertit la tension d'entrée entre 0 et la tension d'alimentation (5V ou 3,3V) en une valeur entière comprise entre 0 et 1023.

Vous avez besoin de la fonction ``analogRead(pin)`` pour lire la valeur de la broche analogique.

* ``analogRead(pin)`` : Lit la valeur de la broche analogique spécifiée.

   **Syntaxe**
      analogRead(pin)

   **Paramètres**
        * ``pin`` : le nom de la broche d'entrée analogique à lire (A0 à A5).

   **Retourne**
      Une valeur entre 0 et 1023. Type de données : int.


**Exemple de lecture analogique**

.. code-block:: arduino

   int analogPin = A0; // appareil connecté à la broche analogique A0
                     // les bornes extérieures mènent à la masse et au +5V
   int val = 0;  // variable pour stocker la valeur lue

   void setup() {
      Serial.begin(9600);           //  initialisation du port série
   }

   void loop() {
      val = analogRead(analogPin);  // lire la broche d'entrée
      Serial.println(val);          // afficher la valeur pour le débogage
   }


**Notes et avertissements**

* Les broches analogiques sont A0-A5.
* Il n'est pas nécessaire d'appeler ``pinMode()`` avant d'utiliser une broche analogique, mais si la broche a été précédemment définie sur ``OUTPUT``, la fonction ``analogRead()`` ne fonctionnera pas correctement. Dans ce cas, vous devez appeler ``pinMode()`` pour la définir à nouveau sur ``INPUT``.

**Composants associés**

Vous trouverez ci-dessous les composants associés. Vous pouvez cliquer pour apprendre à les utiliser.

.. toctree::
    :maxdepth: 2

    ar_turn_the_knob
    ar_photoresistor
    ar_joystick
    ar_moisture
    ar_thermistor