.. note::

    Bonjour et bienvenue dans la Communauté Facebook des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez [|link_sf_facebook|] et rejoignez-nous aujourd'hui !

.. _ar_blink:

1.1 Bonjour, LED ! 
=======================================

Tout comme écrire « Bonjour, monde ! » est la première étape pour apprendre à programmer, utiliser un programme pour contrôler une LED est l'introduction traditionnelle à l'apprentissage de la programmation physique.

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

**Schéma**

.. image:: img/circuit_1.1_led.png

Le principe de ce circuit est simple et la direction du courant est indiquée sur la figure. Lorsque la broche 9 émet un niveau haut (5V), la LED s'illuminera après la résistance limitatrice de courant de 220 ohms. Lorsque la broche 9 émet un niveau bas (0v), la LED s'éteindra.


**Câblage**

.. image:: img/wiring_led.png
    :width: 400
    :align: center

**Code**

.. note::

   * Vous pouvez ouvrir le fichier ``1.1.hello_led.ino`` dans le chemin ``3in1-kit\basic_project\1.1.hello_led``. 
   * Ou copiez ce code dans **Arduino IDE**.
   
   * Ou téléchargez le code via l'`Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.



.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/0497f915-5bf8-41a2-8e0f-b013130a57f5/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Après le téléchargement réussi du code, vous verrez la LED clignoter.

**Comment ça fonctionne ?**

Ici, nous connectons la LED à la broche numérique 9, nous devons donc déclarer une variable int appelée ledpin au début du programme et lui attribuer une valeur de 9.

.. code-block:: arduino

    const int ledPin = 9;


Maintenant, initialisez la broche dans la fonction ``setup()``, où vous devez configurer la broche en mode ``OUTPUT``.

.. code-block:: arduino

    void setup() {
        pinMode(ledPin, OUTPUT);
    }

Dans ``loop()``, ``digitalWrite()`` est utilisé pour fournir un signal de niveau haut de 5V pour ledpin, ce qui provoquera une différence de tension entre les broches de la LED et allumera la LED.

.. code-block:: arduino

    digitalWrite(ledPin, HIGH);

Si le signal de niveau est changé en LOW, le signal de ledPin sera ramené à 0 V pour éteindre la LED.

.. code-block:: arduino

    digitalWrite(ledPin, LOW);


Un intervalle entre allumé et éteint est nécessaire pour permettre aux gens de voir le changement, 
donc nous utilisons un code ``delay(1000)`` pour laisser le contrôleur ne rien faire pendant 1000 ms.

.. code-block:: arduino

    delay(1000);   
