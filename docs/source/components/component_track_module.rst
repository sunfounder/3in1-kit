.. _cpn_track:

Module de Suivi de Ligne
================================

.. image:: img/line_track.png
    :width: 400
    :align: center

* S : Habituellement niveau bas, passe à niveau haut lorsque la ligne noire est détectée.
* V+ : Alimentation électrique, 3.3v~5V
* G : Masse

Il s'agit d'un module de suivi de ligne à 1 canal qui, comme son nom l'indique, suit les lignes noires sur un fond blanc ou les lignes blanches sur un fond noir.

.. image:: img/tcrt5000.jpg
    :width: 200
    :align: center

Le module utilise un capteur infrarouge TCRT500, qui se compose d'une LED infrarouge (bleue) et d'un phototransistor sensible à la lumière (noir).

* La LED infrarouge bleue, une fois alimentée, émet une lumière infrarouge invisible à l'œil humain.
* Le phototransistor noir, utilisé pour recevoir la lumière infrarouge, possède une résistance interne dont la résistance varie en fonction de la lumière infrarouge reçue ; plus il reçoit de lumière infrarouge, plus sa résistance diminue et vice versa.

Il y a un comparateur LM393 sur le module, qui est utilisé pour comparer la tension du phototransistor avec la tension réglée (ajustée par le potentiomètre) ; si elle est supérieure à la tension réglée, la sortie est 1 ; sinon la sortie est 0.

Par conséquent, lorsque le tube émetteur infrarouge brille sur une surface noire, parce que le noir absorbe la lumière, le transistor photosensible reçoit moins de lumière infrarouge, sa résistance augmentera (augmentation de la tension), après le comparateur LM393, la sortie est de niveau haut.

De même, lorsqu'il brille sur une surface blanche, la lumière réfléchie devient plus abondante et la résistance du phototransistor diminue (diminution de la tension) ; par conséquent, le comparateur sort un niveau bas et la LED indicatrice s'allume.

* `TCRT5000 <https://www.vishay.com/docs/83760/tcrt5000.pdf>`_

**Caractéristiques**

* Utilisation du capteur d'émission infrarouge TCRT5000
* Distance de détection : 1-8mm, distance focale de 2.5mm
* Signal de sortie du comparateur propre, bonne forme d'onde, capacité de pilotage supérieure à 15mA
* Utilisation d'un potentiomètre pour ajuster la sensibilité
* Tension de fonctionnement : 3.3V-5V
* Sortie numérique : 0 (blanc) et 1 (noir)
* Utilise un comparateur LM393 à large tension.
* Taille : 42mmx10mm


**Exemple**

* :ref:`ar_line_track` (Projet de base)
* :ref:`follow_the_line` (Projet Voiture)
* :ref:`sh_protect_heart` (Projet Scratch)

