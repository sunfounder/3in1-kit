.. note:: 

    Bonjour et bienvenue dans la communauté Facebook des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions spéciales.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_avoid:

Module de Détection d'Obstacles
===========================================

.. image:: img/IR_Obstacle.png
   :width: 400
   :align: center

* **VCC** : Alimentation électrique, 3,3 ~ 5V DC.
* **GND** : Masse.
* **OUT** : Broche de signal, généralement de niveau haut, et de niveau bas lorsqu'un obstacle est détecté.

Le module de détection d'obstacles à infrarouge (IR) offre une forte adaptabilité à la lumière ambiante. Il est composé d'une paire de tubes émetteurs et récepteurs infrarouges.

Le tube émetteur émet une fréquence infrarouge. Lorsque la direction de détection rencontre un obstacle, le rayonnement infrarouge est reçu par le tube récepteur. 
Après traitement par le circuit comparateur, l'indicateur s'allume et un signal de niveau bas est envoyé en sortie.

La distance de détection peut être ajustée à l'aide du potentiomètre. La plage de distance effective est de 2 à 30 cm.

.. image:: img/IR_module.png
    :width: 600
    :align: center

**Exemple**

* :ref:`ar_ir_obstacle` (Projet de base)
* :ref:`car_ir_obstacle` (Projet pour voiture)
* :ref:`self_driving` (Projet pour voiture)
* :ref:`iot_gate` (Projet IoT)
.. * :ref:`sh_shooting` (Scratch Project)
.. * :ref:`sh_tap_tile` (Scratch Project)