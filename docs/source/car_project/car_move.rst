.. note::

    Bonjour et bienvenue dans la Communauté Facebook des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez [|link_sf_facebook|] et rejoignez-nous aujourd'hui !

.. _car_move:

1. Mouvement
============

.. image:: ../components/img/l9110_module.jpg
    :width: 500
    :align: center

Avant de commencer la programmation, revoyons le principe de fonctionnement du module L9110.

Voici la table de vérité du moteur B :

.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - B-1A
      - B-1B(B-2A)
      - État du moteur B
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

Voici la table de vérité du moteur A :

.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - A-1A
      - A-1B
      - État du moteur B
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


* :ref:`cpn_l9110`

**Avancer**

Connectons maintenant l'entrée du module L9110 directement à 12V et GND respectivement pour faire avancer la voiture.

.. raw:: html
    
  <iframe width="600" height="400" src="https://www.youtube.com/embed/ulD40OtsL7c?si=hJ9nyf8ePAWNp0-8" title="Lecteur vidéo YouTube" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

1. Connectez la carte R3, le module L9110 et 2 moteurs.


.. image:: img/car_1.png
    :width: 800

2. Connectez B-1B(B-2A) et A-1A à VCC, et B-1A et A-1B à GND, alors vous pourrez voir la voiture avancer.


.. image:: img/1.move_4.png 
    :align: center

Si les deux ne tournent pas vers l'avant, mais que les situations suivantes se produisent, 
vous devrez réajuster le câblage des deux moteurs.

* Si les deux moteurs tournent en arrière en même temps (le moteur gauche tourne dans le sens des aiguilles d'une montre, le moteur droit tourne dans le sens inverse), échangez le câblage des moteurs gauche et droit en même temps, OA(A) et OB(A) échangent, OA(B) et OB(B) échangent.
* Si le moteur gauche tourne en arrière (rotation dans le sens des aiguilles d'une montre), échangez le câblage de OA(B) et OB(B) du moteur gauche.
* Si le moteur droit tourne en arrière (rotation dans le sens inverse des aiguilles d'une montre), échangez le câblage de OA(A) et OB(A) du moteur droit.


**Arrière**

Connectez B-1B(B-2A) et A-1A à GND, et B-1A et A-1B à VCC, alors vous pourrez voir la voiture reculer.


.. image:: img/1.move_back.png 
    :width: 800



**Tourner à Gauche**

Si vous voulez faire tourner la voiture à gauche, c'est-à-dire faire tourner les deux moteurs dans le sens des aiguilles d'une montre. 
Vous devez connecter B-1A et A-1A à GND, et B-1B(B-2A) et A-1B à VCC.


.. image:: img/1.move_left.png 
    :width: 800


**Tourner à Droite**

Inversement, si vous voulez tourner la voiture à droite, c'est-à-dire faire tourner les deux moteurs dans le sens inverse des aiguilles d'une montre. 
Vous devez connecter B-1A et A-1A à VCC et B-1B(B-2A) et A-1B à GND.


.. image:: img/1.move_right.png 
    :width: 800



**Arrêt**

Pour arrêter le moteur, connectez les entrées du même côté à 12V ou GND en même temps, par exemple connectez B-1A et B-1B(B-2A) à 12V ou 5V en même temps, et de même pour A-1A et A-1B.

Ceci est bien sûr théorique et nécessaire plus tard lors de la commande avec du code. Ici, retirez l'alimentation de la voiture pour l'arrêter.
