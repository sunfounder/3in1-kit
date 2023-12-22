.. _cpn_esp8266:

Module ESP8266
=================

.. image:: img/esp8266.jpg
    :align: center

L'ESP8266 est une puce Wi-Fi à bas coût, 
dotée d'un logiciel de réseau TCP/IP intégré, 
et d'une capacité de microcontrôleur, produite par Espressif Systems à Shanghai, Chine.

La puce a attiré l'attention des créateurs occidentaux pour la première fois en août 2014 avec le module ESP-01, 
fabriqué par un fabricant tiers Ai-Thinker. 
Ce petit module permet aux microcontrôleurs de se connecter à un réseau Wi-Fi et d'établir des connexions TCP/IP simples en utilisant des commandes de style Hayes. 
Cependant, au début, il y avait presque aucune documentation en anglais sur la puce et les commandes qu'elle acceptait. 
Le prix très bas et le fait qu'il y avait très peu de composants externes sur le module, 
ce qui suggérait qu'il pourrait éventuellement être très bon marché en volume, 
ont attiré de nombreux hackers à explorer le module, 
la puce, et le logiciel qui y est installé, ainsi qu'à traduire la documentation chinoise.

Broches de l'ESP8266 et leurs fonctions :

.. image:: img/ESP8266_pinout.png


.. list-table:: Broches ESP8266-01
   :widths: 25 25 100
   :header-rows: 1

   * - Broche	
     - Nom	
     - Description
   * - 1	
     - TXD	
     - UART_TXD, émission ; Entrée/Sortie Générale : GPIO1 ; Il est interdit de tirer vers le bas lors du démarrage.
   * - 2	
     - GND
     - GND
   * - 3	
     - CU_PD	
     - Fonctionne à un niveau élevé ; S'éteint lorsque un niveau bas est fourni.
   * - 4		
     - GPIO2
     - Doit être à un niveau élevé lors de la mise sous tension, le tirage vers le bas matériel est interdit ; Tiré vers le haut par défaut;
   * - 5	
     - RST	
     - Signal de réinitialisation externe, réinitialisation lorsque un niveau bas est fourni ; fonctionne lorsqu'un niveau élevé est fourni (niveau élevé par défaut) ;
   * - 6	
     - GPIO0	
     - Indicateur d'état WiFi ; Sélection du mode de fonctionnement : Tiré vers le haut : Démarrage Flash, mode de fonctionnement ; Tiré vers le bas : Téléchargement UART, mode de téléchargement
   * - 7	
     - VCC	
     - Alimentation électrique (3.3V)
   * - 8	
     - RXD	
     - UART_RXD, réception ; Entrée/Sortie Générale : GPIO3;


* `ESP8266 - Espressif <https://www.espressif.com/en/products/socs/esp8266>`_
* `Ensemble d'instructions AT ESP8266 <https://github.com/sunfounder/3in1-kit/blob/main/iot_project/esp8266_at_instruction_set_en.pdf>`_

Adaptateur ESP8266
---------------------

.. image:: img/esp8266_adapter.png
    :width: 300
    :align: center

L'adaptateur ESP8266 est une carte d'extension qui permet d'utiliser le module ESP8266 sur une breadboard.

Il correspond parfaitement aux broches de l'ESP8266 lui-même, et ajoute également une broche 5V pour recevoir la tension de la carte Arduino. Le chip AMS1117 intégré est utilisé pour alimenter le module ESP8266 après avoir réduit la tension à 3.3V.

Le schéma est le suivant :

.. image:: img/sch_esp8266adapter.png


**Exemple**

* :ref:`iot_projects` (Projet IoT)
