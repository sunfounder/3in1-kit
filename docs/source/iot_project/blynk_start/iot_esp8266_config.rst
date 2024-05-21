.. note::

    Bonjour et bienvenue dans la Communauté Facebook des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez [|link_sf_facebook|] et rejoignez-nous aujourd'hui !

.. _config_esp8266:

1.1 Configuration de l'ESP8266
===============================

Le module ESP8266 fourni avec le kit est déjà préchargé avec le firmware AT, mais vous devez tout de même modifier sa configuration en suivant les étapes ci-dessous.


1. Construisez le circuit.

    .. image:: img/iot_1_at_set_bb.jpg
        :width: 800

2. Ouvrez le fichier ``1.set_software_serial.ino`` situé dans le dossier ``3in1-kit\iot_project\1.set_software_serial``. Ou copiez ce code dans **Arduino IDE**.

    .. code-block:: Arduino

        #include <SoftwareSerial.h>
        SoftwareSerial espSerial(2, 3); //Rx,Tx

        void setup() {
            // put your setup code here, to run once:
            Serial.begin(115200);
            espSerial.begin(115200);
        }

        void loop() {
            if (espSerial.available()) {
                Serial.write(espSerial.read());
            }
            if (Serial.available()) {
                espSerial.write(Serial.read());
            }
        }


3. Cliquez sur l'icône de la loupe (Moniteur Série) dans le coin supérieur droit et réglez le débit en bauds sur **115200**. (Vous pourriez avoir des informations imprimées comme moi, ou pas, cela n'a pas d'importance, passez simplement à l'étape suivante.)

    .. image:: img/sp20220524113020.png

    .. warning::
        
        * Si ``ready`` n'apparaît pas, vous pouvez essayer de réinitialiser le module ESP8266 (connecter RST à GND) et rouvrir le Moniteur Série.

        * De plus, si le résultat est ``OK``, vous devrez peut-être reprogrammer le firmware, veuillez vous référer à :ref:`burn_firmware` pour plus de détails. Si vous ne parvenez toujours pas à résoudre le problème, veuillez prendre une capture d'écran du moniteur série et l'envoyer à sevice@sunfounder.com, nous vous aiderons à résoudre le problème dès que possible.

4. Cliquez sur **NEWLINE DROPDOWN BOX**, sélectionnez ``both NL & CR`` dans les options déroulantes, entrez ``AT``, si cela retourne OK, cela signifie que l'ESP8266 a établi une connexion réussie avec la carte R3.

    .. image:: img/sp20220524113702.png

5. Entrez ``AT+CWMODE=3`` et le mode géré sera changé en **Station et AP** coexistant.

    .. image:: img/sp20220524114032.png

6. Afin d'utiliser le serial logiciel plus tard, vous devez entrer ``AT+UART=9600,8,1,0,0`` pour modifier le débit en bauds de l'ESP8266 à 9600.

    .. image:: img/PIC4_sp220615_150321.png

.. 7. Changez maintenant le débit en bauds du moniteur série à 9600, essayez d'entrer ``AT``, si cela retourne OK, cela signifie que le réglage est réussi.


..     .. image:: img/PIC5_sp220615_150431.png


