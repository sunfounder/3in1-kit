.. note:: 

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions spéciales.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_resistor:

Résistance
=============

.. image:: img/resistor.png
    :width: 300

La résistance est un élément électronique qui peut limiter le courant dans une branche. 
Une résistance fixe est un type de résistance dont la valeur ne peut pas être modifiée, tandis qu'une résistance variable, comme un potentiomètre, peut être ajustée. 

Voici deux symboles généralement utilisés dans les circuits pour représenter une résistance. En général, la valeur de la résistance est indiquée dessus. Si vous voyez ces symboles dans un circuit, ils désignent une résistance.

.. image:: img/resistor_symbol.png
    :width: 400

**Ω** est l'unité de la résistance, avec des unités supérieures comme KΩ et MΩ. 
Leur relation est la suivante : 1 MΩ = 1000 KΩ, 1 KΩ = 1000 Ω. Normalement, la valeur de la résistance est indiquée dessus. 

Pour utiliser une résistance, il est essentiel de connaître sa valeur. Voici deux méthodes : observer les bandes de couleur sur la résistance ou utiliser un multimètre pour la mesurer. La première méthode est généralement recommandée car elle est plus rapide et pratique. 

.. image:: img/resistance_card.jpg

Comme indiqué sur la carte, chaque couleur correspond à un chiffre.

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

Les résistances à 4 et 5 bandes sont fréquemment utilisées, avec 4 ou 5 bandes colorées.

Habituellement, lorsque vous obtenez une résistance, il peut être difficile de savoir par quel côté commencer la lecture des couleurs. 
Le conseil est que l'écart entre la 4e et la 5e bande est généralement plus grand.

Par conséquent, observez l'écart entre les bandes colorées à une extrémité de la résistance ; 
si cet écart est plus grand que les autres, commencez à lire depuis le côté opposé. 

Voyons comment lire la valeur d'une résistance à 5 bandes comme illustré ci-dessous.

.. image:: img/220ohm.jpg
    :width: 500

Pour cette résistance, la lecture se fait de gauche à droite. 
La valeur se présente sous le format : 1re Bande 2e Bande 3e Bande x 10^Multiplicateur (Ω), avec une tolérance de ± Tolérance %. 
Ainsi, la valeur de cette résistance est de 2 (rouge) 2 (rouge) 0 (noir) x 10^0 (noir) Ω = 220 Ω, 
et la tolérance est de ± 1 % (marron). 

.. list-table::Common resistor color band
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

Pour en savoir plus sur les résistances, consultez Wiki : `Resistor - Wikipedia <https://en.wikipedia.org/wiki/Resistor>`_.
