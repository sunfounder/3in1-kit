.. note::

    Bonjour et bienvenue dans la Communauté Facebook des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez [|link_sf_facebook|] et rejoignez-nous aujourd'hui !

.. _sh_star_crossed:

2.15 JEU - Étoiles Croisées
==============================

Dans les projets suivants, nous allons jouer à quelques mini-jeux amusants dans PictoBlox.

Ici, nous utilisons le module Joystick pour jouer à un jeu nommé Étoiles Croisées.

Après l'exécution du script, des étoiles apparaîtront aléatoirement sur la scène, vous devez utiliser le Joystick pour contrôler le vaisseau spatial afin d'éviter les étoiles, si vous les touchez, le jeu sera terminé.

.. image:: img/16_rocket.png

Vous Apprendrez
---------------------

- Comment fonctionne le module Joystick
- Définir les coordonnées x et y du sprite

Composants requis
---------------------

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_joystick`
        - \-

Construisez le Circuit
-----------------------

Un joystick est un dispositif d'entrée constitué d'un manche qui pivote sur une base et transmet son angle ou sa direction au dispositif qu'il contrôle. Les joysticks sont souvent utilisés pour contrôler les jeux vidéo et les robots.

Pour communiquer une gamme complète de mouvements à l'ordinateur, un joystick doit mesurer la position du manche sur deux axes – l'axe X (de gauche à droite) et l'axe Y (de haut en bas).

Les coordonnées de mouvement du joystick sont présentées dans la figure suivante.

.. note::

    * La coordonnée x est de gauche à droite, la plage est de 0-1023.
    * La coordonnée y est de haut en bas, la plage est de 0-1023.

.. image:: img/16_joystick.png


Construisez maintenant le circuit selon le schéma suivant.

.. image:: img/circuit/joystick_circuit.png

Programmation
------------------
Le script complet vise à obtenir l'effet suivant : lorsque le drapeau vert est cliqué, le sprite **Stars** se déplace en courbe sur la scène et vous devez utiliser le joystick pour déplacer le **Rocketship**, afin qu'il ne soit pas touché par le sprite **Star**.

**1. Ajouter des sprites et des décors**

Supprimez le sprite par défaut et utilisez le bouton **Choose a Sprite** pour ajouter les sprites **Rocketship** et **Star**. Notez que la taille du sprite **Rocket** est réglée à 50%.

.. image:: img/16_sprite.png

Ajoutez maintenant le décor **Stars** via **Choose a Backdrop**.

.. image:: img/16_sprite1.png

**2. Scripter pour le Vaisseau Spatial**

Le sprite **Rocketship** doit donner l'effet qu'il apparaîtra à une position aléatoire et sera ensuite contrôlé par le joystick pour se déplacer vers le haut, le bas, la gauche et la droite.

Le flux de travail est le suivant.

* Lorsque le drapeau vert est cliqué, faites aller le sprite à un endroit aléatoire et créez 2 variables **x** et **y**, qui stockent respectivement les valeurs lues de A0 (VRX du Joystick) et A1 (VRY du Joystick). Vous pouvez laisser le script s'exécuter, basculer le joystick vers le haut et vers le bas, à gauche et à droite, pour voir la plage de valeurs pour x et y.

.. image:: img/16_roc2.png

* La valeur de A0 est dans la plage 0-1023 (le milieu est environ 512). Utilisez ``x-512>200`` pour déterminer si le Joystick bascule vers la droite, et si c'est le cas, faites +30 à la coordonnée x du sprite (pour déplacer le sprite vers la droite).

.. image:: img/16_roc3.png

* Si le Joystick bascule vers la gauche (``x-512<-200``), laissez la coordonnée x du sprite être -30 (laissez le sprite se déplacer vers la gauche).

.. image:: img/16_roc4.png

* Comme la coordonnée y du Joystick est de haut (0) à bas (1023), et la coordonnée y du sprite est de bas en haut. Donc, pour déplacer le Joystick vers le haut et le sprite vers le haut, la coordonnée y doit être -30 dans le script.

.. image:: img/16_roc5.png

* Si le joystick est basculé vers le bas, la coordonnée y du sprite est +30.

.. image:: img/16_roc6.png

**3. Scripter pour l'Étoile**

L'effet à atteindre par le sprite **Star** est d'apparaître à un endroit aléatoire, et s'il touche **Rocketship**, le script s'arrête de fonctionner et le jeu se termine.

* Lorsque le drapeau vert est cliqué et que le sprite va à un endroit aléatoire, le bloc [turn degrees] est pour faire avancer le sprite **Star** avec un peu de changement d'angle pour que vous puissiez voir qu'il se déplace en courbe et s'il touche le bord, rebondit.

.. image:: img/16_star1.png

* Si le sprite touche le sprite **Rocketship** pendant son déplacement, arrêtez l'exécution du script.

.. image:: img/16_star2.png
