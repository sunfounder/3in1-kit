.. note::

    Bonjour et bienvenue dans la Communauté Facebook des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez [|link_sf_facebook|] et rejoignez-nous aujourd'hui !

.. _cpn_reed:

Interrupteur à Lame Souple
============================

.. image:: img/reed.png

L'interrupteur à lame souple est un commutateur électrique qui fonctionne au moyen d'un champ magnétique appliqué. Il a été inventé par Walter B. Ellwood des Bell Telephone Laboratories en 1936 et breveté aux États-Unis le 27 juin 1940, sous le numéro de brevet 2264746.

Le principe de fonctionnement d'un interrupteur à lame souple est très simple. Deux lames (généralement en fer et nickel, deux métaux) qui se chevauchent aux points d'extrémité sont scellées dans un tube en verre, avec les deux lames se chevauchant et séparées par un petit espace (seulement quelques microns). Le tube en verre est rempli d'un gaz inerte de haute pureté (tel que l'azote), et certains interrupteurs à lame souple sont conçus pour avoir un vide à l'intérieur afin d'améliorer leur performance à haute tension.

La lame agit comme un conducteur de flux magnétique. Les deux lames ne sont pas en contact lorsqu'elles ne sont pas encore en fonctionnement ; lorsqu'elles traversent un champ magnétique généré par un aimant permanent ou une bobine électromagnétique, le champ magnétique appliqué provoque des polarités différentes près de leurs points d'extrémité, et lorsque la force magnétique dépasse la force de ressort des lames elles-mêmes, les deux lames seront attirées l'une vers l'autre pour conduire le circuit ; lorsque le champ magnétique s'affaiblit ou disparaît, les lames sont relâchées en raison de leur propre élasticité, et les surfaces de contact se sépareront pour ouvrir le circuit.

.. image:: img/reed_sche.png

* `Interrupteur à Lame Souple - Wikipédia <https://en.wikipedia.org/wiki/Reed_switch>`_

**Exemple**

* :ref:`ar_reed` (Projet de base)
* :ref:`iot_gate` (Projet IoT)
