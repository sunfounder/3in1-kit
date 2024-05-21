.. note::

    Bonjour et bienvenue dans la Communauté Facebook des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez [|link_sf_facebook|] et rejoignez-nous aujourd'hui !

.. _sh_breathing_led:

2.2 LED Respiration
========================

Nous utilisons maintenant une autre méthode pour contrôler la luminosité de la LED. Contrairement au projet précédent, ici la luminosité de la LED diminue lentement jusqu'à disparaître.

Lorsque le sprite sur la scène est cliqué, la luminosité de la LED augmente lentement puis s'éteint instantanément.

.. image:: img/3_ap.png

Vous Apprendrez
--------------------------

- Régler la valeur de sortie de la broche PWM
- Créer des variables
- Changer la luminosité du sprite

Composants requis
--------------------------

Dans ce projet, nous avons besoin des composants suivants.

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

Vous pouvez également les acheter séparément à partir des liens ci-dessous.

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

Construisez le Circuit
------------------------

Ce projet utilise le même circuit que le projet précédent :ref:`sh_table_lamp`, mais au lieu d'utiliser HAUT/BAS pour allumer ou éteindre les LED, ce projet utilise le signal `PWM - Wikipedia <https://en.wikipedia.org/wiki/Pulse-width_modulation>`_ pour allumer ou atténuer lentement la LED.

La plage du signal PWM est de 0 à 255, sur la carte Arduno Uno, les broches 3, 5, 6, 9, 10, 11 peuvent émettre un signal PWM ; sur le Mega2560, les broches 2 à 13, 44 à 46 peuvent émettre un signal PWM.

.. image:: img/circuit/led_circuit.png

Programmation
------------------

**1. Sélectionner un sprite**

Supprimez le sprite par défaut, cliquez sur le bouton **Choose a Sprite** dans le coin inférieur droit de la zone de sprite, entrez **button3** dans la boîte de recherche, puis cliquez pour l'ajouter.

.. image:: img/3_sprite.png

**2. Création d'une variable**.

Créez une variable appelée **pwm** pour stocker la valeur du changement de pwm.

Cliquez sur la palette **Variables** et sélectionnez **Make a Variable**.

.. image:: img/3_ap_va.png

Entrez le nom de la variable, cela peut être n'importe quel nom, mais il est recommandé de décrire sa fonction. Le type de données est un nombre et pour tous les sprites.

.. image:: img/3_ap_pwm.png

Une fois créée, vous verrez **pwm** dans la palette **Variables** et dans l'état coché, ce qui signifie que cette variable apparaîtra sur la scène. Vous pouvez essayer de la décocher pour voir si pwm est toujours présent sur la scène.

.. image:: img/3_ap_0.png

**3. Définir l'état initial**

Lorsque le sprite **button3** est cliqué, changez le costume en **button-b** (état cliqué), et définissez la valeur initiale de la variable **pwm** à 0.

* [set pwm to 0] : de la palette **Variables**, utilisé pour définir la valeur de la variable.

.. image:: img/3_ap_brightness.png

**4. Rendre la LED de plus en plus lumineuse**

Comme la plage de pwm est de 255, alors par le bloc [repeat], la variable **pwm** est accumulée à 255 par 5, puis mise dans le bloc [set PWM pin], donc vous pouvez voir la LED s'allumer lentement.

* [change pwm by 5] : de la palette **Variables**, laissez la variable changer un nombre spécifique à chaque fois. Cela peut être un nombre positif ou négatif, positif signifie qu'il augmente chaque fois, négatif signifie qu'il diminue chaque fois, par exemple, ici la variable pwm est augmentée de 5 chaque fois.
* [set PWM pin] : de la palette **Arduino Uno**, utilisé pour régler la valeur de sortie de la broche pwm.

.. image:: img/3_ap_1.png

Enfin, changez le costume de button3 en **button-a** et mettez la valeur de la broche PWM à 0, afin que la LED s'allume lentement puis s'éteigne à nouveau.

.. image:: img/3_ap_2.png
