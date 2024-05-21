.. note::

    Bonjour et bienvenue dans la Communauté Facebook des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez [|link_sf_facebook|] et rejoignez-nous aujourd'hui !

.. _cpn_l9110:

Module de Contrôle Moteur L9110
=================================

Le module de contrôle moteur L9110 est conçu pour piloter simultanément deux moteurs. Il intègre une paire de puces de pilotage indépendantes L9110S, 
chaque canal offrant une sortie de courant stable allant jusqu'à 800mA.

Couvrant une plage de tension de 2,5V à 12V, le module s'accorde aisément avec des microcontrôleurs de 3,3V et 5V.

Offrant une solution simplifiée, le module de contrôle moteur L9110 facilite la gestion des moteurs dans un large éventail d'applications. 
Grâce à son architecture à deux canaux, il permet l'orchestration indépendante de deux moteurs, idéal pour des projets nécessitant des opérations de moteurs doubles.

Avec sa sortie de courant continu puissante, ce module alimente avec assurance des moteurs de petite à moyenne taille, 
ouvrant la voie à diverses entreprises robotiques, d'automatisation et centrées sur le moteur. Sa large plage de tension ajoute une adaptabilité, s'alignant sur diverses configurations d'alimentation électrique.

Conçu dans un souci de facilité d'utilisation, le module offre des bornes d'entrée et de sortie intuitives, simplifiant les connexions aux microcontrôleurs 
ou appareils de contrôle similaires. De plus, il ne lésine pas sur la sécurité – des protections intégrées contre les surintensités et les surchauffes renforcent la fiabilité 
et la sécurité des opérations des moteurs.

.. image:: img/l9110_module.jpg
    :width: 600
    :align: center

* **B-1A & B-1B(B-2A)** : Broches d'entrée pour contrôler la direction de rotation du moteur B.
* **A-1A & A-1B** : Broches d'entrée pour contrôler la direction de rotation du moteur A.
* **0A & OB(A)** : Broches de sortie du moteur A.
* **0A & OB(B)** : Broches de sortie du moteur B.
* **VCC** : Broche d'entrée d'alimentation (2,5V-12V).
* **GND** : Broche de masse.

**Caractéristiques**

* 2 puces de contrôle moteur L9110S intégrées
* Contrôle moteur à double canal.
* Contrôle indépendant de la direction de rotation des moteurs.
* Sortie de courant élevée (800mA par canal).
* Large plage de tension (2,5V-12V).
* Conception compacte.
* Bornes d'entrée et de sortie pratiques.
* Caractéristiques de protection intégrées.
* Applications polyvalentes.
* Taille du PCB : 29.2mm x 23mm
* Température de fonctionnement : -20°C ~ 80°C
* Indicateur LED de mise sous tension

**Principe de Fonctionnement**

Voici la table de vérité du moteur B :

Cette table de vérité montre les différents états du moteur B en fonction des valeurs des broches d'entrée B-1A et B-1B(B-2A). Elle indique la direction de rotation (dans le sens des aiguilles d'une montre ou dans le sens inverse), le freinage ou l'arrêt du moteur B.

.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - B-1A
      - B-1B(B-2A)
      - État du moteur B
    * - 1
      - 0
      - Rotation dans le sens des aiguilles d'une montre
    * - 0
      - 1
      - Rotation dans le sens inverse des aiguilles d'une montre
    * - 0
      - 0
      - Freinage
    * - 1
      - 1
      - Arrêt

Voici la table de vérité du moteur A :

Cette table de vérité montre les différents états du moteur A en fonction des valeurs des broches d'entrée A-1A et A-1B. Elle indique la direction de rotation (dans le sens des aiguilles d'une montre ou dans le sens inverse), le freinage ou l'arrêt du moteur A.

.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - A-1A
      - A-1B
      - État du moteur A
    * - 1
      - 0
      - Rotation dans le sens des aiguilles d'une montre
    * - 0
      - 1
      - Rotation dans le sens inverse des aiguilles d'une montre
    * - 0
      - 0
      - Freinage
    * - 1
      - 1
      - Arrêt

* :ref:`ar_motor` (Projet de base)
* :ref:`car_move` (Projet Voiture)
* :ref:`car_speed` (Projet Voiture)
* :ref:`iot_car` (Projet IoT)
