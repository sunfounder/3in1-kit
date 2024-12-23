.. note:: 

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions spéciales.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_servo:

Servo
===========

.. image:: img/servo.png
    :align: center

Un servo est généralement composé des éléments suivants : boîtier, axe, système d'engrenages, potentiomètre, moteur à courant continu et carte embarquée.

Son fonctionnement est le suivant : le microcontrôleur envoie des signaux PWM au servo, qui sont ensuite reçus par la carte embarquée via la broche de signal. Celle-ci contrôle le moteur interne pour le faire tourner. En conséquence, le moteur actionne le système d'engrenages, qui entraîne l'axe après réduction. L'axe et le potentiomètre du servo sont connectés ensemble. Lorsque l'axe tourne, il fait tourner le potentiomètre, lequel envoie un signal de tension à la carte embarquée. La carte détermine alors la direction et la vitesse de rotation en fonction de la position actuelle, ce qui permet d'arrêter précisément l'axe à la position définie et de le maintenir en place.

.. image:: img/servo_internal.png
    :align: center

L'angle est déterminé par la durée d'une impulsion appliquée au fil de commande. Ce processus est appelé modulation de largeur d'impulsion (PWM). Le servo attend une impulsion toutes les 20 ms. La durée de l'impulsion détermine l'angle de rotation du moteur. Par exemple, une impulsion de 1,5 ms positionne le moteur à 90 degrés (position neutre). 

Lorsque l'impulsion est inférieure à 1,5 ms, le servo tourne dans le sens antihoraire à partir de la position neutre. Lorsqu'elle est supérieure à 1,5 ms, le mouvement est dans le sens horaire. La largeur minimale et maximale des impulsions nécessaires pour commander le servo dépendent de chaque modèle. En général, l'impulsion minimale est d'environ 0,5 ms et la maximale de 2,5 ms.

.. image:: img/servo_duty.png
    :width: 600
    :align: center

**Exemple**

* :ref:`ar_servo` (Projet de base)
* :ref:`iot_gate` (Projet IoT)

.. * :ref:`sh_pendulum` (Projet Scratch)
