.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions festives et cadeaux** : Participez à des promotions et à des cadeaux festifs.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _ar_shiftout:

5.9 ShiftOut (LED)
=======================

La fonction ``shiftOut()`` permet au 74HC595 de produire 8 signaux numériques. Elle envoie le dernier bit du nombre binaire vers Q0 et le premier bit vers Q7. Autrement dit, écrire le nombre binaire “00000001” fera que Q0 produira un niveau haut et que Q1~Q7 produiront un niveau bas.

Dans ce projet, vous apprendrez à utiliser le 74HC595. Le 74HC595 se compose d’un registre à décalage de 8 bits et d’un registre de stockage avec sorties parallèles à trois états. Il convertit une entrée série en une sortie parallèle, permettant ainsi d’économiser des ports d’E/S sur un microcontrôleur.

Plus précisément, le 74HC595 peut remplacer 8 broches pour produire des signaux numériques en écrivant un nombre binaire de 8 bits.

* `Nombre binaire - Wikipédia <https://en.wikipedia.org/wiki/Binary_number>`_

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
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_74hc595`
        - |link_74hc595_buy|

**Schéma**

.. image:: img/circuit_6.4_74hc595.png

* Lorsque MR (pin10) est à un niveau haut et OE (pin13) à un niveau bas, les données sont saisies sur le front montant de SHcp et transférées au registre mémoire sur le front montant de SHcp.
* Si les deux horloges sont connectées ensemble, le registre à décalage est toujours une impulsion avant le registre mémoire.
* Il y a une broche d'entrée de décalage série (Ds), une broche de sortie série (Q) et un bouton de réinitialisation asynchrone (niveau bas) dans le registre mémoire.
* Le registre mémoire produit un bus parallèle à 8 bits et à trois états.
* Lorsque OE est activé (niveau bas), les données dans le registre mémoire sont sorties vers le bus (Q0 ~ Q7).

**Câblage**

.. image:: img/5.9_74hc595_bb.png
    :width: 800
    :align: center

**Code**

.. note::

    * Ouvrez le fichier ``5.9.shiftout_led.ino`` dans le chemin ``3in1-kit\learning_project\5.9.shiftout_led``.
    * Ou copiez ce code dans **Arduino IDE**.
    
    

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/4c208eb3-67f0-40f7-999a-0eeca8b6b466/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Après avoir téléversé le code sur la carte R4, vous verrez les LED s’allumer une par une.

**Comment cela fonctionne-t-il ?**

Déclarez un tableau pour stocker plusieurs nombres binaires sur 8 bits qui sont utilisés pour changer l’état de fonctionnement des huit LED contrôlées par le 74HC595.

.. code-block:: arduino

    int datArray[] = {B00000000, B00000001, B00000011, B00000111, B00001111, B00011111, B00111111, B01111111, B11111111};

Réglez ``STcp`` à un niveau bas puis à un niveau haut pour générer une impulsion de front montant pour STcp.

.. code-block:: arduino

    digitalWrite(STcp,LOW); 

La fonction ``shiftOut()`` est utilisée pour décaler un octet de données, bit par bit, 
ce qui signifie décaler un octet de données de ``datArray[num]`` vers le registre de 
décalage via la broche ``DS``. **MSBFIRST** signifie décaler les bits de poids fort en premier.

.. code-block:: arduino

    shiftOut(DS,SHcp,MSBFIRST,datArray[num]);

Après l'exécution de ``digitalWrite(STcp,HIGH)``, STcp passe au front montant. 
À ce moment, les données du registre de décalage seront transférées vers le registre mémoire.

.. code-block:: arduino

    digitalWrite(STcp,HIGH);

Un octet de données sera transféré dans le registre mémoire après 8 décalages. 
Ensuite, les données du registre mémoire sont sorties vers le bus (Q0-Q7). 
Par exemple, ``shiftOut(B00000001)`` allumera la LED contrôlée par Q0 et éteindra 
celles contrôlées par Q1~Q7.
