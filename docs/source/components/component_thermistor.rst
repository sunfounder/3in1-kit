.. _cpn_thermistor:

Thermistance
===============

.. image:: img/thermistor.png
    :width: 150
    :align: center

Une thermistance est un type de résistance dont la résistance dépend fortement de la température, bien plus que dans les résistances standard. Le mot est une combinaison de thermal (thermique) et resistor (résistance). Les thermistances sont largement utilisées comme limiteurs de courant d'appel, capteurs de température (type à coefficient de température négatif ou NTC généralement), protecteurs de surintensité auto-réarmables et éléments chauffants autorégulants (type à coefficient de température positif ou PTC généralement).

* `Thermistance - Wikipédia <https://en.wikipedia.org/wiki/Thermistor>`_

Voici le symbole électronique de la thermistance.

.. image:: img/thermistor_symbol.png
    :width: 300
    :align: center

Il existe deux types fondamentaux de thermistances :

* Avec les thermistances NTC, la résistance diminue à mesure que la température augmente, généralement en raison d'une augmentation des électrons de conduction élevés par l'agitation thermique de la bande de valence. Un NTC est couramment utilisé comme capteur de température, ou en série avec un circuit comme limiteur de courant d'appel.
* Avec les thermistances PTC, la résistance augmente à mesure que la température augmente, généralement en raison d'une augmentation de l'agitation thermique du réseau, en particulier celles des impuretés et imperfections. Les thermistances PTC sont généralement installées en série avec un circuit et utilisées pour protéger contre les conditions de surintensité, en tant que fusibles réarmables.

Dans ce kit, nous utilisons un NTC. Chaque thermistance a une résistance normale. Ici, elle est de 10k ohms, mesurée à 25 degrés Celsius.

Voici la relation entre la résistance et la température :

    RT = RN * expB(1/TK – 1/TN)   

* **RT** est la résistance de la thermistance NTC lorsque la température est TK. 
* **RN** est la résistance de la thermistance NTC sous la température nominale TN. Ici, la valeur numérique de RN est 10k.
* **TK** est une température en Kelvin et l'unité est K. Ici, la valeur numérique de TK est 273.15 + degrés Celsius.
* **TN** est une température nominale en Kelvin; l'unité est également K. Ici, la valeur numérique de TN est 273.15+25.
* Et **B(beta)**, la constante de matériau de la thermistance NTC, est également appelée indice de sensibilité thermique avec une valeur numérique 3950.      
* **exp** est l'abréviation d'exponentielle, et le nombre de base e est un nombre naturel et équivaut à environ 2.7.  

Convertissez cette formule TK=1/(ln(RT/RN)/B+1/TN) pour obtenir la température en Kelvin qui moins 273.15 équivaut aux degrés Celsius.

Cette relation est une formule empirique. Elle est précise uniquement lorsque la température et la résistance sont dans la plage effective.

**Exemple**

* :ref:`ar_high_tem_alarm` (Projet de base)
* :ref:`ar_temp` (Projet de base)
* :ref:`sh_low_temperature` (Projet Scratch)

