.. note::

    Bonjour et bienvenue dans la Communauté Facebook des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez [|link_sf_facebook|] et rejoignez-nous aujourd'hui !

.. _ar_if_else:

5.1 If else
==============

Habituellement, nous utilisons des jugements conditionnels pour réaliser les projets d'interaction avec la réalité les plus basiques.
Ici, nous construisons un système de détection de porte avec un interrupteur à lames souples et une LED pour montrer cette logique.

Fixez l'aimant d'un côté de la porte et l'interrupteur à lames souples (avec circuit) de l'autre côté de la porte.
Lorsque la porte est fermée, l'aimant est proche de l'interrupteur à lames souples, ce qui l'activera.

**Composants requis**

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
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_reed`
        - \-

**Schéma**

.. image:: img/circuit_8.1_ifelse.png

**Câblage**

.. image:: img/if_else_bb.jpg
    :width: 600
    :align: center

**Code**

.. note::

    * Ouvrez le fichier ``5.1.if_else.ino`` sous le chemin ``3in1-kit\basic_project\5.1.if_else``.
    * Ou copiez ce code dans **Arduino IDE**.
    
    * Ou téléchargez le code via l'`Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/c7bf6236-1276-45a0-8d34-008d2d838476/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Après le téléchargement réussi du code, si vous ne fermez pas la porte, la LED s'allumera, vous incitant à fermer la porte.

D'ailleurs, si nous avons besoin de l'effet inverse (allumer la LED lorsque la porte est fermée), nous avons juste besoin de modifier la condition dans le ``if``.

* `if else <https://www.arduino.cc/reference/en/language/structure/control-structure/else/>`_

    Le ``if else`` permet un contrôle plus grand sur le flux du code que la simple instruction if, en permettant de regrouper plusieurs tests.
