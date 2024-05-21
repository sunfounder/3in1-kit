.. note::

    Bonjour et bienvenue dans la Communauté Facebook des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez [|link_sf_facebook|] et rejoignez-nous aujourd'hui !

.. _car_ir_obstacle:

5. Jouer avec le module d'évitement d'obstacles
=================================================

Deux modules infrarouges d'évitement d'obstacles sont installés à l'avant de la voiture, ils permettent de détecter certains obstacles proches.

Dans ce projet, la voiture se déplace librement vers l'avant et, lorsqu'elle rencontre un obstacle, elle est capable de l'éviter et de continuer à se déplacer dans d'autres directions.

**Composants requis**

Pour ce projet, nous avons besoin des composants suivants.

Il est certainement pratique d'acheter un kit complet, voici le lien :

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nom	
        - ÉLÉMENTS DANS CE KIT
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
    *   - :ref:`cpn_avoid` 
        - |link_obstacle_avoidance_buy|

**Câblage**

Le module d'évitement d'obstacle est un capteur de proximité infrarouge à distance réglable dont la sortie est normalement haute et basse lorsqu'un obstacle est détecté.

.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/vadNtXwITFc?si=gY4Ww31zmcs8AObP" title="Lecteur vidéo YouTube" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

Construisez maintenant le circuit selon le schéma ci-dessous.

.. list-table:: 
    :header-rows: 1

    * - Module IR gauche
      - Carte R3
    * - OUT
      - 8
    * - GND
      - GND
    * - VCC
      - 5V

.. list-table:: 
    :header-rows: 1

    * - Module IR droit
      - Carte R3
    * - OUT
      - 7
    * - GND
      - GND
    * - VCC
      - 5V

.. image:: img/car_5.png
    :width: 800


**Ajuster le module**

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="_static/video/calibrate_ir.mp4" type="video/mp4">
        Votre navigateur ne prend pas en charge la balise vidéo.
    </video>
    
Avant de commencer le projet, vous devez régler la distance de détection du module.

Câblez selon le schéma ci-dessus, alimentez la carte R3 (soit en branchant directement le câble USB, soit en connectant le câble de la batterie 9V), sans télécharger le code.

Placez un carnet ou tout autre objet plat à environ 5 cm devant le module d'évitement d'obstacle IR.

Utilisez ensuite un tournevis pour tourner le potentiomètre sur le module jusqu'à ce que l'indicateur de signal sur le module s'allume, afin d'ajuster sa distance maximale de détection à 5 cm.

Suivez la même méthode pour régler l'autre module infrarouge.

.. image:: img/ir_obs_cali.jpg



**Code**

.. note::

    * Ouvrez le fichier ``5.obstacle_avoidance_module.ino`` situé dans le dossier ``3in1-kit\car_project\5.obstacle_avoidance_module``.
    * Ou copiez ce code dans **Arduino IDE**.
    
    * Ou téléchargez le code via `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/289ca80d-009f-4f60-b36d-1da6c5e10233/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

La voiture avancera une fois le code téléchargé avec succès. Lorsque le module infrarouge gauche détecte un obstacle, elle reculera vers la gauche ; lorsque le module infrarouge droit détecte un obstacle, elle reculera vers la droite ; si les deux côtés détectent un obstacle, elle reculera directement en arrière.

**Comment ça fonctionne ?**

Ce projet se base sur la valeur des modules d'évitement d'obstacles infrarouges gauche et droit pour faire prendre à la voiture l'action appropriée.

#. Ajoutez la définition de pin pour les 2 modules d'évitement d'obstacles, ici ils sont réglés sur ``INPUT``.

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


#. Lisez les valeurs des modules infrarouges gauche et droit et laissez la voiture prendre l'action correspondante.

    .. code-block:: arduino

        void loop() {

            int left = digitalRead(leftIR);   // 0: Obstructed  1: Empty
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
    * Si les 2 modules IR détectent l'obstacle en même temps, la voiture reculera.
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

* `&& <https://www.arduino.cc/reference/en/language/structure/boolean-operators/logicaland/>`_ : L'opérateur logique ET donne un résultat vrai seulement si les deux opérandes sont vrais.

* `! <https://www.arduino.cc/reference/en/language/structure/boolean-operators/logicalnot/>`_ : L'opérateur logique NON donne un résultat vrai si l'opérande est faux et vice versa.

