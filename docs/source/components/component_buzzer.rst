.. note:: 

    Bonjour et bienvenue dans la communauté Facebook des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions spéciales.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_buzzer:

Buzzer
========

.. image:: img/buzzer.png
    :width: 600

Le buzzer, un type de composant électronique doté d'une structure intégrée, est largement utilisé dans les ordinateurs, imprimantes, photocopieurs, alarmes, jouets électroniques, appareils électroniques automobiles, téléphones, minuteurs et autres produits électroniques ou dispositifs sonores fonctionnant à courant continu.

Les buzzers peuvent être classés en deux catégories : actifs et passifs (voir l'image ci-dessous). Lorsque les broches du buzzer sont orientées vers le haut, celui avec un circuit imprimé vert est un buzzer passif, tandis que celui entouré d'un ruban noir est un buzzer actif.

Différence entre un buzzer actif et un buzzer passif :

Un buzzer actif dispose d'une source d'oscillation intégrée, ce qui lui permet de produire des sons lorsqu'il est alimenté. En revanche, un buzzer passif n'a pas de source d'oscillation et ne produit pas de son si un signal continu est utilisé. Il doit être alimenté par des ondes carrées dont la fréquence se situe entre 2 kHz et 5 kHz pour fonctionner. Le buzzer actif est généralement plus coûteux que le passif en raison de ses circuits oscillateurs intégrés.

Voici le symbole électrique d'un buzzer. Il comporte deux broches, une positive et une négative. La broche portant un "+" sur la surface correspond à l'anode, tandis que l'autre est la cathode.

.. image:: img/buzzer_symbol.png
    :width: 150

Pour identifier les broches du buzzer, la broche la plus longue est l'anode, et la plus courte est la cathode. Veillez à ne pas inverser les connexions, sinon le buzzer ne produira aucun son.

`Buzzer - Wikipedia <https://en.wikipedia.org/wiki/Buzzer>`_

**Exemple**

* :ref:`ar_beep` (Projet de base)
* :ref:`ar_passive_buzzer` (Projet de base)
* :ref:`iot_music` (Projet IoT)
