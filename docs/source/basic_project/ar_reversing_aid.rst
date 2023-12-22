.. _ar_reversing_aid:

6.4 Aide au Stationnement
=========================

Avec le développement de la science et de la technologie, de nombreux produits de haute technologie ont été installés dans les voitures, parmi lesquels le système d'aide au stationnement en marche arrière est l'un d'eux. Ici, nous utilisons un module ultrasonique, un LCD, des LED et un buzzer pour réaliser un système simple d'aide au stationnement ultrasonique.

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
    *   - :ref:`cpn_buzzer`
        - |link_passive_buzzer_buy|
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|

**Schéma**

.. image:: img/image265.png
    :width: 800
    :align: center

**Câblage**

.. image:: img/backcar.png
    :width: 800
    :align: center

**Code**

.. note::

    * Vous pouvez ouvrir le fichier ``6.4_reversingAid.ino`` sous le chemin de ``3in1-kit\basic_project\6.4_reversingAid`` directement.
    * Ou copiez ce code dans Arduino IDE .
    * La bibliothèque ``LiquidCrystal I2C`` est utilisée ici, vous pouvez l'installer depuis le **Library Manager**.

        .. image:: ../img/lib_liquidcrystal_i2c.png

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/d6848669-fe79-42e9-afd7-0f083f96a6d6/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Après le téléchargement réussi du code, la distance détectée actuelle sera affichée sur le LCD. Ensuite, le buzzer changera la fréquence de son en fonction des différentes distances.

.. note::
    Si le code et le câblage sont corrects, mais que le LCD n'affiche toujours pas de contenu, vous pouvez tourner le potentiomètre à l'arrière.

**Comment ça fonctionne ?**

Ce code nous aide à créer un dispositif simple de mesure de distance capable de mesurer la distance entre des objets et de fournir un retour via un affichage LCD et un buzzer.

La fonction ``loop()`` contient la logique principale du programme et s'exécute en continu. Examinons de plus près la fonction ``loop()``.

#. Boucle pour lire la distance et mettre à jour les paramètres

    Dans le ``loop``, le code lit d'abord la distance mesurée par le module ultrasonique et met à jour le paramètre d'intervalle en fonction de la distance.

    .. code-block:: arduino

        // Update the distance
        distance = readDistance();

        // Update intervals based on distance
        if (distance <= 10) {
            intervals = 300;
        } else if (distance <= 20) {
            intervals = 500;
        } else if (distance <= 50) {
            intervals = 1000;
        } else {
            intervals = 2000;
        }

#. Vérifier s'il est temps de biper

    Le code calcule la différence entre l'heure actuelle et l'heure du bip précédent, et si la différence est supérieure ou égale au temps d'intervalle, il déclenche le buzzer et met à jour l'heure du bip précédent.

    .. code-block:: arduino

        unsigned long currentMillis = millis();
        if (currentMillis - previousMillis >= intervals) {
            Serial.println("Beeping!");
            beep();
            previousMillis = currentMillis;
        }

#. Mettre à jour l'affichage LCD

    Le code efface l'affichage LCD puis affiche "Dis:" et la distance actuelle en centimètres sur la première ligne.

    .. code-block:: arduino

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Dis: ");
        lcd.print(distance);
        lcd.print(" cm");

        delay(100);