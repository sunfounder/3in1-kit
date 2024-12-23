.. note:: 

    Bonjour et bienvenue dans la communauté Facebook des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions spéciales.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_dht11:

Capteur DHT11 de Température et d'Humidité
=============================================

Le capteur numérique de température et d'humidité DHT11 est un capteur composite qui intègre une sortie numérique calibrée des mesures de température et d'humidité. 
La technologie de collecte de modules numériques dédiés ainsi que la technologie de détection de température et d'humidité sont appliquées pour garantir une fiabilité élevée et une excellente stabilité à long terme.

Le capteur inclut un composant résistif pour la mesure de l'humidité et un dispositif de mesure de température NTC, le tout connecté à un microcontrôleur 8 bits performant.

Le capteur dispose de trois broches : VCC, GND et DATA. 
Le processus de communication commence par l'envoi de signaux de démarrage par la ligne DATA au DHT11, qui les reçoit et renvoie un signal de réponse. 
Ensuite, l'hôte reçoit ce signal de réponse et commence à recevoir 40 bits de données de température et d'humidité (8 bits pour l'humidité entière + 8 bits pour l'humidité décimale + 8 bits pour la température entière + 8 bits pour la température décimale + 8 bits de somme de contrôle).

.. image:: img/dht11.png

**Caractéristiques**

    #. Plage de mesure d'humidité : 20 - 90 %HR
    #. Plage de mesure de température : 0 - 60 ℃ 
    #. Sortie de signaux numériques indiquant la température et l'humidité
    #. Tension de fonctionnement : 5 V DC ; Dimensions du circuit imprimé : 2,0 x 2,0 cm
    #. Précision de mesure de l'humidité : ±5 %HR
    #. Précision de mesure de la température : ±2 ℃

* `Fiche technique du DHT11 <http://wiki.sunfounder.cc/images/c/c7/DHT11_datasheet.pdf>`_

**Exemple**

* :ref:`ar_dht11` (Projet de base)
* :ref:`iot_home` (Projet IoT)
* :ref:`iot_plant` (Projet IoT)
