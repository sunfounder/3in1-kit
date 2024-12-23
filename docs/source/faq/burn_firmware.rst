.. note:: 

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour perfectionner vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus exclusifs.
    - **Réductions spéciales** : Profitez de remises exclusives sur nos nouveaux produits.
    - **Promotions festives et cadeaux** : Participez à des promotions et des concours pendant les fêtes.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _burn_firmware:

Comment reprogrammer le firmware pour le module ESP8266 ?
=============================================================

.. Re-brun the Firmware with R4
.. ---------------------------------------

.. **1. Build the circuit**

.. Connect ESP8266 and Arduino UNO R4 board.

..     .. image:: img/faq_at_burn_bb.jpg
..         :width: 800

.. **2. Upload the Following Code to R4**

.. .. code-block:: Arduino

..     void setup() {
..         Serial.begin(115200);
..         Serial1.begin(115200);
..     }

..     void loop() {
..         if (Serial.available()) {      // If anything comes in Serial (USB),
..             Serial1.write(Serial.read());   // read it and send it out Serial1 (pins 0 & 1)
..         }
..             if (Serial1.available()) {     // If anything comes in Serial1 (pins 0 & 1)
..             Serial.write(Serial1.read());   // read it and send it out Serial (USB)
..         }
..     }

..     Then, close the Arduino IDE.

.. **3. Burning the firmware**

.. * Follow the steps below to burn the firmware if you are using **Windows**.

..     #. Download firmware and burn-in tool.

..         * :download:`ESP8266 Firmware <https://github.com/sunfounder/3in1-kit/raw/main/iot_project/esp8266_firmware.zip>`

..     #. After unzipping, you will see 4 files.

..         .. .. image:: img/bat_firmware.png

..         * ``BAT_AT_V1.7.1.0_1M.bin``: The firmware to burn to the ESP8266 module.
..         * ``esptool.exe``: This is a command-line utility for Windows.
..         * ``install_r3.bat``: This is the command package for Windows system, double click this file will run all the commands inside the file.
..         * ``install_r4.bat``: Same as ``install_r3.bat``, but dedicated to UNO R4 board.

..     #. Double click ``install_r4.bat`` to start the firmware burning. If you see the following prompt, the firmware has been installed successfully.

..         .. image:: img/install_firmware.png

.. 
            .. note::
..             If the burn-in fails, please check the following points.

..             * Close the Arduino IED.
..             * Reset the ESP8266 module by inserting the RST on the ESP8266 Adapter to GND and then unplugging it.
..             * Check if the wiring is correct.
..             * Whether the computer has recognized your board properly, and make sure the port is not occupied.
..             * Reopen the install.bat file.

.. * To burn the firmware, follow these steps if you are using a **Mac OS** system.

..     #. Use the following commands to install Esptool. Esptool is a Python-based, open-source, platform-independent utility to communicate with the ROM bootloader in Espressif chips.

.. 
            .. code-block::

..             python3 -m pip install --upgrade pip
..             python3 -m pip install esptool

..     #. If esptool is properly installed, it will output a message such as [usage: esptool] if you run ``python3 -m esptool``.

..     #. Download firmware.

..         * :download:`ESP8266 Firmware <https://github.com/sunfounder/3in1-kit/raw/main/iot_project/esp8266_firmware.zip>`

..     #. After unzipping, you will see 4 files.

..         .. .. image:: img/bat_firmware.png

..         * ``BAT_AT_V1.7.1.0_1M.bin``: The firmware to burn to the ESP8266 module.
..         * ``esptool.exe``: This is a command-line utility for Windows.
..         * ``install_r3.bat``: This is the command package for Windows system.
..         * ``install_r4.bat``: Same as ``install_r3.bat``, but dedicated to UNO R4 board.


..     #. Open a terminal and use the ``cd`` command to go into the firmware folder you just downloaded, then run the following command to erase the existing firmware and re-burn the new firmware.

.. 
            .. code-block::

..             python3 -m esptool --chip esp8266 --before no_reset_no_sync erase_flash
..             python3 -m esptool --chip esp8266 --before no_reset_no_sync write_flash 0 "BAT_AT_V1.7.1.0_1M.bin"

..     #. If you see the following prompt, the firmware has been installed successfully.

..         .. image:: img/install_firmware_macos.png

..
             .. note::
..             If the burn-in fails, please check the following points.

..             * Close the Arduino IED.
..             * Reset the ESP8266 module by inserting the RST on the ESP8266 Adapter to GND and then unplugging it.
..             * Check if the wiring is correct.
..             * Whether the computer has recognized your board properly, and make sure the port is not occupied.
..             * Reopen the install.bat file.

.. **4. Test**

.. #. On the basis of the original wiring, connect IO1 to 3V3.

..     .. image:: img/faq_at_burn_check_bb.jpg
..         :width: 800

.. #. You will be able to see information about the ESP8266 module if you click the magnifying glass icon(Serial Monitor) in the upper right corner and set the baud rate to **115200**.

..     .. image:: img/sp20220524113020.png

..     
    .. note::

        * Si le message ``ready`` n'apparaît pas, réinitialisez le module ESP8266 et rouvrez le Moniteur Série.

.. #. Click on **NEWLINE DROPDOWN BOX**, select ``both NL & CR`` in the drop down option, enter ``AT``, if it returns OK, it means ESP8266 has successfully established connection with your board.

..     .. image:: img/sp20220524113702.png

.. Now you can continue to follow :ref:`config_esp8266` to set the working mode and baud rate of the ESP8266 module.




Reprogrammer le firmware avec la carte R3
------------------------------------------

**1. Construire le circuit**

Connectez le module ESP8266 à la carte SunFounder R3.

    .. image:: img/connect_esp8266.png
        :width: 800

**2. Programmer le firmware**

* Suivez les étapes ci-dessous pour programmer le firmware si vous utilisez **Windows**.

    #. Téléchargez le firmware et l'outil de programmation.

        * :download:`Firmware ESP8266 <https://github.com/sunfounder/3in1-kit/raw/main/iot_project/esp8266_firmware.zip>`

    #. Après décompression, vous verrez 4 fichiers.

        .. .. image:: img/bat_firmware.png
    
        * ``BAT_AT_V1.7.1.0_1M.bin`` : Le firmware à programmer sur le module ESP8266.
        * ``esptool.exe`` : Un utilitaire en ligne de commande pour Windows.
        * ``install_r3.bat`` : Le fichier batch pour Windows, double-cliquez dessus pour exécuter toutes les commandes qu'il contient.
        * ``install_r4.bat`` : Similaire à ``install_r3.bat``, mais dédié à la carte UNO R4.

    #. Double-cliquez sur ``install_r3.bat`` pour démarrer la programmation. Si vous voyez l'invite suivante, le firmware a été installé avec succès.

        .. image:: img/install_firmware.png

        .. note::
            Si la programmation échoue, vérifiez les points suivants :

            * Fermez l'IDE Arduino.
            * Réinitialisez le module ESP8266 en insérant la broche RST sur l'adaptateur ESP8266 à GND, puis débranchez-le.
            * Vérifiez si le câblage est correct.
            * Assurez-vous que votre ordinateur reconnaît correctement votre carte et que le port n'est pas occupé.
            * Rouvrez le fichier ``install.bat``.

* Pour programmer le firmware sur un **Mac OS**, suivez ces étapes.

    #. Installez l'outil Esptool avec les commandes suivantes :

        .. code-block::

            python3 -m pip install --upgrade pip
            python3 -m pip install esptool

    #. Si Esptool est installé correctement, la commande ``python3 -m esptool`` affichera un message comme [usage: esptool].

    #. Téléchargez le firmware.

        * :download:`Firmware ESP8266 <https://github.com/sunfounder/3in1-kit/raw/main/iot_project/esp8266_firmware.zip>`

    #. Après décompression, vous verrez 3 fichiers.

        .. image:: img/bat_firmware.png

        * ``BAT_AT_V1.7.1.0_1M.bin`` : Le firmware à programmer sur le module ESP8266.
        * ``esptool.exe`` : Utilitaire en ligne de commande pour Windows.
        * ``install_r3.bat`` : Le fichier batch pour le système Windows.
        * ``install_r4.bat`` : Identique à ``install_r3.bat``, mais dédié à la carte UNO R4.

    #. Ouvrez un terminal et utilisez la commande ``cd`` pour accéder au dossier du firmware téléchargé, puis exécutez les commandes suivantes pour effacer et reprogrammer le firmware.

        .. code-block::

            python3 -m esptool --chip esp8266 --before default_reset erase_flash
            python3 -m esptool --chip esp8266 --before default_reset write_flash 0 "BAT_AT_V1.7.1.0_1M.bin"

    #. Si vous voyez l'invite suivante, la programmation a été réalisée avec succès.

        .. image:: img/install_firmware_macos.png

        .. note::
            Si l'installation échoue, veuillez vérifier les points suivants :

            * Fermez l'IDE Arduino.
            * Réinitialisez le module ESP8266 en connectant la broche RST de l'adaptateur ESP8266 à GND, puis débranchez-le.
            * Vérifiez si le câblage est correct.
            * Assurez-vous que l'ordinateur reconnaît correctement votre carte et que le port n'est pas occupé.
            * Rouvrez le fichier install.bat.

**3. Tester**

#. En vous basant sur le câblage original, connectez IO1 à 3V3.

    .. image:: img/connect_esp826612.png
        :width: 800

#. Cliquez sur l'icône de la loupe (Moniteur Série) dans l'IDE Arduino et réglez le débit en bauds sur **115200** pour afficher les informations du module ESP8266.

    .. image:: img/sp20220524113020.png

    .. note::

        * Si le message ``ready`` n'apparaît pas, réinitialisez le module ESP8266 et rouvrez le Moniteur Série.

#. Dans le menu déroulant **NEWLINE**, sélectionnez ``both NL & CR``, entrez ``AT``. Si la réponse est ``OK``, cela signifie que la connexion a été établie avec succès.

    .. image:: img/sp20220524113702.png


.. xx .. Now you can continue to follow :ref:`config_esp8266` to set the working mode and baud rate of the ESP8266 module.