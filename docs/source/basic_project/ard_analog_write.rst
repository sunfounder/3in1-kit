.. note::

    Bonjour et bienvenue dans la Communauté Facebook des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez [|link_sf_facebook|] et rejoignez-nous aujourd'hui !

.. _ar_analog_write:

2. Écriture Analogique
========================

6 des 14 broches numériques de l'Arduino ont également une fonction de sortie PWM. Par conséquent, en plus d'écrire des signaux numériques sur ces 6 broches, vous pouvez également y écrire des signaux analogiques (signaux d'onde PWM). De cette manière, vous pouvez faire varier la luminosité des LED ou faire tourner le moteur à différentes vitesses.

La Modulation de Largeur d'Impulsion, ou `PWM <https://docs.arduino.cc/learn/microcontrollers/analog-output>`_, est une technique permettant d'obtenir des résultats analogiques avec des moyens numériques. Puisqu'il peut être difficile de saisir le sens littéral, voici un exemple de contrôle de l'intensité d'une LED pour mieux comprendre.

Un signal numérique composé de niveaux haut et bas est appelé une impulsion. La largeur d'impulsion de ces broches peut être ajustée en changeant la vitesse de mise en marche/arrêt.
En d'autres termes, lorsque nous allumons et éteignons la LED sur une courte période (comme 20ms, le temps de persistance visuelle de la plupart des gens),
nous ne verrons pas qu'elle s'est éteinte, mais la luminosité de la lumière sera légèrement plus faible. Pendant cette période, plus la LED est allumée longtemps, plus elle sera lumineuse.
C'est-à-dire, sur une période donnée, plus l'impulsion est large, plus grande sera la "force du signal électrique" sortie par le microcontrôleur.

Voici la fonction nécessaire pour écrire l'onde PWM.

* ``analogWrite(pin, value)``

    Écrit une valeur analogique (onde PWM) sur une broche. Différentes tensions de sortie (0-5V) peuvent être simulées en générant un signal d'impulsion spécifié. La broche conservera ce signal jusqu'à ce qu'elle soit appelée par une nouvelle instruction de lecture ou d'écriture.

   **Syntaxe**
      analogWrite(pin, value)

   **Paramètres**
    * ``pin`` : la broche Arduino à écrire. Types de données autorisés : int.
    * ``value`` : le cycle de travail : entre 0 (toujours éteint) et 255 (toujours allumé). Types de données autorisés : int.


**Exemple d'écriture analogique**

.. code-block:: arduino

   int pin = 9;      //connect  to pwm pin

   void setup() {
      pinMode(pin, OUTPUT);  // sets the pin as output
   }

   void loop() {
      for (int i = 0 ;i<255 ; i++){
         analogWrite(pin, i); //analogWrite values from 0 to 255
         delay(30);
      }
   }

**Notes et avertissements**

* En regardant de près la carte R3, les broches marquées du symbole "~" ont une fonction de sortie analogique.
* Les sorties PWM générées sur les broches 5 et 6 auront des cycles de travail plus élevés que prévu. Cela est dû aux interactions avec les fonctions ``millis()`` et ``delay()``, qui partagent le même minuteur interne utilisé pour générer ces sorties PWM. Cela sera surtout remarqué sur les réglages de cycle de travail faible (par exemple, 0 - 10) et peut entraîner une valeur de 0 ne désactivant pas complètement la sortie sur les broches 5 et 6.


**Composants associés**

Ci-dessous les composants associés, vous pouvez cliquer pour apprendre à les utiliser.

.. toctree::
   :maxdepth: 2

   ar_fading
   ar_colorful_light
