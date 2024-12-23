.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Assistance experte** : Résolvez les problèmes après-vente et relevez des défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprenez et partagez** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions et concours festifs** : Participez à des concours et des offres spéciales.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _basic_projects:

Projets de base
=========================

Ce chapitre est dédié à l'apprentissage du contrôle des circuits électroniques à l'aide d'Arduino.

En fonction des composants, les méthodes de contrôle de base d'Arduino peuvent être divisées en quatre catégories :

* :ref:`ar_digital_write`: Définir la tension de sortie de la broche sur haut ou bas, ce qui permet d'allumer ou d'éteindre une lumière.
* :ref:`ar_analog_write`: Écrire une valeur analogique (`onde PWM <https://docs.arduino.cc/learn/microcontrollers/analog-output>`_) sur la broche, ce qui permet d'ajuster la luminosité de la lumière.
* :ref:`ar_digital_read`: Lire le signal de niveau d'une broche numérique, ce qui permet de connaître l'état de fonctionnement d'un interrupteur.
* :ref:`ar_analog_read`: Lire la tension d'une broche analogique, ce qui permet de connaître l'état de fonctionnement d'un potentiomètre.

Certains composants nécessitent des bibliothèques supplémentaires pour fonctionner et sont regroupés dans la section :ref:`install_libraries_ar`.

Enfin, le kit propose également quelques :ref:`ar_funny_project`, qui comprennent de nombreuses manipulations simples et utiles.
Essayez cette section de code et vous comprendrez comment fonctionnent la plupart des projets simples.

.. toctree::
    :maxdepth: 2

    ard_digital_write
    ard_analog_write
    ard_digital_read
    ard_analog_read
    ard_more_syntax
    ard_funny_project


