.. note::

    Bonjour et bienvenue dans la Communauté Facebook des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez [|link_sf_facebook|] et rejoignez-nous aujourd'hui !

.. _ar_interval:

5.4 Intervalle
================

Parfois, vous avez besoin de faire deux choses en même temps. Par exemple, vous pourriez vouloir faire clignoter une LED tout en lisant un appui sur un bouton. Dans ce cas, vous ne pouvez pas utiliser ``delay()``, car Arduino met votre programme en pause pendant le ``delay()``. Si le bouton est pressé pendant qu'Arduino est en pause en attendant que le ``delay()`` se termine, votre programme manquera l'appui sur le bouton.

Une analogie serait de réchauffer une pizza dans votre micro-ondes tout en attendant un email important. Vous mettez la pizza dans le micro-ondes et réglez le temps sur 10 minutes. L'analogie à l'utilisation de ``delay()`` serait de s'asseoir devant le micro-ondes en regardant le minuteur décompter de 10 minutes jusqu'à ce que le minuteur atteigne zéro. Si l'email important arrive pendant ce temps, vous le manquerez.

Ce que vous feriez dans la vraie vie serait de mettre en marche la pizza, puis de vérifier vos emails, puis peut-être de faire quelque chose d'autre (qui ne prend pas trop de temps !) et de temps en temps, vous reviendriez au micro-ondes pour voir si le minuteur a atteint zéro, indiquant que votre pizza est prête.

Ce sketch démontre comment faire sonner un buzzer sans utiliser ``delay()``. 
Il active le buzzer puis prend note de l'heure. Ensuite, à chaque passage dans ``loop()``, il vérifie si le temps d'intervalle souhaité s'est écoulé.
Si c'est le cas, il fait sonner le buzzer et prend note du nouveau temps.
De cette manière, le buzzer sonne continuellement tandis que l'exécution du sketch ne s'attarde jamais sur une seule instruction.

Sur la base de cette condition, nous pouvons ajouter le code du bouton pour contrôler la LED, 
il ne sera pas perturbé par le buzzer jouant de la musique.

**Composants requis**

Pour ce projet, nous avons besoin des composants suivants.

Il est certainement pratique d'acheter un kit complet, voici le lien :

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nom	
        - ÉLÉMENTS DE CE KIT
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

.. image:: img/interval_bb.jpg
    :width: 600
    :align: center

**Code**

.. note::

    * Ouvrez le fichier ``5.4.interval.ino`` sous le chemin ``3in1-kit\basic_project\5.4.interval``.
    * Ou copiez ce code dans **Arduino IDE**.
    
    * Ou téléchargez le code via l'`Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/0d430b04-ef2d-4e32-8d76-671a3a917cb1/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Après le téléchargement réussi du code, le buzzer jouera de la musique ; chaque fois que vous appuyez sur le bouton, la LED s'allumera. Le travail de la LED et du buzzer ne se gêne pas l'un l'autre.

**Comment ça fonctionne ?**


Initialisez une variable nommée ``previousMillis`` pour stocker le temps de fonctionnement précédent du microcontrôleur.

.. code-block:: arduino

    unsigned long previousMillis = 0;     

Marquez quelle note est jouée.

.. code-block:: arduino

    int thisNote=0; 

Le temps d'intervalle de chaque note.

.. code-block:: arduino

    long interval = 1000; 

Dans ``loop()``, déclarez ``currentMillis`` pour stocker le temps actuel.

.. code-block:: arduino

    unsigned long currentMillis = millis();

Lorsque l'intervalle entre le temps de fonctionnement actuel et le dernier temps de mise à jour est supérieur à 1000ms, certaines fonctions sont déclenchées. En même temps, mettez à jour le previousMillis au temps actuel pour le prochain déclenchement qui doit se produire 1 seconde plus tard.

.. code-block:: arduino

    if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;// save the last time of the last tone
        //...
    }

Jouez les notes de la mélodie une par une.

.. code-block:: arduino

    tone(buzzerPin,melody[thisNote],100);
    interval=1000/noteDurations[thisNote]; // interval at which to tone
    thisNote=(thisNote+1)%(sizeof(melody)/2); //iterate over the notes of the melody

Le bouton contrôle la LED.

.. code-block:: arduino

  // play button & led 
  digitalWrite(ledPin,digitalRead(buttonPin));
