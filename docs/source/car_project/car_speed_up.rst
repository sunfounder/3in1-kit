.. note:: 

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez plus profondément dans Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprenez et partagez** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aperçus exclusifs.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et promotions de vacances.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _car_speed:

3. Augmenter la vitesse
===========================

En plus des signaux numériques (HIGH/LOW), l'entrée du module L9110 peut également recevoir des signaux PWM pour contrôler la vitesse de sortie.

En d'autres termes, nous pouvons utiliser ``AnalogWrite()`` pour contrôler la vitesse de déplacement de la voiture.

Dans ce projet, nous faisons varier progressivement la vitesse de la voiture vers l'avant, en accélérant d'abord, puis en décélérant.


**Câblage**

Ce projet utilise le même câblage que celui du :ref:`car_move_code`.

**Code**

.. note::

    * Ouvrez le fichier ``3.speed_up.ino`` dans le chemin ``3in1-kit\car_project\3.speed_up``.
    * Ou copiez ce code dans **Arduino IDE**.
    
    * Ou téléchargez le code via l'`Éditeur Web Arduino <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/c15276c1-2359-4de6-ac82-a14a72e041c6/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Une fois le programme lancé, la voiture accélérera progressivement, puis ralentira progressivement.

**Comment cela fonctionne-t-il ?**

Le but de ce projet est d'écrire différentes valeurs PWM sur les broches d'entrée du module L9110 pour contrôler la vitesse d'avancement de la voiture.

#. Utilisez l'instruction ``for()`` pour définir ``speed`` par pas de 5, en écrivant des valeurs de 0 à 255 afin que vous puissiez observer le changement de vitesse de la voiture.

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

    Contrairement au :ref:`car_move_code`, qui attribue directement des niveaux haut/bas aux broches d'entrée du module L9110, ici nous passons un paramètre ``speed`` aux endroits où nous devons attribuer des niveaux hauts.

    .. code-block:: arduino

        void moveForward(int speed) {
            analogWrite(A_1B, 0);
            analogWrite(A_1A, speed);
            analogWrite(B_1B, speed);
            analogWrite(B_1A, 0);
        }

* `for <https://www.arduino.cc/reference/en/language/structure/control-structure/for/>`_

L'instruction ``for`` est utilisée pour répéter un bloc d'instructions entouré d'accolades. Un compteur d'incrément est généralement utilisé pour incrémenter et terminer la boucle.

    .. code-block:: arduino

        for (initialization; condition; increment) {
        // instruction(s);
        }

    * ``initialization`` : s'exécute une fois au début.
    * ``condition`` : à chaque passage dans la boucle, la condition est testée ; si elle est vraie, le bloc d'instructions est exécuté, suivi de l'incrémentation, puis la condition est testée à nouveau. Lorsque la condition devient fausse, la boucle se termine.
    * ``increment`` : s'exécute à chaque passage dans la boucle lorsque la condition est vraie.
