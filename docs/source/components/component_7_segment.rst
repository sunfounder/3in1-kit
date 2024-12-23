.. note:: 

    Bonjour et bienvenue dans la communauté Facebook des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions spéciales.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_7_segment:

Affichage à 7 segments
===========================

.. image:: img/7_segment.png
    :width: 200
    :align: center

Un affichage à 7 segments est un composant en forme de 8 regroupant 7 LED. Chaque LED est appelée un segment - lorsqu'elle est alimentée, un segment forme une partie d'un chiffre à afficher.

Il existe deux types de connexion de broches : cathode commune (CC) et anode commune (CA). Comme son nom l'indique, un affichage CC connecte toutes les cathodes des 7 LED, tandis qu'un affichage CA connecte toutes les anodes des 7 segments.

Dans ce kit, nous utilisons un affichage à 7 segments à cathode commune. Voici son symbole électronique :

.. image:: img/segment_cathode.png
    :width: 800

Chacune des LED de l'affichage est associée à un segment positionnel avec une de ses broches de connexion sortie du boîtier plastique rectangulaire. Ces broches de LED sont étiquetées de "a" à "g", représentant chaque LED individuelle. Les autres broches de LED sont connectées ensemble pour former une broche commune. En polarisant dans le sens direct les broches appropriées des segments LED dans un certain ordre, certains segments s'illumineront tandis que d'autres resteront éteints, affichant ainsi le caractère correspondant.

**Codes d'affichage**

Pour vous aider à comprendre comment les affichages à 7 segments (cathode commune) affichent les chiffres, nous avons établi le tableau suivant. Les "Numbers" représentent les chiffres de 0 à F affichés sur l'affichage à 7 segments ; (DP) GFEDCBA indique les LED correspondantes configurées sur 0 ou 1. Par exemple, 00111111 signifie que DP et G sont réglés sur 0, tandis que les autres sont réglés sur 1. Ainsi, le chiffre 0 est affiché sur l'affichage à 7 segments, tandis que le code HEX correspond au nombre hexadécimal.

.. image:: img/segment_code.png

**Exemple**

* :ref:`ar_74hc_7seg` (Projet de base)
* :ref:`iot_gate` (Projet IoT)
