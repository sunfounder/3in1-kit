.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez plus profondément dans le monde de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Assistance d'experts** : Résolvez les problèmes après-vente et relevez des défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits.
    - **Réductions spéciales** : Profitez de remises exclusives sur nos derniers produits.
    - **Promotions et concours festifs** : Participez à des concours et des offres spéciales.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _ar_digital_write:

1. Écriture Numérique
=====================

**Écriture numérique** consiste à envoyer ou écrire un signal numérique à une broche numérique. Le signal numérique n’a que deux états : 0 ou 1, 0V ou 5V. Cela permet de contrôler certains composants, comme une LED ou un buzzer, pour les allumer ou les éteindre.

Sur la carte Arduino R4, il y a 14 broches numériques d'entrée/sortie (I/O) numérotées de 0 à 13. Utilisez les fonctions ``pinMode()`` et ``digitalWrite()`` pour envoyer un niveau haut ou bas à ces broches numériques.


* ``pinMode(pin, mode)`` : Configurez une broche spécifique comme ``INPUT`` ou ``OUTPUT`` ; ici, elle doit être définie comme ``OUTPUT``.

   **Syntaxe**
      pinMode(pin, mode)

   **Paramètres**
    * ``pin`` : le numéro de la broche Arduino à configurer.
    * ``mode`` : ``INPUT``, ``OUTPUT`` ou ``INPUT_PULLUP``.

* ``digitalWrite(pin, value)`` : Écrit un niveau haut (5V) ou un niveau bas (0V) sur une broche numérique pour changer l'état de fonctionnement du composant. Si la broche a été configurée comme sortie avec ``pinMode()``, sa tension sera réglée en conséquence : 5V (ou 3,3V sur les cartes 3,3V) pour HIGH, 0V (masse) pour LOW.

   **Syntaxe**
      digitalWrite(pin, value)

   **Paramètres**
    * ``pin`` : le numéro de la broche Arduino.
    * ``value`` : ``HIGH`` ou ``LOW``.

**Exemple d'Écriture Numérique :**

.. code-block:: arduino

   const int pin = 13;

   void setup() {
      pinMode(pin, OUTPUT);    // configure la broche numérique comme sortie
   }

   void loop() {
      digitalWrite(pin, HIGH); // allume la broche numérique
      delay(1000);            // attend une seconde
      digitalWrite(pin, LOW);  // éteint la broche numérique
      delay(1000);            // attend une seconde
   }

.. image:: img/1_led.jpg


**Notes et Avertissements**

* Les broches 0 à 13 sont toutes des broches numériques.
* Évitez d'utiliser les broches 0 et 1, car elles sont utilisées pour communiquer avec l'ordinateur. Connecter quoi que ce soit à ces broches peut interférer avec la communication, y compris provoquer un échec du téléchargement vers la carte.
* Si toutes les broches numériques sont utilisées, les broches analogiques (A0-A5) peuvent également être utilisées comme broches numériques.

**Composants Associés**

Vous trouverez ci-dessous les composants associés. Cliquez pour apprendre à les utiliser.

.. toctree::
   :maxdepth: 2

   ar_blinking_led
   ar_active_buzzer
   ar_turn_the_wheel
   ar_pumping


