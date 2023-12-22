Comment Construire le Circuit
=================================

Beaucoup des choses que vous utilisez tous les jours sont alimentées par l'électricité, comme les lumières de votre maison et l'ordinateur sur lequel vous lisez.

Pour utiliser l'électricité, vous devez construire un circuit électrique. Fondamentalement, un circuit est un chemin à travers lequel l'électricité circule, ou un circuit électronique, et est composé de dispositifs et de composants électriques (appareils) qui sont connectés d'une certaine manière, tels que des résistances, des condensateurs, des alimentations et des interrupteurs.

.. image:: img/circuit.png

Un circuit est un chemin fermé dans lequel les électrons se déplacent pour créer un courant électrique. Pour faire circuler le courant, il doit y avoir un chemin conducteur entre la borne positive de l'alimentation et la borne négative, ce qui est appelé un circuit fermé (s'il est interrompu, on parle de circuit ouvert).



La carte Arduino dispose de quelques broches de sortie d'alimentation (positives) et de quelques broches de masse (négatives).
Vous pouvez utiliser ces broches comme les côtés positif et négatif de l'alimentation en branchant la source d'alimentation sur la carte.

.. image:: img/arduinoPN.jpg

Avec l'électricité, vous pouvez créer des œuvres avec de la lumière, du son et du mouvement.
Vous pouvez allumer une LED en connectant la broche longue à la borne positive et la broche courte à la borne négative.
La LED se détruira très rapidement si vous faites cela, donc vous devez ajouter une résistance de 220* dans le circuit pour la protéger.

Le circuit qu'ils forment est montré ci-dessous.

.. image:: img/sp221014_181625.png

Vous pouvez vous poser des questions cette fois-ci : comment construire ce circuit ? Tenir les fils à la main ou coller les broches et les fils ?

Dans cette situation, les plaques d'essai sans soudure seront vos alliées les plus fortes.

.. _bc_bb:

Bonjour, Breadboard!
------------------------------

Une breadboard (plaque d'essai) est une plaque en plastique rectangulaire avec un tas de petits trous. 
Ces trous nous permettent d'insérer facilement des composants électroniques et de construire des circuits électroniques. 
Les breadboards ne fixent pas de manière permanente les composants électroniques, donc nous pouvons facilement réparer un circuit et recommencer si quelque chose ne va pas.

.. note::
    Il n'est pas nécessaire d'avoir des outils spéciaux pour utiliser les breadboards. Cependant, de nombreux composants électroniques sont très petits, et une paire de pinces peut nous aider à mieux saisir les petites pièces.

Sur Internet, nous pouvons trouver beaucoup d'informations sur les breadboards.

* `Comment Utiliser une Breadboard - Science Buddies <https://www.sciencebuddies.org/science-fair-projects/references/how-to-use-a-breadboard#pth-smd>`_

* `Qu'est-ce qu'une BREADBOARD ? - Makezine <https://cdn.makezine.com/uploads/2012/10/breadboardworkshop.pdf>`_


Voici quelques choses que vous devez savoir sur les breadboards (planches à pain).

#. Chaque groupe de demi-rangées (comme la colonne A-E dans la rangée 1 ou la colonne F-J dans la rangée 3) est connecté. Par conséquent, si un signal électrique entre par A1, il peut sortir par B1, C1, D1, E1, mais pas par F1 ou A2.

#. Dans la plupart des cas, les deux côtés de la breadboard sont utilisés comme bus d'alimentation, et les trous de chaque colonne (environ 50 trous) sont connectés ensemble. En règle générale, les alimentations positives sont connectées aux trous près du fil rouge, et les alimentations négatives aux trous près du fil bleu.

#. Dans un circuit, le courant circule du pôle positif au pôle négatif après avoir traversé la charge. Dans ce cas, un court-circuit peut se produire.


**Suivons la direction du courant pour construire le circuit !**

.. image:: img/sp221014_182229_2.png


1. Dans ce circuit, nous utilisons la broche 5V de la carte pour alimenter la LED. Utilisez un câble de liaison mâle à mâle (M2M) pour le connecter au bus d'alimentation rouge.
#. Pour protéger la LED, le courant doit passer par une résistance de 220 ohms. Connectez une extrémité (n'importe laquelle) de la résistance au bus d'alimentation rouge, et l'autre extrémité à une rangée libre de la breadboard.

    .. note::
        La bague de couleur de la résistance de 220 ohms est rouge, rouge, noire, noire et marron.

#. Si vous prenez la LED, vous verrez que l'une de ses broches est plus longue que l'autre. Connectez la broche la plus longue à la même rangée que la résistance, et la broche la plus courte à une autre rangée.

    .. note::
        La broche la plus longue est l'anode, qui représente le côté positif du circuit ; la broche la plus courte est la cathode, qui représente le côté négatif. 

        L'anode doit être connectée à la broche GPIO via une résistance ; la cathode doit être connectée à la broche GND.

#. Utilisez un câble de liaison mâle à mâle (M2M) pour connecter la broche courte de la LED au bus d'alimentation négatif de la breadboard.
#. Connectez la broche GND de la carte au bus d'alimentation négatif à l'aide d'un câble de liaison.

Attention aux courts-circuits
------------------------------
Les courts-circuits peuvent se produire lorsque deux composants qui ne devraient pas être connectés le sont "accidentellement". 
Ce kit comprend des résistances, des transistors, des condensateurs, des LED, etc. qui ont de longues broches métalliques pouvant se heurter les unes aux autres et provoquer un court-circuit. Certains circuits sont simplement empêchés de fonctionner correctement lorsqu'un court-circuit se produit. Occasionnellement, un court-circuit peut endommager de manière permanente des composants, en particulier entre l'alimentation et le bus de masse, provoquant un échauffement du circuit, la fusion du plastique sur la breadboard et même la combustion des composants !

Par conséquent, assurez-vous toujours que les broches de tous les composants électroniques sur la breadboard ne se touchent pas entre elles.

Orientation du circuit
-------------------------------
Il existe une orientation pour les circuits, et cette orientation joue un rôle significatif dans certains composants électroniques. Il y a des dispositifs avec polarité, ce qui signifie qu'ils doivent être connectés correctement en fonction de leurs pôles positif et négatif. Les circuits construits avec une mauvaise orientation ne fonctionneront pas correctement.

.. image:: img/sp221014_182229.png

Si vous inversez la LED dans ce simple circuit que nous avons construit plus tôt, vous constaterez qu'elle ne fonctionne plus.

En revanche, certains dispositifs n'ont pas de direction, comme les résistances dans ce circuit, donc vous pouvez les inverser sans affecter le fonctionnement normal des LED.

La plupart des composants et modules avec des étiquettes telles que "+", "-", "GND", "VCC" ou ayant des broches de longueurs différentes doivent être connectés au circuit d'une manière spécifique.


Protection du circuit
-------------------------------------

Le courant est le taux auquel les électrons passent devant un point dans un circuit électrique complet. À sa base, le courant = flux. Un ampère, ou amp, est l'unité internationale utilisée pour mesurer le courant. Il exprime la quantité d'électrons (parfois appelée "charge électrique") passant devant un point dans un circuit sur une période donnée.

La force motrice (tension) derrière le flux de courant est appelée tension et est mesurée en volts (V).

La résistance (R) est la propriété du matériau qui restreint le flux de courant, et elle est mesurée en ohms (Ω).

Selon la loi d'Ohm (tant que la température reste constante), le courant, la tension et la résistance sont proportionnels.
Le courant d'un circuit est proportionnel à sa tension et inversement proportionnel à sa résistance.

Par conséquent, courant (I) = tension (V) / résistance (R).

* `Loi d'Ohm - Wikipedia <https://en.wikipedia.org/wiki/Ohm%27s_law>`_

À propos de la loi d'Ohm, nous pouvons faire une expérience simple.

.. image:: img/sp221014_183107.png

En changeant le fil reliant 5V à 3.3V, la LED devient plus faible.
Si vous changez la résistance de 220 ohms à 1000 ohms (anneau de couleur : marron, noir, noir, marron et marron), vous remarquerez que la LED devient plus faible qu'auparavant. Plus la résistance est grande, plus la LED est faible.

.. note::
    Pour une introduction aux résistances et comment calculer les valeurs de résistance, voir :ref:`cpn_resistor`.

La plupart des modules emballés ne nécessitent qu'un accès à la tension appropriée (généralement 3,3V ou 5V), comme le module ultrasonique.

Cependant, dans vos circuits auto-construits, vous devez être conscient de la tension d'alimentation et de l'utilisation des résistances pour les dispositifs électriques.

Par exemple, les LED consomment généralement 20mA de courant, et leur chute de tension est d'environ 1,8V. Selon la loi d'Ohm, si nous utilisons une alimentation de 5V, nous devons connecter une résistance d'au moins 160 ohms ((5-1,8)/20mA) pour ne pas brûler la LED.


Contrôle du circuit avec Arduino
--------------------------------

Maintenant que nous avons une compréhension de base de la programmation Arduino et des circuits électroniques, il est temps de faire face à la question la plus critique : Comment contrôler les circuits avec Arduino.

En termes simples, la manière dont Arduino contrôle un circuit est en changeant le niveau des broches sur la carte. Par exemple, lors du contrôle d'une LED embarquée, il s'agit d'écrire un signal de haut ou de bas niveau à la broche 13.

Essayons maintenant de coder la carte Arduino pour contrôler le clignotement d'une LED sur la plaque d'essai. Construisez le circuit de sorte que la LED soit connectée à la broche 9.

.. image:: img/wiring_led.png
    :width: 400
    :align: center

Ensuite, téléchargez ce sketch sur la carte de développement Arduino.

.. code-block:: C

    int ledPin = 9;
    int delayTime = 500;

    void setup() {
        pinMode(ledPin,OUTPUT); 
    }

    void loop() {
        digitalWrite(ledPin,HIGH); 
        delay(delayTime); 
        digitalWrite(ledPin,LOW); 
        delay(delayTime);
    }

Ce sketch est très similaire à celui que nous avons utilisé pour contrôler le clignotement de la LED embarquée, la différence est que la valeur de ``ledPin`` a été changée en 9.
Cela est dû au fait que nous essayons de contrôler le niveau de la broche 9 cette fois-ci.

Maintenant, vous pouvez voir la LED sur la plaque d'essai clignoter.
