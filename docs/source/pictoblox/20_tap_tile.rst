.. note::

    Bonjour et bienvenue dans la Communauté Facebook des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez [|link_sf_facebook|] et rejoignez-nous aujourd'hui !

.. _sh_tap_tile:

2.20 JEU - Ne Touchez Pas la Tuile Blanche
==========================================

Je suis sûr que beaucoup d'entre vous ont joué à ce jeu sur vos téléphones portables. Ce jeu se joue en tapotant sur des blocs noirs apparaissant aléatoirement pour ajouter des points, la vitesse devient de plus en plus rapide, tapotez sur des blocs blancs ou manquez des blocs noirs et la partie se termine.

Maintenant, nous utilisons PictoBlox pour le reproduire.

Insérez deux modules d'évitement d'obstacles IR verticalement sur la plaque de montage, lorsque votre main est placée au-dessus de l'un des modules IR, un point clignotant apparaîtra sur la scène, représentant une touche effectuée.

Si la touche est sur le bloc noir, le score augmente de 1, touchez le bloc blanc, le score diminue de 1.

Vous devez décider de placer votre main au-dessus du module IR à gauche ou au-dessus du module IR à droite, en fonction de la position du bloc noir sur la scène.


.. image:: img/21_tile.png

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
    *   - :ref:`cpn_avoid` 
        - |link_obstacle_avoidance_buy|


Construisez le Circuit
-----------------------

Le module d'évitement d'obstacles est un capteur de proximité infrarouge à distance réglable dont la sortie est normalement haute et basse lorsqu'un obstacle est détecté.

Construisez maintenant le circuit selon le schéma ci-dessous.

.. image:: img/circuit/2avoid_circuit.png

Programmation
------------------

Ici, nous avons besoin de 3 sprites, **Tile**, **Left IR** et **Right IR**.

* Sprite **Tile** : utilisé pour obtenir l'effet d'alternance des tuiles noires et blanches vers le bas, dans le jeu sur téléphone portable, il y a généralement 4 colonnes, ici nous en ferons seulement deux.
* Sprite **Left IR** : utilisé pour réaliser l'effet de clic, lorsque le module IR gauche détecte votre main, il enverra un message - **left** au sprite **Left IR**, le laissant commencer à travailler. S'il touche la tuile noire sur la scène, le score augmentera de 1, sinon le score diminuera de 1.
* Sprite **Right IR** : La fonction est essentiellement la même que **Left IR**, sauf qu'il reçoit l'information **Right**.

**1. Peindre un sprite Tuile**.

Supprimez le sprite par défaut, passez la souris sur l'icône **Add Sprite**, sélectionnez **Paint** et un sprite vierge apparaîtra et nommez-le **Tile**.

.. image:: img/21_tile1.png

Allez à la page **Costumes** et utilisez l'outil **Rectangle** pour dessiner un rectangle.

.. image:: img/21_tile2.png

Sélectionnez le rectangle et cliquez sur **Copy** -> **Paste** pour faire un rectangle identique, puis déplacez les deux rectangles en position alignée.

.. image:: img/21_tile01.png

Sélectionnez l'un des rectangles et choisissez une couleur de remplissage noire.

.. image:: img/21_tile02.png

Sélectionnez maintenant les deux rectangles et déplacez-les de sorte que leurs points centraux correspondent au centre du canevas.

.. image:: img/21_tile0.png

Dupliquez le costume1, en alternant les couleurs de remplissage des deux rectangles. Par exemple, la couleur de remplissage du costume1 est blanche à gauche et noire à droite, et la couleur de remplissage du costume2 est noire à gauche et blanche à droite.

.. image:: img/21_tile3.png

**2. Scripter le sprite Tuile**

Retournez maintenant à la page **Blocks** et réglez la position initiale du sprite **Tile** pour qu'il soit en haut de la scène.

.. image:: img/21_tile4.png

Créez une variable - **blocks** et donnez-lui une valeur initiale pour déterminer le nombre de fois où le sprite **Tile** apparaîtra. Utilisez le bloc [repeat until] pour faire diminuer progressivement la variable **blocks** jusqu'à ce que **blocks** soit 0. Pendant ce temps, faites en sorte que le sprite **Tile** change aléatoirement de costume.

Après avoir cliqué sur le drapeau vert, vous verrez le sprite **Tile** sur la scène changer rapidement de costume.

.. image:: img/21_tile5.png

Créez des clones du sprite **Tile** pendant que la variable **blocks** diminue, et arrêtez l'exécution du script lorsque blocs est 0. Deux blocs [wait () seconds] sont utilisés ici, le premier pour limiter l'intervalle entre les clones de **Tile's** et le second pour permettre à la variable blocs de diminuer à 0 sans arrêter immédiatement le programme, donnant au dernier sprite de tuile suffisamment de temps pour se déplacer.


.. image:: img/21_tile6.png

Maintenant, scriptez le clone du sprite **Tile** pour qu'il descende lentement et supprimez-le lorsqu'il atteint le bas de la scène. Le changement dans la coordonnée y affecte la vitesse de chute, plus la valeur est grande, plus la vitesse de chute est rapide.

.. image:: img/21_tile7.png

Cachez le corps et affichez le clone.

.. image:: img/21_tile8.png

**3. Lire les valeurs des 2 modules IR**

Dans le décor, lisez les valeurs des 2 modules IR et effectuez les actions correspondantes.

* Si le module d'évitement d'obstacles IR gauche détecte votre main, diffusez un message - **left**.
* Si le module d'évitement IR gauche détecte votre main, diffusez un message - **right**.

.. image:: img/21_tile9.png

**4. Sprite IR Gauche**

Encore une fois, passez la souris sur l'icône **Add sprite** et sélectionnez **Paint** pour créer un nouveau sprite appelé **Left IR**.

.. image:: img/21_tile10.png

Allez à la page **Costumes** du sprite **Left IR**, sélectionnez la couleur de remplissage (n'importe quelle couleur hors noir et blanc) et dessinez un cercle.

.. image:: img/21_tile11.png

Commencez maintenant à scripter le sprite **Left IR**. Lorsque le message - **left** est reçu (le module récepteur IR à gauche détecte un obstacle), déterminez alors si le bloc noir du sprite **Tile** est touché, et si c'est le cas, laissez la variable **count** ajouter 1, sinon soustraire 1.

.. image:: img/21_tile12.png

.. note::

    Vous devez faire apparaître le sprite **Tile** sur la scène, puis absorber la couleur du bloc noir dans le sprite **Tile**.

    .. image:: img/21_tile13.png

Maintenant, faisons l'effet de détection (agrandir et rétrécir) pour **Left IR**.

.. image:: img/21_tile14.png

Faites en sorte que le sprite **Left IR** se cache lorsque le drapeau vert est cliqué, s'affiche lorsque le message - **left** est reçu, et se cache à nouveau enfin.

.. image:: img/21_tile15.png

**5. Sprite IR Droit**

Copiez le sprite **Left IR** et renommez-le en **Right IR**.

.. image:: img/21_tile16.png

Changez ensuite le message reçu en - **right**.

.. image:: img/21_tile17.png

Maintenant que toute la programmation est terminée, vous pouvez cliquer sur le drapeau vert pour exécuter le script.
