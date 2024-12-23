.. note:: 

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions spéciales.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_track:

Module de Suivi de Ligne
================================

.. image:: img/line_track.png
    :width: 400
    :align: center

* S : Généralement niveau bas, passe au niveau haut lorsqu'une ligne noire est détectée.
* V+ : Alimentation, 3.3V~5V
* G : Masse

Ce module de suivi de ligne à un canal, comme son nom l'indique, permet de suivre des lignes noires sur un fond blanc ou des lignes blanches sur un fond noir.

.. image:: img/tcrt5000.jpg
    :width: 200
    :align: center

Le module utilise un capteur infrarouge TCRT5000, qui se compose d'une LED infrarouge (bleue) et d'un phototransistor (noir).

* La LED infrarouge bleue émet une lumière infrarouge invisible à l'œil humain lorsqu'elle est alimentée.
* Le phototransistor noir reçoit la lumière infrarouge ; sa résistance interne varie en fonction de la lumière reçue : plus il reçoit de lumière, plus sa résistance diminue, et vice versa.

Un comparateur LM393 est intégré au module pour comparer la tension du phototransistor à une tension de référence réglée par un potentiomètre. Si la tension est supérieure à la tension de référence, la sortie est à 1 ; sinon, elle est à 0.

Ainsi, lorsque le tube émetteur infrarouge éclaire une surface noire (qui absorbe la lumière), le phototransistor reçoit moins de lumière infrarouge, sa résistance augmente (tension augmentée), et la sortie du comparateur LM393 passe au niveau haut.

À l'inverse, lorsqu'il éclaire une surface blanche, la lumière réfléchie augmente, la résistance du phototransistor diminue (tension diminuée), et la sortie du comparateur passe au niveau bas, allumant la LED témoin.

* `TCRT5000 <https://www.vishay.com/docs/83760/tcrt5000.pdf>`_

**Caractéristiques**

* Utilise un capteur infrarouge TCRT5000.
* Distance de détection : 1-8 mm, distance focale de 2,5 mm.
* Signal de sortie du comparateur propre, bonne forme d'onde, capacité de conduite supérieure à 15 mA.
* Réglage de la sensibilité via potentiomètre.
* Tension de fonctionnement : 3,3V-5V.
* Sortie numérique : 0 (blanc) et 1 (noir).
* Utilise un comparateur LM393 à large plage de tension.
* Dimensions : 42mm x 10mm.

**Exemple**

* :ref:`ar_line_track` (Projet de base)
* :ref:`follow_the_line` (Projet voiture)

.. * :ref:`sh_protect_heart` (Projet Scratch)
