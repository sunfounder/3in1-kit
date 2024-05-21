.. note::

    Bonjour et bienvenue dans la Communauté Facebook des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez [|link_sf_facebook|] et rejoignez-nous aujourd'hui !

.. _cpn_dht11:

Capteur d'Humidité et de Température DHT11
=============================================

Le capteur numérique de température et d'humidité DHT11 est un capteur composite qui contient une sortie de signal numérique calibrée de la température et de l'humidité. 
La technologie des modules numériques dédiés et la technologie de détection de température et d'humidité sont appliquées pour garantir que le produit a une haute fiabilité et une excellente stabilité à long terme.

Le capteur comprend un composant de détection d'humidité résistif et un dispositif de mesure de température NTC, et est connecté à un microcontrôleur 8 bits haute performance.

Seules trois broches sont disponibles pour l'utilisation : VCC, GND et DATA. 
Le processus de communication commence par la ligne DATA envoyant des signaux de départ au DHT11, et le DHT11 reçoit les signaux et retourne un signal de réponse. 
Ensuite, l'hôte reçoit le signal de réponse et commence à recevoir les données d'humiture de 40 bits (8 bits d'humidité entière + 8 bits d'humidité décimale + 8 bits de température entière + 8 bits de température décimale + 8 bits de somme de contrôle).

.. image:: img/dht11.png

**Caractéristiques**

    #. Plage de mesure de l'humidité : 20 - 90%RH
    #. Plage de mesure de la température : 0 - 60℃
    #. Sortie de signaux numériques indiquant la température et l'humidité
    #. Tension de travail : DC 5V ; Taille du PCB : 2.0 x 2.0 cm
    #. Précision de mesure de l'humidité : ±5%RH
    #. Précision de mesure de la température : ±2℃

* `Fiche technique du DHT11 <http://wiki.sunfounder.cc/images/c/c7/DHT11_datasheet.pdf>`_

**Exemple**

* :ref:`ar_dht11` (Projet de base)
* :ref:`iot_home` (Projet IoT)
* :ref:`iot_plant` (Projet IoT)

