.. note:: 

    Bonjour et bienvenue dans la communauté Facebook des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions spéciales.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_led:

LED
==========

.. image:: img/LED.png
    :width: 400

Une diode électroluminescente (LED) est un composant semi-conducteur capable de transformer l'énergie électrique en énergie lumineuse via des jonctions PN. Selon la longueur d'onde, elle peut être classée en diode laser, diode émettant une lumière infrarouge ou diode émettant une lumière visible, communément appelée LED.

Une diode a une conductivité unidirectionnelle, ce qui signifie que le courant ne peut circuler que dans le sens de la flèche indiqué sur le symbole de circuit. Pour qu'une LED s'allume, son anode doit être connectée à une tension positive et sa cathode à une tension négative.

.. image:: img/led_symbol.png


Une LED possède deux broches. La plus longue est l'anode, et la plus courte, la cathode. Veillez à ne pas les connecter à l'envers. Une LED a une chute de tension directe fixe, elle ne peut donc pas être connectée directement au circuit sans risque d'endommagement, car la tension d'alimentation pourrait dépasser cette chute et brûler la LED. La chute de tension directe pour une LED rouge, jaune ou verte est de 1,8 V, tandis qu'elle est de 2,6 V pour une LED blanche. La plupart des LED peuvent supporter un courant maximal de 20 mA, c'est pourquoi il est nécessaire de connecter une résistance de limitation de courant en série.

La formule pour calculer la valeur de la résistance est la suivante :

    R = (Vsupply – VD)/I

**R** représente la valeur de la résistance limitante, **Vsupply** la tension d'alimentation, **VD** la chute de tension de la LED, et **I** le courant de fonctionnement de la LED.

Pour plus de détails sur les LED, consultez : `LED - Wikipédia <https://en.wikipedia.org/wiki/Light-emitting_diode>`_.

**Exemple**

* :ref:`ar_blink` (Projet de base)
* :ref:`ar_fading` (Projet de base)
* :ref:`iot_blink` (Projet IoT)

.. * :ref:`sh_breathing_led` (Projet Scratch)
.. * :ref:`sh_table_lamp` (Projet Scratch)
