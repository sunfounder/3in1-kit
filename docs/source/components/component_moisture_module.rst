.. _cpn_soil_moisture:

Module d'Humidité du Sol
================================

.. image:: img/soil_mositure.png

* GND : Masse
* VCC : Alimentation électrique, 3.3v~5V
* AOUT : Sort la valeur d'humidité du sol, plus le sol est humide, plus sa valeur est petite.

Ce capteur capacitif d'humidité du sol se distingue de la plupart des capteurs résistifs sur le marché, en utilisant le principe de l'induction capacitive pour détecter l'humidité du sol. Il évite le problème des capteurs résistifs qui sont très sensibles à la corrosion et prolonge considérablement sa durée de vie.

Il est fabriqué à partir de matériaux résistants à la corrosion et possède une excellente durée de vie. Insérez-le dans le sol autour des plantes et surveillez les données d'humidité du sol en temps réel. Le module comprend un régulateur de tension intégré qui lui permet de fonctionner sur une plage de tension de 3.3 ~ 5.5 V. Il est idéal pour les microcontrôleurs basse tension avec des alimentations de 3.3 V et 5 V.

Le schéma matériel du capteur capacitif d'humidité du sol est montré ci-dessous.

.. image:: img/solid_schematic.png

Il y a un oscillateur à fréquence fixe, construit avec un circuit intégré de minuterie 555. L'onde carrée générée est ensuite envoyée au capteur comme un condensateur. Cependant, pour le signal d'onde carrée, le condensateur a une certaine réactance ou, pour simplifier, une résistance avec une résistance ohmique pure (résistance de 10k sur la broche 3) pour former un diviseur de tension.

Plus l'humidité du sol est élevée, plus la capacité du capteur est grande. En conséquence, l'onde carrée a moins de réactance, ce qui réduit la tension sur la ligne de signal, et plus petite est la valeur de l'entrée analogique à travers le microcontrôleur.

**Spécifications**

* Tension de fonctionnement : 3.3 ~ 5.5 VDC
* Tension de sortie : 0 ~ 3.0VDC
* Courant de fonctionnement : 5mA
* Interface : PH2.0-3P
* Dimensions : 3.86 x 0.905 pouces (L x l)
* Poids : 15g

**Exemple**

* :ref:`ar_moisture` (Projet de base)
* :ref:`iot_plant` (Projet IoT)

