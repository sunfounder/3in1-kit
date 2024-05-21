.. note::

    Bonjour et bienvenue dans la Communauté Facebook des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez [|link_sf_facebook|] et rejoignez-nous aujourd'hui !

.. _cpn_receiver:

Récepteur IR
===========================

**Récepteur IR**

.. image:: img/ir_receiver_hs0038b.jpg
    :align: center

* OUT: Sortie du signal
* GND: Masse
* VCC: alimentation électrique, 3.3v~5V

Un récepteur infrarouge est un composant qui reçoit des signaux infrarouges et peut recevoir de manière indépendante des rayons infrarouges et sortir des signaux compatibles avec le niveau TTL. Il est de taille similaire à un transistor classique emballé dans du plastique et convient à toutes sortes de télécommandes infrarouges et de transmissions infrarouges.

La communication infrarouge, ou IR, est une technologie de communication sans fil populaire, peu coûteuse et facile à utiliser. La lumière infrarouge a une longueur d'onde légèrement plus longue que la lumière visible, elle est donc imperceptible à l'œil humain - idéale pour la communication sans fil. Un schéma de modulation courant pour la communication infrarouge est la modulation à 38KHz.

* Capteur de Réception IR `HS0038B <https://pdf1.alldatasheet.com/datasheet-pdf/view/103034/VISHAY/HS0038B.html>`_, haute sensibilité
* Peut être utilisé pour la télécommande
* Alimentation Électrique : 5V
* Interface : Numérique
* Fréquence de Modulation : 38Khz
* Définitions des Broches : (1) Sortie (2) Vcc (3) Masse
* Taille : 23.5mm x 21.5mm

**Télécommande**

.. image:: img/image186.jpeg
    :width: 400

Il s'agit d'une télécommande sans fil infrarouge mince avec 21 boutons de fonction et une distance de transmission allant jusqu'à 8 mètres, adaptée pour commander une large gamme d'appareils dans une chambre d'enfant.

* Taille : 85x39x6mm
* Portée de la télécommande : 8-10m
* Batterie : Batterie au lithium-manganèse de type bouton 3V
* Fréquence porteuse infrarouge : 38KHz
* Matériau de collage de surface : PET de 0.125mm
* Vie effective : plus de 20 000 fois

**Exemple**

* :ref:`ar_receiver` (Projet de base)
* :ref:`car_remote` (Projet Voiture)
* :ref:`car_remote_plus` (Projet Voiture)

