.. note:: 

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions spéciales.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _car_move:

1. Déplacement
===================

.. image:: ../components/img/l9110_module.jpg
    :width: 500
    :align: center

Avant de commencer la programmation, passons en revue le principe de fonctionnement du module L9110.

Voici la table de vérité pour le moteur B :

.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - B-1A
      - B-1B(B-2A)
      - État du moteur B
    * - 1
      - 0
      - Tourne dans le sens horaire
    * - 0
      - 1
      - Tourne dans le sens antihoraire
    * - 0
      - 0
      - Frein
    * - 1
      - 1
      - Arrêt

Voici la table de vérité pour le moteur A :

.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - A-1A
      - A-1B
      - État du moteur A
    * - 1
      - 0
      - Tourne dans le sens horaire
    * - 0
      - 1
      - Tourne dans le sens antihoraire
    * - 0
      - 0
      - Frein
    * - 1
      - 1
      - Arrêt


* :ref:`cpn_l9110`

**Avancer**

Connectons maintenant directement l'entrée du module L9110 à 12V et GND pour faire avancer la voiture.

1. Connectez la carte R4, le module L9110 et les 2 moteurs.

.. image:: img/car_1.png
    :width: 800

2. Connectez B-1B(B-2A) et A-1A à VCC, et B-1A et A-1B à GND, puis vous verrez la voiture avancer.

.. image:: img/1.move_4.png 
    :align: center

Si les deux moteurs ne tournent pas dans le bon sens mais rencontrent les situations suivantes, ajustez le câblage des deux moteurs :

* Si les deux moteurs tournent en arrière en même temps (moteur gauche tourne dans le sens horaire, moteur droit dans le sens antihoraire), échangez les câblages des moteurs gauche et droit simultanément, OA(A) avec OB(A), OA(B) avec OB(B).
* Si le moteur gauche tourne en arrière (rotation horaire), échangez les câblages OA(B) et OB(B) du moteur gauche.
* Si le moteur droit tourne en arrière (rotation antihoraire), échangez les câblages OA(A) et OB(A) du moteur droit.

**Reculer**

Connectez B-1B(B-2A) et A-1A à GND, et B-1A et A-1B à VCC, puis vous verrez la voiture reculer.

.. image:: img/1.move_back.png 
    :width: 800

**Tourner à gauche**

Pour faire tourner la voiture à gauche, c'est-à-dire faire tourner les deux moteurs dans 
le sens horaire, connectez B-1A et A-1A à GND, et B-1B(B-2A) et A-1B à VCC.

.. image:: img/1.move_left.png 
    :width: 800

**Tourner à droite**

Inversement, pour tourner à droite, c'est-à-dire faire tourner les deux moteurs dans le sens antihoraire, connectez B-1A et A-1A à VCC, et B-1B(B-2A) et A-1B à GND.

.. image:: img/1.move_right.png 
    :width: 800



**Arrêt**



Pour arrêter le moteur, connectez les entrées d'un même côté à 12V ou GND en même temps, par exemple connectez B-1A et B-1B(B-2A) à 12V ou 5V simultanément, et faites de même pour A-1A et A-1B.

Cela reste théorique et sera nécessaire plus tard lors du contrôle par code. Pour l'instant, coupez simplement l'alimentation de la voiture pour l'arrêter.
