.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et à des promotions festives.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !
.. _ar_map:

5.6 Mappage
==============

Si vous observez attentivement, vous remarquerez que de nombreuses valeurs ont des plages différentes en programmation.
Par exemple, la plage des valeurs des entrées analogiques est (0~1023).
La plage des valeurs de sortie analogique est (0~255).
L'angle de sortie du servo est (0~180).

Cela signifie que si nous voulons utiliser un potentiomètre pour contrôler la luminosité d'une LED ou l'angle d'un servo, nous devons effectuer une opération de mappage.

Voyons maintenant comment y parvenir.

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
    *   - :ref:`cpn_servo`
        - |link_servo_buy|
    *   - :ref:`cpn_potentiometer`
        - |link_potentiometer_buy|

**Schéma**

.. image:: img/circuit_8.3_amp.png

**Câblage**

.. image:: img/5.6_map_bb.png
    :width: 800
    :align: center

**Code**

.. note::

    * Ouvrez le fichier ``5.6.map.ino`` dans le répertoire ``3in1-kit\learning_project\5.6.map``.
    * Ou copiez ce code dans l'IDE Arduino.
    

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/f00e4c4c-fb13-4445-9d89-eb2857b5fe87/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Une fois le code téléchargé avec succès, vous pouvez tourner le potentiomètre dans les deux sens, et l'arbre de sortie du servo se déplacera en conséquence.

**Comment ça fonctionne ?**

``map(value, fromLow, fromHigh, toLow, toHigh)`` : Permet de mapper un nombre d'une plage à une autre.
Ainsi, une valeur fromLow est mappée à toLow, et une valeur fromHigh est mappée à toHigh.

    **Syntaxe**
        map(value, fromLow, fromHigh, toLow, toHigh)

    **Paramètres**
        * ``value`` : la valeur à mapper.
        * ``fromLow`` : la borne inférieure de la plage actuelle de la valeur.
        * ``fromHigh`` : la borne supérieure de la plage actuelle de la valeur.
        * ``toLow`` : la borne inférieure de la plage cible.
        * ``toHigh`` : la borne supérieure de la plage cible.

Si le potentiomètre contrôle la LED, vous pouvez également utiliser la fonction map() pour réaliser la tâche.

.. code-block:: arduino

    int x = analogRead(knob);
    int y = map(x,0,1023,0,255);
    analogWrite(led,y);


**Notes et avertissements**

* Les "bornes inférieures" des deux plages peuvent être plus grandes ou plus petites que les "bornes supérieures", ce qui signifie que la fonction ``map()`` peut également être utilisée pour inverser une plage de nombres.

  .. code-block:: arduino

    y = map(x,0,180,180,0);

* Le mappage fonctionne également pour les nombres négatifs.

  .. code-block:: arduino

    y = map(x,0,1023,-90,90);

* Le mappage utilise des entiers, les décimales des nombres flottants sont donc supprimées.
