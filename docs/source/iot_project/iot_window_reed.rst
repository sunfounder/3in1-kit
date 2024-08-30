.. note::

    Bonjour et bienvenue dans la Communauté Facebook des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez [|link_sf_facebook|] et rejoignez-nous aujourd'hui !

.. _iot_window:

3. Envoyer des Données à Blynk
=================================

Ce chapitre vous montrera comment envoyer des données à Blynk.

Nous créons ici un dispositif de détection de portes et fenêtres. Le circuit avec l'interrupteur à lames (reed switch) est placé à côté de la porte et de la fenêtre, et l'aimant est monté sur le bord de la porte et de la fenêtre.
Lorsque la porte ou la fenêtre est fermée, l'interrupteur à lames sera activé par la force magnétique et la valeur de pin correspondante sur la carte R3 changera.
Blynk.cloud recevra cette valeur afin que vous puissiez voir si les portes et fenêtres de votre maison sont fermées, même lorsque vous n'êtes pas à la maison.

Nous utiliserons maintenant un widget LED dans Blynk pour indiquer si vos fenêtres et portes sont fermées (c'est-à-dire si l'interrupteur à lames est activé ou désactivé).

**Composants Requis**

Pour ce projet, nous avons besoin des composants suivants.

Il est certainement pratique d'acheter un kit complet, voici le lien :

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nom	
        - ÉLÉMENTS DANS CE KIT
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
    *   - :ref:`cpn_esp8266`
        - |link_esp8266_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_reed`
        - \-

**1. Construire le Circuit**

.. note::

    Le module ESP8266 nécessite un courant élevé pour fournir un environnement de fonctionnement stable, donc assurez-vous que la batterie 9V est branchée.


.. image:: img/wiring_reed.jpg

**2. Éditer le Tableau de Bord**

#. Créez un **Datastream** de type **Virtual Pin** sur la page **Datastream** pour obtenir la valeur de l'Interrupteur à Lames. Réglez le TYPE DE DONNÉES sur **Integer** et MIN et MAX sur **0** et **1**.

    .. image:: img/sp220609_162548.png

#. Faites glisser et déposez un **LED widget** sur la page **Wed Dashboard**, à une valeur de 1, il s'allumera (avec couleur), sinon il sera blanc.

    .. image:: img/blynk_edit_drag_led_widget.png

#. Dans la page de paramètres du **LED widget**, sélectionnez **Datastream** comme **Reed(V1)**, et enregistrez-le.

    .. image:: img/sp220609_163502.png

**3. Exécutez le Code**

#. Ouvrez le fichier ``3.push_data_to_blynk.ino`` situé dans le dossier ``3in1-kit\iot_project\3.push_data_to_blynk``, ou copiez ce code dans **Arduino IDE**.


    .. raw:: html
        
        <iframe src=https://create.arduino.cc/editor/sunfounder01/e81b0024-c11e-4507-8d43-aeb3b6656c2c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


#. Remplacez le ``Template ID``, ``Device Name`` et ``Auth Token`` par les vôtres. Vous devez également entrer le ``ssid`` et le ``password`` du WiFi que vous utilisez. Pour des tutoriels détaillés, veuillez vous référer à :ref:`connect_blynk`.
#. Après avoir sélectionné la bonne carte et le bon port, cliquez sur le bouton **Upoad**.

#. Ouvrez le moniteur série (réglez le débit en bauds sur 115200) et attendez qu'un message tel qu'une connexion réussie apparaisse.

    .. image:: img/2_ready.png

    .. note::

        Si le message ``ESP is not responding`` apparaît lorsque vous vous connectez, veuillez suivre ces étapes.

        * Assurez-vous que la batterie 9V est branchée.
        * Réinitialisez le module ESP8266 en connectant la broche RST à GND pendant 1 seconde, puis débranchez-la.
        * Appuyez sur le bouton de réinitialisation de la carte R3.

        Parfois, il peut être nécessaire de répéter l'opération ci-dessus 3 à 5 fois, veuillez être patient.

#. Maintenant, Blynk affichera l'état de vos portes et fenêtres. Si vos portes et fenêtres sont fermées, le widget LED sera vert, sinon, il sera gris.

#. Si vous souhaitez utiliser Blynk sur des appareils mobiles, veuillez vous référer à :ref:`blynk_mobile`.



**Comment ça fonctionne ?**


Pour cet exemple, vous devriez vous concentrer sur les lignes suivantes. "Écrire des données toutes les secondes dans le Datastream V1 de Blynk Cloud" est défini par ces lignes.

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
        timer.run(); // Initiates BlynkTimer
    }

La bibliothèque Blynk fournit un timer intégré, d'abord nous créons un objet timer.

.. code-block:: arduino

    BlynkTimer timer;

Réglez l'intervalle du timer dans ``setup()``, ici nous réglons pour exécuter la fonction ``myTimerEvent()`` toutes les 1000ms

.. code-block:: arduino

    timer.setInterval(1000L, myTimerEvent);


Exécutez BlynkTimer dans ``loop()``.

.. code-block:: arduino

    timer.run();

Éditez la fonction personnalisée ``myTimerEvent()``, le code ``Blynk.virtualWrite(V1, pinValue)`` est utilisé pour écrire la donnée pinValue pour V1.

.. code-block:: arduino

    void myTimerEvent()
    {
        Blynk.virtualWrite(V1, pinValue);
    }

