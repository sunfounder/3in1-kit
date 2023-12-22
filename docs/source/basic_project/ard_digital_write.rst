.. _ar_digital_write:

1. Écriture Numérique
==============================

L'**Écriture Numérique** consiste à émettre ou écrire un signal numérique sur une broche numérique. Le signal numérique n'a que deux états, 0 ou 1, 0V ou 5V, ce qui permet à certains composants, tels que la LED et le buzzer, d'être allumés ou éteints.

Sur la carte Arduino R3, il y a 14 broches d'entrée/sortie numériques de 0 à 13. Utilisez maintenant les fonctions ``pinMode()`` et ``digitalWrite()`` pour écrire un niveau élevé ou bas sur ces broches numériques.

* ``pinMode(pin, mode)`` : Configurez la broche spécifique en tant que ``INPUT`` ou ``OUTPUT``, ici elle doit être définie comme ``OUTPUT``.

   **Syntaxe**
      pinMode(pin, mode)

   **Paramètres**
    * ``pin`` : le numéro de broche Arduino pour définir le mode.
    * ``mode`` : ``INPUT``, ``OUTPUT``, ou ``INPUT_PULLUP``.

* ``digitalWrite(pin, value)`` : Écrivez un niveau élevé (5V) ou un niveau bas (0V) sur une broche numérique pour changer l'état de fonctionnement du composant. Si la broche a été configurée en tant que sortie avec pinMode(), sa tension sera réglée sur la valeur correspondante : 5V (ou 3,3V sur les cartes 3,3V) pour HIGH, 0V (masse) pour LOW.

   **Syntaxe**
      digitalWrite(pin, value)

   **Paramètres**
    * ``pin`` : le numéro de broche Arduino.
    * ``value`` : ``HIGH`` ou ``LOW``.

**Exemple d'Écriture Numérique :**

.. code-block:: arduino

   const int pin = 13;

   void setup() {
      pinMode(pin, OUTPUT);    // sets the digital pin as output
   }

   void loop() {
      digitalWrite(pin, HIGH); // sets the digital pin on
      delay(1000);            // waits for a second
      digitalWrite(pin, LOW);  // sets the digital pin off
      delay(1000);            // waits for a second
   }

.. image:: img/1_led.jpg

**Notes et Avertissements**

* Les broches 0~13 sont toutes des broches numériques.
* N'utilisez pas les broches 0 et 1, car elles sont utilisées pour communiquer avec l'ordinateur. Connecter quoi que ce soit à ces broches perturbera la communication, y compris provoquant l'échec de la mise en ligne.
* Si les broches numériques sont toutes utilisées, les broches analogiques (A0-A5) peuvent également être utilisées comme broches numériques.

**Composants Connexes**

Ci-dessous se trouvent les composants connexes, vous pouvez cliquer pour apprendre comment les utiliser.

.. toctree::
   :maxdepth: 2

   ar_blinking_led
   ar_active_buzzer
   ar_turn_the_wheel
   ar_pumping
