.. _burn_firmware:

Comment re-graver le firmware pour le module ESP8266 ?
=========================================================


Re-graver le Firmware avec R3
---------------------------------------

**1. Construire le circuit**

Connectez le module ESP8266 et la carte SunFounder R3.

    .. image:: img/connect_esp8266.png
        :width: 800

**2. Graver le firmware**

* Suivez les étapes ci-dessous pour graver le firmware si vous utilisez **Windows**.

    #. Téléchargez le firmware et l'outil de gravure.

        * :download:`Firmware ESP8266 <https://github.com/sunfounder/3in1-kit/raw/main/iot_project/esp8266_firmware.zip>`

    #. Après décompression, vous verrez 4 fichiers.

        .. .. image:: img/bat_firmware.png
    
        * ``BAT_AT_V1.7.1.0_1M.bin`` : Le firmware à graver sur le module ESP8266.
        * ``esptool.exe`` : C'est un utilitaire en ligne de commande pour Windows.
        * ``install_r3.bat`` : C'est le package de commandes pour le système Windows, double-cliquez sur ce fichier pour exécuter toutes les commandes à l'intérieur.
        * ``install_r4.bat`` : Identique à ``install_r3.bat``, mais dédié à la carte UNO R4.

    #. Double-cliquez sur ``install_r3.bat`` pour démarrer la gravure du firmware. Si vous voyez l'invite suivante, le firmware a été installé avec succès.

        .. image:: img/install_firmware.png

        .. note::
            Si la gravure échoue, veuillez vérifier les points suivants.

            * Réinitialisez le module ESP8266 en insérant le RST sur l'adaptateur ESP8266 à GND puis en le débranchant.
            * Vérifiez si le câblage est correct.
            * Si l'ordinateur a correctement reconnu votre carte, et assurez-vous que le port n'est pas occupé.
            * Rouvrez le fichier install.bat.

* Pour graver le firmware, suivez ces étapes si vous utilisez un système **Mac OS**.

    #. Utilisez les commandes suivantes pour installer Esptool. Esptool est un utilitaire basé sur Python, open source et indépendant de la plateforme pour communiquer avec le bootloader ROM dans les puces Espressif.

        .. code-block::

            python3 -m pip install --upgrade pip
            python3 -m pip install esptool

    #. Si esptool est correctement installé, il affichera un message tel que [usage: esptool] si vous exécutez ``python3 -m esptool``.

    #. Téléchargez le firmware.

        * :download:`Firmware ESP8266 <https://github.com/sunfounder/3in1-kit/raw/main/iot_project/esp8266_firmware.zip>`

    #. Après décompression, vous verrez 3 fichiers.

        .. image:: img/bat_firmware.png

        * ``BAT_AT_V1.7.1.0_1M.bin`` : Le firmware à graver sur le module ESP8266.
        * ``esptool.exe`` : C'est un utilitaire en ligne de commande pour Windows.
        * ``install_r3.bat`` : C'est le package de commandes pour le système Windows.
        * ``install_r4.bat`` : Identique à ``install_r3.bat``, mais dédié à la carte UNO R4.


    #. Ouvrez un terminal et utilisez la commande ``cd`` pour aller dans le dossier de firmware que vous venez de télécharger, puis exécutez la commande suivante pour effacer le firmware existant et re-graver le nouveau firmware.

        .. code-block::

            python3 -m esptool --chip esp8266 --before default_reset erase_flash
            python3 -m esptool --chip esp8266 --before default_reset write_flash 0 "BAT_AT_V1.7.1.0_1M.bin"

    #. Si vous voyez l'invite suivante, le firmware a été installé avec succès.

        .. image:: img/install_firmware_macos.png

        .. note::
            Si la gravure échoue, veuillez vérifier les points suivants.

            * Réinitialisez le module ESP8266 en insérant le RST sur l'adaptateur ESP8266 à GND puis en le débranchant.
            * Vérifiez si le câblage est correct.
            * Si l'ordinateur a correctement reconnu votre carte, et assurez-vous que le port n'est pas occupé.
            * Rouvrez le fichier install.bat.

**3. Test**

#. Sur la base du câblage original, connectez IO1 à 3V3.

    .. image:: img/connect_esp826612.png
        :width: 800

#. Vous pourrez voir des informations sur le module ESP8266 si vous cliquez sur l'icône de la loupe (Moniteur Série) dans le coin supérieur droit et réglez le débit en bauds sur **115200**.

    .. image:: img/sp20220524113020.png

    .. note::

        * Si ``ready`` n'apparaît pas, vous pouvez essayer de réinitialiser le module ESP8266 (connectez RST à GND) et rouvrir le Moniteur Série.

#. Cliquez sur **NEWLINE DROPDOWN BOX**, sélectionnez ``both NL & CR`` dans l'option déroulante, entrez ``AT``, si cela retourne OK, cela signifie que l'ESP8266 a établi avec succès une connexion avec la carte R3.

    .. image:: img/sp20220524113702.png

Maintenant, vous pouvez continuer à suivre :ref:`config_esp8266` pour régler le mode de travail et le débit en bauds du module ESP8266.



Re-graver le Firmware avec R4
---------------------------------------



**1. Construire le circuit**

Connectez ESP8266 et la carte Arduino UNO R4.

    .. image:: img/faq_at_burn_bb.jpg
        :width: 800

**2. Téléversez le Code Suivant sur R4**

.. code-block:: Arduino

    void setup() {
        Serial.begin(115200);
        Serial1.begin(115200);
    }

    void loop() {
        if (Serial.available()) {      // If anything comes in Serial (USB),
            Serial1.write(Serial.read());   // read it and send it out Serial1 (pins 0 & 1)
        }
            if (Serial1.available()) {     // If anything comes in Serial1 (pins 0 & 1)
            Serial.write(Serial1.read());   // read it and send it out Serial (USB)
        }
    }

**3. Graver le firmware**

* Suivez les étapes ci-dessous pour graver le firmware si vous utilisez **Windows**.

    #. Téléchargez le firmware et l'outil de gravure.

        * :download:`Firmware ESP8266 <https://github.com/sunfounder/3in1-kit/raw/main/iot_project/esp8266_firmware.zip>`

    #. Après décompression, vous verrez 4 fichiers.

        .. .. image:: img/bat_firmware.png
    
        * ``BAT_AT_V1.7.1.0_1M.bin`` : Le firmware à graver sur le module ESP8266.
        * ``esptool.exe`` : C'est un utilitaire en ligne de commande pour Windows.
        * ``install_r3.bat`` : C'est le package de commandes pour le système Windows, double-cliquez sur ce fichier pour exécuter toutes les commandes à l'intérieur.
        * ``install_r4.bat`` : Identique à ``install_r3.bat``, mais dédié à la carte UNO R4.

    #. Double-cliquez sur ``install_r4.bat`` pour commencer la gravure du firmware. Si vous voyez l'invite suivante, le firmware a été installé avec succès.

        .. image:: img/install_firmware.png

        .. note::
            Si la gravure échoue, veuillez vérifier les points suivants.

            * Réinitialisez le module ESP8266 en insérant le RST sur l'adaptateur ESP8266 à GND puis en le débranchant.
            * Vérifiez si le câblage est correct.
            * Si l'ordinateur a correctement reconnu votre carte, et assurez-vous que le port n'est pas occupé.
            * Rouvrez le fichier install.bat.

* Pour graver le firmware, suivez ces étapes si vous utilisez un système **Mac OS**.

    #. Utilisez les commandes suivantes pour installer Esptool. Esptool est un utilitaire basé sur Python, open source et indépendant de la plateforme pour communiquer avec le bootloader ROM des puces Espressif.

        .. code-block::

            python3 -m pip install --upgrade pip
            python3 -m pip install esptool

    #. Si esptool est correctement installé, il affichera un message tel que [usage: esptool] si vous exécutez ``python3 -m esptool``.

    #. Téléchargez le firmware.

        * :download:`Firmware ESP8266 <https://github.com/sunfounder/3in1-kit/raw/main/iot_project/esp8266_firmware.zip>`

    #. Après décompression, vous verrez 4 fichiers.

        .. .. image:: img/bat_firmware.png

        * ``BAT_AT_V1.7.1.0_1M.bin`` : Le firmware à graver sur le module ESP8266.
        * ``esptool.exe`` : C'est un utilitaire en ligne de commande pour Windows.
        * ``install_r3.bat`` : C'est le package de commandes pour le système Windows.
        * ``install_r4.bat`` : Identique à ``install_r3.bat``, mais dédié à la carte UNO R4.


    #. Ouvrez un terminal et utilisez la commande ``cd`` pour aller dans le dossier de firmware que vous venez de télécharger, puis exécutez la commande suivante pour effacer le firmware existant et re-graver le nouveau firmware.

        .. code-block::

            python3 -m esptool --chip esp8266 --before no_reset_no_sync erase_flash
            python3 -m esptool --chip esp8266 --before no_reset_no_sync write_flash 0 "BAT_AT_V1.7.1.0_1M.bin"

    #. Si vous voyez l'invite suivante, le firmware a été installé avec succès.

        .. image:: img/install_firmware_macos.png

        .. note::
            Si la gravure échoue, veuillez vérifier les points suivants.

            * Réinitialisez le module ESP8266 en insérant le RST sur l'adaptateur ESP8266 à GND puis en le débranchant.
            * Vérifiez si le câblage est correct.
            * Si l'ordinateur a correctement reconnu votre carte, et assurez-vous que le port n'est pas occupé.
            * Rouvrez le fichier install.bat.

**4. Test**

#. Sur la base du câblage original, connectez IO1 à 3V3.

    .. image:: img/faq_at_burn_check_bb.jpg
        :width: 800

#. Vous pourrez voir des informations sur le module ESP8266 si vous cliquez sur l'icône de la loupe (Moniteur Série) dans le coin supérieur droit et réglez le débit en bauds sur **115200**.

    .. image:: img/sp20220524113020.png

    .. note::

        * Si ``ready`` n'apparaît pas, vous pouvez essayer de réinitialiser le module ESP8266 (connectez RST à GND) et rouvrir le Moniteur Série.

#. Cliquez sur **NEWLINE DROPDOWN BOX**, sélectionnez ``both NL & CR`` dans l'option déroulante, entrez ``AT``, si cela retourne OK, cela signifie que l'ESP8266 a établi avec succès une connexion avec votre carte.

    .. image:: img/sp20220524113702.png

Maintenant, vous pouvez continuer à suivre :ref:`config_esp8266` pour régler le mode de travail et le débit en bauds du module ESP8266.



