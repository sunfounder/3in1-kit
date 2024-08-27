.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _connect_blynk:

1.3 Connecting the R3 board to Blynk
=======================================

#. Reconnect the ESP8266 module and R3 board, here the software serial is used, so TX and RX are connected to pins 2 and 3 of R3 board respectively.

    .. note::

        The ESP8266 module requires a high current to provide a stable operating environment, so make sure the 9V battery is plugged in.

    .. image:: img/wiring_23.jpg


#. Click the **devices** page and you will see the new device you just created. Then, click developer tools.

    .. image:: img/blynk_copy_developer.png

#. And you will see ``TEMPLATE_ID``, ``DEVICE_NAME`` and ``AUTH_TOKEN`` on the **Firmware info**, and you will need to copy them later.


    .. image:: img/blynk_copy_firmwareinfo.png

#. Open the ``1.connect.ino`` file under the path of ``3in1-kit\iot_project\1.connect``. Or copy this code into **Arduino IDE**.

    .. raw:: html
        
        <iframe src=https://create.arduino.cc/editor/sunfounder01/1c0c1a8f-2551-484f-9f4f-d5d4117cc864/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


#. Replace the following three lines of code that you can copy from your account's **Firmware info**  These three lines of code will allow your R3 board to find your blynk account.

    .. code-block:: arduino

        #define BLYNK_TEMPLATE_ID "TMPLxxxxxx"
        #define BLYNK_DEVICE_NAME "Device"
        #define BLYNK_AUTH_TOKEN "YourAuthToken"

#. Fill in the ``ssid`` and ``password`` of the WiFi you are using.

    .. code-block:: arduino

        char ssid[] = "ssid";
        char pass[] = "password";

#. Upload the code to the R3 board, then open the serial monitor and set the baud rate to 115200. when the R3 board communicates with Blynk successfully, the serial monitor will show the ``ready`` character.

    .. image:: img/blynk_connect_network.png

    .. note::
    
        If the message ``ESP is not responding`` appears when you connect, please follow these steps.

        * Make sure the 9V battery is plugged in.
        * Reset the ESP8266 module by connecting the pin RST to GND for 1 second, then unplug it.
        * Press the reset button on the R3 board.

        Sometimes, you may need to repeat the above operation 3-5 times, please be patient.

#. The status of Blynk will change from **offline** to **online**.

    .. image:: img/sp220607_170326.png
