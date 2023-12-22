.. _ar_ultrasonic:

5.8 Fonction Définie par l'Utilisateur
======================================

En C, nous pouvons diviser un grand programme en blocs de construction de base connus sous le nom de fonction.
La fonction contient l'ensemble des instructions de programmation entourées par {}.
Une fonction peut être appelée plusieurs fois pour fournir une réutilisabilité et une modularité au programme C.
En d'autres termes, nous pouvons dire que la collection de fonctions crée un programme.
La fonction est également connue sous le nom de procédure ou sous-routine dans d'autres langages de programmation.

Voici les avantages des fonctions :

* En utilisant des fonctions, nous pouvons éviter de réécrire la même logique/code encore et encore dans un programme.
* Nous pouvons appeler des fonctions C autant de fois que nous le souhaitons dans un programme et de n'importe quel endroit dans un programme.
* Nous pouvons facilement suivre un grand programme C lorsqu'il est divisé en plusieurs fonctions.
* La réutilisabilité est la principale réalisation des fonctions C.
* Cependant, l'appel de fonction est toujours un surcoût dans un programme C.

Il existe deux types de fonctions en programmation C :

* **Fonctions de Bibliothèque** : les fonctions qui sont déclarées dans les fichiers d'en-tête C.
* **Fonctions Définies par l'Utilisateur** : les fonctions créées par le programmeur C, afin qu'il/elle puisse les utiliser plusieurs fois. Cela réduit la complexité d'un grand programme et optimise le code.

Dans ce projet, définissez une fonction pour lire la valeur du module ultrasonique.

**Composants Requis**

Dans ce projet, nous avons besoin des composants suivants.

Il est certainement pratique d'acheter un kit complet, voici le lien :

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nom
        - ARTICLES DANS CE KIT
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
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|

**Schéma**

.. image:: img/circuit_6.3_ultrasonic.png

**Câblage**

.. image:: img/ultrasonic_bb.jpg
    :width: 600
    :align: center

**Code**

.. note::

    * Ouvrez le fichier ``5.8.user_function.ino`` sous le chemin de ``3in1-kit\basic_project\5.8.user_function``.
    * Ou copiez ce code dans **Arduino IDE**.
    
    * Ou téléchargez le code via le `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/11717782-3ee6-4eca-bbb9-094385d9eb4b/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    

Après le téléchargement réussi du code, le moniteur série affichera la distance entre le capteur ultrasonique et l'obstacle devant.

**Comment ça marche ?**

Concernant l'application du capteur ultrasonique, nous pouvons directement vérifier la sous-fonction.

.. code-block:: arduino

    float readSensorData(){// ...}

La broche ``trigPin`` du module ultrasonique transmet un signal carré de 10us toutes les 2us

.. code-block:: arduino

    digitalWrite(trigPin, LOW); 
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH); 
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW); 


La broche ``echoPin`` reçoit un signal de haut niveau s'il y a un obstacle dans la portée et utilise la fonction ``pulseIn()`` pour enregistrer le temps entre l'envoi et la réception.

.. code-block:: arduino

    microsecond=pulseIn(echoPin, HIGH);

La vitesse du son est de 340 m/s ou 29 microsecondes par centimètre.

Cela donne la distance parcourue par l'onde carrée, aller et retour, donc
nous divisons par 2 pour obtenir la distance de l'obstacle.

.. code-block:: arduino

    float distance = microsecond / 29.00 / 2;  


Notez que le capteur ultrasonique mettra le programme en pause lorsqu'il fonctionne, ce qui peut provoquer des ralentissements lors de l'écriture de projets complexes.
