.. note:: 

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions spéciales.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _car_remote_plus:

10. Démarrage à Une Touche
===========================

Dans ce projet, nous avons intégré les projets précédents - suivi de ligne, suivi, évitement d'obstacles, conduite autonome, etc. Ces modes peuvent être activés grâce aux boutons de la télécommande, permettant ainsi de démarrer la voiture et d'expérimenter toutes les fonctions en une seule fois.

**Câblage**

.. image:: img/car_10.png
    :width: 800

**Code**

.. note::

    * Ouvrez le fichier ``10.one_touch_start.ino`` situé dans le répertoire ``3in1-kit\car_project\10.one_touch_start``.
    * Ou copiez ce code dans **Arduino IDE**.
    * La bibliothèque ``IRremote`` est utilisée ici, vous pouvez l'installer depuis le **Gestionnaire de bibliothèques**.
  
        .. image:: ../img/lib_irremote.png
    

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/d873724f-120e-4679-b4ec-8d72ad583c8c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Après avoir téléversé le code avec succès, la LED clignotera rapidement 3 fois pour chaque signal reçu de la télécommande par le récepteur IR. Vous pouvez utiliser les touches suivantes pour contrôler la voiture :

* **+** : Accélérer
* **-** : Décélérer
* **1** : Aller vers l'avant gauche
* **2** : Avancer
* **3** : Aller vers l'avant droit
* **4** : Tourner à gauche
* **6** : Tourner à droite
* **7** : Reculer vers la gauche
* **8** : Reculer
* **9** : Reculer vers la droite
* **CYCLE** : Suivre la ligne
* **U/SD** : Conduite autonome
* **▷▷|** : Évitement d'obstacles avec le module ultrasonique
* **|◁◁** : Évitement d'obstacles avec le module IR
* **EQ** : Suivre votre main
* **0** : Arrêt
