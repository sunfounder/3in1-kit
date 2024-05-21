.. note::

    Bonjour et bienvenue dans la Communauté Facebook des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez [|link_sf_facebook|] et rejoignez-nous aujourd'hui !

.. _cpn_servo:

Servomoteur
===========

.. image:: img/servo.png
    :align: center

Un servomoteur est généralement composé des éléments suivants : boîtier, axe, système d'engrenages, potentiomètre, moteur à courant continu (DC) et carte intégrée.

Son fonctionnement est le suivant : le microcontrôleur envoie des signaux PWM au servomoteur, puis la carte intégrée dans le servo reçoit les signaux via la broche de signal et contrôle le moteur interne pour le faire tourner. En conséquence, le moteur entraîne le système d'engrenages, puis motive l'axe après décélération. L'axe et le potentiomètre du servo sont connectés ensemble. Lorsque l'axe tourne, il entraîne le potentiomètre, de sorte que le potentiomètre émet un signal de tension à la carte intégrée. La carte détermine ensuite la direction et la vitesse de rotation en fonction de la position actuelle, de sorte qu'elle puisse s'arrêter exactement à la position définie et y rester.

.. image:: img/servo_internal.png
    :align: center

L'angle est déterminé par la durée d'une impulsion appliquée au fil de commande. Cela s'appelle la modulation de largeur d'impulsion (PWM). Le servomoteur s'attend à voir une impulsion toutes les 20 ms. La longueur de l'impulsion déterminera la rotation du moteur. Par exemple, une impulsion de 1,5 ms fera tourner le moteur à la position de 90 degrés (position neutre).
Lorsqu'une impulsion inférieure à 1,5 ms est envoyée à un servo, le servo tourne vers une position et maintient son axe de sortie à un certain nombre de degrés dans le sens antihoraire à partir du point neutre. Lorsque l'impulsion est plus large que 1,5 ms, l'inverse se produit. La largeur minimale et maximale de l'impulsion qui commande le servo pour tourner vers une position valide dépendent de chaque servo. Généralement, l'impulsion minimale sera d'environ 0,5 ms de large et l'impulsion maximale sera de 2,5 ms de large.

.. image:: img/servo_duty.png
    :width: 600
    :align: center

**Exemple**

* :ref:`ar_servo` (Projet de base)
* :ref:`iot_gate` (Projet IoT)
* :ref:`sh_pendulum` (Projet Scratch)



