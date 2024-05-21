.. note::

    Bonjour et bienvenue dans la Communauté Facebook des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez [|link_sf_facebook|] et rejoignez-nous aujourd'hui !

.. _ar_digital_read:

3. Lecture Numérique
=======================

Les capteurs capturent les informations du monde réel, qui sont ensuite communiquées à la carte principale via des broches (certaines numériques, d'autres analogiques) afin que l'ordinateur puisse connaître la réalité de la situation.

Ainsi, la carte Arduino peut connaître l'état de fonctionnement des capteurs numériques en lisant la valeur des broches numériques comme les boutons, le module d'évitement d'obstacle IR.


Voici les fonctions requises.

* ``pinMode(pin, mode)`` : Configure la broche spécifique comme ``INPUT`` (entrée) ou ``OUTPUT`` (sortie), ici elle doit être réglée sur ``INPUT``.

   **Syntaxe**
      pinMode(pin, mode)

   **Paramètres**
    * ``pin`` : le numéro de broche Arduino à configurer.
    * ``mode`` : INPUT, OUTPUT, ou INPUT_PULLUP.



* ``digitalRead(pin)`` : Lit la valeur (état de niveau) de la broche numérique spécifiée.

   **Syntaxe**
      digitalRead(pin)

   **Paramètres**
    * ``pin`` : le numéro de broche Arduino que vous souhaitez lire

   **Retours**
      HIGH ou LOW


**Exemple de Lecture Numérique**

.. code-block:: arduino

   int ledPin = 13;  // LED connected to digital pin 13
   int inPin = 7;    // pushbutton connected to digital pin 7
   int val = 0;      // variable to store the read value

   void setup() {
      pinMode(ledPin, OUTPUT);  // sets the digital pin 13 as output
      pinMode(inPin, INPUT);    // sets the digital pin 7 as input
   }

   void loop() {
      val = digitalRead(inPin);   // read the input pin
      digitalWrite(ledPin, val);  // sets the LED to the button's value
   }


**Notes et Avertissements**

1. Pull Up & Pull Down.

    ``digitalRead()`` peut produire des valeurs aléatoires et indéterminées si la broche ne reçoit pas un signal de niveau. Ainsi, diriger les broches d'entrée vers un état connu peut rendre le projet plus fiable.
    Lors de l'utilisation d'un composant d'entrée tel qu'un bouton, il est généralement nécessaire de connecter une résistance de pull-up ou pull-down en parallèle à la broche d'entrée numérique.

    Outre la connexion d'une résistance de pull-up, vous pouvez également régler le mode de la broche sur ``INPUT_PULLUP`` dans le code, par exemple ``pinMode(pin,INPUT_PULLUP)``. Dans ce cas, la broche accédera à la résistance de pull-up intégrée de l'Atmega via le logiciel, et cela aura le même effet que la connexion d'une résistance de pull-up.

2. À propos de la Pin13.

    Toutes les broches numériques (1-13) sur la carte R3 peuvent être utilisées comme ``digitalRead()``.
    Cependant, la broche numérique 13 est plus difficile à utiliser comme entrée numérique que les autres broches numériques.
    Car elle connecte une LED et une résistance, elle est soudée sur la plupart des cartes.
    Si vous activez sa résistance de pull-up interne de 20k, elle se maintiendra autour de 1,7V au lieu des 5V attendus car la LED embarquée et la résistance en série tirent le niveau de tension vers le bas, ce qui signifie qu'elle retourne toujours LOW. Si vous devez utiliser la pin 13 comme une entrée numérique, réglez son ``pinMode()`` sur INPUT et utilisez une résistance de pull-down externe.

3. Broches analogiques.

    Si les broches numériques ne sont pas suffisantes, les broches analogiques (A0-A5) peuvent également être utilisées comme broches numériques.
    Il faut les régler sur INPUT avec ``pinMode(pin,mode)``.


**Composants Associés**

Ci-dessous les composants associés, vous pouvez cliquer pour apprendre à les utiliser.

.. toctree::
    :maxdepth: 2

    ar_serial_monitor
    ar_button
    ar_reed
    ar_detect_the_obstacle
    ar_detect_the_line



