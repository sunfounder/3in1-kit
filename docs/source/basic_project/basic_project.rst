.. _basic_projects:

Projets de Base
========================

Ce chapitre est utilisé pour apprendre à contrôler des circuits électroniques en utilisant Arduino.

En fonction des composants, les méthodes de contrôle de base d'Arduino peuvent être divisées en quatre types :

* :ref:`ar_digital_write` : Définir la tension de sortie de la broche en haute ou basse, qui peut être utilisée pour allumer et éteindre la lumière.
* :ref:`ar_analog_write` : Écrire la valeur analogique (`onde PWM <https://docs.arduino.cc/learn/microcontrollers/analog-output>`_) sur la broche, qui peut être utilisée pour ajuster la luminosité de la lumière.
* :ref:`ar_digital_read` : Lire le signal de niveau de la broche numérique, qui peut être utilisé pour lire l'état de fonctionnement de l'interrupteur.
* :ref:`ar_analog_read` : Lire la tension de la broche analogique, qui peut être utilisée pour lire l'état de fonctionnement du bouton.

Il existe également certains composants qui nécessitent des bibliothèques supplémentaires pour être utilisés, et ceux-ci sont regroupés sous la section :ref:`install_libraries_ar`.

Enfin, le kit fournit également quelques :ref:`ar_funny_project`, qui comprend de nombreuses manipulations simples et utiles.
Essayez cette section de code et vous comprendrez comment fonctionnent la plupart des projets simples.


.. toctree::
    :maxdepth: 2

    ard_digital_write
    ard_analog_write
    ard_digital_read
    ard_analog_read
    ard_more_syntax
    ard_funny_project



