.. _sh_pendulum:

2.10 Pendule
=====================

Dans ce projet, nous allons réaliser un pendule en forme de flèche, tandis que le servo-moteur suivra la rotation.

.. image:: img/12_pun.png

Vous Apprendrez
---------------------

- Comment fonctionne un servo-moteur et sa plage d'angle
- Dessiner un sprite et placer le point central sur la queue.

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_servo`
        - |link_servo_buy|

Construisez le Circuit
-----------------------

Un servo-moteur est un moteur engrené qui ne peut tourner que de 180 degrés. Il est contrôlé en envoyant des impulsions électriques depuis votre carte de circuit. Ces impulsions indiquent au servo-moteur la position dans laquelle il doit se déplacer.

Le servo-moteur a trois fils : le fil marron est le GND, le rouge est le VCC (à connecter à 3.3V), et l'orange est le fil de signal. La plage d'angle est de 0 à 180 degrés.

Construisez maintenant le circuit selon le schéma ci-dessous.

.. image:: img/circuit/servo_circuit.png

Programmation
------------------

**1. Peindre un sprite**

Supprimez le sprite par défaut, sélectionnez le bouton Sprite et cliquez sur **Paint**, un sprite vierge **Sprite1** apparaîtra.

.. image:: img/12_paint1.png

Sur la page **Costumes** ouverte, utilisez l'**Line tool** pour dessiner une flèche.

.. note::

    * Assurez-vous de commencer à dessiner la flèche du centre du canevas vers l'extérieur afin que la flèche tourne en cercle avec le point central comme origine.
    * Maintenez la touche Shift pour rendre l'angle de la ligne droit ou à 45 degrés.

.. image:: img/12_paint2.png

Après avoir dessiné, le sprite **arrow** s'affichera sur la scène, nommez-le **arrow**. Puis cliquez sur le nombre après **Direction**, un cadran circulaire apparaîtra, maintenant faites glisser cette flèche et voyez si le sprite **arrow** sur la scène tourne avec la queue comme origine.

.. image:: img/12_paint3.png

Pour faire osciller le sprite **arrow** de la gauche vers la droite, la plage d'angle est de -90 à -180, 180 à 90.

.. image:: img/12_paint4.png

.. image:: img/12_paint5.png

**2. Création d'une variable**.

Créez une variable appelée **servo**, qui stocke la valeur de l'angle et définit la valeur initiale à 270.

.. image:: img/12_servo.png

**3. Oscillation de la gauche vers la droite**

Faites maintenant osciller le sprite **arrow** de la position -90 degrés à gauche à la position 90 degrés à droite.

Avec le bloc [repeat], ajoutez -10 à la variable à chaque fois, et vous atteindrez 90 degrés en 18 passages. Ensuite, utilisez le bloc [point in block] pour faire tourner le sprite flèche vers ces angles.

Comme l'angle de rotation du sprite est de -180 ~ 180, les angles en dehors de cette plage sont convertis par les conditions suivantes.

* Si angle > 180, alors angle -360.

.. image:: img/12_servo1.png

**4. Faire tourner le Servo**

Lorsque vous cliquez sur le drapeau vert, vous verrez la flèche tourner rapidement vers la droite puis revenir vers la gauche, utilisez donc un bloc [wait seconds] ici pour ralentir la rotation. Utilisez également le bloc [set servo on to angle] pour faire tourner le servo connecté à la carte Arduino vers un angle spécifique.

.. image:: img/12_servo2.png

**5. Oscillation de droite à gauche**

De la même manière, faites tourner lentement le servo et le sprite **arrow** de la droite vers la gauche.

* Si angle > 180, alors angle -360.

.. image:: img/12_servo3.png

