.. note::

    Bonjour et bienvenue dans la Communauté Facebook des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez [|link_sf_facebook|] et rejoignez-nous aujourd'hui !

.. _cpn_buzzer:

Buzzer
=======

.. image:: img/buzzer.png
    :width: 600

En tant que type de buzzer électronique à structure intégrée, les buzzers, alimentés par une tension continue (DC), sont largement utilisés dans les ordinateurs, imprimantes, photocopieuses, alarmes, jouets électroniques, dispositifs électroniques automobiles, téléphones, minuteries et autres produits électroniques ou dispositifs sonores.

Les buzzers peuvent être catégorisés en actifs et passifs (voir l'image ci-dessous). Retournez le buzzer pour que ses broches soient orientées vers le haut : le buzzer avec un circuit imprimé vert est un buzzer passif, tandis que celui entouré d'un ruban noir est un buzzer actif.

La différence entre un buzzer actif et un buzzer passif : 

Un buzzer actif possède une source d'oscillation intégrée, donc il émet un son lorsqu'il est électrifié. Cependant, un buzzer passif n'a pas une telle source, donc il ne bipera pas avec des signaux DC ; à la place, vous devez utiliser des ondes carrées dont la fréquence est entre 2K et 5K pour le piloter. Le buzzer actif est souvent plus cher que le passif en raison de multiples circuits d'oscillation intégrés.

Voici le symbole électrique d'un buzzer. Il a deux broches avec des pôles positif et négatif. Un + sur la surface représente l'anode et l'autre est la cathode.

.. image:: img/buzzer_symbol.png
    :width: 150

Vous pouvez vérifier les broches du buzzer, la plus longue est l'anode et la plus courte est la cathode. Veuillez ne pas les mélanger lors de la connexion, sinon le buzzer ne produira pas de son.

`Buzzer - Wikipédia <https://en.wikipedia.org/wiki/Buzzer>`_

**Exemple**

* :ref:`ar_beep` (Projet de base)
* :ref:`ar_passive_buzzer` (Projet de base)
* :ref:`iot_music` (Projet IoT)


