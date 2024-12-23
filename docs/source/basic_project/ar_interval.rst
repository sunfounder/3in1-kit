.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et à des promotions festives.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _ar_interval:

5.4 Intervalle
================

Parfois, vous avez besoin d'effectuer deux tâches simultanément. Par exemple, vous 
pourriez vouloir faire clignoter une LED tout en surveillant l'appui d'un bouton. 
Dans ce cas, vous ne pouvez pas utiliser ``delay()``, car Arduino suspend votre 
programme pendant l'exécution de la fonction ``delay()``. Si le bouton est pressé 
pendant cette pause, votre programme manquera cet événement.

Une analogie serait de chauffer une pizza au micro-ondes tout en attendant un email 
important. Utiliser ``delay()`` serait comme rester devant le micro-ondes à regarder 
le compte à rebours des 10 minutes. Si l'email arrive pendant ce temps, vous le manquerez. 
En revanche, dans la vie réelle, vous allumeriez le micro-ondes et iriez vérifier vos 
emails de temps en temps, tout en revenant périodiquement voir si la pizza est prête.

Ce sketch montre comment jouer des notes avec un buzzer sans utiliser ``delay()``. 
Il allume le buzzer, note l'heure, puis, à chaque itération de la boucle, vérifie si 
l'intervalle de temps souhaité est écoulé. Si c'est le cas, il joue une note et enregistre 
le nouvel instant. Ainsi, le buzzer joue de façon continue sans interrompre l'exécution du 
programme.

Sur cette base, nous pouvons ajouter le code d'un bouton pour contrôler une LED, sans que 
cela n'interfère avec la musique jouée par le buzzer.

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
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|
    *   - :ref:`cpn_buzzer`
        - |link_passive_buzzer_buy|

**Schéma**

.. image:: img/circuit_8.5_interval.png

**Câblage**

.. image:: img/5.4_interval_bb.png
    :width: 600
    :align: center

.. note::

    * Ouvrez le fichier ``5.4.interval.ino`` dans le répertoire ``3in1-kit\learning_project\5.4.interval``.
    * Ou copiez ce code dans l'IDE Arduino.
    

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/0d430b04-ef2d-4e32-8d76-671a3a917cb1/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Après avoir téléchargé le code avec succès, le buzzer jouera une mélodie. Chaque fois que vous appuierez sur le bouton, la LED s'allumera. Le fonctionnement de la LED et du buzzer ne se perturbe pas mutuellement.

**Comment ça fonctionne ?**

Initialisez une variable nommée ``previousMillis`` pour stocker le temps d'opération précédent du microcontrôleur.

.. code-block:: arduino

    unsigned long previousMillis = 0;     

Indiquez quelle note est jouée.

.. code-block:: arduino

    int thisNote = 0; 

Définissez l'intervalle de temps pour chaque note.

.. code-block:: arduino

    long interval = 1000; 

Dans ``loop()``, déclarez ``currentMillis`` pour stocker le temps actuel.

.. code-block:: arduino

    unsigned long currentMillis = millis();

Lorsque l'intervalle entre le temps actuel et le dernier temps enregistré dépasse 1000 ms, certaines fonctions sont déclenchées. Mettez ensuite à jour ``previousMillis`` avec le temps actuel pour préparer le prochain déclenchement dans une seconde.

.. code-block:: arduino

    if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis; // sauvegarder le dernier temps
        //...
    }

Jouez les notes de la mélodie une par une.

.. code-block:: arduino

    tone(buzzerPin,melody[thisNote],100);
    interval=1000/noteDurations[thisNote]; // définir l'intervalle
    thisNote=(thisNote+1)%(sizeof(melody)/2); // parcourir les notes

Le bouton contrôle la LED.

.. code-block:: arduino

    // bouton & LED
    digitalWrite(ledPin,digitalRead(buttonPin));