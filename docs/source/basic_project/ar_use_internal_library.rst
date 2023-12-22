.. _ar_servo:

5.5 Utiliser une Bibliothèque Interne
=======================================

Dans l'IDE Arduino, vous pouvez utiliser de nombreuses bibliothèques intégrées en ajoutant directement le fichier ``.h`` correspondant à votre code.

Ce projet utilise la bibliothèque ``Servo`` pour piloter le servomoteur, afin qu'il puisse pivoter entre 0° et 180°.

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_servo`
        - |link_servo_buy|


**Schéma**


.. image:: img/circuit_6.2_servo.png

Dans ce projet, nous utilisons la broche PWM 9 pour piloter le servomoteur, et connectons le fil orange du servomoteur à la broche PWM 9, le fil rouge à 5V et le fil marron à GND.

**Câblage**

.. image:: img/swinging_servo_bb.jpg

**Code**

.. note::

    * Ouvrez le fichier ``5.5.use_internal_library.ino`` sous le chemin ``3in1-kit\basic_project\5.5.use_internal_library``.
    * Ou copiez ce code dans **Arduino IDE**.
    
    * Ou téléchargez le code via l'`Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/fa27db71-b191-4eda-b5c7-bbbe5f2652ca/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Une fois que vous avez fini de télécharger les codes sur la carte R3, vous pouvez voir le bras du servo pivoter dans la plage de 0° à 180°.

**Comment ça fonctionne ?**

En appelant la bibliothèque ``Servo.h``, vous pouvez facilement piloter le servo. 

.. code-block:: arduino

    #include <Servo.h> 

Fonctions de la Bibliothèque : 

.. code-block:: arduino

    Servo

Créez un objet **Servo** pour contrôler un servo.

.. code-block:: arduino

    uint8_t attach(int pin); 

Appelez ``pinMode()`` pour transformer une broche en pilote de servo et retourner 0 en cas d'échec.

.. code-block:: arduino

    void detach();

Libérez une broche du pilotage de servo.

.. code-block:: arduino

    void write(int value); 

Réglez l'angle du servo en degrés, de 0 à 180.

.. code-block:: arduino

    int read();

Retourne la valeur définie avec le dernier ``write()``.

.. code-block:: arduino

    bool attached(); 

Retourne 1 si le servo est actuellement attaché.
