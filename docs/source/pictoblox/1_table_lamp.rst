.. note::

    Bonjour et bienvenue dans la Communauté Facebook des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez [|link_sf_facebook|] et rejoignez-nous aujourd'hui !

.. _sh_table_lamp:

2.1 Lampe de Table
=====================

Ici, nous connectons une LED sur la plaque d'essai et faisons en sorte que le sprite contrôle le clignotement de cette LED.

Lorsque le sprite Bouton sur la scène est cliqué, la LED clignotera 5 fois puis s'arrêtera.

.. image:: img/2_button.png

Vous Apprendrez
------------------------

- Plaque d'essai, LEDs et résistances
- Construction d'un circuit sur une plaque d'essai
- Supprimer et sélectionner des sprites
- Changer de costumes
- Définir un nombre limité de boucles répétitives

Composants requis
------------------------

Dans ce projet, nous avons besoin des composants suivants.

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

Vous pouvez également les acheter séparément à partir des liens ci-dessous.

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
    *   - :ref:`cpn_led`
        - |link_led_buy|

Construisez le Circuit
-----------------------

Suivez le schéma ci-dessous pour construire le circuit sur la plaque d'essai.

Puisque l'anode de la LED (la broche la plus longue) est connectée à la broche 9 via une résistance de 220Ω, et la cathode de la LED est connectée à GND, vous pouvez allumer la LED en donnant un niveau haut à la broche 9.

.. image:: img/circuit/led_circuit.png

Programmation
------------------

La programmation complète est divisée en 3 parties, la première partie consiste à sélectionner le sprite désiré, la deuxième partie consiste à changer le costume du sprite pour le rendre cliquable, et la troisième partie consiste à faire clignoter la LED.

**1. Sélectionnez le sprite Button3**

Supprimez le sprite Tobi existant en utilisant le bouton Supprimer dans le coin supérieur droit, et sélectionnez à nouveau un sprite.

.. image:: img/2_tobi.png

Ici, nous sélectionnons le sprite **Button3**.

.. image:: img/2_button3.png

Cliquez sur Costumes dans le coin supérieur droit et vous verrez que le sprite Button3 a 2 costumes, nous définissons **button3-a** comme relâché et **button3-b** comme pressé.

.. image:: img/2_button3_2.png

**2. Changer de costumes**.

Lorsque le sprite est cliqué (**palette Événements**), il passe au costume pour **button3-b** (**palette apparence**).

.. image:: img/2_switch.png

**3. Faire clignoter la LED 5 fois**

Utilisez le bloc [Repeat] pour faire clignoter la LED 5 fois (cycle Haut-> BAS), n'oubliez pas de changer la broche 13 en broche 9, et enfin repassez le costume à **button3-a**.

* [Repeat 10] : nombre limité de boucles répétitives, vous pouvez définir le nombre de répétitions vous-même, à partir de la palette **Contrôle**.

.. image:: img/2_led_on_off.png
