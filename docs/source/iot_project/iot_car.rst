.. note::

    Bonjour et bienvenue dans la Communauté Facebook des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez [|link_sf_facebook|] et rejoignez-nous aujourd'hui !

.. _iot_car:

8. Voiture IoT
====================

Pour ce projet, nous avons utilisé l'application Blynk sur le téléphone portable pour contrôler la voiture. Mais vous devez vous référer à :ref:`car_projects` pour assembler la voiture et pour en comprendre les bases.
À l'ère de la popularité du réseau 5G, ce mode pourrait devenir l'une des principales méthodes de production dans de nombreuses industries, alors expérimentons ce jeu en avance.

**1. Construire le Circuit**

.. image:: img/wiring_iot_car.png
    :width: 800


**2. Éditer le Tableau de Bord**

Blynk sur mobile ne peut pas éditer les Datastream, nous devons donc toujours effectuer ces étapes sur le côté web.

#. Créez un **Datastream** de type **Virtual Pin** sur la page **Datastream**, pour enregistrer la valeur de l'axe X du joystick. Nommez-le ``Xvalue``, réglez le TYPE DE DONNÉES sur ``Integer``, et MIN et MAX sur ``-10`` et ``10``.

    .. image:: img/sp220613_164507.png

#. Créez un **Datastream** de type **Virtual Pin** pour enregistrer la valeur de l'axe Y du joystick. Nommez-le ``Yvalue``, réglez le TYPE DE DONNÉES sur ``Integer``, MIN et MAX sur ``-10`` et ``10``.

    .. image:: img/sp220613_164717.png

Ensuite, vous devez faire ce qui suit sur votre téléphone.

1. Recherchez "Blynk IoT" (pas Blynk(legacy)) sur GOOGLE Play ou l'APP Store pour le télécharger.
2. Après avoir ouvert l'APP, connectez-vous, ce compte doit être le même que celui utilisé sur le client web.
3. Allez ensuite sur le tableau de bord (si vous n'en avez pas, créez-en un) et vous verrez que les tableaux de bord mobiles et web sont indépendants l'un de l'autre.

.. image:: img/APP_1.jpg

4. Cliquez sur l'icône Éditer.
5. Cliquez sur la zone vide.
6. Sélectionnez un widget Joystick.

.. image:: img/APP_2.jpg

7. Maintenant, vous verrez un widget Joystick apparaître dans la zone vide, cliquez dessus.
8. Les paramètres du Joystick apparaîtront, sélectionnez les Xvalue et Yvalue que vous venez de régler dans les datastreams.
9. Retournez sur la page du tableau de bord et vous pourrez utiliser le Joystick quand vous le souhaitez.

.. image:: img/APP_3.jpg


**3. Exécutez le Code**


#. Ouvrez le fichier ``8.iot_car.ino`` situé dans le dossier ``3in1-kit\iot_project\8.iot_car``, ou copiez ce code dans **Arduino IDE**.

    .. raw:: html 
        
        <iframe src=https://create.arduino.cc/editor/sunfounder01/a1db6c35-2f26-425c-8636-53d2df7936d7/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Remplacez le ``Template ID``, ``Device Name`` et ``Auth Token`` par les vôtres. Vous devez également entrer le ``ssid`` et le ``password`` du WiFi que vous utilisez. Pour des tutoriels détaillés, veuillez vous référer à :ref:`connect_blynk`.
#. Après avoir sélectionné la bonne carte et le bon port, cliquez sur le bouton **Upoad**.

#. Ouvrez le moniteur série (réglez le débit en bauds sur 115200) et attendez qu'un message tel qu'une connexion réussie apparaisse.

    .. image:: img/2_ready.png

    .. note::

        Si le message ``ESP is not responding`` apparaît lors de la connexion, veuillez suivre ces étapes.

        * Assurez-vous que la batterie 9V est branchée.
        * Réinitialisez le module ESP8266 en connectant la broche RST à GND pendant 1 seconde, puis débranchez-la.
        * Appuyez sur le bouton de réinitialisation de la carte R3.

        Parfois, il peut être nécessaire de répéter l'opération ci-dessus 3 à 5 fois, veuillez être patient.

#. Maintenant, débranchez le câble USB et alimentez la voiture avec une batterie 9V uniquement, puis attendez que la LED s'allume, indiquant que la voiture est connectée à Blynk.
#. Ouvrez Blynk sur votre téléphone et vous pouvez utiliser le widget Joystick pour contrôler le mouvement de la voiture.

    .. image:: img/iot_car.jpg



**Comment ça fonctionne ?**

Ces fonctions sont utilisées pour contrôler le mouvement de la voiture.

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

Dans ``loop()``, faites exécuter différentes actions à la voiture en fonction des ``Xvalue`` et ``Yvalue``.

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

Ajoutez également une détermination de l'état du réseau à ``loop()`` pour allumer une LED si elle est connectée au Cloud Blynk.

.. code-block:: arduino

    if (!Blynk.connected()) {
        digitalWrite(ledPin, LOW);
        Serial.print("offline!");
        bool result = Blynk.connect();
        Serial.println(result);
    } else {
        digitalWrite(ledPin, HIGH);
    }