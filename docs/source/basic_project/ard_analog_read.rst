.. note::

    Bonjour et bienvenue dans la Communauté Facebook des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez [|link_sf_facebook|] et rejoignez-nous aujourd'hui !

.. _ar_analog_read:

4. Lecture Analogique
======================

L'Arduino peut lire les capteurs analogiques connectés via les broches analogiques.

La carte R3 contient un convertisseur analogique-numérique multicanal de 10 bits. Cela signifie qu'elle mappe la tension d'entrée entre 0 et la tension de fonctionnement (5V ou 3.3V) en une valeur entière entre 0 et 1023.

Vous avez besoin de la fonction ``analogRead(pin)`` pour lire la valeur de la broche analogique.

* ``analogRead(pin)`` : Lit la valeur de la broche analogique spécifiée.

   **Syntaxe**
      analogRead(pin)

   **Paramètres**
        * ``pin`` : le nom de la broche d'entrée analogique à lire (de A0 à A5).

   **Retours**
      0-1023. Type de données : int.


**Exemple de Lecture Analogique**

.. code-block:: arduino

   int analogPin = A0; // device connected to analog pin A0
                     // outside leads to ground and +5V
   int val = 0;  // variable to store the value read

   void setup() {
      Serial.begin(9600);           //  setup serial
   }

   void loop() {
      val = analogRead(analogPin);  // read the input pin
      Serial.println(val);          // debug value
   }


**Notes et Avertissements**

* Les broches analogiques sont A0-A5.
* Vous n'avez pas besoin d'appeler ``pinMode()`` avant d'appeler la broche analogique, mais si la broche était précédemment réglée sur ``OUTPUT``, la fonction ``analogRead()`` ne fonctionnera pas correctement. Dans ce cas, vous devez appeler ``pinMode()`` pour la remettre en ``INTPUT``.

**Composants Associés**

Ci-dessous les composants associés, vous pouvez cliquer pour apprendre à les utiliser.

.. toctree::
    :maxdepth: 2

    ar_turn_the_knob
    ar_photoresistor
    ar_joystick
    ar_moisture
    ar_thermistor
