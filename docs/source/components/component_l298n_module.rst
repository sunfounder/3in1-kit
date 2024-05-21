.. note::

    Bonjour et bienvenue dans la Communauté Facebook des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez [|link_sf_facebook|] et rejoignez-nous aujourd'hui !

.. _cpn_l298n:

Module L298N
==================================

Ce module de commande de moteur L298N est un module de commande de moteur de haute puissance pour la conduite de moteurs à courant continu et de moteurs pas à pas. Ce module se compose d'un circuit intégré de commande de moteur L298 et d'un régulateur 78M05 5V. Le module L298N peut contrôler jusqu'à 4 moteurs à courant continu ou 2 moteurs à courant continu avec contrôle de direction et de vitesse.

.. image:: img/l298n_pin.jpg
    :width: 400
    :align: center

* **IN1 & IN2** : Broches d'entrée du moteur A. Utilisées pour contrôler la direction de rotation du moteur A.
* **IN3 & IN4** : Broches d'entrée du moteur B. Utilisées pour contrôler la direction de rotation du moteur B.
* **ENA** : Active le signal PWM pour le moteur A. Ici, il a été connecté à 5V avec un cavalier.
* **ENB** : Active le signal PWM pour le moteur B. Ici, il a été connecté à 5V avec un cavalier.
* **OUT1 & OUT2** : Broches de sortie du moteur A.
* **OUT3 & OUT4** : Broches de sortie du moteur B.
* **12V** : Entrée 12V provenant d'une source d'alimentation DC.
* **5V** : Fournit de l'énergie pour la logique de commutation à l'intérieur du circuit intégré L298N.
* **GND** : Broche de masse.

**Caractéristiques**

* Modèle de pilote : L298N 2A.
* Puce de pilote : Double pont en H L298N.
* Tension d'alimentation du moteur (Maximum) : 46V.
* Courant d'alimentation du moteur (Maximum) : 2A.
* Tension logique : 5V.
* Tension de pilote : 5-35V.
* Courant de pilote : 2A.
* Courant logique : 0-36mA.
* Puissance maximale (W) : 25W.
* Détection de courant pour chaque moteur.
* Radiateur pour de meilleures performances.
* Indicateur LED de mise sous tension.

**Principe de Fonctionnement**

Le module de pilote peut commander deux moteurs. Les bornes activées ENA et ENB sont efficaces à niveau haut.

La relation de fonctionnement entre ENA et IN1, IN2 est la suivante :

.. list-table:: 
    :widths: 25 25 25 50
    :header-rows: 1

    * - ENA
      - IN1
      - IN2
      - État du moteur A
    * - 0
      - X
      - X
      - Arrêt
    * - 1
      - 0
      - 0
      - Frein
    * - 1
      - 0
      - 1
      - Rotation dans le sens des aiguilles d'une montre
    * - 1
      - 1
      - 0
      - Rotation dans le sens inverse des aiguilles d'une montre
    * - 1
      - 1
      - 1
      - Frein

La relation de fonctionnement entre ENB et IN3, IN4 est la suivante.

.. list-table:: 
    :widths: 25 25 25 50
    :header-rows: 1

    * - ENB
      - IN3
      - IN4
      - État du moteur B
    * - 0
      - X
      - X
      - Arrêt
    * - 1
      - 0
      - 0
      - Frein
    * - 1
      - 0
      - 1
      - Rotation dans le sens des aiguilles d'une montre
    * - 1
      - 1
      - 0
      - Rotation dans le sens inverse des aiguilles d'une montre
    * - 1
      - 1
      - 1
      - Frein

**À propos du Cavalier 5V**

Le module de commande de moteur L298N se compose d'un circuit intégré de commande de moteur L298, d'un régulateur de tension 78M05, de résistances, d'un condensateur, d'une LED d'alimentation, d'un cavalier 5V dans un circuit intégré.

.. image:: img/l298n_introduce.jpg
    :width: 500
    :align: center

Le régulateur de tension 78M05 sera activé uniquement lorsque le cavalier est placé. Lorsque l'alimentation est inférieure ou égale à 12V, alors le circuit interne sera alimenté par le régulateur de tension et la broche 5V peut être utilisée comme broche de sortie pour alimenter le microcontrôleur.

Le cavalier ne doit pas être placé lorsque l'alimentation est supérieure à 12V et une alimentation 5V séparée doit être fournie par la borne 5V pour alimenter le circuit interne.

* `Fiche technique L298N <https://www.yerical.com/product/L298N?product/XXXXX?source=adg&gclid=CjwKCAjwkYGVBhArEiwA4sZLuKEC19ydceKs396z1JENqjcbJDEvedRkcsza1aH_swhuNPWzL-CYfRoCMTMQAvD_BwE#g-pd-res>`_

**Exemple**

* :ref:`ar_motor` (Projet de base)
* :ref:`car_move` (Projet Voiture)
* :ref:`car_speed` (Projet Voiture)
* :ref:`iot_car` (Projet IoT)
* :ref:`sh_test` (Projet Scratch)

