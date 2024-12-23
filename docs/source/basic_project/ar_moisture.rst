.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et à des promotions festives.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !
.. _ar_moisture:

4.4 Mesurer l'humidité du sol
================================

Dans l'industrie agricole, les cultures ne peuvent pas directement absorber les éléments 
inorganiques du sol. L'eau présente dans le sol agit comme un solvant pour dissoudre ces 
éléments inorganiques.

Les cultures absorbent l'humidité du sol via leur système racinaire, ce qui leur permet 
d'acquérir des nutriments et de favoriser leur croissance.

Au cours du processus de croissance et de développement des cultures, les exigences en 
matière de température et d'humidité du sol varient également. Par conséquent, un capteur 
d'humidité du sol est nécessaire.

**Composants nécessaires**

Dans ce projet, nous avons besoin des composants suivants :

C'est pratique d'acheter un kit complet, voici le lien :

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nom
        - ARTICLES DANS CE KIT
        - LIEN
    *   - Kit de démarrage 3 en 1
        - 380+
        - |link_3IN1_kit|

Vous pouvez également les acheter séparément via les liens ci-dessous.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUCTION DES COMPOSANTS
        - LIEN D'ACHAT

    *   - :ref:`cpn_uno`
        - \-
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_soil_moisture`
        - |link_soil_moisture_buy|

**Schéma**

.. image:: img/circuit_5.4_soil.png

**Câblage**

.. image:: img/4.4_measure_the_moisture_bb.png
    :width: 800
    :align: center

**Code**

.. note::

    * Ouvrez le fichier ``4.4.measure_soil_moisture.ino`` dans le répertoire ``3in1-kit\learning_project\4.4.measure_soil_moisture``.
    * Ou copiez ce code dans l'IDE Arduino.
    

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/b6f7e756-0f14-4117-9bb2-ee5083b6445f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Une fois le code téléchargé avec succès, le moniteur série affichera la valeur d'humidité du sol.



En insérant le module dans le sol et en l'arrosant, la valeur du capteur d'humidité du sol diminuera.
