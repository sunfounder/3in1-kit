.. _sh_eat_apple:

2.16 JEU - Manger la Pomme
==============================

Dans ce projet, nous jouons à un jeu qui utilise un bouton pour contrôler un scarabée afin de manger une pomme.

Lorsque le drapeau vert est cliqué, appuyez sur le bouton et le scarabée tournera, appuyez à nouveau sur le bouton et le scarabée s'arrête de courir et avance dans cet angle. Vous devez contrôler l'angle du scarabée pour qu'il avance sans toucher la ligne noire sur la carte jusqu'à ce qu'il mange la pomme. Si il touche la ligne noire, le jeu est terminé.

.. image:: img/14_apple.png

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
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_capacitor`
        - |link_capacitor_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|

Construisez le Circuit
-----------------------

Le bouton est un dispositif à 4 broches, puisque la broche 1 est connectée à la broche 2, et la broche 3 à la broche 4, lorsque le bouton est pressé, les 4 broches sont connectées, fermant ainsi le circuit.

.. image:: img/5_buttonc.png

Construisez le circuit selon le schéma suivant.

* Connectez l'une des broches du côté gauche du bouton à la broche 12, qui est connectée à une résistance de tirage et à un condensateur de 0.1uF (104) (pour éliminer le jitter et émettre un niveau stable lorsque le bouton fonctionne).
* Connectez l'autre extrémité de la résistance et du condensateur à GND, et l'une des broches du côté droit du bouton à 5V.

.. image:: img/circuit/button_circuit.png

Programmation
------------------
L'effet que nous voulons atteindre est d'utiliser le bouton pour contrôler la direction du sprite **Beetle** pour avancer et manger la pomme sans toucher la ligne noire sur le décor **Maze**, ce qui changera le décor lorsqu'elle sera mangée.

Ajoutez maintenant les décors et sprites pertinents.

**1. Ajouter des décors et des sprites**

Ajoutez un décor **Maze** via le bouton **Choose a backdrop**.

.. image:: img/14_backdrop.png

Supprimez le sprite par défaut, puis sélectionnez le sprite **Beetle**.

.. image:: img/14_sprite.png

Placez le sprite **Beetle** à l'entrée du décor **Maze**, en notant les valeurs des coordonnées x, y à ce point, et redimensionnez le sprite à 40%.

.. image:: img/14_sprite1.png

**2. Dessiner un décor**

Il est maintenant temps de dessiner simplement un décor avec le personnage GAGNÉ ! apparaissant dessus.

Cliquez d'abord sur la miniature du décor pour aller à la page **Backdrops** et cliquez sur le décor vierge1.

.. image:: img/14_paint_back.png
    :width: 800

Commencez maintenant à dessiner, vous pouvez vous référer à l'image ci-dessous pour dessiner, ou vous pouvez dessiner un décor par vous-même, tant que l'expression est gagnante.

* Utilisez l'outil **Circle** pour dessiner une ellipse avec la couleur réglée sur rouge et sans contour.
* Ensuite, utilisez l'outil **Text**, écrivez le caractère \"GAGNÉ !\", réglez la couleur du caractère sur noir et ajustez la taille et la position du caractère.
* Nommez le décor **Win**.

.. image:: img/14_win.png

**3. Scripter pour le décor**

Le décor doit être changé en **Maze** à chaque début de jeu.

.. image:: img/14_switchback.png

**4. Écrire des scripts pour le sprite Scarabée**

Écrivez maintenant un script pour le sprite **Beetle** pour pouvoir avancer et changer de direction sous le contrôle d'un bouton. Le flux de travail est le suivant.

* Lorsque le drapeau vert est cliqué, réglez l'angle du **Beetle** à 90, et la position à (-134, -134), ou remplacez-la par la valeur de coordonnée de votre propre position placée. Créez la variable **flag** et réglez la valeur initiale à -1.

.. image:: img/14_bee1.png

Ensuite, dans le bloc [forever], quatre blocs [if] sont utilisés pour déterminer divers scénarios possibles.

* Si la clé est 1 (pressée), utilisez le bloc [`mod <https://en.scratch-wiki.info/wiki/Boolean_Block>`_] pour basculer la valeur de la variable **flag** entre 0 et 1 (alternant entre 0 pour cette pression et 1 pour la pression suivante).

.. image:: img/14_bee2.png

* Si flag=0 (cette pression de touche), laissez le sprite **Beetle** tourner dans le sens horaire. Puis déterminez si flag est égal à 1 (touche pressée à nouveau), le sprite **Beetle** avance. Sinon, il continue à tourner dans le sens horaire.

.. image:: img/14_bee3.png

* Si le sprite Scarabée touche le noir (la ligne noire sur le décor **Maze**), le jeu se termine et le script cesse de fonctionner.

.. note::
    
    Vous devez cliquer sur la zone de couleur dans le bloc [Touch color], puis sélectionner l'outil pipette pour prendre la couleur de la ligne noire sur la scène. Si vous choisissez un noir arbitrairement, ce bloc [Touch color] ne fonctionnera pas.


.. image:: img/14_bee5.png

* Si le Scarabée touche le rouge (Utilisez également l'outil paille pour prendre la couleur rouge de la pomme), le décor sera changé en **Win**, ce qui signifie que le jeu réussit et arrête le script de fonctionner.


.. image:: img/14_bee4.png





