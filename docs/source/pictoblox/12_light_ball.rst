.. _sh_light_ball:

2.12 Balle Sensible à la Lumière
===================================

Dans ce projet, nous utilisons une photorésistance pour faire voler la balle sur la scène vers le haut. Placez votre main au-dessus de la photorésistance pour contrôler l'intensité lumineuse qu'elle reçoit. Plus votre main est proche de la photorésistance, plus sa valeur est petite et plus la balle vole haut sur la scène, sinon elle tombera. Lorsque la balle touche la corde, elle produit un joli son ainsi qu'une lumière d'étoiles scintillantes.

.. image:: img/18_ball.png

Vous Apprendrez
---------------------

- Remplir le sprite avec des couleurs
- Toucher entre les sprites

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
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_buy|

Construisez le Circuit
-----------------------

Une photorésistance ou cellule photoélectrique est une résistance variable contrôlée par la lumière. La résistance d'une photorésistance diminue avec l'augmentation de l'intensité lumineuse incidente.

Construisez le circuit selon le schéma suivant.

Connectez une extrémité de la photorésistance à 5V, l'autre à A0, et connectez une résistance de 10K en série avec GND à cette extrémité.

Ainsi, lorsque l'intensité lumineuse augmente, la résistance de la photorésistance diminue, la division de tension de la résistance de 10K augmente, et la valeur obtenue par A0 devient plus grande.

.. image:: img/circuit/photoresistor_circuit.png

Programmation
------------------

L'effet que nous voulons obtenir est que plus votre main est proche de la photorésistance, plus le sprite de la balle sur la scène continue de monter, sinon il tombera sur le sprite bol. S'il touche le sprite Ligne en montant ou en tombant, il produira un son musical et émettra des sprites d'étoiles dans toutes les directions.


**1. Sélectionner le sprite et le décor**

Supprimez le sprite par défaut, sélectionnez les sprites **Ball**, **Bowl** et **Star**.

.. image:: img/18_ball1.png

Déplacez le sprite **Bowl** au centre bas de la scène et agrandissez sa taille.

.. image:: img/18_ball3.png

Comme nous devons le déplacer vers le haut, réglez la direction du sprite **Ball** sur 0.

.. image:: img/18_ball4.png

Réglez la taille et la direction du sprite **Star** sur 180 car nous avons besoin qu'il tombe, ou vous pouvez le changer à un autre angle.

.. image:: img/18_ball12.png

Ajoutez maintenant le décor **Stars**.

.. image:: img/18_ball2.png

**2. Dessiner un sprite Ligne**

Ajoutez un sprite Ligne.

.. image:: img/18_ball7.png

Allez sur la page **Costumes** du sprite **Line**, réduisez légèrement la largeur de la ligne rouge sur le canevas, puis copiez-la 5 fois et alignez les lignes.

.. image:: img/18_ball8.png

Remplissez maintenant les lignes avec différentes couleurs. Choisissez d'abord une couleur que vous aimez, puis cliquez sur l'outil **Fill** et déplacez la souris sur la ligne pour la remplir de couleur.

.. image:: img/18_ball9.png

Suivez la même méthode pour changer la couleur des autres lignes.

.. image:: img/18_ball10.png

**3. Scripter le sprite Balle**

Définissez la position initiale du sprite **Ball**, puis lorsque la valeur de lumière est inférieure à 800 (cela peut être toute autre valeur, selon votre environnement actuel), laissez la Balle monter.

Vous pouvez faire apparaître la variable light_value sur la scène pour observer le changement d'intensité lumineuse à tout moment.

.. image:: img/18_ball5.png

Sinon, le sprite **Ball** tombera et limitera sa coordonnée Y à un minimum de -100. Cela peut être modifié pour qu'il semble tomber sur le sprite **Bowl**.

.. image:: img/18_ball6.png

Lorsque le sprite **Line** est touché, la coordonnée Y actuelle est enregistrée dans la variable **ball_coor** et un message **Bling** est diffusé.

.. image:: img/18_ball11.png

**4. Scripter le sprite Étoile**

Lorsque le script démarre, cachez d'abord le sprite **Star**. Lorsque le message **Bling** est reçu, clonez le sprite **Star**.

.. image:: img/18_ball13.png

Lorsque le sprite **Star** apparaît en tant que clone, jouez l'effet sonore et réglez ses coordonnées pour être synchronisées avec le sprite **Ball**.

.. image:: img/18_ball14.png

Créez l'effet de l'apparition du sprite **Star** et ajustez-le selon les besoins.

.. image:: img/18_ball15.png
