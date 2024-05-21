.. note::

    Bonjour et bienvenue dans la Communauté Facebook des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez [|link_sf_facebook|] et rejoignez-nous aujourd'hui !

.. _ar_temp:

4.5 Thermomètre
===========================

Un thermomètre est un appareil qui mesure la température ou un gradient de température (le degré de chaleur ou de froid d'un objet).
Un thermomètre a deux éléments importants : (1) un capteur de température (par exemple, le bulbe d'un thermomètre à mercure ou le capteur pyrométrique dans un thermomètre infrarouge) dans lequel un changement se produit avec un changement de température ;
et (2) un moyen de convertir ce changement en une valeur numérique (par exemple, l'échelle visible qui est marquée sur un thermomètre à mercure ou l'affichage numérique sur un modèle infrarouge).
Les thermomètres sont largement utilisés dans la technologie et l'industrie pour surveiller les processus, en météorologie, en médecine et dans la recherche scientifique.

Un thermistor est un type de capteur de température dont la résistance dépend fortement de la température, et il a deux types :
Coefficient de Température Négatif (NTC) et Coefficient de Température Positif (PTC),
également connus sous les noms de NTC et PTC. La résistance du thermistor PTC augmente avec la température, tandis que la condition du NTC est opposée à la précédente.

Dans cette expérience, nous utilisons un **thermistor NTC** pour fabriquer un thermomètre.

**Composants requis**

Pour ce projet, nous avons besoin des composants suivants.

Il est certainement pratique d'acheter un kit complet, voici le lien :

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nom	
        - ÉLÉMENTS DE CE KIT
        - LIEN
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

Vous pouvez également les acheter séparément via les liens ci-dessous.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUCTION DES COMPOSANTS
        - LIEN D'ACHAT

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
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

Chaque thermistor a une résistance normale. Ici, elle est de 10k ohms, mesurée à 25 degrés Celsius.

Lorsque la température augmente, la résistance du thermistor diminue. Ensuite, les données de tension sont converties en quantités numériques par l'adaptateur A/D.

La température en degrés Celsius ou Fahrenheit est sortie par programmation.

Voici la relation entre la résistance et la température :

    **RT =RN expB(1/TK – 1/TN)** 

    * **RT** est la résistance du thermistor NTC lorsque la température est **TK**. 
    * **RN** est la résistance du thermistor NTC sous la température nominale TN. Ici, la valeur numérique de RN est de 10k. 
    * **TK** est une température Kelvin et l'unité est K. Ici, la valeur numérique de **TK** est ``273.15 + degrés Celsius``. 
    * **TN** est une température Kelvin nominale ; l'unité est également K. Ici, la valeur numérique de TN est ``273.15+25``.
    * Et **B(beta)**, la constante matérielle du thermistor NTC, est également appelée indice de sensibilité thermique avec une valeur numérique ``3950``. 
    * **exp** est l'abréviation d'exponentiel, et le nombre de base ``e`` est un nombre naturel et vaut approximativement 2.7.

    Convertissez cette formule ``TK=1/(ln(RT/RN)/B+1/TN)`` pour obtenir une température Kelvin qui moins 273.15 équivaut aux degrés Celsius.

    Cette relation est une formule empirique. Elle n'est précise que lorsque la température et la résistance sont dans la plage effective.


**Câblage**

.. note::
    * Le thermistor est noir ou vert et marqué 103.

.. image:: img/thermistor_bb.png
    :width: 600
    :align: center

**Code**

.. note::

   * Ouvrez le fichier ``4.5_thermometer.ino`` sous le chemin ``euler-kit/arduino/4.5_thermometer``. 
   * Ou copiez ce code dans **Arduino IDE**.
   
   * Ou téléchargez le code via l'`Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

    N'oubliez pas de sélectionner la carte Raspberry Pi Pico et le port correct avant de cliquer sur le bouton Télécharger.


.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/1ceb0ea2-a330-4052-824d-bd6762c6f0e0/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    

Après le téléchargement réussi du code, le Moniteur Série affichera les températures en degrés Celsius et Fahrenheit.

