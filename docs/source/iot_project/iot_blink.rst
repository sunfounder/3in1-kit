.. note:: 

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour perfectionner vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus exclusifs.
    - **Réductions spéciales** : Profitez de remises exclusives sur nos nouveaux produits.
    - **Promotions festives et cadeaux** : Participez à des promotions et des concours pendant les fêtes.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _iot_blink:

2. Récupérer des données de Blynk
======================================

Dans ce chapitre, vous apprendrez à contrôler le circuit avec Blynk. Allumons les LED via Internet !

**Composants nécessaires**

Dans ce projet, nous avons besoin des composants suivants.

Il est beaucoup plus pratique d'acheter un kit complet, voici le lien : 

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nom
        - ARTICLES DANS CE KIT
        - LIEN
    *   - Kit de démarrage 3 en 1
        - 380+
        - |link_3IN1_kit|

Vous pouvez également les acheter séparément avec les liens ci-dessous.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUCTION AU COMPOSANT
        - LIEN D'ACHAT

    *   - :ref:`cpn_uno`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_esp8266`
        - |link_esp8266_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|

**1. Construire le circuit**

.. note::

    Le module ESP8266 nécessite un courant élevé pour un fonctionnement stable. Assurez-vous que la batterie 9V est branchée.

.. image:: img/iot_2_bb.png
    :width: 600
    :align: center

**2. Modifier le tableau de bord**
#. Accédez à l’appareil **Quickstart Device** que vous avez créé précédemment et cliquez sur l’icône **Modifier le tableau de bord**.

    .. image:: img/blynk_edit_dashboard.png

#. Les flux de données permettent aux widgets de Blynk et au code de la carte R3 de se reconnaître.

    .. image:: img/blynk_edit_datastream.png

#. Supprimez tous les flux de données existants de la page des flux de données pour suivre tout le processus de configuration.

    .. image:: img/blynk_edit_datastream_delete.png

#. Créez un flux de données de type **Virtual Pin**, qui sera utilisé pour contrôler la LED via l'interrupteur de Blynk.

    .. image:: img/blynk_edit_virtualpin.png

#. Configurez le **Virtual Pin**. Comme le bouton et la LED ne nécessitent que des états ON et OFF, réglez le TYPE DE DONNÉES sur ``Integer`` et les valeurs MIN et MAX sur ``0`` et ``1``.

    .. image:: img/sp220609_115520.png

#. Accédez à la page **Web Dashboard**.

    .. image:: img/blynk_edit_web_dashboard.png

#. Supprimez les widgets existants.

    .. image:: img/blynk_edit_delete_dashboard.png

#. Faites glisser un widget **interrupteur** depuis la **Widget Box** à gauche.

    .. image:: img/blynk_edit_drag_switch_widget.png

#. Configurez le widget.

    .. image:: img/blynk_edit_edit_widget.png

#. Sélectionnez le flux de données configuré précédemment.

    .. image:: img/sp220609_133741.png

#. Une fois le flux de données sélectionné, quelques paramètres personnalisés apparaissent. Appuyez ensuite sur Enregistrer.

    .. image:: img/sp220609_133950.png

#. Cliquez enfin sur **Enregistrer et appliquer**.

    .. image:: img/sp220609_141733.png

**3. Exécuter le code**

#. Ouvrez le fichier ``2.get_data_from_blynk.ino`` situé dans ``3in1-kit\iot_project\2.get_data_from_blynk``, ou copiez ce code dans l'**Arduino IDE**.

    .. raw:: html
        
        <iframe src=https://create.arduino.cc/editor/sunfounder01/06b187a8-dabf-4866-b38c-742e0446cc3f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Remplacez le ``Template ID``, le ``Device Name`` et le ``Auth Token`` par vos propres informations. Vous devez également entrer le ``ssid`` et le ``password`` de votre réseau WiFi. Pour des tutoriels détaillés, reportez-vous à :ref:`connect_blynk`.

#. Après avoir sélectionné la carte et le port appropriés, cliquez sur le bouton **Téléverser**.

    .. image:: img/2_upload.png

#. Ouvrez le Moniteur Série (définissez le débit en bauds à 115200) et attendez qu'un message de connexion réussie apparaisse.

    .. image:: img/2_ready.png

    .. note::

        Si le message ``ESP is not responding`` apparaît lors de la connexion, suivez ces étapes :

        * Assurez-vous que la batterie 9V est branchée.
        * Réinitialisez le module ESP8266 en connectant la broche RST à GND pendant 1 seconde, puis débranchez-la.
        * Appuyez sur le bouton de réinitialisation de votre carte.

        Vous devrez peut-être répéter ces opérations 3 à 5 fois. Veuillez être patient.

#. De retour sur Blynk, vous pouvez voir que le statut est passé à en ligne, et vous pouvez maintenant utiliser le widget interrupteur sur Blynk pour contrôler la LED connectée à la carte R4.

    .. image:: img/blynk_button_on.png

#. Si vous souhaitez utiliser Blynk sur des appareils mobiles, veuillez consulter :ref:`blynk_mobile`.


**Comment cela fonctionne-t-il ?**

La différence entre le code de ce projet et celui du chapitre précédent :ref:`connect_blynk` réside dans les lignes suivantes :

.. code-block:: arduino

    const int ledPin=6;

    BLYNK_WRITE(V0)
    {
        int pinValue = param.asInt(); // affecte la valeur entrante de la broche V0 à une variable
        // Vous pouvez également utiliser :
        // String i = param.asStr();
        // double d = param.asDouble();
        digitalWrite(ledPin,pinValue);
    }

    void setup()
    {
        pinMode(ledPin,OUTPUT);
    }

Concernant les fonctions ``pinMode`` et ``digitalWrite`` de ledPin, vous en êtes déjà probablement familier, donc elles ne seront pas détaillées ici. Ce qui est important, c'est la fonction ``BLYNK_WRITE(V0)``.

Cette fonction agit lorsque la valeur de ``V0`` change sur Blynk. Blynk.Cloud informe alors votre appareil qu'il écrit sur la **broche virtuelle** V0, permettant à l'appareil d'exécuter une action après réception de cette information.

Nous avons créé le flux de données V0 à l'étape précédente et l'avons appliqué au Widget Interrupteur. Cela signifie qu'à chaque utilisation du Widget Interrupteur, ``BLYNK_WRITE(V0)`` sera déclenchée.

Voici les instructions dans cette fonction :

.. code-block:: arduino

    int pinValue = param.asInt();

Récupère la valeur de V0 et l'assigne à la variable ``pinValue``.

.. code-block:: arduino

    digitalWrite(ledPin,pinValue);

Écrit la valeur de V0 sur ledPin, permettant ainsi au Widget Interrupteur de Blynk de contrôler la LED.
