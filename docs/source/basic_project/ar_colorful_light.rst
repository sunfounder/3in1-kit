.. note:: 

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez plus profondément dans Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprenez et partagez** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aperçus exclusifs.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et promotions de vacances.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _ar_rgb:

2.2 Lumière colorée
==============================================

Comme nous le savons, la lumière peut se superposer. Par exemple, mélanger une lumière bleue et une lumière verte donne une lumière cyan, tandis que la lumière rouge et la lumière verte donnent une lumière jaune. 
Ceci est appelé "la méthode additive de mélange des couleurs".

* `Additive color - Wikipedia <https://en.wikipedia.org/wiki/Additive_color>`_

En utilisant cette méthode, nous pouvons utiliser les trois couleurs primaires pour créer une lumière visible de n'importe quelle couleur selon des proportions spécifiques. Par exemple, l'orange peut être obtenu avec plus de rouge et moins de vert.

Dans ce chapitre, nous allons utiliser une LED RGB pour explorer le mystère du mélange additif des couleurs !

Une LED RGB équivaut à encapsuler une LED rouge, une LED verte et une LED bleue sous un même capot, et les trois LED partagent une broche cathodique commune.
Puisque le signal électrique est fourni pour chaque broche anodique, la lumière de la couleur correspondante peut être affichée.
En modifiant l'intensité du signal électrique de chaque anode, il est possible de produire diverses couleurs.

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_rgb`
        - |link_rgb_led_buy|


**Schéma**

.. image:: img/circuit_2.2_rgb.png

Les broches PWM 11, 10 et 9 contrôlent respectivement les broches Rouge, Vert et Bleu de la LED RGB, et la broche cathodique commune est connectée à la masse (GND). 
Cela permet à la LED RGB d'afficher une couleur spécifique en superposant la lumière sur ces broches avec différentes valeurs PWM.

**Câblage**

.. image:: img/rgb_led_sch.png

Une LED RGB a 4 broches : la plus longue est la broche cathodique commune, qui est généralement connectée à GND, 
la broche à gauche de la plus longue est Rouge, et les deux broches à droite sont Vert et Bleu.

.. image:: img/2.2_colorful_light_bb.png
    :width: 600
    :align: center

**Code**

Ici, nous pouvons choisir notre couleur préférée dans un logiciel de dessin (comme Paint) et l'afficher avec la LED RGB.

.. note::

   * Vous pouvez ouvrir le fichier ``2.2.colorful_light.ino`` sous le chemin ``3in1-kit\learning_project\2.analogWrite\2.2.colorful_light``. 
   * Ou copiez ce code dans **Arduino IDE**.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/5d70e864-4f34-4090-b65d-904350091936/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

.. image:: img/edit_colors.png

Écrivez la valeur RGB dans ``color_set()``, vous pourrez voir la LED RGB afficher les couleurs souhaitées.


**Comment ça fonctionne ?**

Dans cet exemple, la fonction utilisée pour attribuer des valeurs aux trois broches de la LED RGB est encapsulée dans une sous-fonction indépendante ``color()``.

.. code-block:: arduino

    void color (unsigned char red, unsigned char green, unsigned char blue)
    {
        analogWrite(redPin, red);
        analogWrite(greenPin, green);
        analogWrite(bluePin, blue);
    }

Dans ``loop()``, la valeur RGB fonctionne comme un argument d'entrée pour appeler la fonction ``color()`` et permettre à la LED RGB d'émettre différentes couleurs.

.. code-block:: arduino

    void loop() 
    {    
        color(255, 0, 0); // rouge 
        delay(1000); 
        color(0, 255, 0); // vert  
        delay(1000);  
        color(0, 0, 255); // bleu  
        delay(1000);
    }
