.. note::

    Bonjour et bienvenue dans la Communauté Facebook des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez [|link_sf_facebook|] et rejoignez-nous aujourd'hui !

.. _cpn_potentiometer:

Potentiomètre
===============

.. image:: img/potentiometer.png
    :align: center
    :width: 150

Le potentiomètre est également un composant de résistance à 3 bornes dont la valeur peut être ajustée selon une variation régulière.

Les potentiomètres se présentent sous différentes formes, tailles et valeurs, mais ils ont tous les points communs suivants :

* Ils ont trois bornes (ou points de connexion).
* Ils disposent d'un bouton, d'une vis ou d'un curseur qui peut être déplacé pour faire varier la résistance entre la borne centrale et l'une des bornes extérieures.
* La résistance entre la borne centrale et l'une des bornes extérieures varie de 0 Ω à la résistance maximale du potentiomètre lorsque le bouton, la vis ou le curseur est déplacé.

Voici le symbole de circuit du potentiomètre.

.. image:: img/potentiometer_symbol.png
    :align: center
    :width: 400

Les fonctions du potentiomètre dans le circuit sont les suivantes :

#. Agir comme un diviseur de tension

    Le potentiomètre est une résistance réglable en continu. Lorsque vous ajustez l'axe ou la poignée coulissante du potentiomètre, le contact mobile glissera sur la résistance. À ce moment, une tension peut être délivrée en fonction de la tension appliquée sur le potentiomètre et de l'angle de rotation ou du déplacement du bras mobile.

#. Agir comme un rhéostat

    Lorsque le potentiomètre est utilisé comme un rhéostat, connectez la broche centrale et l'une des 2 autres broches dans le circuit. Ainsi, vous pouvez obtenir une valeur de résistance modifiée en douceur et de manière continue dans le déplacement du contact mobile.

#. Agir comme un régulateur de courant

    Lorsque le potentiomètre agit comme un régulateur de courant, la borne de contact coulissante doit être connectée comme l'une des bornes de sortie.

Si vous souhaitez en savoir plus sur le potentiomètre, consultez : `Potentiomètre - Wikipédia <https://en.wikipedia.org/wiki/Potentiometer>`_

**Exemple**

* :ref:`ar_potentiometer` (Projet de base)
* :ref:`sh_moving_mouse` (Projet Scratch)
* :ref:`sh_breakout_clone` (Projet Scratch)



