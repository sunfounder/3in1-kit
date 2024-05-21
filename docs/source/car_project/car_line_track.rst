.. note::

    Bonjour et bienvenue dans la Communauté Facebook des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez [|link_sf_facebook|] et rejoignez-nous aujourd'hui !

.. _follow_the_line:

4. Suivre la ligne
======================

La voiture est équipée d'un module de suivi de ligne, qui peut être utilisé pour faire suivre à la voiture une ligne noire.

Lorsque le module de suivi de ligne détecte la ligne noire, le moteur droit tourne tandis que le moteur gauche reste immobile, permettant ainsi à la voiture de se déplacer d'un pas vers l'avant gauche.
Au fur et à mesure que la voiture se déplace, le module de ligne sera déplacé hors de la ligne, puis le moteur gauche tourne et le moteur droit ne tourne pas, la voiture se déplace d'un pas vers la droite pour revenir sur la ligne.
En répétant les deux étapes ci-dessus, la voiture peut se déplacer le long de la ligne noire.

Avant de commencer le projet, vous devez construire une carte de courbe avec du ruban adhésif noir pour ligne, la largeur de ligne recommandée est entre 0,8-1,5 cm et l'angle du virage ne doit pas être inférieur à 90 degrés.

**Composants requis**

Dans ce projet, nous avons besoin des composants suivants.

Il est certainement pratique d'acheter un kit complet, voici le lien :

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nom	
        - ARTICLES DANS CE KIT
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
    *   - :ref:`cpn_track`
        - |link_track_buy|

**Câblage**


C'est un module numérique de suivi de ligne, lorsqu'une ligne noire est détectée, il émet 1 ; lorsqu'une ligne blanche est détectée, il émet une valeur de 0. De plus, vous pouvez ajuster sa distance de détection grâce au potentiomètre sur le module.

.. raw:: html

    <iframe width="600" height="400" src="https://www.youtube.com/embed/mlCQgAq4elo?si=ZFmHeA6bVsDCPG0p" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

Construisez le circuit selon le schéma suivant.

.. list-table:: 
    :header-rows: 1

    * - Module de suivi de ligne
      - Carte R3
    * - S
      - 2
    * - V+
      - 5V
    * - G
      - GND

.. image:: img/car_4.png
    :width: 800


**Ajuster le module**


Avant de commencer le projet, vous devez ajuster la sensibilité du module.

Câblez selon le schéma ci-dessus, puis alimentez la carte R3 (soit directement dans le câble USB soit dans le câble du bouton de la batterie 9V), sans télécharger le code.

Collez un ruban électrique noir sur la table et placez la voiture dessus.

Observez la LED de signal sur le module pour vous assurer qu'elle s'allume sur la table blanche et s'éteint sur le ruban noir.

Si ce n'est pas le cas, vous devez ajuster le potentiomètre sur le module, afin qu'il puisse faire l'effet ci-dessus.

.. image:: img/line_track_cali.JPG

**Code**

.. note::

    * Ouvrez le fichier ``4.follow_the_line.ino`` sous le chemin de ``3in1-kit\car_project\4.follow_the_line``.
    * Ou copiez ce code dans **Arduino IDE**.
    
    * Ou téléchargez le code via le `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/2779e9eb-b7b0-4d47-b8c0-78fed39828c3/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Après avoir téléchargé le code sur la carte R3, alignez le module de suivi de ligne sous la voiture avec la ligne noire, et vous verrez la voiture suivre la ligne.


**Comment ça fonctionne ?**

Dans ce code, il permet aux deux moteurs de micro-tourner à gauche et à droite en fonction de la valeur du module de suivi de ligne, afin que vous puissiez voir la voiture suivre la ligne noire.


#. Ajoutez la définition de pin pour le module de suivi de ligne, ici il est réglé sur ``INPUT``. Initialisez également le moniteur série et réglez le débit en bauds à 9600bps.

    .. code-block:: arduino

        ...
        const int lineTrack = 2;
        Serial.begin(9600);
        void setup() {
            ...
            pinMode(lineTrack, INPUT);
        }

#. Lisez la valeur du module de suivi de ligne, si elle est 1, alors laissez la voiture aller vers l'avant gauche ; sinon, aller vers l'avant droite. Vous pouvez également ouvrir le moniteur série en cliquant sur l'icône de la loupe dans le coin supérieur droit pour voir le changement de la valeur du module de suivi de ligne sur la ligne noire et blanche avant de débrancher le câble USB.

    .. code-block:: arduino
    
        void loop() {

            int speed = 150;

            int lineColor = digitalRead(lineTrack); // 0:white    1:black
            Serial.println(lineColor); 
            if (lineColor) {
                moveLeft(speed);
            } else {
                moveRight(speed);
            }
        }

#. À propos des fonctions ``moveLeft()`` et ``moveRight()``.

    Contrairement à la fonction de virage gauche-droite dans le projet :ref:`car_move_code`, seuls de petits virages gauche-droite sont nécessaires ici, donc vous n'avez besoin d'ajuster la valeur de ``A_1A`` ou ``B_1B`` à chaque fois. Par exemple, si vous vous déplacez vers l'avant gauche (``moveLeft()``), vous devez uniquement régler la vitesse sur ``A_1A`` et toutes les autres à 0, ce qui fera tourner le moteur droit dans le sens des aiguilles d'une montre et le moteur gauche immobile.

    .. code-block:: arduino
    

        void moveLeft(int speed) {
            analogWrite(A_1B, 0);
            analogWrite(A_1A, speed);
            analogWrite(B_1B, 0);
            analogWrite(B_1A, 0);
        }

        void moveRight(int speed) {
            analogWrite(A_1B, 0);
            analogWrite(A_1A, 0);
            analogWrite(B_1B, speed);
            analogWrite(B_1A, 0);
        }

* `Serial <https://www.arduino.cc/reference/en/language/functions/communication/serial/>`_

    Utilisé pour la communication entre la carte Arduino et un ordinateur ou d'autres appareils.

    * ``Serial.begin()`` : Définit le taux de données en bits par seconde (baud) pour la transmission de données série.
    * ``Serial.println()`` : Imprime des données sur le port série sous forme de texte ASCII lisible par l'homme suivi d'un caractère de retour chariot (ASCII 13, ou '\r') et d'un caractère de saut de ligne (ASCII 10, ou '\n'). 

* `if else <https://www.arduino.cc/reference/en/language/structure/control-structure/else/>`_

    Le ``if else`` permet un contrôle plus grand sur le flux de code que la simple instruction if, en permettant de regrouper plusieurs tests.
