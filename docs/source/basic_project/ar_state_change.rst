.. _ar_state_change:

5.3 Detección de Cambio de Estado
====================================

Cuando el botón controla otros dispositivos, no solo puede funcionar cuando se presiona, sino que también puede detenerse cuando se suelta.
También es posible cambiar el estado de trabajo cada vez que se presiona el botón.

Para lograr este efecto, necesitas saber cómo alternar el estado de trabajo entre apagado y encendido cuando se presiona el botón,
Es decir, "detección de cambio de estado".

En este proyecto, usaremos el botón para controlar el motor.

**Componentes Necesarios**

En este proyecto, necesitamos los siguientes componentes.

Es definitivamente conveniente comprar un kit completo, aquí está el enlace:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nombre	
        - ELEMENTOS EN ESTE KIT
        - ENLACE
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

También puedes comprarlos por separado en los enlaces a continuación.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUCCIÓN DEL COMPONENTE
        - ENLACE DE COMPRA

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|
    *   - :ref:`cpn_tt_motor`
        - \-
    *   - :ref:`cpn_l9110`
        - \-

**Esquemático**

.. image:: img/circuit_8.3_statechange.png

**Cableado**

.. image:: img/5.3_state_change_l9110_bb.png
    :width: 800
    :align: center

**Código**

.. note::

    * Abre el archivo ``5.3.state_change_detection.ino`` en la ruta ``3in1-kit\basic_project\5.3.state_change_detection``.
    * O copia este código en **Arduino IDE**.
    
    * O carga el código a través del `Editor Web de Arduino <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/67a62a3d-46d3-4f5f-889c-364cbdf9b66f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Después de cargar el código con éxito, presionas el botón y el motor girará; hasta que presiones el botón de nuevo, el motor se detendrá.


**¿Cómo funciona?**

#. Crea variables y define pines para el motor y el botón.

    .. code-block:: arduino

        ...
        int detectionState = 0;   
        int buttonState = 0;         
        int lastButtonState = 0;    

    * ``detectionState`` es una bandera cuyo valor cambia cada vez que se presiona el botón, por ejemplo, 0 esta vez, 1 la próxima, y así sucesivamente de forma alternativa.
    * ``buttonState`` y ``lastButtonState`` se utilizan para registrar el estado del botón en esta ocasión y la última vez, para comparar si el botón fue presionado o soltado.

#. Inicializa cada pin y establece la tasa de baudios del monitor serial.

    .. code-block:: arduino

        void setup() {
            pinMode(buttonPin, INPUT);
            Serial.begin(9600);
            pinMode(B_1A, OUTPUT);
            pinMode(B_1B, OUTPUT);
        }


#. Primero lee el estado del botón, y si el botón está presionado, la variable ``detectionState`` cambiará su valor de 0 a 1 o de 1 a 0. Cuando ``detectionState`` es 1, el motor se activará. Tiene el efecto de que esta vez se presiona el botón, el motor gira, la próxima vez que se presiona el botón, el motor se detiene, y así sucesivamente de forma alternativa.

    .. code-block:: arduino

        void loop() {
            // Toggle the detectionState each time the button is pressed
        buttonState = digitalRead(buttonPin);
        if (buttonState != lastButtonState) {
            if (buttonState == HIGH) {
            detectionState=(detectionState+1)%2;
            Serial.print("The detection state is: ");
            Serial.println(detectionState);
            } 
            delay(50);
        }
        lastButtonState = buttonState;
        
        // According to the detectionState, start the motor
            if(detectionState==1){
                digitalWrite(B_1A,HIGH);
                digitalWrite(B_1B,LOW);
            }else{
                digitalWrite(B_1A,LOW);
                digitalWrite(B_1B,LOW);
            }
        }

    El flujo de trabajo completo es el siguiente.

    * Lee el valor del botón.

    .. code-block:: arduino

        buttonState = digitalRead(buttonPin);

    * Si ``buttonState`` y ``lastButtonState`` no son iguales, significa que el estado del botón ha cambiado, continúa con el siguiente juicio y almacena el estado del botón en este momento en la variable ``lastButtonState``. ``delay(50)`` se utiliza para eliminar el jitter.
    
    .. code-block:: arduino

        if (buttonState != lastButtonState) {
        ...
            delay(50);
        }
        lastButtonState = buttonState;

    * Cuando se presiona el botón, su valor es HIGH. Aquí, cuando se presiona el botón, se cambia el valor de la variable ``detectionState``, por ejemplo, de 0 a 1 después de una operación.

    .. code-block:: arduino

        if (buttonState == HIGH) {
            detectionState=(detectionState+1)%2;
            Serial.print("The detection state is: ");
            Serial.println(detectionState);
        }

    * Cuando la variable ``detectionState`` es 1, deja que el motor gire, de lo contrario, detente.

    .. code-block:: arduino

        if(detectionState==1){
            digitalWrite(B_1A,HIGH);
            digitalWrite(B_1B,LOW);
        }else{
            digitalWrite(B_1A,LOW);
            digitalWrite(B_1B,LOW);
        }
