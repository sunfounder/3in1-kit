.. note::

    Bonjour et bienvenue dans la Communauté Facebook des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez [|link_sf_facebook|] et rejoignez-nous aujourd'hui !

.. _sh_shooting:

2.13 JEU - Tir
====================================

Avez-vous déjà vu ces jeux de tir à la télévision ? Plus un concurrent tire une balle près du centre de la cible, plus son score est élevé.

Aujourd'hui, nous réalisons également un jeu de tir sur Scratch. Dans le jeu, faites tirer le Réticule le plus loin possible vers le centre de la cible pour obtenir un score plus élevé.

Cliquez sur le drapeau vert pour commencer. Utilisez le module d'Évitement d'Obstacles pour tirer une balle.

.. image:: img/14_shooting.png

Vous Apprendrez
---------------------

- Comment fonctionne le module d'Évitement d'Obstacles et sa plage d'angle
- Peindre différents sprites
- Toucher des couleurs

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
    *   - :ref:`cpn_avoid`
        - |link_obstacle_avoidance_buy|

Construisez le Circuit
-----------------------

Le module d'évitement d'obstacles est un capteur infrarouge de proximité à distance réglable dont la sortie est normalement haute et devient basse lorsqu'un obstacle est détecté.

Construisez maintenant le circuit selon le schéma ci-dessous.

.. image:: img/circuit/avoid_circuit.png

Programmation
------------------

**1. Peindre le sprite Réticule**

Supprimez le sprite par défaut, sélectionnez le bouton **Sprite** et cliquez sur **Paint**, un sprite vierge **Sprite1** apparaîtra et nommez-le **Crosshair**.

.. image:: img/14_shooting0.png


Allez à la page **Costumes** du sprite **Crosshair**. Cliquez sur l'outil **Circle**, retirez la couleur de remplissage et définissez la couleur et la largeur du contour.

.. image:: img/14_shooting02.png

Dessinez maintenant un cercle avec l'outil **Circle**. Après le dessin, vous pouvez cliquer sur l'outil **Select** et déplacer le cercle de sorte que le point d'origine soit aligné avec le centre du canevas.

.. image:: img/14_shooting03.png

Utilisez l'outil **Line** pour dessiner une croix à l'intérieur du cercle.

.. image:: img/14_shooting033.png

**Peindre le sprite Cible**

Créez un nouveau sprite appelé sprite **Target**.

.. image:: img/14_shooting01.png

Allez à la page Costumes du sprite **Target**, cliquez sur l'outil **Circle**, sélectionnez une couleur de remplissage et supprimez le contour et peignez un grand cercle.

.. image:: img/14_shooting05.png

Utilisez la même méthode pour dessiner des cercles supplémentaires, chacun de couleur différente, et vous pouvez utiliser les outils **Forward** ou **Backbard** pour changer la position des cercles qui se chevauchent. Notez que vous devez également sélectionner l'outil pour déplacer les cercles, afin que l'origine de tous les cercles et le centre du canevas soient alignés.

.. image:: img/14_shooting04.png

**3. Ajouter un décor**

Ajoutez un fond approprié qui de préférence n'a pas trop de couleurs et ne correspond pas aux couleurs dans le sprite **Target**. Ici, j'ai choisi le décor **Wall1**.

.. image:: img/14_shooting06.png

**4. Scripter le sprite Réticule**

Définissez la position et la taille aléatoires du sprite **Crosshair**, et laissez-le se déplacer de manière aléatoire.

.. image:: img/14_shooting4.png

Lorsqu'une main est placée devant le module d'évitement d'obstacles, il émet un niveau bas comme signal de transmission.

.. image:: img/14_shooting5.png

Lorsque le message **shooting** est reçu, le sprite arrête de bouger et rétrécit lentement, simulant ainsi l'effet d'un tir de balle.

.. image:: img/14_shooting6.png

Utilisez le bloc [Touch color ()] pour déterminer la position du tir.

.. image:: img/14_shooting7.png

Lorsque le tir est à l'intérieur du cercle jaune, 10 est annoncé.

.. image:: img/14_shooting8.png

Utilisez la même méthode pour déterminer la position du tir, si ce n'est pas sur le sprite **Target**, cela signifie qu'il est en dehors du cercle.

.. image:: img/14_shooting9.png
