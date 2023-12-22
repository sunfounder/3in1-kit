.. _ar_rgb:

2.2 Lumière Colorée
==============================================

Comme nous le savons, la lumière peut être superposée. Par exemple, mélanger de la lumière bleue et verte donne une lumière cyan, du rouge et du vert donne une lumière jaune.
Cela s'appelle "La méthode additive de mélange des couleurs".

* `Couleur additive - Wikipédia <https://en.wikipedia.org/wiki/Additive_color>`_

En se basant sur cette méthode, nous pouvons utiliser les trois couleurs primaires pour mélanger la lumière visible de n'importe quelle couleur selon des proportions spécifiques. Par exemple, l'orange peut être produit avec plus de rouge et moins de vert.

Dans ce chapitre, nous utiliserons une LED RVB pour explorer le mystère du mélange des couleurs additives !

La LED RVB équivaut à encapsuler une LED rouge, verte et bleue sous un même capuchon de lampe, et les trois LED partagent une broche de cathode commune.
Puisque le signal électrique est fourni à chaque broche d'anode, la lumière de la couleur correspondante peut être affichée.
En changeant l'intensité du signal électrique de chaque anode, elle peut produire diverses couleurs.


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
    *   - :ref:`cpn_rgb`
        - |link_rgb_led_buy|


**Schéma**

.. image:: img/circuit_2.2_rgb.png


Les broches PWM 11, 10 et 9 contrôlent respectivement les broches Rouge, Verte et Bleue de la LED RVB, et connectent la broche de cathode commune à GND. 
Cela permet à la LED RVB d'afficher une couleur spécifique en superposant la lumière sur ces broches avec différentes valeurs PWM.



**Câblage**

.. image:: img/rgb_led_sch.png

Une LED RVB a 4 broches : la broche la plus longue est la broche de cathode commune, généralement connectée à GND, 
la broche à gauche de la plus longue est Rouge, et les 2 broches à droite sont Vert et Bleu.


.. image:: img/colorful_light_bb.jpg
    :width: 500
    :align: center

**Code**

Ici, nous pouvons choisir notre couleur préférée dans un logiciel de dessin (comme Paint) et l'afficher avec la LED RVB.

.. note::

   * Vous pouvez ouvrir le fichier ``2.2.colorful_light.ino`` dans le chemin ``3in1-kit\basic_project\2.analogWrite\2.2.colorful_light``. 
   * Ou copiez ce code dans **Arduino IDE**.
   
   * Ou téléchargez le code via l'`Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.


.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/5d70e864-4f34-4090-b65d-904350091936/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

.. image:: img/edit_colors.png

Écrivez la valeur RVB dans ``color_set()``, et vous pourrez voir la lumière RVB afficher les couleurs que vous souhaitez.


**Comment ça fonctionne ?**

Dans cet exemple, la fonction utilisée pour attribuer des valeurs aux trois broches de RVB est emballée dans une sous-fonction indépendante ``color()``.

.. code-block:: arduino

    void color (unsigned char red, unsigned char green, unsigned char blue)
    {
        analogWrite(redPin, red);
        analogWrite(greenPin, green);
        analogWrite(bluePin, blue);
    }

Dans ``loop()``, la valeur RVB sert d'argument d'entrée pour appeler la fonction ``color()`` pour réaliser que le RVB peut émettre différentes couleurs.

.. code-block:: arduino

    void loop() 
    {    
        color(255, 0, 0); //  red 
        delay(1000); 
        color(0,255, 0); //  green  
        delay(1000);  
        color(0, 0, 255); //  blue  
        delay(1000);
    }
