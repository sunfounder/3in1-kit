.. note:: 

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez plus profondément dans Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprenez et partagez** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aperçus exclusifs.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et promotions de vacances.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _ar_blink:

1.1 Bonjour, LED ! 
==============================

Allumer une LED à l’aide d’un programme est une introduction classique à la programmation physique, tout comme afficher « Bonjour, monde ! » est la première étape pour apprendre la programmation.

**Composants nécessaires**

Dans ce projet, nous aurons besoin des composants suivants. 

Il est très pratique d'acheter un kit complet, voici le lien : 

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nom
        - ARTICLES DANS CE KIT
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
        - \-
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

Le principe de ce circuit est simple et le sens du courant est indiqué sur le schéma. Lorsque la broche 9 fournit un signal haut (5V), la LED s’allume via la résistance limitant le courant de 1 kohm. Lorsque la broche 9 fournit un signal bas (0V), la LED s’éteint.

**Câblage**

.. image:: img/1.1_hello_led_bb.png
    :width: 600
    :align: center

**Code**

.. note::

   * Vous pouvez ouvrir le fichier ``1.1.hello_led.ino`` sous le chemin ``3in1-kit\learning_project\1.1.hello_led``.
   * Ou copiez ce code dans **Arduino IDE**.
   
.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/0497f915-5bf8-41a2-8e0f-b013130a57f5/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Après le téléchargement réussi du code, vous verrez la LED clignoter.

**Comment ça fonctionne ?**

Ici, nous connectons la LED à la broche numérique 9, nous devons donc déclarer une variable entière appelée ``ledPin`` au début du programme et lui attribuer la valeur 9.

.. code-block:: arduino

    const int ledPin = 9;

Ensuite, initialisez la broche dans la fonction ``setup()``, où vous devez définir la broche en mode ``OUTPUT``.

.. code-block:: arduino

    void setup() {
        pinMode(ledPin, OUTPUT);
    }

Dans la fonction ``loop()``, utilisez ``digitalWrite()`` pour fournir un signal haut de 5V à ``ledPin``, ce qui créera une différence de tension entre les broches de la LED et allumera la LED.

.. code-block:: arduino

    digitalWrite(ledPin, HIGH);

Si le signal est modifié à LOW, le signal de ``ledPin`` revient à 0V, ce qui éteindra la LED.

.. code-block:: arduino

    digitalWrite(ledPin, LOW);

Un intervalle entre l'allumage et l'extinction est nécessaire pour permettre de voir 
le changement. Nous utilisons donc ``delay(1000)`` pour que le contrôleur reste inactif 
pendant 1000 ms.

.. code-block:: arduino

    delay(1000);