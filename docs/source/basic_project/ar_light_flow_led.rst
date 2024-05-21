.. note::

    Bonjour et bienvenue dans la Communauté Facebook des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez [|link_sf_facebook|] et rejoignez-nous aujourd'hui !

6.1 Tableau Sensible à la Lumière
=================================

Un photo-résistor ou une cellule photoélectrique est une résistance variable contrôlée par la lumière. La résistance d'un photo-résistor diminue avec l'augmentation de l'intensité lumineuse incidente ; en d'autres termes, il présente une photoconductivité. Un photo-résistor peut être appliqué dans des circuits détecteurs sensibles à la lumière, et dans des circuits de commutation activés par la lumière et l'obscurité.

La résistance d'un photo-résistor change avec l'intensité lumineuse incidente. Si l'intensité lumineuse augmente, la résistance diminue ; si elle diminue, la résistance augmente.
Dans cette expérience, nous utiliserons huit LEDs pour montrer l'intensité lumineuse. Plus l'intensité lumineuse est élevée, plus de LEDs s'allumeront. Lorsque l'intensité lumineuse est suffisamment élevée, toutes les LEDs seront allumées. Lorsqu'il n'y a pas de lumière, toutes les LEDs s'éteindront.


**Composants requis**

Pour ce projet, nous aurons besoin des composants suivants.

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
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_buy|

**Schéma**

.. image:: img/circuit_6.1_light_led.png

**Câblage**

.. image:: img/light_control_led.png
    :width: 800
    :align: center


**Code**

.. note::

    * Ouvrez le fichier ``6.1.light_control_led.ino`` situé dans le dossier ``3in1-kit\basic_project\6.1.light_control_led``.
    * Ou copiez ce code dans **Arduino IDE**.
    
    * Ou téléversez le code via l'`Éditeur Web Arduino <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/859e1688-5801-400e-9409-f844ca9b7da7/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Maintenant, éclairez le photo-résistor, et vous verrez plusieurs LEDs s'allumer. Éclairez davantage et vous verrez plus de LEDs s'allumer. Quand vous le placez dans un environnement sombre, toutes les LEDs s'éteindront.

**Comment ça fonctionne ?**


.. code-block:: arduino

    void loop() 
    {
        sensorValue = analogRead(photocellPin); //read the value of A0
        ledLevel = map(sensorValue, 300, 1023, 0, NbrLEDs); // map to the number of LEDs
        for (int led = 0; led < NbrLEDs; led++)//
        {
            if (led < ledLevel ) //When led is smaller than ledLevel, run the following code. 
            {
                digitalWrite(ledPins[led], HIGH); // turn on pins less than the level
            }
            else 
            {
                digitalWrite(ledPins[led],LOW); // turn off pins higher than 
            }
        }
    }

En utilisant la fonction ``map()``, vous pouvez mapper la valeur du photo-résistor aux 8 LEDs, par exemple, si sensorValue est 560, alors ledLevel est 4, donc à ce moment, ledPins[0] à ledPins[4] devraient être allumés, et ledPins[5] à ledPins[7] devraient être éteints.

