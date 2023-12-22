.. _connect_blynk:

1.4 Connexion de la carte R3 à Blynk
--------------------------------------------

#. Reconnectez le module ESP8266 et la carte R3, ici le serial logiciel est utilisé, donc TX et RX sont connectés respectivement aux broches 2 et 3 de la carte R3.

    .. note::

        Le module ESP8266 nécessite un courant élevé pour fournir un environnement de fonctionnement stable, donc assurez-vous que la batterie 9V est branchée.

    .. image:: img/wiring_23.jpg

#. Ouvrez le fichier ``1.connect.ino`` situé dans le dossier ``3in1-kit\iot_project\1.connect``. Ou copiez ce code dans **Arduino IDE**.

    .. raw:: html
        
        <iframe src=https://create.arduino.cc/editor/sunfounder01/1c0c1a8f-2551-484f-9f4f-d5d4117cc864/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Remplacez les trois lignes de code suivantes que vous pouvez copier depuis la page **Device info** de votre compte. Ces trois lignes de code permettront à votre carte R3 de trouver votre compte blynk.

    .. code-block:: arduino

        #define BLYNK_TEMPLATE_ID "TMPLxxxxxx"
        #define BLYNK_DEVICE_NAME "Device"
        #define BLYNK_AUTH_TOKEN "YourAuthToken"
    
    .. image:: img/sp20220614174721.png

#. Remplissez le ``ssid`` et le ``password`` du WiFi que vous utilisez.

    .. code-block:: arduino

        char ssid[] = "ssid";
        char pass[] = "password";

#. Téléchargez le code sur la carte R3, puis ouvrez le moniteur série et réglez le débit en bauds sur 115200. Lorsque la carte R3 communique avec Blynk avec succès, le moniteur série affichera le caractère ``ready``.

    .. image:: img/sp220607_170223.png

    .. note::
    
        Si le message ``ESP is not responding`` apparaît lorsque vous vous connectez, veuillez suivre ces étapes.

        * Assurez-vous que la batterie 9V est branchée.
        * Réinitialisez le module ESP8266 en connectant la broche RST à GND pendant 1 seconde, puis débranchez-la.
        * Appuyez sur le bouton de réinitialisation de la carte R3.

        Parfois, il peut être nécessaire de répéter l'opération ci-dessus 3 à 5 fois, veuillez être patient.

#. Le statut de Blynk passera de **offline** à **online**.

    .. image:: img/sp220607_170326.png

