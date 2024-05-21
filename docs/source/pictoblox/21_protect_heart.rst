.. note::

    Bonjour et bienvenue dans la Communauté Facebook des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez [|link_sf_facebook|] et rejoignez-nous aujourd'hui !

.. _sh_protect_heart:

2.21 JEU - Protège ton Cœur
=====================================

Dans ce projet, créons un jeu qui teste la vitesse de réaction.

Sur la scène, un cœur est protégé dans une boîte rectangulaire, et des flèches volent vers ce cœur depuis n'importe quelle position sur la scène. La couleur des flèches alterne aléatoirement entre noir et blanc, et leur vitesse augmente progressivement.

Si la couleur de la boîte rectangulaire et celle de la flèche sont identiques, la flèche est bloquée à l'extérieur et le niveau augmente de 1 ; si leurs couleurs diffèrent, la flèche transperce le cœur et la partie se termine.

Ici, la couleur de la boîte rectangulaire est contrôlée par le module de Suivi de Ligne. Lorsque ce module est placé sur une surface noire (une surface réfléchissante), la couleur de la boîte est noire, sinon elle est blanche.

Ainsi, vous devez décider de placer le module de Suivi de Ligne sur une surface blanche ou noire en fonction de la couleur de la flèche.

.. image:: img/22_heart.png

Composants requis
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
    *   - :ref:`cpn_track` 
        - |link_track_buy|


Construisez le Circuit
-----------------------

Il s'agit d'un module numérique de Suivi de Ligne, lorsqu'une ligne noire est détectée, il sort une valeur de 1 ; lorsqu'une ligne blanche est détectée, il sort une valeur de 0. De plus, vous pouvez ajuster sa distance de détection grâce au potentiomètre sur le module.

Construisez maintenant le circuit selon le schéma ci-dessous.

.. image:: img/circuit/linetrack_circuit.png

.. note::

    Avant de commencer le projet, vous devez ajuster la sensibilité du module.

    Câblez selon le schéma ci-dessus, puis alimentez la carte R3 (soit directement via le câble USB, soit via le câble de la pile bouton 9V), sans télécharger le code.

    Collez maintenant un ruban électrique noir sur le bureau, placez le module de Suivi de Ligne à une hauteur de 2 cm du bureau.

    Avec le capteur orienté vers le bas, observez la LED de signal sur le module pour vous assurer qu'elle s'allume sur la table blanche et s'éteint sur le ruban noir.

    Si ce n'est pas le cas, vous devez ajuster le potentiomètre sur le module, afin qu'il puisse produire l'effet ci-dessus.


Programmation
------------------

Ici, nous devons créer 3 sprites : **Heart**, **Square Box** et **Arrow1**.

* **Heart** : reste au milieu de la scène, si touché par le sprite **Arrow1**, la partie est terminée.
* **Square Box** : Deux types de costumes, noir et blanc, changeront selon la valeur du module de Suivi de Ligne.
* **Arrow** : vole vers le milieu de la scène depuis n'importe quelle position en noir/blanc ; si sa couleur correspond à celle du sprite **Square Box**, elle est bloquée et revole vers le milieu de la scène depuis une position aléatoire ; si sa couleur ne correspond pas à celle du sprite **Square Box**, elle traverse le sprite **Heart** et la partie se termine.

**1. Ajouter le sprite Boîte Carrée**

Puisque les sprites Flèche1 et Boîte Carrée ont tous deux des costumes blancs, afin qu'ils puissent être affichés sur la scène, remplissez maintenant l'arrière-plan avec une couleur qui peut être n'importe quelle couleur sauf noir, blanc et rouge.

* Cliquez sur **Backdrop1** pour accéder à sa page **Backdrops**.
* Sélectionnez la couleur que vous souhaitez remplir.
* Utilisez l'outil **Rectangle** pour dessiner un rectangle de la même taille que le tableau de dessin.

.. image:: img/22_heart0.png

Supprimez le sprite par défaut, utilisez le bouton **Choose a Sprite** pour ajouter le sprite **Square Box**, et réglez ses coordonnées x et y à (0, 0).

.. image:: img/22_heart1.png

Allez à la page **Costumes** du sprite **Square Box** et réglez les costumes noir et blanc.

* Cliquez sur l'outil de sélection
* Sélectionnez le rectangle sur le canevas
* Sélectionnez la couleur de remplissage en noir
* et nommez le costume **Black**

.. image:: img/22_heart2.png

Sélectionnez le deuxième costume, réglez la couleur de remplissage en blanc, nommez-le Blanc et supprimez les autres costumes.

.. image:: img/22_heart3.png

**2. Ajouter le sprite Cœur**

Ajoutez également un sprite **Heart**, réglez sa position à (0, 0), et réduisez sa taille pour qu'il semble être situé à l'intérieur de la Boîte Carrée.

.. image:: img/22_heart5.png

Sur la page **Costumes**, ajustez le costume violet du cœur pour qu'il semble être brisé.

.. image:: img/22_heart6.png

**3. Ajouter le sprite Flèche1**

Ajoutez un sprite **Arrow1**.

.. image:: img/22_heart7.png

Sur la page **Costumes**, gardez et copiez le costume orienté vers la droite et réglez sa couleur en noir et blanc.

.. image:: img/22_heart8.png


**4. Script pour le sprite Boîte Carrée**

Retournez à la page **Blocks** et programmez le sprite **Square Box**.

* Ainsi, lorsque la valeur de la broche numérique 2 (module de Suivi de Ligne) est 1 (ligne noire détectée), alors changez le costume pour **Black**.
* Sinon, basculez le costume en **White**.

.. image:: img/22_heart4.png


**5. Script pour le sprite Cœur**

Le sprite **Heart** est protégé à l'intérieur de **Square Box**, et par défaut a un costume rouge. Lorsque le sprite Flèche1 le touche, la partie se termine.

.. image:: img/22_heart9.png

**6. Script pour le sprite Flèche1**

Faites que le sprite **Arrow1** se cache et crée un clone lorsque le drapeau vert est cliqué.

.. image:: img/22_heart10.png

Créez un bloc [init] pour initialiser la position, l'orientation et la couleur du sprite **Arrow1**.

Il apparaît à un endroit aléatoire, et si la distance entre lui et le sprite **Heart** est inférieure à 200, il se déplace vers l'extérieur jusqu'à ce que la distance soit supérieure à 200.

.. image:: img/22_heart11.png

Réglez sa direction face au sprite **Heart**.

.. image:: img/22_heart12.png

Faites alterner sa couleur aléatoirement entre noir/blanc.

* Si la variable couleur est 0, basculez le costume en **White**.
* Si la variable couleur est 1, basculez le costume en **Black**.

.. image:: img/22_heart14.png

Maintenant, laissez-le commencer à bouger, il se déplacera plus vite au fur et à mesure que la valeur de la variable **level** augmente.

.. image:: img/22_heart13.png

Maintenant, réglez son effet de collision avec le sprite **Square Box**.

* Si le sprite **Arrow1** et le sprite **Square Box** ont la même couleur (qui sera modifiée selon la valeur du module de Suivi de Ligne), soit noir soit blanc, un nouveau clone est créé et la partie continue.
* Si leurs couleurs ne correspondent pas, le sprite **Arrow1** continue de se déplacer et la partie se termine lorsqu'il heurte le sprite **Heart**.

.. image:: img/22_heart15.png

.. note::
    Les deux blocs [touch color()] doivent prendre en compte les costumes noir/blanc de Boîte Carrée séparément.

    .. image:: img/22_heart16.png

