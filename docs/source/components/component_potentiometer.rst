.. note:: 

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions spéciales.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_potentiometer:

Potentiomètre
================

.. image:: img/potentiometer.png
    :align: center
    :width: 150

Un potentiomètre est également un composant de résistance avec 3 bornes, dont la valeur de résistance peut être ajustée selon une variation régulière.

Les potentiomètres se déclinent en différentes formes, tailles et valeurs, mais ils ont tous les points suivants en commun :

* Ils possèdent trois bornes (ou points de connexion).
* Ils comportent un bouton, une vis ou un curseur qui peut être déplacé pour faire varier la résistance entre la borne centrale et l'une des bornes extérieures.
* La résistance entre la borne centrale et l'une des bornes extérieures varie de 0 Ω à la résistance maximale du potentiomètre lorsque le bouton, la vis ou le curseur est déplacé.

Voici le symbole de circuit du potentiomètre.

.. image:: img/potentiometer_symbol.png
    :align: center
    :width: 400

Les fonctions du potentiomètre dans un circuit sont les suivantes :

#. Servir de diviseur de tension

    Le potentiomètre est une résistance réglable en continu. Lorsque vous ajustez l'axe ou la poignée coulissante du potentiomètre, le contact mobile glisse sur la résistance. À ce stade, une tension peut être délivrée en fonction de la tension appliquée au potentiomètre et de l'angle de rotation du bras mobile ou de son déplacement.

#. Servir de rhéostat

    Lorsqu'il est utilisé comme rhéostat, connectez la borne centrale et l'une des deux autres bornes dans le circuit. Ainsi, vous pouvez obtenir une valeur de résistance qui change de manière fluide et continue sur la course du contact mobile.

#. Servir de contrôleur de courant

    Lorsque le potentiomètre agit comme contrôleur de courant, la borne de contact coulissante doit être connectée comme l'une des bornes de sortie.

Pour en savoir plus sur les potentiomètres, consultez : `Potentiomètre - Wikipédia <https://en.wikipedia.org/wiki/Potentiometer>`_

**Exemple**

* :ref:`ar_potentiometer` (Projet de base)

.. * :ref:`sh_moving_mouse` (Projet Scratch)
.. * :ref:`sh_breakout_clone` (Projet Scratch)
