.. _sh_rotating_fan:

2.11 Ventilateur Rotatif
========================

Dans ce projet, nous allons créer un sprite d'étoile tournante et un ventilateur.

Cliquer sur les sprites de flèche gauche et droite sur la scène contrôlera la rotation dans le sens horaire et antihoraire du moteur et du sprite étoile, cliquez sur le sprite étoile pour arrêter la rotation.

.. image:: img/13_fan.png

Vous Apprendrez
---------------------

- Principe de fonctionnement d'un moteur
- Fonction de diffusion
- Arrêter d'autres scripts dans le bloc de sprite

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
    *   - :ref:`cpn_tt_motor`
        - \-
    *   - :ref:`cpn_l9110`
        - \-

Construisez le Circuit
-----------------------

.. image:: img/circuit/motor_circuit.png

Programmation
------------------
L'effet que nous voulons atteindre est d'utiliser 2 sprites flèche pour contrôler respectivement la rotation dans le sens horaire et antihoraire du moteur et du sprite étoile, cliquer sur le sprite étoile arrêtera la rotation du moteur.

**1. Ajouter des sprites**

Supprimez le sprite par défaut, puis sélectionnez le sprite **Star** et le sprite **Arrow1**, et copiez **Arrow1** une fois.

.. image:: img/13_star.png

Dans l'option **Costumes**, changez le sprite **Arrow1** pour un costume de direction différente.

.. image:: img/13_star1.png

Ajustez la taille et la position du sprite de manière appropriée.

.. image:: img/13_star2.png

**2. Sprite de flèche gauche**

Quand ce sprite est cliqué, il diffuse un message - tourner, puis définit la broche numérique 9 à bas et la broche 10 à haut, et définit la variable **flag** à 1. Si vous cliquez sur le sprite de flèche gauche, vous constaterez que le moteur tourne dans le sens antihoraire, si votre tour est dans le sens horaire, alors vous échangez les positions des broches 9 et 10.

Il y a 2 points à noter ici.

* `[broadcast <https://en.scratch-wiki.info/wiki/Broadcast>`_]: de la palette **Events**, utilisé pour diffuser un message aux autres sprites, quand les autres sprites reçoivent ce message, ils exécuteront un événement spécifique. Par exemple, ici c'est **turn**, quand le sprite **star** reçoit ce message, il exécute le script de rotation.
* variable flag : La direction de rotation du sprite étoile est déterminée par la valeur de flag. Donc, quand vous créez la variable **flag**, vous devez la rendre applicable à tous les sprites.

.. image:: img/13_left.png

**3. Sprite de flèche droite**

Quand ce sprite est cliqué, diffusez un message tourner, puis réglez la broche numérique 9 à haut et la broche 10 à bas pour faire tourner le moteur dans le sens horaire et définissez la variable **flag** à 0.

.. image:: img/13_right.png

**4. Sprite étoile**

Il y a 2 événements inclus ici.

* Quand le sprite **star** reçoit le message diffusé tourner, il détermine la valeur de flag ; si flag est 1, il tourne de 10 degrés à gauche, sinon il inverse. Comme il est dans [FOREVER], il continuera à tourner.
* Quand ce sprite est cliqué, réglez les deux broches du moteur à haut pour le faire arrêter de tourner et arrêtez les autres scripts dans ce sprite.

.. image:: img/13_broadcast.png

