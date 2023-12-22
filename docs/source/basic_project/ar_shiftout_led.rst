.. _ar_shiftout:

5.9 ShiftOut(LED)
=======================

La fonction ``shiftOut()`` permet au 74HC595 de produire 8 signaux numériques. Elle émet le dernier bit du nombre binaire sur Q0, et la sortie du premier bit sur Q7. En d'autres termes, écrire le nombre binaire « 00000001 » fera que Q0 émette un niveau haut et que Q1~Q7 émettent un niveau bas.

Dans ce projet, vous apprendrez à utiliser le 74HC595. Le 74HC595 comprend un registre de décalage de 8 bits et un registre de stockage avec des sorties parallèles à trois états. Il convertit une entrée série en sortie parallèle, vous permettant ainsi d'économiser des ports IO d'un MCU.

Plus précisément, le 74hc595 peut remplacer 8 broches pour la sortie de signal numérique en écrivant un nombre binaire de 8 bits.

* `Nombre binaire - Wikipédia <https://en.wikipedia.org/wiki/Binary_number>`_

**Composants requis**

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_74hc595`
        - |link_74hc595_buy|

**Schéma**

.. image:: img/circuit_6.4_74hc595.png

* Lorsque MR (broche 10) est au niveau haut et OE (broche 13) au niveau bas, les données sont entrées sur le bord montant de SHcp et vont au registre mémoire via le bord montant de SHcp.
* Si les deux horloges sont connectées ensemble, le registre de décalage est toujours un pulse en avance sur le registre mémoire.
* Il y a une broche d'entrée de décalage série (Ds), une broche de sortie série (Q) et un bouton de réinitialisation asynchrone (niveau bas) dans le registre mémoire.
* Le registre mémoire émet un bus avec un 8 bits parallèle et en trois états.
* Lorsque OE est activé (niveau bas), les données dans le registre mémoire sont émises vers le bus(Q0 ~ Q7).

**Câblage**

.. image:: img/74hc595_bb.jpg
    :width: 800
    :align: center

**Code**

.. note::

    * Ouvrez le fichier ``5.9.shiftout_led.ino`` se trouvant dans ``3in1-kit\basic_project\5.9.shiftout_led``.
    * Ou copiez ce code dans **Arduino IDE**.
    
    * Ou téléchargez le code via `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.


.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/4c208eb3-67f0-40f7-999a-0eeca8b6b466/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Une fois les codes téléchargés sur la carte R3, vous pouvez voir les LED s'allumer l'une après l'autre.

**Comment ça fonctionne ?**

Déclarez un tableau,
stockez plusieurs nombres binaires de 8 bits utilisés pour changer l'état de fonctionnement des huit LED contrôlées par le 74HC595.

.. code-block:: arduino

    int datArray[] = {B00000000, B00000001, B00000011, B00000111, B00001111, B00011111, B00111111, B01111111, B11111111};

Mettez ``STcp`` à un niveau bas puis à un niveau haut.
Cela générera une impulsion de bord montant sur STcp.

.. code-block:: arduino

    digitalWrite(STcp, LOW); 

``shiftOut()`` est utilisé pour décaler un octet de données bit par bit,
ce qui signifie décaler un octet de données dans ``datArray[num]`` vers le registre de décalage avec la broche ``DS``. **MSBFIRST** indique de déplacer les bits du plus significatif au moins significatif.

.. code-block:: arduino

    shiftOut(DS,SHcp,MSBFIRST,datArray[num]);

Après l'exécution de ``digitalWrite(STcp, HIGH)``, ``STcp`` sera sur un bord montant.
À ce moment, les données dans le registre de décalage seront transférées vers le registre mémoire.

.. code-block:: arduino

    digitalWrite(STcp,HIGH);

Un octet de données sera transféré dans le registre mémoire après 8 opérations.
Ensuite, les données du registre mémoire sont envoyées au bus (Q0-Q7).
Par exemple, un shiftOut de ``B00000001`` allumera la LED contrôlée par Q0 et éteindra les LED contrôlées par Q1 à Q7.
