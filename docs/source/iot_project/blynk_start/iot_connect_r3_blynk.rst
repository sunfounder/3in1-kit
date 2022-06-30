.. _connect_blynk:

1.4 Connecting the R3 board to Blynk
--------------------------------------------

#. Reconnect the ESP8266 module and R3 board, here the software serial is used, so TX and RX are connected to pins 2 and 3 of R3 board respectively.

    .. image:: img/wiring_23.jpg

#. Open the ``1.connect.ino`` file under the path of ``3in1-kit\iot_project\1.connect``. Or copy this code into **Arduino IDE**.

    .. raw:: html
        
        <iframe src=https://create.arduino.cc/editor/sunfounder01/1c0c1a8f-2551-484f-9f4f-d5d4117cc864/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Replace the following three lines of code that you can copy from your account's **Device info** page. These three lines of code will allow your R3 board to find your blynk account.

    .. code-block:: arduino

        #define BLYNK_TEMPLATE_ID "TMPLxxxxxx"
        #define BLYNK_DEVICE_NAME "Device"
        #define BLYNK_AUTH_TOKEN "YourAuthToken"
    
    .. image:: img/sp20220614174721.png

#. Fill in the ``ssid`` and ``password`` of the WiFi you are using.

    .. code-block:: arduino

        char ssid[] = "ssid";
        char pass[] = "password";

#. Connect 9V power supply for R3 board, this is because ESP8266 needs higher current to provide stable working environment when it is connected to internet.

#. Upload the code to the R3 board, then open the serial monitor and set the baud rate to 115200. when the R3 board communicates with Blynk successfully, the serial monitor will show the ``ready`` character.

    .. image:: img/sp220607_170223.png

    .. note::

        If ``ESP is not responding`` prompt appears when connecting, please check if the 9V power connection is normal, and try to reset the ESP8266 module by connecting the pin RST to GND for about 1 second and then unplug it, and then turn on the serial monitor again.

#. The status of Blynk will change from **offline** to **online**.

    .. image:: img/sp220607_170326.png
