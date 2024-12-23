.. note:: 

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez plus profondément dans le monde de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Obtenez un accès anticipé aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions spéciales** : Profitez de remises exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des promotions et concours pendant les fêtes.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _connect_blynk:

1.3 Connexion de la carte R4 à Blynk
=======================================

#. Reconnectez le module ESP8266 et la carte R4. Ici, le port série logiciel est utilisé, donc les broches TX et RX sont respectivement connectées aux broches 2 et 3 de la carte R4.

    .. note::

        Le module ESP8266 nécessite un courant élevé pour fournir un environnement de fonctionnement stable. Assurez-vous donc que la batterie 9V est branchée.

    .. image:: img/iot_1.4_bb.png



#. Cliquez sur la page **devices**, et vous verrez le nouvel appareil que vous venez de créer. Ensuite, cliquez sur **developer tools**.

    .. image:: img/blynk_copy_developer.png

#. Vous verrez alors ``TEMPLATE_ID``, ``DEVICE_NAME`` et ``AUTH_TOKEN`` dans les **Firmware info**, que vous devrez copier plus tard.

    .. image:: img/blynk_copy_firmwareinfo.png

#. Ouvrez le fichier ``1.connect.ino`` situé dans le répertoire ``3in1-kit\iot_project\1.connect`` ou copiez ce code dans l'**Arduino IDE**.

    .. raw:: html
        
        <iframe src=https://create.arduino.cc/editor/sunfounder01/1c0c1a8f-2551-484f-9f4f-d5d4117cc864/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Remplacez les trois lignes de code suivantes que vous pouvez copier depuis les **Firmware info** de votre compte. Ces trois lignes de code permettront à votre carte R4 de se connecter à votre compte Blynk.

    .. code-block:: arduino

        #define BLYNK_TEMPLATE_ID "TMPLxxxxxx"
        #define BLYNK_DEVICE_NAME "Device"
        #define BLYNK_AUTH_TOKEN "YourAuthToken"

#. Remplissez les champs ``ssid`` et ``password`` avec le WiFi que vous utilisez.

    .. code-block:: arduino

        char ssid[] = "ssid";
        char pass[] = "password";

#. Téléversez le code sur la carte R4, puis ouvrez le moniteur série et réglez le débit en bauds à 115200. Lorsque la carte R4 communique avec succès avec Blynk, le moniteur série affichera le message ``ready``.

    .. image:: img/blynk_connect_network.png


    .. note::

        Si le message ``ESP is not responding`` apparaît lors de la connexion, suivez ces étapes :

        * Assurez-vous que la batterie 9V est branchée.
        * Réinitialisez le module ESP8266 en connectant la broche RST à GND pendant 1 seconde, puis débranchez-la.
        * Appuyez sur le bouton de réinitialisation de la carte R4.

        Parfois, il peut être nécessaire de répéter les opérations ci-dessus 3 à 5 fois. Merci de faire preuve de patience.

#. Le statut de Blynk passera de **offline** à **online**.

    .. image:: img/sp220607_170326.png
