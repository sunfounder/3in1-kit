.. _ar_interrupt:

5.13 Interruption
=================

Si vous utilisez des ``delay()`` dans un projet utilisant des capteurs, vous pourriez constater que lors du déclenchement de ces capteurs, le programme peut ne pas réagir.
Cela est dû au fait que l'instruction delay provoque la suspension du programme, et celui-ci ne pourra pas obtenir le signal envoyé par le capteur à la carte de contrôle principale.

Dans ce cas, on peut utiliser l'interruption. L'interruption permet au programme de ne pas manquer une impulsion.

Dans ce chapitre, nous utilisons un buzzer actif et des boutons pour expérimenter le processus d'utilisation de l'interruption.

Dans la fonction ``loop()``, ``delay(1000)`` est utilisé pour compter les secondes.
Placez le bouton pour contrôler le buzzer dans l'ISR, afin qu'il ne soit pas perturbé par le delay et qu'il puisse accomplir la tâche en douceur.

.. note::
    Les ISR sont des types spéciaux de fonctions qui ont certaines limitations uniques que la plupart des autres fonctions n'ont pas. Une ISR ne peut pas avoir de paramètres, et elles ne devraient rien retourner.
    Généralement, une ISR doit être aussi courte et rapide que possible. Si votre croquis utilise plusieurs ISR, une seule peut s'exécuter à la fois, les autres interruptions seront exécutées après la fin de la courante, dans un ordre qui dépend de la priorité qu'elles ont.

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
    *   - :ref:`cpn_button`
        - |link_button_buy|
    *   - :ref:`cpn_buzzer`
        - \-

**Schéma**

.. image:: img/circuit_8.6_interval.png

**Câblage**

.. image:: img/interrupt_bb.jpg
    :width: 600
    :align: center

**Code**

.. note::

    * Ouvrez le fichier ``5.13.interrupt.ino`` situé dans le dossier ``3in1-kit\basic_project\5.13.interrupt``.
    * Ou copiez ce code dans **Arduino IDE**.
    
    * Ou téléversez le code via l'`Éditeur Web Arduino <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/6111757d-dd63-4c4c-95b5-9d96fb0843f0/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Après le téléversement réussi du code, activez le moniteur série et vous verrez un nombre s'incrémentant automatiquement s'afficher chaque seconde. Si vous appuyez sur le bouton, le buzzer émettra un son.
La fonction du buzzer contrôlée par le bouton et la fonction de temporisation ne sont pas en conflit l'une avec l'autre.

**Comment ça fonctionne ?**

* ``attachInterrupt(digitalPinToInterrupt(pin), ISR, mode)`` : Ajouter une interruption.

    **Syntaxe**
        attachInterrupt(digitalPinToInterrupt(pin), ISR, mode) 

    **Paramètres**
        * ``pin`` : le numéro de pin Arduino. Vous devriez utiliser ``digitalPinToInterrupt(pin)`` pour convertir le pin numérique réel en un numéro d'interruption spécifique. Par exemple, si vous vous connectez au pin 3, utilisez son ``digitalPinToInterrupt(3)`` comme premier paramètre.
        * ``ISR`` : l'ISR à appeler lorsque l'interruption se produit ; cette fonction ne doit prendre aucun paramètre et ne rien retourner. Cette fonction est parfois appelée routine de service d'interruption.
        * ``mode`` : définit quand l'interruption doit être déclenchée. Quatre constantes sont prédéfinies comme valeurs valides :

          * ``LOW`` pour déclencher l'interruption lorsque le pin est bas,
          * ``CHANGE`` pour déclencher l'interruption chaque fois que la valeur du pin change.
          * ``RISING`` pour déclencher lorsque le pin passe de bas à haut.
          * ``FALLING`` pour quand le pin passe de haut à bas.

.. note:: 
    Différentes cartes de contrôle principales peuvent utiliser les pins d'interruption différemment. Sur la carte R3, seuls les pins 2 et 3 peuvent utiliser l'interruption.
