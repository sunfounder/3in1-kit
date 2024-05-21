.. note::

    Bonjour et bienvenue dans la Communauté Facebook des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez [|link_sf_facebook|] et rejoignez-nous aujourd'hui !

.. _sh_line:

3.3 Suivre la ligne
======================

La voiture est équipée d'un module de Suivi de Ligne, qui peut être utilisé pour faire suivre à la voiture une ligne noire.

Avant de commencer le projet, vous devez construire une carte de courbe avec du ruban de ligne noire, la largeur de ligne recommandée est entre 0,8-1,5 cm et l'angle du virage ne doit pas être inférieur à 90 degrés.

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
    *   - :ref:`cpn_track`
        - |link_track_buy|

Construire le Circuit
-----------------------

Il s'agit d'un module numérique de Suivi de Ligne, lorsqu'une ligne noire est détectée, il sort une valeur de 1 ; lorsqu'une ligne blanche est détectée, il sort une valeur de 0. De plus, vous pouvez ajuster sa distance de détection grâce au potentiomètre sur le module.

Construisez le circuit selon le schéma suivant.

.. list-table:: 

    * - Module de Suivi de Ligne
      - Carte R3
    * - S
      - 2
    * - V+
      - 5V
    * - G
      - GND

.. image:: img/car_4.png
    :width: 800

Ajuster le Module
-----------------------

Avant de commencer le projet, vous devez ajuster la sensibilité du module.

Câblez selon le schéma ci-dessus, puis alimentez la carte R3 (soit directement via le câble USB, soit via le câble de la pile bouton 9V), sans télécharger le code.

Collez un ruban électrique noir sur la table et placez la voiture dessus.

Observez la LED de signal sur le module pour vous assurer qu'elle s'allume sur la table blanche et s'éteint sur le ruban noir.

Si ce n'est pas le cas, vous devez ajuster le potentiomètre sur le module, afin qu'il puisse produire l'effet ci-dessus.

.. image:: img/line_track_cali.JPG


Programmation
----------------

Créez maintenant 2 blocs qui permettent à la voiture de se déplacer soit vers l'avant gauche, soit vers l'avant droit.

**1. Se déplacer vers l'avant gauche**

Lorsque le moteur droit tourne dans le sens des aiguilles d'une montre et que le moteur gauche reste immobile, la voiture se déplace légèrement vers l'avant gauche.

.. image:: img/3_forward_left.png

**2. Se déplacer vers l'avant droit**

De même, lorsque le moteur gauche tourne dans le sens inverse des aiguilles d'une montre et que le moteur droit ne bouge pas, la voiture se déplace légèrement vers la droite.

.. image:: img/3_forward_left.png

**3. Suivi de Ligne**

Lisez la valeur du module de Suivi de Ligne, si c'est 1, cela signifie qu'une ligne noire a été détectée, laissez la voiture se déplacer vers l'avant gauche, sinon avancez vers la droite.

.. image:: img/3_follow.png

Après avoir téléchargé le code sur la carte R3, alignez le module de Suivi de Ligne sous la voiture avec la ligne noire, et vous verrez la voiture suivre la ligne.
