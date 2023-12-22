.. _cpn_ultrasonic:

Module Ultrasonique
================================

.. image:: img/ultrasonic_pic.png
    :width: 400
    :align: center

Le module de télémétrie ultrasonique offre une fonction de mesure sans contact de 2 cm à 400 cm, et la précision de mesure peut atteindre 3 mm. 
Il garantit que le signal reste stable jusqu'à 5 m, puis s'affaiblit progressivement après 5 m, jusqu'à disparaître à la position de 7 m.

Le module comprend des émetteurs ultrasoniques, un récepteur et un circuit de contrôle. Les principes de base sont les suivants :

#. Utiliser un basculeur IO pour traiter un signal de niveau haut d'au moins 10us.

#. Le module envoie automatiquement huit signaux de 40 kHz et détecte s'il y a un retour de signal d'impulsion.

#. Si le signal revient, en passant le niveau haut, la durée de sortie IO haute est le temps écoulé entre l'émission de l'onde ultrasonique et son retour. Ici, distance testée = (temps haut x vitesse du son (340 m/s) / 2.

Le diagramme temporel est présenté ci-dessous.

.. image:: img/ultrasonic228.png

Vous avez juste besoin de fournir une impulsion courte de 10us pour l'entrée de déclenchement pour commencer la télémétrie, et ensuite le module
émettra une salve de 8 cycles d'ultrasons à 40 kHz et augmentera son
écho. Vous pouvez calculer la distance à travers l'intervalle de temps entre
l'envoi du signal de déclenchement et la réception du signal d'écho.

Formule : us / 58 = centimètres ou us / 148 = pouces ; ou : la distance = temps de niveau haut
\* vitesse (340M/S) / 2 ; il est conseillé d'utiliser
un cycle de mesure supérieur à 60 ms afin d'éviter les collisions de signaux entre
le signal de déclenchement et le signal d'écho.

**Exemple**

* :ref:`ar_ultrasonic` (Projet de base)
* :ref:`follow_your_hand` (Projet Voiture)
* :ref:`car_ultrasonic` (Projet Voiture)
* :ref:`sh_parrot` (Projet Scratch)

