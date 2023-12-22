.. _sh_colorful_ball:

2.3 Balles Colorées
=====================

Dans ce projet, nous allons faire en sorte que les LED RVB affichent différentes couleurs.

Cliquer sur des balles de différentes couleurs dans l'espace scénique entraînera l'illumination de la LED RVB dans différentes couleurs.

.. image:: img/4_color.png

Vous Apprendrez
-------------------------

- Le principe de la LED RVB
- Copier des sprites et sélectionner différents costumes
- Superposition des trois couleurs primaires

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
    *   - :ref:`cpn_rgb`
        - |link_rgb_led_buy|

Construire le Circuit
---------------------

Une LED RVB combine trois LED de rouge, vert et bleu dans une coque en plastique transparent ou semi-transparent. Elle peut afficher diverses couleurs en changeant la tension d'entrée des trois broches et en les superposant, ce qui, selon les statistiques, peut créer 16 777 216 couleurs différentes.

.. image:: img/4_rgb.png
    :width: 300

.. image:: img/circuit/rgb_circuit.png

Programmation
------------------

**1. Sélectionner un sprite**


Supprimez le sprite par défaut, puis choisissez le sprite **Ball**.

.. image:: img/4_ball.png

Et dupliquez-le 5 fois.

.. image:: img/4_duplicate_ball.png

Choisissez différents costumes pour ces 5 sprites **Ball** et placez-les aux positions correspondantes.

.. note::

    Le costume du sprite **Ball3** doit être manuellement changé en rouge.

.. image:: img/4_rgb1.png
    :width: 800

**2. Faire s'illuminer les LED RVB dans la couleur appropriée**

Avant de comprendre le code, nous devons comprendre le `modèle de couleur RVB <https://en.wikipedia.org/wiki/RGB_color_model>`_.

Le modèle de couleur RVB est un modèle de couleur additive dans lequel les lumières rouge, verte et bleue sont combinées de diverses manières pour reproduire un large éventail de couleurs.

Mélange de couleurs additives : ajouter du rouge au vert donne du jaune; ajouter du vert au bleu donne du cyan; ajouter du bleu au rouge donne du magenta; ajouter les trois couleurs primaires ensemble donne du blanc.

.. image:: img/4_rgb_addition.png
  :width: 400

Ainsi, le code pour faire s'illuminer la LED RVB en jaune est le suivant.

.. image:: img/4_yellow.png

Lorsque le sprite Ballon (balle jaune) est cliqué, nous réglons la broche 11 en mode haut (LED rouge allumée), la broche 10 en mode haut (LED verte allumée) et la broche 9 en mode bas (LED bleue éteinte) afin que la LED RVB s'illumine en jaune.

Vous pouvez écrire des codes pour les autres sprites de la même manière pour faire s'illuminer les LED RVB dans les couleurs correspondantes.

**3. Sprite Ballon2 (bleu clair)**

.. image:: img/4_blue.png

**4. Sprite Ballon3 (rouge)**

.. image:: img/4_red.png

**5. Sprite Ballon4 (vert)**

.. image:: img/4_green.png

**6. Sprite Ballon5 (violet)**

.. image:: img/4_purple.png




