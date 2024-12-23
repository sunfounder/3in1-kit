.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez plus profondément dans Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Assistance d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et à des promotions saisonnières.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _ar_if_else:

5.1 Si sinon
==============

Nous utilisons généralement des jugements conditionnels pour réaliser les projets interactifs les plus élémentaires.
Ici, nous construisons un système de détection de porte avec un interrupteur magnétique (reed switch) et une LED pour illustrer cette logique.

Fixez l'aimant d'un côté de la porte et l'interrupteur magnétique (avec circuit) de l'autre 
côté. Lorsque la porte est fermée, l'aimant s'approche de l'interrupteur magnétique, ce qui 
le met en marche.

**Composants nécessaires**

Dans ce projet, nous avons besoin des composants suivants. 

Il est très pratique d'acheter un kit complet, voici le lien : 

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nom  
        - ÉLÉMENTS DANS CE KIT
        - LIEN
    *   - Kit de démarrage 3 en 1
        - 380+
        - |link_3IN1_kit|

Vous pouvez également les acheter séparément via les liens ci-dessous.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUCTION DES COMPOSANTS
        - LIEN D'ACHAT

    *   - :ref:`cpn_uno`
        - \-
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

.. image:: img/5.1_if_else_bb.png
    :width: 600
    :align: center

**Code**

.. note::

    * Vous pouvez ouvrir le fichier ``5.1.if_else.ino`` dans le répertoire ``3in1-kit\learning_project\5.1.if_else``.
    * Ou copiez ce code dans **Arduino IDE**.
    

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/c7bf6236-1276-45a0-8d34-008d2d838476/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Après avoir téléchargé le code avec succès, si vous ne fermez pas la porte, la LED s'allumera pour vous rappeler de fermer la porte.

Par ailleurs, si nous avons besoin de l'effet inverse (allumer la LED lorsque la porte est fermée), il suffit de modifier la condition dans le ``if``.

* `if else <https://www.arduino.cc/reference/en/language/structure/control-structure/else/>`_

    Le ``if else`` permet un contrôle plus précis du flux de code que l'instruction de base if, en permettant de regrouper plusieurs tests.
