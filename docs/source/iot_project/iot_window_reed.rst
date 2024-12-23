.. note:: 

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour perfectionner vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus exclusifs.
    - **Réductions spéciales** : Profitez de remises exclusives sur nos nouveaux produits.
    - **Promotions festives et cadeaux** : Participez à des promotions et des concours pendant les fêtes.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _iot_window:

3. Envoyer des données vers Blynk
=====================================

Ce chapitre vous montrera comment envoyer des données vers Blynk.

Nous allons créer ici un dispositif de détection de porte et de fenêtre. Le circuit avec l'interrupteur à lame est placé près des portes et fenêtres, et un aimant est fixé sur le bord des portes et fenêtres. 
Lorsque la porte ou la fenêtre est fermée, l'interrupteur à lame s'active sous l'effet de la force magnétique, et la valeur du pin correspondant sur la carte R4 change.
Blynk.cloud recevra cette valeur, vous permettant ainsi de savoir si les portes et fenêtres de votre maison sont fermées, même lorsque vous êtes absent.

Nous utiliserons maintenant un widget LED dans Blynk pour indiquer si vos portes et fenêtres sont fermées (c'est-à-dire si l'interrupteur à lame est activé ou désactivé).

**Composants nécessaires**

Dans ce projet, nous avons besoin des composants suivants :

Il est certainement plus pratique d'acheter un kit complet, voici le lien : 

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
    *   - :ref:`cpn_reed`
        - \-

**1. Construire le circuit**

.. note::

    Le module ESP8266 nécessite un courant élevé pour offrir un environnement de fonctionnement stable, assurez-vous que la batterie 9V est bien branchée.

.. image:: img/iot_3_bb.png

**2. Modifier le tableau de bord**

#. Créez un **Datastream** de type **Virtual Pin** dans la page **Datastream** pour obtenir la valeur de l'interrupteur à lame. Définissez le TYPE DE DONNÉES sur **Integer** et MIN et MAX sur **0** et **1**.

    .. image:: img/sp220609_162548.png

#. Faites glisser un widget **LED** dans la page **Tableau de bord Web**. Lorsque la valeur est de 1, la LED s'allumera (avec couleur), sinon elle sera blanche.

    .. image:: img/blynk_edit_drag_led_widget.png
        
#. Dans la page des paramètres du widget **LED**, sélectionnez **Datastream** comme **Reed(V1)**, puis enregistrez.

    .. image:: img/sp220609_163502.png

**3. Exécuter le code**

#. Ouvrez le fichier ``3.push_data_to_blynk.ino`` dans le chemin ``3in1-kit\iot_project\3.push_data_to_blynk``, ou copiez ce code dans l'**Arduino IDE**.


    .. raw:: html
        
        <iframe src=https://create.arduino.cc/editor/sunfounder01/e81b0024-c11e-4507-8d43-aeb3b6656c2c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


#. Remplacez le ``Template ID``, ``Device Name`` et ``Auth Token`` par les vôtres. Vous devez également saisir le ``ssid`` et le ``password`` du WiFi que vous utilisez. Pour des tutoriels détaillés, veuillez vous référer à :ref:`connect_blynk`.
#. Après avoir sélectionné la carte et le port corrects, cliquez sur le bouton **Téléverser**.

#. Ouvrez le Moniteur série (définissez le débit en bauds sur 115200) et attendez qu'un message de connexion réussie apparaisse.

    .. image:: img/2_ready.png

    .. note::

        Si le message ``ESP is not responding`` apparaît lors de la connexion, suivez ces étapes :

        * Assurez-vous que la batterie 9V est branchée.
        * Réinitialisez le module ESP8266 en connectant le pin RST à GND pendant 1 seconde, puis débranchez-le.
        * Appuyez sur le bouton de réinitialisation de la carte R4.

        Parfois, vous devrez peut-être répéter cette opération 3 à 5 fois, soyez patient.

#. Maintenant, Blynk affichera l'état de vos portes et fenêtres. Si elles sont fermées, le widget LED sera vert, sinon il sera gris.

#. Si vous souhaitez utiliser Blynk sur des appareils mobiles, veuillez vous référer à :ref:`blynk_mobile`.

**Comment ça fonctionne ?**

Pour cet exemple, concentrez-vous sur les lignes suivantes. L'écriture des données chaque seconde dans le Datastream V1 de Blynk Cloud est définie par ces lignes.

.. code-block:: arduino

    BlynkTimer timer;

    void myTimerEvent()
    {
        Blynk.virtualWrite(V1, pinValue);
    }

    void setup()
    {
        timer.setInterval(1000L, myTimerEvent);
    }

    void loop()
    {
        timer.run(); // Initialise BlynkTimer
    }

La bibliothèque Blynk fournit un minuteur intégré, nous créons d'abord un objet minuteur.

.. code-block:: arduino

    BlynkTimer timer;

Définissez l'intervalle du minuteur dans ``setup()``, ici il est défini pour exécuter la fonction ``myTimerEvent()`` toutes les 1000ms.

.. code-block:: arduino

    timer.setInterval(1000L, myTimerEvent);

Exécutez BlynkTimer dans ``loop()``.

.. code-block:: arduino

    timer.run();

Modifiez la fonction personnalisée ``myTimerEvent()``, le code ``Blynk.virtualWrite(V1, pinValue)`` est utilisé pour écrire la donnée ``pinValue`` pour V1.

.. code-block:: arduino

    void myTimerEvent()
    {
        Blynk.virtualWrite(V1, pinValue);
    }

