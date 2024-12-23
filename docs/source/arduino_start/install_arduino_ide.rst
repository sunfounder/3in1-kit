.. note::

    Bonjour, bienvenue dans la communauté SunFounder dédiée aux passionnés de Raspberry Pi, Arduino et ESP32 sur Facebook ! Explorez plus en profondeur Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes post-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et à des aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions spéciales.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _install_arduino:

Télécharger et installer l'Arduino IDE 2.0
===========================================

L'Arduino IDE, également connu sous le nom d'environnement de développement intégré Arduino, fournit tout le support logiciel nécessaire pour réaliser un projet Arduino. C'est un logiciel de programmation spécifiquement conçu pour Arduino, fourni par l'équipe Arduino, qui nous permet d'écrire des programmes et de les téléverser sur la carte Arduino.

L'Arduino IDE 2.0 est un projet open-source. C'est une avancée majeure par rapport à son prédécesseur robuste, Arduino IDE 1.x, et il offre une interface utilisateur remaniée, un gestionnaire de cartes et de bibliothèques amélioré, un débogueur, une fonctionnalité d'autocomplétion et bien plus encore.

Dans ce tutoriel, nous allons vous montrer comment télécharger et installer l'Arduino IDE 2.0 sur votre ordinateur Windows, Mac ou Linux.

Prérequis
------------------

* Windows - Win 10 ou version ultérieure, 64 bits
* Linux - 64 bits
* macOS - Version 10.14 : "Mojave" ou plus récent, 64 bits

Télécharger l'Arduino IDE 2.0
--------------------------------

#. Visitez |link_download_arduino|.

#. Téléchargez l'IDE correspondant à la version de votre système d'exploitation.

    .. image:: img/sp_001.png

Installation
------------------------------

Windows
^^^^^^^^^^^^^

#. Double-cliquez sur le fichier ``arduino-ide_xxxx.exe`` pour exécuter le fichier téléchargé.

#. Lisez l'accord de licence et acceptez-le.

    .. image:: img/sp_002.png

#. Choisissez les options d'installation.

    .. image:: img/sp_003.png

#. Sélectionnez l'emplacement d'installation. Il est recommandé d'installer le logiciel sur un lecteur autre que le lecteur système.

    .. image:: img/sp_004.png

#. Cliquez sur **Finish**. 

    .. image:: img/sp_005.png

macOS
^^^^^^^^^^^^^^^^

Double-cliquez sur le fichier téléchargé ``arduino_ide_xxxx.dmg`` et suivez les instructions pour copier **Arduino IDE.app** dans le dossier **Applications**. Vous verrez l'IDE Arduino installé avec succès après quelques secondes.

.. image:: img/macos_install_ide.png
    :width: 800

Linux
^^^^^^^^^^^^

Pour le tutoriel d'installation de l'Arduino IDE 2.0 sur un système Linux, veuillez consulter : https://docs.arduino.cc/software/ide-v2/tutorials/getting-started/ide-v2-downloading-and-installing#linux

Ouvrir l'IDE
---------------

#. Lors de la première ouverture de l'Arduino IDE 2.0, celui-ci installe automatiquement les cartes Arduino AVR, les bibliothèques intégrées et d'autres fichiers requis.

    .. image:: img/sp_901.png

#. De plus, votre pare-feu ou votre centre de sécurité peut s'afficher plusieurs fois pour vous demander si vous souhaitez installer certains pilotes de périphérique. Veuillez les installer tous.

    .. image:: img/sp_104.png

#. Votre Arduino IDE est maintenant prêt !

    .. note::
        Si certaines installations n'ont pas réussi en raison de problèmes de réseau ou d'autres raisons, vous pouvez rouvrir l'Arduino IDE, qui terminera le reste de l'installation. La fenêtre de sortie ne s'ouvrira pas automatiquement après l'installation complète, sauf si vous cliquez sur **Verify** ou **Upload**.
