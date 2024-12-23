.. note:: 

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions spéciales.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_ultrasonic:

Module Ultrasonique
================================

.. image:: img/ultrasonic_pic.png
    :width: 400
    :align: center

Le module de télémétrie ultrasonique fournit une mesure sans contact de 2 cm à 400 cm, avec une précision de l'ordre de 3 mm. 
Il garantit un signal stable jusqu'à 5 m, tandis que le signal s'affaiblit progressivement au-delà de cette distance, pour disparaître à environ 7 m.

Le module inclut des émetteurs ultrasoniques, un récepteur et un circuit de commande. Les principes de fonctionnement sont les suivants :

#. Utilisez une bascule IO pour générer un signal de niveau haut d'au moins 10 µs.

#. Le module envoie automatiquement huit signaux ultrasoniques à 40 kHz et détecte s'il y a un signal de retour.

#. Si un signal est renvoyé, le niveau haut de sortie IO correspond à la durée entre l'émission de l'onde ultrasonique et son retour. La distance est calculée comme suit : distance = (temps haut x vitesse du son (340 m/s)) / 2.

Le diagramme temporel est présenté ci-dessous. 

.. image:: img/ultrasonic228.png

Vous devez simplement fournir une impulsion courte de 10 µs à l'entrée du déclencheur 
pour démarrer la mesure. Le module enverra ensuite une salve de 8 cycles d'ultrasons à 
40 kHz et élèvera son signal d'écho. Vous pouvez calculer la distance grâce à l'intervalle 
de temps entre l'émission du signal de déclenchement et la réception du signal d'écho.

Formule : µs / 58 = centimètres ou µs / 148 = pouces ; ou : distance = temps haut \* vitesse 
(340 m/s) / 2. Il est conseillé d'utiliser un cycle de mesure supérieur à 60 ms pour éviter 
les collisions entre le signal de déclenchement et le signal d'écho.

**Exemple**

* :ref:`ar_ultrasonic` (Projet de base)
* :ref:`follow_your_hand` (Projet voiture)
* :ref:`car_ultrasonic` (Projet voiture)

.. * :ref:`sh_parrot` (Projet Scratch)
