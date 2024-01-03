.. _ar_interval:

5.4 Intervalo
================

A veces necesitas hacer dos cosas a la vez. Por ejemplo, podrías querer hacer parpadear un LED mientras lees una pulsación de botón. En este caso, no puedes usar ``delay()``, porque Arduino pausa tu programa durante el ``delay()``. Si se presiona el botón mientras Arduino está en pausa esperando a que pase el ``delay()``, tu programa se perderá la pulsación del botón.

Una analogía sería calentar una pizza en tu microondas y también esperar un correo electrónico importante. Pones la pizza en el microondas y lo programas por 10 minutos. La analogía de usar ``delay()`` sería sentarte frente al microondas viendo el temporizador contar desde 10 minutos hasta que el temporizador llegue a cero. Si el correo electrónico importante llega durante este tiempo, te lo perderás.

Lo que harías en la vida real sería encender la pizza, luego revisar tu correo electrónico, y luego quizás hacer algo más (¡que no tome mucho tiempo!) y de vez en cuando volver al microondas para ver si el temporizador ha llegado a cero, indicando que tu pizza está lista.

Este sketch demuestra cómo hacer sonar un zumbador sin usar ``delay()``. 
Enciende el zumbador y luego toma nota del tiempo. Luego, cada vez que pasa por ``loop()``, verifica si ha pasado el tiempo de intervalo deseado.
Si ha pasado, hace sonar el zumbador y toma nota del nuevo tiempo.
De esta manera, el zumbador suena continuamente mientras la ejecución del sketch nunca se retrasa en una sola instrucción.

Basándonos en esta condición, podemos agregar el código del botón para controlar el LED, 
no será perturbado por el zumbador tocando música.

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
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|
    *   - :ref:`cpn_buzzer`
        - |link_passive_buzzer_buy|


**Esquemático**

.. image:: img/circuit_8.5_interval.png


**Cableado**

.. image:: img/interval_bb.jpg
    :width: 600
    :align: center

**Código**

.. note::

    * Abre el archivo ``5.4.interval.ino`` en la ruta ``3in1-kit\basic_project\5.4.interval``.
    * O copia este código en **Arduino IDE**.
    
    * O carga el código a través del `Editor Web de Arduino <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/0d430b04-ef2d-4e32-8d76-671a3a917cb1/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Después de cargar el código con éxito, el zumbador tocará música; cada vez que presiones el botón, el LED se encenderá. El trabajo del LED y el zumbador no se interfiere entre sí.

**¿Cómo funciona?**

Inicializar una variable llamada ``previousMillis`` para almacenar el tiempo de operación anterior del microcontrolador.

.. code-block:: arduino

    unsigned long previousMillis = 0;     

Marcar qué nota se está tocando.

.. code-block:: arduino

    int thisNote=0; 

El tiempo de intervalo de cada nota.

.. code-block:: arduino

    long interval = 1000; 

En ``loop()``, declara ``currentMillis`` para almacenar el tiempo actual.

.. code-block:: arduino

    unsigned long currentMillis = millis();

Cuando el intervalo entre el tiempo de operación actual y el último tiempo de actualización es mayor que 1000ms, se activan ciertas funciones. Mientras tanto, actualiza el previousMillis al tiempo actual para la próxima activación que ocurrirá 1 segundo después.  

.. code-block:: arduino

    if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;// save the last time of the last tone
        //...
    }

Tocar las notas de la melodía una por una.

.. code-block:: arduino

    tone(buzzerPin,melody[thisNote],100);
    interval=1000/noteDurations[thisNote]; // interval at which to tone
    thisNote=(thisNote+1)%(sizeof(melody)/2); //iterate over the notes of the melody

El botón controla el LED.

.. code-block:: arduino

  // play button & led 
  digitalWrite(ledPin,digitalRead(buttonPin));