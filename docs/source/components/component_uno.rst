.. note:: 

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions spéciales.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_uno:



Arduino Uno R4 Minima
=================================

**Vue d'ensemble**

Améliorée et perfectionnée, l'Arduino UNO R4 Minima est équipée d'un puissant microcontrôleur 32 bits fourni par Renesas. Préparez-vous à une puissance de traitement accrue, une mémoire élargie et une nouvelle gamme de périphériques intégrés. Le meilleur dans tout ça ? La compatibilité avec les shields et accessoires existants reste intacte, sans modification du facteur de forme standard ni de la tension de fonctionnement de 5 V.

S'intégrant parfaitement à l'écosystème Arduino, l'UNO R4 est une alliée de confiance pour les débutants comme pour les amateurs d'électronique chevronnés. Que vous débutiez ou cherchiez à repousser les limites de vos projets, cette carte robuste offre des performances fiables à chaque fois.

.. image:: img/uno_r4.png

Voici ce que l'UNO R4 Minima vous apporte :

* Compatibilité matérielle avec le facteur de forme UNO : L'UNO R4 Minima conserve le même facteur de forme, le même brochage et la même tension de fonctionnement de 5 V que son prédécesseur, l'UNO R3. Cela garantit une transition fluide pour les shields et projets existants, en tirant parti de l'écosystème étendu et unique déjà établi pour l'Arduino UNO.
* Mémoire élargie et horloge plus rapide : Préparez-vous à des calculs plus précis et à la possibilité de gérer facilement des projets complexes. L'UNO R4 Minima offre une mémoire accrue et une vitesse d'horloge plus rapide, vous permettant de relever des défis exigeants sans effort.
* Périphériques intégrés supplémentaires : L'UNO R4 Minima introduit une gamme de périphériques intégrés, y compris un DAC 12 bits, un CAN BUS et un OP AMP. Ces composants supplémentaires vous offrent des capacités et une flexibilité accrues dans vos conceptions.
* Tolérance étendue à 24 V : L'UNO R4 Minima prend désormais en charge une plage de tension d'entrée plus large, permettant des alimentations allant jusqu'à 24 V. Cela permet une intégration transparente avec des moteurs, des bandes LED et d'autres actionneurs, simplifiant vos projets en utilisant une seule source d'alimentation.
* Connecteur SWD : Le débogage est un aspect critique de tout projet. Connectez simplement un débogueur externe à l'UNO R4 Minima pour surveiller facilement le fonctionnement interne de votre système. Gardez le contrôle et obtenez des informations précieuses.
* Support HID : L'UNO R4 Minima est dotée d'un support HID (Human Interface Device) intégré, lui permettant de simuler une souris ou un clavier lorsqu'elle est connectée à un ordinateur via un câble USB. Cette fonctionnalité pratique simplifie l'envoi de frappes et de mouvements de souris à un ordinateur, améliorant ainsi la convivialité et les fonctionnalités.

**Spécifications techniques**

* Carte :
    * Nom : Arduino® UNO R4 Minima
    * SKU : ABX00080
* Microcontrôleur : Renesas RA4M1 (Arm® Cortex®-M4)
* USB : Port de programmation USB-C®
* Broches :
    * Broches d'entrée/sortie numériques : 14
    * Broches d'entrée analogique : 6
    * DAC : 1
    * Broches PWM : 6
* Communication :
    * UART : Oui, 1x
    * I2C : Oui, 1x
    * SPI : Oui, 1x
    * CAN : Oui, 1x CAN Bus
* Alimentation :
    * Tension de fonctionnement du circuit : 5 V
    * Tension d'entrée (VIN) : 6-24 V
    * Courant DC par broche I/O : 8 mA
* Vitesse d'horloge principale : 48 MHz
* Mémoire : RA4M1 256 kB Flash, 32 kB RAM
* Dimensions :
    * Largeur : 68,85 mm
    * Longueur : 53,34 mm

**Schéma des broches**

.. image:: img/uno_r4_pinsout.png
    :width: 800

* |link_r4_datasheet|
* |link_r4_schematic|
* |link_r4_doc|


.. SunFounder R4 Board
.. ===========================

.. .. image:: img/uno_r3.jpg
..     :width: 600
..     :align: center

.. .. note::

..     The SunFounder R4 board is a mainboard with almost the same functions as the `Arduino Uno <https://store.arduino.cc/products/arduino-uno-rev3/>`_, and the two boards can be used interchangeably.

.. SunFounder R4 board is a microcontroller board based on the ATmega328P (`datasheet <http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf>`_). It has 14 digital input/output pins (of which 6 can be used as PWM outputs), 6 analog inputs, a 16 MHz ceramic resonator (CSTCE16M0V53-R0), a USB connection, a power jack, an ICSP header and a reset button. It contains everything needed to support the microcontroller; simply connect it to a computer with a USB cable or power it with a AC-to-DC adapter or battery to get started.

.. **Technical Parameters**

.. .. image:: img/uno.jpg
..     :align: center

.. * MICROCONTROLLER: ATmega328P
.. * OPERATING VOLTAGE: 5V
.. * INPUT VOLTAGE (RECOMMENDED): 7-12V
.. * INPUT VOLTAGE (LIMIT): 6-20V
.. * DIGITAL I/O PINS: 14 (0-13, of which 6 provide PWM output(3, 5, 6, 9-11))
.. * PWM DIGITAL I/O PINS: 6 (3, 5, 6, 9-11)
.. * ANALOG INPUT PINS: 6 (A0-A5)
.. * DC CURRENT PER I/O PIN: 20 mA
.. * DC CURRENT FOR 3.3V PIN: 50 mA
.. * FLASH MEMORY: 32 KB (ATmega328P) of which 0.5 KB used by bootloader
.. * SRAM: 2 KB (ATmega328P)
.. * EEPROM: 1 KB (ATmega328P)
.. * CLOCK SPEED: 16 MHz
.. * LED_BUILTIN: 13
.. * LENGTH: 68.6 mm
.. * WIDTH: 53.4 mm
.. * WEIGHT: 25 g
.. * I2C Port: A4(SDA), A5(SCL)


.. **What's More**

.. * `Arduino IDE <https://www.arduino.cc/en/software>`_
.. * `Arduino Programming Language Reference <https://www.arduino.cc/reference/en/>`_
.. * :ref:`install_arduino`
.. * `ATmega328P Datasheet <http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf>`_

