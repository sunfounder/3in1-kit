.. note:: 

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour perfectionner vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus exclusifs.
    - **Réductions spéciales** : Profitez de remises exclusives sur nos nouveaux produits.
    - **Promotions festives et cadeaux** : Participez à des promotions et des concours pendant les fêtes.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _iot_car:

8. Voiture IoT
====================

Dans ce projet, nous utilisons l'application Blynk sur un téléphone portable pour contrôler la voiture. Mais vous devez vous référer à :ref:`car_projects` pour assembler la voiture et acquérir une compréhension de base de son fonctionnement. 
À l'ère de la popularité des réseaux 5G, ce mode pourrait devenir l'une des principales méthodes de production dans de nombreuses industries. Alors, explorons cette approche dès maintenant.

**1. Construire le circuit**

.. image:: img/iot_car.png
    :width: 800


**2. Modifier le tableau de bord**


Blynk sur mobile ne permet pas de modifier les flux de données. Ces étapes doivent donc être réalisées sur l'interface web.

#. Créez un **Datastream** de type **Virtual Pin** sur la page **Datastream** pour enregistrer la valeur de l'axe X du joystick. Réglez le NOM sur ``Xvalue``, le TYPE DE DONNÉES sur ``Integer``, et les valeurs MIN et MAX sur ``-10`` et ``10``.

    .. image:: img/sp220613_164507.png

#. Créez un autre **Datastream** de type **Virtual Pin** pour enregistrer la valeur de l'axe Y du joystick. Réglez le NOM sur ``Yvalue``, le TYPE DE DONNÉES sur ``Integer``, et les valeurs MIN et MAX sur ``-10`` et ``10``.

    .. image:: img/sp220613_164717.png

Ensuite, effectuez les étapes suivantes sur votre téléphone.

1. Recherchez "Blynk IoT" (et non Blynk (legacy)) sur GOOGLE Play ou l'App Store pour le télécharger.
2. Après avoir ouvert l'application, connectez-vous avec le même compte que celui utilisé sur le client web.
3. Accédez au tableau de bord (si vous n'en avez pas, créez-en un) et vous verrez que les tableaux de bord pour mobile et web sont indépendants.

.. image:: img/APP_1.jpg

4. Cliquez sur l'icône d'édition.
5. Appuyez sur une zone vide.
6. Sélectionnez un widget Joystick.

.. image:: img/APP_2.jpg

7. Un widget Joystick apparaîtra dans la zone vide, cliquez dessus.
8. Dans les paramètres du joystick, sélectionnez les ``Xvalue`` et ``Yvalue`` que vous venez de configurer dans les flux de données.
9. Revenez à la page du tableau de bord et vous pourrez manipuler le joystick.

.. image:: img/APP_3.jpg


**3. Exécuter le code**

#. Ouvrez le fichier ``8.iot_car.ino`` situé dans ``3in1-kit\iot_project\8.iot_car`` ou copiez ce code dans l'**Arduino IDE**.

    .. raw:: html 
        
        <iframe src=https://create.arduino.cc/editor/sunfounder01/a1db6c35-2f26-425c-8636-53d2df7936d7/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Remplacez les valeurs ``Template ID``, ``Device Name`` et ``Auth Token`` par vos informations personnelles. Entrez également le ``ssid`` et le ``password`` de votre réseau WiFi. Pour des tutoriels détaillés, reportez-vous à :ref:`connect_blynk`.
#. Après avoir sélectionné la carte et le port appropriés, cliquez sur le bouton **Téléverser**.

#. Ouvrez le Moniteur Série (définissez le débit en bauds à 115200) et attendez qu'un message de connexion réussie apparaisse.

    .. image:: img/2_ready.png

    .. note::

        Si le message ``ESP is not responding`` s'affiche lors de la connexion, suivez ces étapes :

        * Assurez-vous que la batterie 9V est branchée.
        * Réinitialisez le module ESP8266 en connectant la broche RST à GND pendant 1 seconde, puis débranchez-la.
        * Appuyez sur le bouton de réinitialisation sur la carte R4.

        Vous devrez peut-être répéter ces étapes 3 à 5 fois. Soyez patient.

#. Débranchez le câble USB et alimentez la voiture avec une batterie 9V, attendez que la LED s'allume, ce qui indique que la voiture est connectée à Blynk.
#. Ouvrez Blynk sur votre téléphone et utilisez le widget Joystick pour contrôler les mouvements de la voiture.

    .. image:: img/iot_car.jpg



**Comment cela fonctionne-t-il ?**

Ces fonctions permettent de contrôler les mouvements de la voiture.

.. code-block:: arduino

    void moveForward(int speed) {...}
    void moveBackward(int speed) {...}
    void turnRight(int speed) {...}
    void turnLeft(int speed) {...}
    void stopMove() {...}

La section IoT lit les valeurs du widget Joystick et les assigne aux variables ``Xvalue`` et ``Yvalue``.

.. code-block:: arduino

    int Xvalue = 0;
    int Yvalue = 0;

    BLYNK_WRITE(V9)
    {
        Xvalue = param.asInt();
    }

    BLYNK_WRITE(V10)
    {
        Yvalue = param.asInt();
    }

Dans la fonction ``loop()``, faites effectuer différentes actions à la voiture en fonction des valeurs de ``Xvalue`` et ``Yvalue``.

.. code-block:: arduino

    if (Yvalue >= 5) {
        moveForward(255);
    } else if (Yvalue <= -5) {
        moveBackward(255);
    } else if (Xvalue >= 5) {
        turnRight(150);
    } else if (Xvalue <= -5) {
        turnLeft(150);
    } else {
        stopMove();
    }

Ajoutez également une vérification du statut réseau dans la fonction ``loop()`` pour allumer une LED si elle est connectée à Blynk Cloud.

.. code-block:: arduino

    if (!Blynk.connected()) {
        digitalWrite(ledPin, LOW);
        Serial.print("offline!");
        bool result = Blynk.connect();
        Serial.println(result);
    } else {
        digitalWrite(ledPin, HIGH);
    }