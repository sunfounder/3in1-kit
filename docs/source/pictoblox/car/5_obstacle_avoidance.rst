.. note::

    Bonjour et bienvenue dans la Communauté Facebook des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez [|link_sf_facebook|] et rejoignez-nous aujourd'hui !

.. _sh_avoid1:

3.5 Évitement d'obstacles
==================================

Deux modules d'évitement d'obstacles infrarouges sont montés à l'avant de la voiture, pouvant détecter certains obstacles proches.

Dans ce projet, la voiture peut avancer librement, et lorsqu'elle rencontre un obstacle, elle est capable de l'éviter et de continuer à se déplacer dans d'autres directions.

Composants requis
---------------------

Pour ce projet, nous avons besoin des composants suivants.

Il est certainement pratique d'acheter un kit complet, voici le lien :

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nom	
        - ÉLÉMENTS DANS CE KIT
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
    *   - :ref:`cpn_l9110` 
        - \-
    *   - :ref:`cpn_tt_motor`
        - \-
    *   - :ref:`cpn_avoid` 
        - |link_obstacle_avoidance_buy|

Construire le Circuit
-----------------------

Le module d'évitement d'obstacles est un capteur de proximité infrarouge à distance ajustable dont la sortie est normalement haute et basse lorsqu'un obstacle est détecté.

Construisez le circuit selon le schéma ci-dessous.

.. list-table:: 

    * - Module IR Gauche
      - Carte R3
    * - OUT
      - 8
    * - GND
      - GND
    * - VCC
      - 5V

.. list-table:: 

    * - Module IR Droit
      - Carte R3
    * - OUT
      - 7
    * - GND
      - GND
    * - VCC
      - 5V

.. image:: img/car_5.png
    :width: 800

Ajuster le Module
-----------------------

Avant de commencer le projet, vous devez ajuster la distance de détection du module.

Câblez selon le schéma ci-dessus, alimentez la carte R3 (soit en branchant directement le câble USB, soit en clipsant le câble de la pile 9V), sans télécharger le code.

Placez un cahier ou tout autre objet plat à environ 5 cm devant le module d'évitement d'obstacles IR.

Ensuite, utilisez un tournevis pour tourner le potentiomètre sur le module jusqu'à ce que l'indicateur de signal sur le module s'allume juste, afin d'ajuster sa distance de détection maximale de 5 cm.

Suivez la même méthode pour ajuster un autre module infrarouge.

.. image:: img/ir_obs_cali.jpg

Programmation
---------------

L'effet que nous voulons atteindre.

* Lorsque le module IR gauche détecte un obstacle, la voiture recule vers la gauche
* Lorsque le module IR droit détecte un obstacle, la voiture recule vers la droite.
* Si les deux modules IR détectent l'obstacle, la voiture reculera directement.
* Sinon, la voiture avancera.

Créez maintenant les blocs correspondants.

**1. La voiture recule vers la gauche**

Lorsque le moteur droit tourne dans le sens inverse des aiguilles d'une montre et que le moteur gauche ne tourne pas, la voiture reculera vers la gauche.

.. image:: img/5_avoid1.png

**2. La voiture recule vers la droite**

Lorsque le moteur gauche tourne dans le sens des aiguilles d'une montre et que le moteur droit ne tourne pas, la voiture reculera vers la droite.

.. image:: img/5_avoid2.png

**3. La voiture avance, recule et s'arrête**

.. image:: img/5_avoid3.png

**4. Lire les valeurs des 2 modules IR**

Cliquez sur **Make a variable** dans la palette **Variables**.

.. image:: img/5_avoid4.png

Entrez le nom de la variable et cliquez sur **OK** pour créer une nouvelle variable.

.. image:: img/5_avoid5.png

Lisez les valeurs des modules d'évitement d'obstacles IR gauche et droit et stockez-les dans les 2 nouvelles variables.

.. image:: img/5_avoid6.png

**5. Évitement d'obstacles**

* Lorsque le module IR gauche est à 0 (obstacle détecté) et que le module IR droit est à 1, faites reculer la voiture vers la gauche.
* Lorsque le module IR droit est à 0 (obstacle détecté), faites reculer la voiture vers la droite.
* Si les 2 modules IR détectent l'obstacle en même temps, la voiture reculera.
* Sinon, la voiture continuera d'avancer.

.. image:: img/5_avoid7.png
