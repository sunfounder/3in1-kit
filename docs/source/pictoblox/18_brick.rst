.. note::

    Bonjour et bienvenue dans la Communauté Facebook des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez [|link_sf_facebook|] et rejoignez-nous aujourd'hui !

.. _sh_breakout_clone:

2.18 JEU - Clone de Breakout
============================

Ici, nous utilisons le potentiomètre pour jouer à un jeu clone de Breakout.

Après avoir cliqué sur le drapeau vert, vous devez utiliser le potentiomètre pour contrôler la raquette sur la scène pour attraper la balle afin qu'elle puisse monter et frapper les briques, toutes les briques disparaissent alors le jeu est gagné, si vous ne rattrapez pas la balle, le jeu est perdu.

.. image:: img/17_brick.png

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_potentiometer`
        - |link_potentiometer_buy|

Construisez le Circuit
-----------------------

Le potentiomètre est un élément résistif à 3 bornes, les 2 broches latérales sont connectées à 5V et GND, et la broche centrale est connectée à A0. Après la conversion par le convertisseur ADC de la carte Arduino, la plage de valeurs est de 0-1023.

.. image:: img/circuit/potentiometer_circuit.png

Programmation
------------------

Il y a 3 sprites sur la scène.

**1. Sprite Raquette**

L'effet à atteindre par la **Paddle** est que la position initiale est au milieu du bas de la scène, et elle est contrôlée par un potentiomètre pour se déplacer vers la gauche ou vers la droite.

* Supprimez le sprite par défaut, utilisez le bouton **Choose a Sprite** pour ajouter le sprite **Paddle**, et réglez ses x et y à (0, -140).

.. image:: img/17_padd1.png

* Allez à la page **Costumes**, retirez le Contour et changez sa couleur en gris foncé.

.. image:: img/17_padd3.png


* Scriptez maintenant le sprite **Paddle** pour définir sa position initiale à (0, -140) lorsque le drapeau vert est cliqué, et lisez la valeur de A0 (potentiomètre) dans la variable **a0**. Comme le sprite **Paddle** se déplace de gauche à droite sur la scène aux coordonnées x -195~195, vous devez utiliser le bloc [map] pour mapper la plage de la variable **a0** de 0~1023 à -195~195. 

.. image:: img/17_padd2.png

* Maintenant, vous pouvez tourner le potentiomètre pour voir si la **Paddle** peut se déplacer à gauche et à droite sur la scène.

**2. Sprite Balle**

L'effet du sprite balle est qu'il se déplace autour de la scène et rebondit lorsqu'il touche le bord ; il rebondit vers le bas s'il touche le bloc au-dessus de la scène ; il rebondit vers le haut s'il touche le sprite Raquette pendant sa chute ; si ce n'est pas le cas, le script cesse de fonctionner et le jeu se termine.


* Ajoutez le sprite **Ball**.

.. image:: img/17_ball1.png

* Lorsque le drapeau vert est cliqué, réglez l'angle du sprite **Ball** à 45° et positionnez-le initialement à (0, -120).

.. image:: img/17_ball2.png

* Laissez maintenant le sprite **Ball** se déplacer autour de la scène et rebondir lorsqu'il touche le bord, et vous pouvez cliquer sur le drapeau vert pour voir l'effet.

.. image:: img/17_ball3.png

* Lorsque le sprite **Ball** touche le sprite **Paddle**, faites un rebond. La façon simple de faire cela est de laisser l'angle être directement inversé, mais alors vous trouverez que la trajectoire de la balle est complètement fixe, ce qui est trop ennuyeux. Par conséquent, nous utilisons le centre des deux sprites pour calculer et faire rebondir la balle dans la direction opposée au centre de la raquette.

.. image:: img/17_ball4.png

.. image:: img/17_ball6.png

* Lorsque le sprite **Ball** tombe au bord de la scène, le script cesse de fonctionner et le jeu se termine.

.. image:: img/17_ball5.png


**3. Sprite Bloc1**

Le sprite **Block1** doit apparaître avec l'effet de clonage 4x8 de lui-même au-dessus de la scène dans une couleur aléatoire, et supprimer un clone s'il est touché par le sprite **Ball**.

Le sprite **Block1** n'est pas disponible dans la bibliothèque **PictoBlox**, vous devez le dessiner vous-même ou le modifier à partir d'un sprite existant. Ici, nous allons le modifier avec le sprite **Button3**.

* Après avoir ajouté le sprite **Button3**, allez à la page **Costumes**. Maintenant, supprimez d'abord **button-a**, puis réduisez à la fois la largeur et la hauteur de **button-b**, et changez le nom du sprite en **Block1**, comme indiqué dans l'image suivante.

.. note::

    * Pour la largeur de **Block1**, vous pouvez probablement la simuler sur l'écran pour voir si vous pouvez en mettre 8 de suite, sinon, réduisez la largeur de manière appropriée.
    * Lors du rétrécissement du sprite **Block1**, vous devez garder le point central au milieu du sprite.

.. image:: img/17_bri2.png

* Créez maintenant 2 variables en premier, **block** pour stocker le nombre de blocs et **roll** pour stocker le nombre de rangées.

.. image:: img/17_bri3.png

* Nous devons faire un clone du sprite **Block1**, pour qu'il s'affiche de gauche à droite, de haut en bas, un par un, au total 4x8, avec des couleurs aléatoires.

.. image:: img/17_bri4.png

* Après avoir écrit le script, cliquez sur le drapeau vert et regardez l'affichage sur la scène, si c'est trop compact ou trop petit, vous pouvez changer la taille.

.. image:: img/17_bri5.png

* Écrivez maintenant l'événement déclencheur. Si le sprite cloné **Block1** touche le sprite **Balle**, supprimez le clone et diffusez le message **crush**.

.. image:: img/17_bri6.png

* Retour au sprite **Ball**, lorsque la diffusion **crush** est reçue (le sprite **Ball** touche le clone du sprite **Block1**), la **Ball** est éjectée de la direction opposée.

.. image:: img/17_ball7.png







