.. note::

    Bonjour et bienvenue dans la Communauté Facebook des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez [|link_sf_facebook|] et rejoignez-nous aujourd'hui !

.. _car_remote_plus:

10. Démarrage en Un Clic
=============================

Dans ce projet, nous avons intégré les projets précédents - suivi de ligne, suivi, évitement d'obstacles, conduite autonome, etc. Ils peuvent être changés par les boutons de la télécommande, vous permettant ainsi de démarrer la voiture et d'expérimenter toutes les fonctions en une seule fois.

**Câblage**

.. image:: img/car_10.png
    :width: 800

**Code**

.. note::

    * Ouvrez le fichier ``10.one_touch_start.ino`` situé dans le dossier ``3in1-kit\car_project\10.one_touch_start``.
    * Ou copiez ce code dans **Arduino IDE**.
    * La bibliothèque ``IRremote`` est utilisée ici, vous pouvez l'installer depuis le **Library Manager**.
  
        .. image:: ../img/lib_irremote.png
    

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/d873724f-120e-4679-b4ec-8d72ad583c8c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Après le téléchargement réussi du code, la LED clignotera rapidement 3 fois pour chaque signal reçu de la télécommande par le récepteur IR. Vous pouvez appuyer sur les touches suivantes pour faire fonctionner le chariot.

* **+** : Accélérer
* **-** : Ralentir
* **1** : Avancer vers la gauche
* **2** : Avancer
* **3** : Avancer vers la droite.
* **4** : Tourner à gauche
* **6** : Tourner à droite
* **7** : Reculer vers la gauche
* **8** : Reculer.
* **9** : Reculer vers la droite
* **CYCLE** : Suivre la ligne
* **U/SD** : Conduite autonome
* **▷▷|** : Évitement d'obstacles avec module ultrasonique
* **|◁◁** : Évitement d'obstacles avec module IR Obstacle
* **EQ** : Suivre votre main
* **0** : Arrêter



