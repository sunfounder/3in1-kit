.. note:: 

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions spéciales.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_rgb:

LED RGB
=================

.. image:: img/rgb_led.png
    :width: 100
    
Les LED RGB émettent de la lumière en différentes couleurs. Une LED RGB intègre trois LEDs (rouge, vert et bleu) dans une coque en plastique transparente ou semi-transparente. En modifiant la tension d'entrée des trois broches et en superposant les couleurs, elle peut afficher une large gamme de teintes, avec un total statistique de 16 777 216 couleurs possibles.

.. image:: img/rgb_light.png
    :width: 600

Les LED RGB se divisent en deux catégories : **anode commune** et **cathode commune**. Ce kit utilise le modèle à **cathode commune**. Dans une configuration à cathode commune (CC), les cathodes des trois LEDs sont connectées ensemble. Après avoir relié la cathode à la masse (GND) et branché les trois broches, la LED affichera la couleur correspondante.

Le symbole du circuit est représenté ci-dessous.

.. image:: img/rgb_symbol.png
    :width: 300

Une LED RGB possède 4 broches : la plus longue est la masse (GND), les trois autres correspondent respectivement au Rouge, au Vert et au Bleu. En touchant la coque en plastique, vous remarquerez une découpe. La broche la plus proche de cette découpe est la première, marquée Rouge, suivie de GND, Vert et Bleu.

.. image:: img/rgb_pin.jpg
    :width: 200

**Exemple**

* :ref:`ar_rgb` (Projet de base)
* :ref:`ar_threshold` (Projet de base)

.. * :ref:`sh_colorful_ball` (Projet Scratch)
