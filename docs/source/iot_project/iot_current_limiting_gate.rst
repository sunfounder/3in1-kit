.. note:: 

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour perfectionner vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus exclusifs.
    - **Réductions spéciales** : Profitez de remises exclusives sur nos nouveaux produits.
    - **Promotions festives et cadeaux** : Participez à des promotions et des concours pendant les fêtes.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _iot_gate:

7. Barrière intelligente avec limitation de courant
========================================================

Certaines situations, comme les parkings, nécessitent une gestion quantitative.

Ici, nous créons une barrière intelligente : un servo-moteur est utilisé comme barrière, et un détecteur d'obstacle infrarouge est placé devant. Si un objet (comme une voiture) est détecté, la barrière s'ouvre et le compteur est incrémenté de 1. 
Le compteur est affiché sur un afficheur 7 segments et est également envoyé au Cloud Blynk pour une consultation à distance. Enfin, un widget Switch de Blynk permet d'activer ou de désactiver ce système de barrière intelligente.

**Composants requis**

Pour ce projet, nous avons besoin des composants suivants. 

Il est bien sûr pratique d'acheter un kit complet. Voici le lien : 

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nom	
        - ÉLÉMENTS DANS CE KIT
        - LIEN
    *   - Kit de démarrage 3 en 1
        - 380+
        - |link_3IN1_kit|

Vous pouvez également les acheter séparément à partir des liens ci-dessous.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUCTION DES COMPOSANTS
        - LIEN D'ACHAT

    *   - :ref:`cpn_uno`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_esp8266`
        - |link_esp8266_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_servo`
        - |link_servo_buy|
    *   - :ref:`cpn_avoid`
        - |link_obstacle_avoidance_buy|
    *   - :ref:`cpn_7_segment`
        - |link_7segment_buy|
    *   - :ref:`cpn_74hc595`
        - |link_74hc595_buy|

**1. Construire le circuit**

.. note::

    Le module ESP8266 nécessite un courant élevé pour assurer un environnement de fonctionnement stable. Assurez-vous que la batterie 9V est connectée.

.. image:: img/iot_7_bb.png
    :width: 800
    :align: center

**2. Modifier le tableau de bord**

#. Pour enregistrer le nombre, créez un **Datastream** de type **Virtual Pin** sur la page **Datastream**. Réglez le TYPE DE DONNÉES sur ``Integer`` et les valeurs MIN et MAX sur ``0`` et ``10``.

    .. image:: img/sp220610_165328.png
 
#. Accédez maintenant à la page **Web Dashboard**, faites glisser un widget **Switch** pour définir son flux de données sur **V0** et un widget **Label** pour définir son flux de données sur **V8**.

    .. image:: img/sp220610_165548.png

**3. Exécuter le code**

#. Ouvrez le fichier ``7.current_limiting_gate.ino`` situé dans ``3in1-kit\iot_project\7.current_limiting_gate``, ou copiez ce code dans **Arduino IDE**.

    .. raw:: html
        
        <iframe src=https://create.arduino.cc/editor/sunfounder01/bd829175-652f-4c3e-85b0-048c3fda4555/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Remplacez les valeurs ``Template ID``, ``Device Name``, et ``Auth Token`` par vos informations personnelles. Entrez également le ``ssid`` et le ``password`` de votre réseau WiFi. Pour des tutoriels détaillés, reportez-vous à :ref:`connect_blynk`.
#. Après avoir sélectionné la carte et le port appropriés, cliquez sur le bouton **Téléverser**.

#. Ouvrez le Moniteur Série (réglez le débit en bauds à 115200) et attendez qu'un message de connexion réussie apparaisse.

    .. image:: img/2_ready.png

    .. note::

        Si le message ``ESP is not responding`` s'affiche lors de la connexion, suivez ces étapes.

        * Assurez-vous que la batterie 9V est branchée.
        * Réinitialisez le module ESP8266 en connectant la broche RST à GND pendant 1 seconde, puis débranchez-la.
        * Appuyez sur le bouton de réinitialisation sur la carte R4.

        Vous devrez peut-être répéter ces étapes 3 à 5 fois. Soyez patient.

#. Cliquez maintenant sur le widget Bouton de contrôle sur Blynk pour activer le système de barrière intelligente. Si le module d'évitement d'obstacles infrarouge détecte un obstacle, la barrière s'ouvre et l'afficheur 7 segments ainsi que le widget Compteur sur Blynk ajoutent 1.

    .. image:: img/sp220610_165548.png

#. Si vous souhaitez utiliser Blynk sur des appareils mobiles, reportez-vous à :ref:`blynk_mobile`.

    .. image:: img/mobile_gate.jpg

**Comment cela fonctionne-t-il ?**

La fonction ``BLYNK_WRITE(V0)`` obtient l'état du widget **Switch** et l'assigne à la variable ``doorFlag``, qui sera utilisée pour déterminer si le système de barrière intelligente est activé ou non.

.. code-block:: arduino

    BLYNK_WRITE(V0)
    {
        doorFlag = param.asInt(); // Activer la barrière
    }

Dans le Timer Blynk, ``doorFlag`` est évalué chaque seconde, et si le système est activé, la fonction principale de la barrière est exécutée.

.. code-block:: arduino

    void myTimerEvent()
    {
        if (doorFlag)
        {
            channelEntrance();
        }
    }

La fonction principale de la barrière est ``channelEntrance()``.
Lorsqu'un objet approche de la barrière (le capteur détecte un obstacle), le ``count`` est incrémenté de 1.
Le ``count`` est envoyé au flux de données ``V8`` du Cloud Blynk ainsi qu'à l'afficheur 7 segments du circuit, et la barrière s'ouvre.
Si l'objet passe de présent à absent, ce qui signifie qu'il est entré, la barrière se ferme.

.. code-block:: arduino

    void channelEntrance()
    {
        int currentState = digitalRead(irPin); // 0:obstacle 1:no-obstacle
        if (currentState == 0 && lastState == 1) {
            count=(count+1)%10;
            Blynk.virtualWrite(V8, count);
            showNumber(count);
            operateGate(true);
        } else if ((currentState == 1 && lastState == 0)) {
            operateGate(false);
        }
        lastState = currentState;
    }

La fonction ``showNumber(int num)`` permet d'afficher la valeur sur l'afficheur 7 segments.

.. code-block:: arduino

    void showNumber(int num)
    {
        digitalWrite(STcp, LOW); //ground ST_CP and hold low for as long as you are transmitting
        shiftOut(DS, SHcp, MSBFIRST, datArray[num]);
        digitalWrite(STcp, HIGH); //pull the ST_CPST_CP to save the data
    }

La fonction ``operateGate(bool openGate)`` ouvre lentement la barrière si la référence est ``True``, et la ferme lentement si la référence est ``False``.

.. code-block:: arduino

    void operateGate(bool openGate) {
        if (openGate == true) 
        {
            // ouvrir la barrière
            while (angle <= 90) { 
            angle++;
            myservo.write(angle);
            delay(5);
            }
        } else {
            // fermer la barrière
            while (angle >= 0){ 
            angle--;
            myservo.write(angle);
            delay(5);
            }
        }
    }