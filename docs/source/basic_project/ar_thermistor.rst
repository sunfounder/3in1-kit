.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions festives et cadeaux** : Participez à des promotions et à des cadeaux festifs.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _ar_temp:

4.5 Thermomètre
==================

Un thermomètre est un appareil qui mesure la température ou un gradient de température (le degré de chaleur ou de froid d’un objet). 
Un thermomètre a deux éléments importants : (1) un capteur de température (par exemple, l’ampoule d’un thermomètre à mercure ou le capteur pyrométrique dans un thermomètre infrarouge) dans lequel un changement se produit en fonction de la température ; 
et (2) un moyen de convertir ce changement en une valeur numérique (par exemple, l’échelle visible sur un thermomètre à mercure ou l’affichage numérique sur un modèle infrarouge). 
Les thermomètres sont largement utilisés dans la technologie et l’industrie pour surveiller les processus, en météorologie, en médecine et dans la recherche scientifique.

Une thermistance est un type de capteur de température dont la résistance dépend fortement de la température, et elle en existe deux types : 
le coefficient de température négatif (NTC) et le coefficient de température positif (PTC). 
La résistance d’une thermistance PTC augmente avec la température, tandis que la résistance d’une thermistance NTC diminue avec la température.

Dans cette expérience, nous utilisons une **thermistance NTC** pour créer un thermomètre.

**Composants nécessaires**

Dans ce projet, nous avons besoin des composants suivants.

Il est vraiment pratique d'acheter un kit complet, voici le lien :

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nom
        - ÉLÉMENTS DANS CE KIT
        - LIEN
    *   - Kit de démarrage 3 en 1
        - 380+
        - |link_3IN1_kit|

Vous pouvez également les acheter séparément via les liens ci-dessous.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUCTION AUX COMPOSANTS
        - LIEN D'ACHAT

    *   - :ref:`cpn_uno`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_thermistor`
        - |link_thermistor_buy|

**Schéma**

.. image:: img/circuit_5.5_thermistor.png

Chaque thermistance a une résistance normale. Ici, elle est de 10k ohms, mesurée à 25 degrés Celsius.

Lorsque la température augmente, la résistance de la thermistance diminue. Les données de tension sont ensuite converties en quantités numériques par l'adaptateur A/D. 

La température en Celsius ou Fahrenheit est obtenue via programmation.

Voici la relation entre la résistance et la température :

    **RT = RN exp(B(1/TK – 1/TN))**

    * **RT** est la résistance de la thermistance NTC lorsque la température est **TK**.
    * **RN** est la résistance de la thermistance NTC à la température nominale TN. Ici, la valeur de RN est de 10k.
    * **TK** est une température en Kelvin, et l'unité est K. Ici, la valeur de **TK** est ``273.15 + degree Celsius``.
    * **TN** est une température nominale en Kelvin, également en K. Ici, la valeur de TN est ``273.15+25``.
    * **B (bêta)**, la constante matérielle de la thermistance NTC, est également appelée indice de sensibilité thermique avec une valeur numérique de ``3950``.
    * **exp** est l'abréviation d'exponentielle, et le nombre de base ``e`` est un nombre naturel égal à environ 2,7.

    Transformez cette formule ``TK=1/(ln(RT/RN)/B+1/TN)`` pour obtenir la température Kelvin, qui moins 273,15 donne la température en degrés Celsius.

    Cette relation est une formule empirique. Elle est précise uniquement lorsque la température et la résistance sont dans la plage effective.

**Câblage**

.. note::
    * La thermistance est noire ou verte et marquée 103.

.. image:: img/4.5_thermistor_bb.png
    :width: 600
    :align: center

**Code**

.. note::

   * Ouvrez le fichier ``4.5_thermometer.ino`` dans le chemin ``euler-kit/arduino/4.5_thermometer``. 
   * Ou copiez ce code dans **Arduino IDE**.
   
   

    N'oubliez pas de sélectionner la carte Raspberry Pi Pico et le port correct avant de cliquer sur le bouton Upload.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/1ceb0ea2-a330-4052-824d-bd6762c6f0e0/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    

Après avoir téléversé le code, le Moniteur Série affichera les températures en Celsius et en Fahrenheit.
