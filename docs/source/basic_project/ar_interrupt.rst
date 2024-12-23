.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et à des promotions festives.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _ar_interrupt:

5.13 Interruption
=======================

Si vous utilisez des ``delay()`` dans un projet avec des capteurs, vous remarquerez peut-être que lorsque vous déclenchez ces capteurs, le programme ne réagit pas. 
Cela est dû au fait que l'instruction ``delay`` suspend l'exécution du programme, empêchant ce dernier de recevoir les signaux envoyés par les capteurs à la carte de contrôle.

Dans ce cas, vous pouvez utiliser des interruptions. Les interruptions permettent au programme de ne pas manquer une impulsion.

Dans ce chapitre, nous utilisons un buzzer actif et des boutons pour expérimenter l'utilisation des interruptions.

Dans la fonction ``loop()``, ``delay(1000)`` est utilisé pour compter les secondes. Le bouton qui contrôle le buzzer est placé dans l'ISR, de manière à ne pas être perturbé par le délai et à accomplir sa tâche sans problème.

.. note::
    Les ISR (Interrupt Service Routines) sont des fonctions spéciales ayant des limitations uniques. Un ISR ne peut pas prendre de paramètres et ne doit rien renvoyer. 
    En général, un ISR doit être aussi court et rapide que possible. Si votre sketch utilise plusieurs ISR, un seul peut être exécuté à la fois. Les autres interruptions seront exécutées après que l'interruption actuelle soit terminée, dans un ordre dépendant de leur priorité.

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
    *   - :ref:`cpn_button`
        - |link_button_buy|
    *   - :ref:`cpn_buzzer`
        - \-

**Schéma**

.. image:: img/circuit_8.6_interval.png

**Câblage**

.. image:: img/5.13_interrupt_bb.png
    :width: 600
    :align: center

**Code**

.. note::

    * Ouvrez le fichier ``5.13.interrupt.ino`` dans le répertoire ``3in1-kit\learning_project\5.13.interrupt``.
    * Ou copiez ce code dans l'IDE Arduino.
    

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/6111757d-dd63-4c4c-95b5-9d96fb0843f0/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Après avoir téléchargé le code avec succès, ouvrez le moniteur série et vous verrez un 
nombre auto-incrémenté imprimé toutes les secondes. Si vous appuyez sur le bouton, le 
buzzer émet un son. La fonction de minuterie et la fonction du buzzer contrôlé par le 
bouton ne se perturbent pas.

**Comment ça fonctionne ?**

* ``attachInterrupt(digitalPinToInterrupt(pin), ISR, mode)`` : Ajoute une interruption.

    **Syntaxe**
        attachInterrupt(digitalPinToInterrupt(pin), ISR, mode) 

    **Paramètres**
        * ``pin`` : le numéro du pin Arduino. Utilisez ``digitalPinToInterrupt(pin)`` pour convertir le numéro du pin en numéro d'interruption spécifique. Par exemple, si vous connectez au pin 3, utilisez ``digitalPinToInterrupt(3)`` comme premier paramètre.
        * ``ISR`` : l'ISR à appeler lorsque l'interruption se produit ; cette fonction ne doit pas prendre de paramètres ni renvoyer quoi que ce soit. Elle est parfois appelée routine de service d'interruption.
        * ``mode`` : définit quand l'interruption doit être déclenchée. Quatre constantes sont prédéfinies comme valeurs valides :

          * ``LOW`` pour déclencher l'interruption lorsque le pin est bas,
          * ``CHANGE`` pour déclencher l'interruption lorsque la valeur du pin change,
          * ``RISING`` pour déclencher lorsque le pin passe de bas à haut,
          * ``FALLING`` pour lorsque le pin passe de haut à bas.

.. note:: 
    Les différents microcontrôleurs utilisent les pins d'interruption différemment. Sur votre carte, seuls les pins 2 et 3 peuvent utiliser les interruptions.
