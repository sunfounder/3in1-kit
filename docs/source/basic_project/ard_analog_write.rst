.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Explorez en profondeur Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Assistance d'experts** : Résolvez les problèmes après-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits.
    - **Réductions spéciales** : Profitez de remises exclusives sur nos derniers produits.
    - **Promotions et concours festifs** : Participez à des concours et des promotions spéciales.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _ar_analog_write:

2. Écriture Analogique
=========================

6 des 14 broches numériques de l'Arduino disposent également de la fonction de sortie PWM. Par conséquent, en plus d'écrire des signaux numériques sur ces 6 broches, vous pouvez également y écrire des signaux analogiques (signaux d'onde PWM). De cette manière, vous pouvez faire varier la luminosité des LED ou ajuster la vitesse de rotation d'un moteur.

La modulation de largeur d'impulsion, ou `PWM <https://docs.arduino.cc/learn/microcontrollers/analog-output>`_, est une technique permettant d'obtenir des résultats analogiques par des moyens numériques. Comme cela peut être difficile à comprendre littéralement, voici un exemple de contrôle de l'intensité d'une LED pour mieux saisir le concept.

Un signal numérique composé de niveaux hauts et bas est appelé une impulsion. La largeur d'impulsion de ces broches peut être ajustée en modifiant la vitesse ON/OFF. 
En termes simples, lorsque nous allumons, éteignons et rallumons une LED pendant une courte période (par exemple 20ms, la durée de persistance visuelle de la plupart des gens), nous ne percevons pas qu'elle s'éteint, mais sa luminosité est légèrement réduite. Plus longtemps la LED est allumée pendant cette période, plus elle semble lumineuse. 
Autrement dit, sur une période donnée, plus l'impulsion est large, plus l'« intensité du signal électrique » émise par le microcontrôleur est grande.

Voici la fonction nécessaire pour écrire une onde PWM :

* ``analogWrite(pin, value)``

    Écrit une valeur analogique (onde PWM) sur une broche. Différentes tensions de sortie (0-5V) peuvent être simulées en générant un signal d'impulsion spécifié. La broche maintiendra ce signal jusqu'à ce qu'elle soit appelée par une nouvelle instruction de lecture ou d'écriture.

   **Syntaxe**
      analogWrite(pin, value)

   **Paramètres**
    * ``pin`` : la broche Arduino à écrire. Types de données autorisés : int.
    * ``value`` : le rapport cyclique : entre 0 (toujours éteint) et 255 (toujours allumé). Types de données autorisés : int.


**Exemple d'Écriture Analogique**

.. code-block:: arduino

   int pin = 9;      // connecter à une broche pwm

   void setup() {
      pinMode(pin, OUTPUT);  // configure la broche comme sortie
   }

   void loop() {
      for (int i = 0 ;i<255 ; i++){
         analogWrite(pin, i); // valeurs analogWrite de 0 à 255
         delay(30);
      }
   }

**Notes et Avertissements**

* En examinant attentivement la carte R4, les broches marquées du symbole « ~ » disposent de la fonction de sortie analogique.
* Les sorties PWM générées sur les broches 5 et 6 auront des cycles de travail supérieurs aux attentes. Cela est dû aux interactions avec les fonctions ``millis()`` et ``delay()``, qui partagent le même minuteur interne utilisé pour générer ces sorties PWM. Cela se remarque principalement sur des réglages de faible cycle de travail (par exemple 0 - 10) et peut entraîner un échec à éteindre complètement la sortie sur les broches 5 et 6 lorsque la valeur est 0.


**Composants Associés**

Vous trouverez ci-dessous les composants associés. Cliquez pour apprendre à les utiliser.

.. toctree::
   :maxdepth: 2

   ar_fading
   ar_colorful_light