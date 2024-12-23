.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Explorez en profondeur Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Assistance d'experts** : Résolvez les problèmes après-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits.
    - **Réductions spéciales** : Profitez de remises exclusives sur nos derniers produits.
    - **Promotions et concours festifs** : Participez à des concours et des promotions spéciales.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _ar_digital_read:

3. Lecture Numérique
========================

Les capteurs capturent des informations du monde réel, qui sont ensuite communiquées à la carte principale via des broches (certaines numériques, d'autres analogiques) pour que l'ordinateur puisse connaître l'état réel de la situation.

Ainsi, la carte Arduino peut connaître l'état de fonctionnement des capteurs numériques en lisant la valeur des broches numériques, comme les boutons ou le module d'évitement d'obstacles IR.


Voici les fonctions nécessaires.

* ``pinMode(pin, mode)`` : Configurez la broche spécifique comme ``INPUT`` ou ``OUTPUT`` ; ici, elle doit être définie comme ``INPUT``.

   **Syntaxe**
      pinMode(pin, mode)

   **Paramètres**
    * ``pin`` : le numéro de la broche Arduino à configurer.
    * ``mode`` : INPUT, OUTPUT ou INPUT_PULLUP.


* ``digitalRead(pin)`` : Lit la valeur (état du niveau) de la broche numérique spécifiée.

   **Syntaxe**
      digitalRead(pin)

   **Paramètres**
    * ``pin`` : le numéro de la broche Arduino à lire.

   **Retourne**
      HIGH ou LOW.


**Exemple de Lecture Numérique**

.. code-block:: arduino

   int ledPin = 13;  // LED connectée à la broche numérique 13
   int inPin = 7;    // bouton poussoir connecté à la broche numérique 7
   int val = 0;      // variable pour stocker la valeur lue

   void setup() {
      pinMode(ledPin, OUTPUT);  // configure la broche numérique 13 comme sortie
      pinMode(inPin, INPUT);    // configure la broche numérique 7 comme entrée
   }

   void loop() {
      val = digitalRead(inPin);   // lit la broche d'entrée
      digitalWrite(ledPin, val);  // ajuste la LED selon la valeur du bouton
   }


**Notes et Avertissements**

1. Résistances Pull-Up & Pull-Down.

    ``digitalRead()`` peut produire des valeurs aléatoires ou indéterminées si la broche ne reçoit pas de signal de niveau. Diriger les broches d'entrée vers un état connu peut rendre le projet plus fiable. 
    Lors de l'utilisation d'un composant d'entrée tel qu'un bouton, il est généralement nécessaire de connecter une résistance pull-up ou pull-down en parallèle avec la broche d'entrée numérique.

    En plus de connecter une résistance pull-up, vous pouvez également définir le mode de la broche sur ``INPUT_PULLUP`` dans le code, par exemple ``pinMode(pin, INPUT_PULLUP)``. Dans ce cas, la broche accède à la résistance pull-up intégrée de l'Atmega via le logiciel, ce qui a le même effet que de connecter une résistance pull-up.

2. À propos de la broche 13.

    Toutes les broches numériques (1-13) de la carte R4 peuvent être utilisées avec ``digitalRead()``.
    Cependant, la broche numérique 13 est plus difficile à utiliser comme entrée numérique que les autres broches numériques. Cela est dû au fait qu'elle est connectée à une LED et à une résistance sur la carte.
    Si vous activez sa résistance pull-up interne de 20k, elle restera à environ 1,7V au lieu des 5V attendus, car la LED embarquée et la résistance en série abaissent le niveau de tension, ce qui signifie qu'elle renvoie toujours LOW. Si vous devez utiliser la broche 13 comme entrée numérique, configurez son ``pinMode()`` sur INPUT et utilisez une résistance pull-down externe.

3. Broches Analogiques.

    Si les broches numériques ne suffisent pas, les broches analogiques (A0-A5) peuvent également être utilisées comme broches numériques. 
    Elles doivent être configurées sur INPUT avec ``pinMode(pin, mode)``.


**Composants Associés**

Vous trouverez ci-dessous les composants associés. Cliquez pour apprendre à les utiliser.

.. toctree::
    :maxdepth: 2

    ar_serial_monitor
    ar_button
    ar_reed
    ar_detect_the_obstacle
    ar_detect_the_line


