.. note::

    Bonjour et bienvenue dans la Communauté Facebook des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez [|link_sf_facebook|] et rejoignez-nous aujourd'hui !

.. _sh_move:

3.2 Mouvement
==================

Ce projet est basé sur :ref:`sh_test` pour faire bouger la voiture dans toutes les directions.

Avant de commencer la programmation, revoyons le principe de fonctionnement du module L9110.

Voici la table de vérité du Moteur B :

.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - B-1A
      - B-1B(B-2A)
      - État du Moteur B
    * - 1
      - 0
      - Rotation dans le sens des aiguilles d'une montre
    * - 0
      - 1
      - Rotation dans le sens inverse des aiguilles d'une montre
    * - 0
      - 0
      - Freinage
    * - 1
      - 1
      - Arrêt

Voici la table de vérité du Moteur A :

.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - A-1A
      - A-1B
      - État du Moteur A
    * - 1
      - 0
      - Rotation dans le sens des aiguilles d'une montre
    * - 0
      - 1
      - Rotation dans le sens inverse des aiguilles d'une montre
    * - 0
      - 0
      - Freinage
    * - 1
      - 1
      - Arrêt

Programmation
-------------------

Créez maintenant des blocs pour faire avancer, reculer, tourner à gauche, tourner à droite et arrêter la voiture respectivement.


**1. Avancer**

Le moteur droit tourne dans le sens des aiguilles d'une montre et le moteur gauche dans le sens inverse pour faire avancer la voiture.

.. image:: img/2_forward.png

**2. Reculer**

Le recul est juste l'opposé, le moteur droit doit tourner dans le sens inverse des aiguilles d'une montre, le moteur gauche dans le sens des aiguilles d'une montre.

.. image:: img/2_backward.png

**3. Tourner à Gauche**

Les moteurs gauche et droit tournent dans le sens des aiguilles d'une montre en même temps pour faire tourner la voiture à gauche.

.. image:: img/2_turn_left.png

**4. Tourner à Droite**

De même, faites tourner les moteurs gauche et droit dans le sens inverse des aiguilles d'une montre pour tourner la voiture à droite.

.. image:: img/2_turn_right.png

**5. Arrêt**

Arrêtez la voiture en réglant tous les moteurs à 0.

.. image:: img/2_stop.png

**6. Faire bouger la voiture**

Faites bouger la voiture en avant, en arrière, à gauche et à droite pendant 1 seconde, puis arrêtez. Comme tous les blocs sont placés dans le bloc [Forever], vous verrez que la voiture répète les actions ci-dessus.

.. image:: img/2_move.png
