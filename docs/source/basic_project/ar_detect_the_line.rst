.. note:: 

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez plus profondément dans Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprenez et partagez** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aperçus exclusifs.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et promotions de vacances.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _ar_line_track:

3.4 Détection de ligne
===================================

Le module de suivi de ligne est utilisé pour détecter la présence de zones noires au sol, comme des lignes noires collées avec du ruban adhésif électrique.

L'une de ses LED émet une lumière infrarouge appropriée vers le sol, et la surface noire a une capacité relativement forte d'absorption de la lumière et une capacité de réflexion plus faible. Les surfaces blanches sont à l'inverse.
Si une lumière réfléchie est détectée, cela signifie que le sol est actuellement blanc. Si aucune lumière n'est détectée, cela signifie qu'il est noir.

Voici comment cela fonctionne.

**Composants nécessaires**

Dans ce projet, nous aurons besoin des composants suivants. 

Il est très pratique d'acheter un kit complet, voici le lien : 

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nom
        - ARTICLES DANS CE KIT
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
        - \-
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_track`
        - |link_track_buy|

**Schéma**

.. image:: img/circuit_3.4_line.png

La broche numérique 2 est utilisée pour lire le signal du module de suivi de ligne. Nous connectons le VCC du module au 5V, 
le GND au GND et la broche OUT à la broche numérique 2.

**Câblage**



.. image:: img/3.4_detect_the_line_bb.png
    :width: 500
    :align: center

**Code**

.. note::

   * Vous pouvez ouvrir le fichier ``3.4.detect_the_line.ino`` sous le chemin ``3in1-kit\learning_project\3.4.detect_the_line``. 
   * Ou copiez ce code dans **Arduino IDE**.
   
.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/9795add6-c838-4a66-b484-0c39f252a7b4/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Lorsque le module de suivi de ligne détecte une ligne noire, un [1] apparaît sur le moniteur série ; sinon, un [0] est affiché.
