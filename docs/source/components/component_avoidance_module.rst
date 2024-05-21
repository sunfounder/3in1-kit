.. note::

    Bonjour et bienvenue dans la Communauté Facebook des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez [|link_sf_facebook|] et rejoignez-nous aujourd'hui !

.. _cpn_avoid:

Module d'Évitement d'Obstacle
===========================================

.. image:: img/IR_Obstacle.png
   :width: 400
   :align: center

* **VCC** : Alimentation électrique, 3.3 ~ 5V DC.
* **GND** : Masse
* **OUT** : Broche de signal, habituellement au niveau haut, et passe au niveau bas lorsqu'un obstacle est détecté.

Le module d'évitement d'obstacle IR a une forte adaptabilité à la lumière ambiante, il possède une paire de tubes infrarouges émetteurs et récepteurs.

Le tube émetteur émet une fréquence infrarouge, lorsque la direction de détection rencontre un obstacle, le rayonnement infrarouge est reçu par le tube récepteur, 
après le traitement du circuit comparateur, l'indicateur s'allume et émet un signal de niveau bas.

La distance de détection peut être ajustée par un potentiomètre, la plage de distance effective est de 2-30cm.

.. image:: img/IR_module.png
    :width: 600
    :align: center

**Exemple**

* :ref:`ar_ir_obstacle` (Projet de base)
* :ref:`car_ir_obstacle` (Projet Voiture)
* :ref:`self_driving` (Projet Voiture)
* :ref:`iot_gate` (Projet IoT)
* :ref:`sh_shooting` (Projet Scratch)
* :ref:`sh_tap_tile` (Projet Scratch)

