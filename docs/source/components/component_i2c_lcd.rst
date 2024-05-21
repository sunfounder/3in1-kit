.. note::

    Bonjour et bienvenue dans la Communauté Facebook des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez [|link_sf_facebook|] et rejoignez-nous aujourd'hui !

.. _cpn_i2c_lcd1602:

I2C LCD1602
==============

.. image:: img/i2c_lcd1602.png
    :width: 800

* **GND** : Masse
* **VCC** : Alimentation en tension, 5V.
* **SDA** : Ligne de données série. Connecter à VCC via une résistance de tirage.
* **SCL** : Ligne d'horloge série. Connecter à VCC via une résistance de tirage.

Comme nous le savons tous, bien que les écrans LCD et certains autres affichages enrichissent grandement l'interaction homme-machine, ils partagent une faiblesse commune. Lorsqu'ils sont connectés à un contrôleur, de multiples IOs sont occupés sur le contrôleur qui ne dispose pas de tant de ports externes. Cela limite également d'autres fonctions du contrôleur.

Par conséquent, un LCD1602 avec un module I2C a été développé pour résoudre ce problème. Le module I2C intègre une puce PCF8574 I2C qui convertit les données série I2C en données parallèles pour l'affichage LCD.

* `Fiche technique PCF8574 <https://www.ti.com/lit/ds/symlink/pcf8574.pdf?ts=1627006546204&ref_url=https%253A%252F%252Fwww.google.com%252F>`_

**Adresse I2C**

L'adresse par défaut est généralement 0x27, dans quelques cas, elle peut être 0x3F.

Prenant l'adresse par défaut de 0x27 comme exemple, l'adresse de l'appareil peut être modifiée en court-circuitant les pads A0/A1/A2 ; dans l'état par défaut, A0/A1/A2 est 1, et si le pad est court-circuité, A0/A1/A2 est 0.

.. image:: img/i2c_address.jpg
    :width: 600

**Rétroéclairage/Contraste**

Le rétroéclairage peut être activé par un capuchon de cavalier, retirez le capuchon pour désactiver le rétroéclairage. Le potentiomètre bleu à l'arrière sert à ajuster le contraste (le rapport de luminosité entre le blanc le plus brillant et le noir le plus sombre).

.. image:: img/back_lcd1602.jpg

* **Capuchon de Court-Circuit** : Le rétroéclairage peut être activé par ce capuchon, retirez ce capuchon pour désactiver le rétroéclairage.
* **Potentiomètre** : Il sert à ajuster le contraste (la clarté du texte affiché), qui est augmenté dans le sens des aiguilles d'une montre et diminué dans le sens inverse.

**Exemple**

* :ref:`ar_lcd1602` (Projet de base)
* :ref:`ar_serial_read` (Projet de base)

