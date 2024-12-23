.. note:: 

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions spéciales.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _car_move_code:

2. Déplacez-vous par le code
================================

Dans le projet précédent, nous avons essayé de contrôler le fonctionnement du moteur en utilisant différents signaux de niveau pour l'entrée du module L9110.

Si nous modifions les signaux de niveau par le biais du programme, nous pouvons alors contrôler le mouvement de la voiture de manière flexible.

**Composants Requis**

Dans ce projet, nous avons besoin des composants suivants :

Il est certainement pratique d'acheter un kit complet, voici le lien :

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nom	
        - ARTICLES DANS CE KIT
        - LIEN
    *   - Kit de démarrage 3 en 1
        - 380+
        - |link_3IN1_kit|

Vous pouvez également les acheter séparément via les liens ci-dessous.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUCTION DU COMPOSANT
        - LIEN D'ACHAT

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_l9110`
        - \-
    *   - :ref:`cpn_tt_motor`
        - \-

**Câblage**


Connectez les fils entre le module L9110 et la carte R4 selon le schéma ci-dessous.

.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - Module L9110
      - Carte R4
      - Moteur
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
      - Fil noir du moteur droit
    * - OA(B)
      - 
      - Fil rouge du moteur droit
    * - OB(A)
      - 
      - Fil noir du moteur gauche
    * - OA(A)
      - 
      - Fil rouge du moteur gauche

.. image:: img/car_2.png
    :width: 800

**Code**

.. note::

    * Ouvrez le fichier ``2.move.ino`` sous le chemin ``3in1-kit\car_project\2.move``.
    * Ou copiez ce code dans **Arduino IDE**.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/6ff67dfb-a1c1-474b-a106-6acbb3a39e6f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Après le téléversement du code, la voiture avancera, reculera, se déplacera à gauche et à droite pendant deux secondes respectivement.

**Comment ça marche ?**

Ce projet est essentiellement identique au précédent, impliquant le déplacement de la voiture en avant, arrière, gauche et droite, ainsi que l'arrêt, en fournissant différents signaux de niveau aux broches d'entrée du module L9110.

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

#. Définissez les broches d'entrée à différents niveaux haut ou bas pour contrôler la rotation des moteurs gauche et droit, puis encapsulez-les dans des fonctions individuelles.

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

    * ``pin`` : numéro de la broche Arduino.
    * ``value`` : HIGH ou LOW.
    
    Écrit une valeur HIGH ou LOW sur une broche numérique. Si la broche a été configurée comme ``OUTPUT`` avec ``pinMode()``, sa tension sera réglée sur la valeur correspondante : 5V (ou 3.3V sur des cartes 3.3V) pour HIGH, 0V (masse) pour LOW.

* `pinMode(pin, mode) <https://www.arduino.cc/reference/en/language/functions/digital-io/pinmode/>`_

    * ``pin`` : numéro de la broche Arduino à configurer.
    * ``mode`` : INPUT, OUTPUT ou INPUT_PULLUP.
    
    Configure la broche spécifiée pour se comporter soit comme une entrée, soit comme une sortie.

* `delay(ms) <https://www.arduino.cc/reference/en/language/functions/time/delay/>`_

    * ``ms`` : nombre de millisecondes pour mettre en pause. Types de données autorisés : unsigned long.

    Met en pause le programme pour la durée (en millisecondes) spécifiée en paramètre. (Il y a 1000 millisecondes dans une seconde.)
