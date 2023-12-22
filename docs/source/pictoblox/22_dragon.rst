.. _sh_dragon:

2.22 JEU - Tueur de Dragon
============================

Ici, nous utilisons un joystick pour jouer à un jeu de chasse au dragon.

En cliquant sur le bouton vert, le dragon flottera de haut en bas sur le côté droit et crachera du feu par intermittence. Vous devez utiliser le joystick pour contrôler le mouvement de la baguette magique et lancer des attaques d'étoiles sur le dragon, tout en évitant les flammes qu'il projette, et finalement le vaincre.

.. image:: img/19_dragon.png

Vous Apprendrez
---------------------

Pour ce projet, nous aurons besoin des composants suivants.

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_joystick`
        - \-

Construire le Circuit
-----------------------

Un joystick est un dispositif d'entrée composé d'un bâton qui pivote sur une base et transmet son angle ou sa direction au dispositif qu'il contrôle. Les joysticks sont souvent utilisés pour contrôler des jeux vidéo et des robots.

Pour communiquer une gamme complète de mouvements à l'ordinateur, un joystick doit mesurer la position du bâton sur deux axes – l'axe X (de gauche à droite) et l'axe Y (de haut en bas).

Les coordonnées de mouvement du joystick sont montrées dans la figure suivante.

.. note::

    * La coordonnée x va de gauche à droite, la plage est de 0 à 1023.
    * La coordonnée y va de haut en bas, la plage est de 0 à 1023.

.. image:: img/16_joystick.png


Maintenant, construisez le circuit selon le schéma suivant.

.. image:: img/circuit/joystick_circuit.png

Programmation
------------------

**1. Dragon**

Ajout du décor **Woods** via le bouton **Choose a Backdrop**.

.. image:: img/19_dragon01.png

* Supprimez le sprite par défaut et ajoutez le sprite **Dragon**.

.. image:: img/19_dragon0.png

* Allez à la page **Costumes** et retournez horizontalement les costumes dragon-b et dragon-c.

.. image:: img/19_dragon1.png

* Réglez la taille à 50%.

.. image:: img/19_dragon3.png

* Créez maintenant une variable - **dragon** pour enregistrer les points de vie du dragon, et réglez la valeur initiale à 50.

.. image:: img/19_dragon2.png

* Ensuite, changez le costume du sprite pour **dragon-b** et faites bouger le sprite **Dragon** de haut en bas dans une certaine plage.

.. image:: img/19_dragon4.png


* Ajoutez un sprite **Lightning** comme le feu soufflé par le sprite **Dragon**. Vous devez le tourner de 90° dans le sens des aiguilles d'une montre sur la page Costumes, ceci pour faire bouger le sprite **Lightning** dans la bonne direction.

.. note::
    Lors de l'ajustement du costume du sprite **Lightning**, vous pouvez le déplacer hors du centre, ce qui doit être évité ! Le point central doit être exactement au milieu du sprite !

.. image:: img/19_lightning1.png



* Ensuite, ajustez le costume **dragon-c** du sprite **Dragon** pour que son point central soit à la queue du feu. Cela permettra d'aligner correctement les positions du sprite **Dragon** et du sprite **Lightning**, et d'éviter que l'**Lightning** ne soit lancé des pieds du dragon. 

.. image:: img/19_dragon5.png

* De même, **dragon-b** doit faire coïncider la tête du dragon avec le point central.

.. image:: img/19_dragon5.png

* Ajustez la taille et l'orientation du sprite **Lightning** pour rendre l'image plus harmonieuse.

.. image:: img/19_lightning3.png

* Programmez maintenant le sprite **Lightning**. C'est simple, faites-le suivre le sprite **Dragon** en permanence. À ce stade, cliquez sur le drapeau vert et vous verrez le **Dragon** se déplacer avec un éclair dans la bouche.

.. image:: img/19_lightning4.png

* Revenez au sprite **Dragon**, maintenant faites-le cracher du feu, en veillant à ce que le feu dans sa bouche ne soit pas projeté, mais à créer un clone pour le sprite **Lightning**.

.. image:: img/19_dragon6.png

* Cliquez sur le sprite **Lightning** et laissez le clone de **Lightning** être projeté sous un angle aléatoire, il rebondira sur le mur et disparaîtra après un certain temps.

.. image:: img/19_lightning5.png

* Dans le sprite **Lightning**, cachez son corps et montrez le clone.

.. image:: img/19_lightning6.png

Maintenant, le dragon peut se déplacer de haut en bas et cracher du feu.


**2. Baguette Magique**

* Créez un sprite **Wand** et tournez sa direction à 180 pour pointer vers la droite.

.. image:: img/19_wand1.png

* Créez maintenant une variable **hp** pour enregistrer sa valeur de vie, initialement réglée sur 3. Puis lisez la valeur du Joystick, qui est utilisée pour contrôler le mouvement de la baguette.

.. image:: img/19_wand2.png

* Le dragon a des éclairs, et la baguette qui les écrase a sa "balle magique" ! Créez un sprite **Star**, redimensionnez-le, et programmez-le pour qu'il suive toujours le sprite **Wand**, et limitez le nombre d'étoiles à trois.

.. image:: img/19_star2.png

* Faites tirer des étoiles automatiquement par le sprite **Wand**. Le sprite **Wand** tire des étoiles de la même manière que le dragon crache du feu -- en créant des clones.

.. image:: img/19_wand3.png


* Revenez au sprite **Star** et programmez son clone pour qu'il tourne et tire vers la droite, disparaisse après avoir dépassé la scène et restaure le nombre d'étoiles. Comme pour le sprite **Lightning**, cachez le corps et montrez le clone.

.. image:: img/19_star3.png

Maintenant, nous avons une baguette qui tire des balles d'étoiles.

**3. Combat !**

La baguette et le dragon sont actuellement encore en désaccord l'un avec l'autre, et nous allons les faire combattre. Le dragon est fort, et la baguette est le brave homme qui part en croisade contre le dragon. L'interaction entre eux se compose des parties suivantes.


1. si la baguette touche le dragon, elle sera repoussée et perdra des points de vie.
2. si un éclair frappe la baguette, la baguette perdra des points de vie.
3. si la balle d'étoile touche le dragon, le dragon perdra des points de vie.


Une fois cela résolu, passons à la modification des scripts pour chaque sprite.

* Si la **Wand** touche le **Dragon**, elle sera repoussée et perdra des points de vie.

.. image:: img/19_wand4.png

* Si **Lightning** (un clone du sprite **Lightning**) touche le sprite **Wand**, il produira un son de pop et disparaîtra, et la **Wand** perdra des points de vie.

.. image:: img/19_lightning7.png

* Si une **Star** (clone du sprite **Star**) touche le **Dragon**, elle émettra un son de collecte et disparaîtra, tout en restaurant le nombre d'**Star**, et le **Dragon** perdra des points de vie.

.. image:: img/19_star4.png


**4. scène**

La bataille entre la **Wand** et le **Dragon** se terminera finalement par des gagnants et des perdants, que nous représentons avec la scène.

* Ajoutez l'arrière-plan **Blue Sky**, et écrivez le mot "VICTOIRE !" dessus pour représenter que le dragon a été vaincu et l'aube est arrivée.


.. image:: img/19_sky0.png

* Et modifiez l'arrière-plan vierge comme suit, pour représenter que le jeu a échoué et tout sera dans l'obscurité.

.. image:: img/19_night.png

* Écrivez maintenant un script pour changer ces arrière-plans, lorsque le drapeau vert est cliqué, passez à l'arrière-plan **Woods** ; si le point de vie du dragon est inférieur à 1, alors le jeu réussit et changez l'arrière-plan pour **Blue Sky** ; si le point de valeur de vie de la **Wand** est inférieur à 1, alors changez pour l'arrière-plan **Night** et le jeu échoue.


.. image:: img/19_sky1.png

