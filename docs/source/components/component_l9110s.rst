.. note:: 

    Bonjour et bienvenue dans la communauté Facebook des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions spéciales.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_l9110:

Module de commande moteur L9110
==================================

Le module de commande moteur L9110 est spécialisé dans la conduite de deux moteurs simultanément. Il intègre une paire de puces L9110S indépendantes, 
chacune offrant un courant de sortie constant pouvant atteindre 800 mA.

Fonctionnant sur une plage de tension de 2,5 V à 12 V, ce module s’adapte parfaitement aux microcontrôleurs 3,3 V et 5 V.

Solution compacte, le module de commande moteur L9110 simplifie le contrôle des moteurs dans une large gamme d'applications. 
Grâce à son architecture à deux canaux, il permet une gestion indépendante de deux moteurs, ce qui est idéal pour les projets nécessitant une coordination double des moteurs.

Avec une sortie de courant continue robuste, ce module alimente facilement des moteurs de petite à moyenne taille, 
ouvrant la voie à une variété de projets robotiques, d'automatisation et de moteurs. Sa large plage de tension ajoute une flexibilité supplémentaire, s'adaptant à divers systèmes d'alimentation.

Conçu pour une utilisation intuitive, le module offre des terminaux d'entrée et de sortie simples, facilitant les connexions avec des microcontrôleurs 
ou d'autres dispositifs de contrôle. De plus, il inclut des dispositifs de protection intégrés contre les surintensités et les surchauffes, renforçant la fiabilité 
et la sécurité des opérations.

.. image:: img/l9110_module.jpg
    :width: 600
    :align: center
    
* **B-1A & B-1B(B-2A)** : Broches d'entrée pour contrôler la direction de rotation du moteur B.
* **A-1A & A-1B** : Broches d'entrée pour contrôler la direction de rotation du moteur A.
* **0A & OB(A)** : Broches de sortie du moteur A.
* **0A & OB(B)** : Broches de sortie du moteur B.
* **VCC** : Broche d'entrée d'alimentation (2,5 V-12 V).
* **GND** : Broche de masse.

**Caractéristiques**

* Puce de commande moteur L9110S intégrée.
* Contrôle double canal pour deux moteurs.
* Gestion indépendante de la direction de rotation des moteurs.
* Courant de sortie élevé (800 mA par canal).
* Large plage de tension (2,5 V-12 V).
* Conception compacte.
* Connexions d'entrée et de sortie pratiques.
* Dispositifs de protection intégrés.
* Applications polyvalentes.
* Dimensions du PCB : 29,2 mm x 23 mm.
* Température de fonctionnement : -20°C ~ 80°C.
* Indicateur LED d'alimentation.

**Principe de fonctionnement**

Voici la table de vérité pour le moteur B :

Cette table de vérité montre les différents états du moteur B en fonction des valeurs des broches d'entrée B-1A et B-1B(B-2A). Elle indique la direction de rotation (horaire ou antihoraire), le freinage ou l'arrêt du moteur B.

.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - B-1A
      - B-1B(B-2A)
      - État du moteur B
    * - 1
      - 0
      - Rotation horaire
    * - 0
      - 1
      - Rotation antihoraire
    * - 0
      - 0
      - Frein
    * - 1
      - 1
      - Arrêt

Voici la table de vérité pour le moteur A :

Cette table de vérité montre les différents états du moteur A en fonction des valeurs des broches d'entrée A-1A et A-1B. Elle indique la direction de rotation (horaire ou antihoraire), le freinage ou l'arrêt du moteur A.

.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - A-1A
      - A-1B
      - État du moteur A
    * - 1
      - 0
      - Rotation horaire
    * - 0
      - 1
      - Rotation antihoraire
    * - 0
      - 0
      - Frein
    * - 1
      - 1
      - Arrêt

* :ref:`ar_motor` (Projet de base)
* :ref:`car_move` (Projet voiture)
* :ref:`car_speed` (Projet voiture)
* :ref:`iot_car` (Projet IoT)
