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

