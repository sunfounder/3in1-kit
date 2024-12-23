.. note:: 

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions spéciales.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_reed:

Interrupteur Reed
======================

.. image:: img/reed.png

L'interrupteur Reed est un interrupteur électrique qui fonctionne grâce à un champ magnétique appliqué. Il a été inventé par Walter B. Ellwood des laboratoires Bell Telephone en 1936 et breveté aux États-Unis le 27 juin 1940 sous le numéro de brevet 2264746.

Le principe de fonctionnement d'un interrupteur Reed est très simple. Deux lamelles (généralement en fer et en nickel, deux métaux) qui se chevauchent à leurs extrémités sont scellées dans un tube en verre. Ces deux lamelles se chevauchent avec un petit écart (d'environ quelques microns). Le tube en verre est rempli d'un gaz inerte de haute pureté (comme l'azote), et certains interrupteurs Reed sont conçus pour être sous vide afin d'améliorer leur performance en haute tension. 

Les lamelles agissent comme des conducteurs de flux magnétique. Lorsque l'interrupteur n'est pas activé, les deux lamelles ne sont pas en contact. Lorsqu'un champ magnétique généré par un aimant permanent ou une bobine électromagnétique est appliqué, ce champ magnétique provoque des polarités opposées aux extrémités des lamelles. Lorsque la force magnétique dépasse la force de rappel des lamelles, celles-ci sont attirées l'une vers l'autre, fermant ainsi le circuit. Lorsque le champ magnétique diminue ou disparaît, les lamelles reviennent à leur position initiale grâce à leur élasticité, séparant les surfaces de contact et ouvrant le circuit.

.. image:: img/reed_sche.png

* `Interrupteur Reed - Wikipedia <https://en.wikipedia.org/wiki/Reed_switch>`_


**Exemple**


* :ref:`ar_reed` (Projet de base)
* :ref:`iot_gate` (Projet IoT)
