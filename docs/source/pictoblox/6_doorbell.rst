.. note::

    Bonjour et bienvenue dans la Communauté Facebook des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez [|link_sf_facebook|] et rejoignez-nous aujourd'hui !

.. _sh_doorbell:

2.6 Sonnette
======================

Ici, nous utiliserons le bouton et la cloche sur la scène pour créer une sonnette.

Après avoir cliqué sur le drapeau vert, vous pouvez appuyer sur le bouton et la cloche sur la scène émettra un son.

.. image:: img/7_doorbell.png

Vous Apprendrez
---------------------

- Fonctionnement du bouton
- Lecture d'une broche numérique et ses plages de valeurs
- Création d'une boucle conditionnelle
- Ajout d'un arrière-plan
- Jouer un son

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
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|
    *   - :ref:`cpn_capacitor`
        - |link_capacitor_buy|

Construire le Circuit
-----------------------

Le bouton est un dispositif à 4 broches, puisque la broche 1 est connectée à la broche 2, et la broche 3 à la broche 4, lorsque le bouton est pressé, les 4 broches sont connectées, fermant ainsi le circuit.

.. image:: img/5_buttonc.png

Construisez le circuit selon le schéma suivant.

* Connectez l'une des broches du côté gauche du bouton à la broche 12, qui est connectée à une résistance de tirage vers le bas et un condensateur de 0.1uF (104) (pour éliminer le jitter et produire un niveau stable lorsque le bouton fonctionne).
* Connectez l'autre extrémité de la résistance et du condensateur à GND, et l'une des broches du côté droit du bouton à 5V.

.. image:: img/circuit/button_circuit.png

Programmation
------------------

**1. Ajouter un arrière-plan**

Cliquez sur le bouton **Choose a Backdrop** dans le coin inférieur droit.

.. image:: img/7_backdrop.png

Choisissez **Bedroom 1**.

.. image:: img/7_bedroom2.png

**2. Sélectionner le sprite**

Supprimez le sprite par défaut, cliquez sur le bouton **Choose a Sprite** dans le coin inférieur droit de la zone des sprites, entrez **bell** dans la boîte de recherche, puis cliquez pour l'ajouter.

.. image:: img/7_sprite.png

Ensuite, sélectionnez le sprite **bell** sur la scène et placez-le à la position appropriée.

.. image:: img/7_doorbell.png

**3. Appuyez sur le bouton et la cloche émet un son**

Utilisez [if then] pour faire une déclaration conditionnelle qui, lorsque la valeur de la broche 12 lue est égale à 1 (la touche est pressée), le son **xylo1** sera joué.

* [read status of digital pin] : Ce bloc vient de la palette **Arduino Uno** et sert à lire la valeur d'une broche numérique, le résultat est 0 ou 1.
* [`if then <https://en.scratch-wiki.info/wiki/If_()_Then_(block)>`_] : Ce bloc est un bloc de contrôle et provient de la palette **Contrôle**. Si sa condition booléenne est vraie, les blocs qu'il contient seront exécutés, puis le script concerné continuera. Si la condition est fausse, les scripts à l'intérieur du bloc seront ignorés. La condition n'est vérifiée qu'une seule fois ; si la condition devient fausse pendant que le script à l'intérieur du bloc est en cours d'exécution, il continuera jusqu'à sa fin.
* [play sound until done] : de la palette Son, utilisé pour jouer des sons spécifiques.

.. image:: img/7_bell.png
