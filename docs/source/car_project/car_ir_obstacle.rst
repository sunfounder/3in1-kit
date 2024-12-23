.. note:: 

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions spéciales.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _car_ir_obstacle:

5. Jouez avec le Module d'Évitement d'Obstacles
===================================================

Deux modules infrarouges d'évitement d'obstacles sont montés à l'avant de la voiture, permettant de détecter des obstacles proches.

Dans ce projet, la voiture avance librement et, lorsqu'elle rencontre un obstacle, elle est capable de l'éviter et de continuer dans une autre direction.

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
    *   - :ref:`cpn_avoid` 
        - |link_obstacle_avoidance_buy|

**Câblage**

Le module d'évitement d'obstacles est un capteur de proximité infrarouge à distance réglable, dont la sortie est normalement haute et devient basse lorsqu'un obstacle est détecté.

Construisez maintenant le circuit selon le schéma ci-dessous.

.. list-table:: 
    :header-rows: 1

    * - Left IR Module
      - R4 Board
    * - OUT
      - 8
    * - GND
      - GND
    * - VCC
      - 5V

.. list-table:: 
    :header-rows: 1

    * - Right IR Module
      - R4 Board
    * - OUT
      - 7
    * - GND
      - GND
    * - VCC
      - 5V

.. image:: img/car_5.png
    :width: 800

**Ajustez le Module**

Avant de commencer le projet, vous devez ajuster la distance de détection du module.

Câblez selon le schéma ci-dessus, alimentez la carte R4 (soit en branchant directement le câble USB, soit en connectant le câble de batterie 9V), sans téléverser le code.

Placez un cahier ou tout autre objet plat à environ 5 cm devant le module d'évitement d'obstacles IR.

Utilisez ensuite un tournevis pour tourner le potentiomètre sur le module jusqu'à ce que l'indicateur de signal sur le module s'allume juste, afin de régler sa distance de détection maximale à 5 cm.

Suivez la même méthode pour ajuster l'autre module infrarouge.

.. image:: img/ir_obs_cali.jpg

**Code**

.. note::

    * Ouvrez le fichier ``5.obstacle_avoidance_module.ino`` sous le chemin ``3in1-kit\car_project\5.obstacle_avoidance_module``.
    * Ou copiez ce code dans **Arduino IDE**.
    
    * Ou téléversez le code via l'`Éditeur Web Arduino <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/289ca80d-009f-4f60-b36d-1da6c5e10233/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

La voiture avancera dès que le code sera téléversé avec succès. Lorsque le module infrarouge gauche détecte un obstacle, elle reculera à gauche ; lorsque le module infrarouge droit détecte un obstacle, elle reculera à droite ; si les deux côtés détectent un obstacle, elle reculera droit.

**Comment ça marche ?**

Ce projet repose sur les valeurs des modules infrarouges d'évitement d'obstacles gauche et droit pour que la voiture effectue les actions appropriées.

#. Ajoutez la définition des broches pour les 2 modules d'évitement d'obstacles, ici elles sont définies comme ``INPUT``.

    .. code-block:: arduino

        ...
        const int rightIR = 7;
        const int leftIR = 8;

        void setup() {
        ...

        //IR obstacle
            pinMode(leftIR, INPUT);
            pinMode(rightIR, INPUT);
        }


#. Lisez les valeurs des modules infrarouges gauche et droit et laissez la voiture effectuer l'action correspondante.

    .. code-block:: arduino

        void loop() {

            int left = digitalRead(leftIR);   // 0 : Obstrué  1 : Libre
            int right = digitalRead(rightIR);
            int speed = 150;

            if (!left && right) {
                backLeft(speed);
            } else if (left && !right) {
                backRight(speed);
            } else if (!left && !right) {
                moveBackward(speed);
            } else {
                moveForward(speed);
            }
        }

    * Si le module IR gauche est à 0 (obstacle détecté) et le module IR droit est à 1, laissez la voiture reculer à gauche.
    * Si le module IR droit est à 0 (obstacle détecté), laissez la voiture reculer à droite.
    * Si les 2 modules IR détectent un obstacle en même temps, la voiture reculera.
    * Sinon, la voiture continuera à avancer.

#. À propos de la fonction ``backLeft()``.

    Lorsque le moteur droit tourne dans le sens antihoraire et que le moteur gauche ne tourne pas, la voiture reculera vers la gauche. 

    .. code-block:: arduino

        void backLeft(int speed) {
            analogWrite(A_1B, speed);
            analogWrite(A_1A, 0);
            analogWrite(B_1B, 0);
            analogWrite(B_1A, 0);
        }

#. À propos de la fonction ``backRight()``.

    Lorsque le moteur gauche tourne dans le sens horaire et que le moteur droit ne tourne pas, la voiture reculera vers la droite.

    .. code-block:: arduino

        void backRight(int speed) {
            analogWrite(A_1B, 0);
            analogWrite(A_1A, 0);
            analogWrite(B_1B, 0);
            analogWrite(B_1A, speed);
        }

* `&& <https://www.arduino.cc/reference/en/language/structure/boolean-operators/logicaland/>`_: ET logique donne un résultat vrai uniquement si les deux opérandes sont vrais.

* `! <https://www.arduino.cc/reference/en/language/structure/boolean-operators/logicalnot/>`_: NON logique donne un résultat vrai si l'opérande est faux, et vice versa.
