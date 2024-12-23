.. note:: 

    Bonjour et bienvenue dans la communauté Facebook des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions spéciales.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_i2c_lcd1602:

I2C LCD1602
==============

.. image:: img/i2c_lcd1602.png
    :width: 800

* **GND** : Masse
* **VCC** : Alimentation, 5V.
* **SDA** : Ligne de données série. Connectez à VCC via une résistance de pull-up.
* **SCL** : Ligne d'horloge série. Connectez à VCC via une résistance de pull-up.

Comme nous le savons tous, bien que les écrans LCD et d'autres affichages enrichissent considérablement l'interaction homme-machine, ils présentent un inconvénient majeur. Lorsqu'ils sont connectés à un contrôleur, ils occupent plusieurs ports d'entrée/sortie (IO) du contrôleur, limitant ainsi les autres fonctions du contrôleur.

Pour résoudre ce problème, un module I2C a été ajouté au LCD1602. Ce module I2C intègre une puce PCF8574 qui convertit les données série I2C en données parallèles pour l'affichage LCD.

* `Fiche technique PCF8574 <https://www.ti.com/lit/ds/symlink/pcf8574.pdf?ts=1627006546204&ref_url=https%253A%252F%252Fwww.google.com%252F>`_

**Adresse I2C**

L'adresse par défaut est généralement 0x27, mais dans certains cas, elle peut être 0x3F.

En prenant l'adresse par défaut 0x27 comme exemple, l'adresse de l'appareil peut être modifiée en reliant les broches A0/A1/A2 ; à l'état par défaut, A0/A1/A2 est à 1, et si les broches sont reliées, A0/A1/A2 passe à 0.

.. image:: img/i2c_address.jpg
    :width: 600

**Rétroéclairage/Contraste**

Le rétroéclairage peut être activé à l'aide d'un cavalier. Retirez le cavalier pour désactiver le rétroéclairage. Le potentiomètre bleu situé à l'arrière est utilisé pour ajuster le contraste (le rapport entre la luminosité du blanc le plus clair et du noir le plus sombre).

.. image:: img/back_lcd1602.jpg

* **Cavalier** : Le rétroéclairage peut être activé avec ce cavalier. Retirez-le pour désactiver le rétroéclairage.
* **Potentiomètre** : Utilisé pour ajuster le contraste (la clarté du texte affiché), qui augmente dans le sens horaire et diminue dans le sens antihoraire.

**Exemple**

* :ref:`ar_lcd1602` (Projet de base)
* :ref:`ar_serial_read` (Projet de base)
