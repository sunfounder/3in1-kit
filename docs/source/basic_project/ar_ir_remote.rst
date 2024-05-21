.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

.. _ar_receiver:

5.11.2 Receptor de Infrarrojos
=================================

En este proyecto, aprenderás a usar un receptor de infrarrojos.

Un receptor de infrarrojos es un componente que recibe señales infrarrojas y puede recibir de manera independiente rayos infrarrojos y emitir señales compatibles con el nivel TTL. 
Es similar en tamaño a un transistor normal empaquetado en plástico y es adecuado para todo tipo de control remoto por infrarrojos y transmisión de infrarrojos.

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
    *   - :ref:`cpn_receiver`
        - \-

**Esquemático**

.. image:: img/circuit_7.2_receiver.png

**Cableado**

En este ejemplo, conectamos el pin izquierdo del receptor de infrarrojos al pin 11, 
el pin central a GND, y el pin derecho a 5V.

.. image:: img/ir_remote_control_bb.jpg


**Código**

.. note::

    * Abre el archivo ``5.11.ir_receiver.ino`` en la ruta ``3in1-kit\basic_project\5.11.ir_receiver``.
    * O copia este código en el **Arduino IDE**.
    * Aquí se usa la biblioteca ``IRremote``, puedes instalarla desde el **Library Manager**.
  
        .. image:: ../img/lib_irremote.png


.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/1141d808-cc26-4589-ae5c-d1834033ac3d/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    

Después de cargar los códigos en la placa R3, podrás ver que el
valor actual del botón presionado del control remoto IR se muestra en
el monitor serial.

**¿Cómo funciona?**

Este código está diseñado para trabajar con un control remoto infrarrojo (IR) utilizando la biblioteca ``IRremote``. Aquí tienes el desglose:

#. Incluir Bibliotecas: Esto incluye la biblioteca ``IRremote``, que proporciona funciones para trabajar con controles remotos IR.

    .. code-block:: arduino

        #include <IRremote.h>

#. Define el pin de Arduino al que está conectado el pin de señal del sensor IR.

    .. code-block:: arduino

        const int IR_RECEIVE_PIN = 11;  // Define the pin number for the IR Sensor

#. Inicializa la comunicación serial con una tasa de baudios de 9600. Inicializa el receptor IR en el pin especificado (``IR_RECEIVE_PIN``) y habilita el feedback LED (si aplica).

    .. code-block:: arduino

        void setup() {
            Serial.begin(9600);                                     // Start serial communication at 9600 baud rate
            IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);  // Start the IR receiver
        }

#. El bucle se ejecuta continuamente para procesar las señales entrantes del control remoto IR.

    .. code-block:: arduino

        void loop() {
            if (IrReceiver.decode()) {
                String decodedValue = decodeKeyValue(IrReceiver.decodedIRData.command);
                if (decodedValue != "ERROR") {
                    Serial.println(decodedValue);
                    delay(100);
                }
                IrReceiver.resume();  // Enable receiving of the next value
            }
        }
    
    * Verifica si se ha recibido y decodificado con éxito una señal IR.
    * Decodifica el comando IR y lo almacena en ``decodedValue`` usando una función personalizada ``decodeKeyValue()``.
    * Verifica si el valor decodificado no es un error.
    * Imprime el valor IR decodificado en el monitor serial.
    * Reanuda la recepción de señales IR para la siguiente señal.
