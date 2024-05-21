.. note::

    Bonjour et bienvenue dans la Communauté Facebook des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez [|link_sf_facebook|] et rejoignez-nous aujourd'hui !

.. _sh_test:

3.1 Tester la Voiture
======================

Ici, vous apprendrez à écrire des scripts pour faire avancer la voiture, mais vous devez vous référer à :ref:`car_projects` pour assembler la voiture et pour obtenir une compréhension de base de celle-ci.

Mais avant de commencer le projet, vous devez connaître les étapes pour utiliser PictoBlox en :ref:`upload_mode`.

Composants Requis
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

Construire le Circuit
-----------------------

Le module de pilote de moteur L9110 est un module de pilote de moteur haute puissance pour entraîner des moteurs DC et pas à pas. Le module L9110 peut contrôler jusqu'à 4 moteurs DC, ou 2 moteurs DC avec contrôle de direction et de vitesse.


Connectez les fils entre le module L9110 et la carte R3 selon le schéma ci-dessous.


.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - Module L9110
      - Carte R3
      - Moteur
    * - A-1B
      - 5
      - 
    * - A-1A
      - 6
      - 
    * - B-1B(B-2A)
      - 9
      - 
    * - B-1A
      - 10
      - 
    * - OB(B)
      - 
      - Fil noir du moteur droit
    * - OA(B)
      - 
      - Fil rouge du moteur droit
    * - OB(A)
      - 
      - Fil noir du moteur gauche
    * - OA(A)
      - 
      - Fil rouge du moteur gauche

.. image:: img/car_2.png
    :width: 800

Programmation
-------------------

**1. Faire avancer la voiture**

Sur la base du câblage ci-dessus, nous savons que les broches 5 et 6 sont utilisées pour contrôler la rotation du moteur droit et les broches 9 et 10 pour celle du moteur gauche. Écrivons maintenant un script pour faire avancer la voiture.

Après avoir sélectionné la carte Arduino Uno, passez en :ref:`upload_mode` et écrivez le script selon le schéma suivant.

.. image:: img/1_test1.png

Cliquez sur le bouton **Upload Code** pour uploader le code sur la carte R3. Une fois terminé, vous verrez les deux moteurs de la voiture avancer (si vous posez la voiture sur le sol, elle avancera en ligne droite, mais peut-être la voiture ira en courbe car la vitesse des deux moteurs est un peu différente).

Si les deux ne tournent pas en avant, mais que les situations suivantes se produisent, vous devez réajuster le câblage des deux moteurs.

* Si les deux moteurs tournent en arrière en même temps (le moteur gauche tourne dans le sens des aiguilles d'une montre, le moteur droit tourne dans le sens inverse), inversez le câblage des moteurs gauche et droit en même temps, OA(A) et OB(A) échangent, OA(B) et OB(B) échangent.
* Si le moteur gauche tourne en arrière (rotation dans le sens des aiguilles d'une montre), échangez le câblage de OA(B) et OB(B) du moteur gauche.
* Si le moteur droit tourne en arrière (rotation dans le sens inverse des aiguilles d'une montre), inversez le câblage de OA(A) et OB(A) du moteur droit.


**2. Création d'un bloc**

Pour rendre le script plus propre et facile à utiliser, plaçons ici tous les blocs qui contrôlent le mouvement en avant dans un bloc, et lors de son utilisation, appelez directement ce bloc.

Cliquez sur **Make a Block** dans la palette **My Blocks**.

.. image:: img/1_test31.png

Entrez le nom du bloc - **forward** et cochez **Add an input**, définissez le nom de l'entrée sur **speed**.

.. image:: img/1_test32.png

Glissez-déposez les blocs qui contrôlent l'avancement des voitures dans **forward**, notez que vous devez ajouter le paramètre - **speed** aux broches 6 et 9.

.. image:: img/1_test33.png

Appelez le bloc créé dans le bloc [Forward] - **forward**. En mode Téléversement, le bloc [When Arduino Uno starts up] doit être ajouté au début.

* La plage de vitesse de rotation du moteur est de 100 à 255.

.. image:: img/1_test3.png
    
**3. Ajuster la vitesse des moteurs**

Comme il peut y avoir une légère différence dans la vitesse des 2 moteurs, entraînant la voiture à ne pas avancer en ligne droite, nous pouvons donner aux moteurs gauche et droit des vitesses différentes pour garder la voiture avançant le plus possible en ligne droite.

Comme ma voiture avance lentement vers la droite, réduisez ici la vitesse du moteur gauche.

.. image:: img/1_test2.png





