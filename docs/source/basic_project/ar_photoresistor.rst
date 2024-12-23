.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et à des promotions festives.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _ar_photoresistor:

4.2 Ressentir la lumière
============================

La photorésistance est un dispositif typique pour les entrées analogiques, utilisé de manière très similaire à un potentiomètre. Sa valeur de résistance dépend de l'intensité de la lumière : plus la lumière irradiée est forte, plus la résistance est faible ; inversement, la résistance augmente.

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_buy|

**Schéma**

.. image:: img/circuit_5.2_light.png

Dans ce circuit, la résistance de 10 kΩ et la photorésistance sont connectées en série, et le courant qui les traverse est le même. La résistance de 10 kΩ agit comme une protection, et la broche A0 lit la valeur après la conversion de tension de la photorésistance.

Lorsque la lumière est renforcée, la résistance de la photorésistance diminue, alors sa tension diminue, ce qui fait augmenter la valeur de la broche A0. 
Si la lumière est suffisamment forte, la résistance de la photorésistance sera proche de 0, et la valeur de la broche A0 sera proche de 1023. 
Dans ce cas, la résistance de 10 kΩ joue un rôle de protection, empêchant ainsi que le 5V et le GND soient connectés ensemble, ce qui entraînerait un court-circuit.

Si vous placez la photorésistance dans l'obscurité, la valeur de la broche A0 diminuera. 
Dans une obscurité suffisante, la résistance de la photorésistance sera infinie, et sa tension sera proche de 5V (la résistance de 10 kΩ est négligeable), ce qui entraînera une valeur de la broche A0 proche de 0.

**Câblage**

.. image:: img/4.2_feel_the_light_bb.png
    :width: 600
    :align: center

**Code**

.. note::

    * Ouvrez le fichier ``4.2.feel_the_light.ino`` dans le répertoire ``3in1-kit\learning_project\4.2.feel_the_light``.
    * Ou copiez ce code dans l'IDE Arduino.
    

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/e1bc4c8b-788e-4bfe-a0a1-532d4fdc7753/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Après avoir téléchargé le code avec succès, le moniteur série imprimera les valeurs de la photorésistance. 
Plus la luminosité ambiante est forte, plus la valeur affichée sur le moniteur série sera grande.
