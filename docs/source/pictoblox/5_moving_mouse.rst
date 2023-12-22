.. _sh_moving_mouse:

2.5 Souris Mobile
===================

Aujourd'hui, nous allons créer un jouet en forme de souris contrôlé par un potentiomètre.

Lorsque le drapeau vert est cliqué, la souris sur la scène avance, et lorsque vous tournez le potentiomètre, la souris change de direction de mouvement.

.. image:: img/6_mouse.png

Vous Apprendrez
---------------------

- Principe du potentiomètre
- Lire une broche analogique et ses plages de valeurs
- Mapper une plage de valeurs à une autre
- Déplacer et changer la direction d'un sprite

Composants requis
---------------------

Pour ce projet, nous avons besoin des composants suivants.

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

Construire le Circuit
-----------------------

Le potentiomètre est un élément résistif avec 3 bornes, les 2 broches latérales sont connectées à 5V et GND, et la broche centrale est connectée à A0. Après conversion par le convertisseur ADC de la carte Arduino, la plage de valeurs est de 0-1023.

.. image:: img/circuit/potentiometer_circuit.png

Programmation
------------------

**1. Choisir un sprite**

Supprimez le sprite par défaut, cliquez sur le bouton **Choose a Sprite** dans le coin inférieur droit de la zone de sprite, entrez **mouse** dans la boîte de recherche, puis cliquez pour l'ajouter.

.. image:: img/6_sprite.png

**2. Création d'une variable**.

Créez une variable nommée **value** pour stocker la valeur lue du potentiomètre.

Une fois créée, vous verrez **value** apparaître dans la palette **Variables** et dans l'état coché, ce qui signifie que cette variable apparaîtra sur la scène.

.. image:: img/6_value.png

**3. Lire la valeur de A0**

Stockez la valeur lue de A0 dans la variable **value**.

* [set my variable to 0] : Définir la valeur de la variable.
* [read analog pin A0] : Lire la valeur de A0~A5 dans la plage de 0-1023.

.. image:: img/6_read_a0.png

Pour pouvoir lire en continu, vous devez utiliser le bloc [forever]. Cliquez sur ce script pour l'exécuter, tournez le potentiomètre dans les deux sens, et vous verrez que la plage de valeurs est de 0-1023.

.. image:: img/6_1023.png

**4. Déplacer le sprite**

Utilisez le bloc [move steps] pour déplacer le sprite, exécutez le script et vous verrez le sprite se déplacer du milieu vers la droite.

.. image:: img/6_move.png

**5. Changer la direction du sprite**

Changez maintenant la direction du mouvement du sprite par la valeur de A0. Comme la valeur de A0 varie de 0-1023, mais la direction de rotation du sprite est de -180~180, un bloc [map] doit être utilisé.

Ajoutez également [when green flag clicked] au début pour démarrer le script.

* [`point in direction <https://en.scratch-wiki.info/wiki/Point_in_Direction_()_(block)>`_] : Définir l'angle de direction du sprite, de la palette **Motion**.
* [map from to] : Mapper une plage à une autre plage.

.. image:: img/6_direction.png






