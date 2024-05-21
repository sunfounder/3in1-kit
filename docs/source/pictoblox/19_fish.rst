.. note::

    Bonjour et bienvenue dans la Communauté Facebook des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez [|link_sf_facebook|] et rejoignez-nous aujourd'hui !

.. _sh_fishing:

2.19 JEU - Pêche
===========================

Ici, nous jouons à un jeu de pêche avec un bouton.

Lorsque le script est en cours d'exécution, les poissons nagent de gauche à droite sur la scène, vous devez appuyer sur le bouton lorsque le poisson est presque proche de l'hameçon (il est recommandé de le presser plus longtemps) pour attraper le poisson, et le nombre de poissons attrapés sera enregistré automatiquement.

.. image:: img/18_fish.png

Composants requis
---------------------

Pour ce projet, nous aurons besoin des composants suivants.

Il est certainement pratique d'acheter un kit complet, voici le lien :

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nom	
        - ÉLÉMENTS DE CE KIT
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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_capacitor`
        - |link_capacitor_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|

Construisez le Circuit
-----------------------

Le bouton est un dispositif à 4 broches, puisque la broche 1 est connectée à la broche 2, et la broche 3 à la broche 4, lorsque le bouton est pressé, les 4 broches sont connectées, fermant ainsi le circuit.

.. image:: img/5_buttonc.png

Construisez le circuit selon le schéma suivant.

* Connectez l'une des broches du côté gauche du bouton à la broche 12, qui est connectée à une résistance de tirage et à un condensateur de 0.1uF (104) (pour éliminer le jitter et émettre un niveau stable lorsque le bouton fonctionne).
* Connectez l'autre extrémité de la résistance et du condensateur à GND, et l'une des broches du côté droit du bouton à 5V.

.. image:: img/circuit/button_circuit.png

Programmation
------------------

Nous devons d'abord sélectionner un décor **Underwater**, puis ajouter un sprite **Fish** et le faire nager de gauche à droite sur la scène. Dessinez ensuite un sprite **Fishhook** et contrôlez-le par un bouton pour commencer la pêche. Lorsque le sprite **Fish** touche le sprite **Fishhook** dans l'état accroché (devient rouge), il sera attrapé.

**1. Ajouter un décor**

Utilisez le bouton **Choose a Backdrop** pour ajouter un décor **Underwater**.

.. image:: img/18_under.png

**2. Sprite Hameçon**

Le sprite **Fishhook** reste généralement sous l'eau en état jaune ; lorsque le bouton est pressé, il est en état de pêche (rouge) et se déplace au-dessus de la scène.

Il n'y a pas de sprite **Fishhook** dans Pictoblox, nous pouvons modifier le sprite **Glow-J** pour qu'il ressemble à un hameçon.

* Ajoutez le sprite **Glow-J** via **Choose a Sprite**.

.. image:: img/18_hook.png

* Allez maintenant à la page **Costumes** du sprite **Glow-J**, sélectionnez le remplissage Cyan à l'écran et retirez-le. Changez ensuite la couleur J en rouge et réduisez également sa largeur. Le point le plus important à noter est que vous devez avoir le haut juste au point central.

.. image:: img/18_hook1.png

* Utilisez l'outil **Line tool** pour dessiner une ligne aussi longue que possible du point central vers le haut (ligne hors de la scène). Maintenant que le sprite est dessiné, réglez le nom du sprite sur **Fishhook** et déplacez-le à la bonne position.

.. image:: img/18_hook2.png

* Lorsque le drapeau vert est cliqué, réglez l'effet de couleur du sprite à 30 (jaune), et définissez sa position initiale.

.. image:: img/18_hook3.png


* Si le bouton est pressé, réglez l'effet de couleur à 0 (rouge, commencez l'état de pêche), attendez 0,1 puis déplacez le sprite **Fishhook** au-dessus de la scène. Relâchez le bouton et laissez le **Fishhook** revenir à sa position initiale.

.. image:: img/18_hook4.png

**3. Sprite Poisson**

L'effet à atteindre par le sprite **Fish** est de se déplacer de gauche à droite sur la scène, et lorsqu'il rencontre un sprite **Fishhook** en état de pêche, il rétrécit et se déplace à une position spécifique puis disparaît, et clone ensuite un nouveau sprite **fish**.

* Ajoutez maintenant le sprite **fish** et ajustez sa taille et sa position.

.. image:: img/18_fish1.png

* Créez une variable **score** pour stocker le nombre de poissons attrapés, cachez ce sprite et clonez-le.

.. image:: img/18_fish2.png


* Montrez le clone du sprite **fish**, changez son costume et enfin définissez la position initiale.


.. image:: img/18_fish3.png


* Faites bouger le clone du sprite **fish** de gauche à droite et rebondir lorsqu'il touche le bord.


.. image:: img/18_fish4.png


* Le sprite **fish** (du clone) ne réagit pas lorsqu'il passe l'sprite **Fishhook** ; lorsqu'il touche le sprite **Fishhook** en état de pêche (devient rouge), il sera attrapé, à ce moment le score (variable score) +1, et il montrera également une animation de score (rétrécit de 40%, se déplace rapidement vers la position du tableau de score et disparaît). En même temps, un nouveau poisson est créé (un nouveau clone de sprite poisson) et le jeu continue.

.. note::
    
    Vous devez cliquer sur la zone de couleur dans le bloc [Touch color], puis sélectionner l'outil pipette pour prendre la couleur rouge du sprite **Fishhook** sur la scène. Si vous choisissez une couleur arbitrairement, ce bloc [Touch color] ne fonctionnera pas.



.. image:: img/18_fish5.png







