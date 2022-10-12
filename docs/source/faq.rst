FAQ
==============

.. _blynk_mobile:

How to use Blynk on mobile device?
--------------------------------------------

.. note::

    As datastreams can only be created in Blynk on the web, you will need to reference different projects to create datastreams on the web, then follow the tutorial below to create widgets in Blynk on your mobile device.


#. Open Google Play or APP Store on your mobile device and search for "Blynk IoT" (not Blynk(legacy)) to download.
#. After opening the APP, login in, this account should be the same as the account used on the web client.
#. Then go to **Dashboard** (if you don't have one, create one) and you will see that the **Dashboard** for mobile and web are independent of each other.

    .. image:: iot_project/img/APP_1.jpg

#. Click **Edit** Icon.
#. Click on the blank area. 
#. Choose the same widget as on the web page, such as select a **Joystick** widget.

    .. image:: iot_project/img/APP_2.jpg

#. Now you will see a **Joystick** widget appear in the blank area, click on it.
#. **Joystick** Settings will appear, select the **Xvalue** and **Yvalue** datastreams you just set in the web page. Note that each widget corresponds to a different datastream in each project.
#. Go back to the **Dashboard** page and you can operate the **Joystick** when you want.

    .. image:: iot_project/img/APP_3.jpg

.. _burn_firmware:

How to re-burn the firmware for ESP8266 module?
-----------------------------------------------------

**1. Build the circuit**

Connect ESP8266 and SunFounder R3 board.

    .. image:: img/connect_esp8266.png
        :width: 800

**2. Burning the firmware**

* Follow the steps below to burn the firmware if you are using **Windows**.

    #. Download firmware and burn-in tool.

        * :download:`ESP8266 Firmware <https://github.com/sunfounder/3in1-kit/raw/main/iot_project/esp8266_firmware.zip>`

    #. After unzipping, you will see 3 files.

        .. image:: img/bat_firmware.png
    
        * ``BAT_AT_V1.7.1.0_1M.bin``: The firmware to burn to the ESP8266 module.
        * ``esptool.exe``: This is a command-line utility for Windows.
        * ``install.bat``: This is the command package for Windows system, double click this file will run all the commands inside the file.

    #. Double click ``install.bat`` to start the firmware burning. If you see the following prompt, the firmware has been installed successfully.

        .. image:: img/install_firmware.png

        .. note::
            If the burn-in fails, please check the following points.

            * Reset the ESP8266 module by inserting the RST on the ESP8266 Adapter to GND and then unplugging it.
            * Check if the wiring is correct.
            * Whether the computer has recognized your board properly, and make sure the port is not occupied.
            * Reopen the install.bat file.

* To burn the firmware, follow these steps if you are using a **Mac OS** system.

    #. Use the following commands to install Esptool. Esptool is a Python-based, open-source, platform-independent utility to communicate with the ROM bootloader in Espressif chips.

        .. code-block::

            python3 -m pip install --upgrade pip
            python3 -m pip install esptool

    #. If esptool is properly installed, it will output a message such as [usage: esptool] if you run ``python3 -m esptool``.

    #. Download firmware.

        * :download:`ESP8266 Firmware <https://github.com/sunfounder/3in1-kit/raw/main/iot_project/esp8266_firmware.zip>`

    #. After unzipping, you will see 3 files.

        .. image:: img/bat_firmware.png

        * ``BAT_AT_V1.7.1.0_1M.bin``: The firmware to burn to the ESP8266 module.
        * ``esptool.exe``: This is a command-line utility for Windows.
        * ``install.bat``: This is the command package for Windows system, double click this file will run all the commands inside the file.

    #. Open a terminal and use the ``cd`` command to go into the firmware folder you just downloaded, then run the following command to erase the existing firmware and re-burn the new firmware.

        .. code-block::

            python3 -m esptool --chip esp8266 --before default_reset erase_flash
            python3 -m esptool --chip esp8266 --before default_reset write_flash 0 "BAT_AT_V1.7.1.0_1M.bin"

    #. If you see the following prompt, the firmware has been installed successfully.

        .. image:: img/install_firmware_macos.png

        .. note::
            If the burn-in fails, please check the following points.

            * Reset the ESP8266 module by inserting the RST on the ESP8266 Adapter to GND and then unplugging it.
            * Check if the wiring is correct.
            * Whether the computer has recognized your board properly, and make sure the port is not occupied.
            * Reopen the install.bat file.

**3. Test**

#. On the basis of the original wiring, connect IO1 to 3V3.

    .. image:: img/connect_esp826612.png
        :width: 800

#. You will be able to see information about the ESP8266 module if you click the magnifying glass icon(Serial Monitor) in the upper right corner and set the baud rate to **115200**.

    .. image:: iot_project/blynk_start/img/sp20220524113020.png

    .. note::

        * If ``ready`` doesn't appear, you can try to reset the ESP8266 module(connect RST to GND) and re-open the Serial Monitor.

#. Click on **NEWLINE DROPDOWN BOX**, select ``both NL & CR`` in the drop down option, enter ``AT``, if it returns OK, it means ESP8266 has successfully established connection with R3 board.

    .. image:: iot_project/blynk_start/img/sp20220524113702.png

Now you can continue to follow :ref:`config_esp8266` to set the working mode and baud rate of the ESP8266 module.