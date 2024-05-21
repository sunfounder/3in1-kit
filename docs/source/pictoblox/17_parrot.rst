.. note::

    Bonjour et bienvenue dans la Communauté Facebook des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez [|link_sf_facebook|] et rejoignez-nous aujourd'hui !

.. _sh_parrot:

2.17 JEU - Perroquet Volant
==============================

Ici, nous utilisons le module ultrasonique pour jouer à un jeu de perroquet volant.

Après l'exécution du script, le bambou vert se déplacera lentement de la droite vers la gauche à une hauteur aléatoire. Maintenant, placez votre main au-dessus du module ultrasonique, si la distance entre votre main et le module ultrasonique est inférieure à 10, le perroquet s'envolera vers le haut, sinon il tombera vers le bas.
Vous devez contrôler la distance entre votre main et le module ultrasonique pour que le Perroquet puisse éviter le bambou vert (Paddle), s'il le touche, le jeu est terminé.

.. image:: img/15_parrot.png

Composants Requis
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
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|

Construisez le Circuit
-----------------------

Un module capteur ultrasonique est un instrument qui mesure la distance jusqu'à un objet en utilisant des ondes sonores ultrasoniques. 
Il a deux sondes. L'une sert à envoyer des ondes ultrasoniques et l'autre à recevoir les ondes et à transformer le temps d'envoi et de réception en distance, détectant ainsi la distance entre l'appareil et un obstacle.

Construisez maintenant le circuit selon le schéma suivant.

.. image:: img/circuit/ultrasonic_circuit.png

Programmation
------------------

L'effet que nous voulons atteindre est d'utiliser le module ultrasonique pour contrôler la hauteur de vol du sprite **Parrot**, tout en évitant le sprite **Paddle**.


**1. Ajouter un sprite**

Supprimez le sprite par défaut et utilisez le bouton **Choose a Sprite** pour ajouter le sprite **Parrot**. Réglez sa taille à 50% et déplacez sa position vers le centre gauche.

.. image:: img/15_sprite.png

Ajoutez maintenant le sprite **Paddle**, réglez sa taille à 150%, son angle à 180 et déplacez sa position initiale dans le coin supérieur droit.

.. image:: img/15_sprite1.png

Allez à la page **Costumes** du sprite **Paddle** et supprimez le Contour.

.. image:: img/15_sprite2.png

**2. Scripter pour le sprite Perroquet**

Scriptez maintenant le sprite **Parrot**, qui est en vol et dont l'altitude de vol est déterminée par la distance de détection du module ultrasonique.


* Lorsque le drapeau vert est cliqué, changez le costume toutes les 0,2 secondes pour qu'il soit toujours en vol.

.. image:: img/15_parr1.png

* Lisez la valeur du module ultrasonique et stockez-la dans la variable **distance** après l'avoir arrondie avec le bloc [round].

.. image:: img/15_parr2.png

* Si la distance de détection ultrasonique est inférieure à 10 cm, laissez la coordonnée y augmenter de 50, le sprite **Parrot** volera vers le haut. Sinon, la valeur de la coordonnée y est diminuée de 40, le **Parrot** tombera.

.. image:: img/15_parr3.png

* Si le sprite **Parrot** touche le sprite **Paddle**, le jeu se termine et le script cesse de fonctionner.

.. image:: img/15_parr4.png


**3. Scripter pour le sprite Pagaie**

Écrivez maintenant le script pour le sprite **Paddle**, qui doit apparaître aléatoirement sur la scène.

* Cachez le sprite **Paddle** lorsque le drapeau vert est cliqué, et clonez-le en même temps. Le bloc [`create clone of <https://en.scratch-wiki.info/wiki/Create_Clone_of_()_(block)>`_] est un bloc de contrôle et un bloc empilable. Il crée un clone du sprite dans l'argument. Il peut aussi cloner le sprite dans lequel il s'exécute, créant des clones de clones, de manière récursive.

.. image:: img/15_padd.png

* Lorsque **Paddle** est présenté comme un clone, sa position est de 220 (le plus à droite) pour la coordonnée x et sa coordonnée y à (-125 à 125) aléatoire (hauteur aléatoire).

.. image:: img/15_padd1.png

* Utilisez le bloc [repeat] pour faire diminuer lentement sa valeur de coordonnée x, ainsi vous pouvez voir le clone du sprite **Paddle** se déplacer lentement de la droite vers la gauche jusqu'à ce qu'il disparaisse.

.. image:: img/15_padd2.png

* Reclonez un nouveau sprite **Paddle** et supprimez le clone précédent.

.. image:: img/15_padd3.png
