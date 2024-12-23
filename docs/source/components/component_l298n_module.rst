.. note:: 

    Bonjour et bienvenue dans la communauté Facebook des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions spéciales.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_l298n:

Module L298N
==================================

Ce module de commande moteur L298N est un module puissant pour piloter des moteurs à courant continu et des moteurs pas à pas. Ce module se compose d’un circuit intégré de commande moteur L298 et d’un régulateur 5V 78M05. Le module L298N peut contrôler jusqu'à 4 moteurs à courant continu, ou 2 moteurs à courant continu avec commande de direction et de vitesse.

.. image:: img/l298n_pin.jpg
    :width: 400
    :align: center

* **IN1 & IN2** : Broches d'entrée du moteur A. Utilisées pour contrôler la direction de rotation du moteur A.
* **IN3 & IN4** : Broches d'entrée du moteur B. Utilisées pour contrôler la direction de rotation du moteur B.
* **ENA** : Active le signal PWM pour le moteur A. Connecté à 5V avec un cavalier.
* **ENB** : Active le signal PWM pour le moteur B. Connecté à 5V avec un cavalier.
* **OUT1 & OUT2** : Broches de sortie du moteur A.
* **OUT3 & OUT4** : Broches de sortie du moteur B.
* **12V** : Entrée 12V provenant d'une source d'alimentation CC.
* **5V** : Fournit l'alimentation pour la logique interne du circuit intégré L298N.
* **GND** : Broche de masse.

**Caractéristiques**

* Modèle de pilote : L298N 2A
* Puce pilote : Double pont en H L298N
* Tension d'alimentation moteur (maximum) : 46V
* Courant d'alimentation moteur (maximum) : 2A
* Tension logique : 5V
* Tension du pilote : 5-35V
* Courant du pilote : 2A
* Courant logique : 0-36mA
* Puissance maximale (W) : 25W
* Détection de courant pour chaque moteur
* Dissipateur thermique pour de meilleures performances
* Indicateur LED d'alimentation

**Principe de fonctionnement**

Le module de commande peut piloter deux moteurs. Les bornes d'activation ENA et ENB sont actives à un niveau haut. 

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
      - Rotation horaire
    * - 1
      - 1
      - 0
      - Rotation antihoraire
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
      - Rotation horaire
    * - 1
      - 1
      - 0
      - Rotation antihoraire
    * - 1
      - 1
      - 1
      - Frein


**À propos du cavalier d'activation 5V**

Le module de commande moteur L298N comprend un circuit intégré de commande moteur L298, un régulateur de tension 78M05, des résistances, un condensateur, une LED d'alimentation et un cavalier 5V intégrés.

.. image:: img/l298n_introduce.jpg
    :width: 500
    :align: center

Le régulateur de tension 78M05 sera activé uniquement si le cavalier est placé. Lorsque la tension d'alimentation est inférieure ou égale à 12V, le circuit interne sera alimenté par le régulateur de tension et la broche 5V peut être utilisée comme broche de sortie pour alimenter le microcontrôleur.

Le cavalier ne doit pas être placé si la tension d'alimentation est supérieure à 12V. Une alimentation 5V distincte doit être fournie via la borne 5V pour alimenter le circuit interne.

* `Fiche technique du L298N <https://www.yerical.com/product/L298N?product/XXXXX?source=adg&gclid=CjwKCAjwkYGVBhArEiwA4sZLuKEC19ydceKs396z1JENqjcbJDEvedRkcsza1aH_swhuNPWzL-CYfRoCMTMQAvD_BwE#g-pd-res>`_

**Exemple**

* :ref:`ar_motor` (Projet de base)
* :ref:`car_move` (Projet voiture)
* :ref:`car_speed` (Projet voiture)
* :ref:`iot_car` (Projet IoT)

.. * :ref:`sh_test` (Projet Scratch)
