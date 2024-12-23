.. note:: 

    Bonjour et bienvenue dans la communauté Facebook des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions spéciales.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_esp8266:

Module ESP8266
=================

.. image:: img/esp8266.jpg
    :align: center

L'ESP8266 est une puce Wi-Fi à faible coût, 
intégrant un logiciel de mise en réseau TCP/IP, 
et dotée de capacités de microcontrôleur, produite par Espressif Systems à Shanghai, en Chine.

La puce a attiré l'attention des fabricants occidentaux en août 2014 avec le module ESP-01, 
fabriqué par un tiers, Ai-Thinker. 
Ce petit module permet aux microcontrôleurs de se connecter à un réseau Wi-Fi et d'établir des connexions TCP/IP simples à l'aide de commandes de style Hayes. 
Cependant, au début, il n'y avait presque aucune documentation en anglais sur la puce et les commandes acceptées. 
Le prix très bas et le fait qu'il y avait très peu de composants externes sur le module, 
suggérant qu'il pourrait être très peu coûteux à grande échelle, 
ont attiré de nombreux hackers à explorer le module, 
la puce et le logiciel qui l'accompagne, ainsi qu'à traduire la documentation en chinois.

Broches de l'ESP8266 et leurs fonctions :

.. image:: img/ESP8266_pinout.png


.. list-table:: ESP8266-01 Pins
   :widths: 25 25 100
   :header-rows: 1

   * - Broche	
     - Nom	
     - Description
   * - 1	
     - TXD	
     - UART_TXD, émission ; Entrée/Sortie Générale : GPIO1 ; Pas de pull-down autorisé au démarrage.
   * - 2	
     - GND
     - Masse
   * - 3	
     - CU_PD	
     - Fonctionne à haut niveau ; Coupure de l'alimentation à bas niveau.
   * - 4		
     - GPIO2
     - Doit être à haut niveau à l'allumage, pull-down matériel non autorisé ; Pull-up par défaut ;
   * - 5	
     - RST	
     - Signal de réinitialisation externe, réinitialisation à bas niveau ; fonctionnement à haut niveau (haut niveau par défaut) ;
   * - 6	
     - GPIO0	
     - Indicateur d'état WiFi ; Sélection du mode de fonctionnement : Pull-up : Flash Boot, mode opérationnel ; Pull-down : UART Download, mode téléchargement
   * - 7	
     - VCC	
     - Alimentation (3.3V)
   * - 8	
     - RXD	
     - UART_RXD, Réception ; Entrée/Sortie Générale : GPIO3 ;


* `ESP8266 - Espressif <https://www.espressif.com/en/products/socs/esp8266>`_
* `Jeu d'instructions AT ESP8266 <https://github.com/sunfounder/3in1-kit/blob/main/iot_project/esp8266_at_instruction_set_en.pdf>`_

Adaptateur ESP8266
--------------------

.. image:: img/esp8266_adapter.png
    :width: 300
    :align: center

L'adaptateur ESP8266 est une carte d'extension permettant d'utiliser le module ESP8266 sur une breadboard.

Il s'adapte parfaitement aux broches de l'ESP8266 lui-même et ajoute également une broche 5V pour recevoir la tension de la carte Arduino. Le circuit intégré AMS1117 est utilisé pour alimenter le module ESP8266 après avoir abaissé la tension à 3,3 V.

Le schéma suivant illustre l'adaptateur :

.. image:: img/sch_esp8266adapter.png


**Exemple**



* :ref:`iot_projects` (Projet IoT)
