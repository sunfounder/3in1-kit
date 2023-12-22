.. _cpn_resistor:

Résistance
============

.. image:: img/resistor.png
    :width: 300

Une résistance est un élément électronique qui peut limiter le courant d'une branche.
Une résistance fixe est un type de résistance dont la valeur ne peut pas être changée, contrairement à un potentiomètre ou une résistance variable qui peuvent être ajustés.

Deux symboles de circuit généralement utilisés pour une résistance. Normalement, la valeur de la résistance y est marquée. Donc, si vous voyez ces symboles dans un circuit, cela représente une résistance.

.. image:: img/resistor_symbol.png
    :width: 400

**Ω** est l'unité de résistance et les unités plus grandes incluent KΩ, MΩ, etc.
Leur relation peut être présentée comme suit : 1 MΩ = 1000 KΩ, 1 KΩ = 1000 Ω. Normalement, la valeur de la résistance est marquée dessus.

Lors de l'utilisation d'une résistance, nous devons d'abord connaître sa valeur. Voici deux méthodes : vous pouvez observer les bandes sur la résistance, ou utiliser un multimètre pour mesurer la résistance. La première méthode est recommandée car elle est plus pratique et plus rapide.

.. image:: img/resistance_card.jpg

Comme le montre la carte, chaque couleur représente un nombre.

.. list-table::

   * - Noir
     - Marron
     - Rouge
     - Orange
     - Jaune
     - Vert
     - Bleu
     - Violet
     - Gris
     - Blanc
     - Or
     - Argent
   * - 0
     - 1
     - 2
     - 3
     - 4
     - 5
     - 6
     - 7
     - 8
     - 9
     - 0.1
     - 0.01

Les résistances à 4 et 5 bandes sont fréquemment utilisées, sur lesquelles il y a 4 et 5 bandes chromatiques.

Normalement, lorsque vous obtenez une résistance, il peut être difficile de décider par quelle extrémité commencer pour lire la couleur.
L'astuce est que l'écart entre la 4e et la 5e bande sera comparativement plus grand.

Par conséquent, vous pouvez observer l'écart entre les deux bandes chromatiques à une extrémité de la résistance ;
si c'est plus grand que tout autre écart de bande, alors vous pouvez lire à partir du côté opposé.

Voyons comment lire la valeur de la résistance d'une résistance à 5 bandes comme indiqué ci-dessous.

.. image:: img/220ohm.jpg
    :width: 500

Pour cette résistance, la valeur doit être lue de gauche à droite.
La valeur doit être dans ce format : 1re Bande 2e Bande 3e Bande x 10^Multiplicateur (Ω) et l'erreur admissible est de ±Tolérance%.
Ainsi, la valeur de la résistance de cette résistance est 2 (rouge) 2 (rouge) 0 (noir) x 10^0 (noir) Ω = 220 Ω,
et l'erreur admissible est de ± 1 % (marron).

.. list-table:: Bandes de couleur de résistance courantes
    :header-rows: 1

    * - Résistance 
      - Bandes de couleur  
    * - 10Ω   
      - marron noir noir argent marron
    * - 100Ω   
      - marron noir noir noir marron
    * - 220Ω 
      - rouge rouge noir noir marron
    * - 330Ω 
      - orange orange noir noir marron
    * - 1kΩ 
      - marron noir noir marron marron
    * - 2kΩ 
      - rouge noir noir marron marron
    * - 5.1kΩ 
      - vert marron noir marron marron
    * - 10kΩ 
      - marron noir noir rouge marron 
    * - 100kΩ 
      - marron noir noir orange marron 
    * - 1MΩ 
      - marron noir noir vert marron 

Vous pouvez en apprendre plus sur les résistances sur Wiki : `Résistance - Wikipédia <https://en.wikipedia.org/wiki/Resistor>`_.

