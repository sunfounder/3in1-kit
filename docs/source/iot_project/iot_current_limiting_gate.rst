.. _iot_gate:

7. Portail à Limite de Courant
==================================

Certaines situations, comme les parkings, nécessitent une gestion de quantité.

Ici, nous créons un portail intelligent : un servo est utilisé comme portail, et un détecteur d'obstacles IR est placé devant ; si un objet (comme une voiture) est détecté, le portail s'ouvre et le nombre est augmenté de 1.
Le compte est affiché avec un afficheur à 7 segments et est également téléchargé sur le Cloud Blynk pour que vous puissiez le visualiser à distance. Enfin, Blynk possède un widget Interrupteur pour activer ou désactiver ce système de portail intelligent.

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
    *   - :ref:`cpn_servo`
        - |link_servo_buy|
    *   - :ref:`cpn_avoid`
        - |link_obstacle_avoidance_buy|
    *   - :ref:`cpn_7_segment`
        - |link_7segment_buy|
    *   - :ref:`cpn_74hc595`
        - |link_74hc595_buy|


**1. Construire le Circuit**

.. note::

    Le module ESP8266 nécessite un courant élevé pour fournir un environnement de fonctionnement stable, donc assurez-vous que la batterie 9V est branchée.


.. image:: img/wiring_servo_segment.jpg
    :width: 800


**2. Éditer le Tableau de Bord**


#. Pour enregistrer le nombre, créez un **Datastream** de type **Virtual Pin** sur la page **Datastream**. Réglez le TYPE DE DONNÉES sur ``Integer`` et MIN et MAX sur ``0`` et ``10``.


    .. image:: img/sp220610_165328.png
 
#. Maintenant, allez sur la page **Wed Dashboard**, faites glisser un widget **Switch** pour régler son data stream sur **V0** et un widget **Label** pour régler son data stream sur **V8**.

    .. image:: img/sp220610_165548.png


**3. Exécutez le Code**

#. Ouvrez le fichier ``7.current_limiting_gate.ino`` situé dans le dossier ``3in1-kit\iot_project\7.current_limiting_gate``, ou copiez ce code dans **Arduino IDE**.

    .. raw:: html
        
        <iframe src=https://create.arduino.cc/editor/sunfounder01/bd829175-652f-4c3e-85b0-048c3fda4555/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Remplacez le ``Template ID``, ``Device Name`` et ``Auth Token`` par les vôtres. Vous devez également entrer le ``ssid`` et le ``password`` du WiFi que vous utilisez. Pour des tutoriels détaillés, veuillez vous référer à :ref:`connect_blynk`.
#. Après avoir sélectionné la bonne carte et le bon port, cliquez sur le bouton **Upoad**.

#. Ouvrez le moniteur série (réglez le débit en bauds sur 115200) et attendez qu'un message tel qu'une connexion réussie apparaisse.


    .. image:: img/2_ready.png

    .. note::

        Si le message ``ESP is not responding`` apparaît lorsque vous vous connectez, veuillez suivre ces étapes.

        * Assurez-vous que la batterie 9V est branchée.
        * Réinitialisez le module ESP8266 en connectant la broche RST à GND pendant 1 seconde, puis débranchez-la.
        * Appuyez sur le bouton de réinitialisation de la carte R3.

        Parfois, il peut être nécessaire de répéter l'opération ci-dessus 3 à 5 fois, veuillez être patient.

#. Maintenant, cliquez sur le widget Bouton de Contrôle sur Blynk pour activer le système de porte intelligent. Si le module d'évitement d'obstacles IR détecte un obstacle, le portail s'ouvrira et l'afficheur à 7 segments et le widget Compteur sur Blynk ajouteront 1.

    .. image:: img/sp220610_165548.png

#. Si vous souhaitez utiliser Blynk sur des appareils mobiles, veuillez vous référer à :ref:`blynk_mobile`.

    .. image:: img/mobile_gate.jpg

**Comment ça fonctionne ?**


La fonction ``BLYNK_WRITE(V0)`` obtient l'état du widget **Switch** et l'assigne à la variable ``doorFlag``, qui sera utilisée pour déterminer si le système de portail intelligent est activé ou non.


.. code-block:: arduino

    BLYNK_WRITE(V0)
    {
        doorFlag = param.asInt(); // Enable Gate
    }

Dans le Timer Blynk, ``doorFlag`` est évalué chaque seconde et si activé, la fonction principale du portail est exécutée.

.. code-block:: arduino

    void myTimerEvent()
    {
        if (doorFlag)
        {
            channelEntrance();
        }
    }

La fonction principale du portail est ``channelEntrance()``.
Lorsqu'un objet s'approche du portail (le capteur détecte un obstacle), le ``count`` est augmenté de 1.
Écrivez ``count`` dans le datastream ``V8`` du Cloud Blynk et sur l'afficheur à 7 segments du circuit, et ouvrez le portail.
Si l'objet passe de présent à absent, ce qui signifie que l'objet est entré par le portail, fermez le portail.


.. code-block:: arduino

    void channelEntrance()
    {
        int currentState = digitalRead(irPin); // 0:obstacle 1:no-obstacle
        if (currentState == 0 && lastState == 1) {
            count=(count+1)%10;
            Blynk.virtualWrite(V8, count);
            showNumber(count);
            operateGate(true);
        } else if ((currentState == 1 && lastState == 0)) {
            operateGate(false);
        }
        lastState = currentState;
    }

La fonction ``showNumber(int num)`` est utilisée pour faire afficher la valeur par l'afficheur à 7 segments.

.. code-block:: arduino

    void showNumber(int num)
    {
        digitalWrite(STcp, LOW); //ground ST_CP and hold low for as long as you are transmitting
        shiftOut(DS, SHcp, MSBFIRST, datArray[num]);
        digitalWrite(STcp, HIGH); //pull the ST_CPST_CP to save the data
    }

La fonction ``operateGate(bool openGate)`` ouvre lentement la porte lorsque la référence est ``True``, et ferme lentement la porte lorsque la référence est ``False``.

.. code-block:: arduino

    void operateGate(bool openGate) {
        if (openGate == true) 
        {
            // open gate
            while (angle <= 90) { 
            angle++;
            myservo.write(angle);
            delay(5);
            }
        } else {
            // close gate
            while (angle >= 0){ 
            angle--;
            myservo.write(angle);
            delay(5);
            }
        }
    }