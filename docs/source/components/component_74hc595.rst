.. _cpn_74hc595:

74HC595
===========

.. image:: img/74HC595.png

Le 74HC595 est composé d'un registre à décalage de 8 bits et d'un registre de stockage avec des sorties parallèles à trois états. Il convertit l'entrée série en sortie parallèle, permettant ainsi d'économiser les ports IO d'un MCU.
Lorsque MR (broche 10) est à un niveau haut et OE (broche 13) à un niveau bas, les données sont entrées sur le front montant de SHcp et passent au registre de mémoire sur le front montant de SHcp. Si les deux horloges sont connectées ensemble, le registre à décalage est toujours un pulse en avance sur le registre de mémoire. Il y a une broche d'entrée de décalage série (Ds), une broche de sortie série (Q) et un bouton de réinitialisation asynchrone (niveau bas) dans le registre de mémoire. Le registre de mémoire sort un bus avec un 8-bit parallèle et en trois états. Lorsque OE est activé (niveau bas), les données dans le registre de mémoire sont sorties vers le bus.

* `Fiche technique du 74HC595 <https://www.ti.com/lit/ds/symlink/cd74hc595.pdf?ts=1617341564801>`_

.. image:: img/74hc595_pin.png
    :width: 600

Broches du 74HC595 et leurs fonctions :

* **Q0-Q7** : broches de sortie de données parallèles 8 bits, capables de contrôler directement 8 LEDs ou 8 broches d'affichage à 7 segments.
* **Q7'** : Broche de sortie série, connectée à DS d'un autre 74HC595 pour connecter plusieurs 74HC595 en série
* **MR** : Broche de réinitialisation, active à un niveau bas ; 
* **SHcp** : Entrée de séquence temporelle du registre à décalage. Sur le front montant, les données dans le registre à décalage se déplacent successivement d'un bit, c'est-à-dire que les données en Q1 passent à Q2, et ainsi de suite. Alors que sur le front descendant, les données dans le registre à décalage restent inchangées.
* **STcp** : Entrée de séquence temporelle du registre de stockage. Sur le front montant, les données dans le registre à décalage passent dans le registre de mémoire.
* **CE** : Broche d'activation de sortie, active à un niveau bas. 
* **DS** : Broche d'entrée de données série
* **VCC** : Tension d'alimentation positive.
* **GND** : Masse.

**Exemple**

* :ref:`ar_shiftout` (Projet de base)
* :ref:`ar_segment` (Projet de base)
* :ref:`iot_gate` (Projet IoT)

