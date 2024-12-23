.. note:: 

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez plus profondément dans Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprenez et partagez** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aperçus exclusifs.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et promotions de vacances.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _speed_calibration:

11. Calibration de la vitesse
================================

Lorsqu'il s'agit de faire avancer la voiture, vous pourriez constater qu'elle ne se déplace pas en ligne droite. 
Cela est dû au fait que les deux moteurs n'ont peut-être pas la même vitesse en usine. 
Cependant, nous pouvons ajuster un décalage sur les deux moteurs pour aligner leurs vitesses de rotation.

Dans ce projet, nous allons apprendre à stocker le décalage dans l'`EEPROM <https://docs.arduino.cc/learn/built-in-libraries/eeprom>`_. 
Cela permet qu'après chaque calibration, tous les projets puissent accéder directement à cette valeur de décalage dans l'EEPROM, pour 
que la voiture puisse avancer en ligne droite sans difficulté.


**Câblage**

Ce projet utilise le même câblage que celui du :ref:`car_move_code`.

**Comment jouer ?**

1. Ouvrez le fichier ``11.speed_calibration.ino`` dans le chemin ``3in1-kit\car_project\11.speed_calibration``. Ou copiez ce code dans **Arduino IDE**.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/66dc7ee5-31a5-418e-9aa2-43e7820cf5e6/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


2. Une fois le code téléchargé avec succès, connectez la voiture à une batterie 9V, posez-la sur le sol et laissez-la avancer pour voir de quel côté elle dévie.

* Si la voiture se déplace vers l'avant gauche, cela signifie que la vitesse du moteur droit est trop rapide et doit être réduite.

    .. code-block:: arduino

        EEPROM.write(1, 100) // 1 correspond au moteur droit, 100 signifie 100% de vitesse, cela peut être réglé à 90, 95, etc., en fonction de la situation réelle.

* Si la voiture se déplace vers la droite, cela signifie que la vitesse du moteur gauche est trop rapide et doit être réduite.

    .. code-block:: arduino

        EEPROM.write(0, 100) // 0 correspond au moteur gauche, 100 signifie 100% de vitesse, cela peut être réglé à 90, 95, etc., en fonction de la situation réelle.

3. Après avoir modifié le code, téléchargez-le à nouveau sur la carte R4 pour vérifier l'effet. Répétez les étapes ci-dessus jusqu'à ce que la voiture avance presque en ligne droite.

4. Ce décalage sera enregistré dans l'`EEPROM <https://docs.arduino.cc/learn/built-in-libraries/eeprom>`_. Vous n'aurez qu'à lire ce décalage lorsque vous l'utiliserez dans d'autres projets, comme dans :ref:`car_ir_obstacle`.

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

        // Moteurs
        pinMode(A_1B, OUTPUT);
        pinMode(A_1A, OUTPUT);
        pinMode(B_1B, OUTPUT);
        pinMode(B_1A, OUTPUT);

        // Obstacle IR
        pinMode(leftIR, INPUT);
        pinMode(rightIR, INPUT);

        leftOffset = EEPROM.read(0) * 0.01; // Lit le décalage du moteur gauche
        rightOffset = EEPROM.read(1) * 0.01; // Lit le décalage du moteur droit
    }

    void loop() {

        int left = digitalRead(leftIR);   // 0 : Obstrué, 1 : Libre
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

