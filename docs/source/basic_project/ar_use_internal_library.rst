.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Explorez en profondeur Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Assistance d'experts** : Résolvez les problèmes après-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits.
    - **Réductions spéciales** : Profitez de remises exclusives sur nos derniers produits.
    - **Promotions et concours festifs** : Participez à des concours et des promotions spéciales.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _ar_servo:

5.5 Utiliser une bibliothèque intégrée
==========================================

Dans l'IDE Arduino, vous pouvez utiliser de nombreuses bibliothèques intégrées en ajoutant directement le fichier ``.h`` correspondant à votre code.

Ce projet utilise la bibliothèque ``Servo`` pour piloter le Servo, afin qu'il puisse effectuer une rotation entre 0° et 180°.

**Composants requis**

Pour ce projet, nous avons besoin des composants suivants :

Il est très pratique d’acheter un kit complet. Voici le lien :

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_servo`
        - |link_servo_buy|

**Schéma**

.. image:: img/circuit_6.2_servo.png

Dans ce projet, nous utilisons la broche PWM 9 pour piloter le Servo, en connectant 
le fil orange du servo à la broche PWM 9, le fil rouge à 5V, et le fil marron à GND.

**Câblage**

.. image:: img/5.5_swinging_servo_bb.png

**Code**

.. note::

    * Ouvrez le fichier ``5.5.use_internal_library.ino`` dans le chemin ``3in1-kit\learning_project\5.5.use_internal_library``.
    * Ou copiez ce code dans **Arduino IDE**.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/fa27db71-b191-4eda-b5c7-bbbe5f2652ca/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Une fois que vous avez terminé le téléchargement du code sur la carte R4, vous pouvez voir le bras du servo effectuer une rotation dans la plage de 0° à 180°.

**Comment ça fonctionne ?**

En appelant la bibliothèque ``Servo.h``, vous pouvez piloter le servo facilement.

.. code-block:: arduino

    #include <Servo.h>

Fonctions de la bibliothèque :

.. code-block:: arduino

    Servo

Créer un objet **Servo** pour contrôler un servo.

.. code-block:: arduino

    uint8_t attach(int pin);

Appeler ``pinMode()`` pour transformer une broche en pilote de servo et retourner 0 en cas d'échec.

.. code-block:: arduino

    void detach();

Libérer une broche du pilotage de servo.

.. code-block:: arduino

    void write(int value);

Définir l'angle du servo en degrés, de 0 à 180.

.. code-block:: arduino

    int read();

Retourne la valeur définie lors du dernier appel à ``write()``.

.. code-block:: arduino

    bool attached();

Retourne 1 si le servo est actuellement attaché.
