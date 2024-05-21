.. note::

    Bonjour et bienvenue dans la Communauté Facebook des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez [|link_sf_facebook|] et rejoignez-nous aujourd'hui !

.. _speed_calibration:

11. Calibration de la Vitesse
=================================

Lors de la mise en mouvement de la voiture, vous pourriez constater que la voiture ne se déplace pas en ligne droite.
Cela est dû au fait que les deux moteurs peuvent ne pas avoir la même vitesse en sortie d'usine. 
Mais nous pouvons écrire un décalage aux deux moteurs pour faire converger leurs vitesses de rotation.

Dans ce projet, 
nous apprendrons à stocker le décalage dans `EEPROM <https://docs.arduino.cc/learn/built-in-libraries/eeprom>`_. L'intérêt est que, après chaque calibration, 
tous les projets peuvent obtenir directement la valeur de décalage depuis l'EEPROM, 
afin que la voiture puisse avancer en ligne droite de manière fluide.


**Câblage**

Ce projet a le même câblage que :ref:`car_move_code`.



**Comment jouer ?**

1. Ouvrez le fichier ``11.speed_calibration.ino`` situé dans le dossier ``3in1-kit\car_project\11.speed_calibration``. Ou copiez ce code dans **Arduino IDE**.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/66dc7ee5-31a5-418e-9aa2-43e7820cf5e6/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


2. Après le téléchargement réussi du code, connectez la voiture avec une batterie 9V, posez-la sur le sol et laissez-la avancer pour voir de quel côté elle se décale.

* Si la voiture se déplace vers l'avant gauche, cela signifie que la vitesse du moteur droit est trop rapide et doit être réduite.

    .. code-block:: arduino

        EEPROM.write(1, 100) // 1 means the right motor, 100 means 100% speed, can be set to 90, 95, etc., depending on the actual situation.

* Si la voiture se déplace vers la droite, cela signifie que la vitesse du moteur gauche est trop rapide et doit être réduite.

    .. code-block:: arduino

        EEPROM.write(0, 100) // 0 means the right motor, 100 means the speed is 100%, can be set to 90, 95, etc., depending on the actual situation. 3.

3. Après avoir modifié le code, téléchargez le code sur la carte R3 pour voir l'effet. Répétez les étapes ci-dessus jusqu'à ce que la voiture soit presque droite.

4. Ce décalage sera enregistré dans `EEPROM <https://docs.arduino.cc/learn/built-in-libraries/eeprom>`_, vous n'avez besoin de lire ce décalage que lorsque vous l'utilisez dans d'autres projets, prenez :ref:`car_ir_obstacle` comme exemple.


.. code-block:: arduino
    :emphasize-lines: 1,3,4,27,28,50,51

    #include <EEPROM.h>

    float leftOffset = 1.0;
    float rightOffset = 1.0;

    const int A_1B = 5;
    const int A_1A = 6;
    const int B_1B = 9;
    const int B_1A = 10;

    const int rightIR = 7;
    const int leftIR = 8;

    void setup() {
        Serial.begin(9600);

        //motor
        pinMode(A_1B, OUTPUT);
        pinMode(A_1A, OUTPUT);
        pinMode(B_1B, OUTPUT);
        pinMode(B_1A, OUTPUT);

        //IR obstacle
        pinMode(leftIR, INPUT);
        pinMode(rightIR, INPUT);

        leftOffset = EEPROM.read(0) * 0.01;//read the offset of the left motor
        rightOffset = EEPROM.read(1) * 0.01;//read the offset of the right motor
    }

    void loop() {

        int left = digitalRead(leftIR);   // 0: Obstructed  1: Empty
        int right = digitalRead(rightIR);
        int speed = 150;

        if (!left && right) {
            backLeft(speed);
        } else if (left && !right) {
            backRight(speed);
        } else if (!left && !right) {
            moveBackward(speed);
        } else {
            moveForward(speed);
        }
    }

    void moveForward(int speed) {
        analogWrite(A_1B, 0);
        analogWrite(A_1A, int(speed * leftOffset));
        analogWrite(B_1B, int(speed * rightOffset));
        analogWrite(B_1A, 0);
    }

    void moveBackward(int speed) {
        analogWrite(A_1B, speed);
        analogWrite(A_1A, 0);
        analogWrite(B_1B, 0);
        analogWrite(B_1A, speed);
    }

    void backLeft(int speed) {
        analogWrite(A_1B, speed);
        analogWrite(A_1A, 0);
        analogWrite(B_1B, 0);
        analogWrite(B_1A, 0);
    }

    void backRight(int speed) {
        analogWrite(A_1B, 0);
        analogWrite(A_1A, 0);
        analogWrite(B_1B, 0);
        analogWrite(B_1A, speed);
    }

