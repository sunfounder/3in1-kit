.. _car_speed:

3. Accélération
===============

En plus du signal numérique (HIGH/LOW), l'entrée du module L9110 peut également recevoir un signal PWM pour contrôler la vitesse de sortie.

En d'autres termes, nous pouvons utiliser ``AnalogWrite()`` pour contrôler la vitesse de déplacement de la voiture.

Dans ce projet, nous faisons varier progressivement la vitesse de la voiture vers l'avant, en accélérant d'abord puis en décélérant.


**Câblage**

Ce projet utilise le même câblage que :ref:`car_move_code`.

**Code**

.. note::

    * Ouvrez le fichier ``3.speed_up.ino`` dans le chemin ``3in1-kit\car_project\3.speed_up``.
    * Ou copiez ce code dans **Arduino IDE**.
    
    * Ou téléchargez le code via le `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/c15276c1-2359-4de6-ac82-a14a72e041c6/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Après l'exécution du programme, la voiture accélérera progressivement puis décélérera graduellement.

**Comment ça fonctionne ?**

Le but de ce projet est d'écrire différentes valeurs PWM aux broches d'entrée du module L9110 pour contrôler la vitesse avant de la voiture.


#. Utilisez la déclaration ``for()`` pour donner ``speed`` par paliers de 5, en écrivant des valeurs de 0 à 255 afin de voir le changement de vitesse de la voiture.

    .. code-block:: arduino

        void loop() {
            for(int i=0;i<=255;i+=5){
                moveForward(i);
                delay(500);
            }
            for(int i=255;i>=0;i-=5){
                moveForward(i);
                delay(500);
            }
        }

#. À propos de la fonction ``moveForward()``.

    Contrairement à :ref:`car_move_code` qui donne directement des niveaux hauts/bas aux broches d'entrée du module L9110, ici nous passons un paramètre ``speed`` là où nous devons donner des niveaux hauts.

    .. code-block:: arduino

        void moveForward(int speed) {
            analogWrite(A_1B, 0);
            analogWrite(A_1A, speed);
            analogWrite(B_1B, speed);
            analogWrite(B_1A, 0);
        }


* `for <https://www.arduino.cc/reference/en/language/structure/control-structure/for/>`_

La déclaration ``for`` est utilisée pour répéter un bloc d'instructions entre accolades. Un compteur d'incrémentation est généralement utilisé pour incrémenter et terminer la boucle.

    .. code-block:: arduino

        for (initialization; condition; increment) {
        // statement(s);
        }

    * ``initialization`` : se produit d'abord et une seule fois.
    * ``condition`` : à chaque passage dans la boucle, la condition est testée ; si elle est vraie, le bloc d'instructions et l'incrémentation sont exécutés, puis la condition est à nouveau testée. Lorsque la condition devient fausse, la boucle se termine.
    * ``increment`` : exécuté à chaque passage dans la boucle lorsque la condition est vraie.
