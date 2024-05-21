.. note::

    Bonjour et bienvenue dans la Communauté Facebook des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez [|link_sf_facebook|] et rejoignez-nous aujourd'hui !

.. _sh_balloon:

2.14 JEU - Gonfler le Ballon
=========================================

Ici, nous allons jouer à un jeu de gonflage de ballon.

Après avoir cliqué sur le drapeau vert, le ballon deviendra de plus en plus gros. Si le ballon est trop gros, il explosera ; si le ballon est trop petit, il tombera ; vous devez juger quand appuyer sur le bouton pour le faire monter.

.. image:: img/13_balloon0.png

Vous Apprendrez
---------------------

- Peindre un costume pour le sprite

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

**1. Ajouter un sprite et un décor**

Supprimez le sprite par défaut, cliquez sur le bouton **Choose a Sprite** dans le coin inférieur droit de la zone de sprite, puis sélectionnez le sprite **Balloon1**.

.. image:: img/13_balloon1.png

Ajoutez un décor **Boardwalk** via le bouton **Choose a backdrop**, ou d'autres décors de votre choix.

.. image:: img/13_balloon2.png

**2. Peindre un costume pour le sprite Ballon1**

Dessinons maintenant un costume d'effet d'explosion pour le sprite de ballon.

Allez à la page **Costumes** pour le sprite **Balloon1**, cliquez sur le bouton **Choose a Costume** dans le coin inférieur gauche, et sélectionnez **Paint** pour afficher un **Costume** vierge.

.. image:: img/13_balloon7.png

Sélectionnez une couleur, puis utilisez l'outil **Brush** pour dessiner un motif.

.. image:: img/13_balloon3.png

Sélectionnez à nouveau une couleur, cliquez sur l'outil Remplir, et déplacez la souris à l'intérieur du motif pour le remplir d'une couleur.

.. image:: img/13_balloon4.png

Enfin, écrivez le texte BOUM, afin qu'un costume d'effet d'explosion soit complet.

.. image:: img/13_balloon5.png

**3. Scripter le sprite Ballon**

Définissez la position et la taille initiales du sprite **Balloon1**.

.. image:: img/13_balloon6.png

Puis laissez le sprite **Balloon** grossir lentement.

.. image:: img/13_balloon8.png

Lorsque le bouton est pressé (valeur est 1), la taille du sprite **Balloon1** cesse de grossir.

* Lorsque la taille est inférieure à 90, il tombera (la coordonnée y diminue).
* Lorsque la taille est supérieure à 90 et inférieure à 120, il volera vers le ciel (la coordonnée y augmente).

.. image:: img/13_balloon9.png

Si le bouton n'a pas été pressé, le ballon grossit lentement et quand la taille dépasse 120, il explosera (basculer vers le costume d'effet d'explosion).

.. image:: img/13_balloon10.png


