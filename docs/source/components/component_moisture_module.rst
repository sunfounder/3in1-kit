.. note:: 

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions spéciales.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_soil_moisture:

Module de capteur d'humidité du sol
======================================

.. image:: img/soil_mositure.png

* GND : Masse
* VCC : Alimentation, 3.3V~5V
* AOUT : Sort la valeur de l'humidité du sol. Plus le sol est humide, plus la valeur est faible.

Ce capteur capacitif d'humidité du sol se distingue des capteurs résistifs traditionnels en utilisant le principe de l'induction capacitive pour détecter l'humidité du sol. Il évite les problèmes de corrosion fréquents avec les capteurs résistifs et prolonge considérablement sa durée de vie.

Fabriqué avec des matériaux résistants à la corrosion, ce capteur garantit une excellente longévité. Insérez-le dans le sol autour des plantes pour surveiller les données d'humidité du sol en temps réel. Le module intègre un régulateur de tension intégré, lui permettant de fonctionner dans une plage de tension de 3,3 ~ 5,5 V. Il est idéal pour les microcontrôleurs à faible tension alimentés en 3,3 V ou 5 V.

Le schéma matériel du capteur capacitif d'humidité du sol est présenté ci-dessous.

.. image:: img/solid_schematic.png

Le capteur comprend un oscillateur à fréquence fixe construit avec un circuit intégré de minuterie 555. L'onde carrée générée est ensuite transmise au capteur comme un condensateur. Pour le signal d'onde carrée, le condensateur présente une certaine réactance qui forme, avec une résistance pure (résistance de 10k sur la broche 3), un diviseur de tension.

Plus l'humidité du sol est élevée, plus la capacité du capteur est importante. En conséquence, la réactance diminue, réduisant la tension sur la ligne de signal et donc la valeur d'entrée analogique capturée par le microcontrôleur.

**Spécifications**

* Tension de fonctionnement : 3.3 ~ 5.5 VDC
* Tension de sortie : 0 ~ 3.0VDC
* Courant de fonctionnement : 5mA
* Interface : PH2.0-3P
* Dimensions : 3.86 x 0.905 pouces (L x l)
* Poids : 15g

**Exemples**

* :ref:`ar_moisture` (Projet de base)
* :ref:`iot_plant` (Projet IoT)
