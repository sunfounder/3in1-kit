.. _car_move_code:

2. Mouvement par Code
=====================

Dans le projet précédent, nous avons essayé de contrôler le fonctionnement du moteur en utilisant différents signaux de niveau pour l'entrée du module L9110.

Si nous modifions les signaux de niveau par le programme, alors nous pouvons contrôler le mouvement de la voiture de manière flexible.

**Composants requis**

Pour ce projet, nous aurons besoin des composants suivants.

Il est certainement pratique d'acheter un kit complet, voici le lien :

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nom	
        - ÉLÉMENTS DE CE KIT
        - LIEN
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

Vous pouvez également les acheter séparément via les liens ci-dessous.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUCTION DES COMPOSANTS
        - LIEN D'ACHAT

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_l9110`
        - \-
    *   - :ref:`cpn_tt_motor`
        - \-


**Câblage**

.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/Dpxpb4wSq5k?si=ep6p_jzhm-DPU9w4" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

Connectez les fils entre le module L9110 et la carte R3 selon le schéma ci-dessous.

.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - L9110 Module
      - R3 Board
      - Motor
    * - A-1B
      - 5
      - 
    * - A-1A
      - 6
      - 
    * - B-1B(B-2A)
      - 9
      - 
    * - B-1A
      - 10
      - 
    * - OB(B)
      - 
      - Black wire of right motor
    * - OA(B)
      - 
      - Red wire of right motor
    * - OB(A)
      - 
      - Black wire of left motor
    * - OA(A)
      - 
      - Red wire of left motor

.. image:: img/car_2.png
    :width: 800


**Code**

.. note::

    * Ouvrez le fichier ``2.move.ino`` dans le chemin ``3in1-kit\car_project\2.move``.
    * Ou copiez ce code dans **Arduino IDE**.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/6ff67dfb-a1c1-474b-a106-6acbb3a39e6f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Après le téléchargement du code, la voiture se déplacera respectivement vers l'avant, l'arrière, la gauche et la droite pendant deux secondes.

**Comment ça fonctionne ?**

Ce projet est essentiellement le même que le précédent, impliquant de faire avancer, reculer, tourner à gauche et à droite la voiture, ainsi que de l'arrêter en fournissant différents niveaux de signal aux broches d'entrée du module L9110.

#. Initialisez les broches du module L9110.

    .. code-block:: arduino

        const int A_1B = 5;
        const int A_1A = 6;
        const int B_1B = 9;
        const int B_1A = 10;

        void setup() {
            pinMode(A_1B, OUTPUT);
            pinMode(A_1A, OUTPUT);
            pinMode(B_1B, OUTPUT);
            pinMode(B_1A, OUTPUT);
        }

#. Réglez les broches d'entrée à différents niveaux hauts ou bas pour contrôler la rotation des moteurs gauche et droit, puis encapsulez-les dans des fonctions individuelles.

    .. code-block:: arduino

        void moveForward() {
            digitalWrite(A_1B, LOW);
            digitalWrite(A_1A, HIGH);
            digitalWrite(B_1B, HIGH);
            digitalWrite(B_1A, LOW);
        }

        void moveBackward() {
            digitalWrite(A_1B, HIGH);
            digitalWrite(A_1A, LOW);
            digitalWrite(B_1B, LOW);
            digitalWrite(B_1A, HIGH);
        }
        ...
#. Appelez ces fonctions dans ``loop()``.

    .. code-block:: arduino

        void loop() {
            moveForward();
            delay(2000);
            stopMove();
            delay(500);

            moveBackward();
            delay(2000);
            stopMove();
            delay(500);
        ...

* `digitalWrite(pin, value) <https://www.arduino.cc/reference/en/language/functions/digital-io/digitalwrite/>`_

    * ``pin`` : le numéro de la broche Arduino.
    * ``value`` : HIGH ou LOW.
    
    Écrit une valeur HIGH ou LOW sur une broche numérique. Si la broche a été configurée comme une ``OUTPUT`` avec ``pinMode()``, sa tension sera réglée sur la valeur correspondante : 5V (ou 3,3V sur les cartes 3,3V) pour HIGH, 0V (masse) pour LOW.

* `pinMode(pin, mode) <https://www.arduino.cc/reference/en/language/functions/digital-io/pinmode/>`_

    * ``pin`` : le numéro de la broche Arduino à configurer.
    * ``mode`` : INPUT, OUTPUT ou INPUT_PULLUP.
    
    Configure la broche spécifiée pour se comporter soit comme une entrée, soit comme une sortie.

* `delay(ms) <https://www.arduino.cc/reference/en/language/functions/time/delay/>`_

    * ``ms`` : le nombre de millisecondes de pause. Types de données autorisés : unsigned long.

    Interrompt le programme pendant la durée (en millisecondes) spécifiée en paramètre. (Il y a 1000 millisecondes dans une seconde.)
