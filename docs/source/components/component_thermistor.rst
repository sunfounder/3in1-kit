.. note:: 

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions spéciales.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_thermistor:

Thermistance
===============

.. image:: img/thermistor.png
    :width: 150
    :align: center

Une thermistance est un type de résistance dont la valeur dépend fortement de la température, bien plus que celle des résistances standards. Le terme est une combinaison de "thermique" et "résistance". Les thermistances sont largement utilisées comme limiteurs de courant d'appel, capteurs de température (généralement de type à coefficient de température négatif ou NTC), protecteurs contre les surintensités réinitialisables et éléments chauffants autorégulateurs (généralement de type à coefficient de température positif ou PTC).

* `Thermistance - Wikipedia <https://fr.wikipedia.org/wiki/Thermistance>`_

Voici le symbole électronique d'une thermistance.

.. image:: img/thermistor_symbol.png
    :width: 300
    :align: center

Les thermistances se divisent en deux types fondamentaux opposés :

* Avec les thermistances NTC, la résistance diminue lorsque la température augmente, en général en raison d'une augmentation des électrons de conduction stimulés par l'agitation thermique de la bande de valence. Une NTC est couramment utilisée comme capteur de température ou en série avec un circuit comme limiteur de courant d'appel.
* Avec les thermistances PTC, la résistance augmente lorsque la température augmente, en général en raison des agitations thermiques accrues du réseau, notamment celles des impuretés et imperfections. Les thermistances PTC sont généralement installées en série avec un circuit et utilisées comme fusibles réinitialisables pour protéger contre les conditions de surintensité.

Dans ce kit, nous utilisons une NTC. Chaque thermistance possède une résistance normale, ici de 10 kΩ, mesurée à 25 degrés Celsius.

Voici la relation entre la résistance et la température :

    RT = RN * expB(1/TK – 1/TN)   

* **RT** est la résistance de la thermistance NTC à la température TK. 
* **RN** est la résistance de la thermistance NTC à la température nominale TN. Ici, RN vaut 10 kΩ.
* **TK** est une température exprimée en Kelvin et son unité est K. Ici, TK vaut 273,15 + degrés Celsius.
* **TN** est une température nominale exprimée en Kelvin. Ici, TN vaut 273,15+25.
* **B(beta)**, la constante de matériau de la thermistance NTC, est également appelée indice de sensibilité thermique et sa valeur est 3950.      
* **exp** est l'abréviation de "exponentielle", et le nombre de base e est une constante naturelle et vaut environ 2,7.  

On peut transformer cette formule en :  TK=1/(ln(RT/RN)/B+1/TN)  pour obtenir la température en Kelvin, à laquelle on soustrait 273,15 pour obtenir la température en degrés Celsius.

Cette relation est une formule empirique. Elle est précise uniquement lorsque la température et la résistance se situent dans la plage effective.

**Exemple**

* :ref:`ar_high_tem_alarm` (Projet de base)
* :ref:`ar_temp` (Projet de base)

.. * :ref:`sh_low_temperature` (Projet Scratch)
