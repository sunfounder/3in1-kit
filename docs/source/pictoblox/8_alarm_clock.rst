.. note::

    Bonjour et bienvenue dans la Communauté Facebook des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez [|link_sf_facebook|] et rejoignez-nous aujourd'hui !

.. _sh_light_alarm:

2.8 Réveil Lumineux
====================

Dans la vie, il existe divers types de réveils. Créons maintenant un réveil commandé par la lumière. Quand le matin arrive, la luminosité augmente et ce réveil lumineux vous rappellera qu'il est temps de se lever.

.. image:: img/10_clock.png

Vous Apprendrez
---------------------

- Principe de fonctionnement d'une photorésistance
- Arrêter la lecture de son et stopper l'exécution des scripts

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
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_buy|

Construisez le Circuit
-----------------------

Une photorésistance ou cellule photoélectrique est une résistance variable contrôlée par la lumière. La résistance d'une photorésistance diminue avec l'augmentation de l'intensité lumineuse incidente.

Construisez le circuit selon le schéma suivant.

Connectez une extrémité de la photorésistance à 5V, l'autre à A0, et connectez une résistance de 10K en série avec GND à cette extrémité.

Ainsi, lorsque l'intensité lumineuse augmente, la résistance de la photorésistance diminue, la division de tension de la résistance de 10K augmente, et la valeur obtenue par A0 devient plus grande.

.. image:: img/circuit/photoresistor_circuit.png

Programmation
------------------

**1. Sélectionnez un sprite**

Supprimez le sprite par défaut, cliquez sur le bouton **Choose a Sprite** dans le coin inférieur droit de la zone des sprites, entrez **bell** dans la barre de recherche, puis cliquez pour l'ajouter.

.. image:: img/10_sprite.png

**2. Lisez la valeur de A0**

Créez deux variables **before** et **current**. Lorsque le drapeau vert est cliqué, lisez la valeur de A0 et stockez-la dans la variable **before** comme valeur de référence. Dans [forever], lisez à nouveau la valeur de A0 et stockez-la dans la variable **current**.

.. image:: img/10_reada0.png

**3. Produire un son**

Lorsque la valeur actuelle de A0 est supérieure de 50 à la précédente, ce qui représente une intensité lumineuse supérieure au seuil, alors faites sonner le sprite.

.. image:: img/10_sound.png

**4. Faire tourner le sprite**

Utilisez [turn block] pour faire tourner le sprite **bell** à gauche et à droite pour obtenir l'effet de réveil.

.. image:: img/10_turn.png

**5. Arrêter tout**

Arrêtez l'alarme après qu'elle ait sonné pendant un moment.

.. image:: img/10_stop.png
