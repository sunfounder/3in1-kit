.. note::

    Bonjour et bienvenue dans la Communauté Facebook des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez [|link_sf_facebook|] et rejoignez-nous aujourd'hui !

.. _iot_blink:

2. Obtenir des Données depuis Blynk
=======================================

Dans ce chapitre, vous apprendrez à contrôler le circuit avec Blynk. Allumons les LED via Internet !

**Composants Requis**

Pour ce projet, nous avons besoin des composants suivants.

Il est certainement pratique d'acheter un kit complet, voici le lien :

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nom	
        - ÉLÉMENTS DANS CE KIT
        - LIEN
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

Vous pouvez également les acheter séparément via les liens ci-dessous.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUCTION DES COMPOSANTS
        - LIEN D'ACHAT

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
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

**1. Construire le Circuit**

.. note::

    Le module ESP8266 nécessite un courant élevé pour fournir un environnement de fonctionnement stable, donc assurez-vous que la batterie 9V est branchée.

.. image:: img/wiring_led.jpg

**2. Éditer le Tableau de Bord**

#. Allez sur le **Quickstart Device** que vous avez créé précédemment, cliquez sur l'icône du menu en haut à droite et sélectionnez **edit dashboard**.

    .. image:: img/sp220609_112825.png

#. Les Datastreams permettent aux widgets sur Blynk et au code sur la carte R3 de se reconnaître mutuellement. Pour expérimenter le processus de configuration complet, supprimez tous les Datastreams de la page Datastreams.

    .. image:: img/sp220609_114723.png

#. Veuillez lire attentivement l'avertissement et confirmer qu'il est correct avant de supprimer les Datastreams.

    .. image:: img/sp220609_114929.png

#. Créez un Datastream de type **Virtual Pin**, qui sera utilisé pour contrôler la LED en utilisant l'interrupteur Blynk.

    .. image:: img/sp220609_115124.png


#. Configurez le **Virtual Pin**. Comme le bouton et la LED n'ont besoin que d'être ON et OFF, réglez DATA TYPE sur ``Integer`` et MIN et MAX sur ``0`` et ``1``. 

    .. image:: img/sp220609_115520.png

#. Allez sur la page **Web Dashboard** et supprimez les widgets existants.

    .. image:: img/sp220609_133707.png

#. Faites glisser et déposez un widget **switch** depuis la **Widget Box** à gauche.

    .. image:: img/sp220609_114508.png

#. Maintenant pour le configurer.

    .. image:: img/sp20220615180127.png

#. Sélectionnez **Datastream** comme celui que vous avez configuré précédemment.

    .. image:: img/sp220609_133741.png

#. Après avoir sélectionné Datastream, vous verrez quelques paramètres personnalisés, puis appuyez sur Enregistrer.

    .. image:: img/sp220609_133950.png

#. Enfin, cliquez sur **Save And Apply**.

    .. image:: img/sp220609_141733.png

**3. Exécutez le Code**

#. Ouvrez le fichier ``2.get_data_from_blynk.ino`` situé dans le dossier ``3in1-kit\iot_project\2.get_data_from_blynk``, ou copiez ce code dans **Arduino IDE**.

    .. raw:: html
        
        <iframe src=https://create.arduino.cc/editor/sunfounder01/06b187a8-dabf-4866-b38c-742e0446cc3f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Remplacez le ``Template ID``, ``Device Name`` et ``Auth Token`` par les vôtres. Vous devez également entrer le ``ssid`` et le ``mot de passe`` du WiFi que vous utilisez. Pour des tutoriels détaillés, veuillez vous référer à :ref:`connect_blynk`.

#. Après avoir sélectionné la bonne carte et le bon port, cliquez sur le bouton **Upoad**.

    .. image:: img/2_upload.png

#. Ouvrez le moniteur série (réglez le débit en bauds sur 115200) et attendez qu'un message tel qu'une connexion réussie apparaisse.

    .. image:: img/2_ready.png

    .. note::

        Si le message ``ESP is not responding`` apparaît lorsque vous vous connectez, veuillez suivre ces étapes.

        * Assurez-vous que la batterie 9V est branchée.
        * Réinitialisez le module ESP8266 en connectant la broche RST à GND pendant 1 seconde, puis débranchez-la.
        * Appuyez sur le bouton de réinitialisation de la carte R3.

        Parfois, il peut être nécessaire de répéter l'opération ci-dessus 3 à 5 fois, veuillez être patient.

#. De retour sur Blynk, vous pouvez voir que le statut a changé en ligne et vous pouvez maintenant utiliser l'interrupteur widget sur Blynk pour contrôler la LED connectée à la carte R3.

    .. image:: img/2_blynk_button.png

#. Si vous souhaitez utiliser Blynk sur des appareils mobiles, veuillez vous référer à :ref:`blynk_mobile`.


**Comment ça fonctionne ?**

La différence entre le code de ce projet et le code du chapitre précédent :ref:`connect_blynk` est les lignes suivantes.

.. code-block:: arduino

    const int ledPin=6;

    BLYNK_WRITE(V0)
    {
        int pinValue = param.asInt(); // assigning incoming value from pin V0 to a variable
        // You can also use:
        // String i = param.asStr();
        // double d = param.asDouble();
        digitalWrite(ledPin,pinValue);
    }

    void setup()
    {
        pinMode(ledPin,OUTPUT);
    }


En ce qui concerne les fonctions ``pinMode`` et ``digitalWrite`` du ledPin, je suis sûr que vous les connaissez déjà, donc je ne vais pas les réexpliquer. Ce sur quoi vous devez vous concentrer, c'est la fonction ``BLYNK_WRITE(V0)``.

Ce qu'elle va faire, c'est que lorsque la valeur de ``V0`` sur Blynk change, Blynk.Cloud dira à votre appareil "Je suis en train d'écrire sur le **Virtual Pin** V0", et votre appareil pourra réaliser quelque chose une fois qu'il aura reçu cette information.

Nous avons créé le Datastream V0 à l'étape précédente et l'avons appliqué au Widget Interrupteur.
Cela signifie que chaque fois que nous utilisons le Widget Interrupteur, ``BLYNK_WRITE(V0)`` sera déclenché.

Nous écrivons deux instructions dans cette fonction.

.. code-block:: arduino

    int pinValue = param.asInt();

Obtenez la valeur de V0 et attribuez-la à la variable ``pinValue``.

.. code-block:: arduino

    digitalWrite(ledPin,pinValue);

Écrivez la valeur de V0 obtenue sur le ledPin, afin que le widget Interrupteur sur Blynk puisse contrôler la LED.



