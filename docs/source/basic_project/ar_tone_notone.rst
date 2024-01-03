.. _ar_passive_buzzer:

5.7 ``Tone()`` o ``noTone()``
===============================

``Tone()`` se utiliza para generar una onda cuadrada de la frecuencia especificada (y un ciclo de trabajo del 50%) en un pin. Se puede especificar una duración, de lo contrario, la onda continúa hasta que se llama a ``noTone()``.

En este proyecto, usa estas dos funciones para hacer vibrar el zumbador pasivo y emitir sonido.
Al igual que el zumbador activo, el zumbador pasivo también utiliza el fenómeno de la inducción electromagnética para funcionar.
La diferencia es que un zumbador pasivo no tiene una fuente oscilante, por lo que no emitirá un sonido si se utilizan señales de corriente continua (DC).
Pero esto permite que el zumbador pasivo ajuste su propia frecuencia de oscilación y pueda emitir diferentes notas como “do, re, mi, fa, sol, la, si”.

**Componentes Necesarios**

En este proyecto, necesitamos los siguientes componentes.

Es definitivamente conveniente comprar todo un kit, aquí está el enlace:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nombre	
        - ELEMENTOS DE ESTE KIT
        - ENLACE
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

También puedes comprarlos por separado en los siguientes enlaces.

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
    *   - :ref:`cpn_buzzer`
        - |link_passive_buzzer_buy|


**Esquemático**

.. image:: img/circuit_6.1_passive.png

Conecta el cátodo del Zumbador a GND, y el ánodo al pin digital 9. 


**Cableado**

.. image:: img/custom_tone_bb.jpg

**Código**

.. note::

    * Abre el archivo ``5.7.tone_notone.ino`` en la ruta ``3in1-kit\basic_project\5.7.tone_notone``.
    * O copia este código en el **Arduino IDE**.
    
    * O sube el código a través del `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.


.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/9212e985-1f31-4bd9-bee6-f29357035aae/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Cuando termines de cargar los códigos en la placa R3, puedes escuchar una melodía que contiene siete notas. 

**¿Cómo funciona?**

Hay dos puntos que requieren tu atención:

1. ``tone()`` & ``noTone()``: Esta función se utiliza para controlar directamente el sonido del zumbador pasivo y su prototipo es como sigue:

**Sintaxis**
    void tone(int pin, unsigned int frequency)

    void tone(int pin, unsigned int frequency, unsigned long duration)

**Parámetros**
    * ``pin``: El pin de Arduino en el que generar el tono.
    * ``frequency``: La frecuencia del tono en hertz.
    * ``duration``: La duración del tono en milisegundos (opcional)

Genera una onda cuadrada de la frecuencia especificada (y un ciclo de trabajo del 50%) en un pin (para hacer vibrar el zumbador pasivo y emitir sonido). Se puede especificar una duración, de lo contrario, la onda continúa hasta que se llama a ``noTone()``.
El pin se puede conectar a un zumbador piezoeléctrico u otro altavoz para reproducir tonos.

Solo se puede generar un tono a la vez. Si un tono ya se está reproduciendo en un pin diferente, la llamada a ``tone()`` no tendrá efecto. Si el tono se está reproduciendo en el mismo pin, la llamada configurará su frecuencia.

El uso de la función ``tone()`` interferirá con la salida PWM en los pines 3 y 11.

No es posible generar tonos inferiores a 31Hz.

**Sintaxis**
    void noTone(int pin)

**Parámetros**
    ``pin``: El pin de Arduino en el que generar el tono.

Detiene la generación de una onda cuadrada activada por ``tone()``. No tiene efecto si no se está generando ningún tono.

Conociendo estas dos funciones, puedes entender los códigos: la instalación de la matriz ``melody[]`` y la matriz ``noteDurations[]`` es la preparación para las siguientes veces que se llame a la función ``tone()`` y el cambio de tono y duración en el bucle para un mejor efecto de reproducción musical.

2. ``pitches.h``: El código utiliza un archivo adicional, ``pitches.h``. Este archivo contiene todos los valores de tono para las notas típicas. Por ejemplo, NOTE_C4 es el Do central. NOTE_FS4 es Fa sostenido, y así sucesivamente. Esta tabla de notas fue originalmente escrita por Brett Hagman, en cuyo trabajo se basó el comando ``tone()``. Puede resultarte útil cada vez que quieras hacer notas musicales.

.. code-block:: arduino

    #include "pitches.h"

.. note::
    Ya hay un archivo ``pitches.h`` en este programa de muestra. Si lo ponemos junto con el código principal en una carpeta, se pueden omitir los pasos sucesivos de instalación de ``pitches.h``.

.. image:: img/image123.png

Después de abrir el archivo de código, si no puedes abrir el
código ``pitches.h``, puedes crear uno manualmente. Los pasos son los
siguientes:

Para hacer el archivo ``pitches.h``, haz clic en el botón justo debajo del
icono del monitor serie y elige **New Tab**, o usa **Ctrl+Shift+N**.

.. image:: img/image124.png

Luego pega el siguiente código y guárdalo como ``pitches.h``:

.. code-block:: arduino

    /*****************
    Public Constants
    *****************/
    #define NOTE_B0  31
    #define NOTE_C1  33
    #define NOTE_CS1 35
    #define NOTE_D1  37
    #define NOTE_DS1 39
    #define NOTE_E1  41
    #define NOTE_F1  44
    #define NOTE_FS1 46
    #define NOTE_G1  49
    #define NOTE_GS1 52
    #define NOTE_A1  55
    #define NOTE_AS1 58
    #define NOTE_B1  62
    #define NOTE_C2  65
    #define NOTE_CS2 69
    #define NOTE_D2  73
    #define NOTE_DS2 78
    #define NOTE_E2  82
    #define NOTE_F2  87
    #define NOTE_FS2 93
    #define NOTE_G2  98
    #define NOTE_GS2 104
    #define NOTE_A2  110
    #define NOTE_AS2 117
    #define NOTE_B2  123
    #define NOTE_C3  131
    #define NOTE_CS3 139
    #define NOTE_D3  147
    #define NOTE_DS3 156
    #define NOTE_E3  165
    #define NOTE_F3  175
    #define NOTE_FS3 185
    #define NOTE_G3  196
    #define NOTE_GS3 208
    #define NOTE_A3  220
    #define NOTE_AS3 233
    #define NOTE_B3  247
    #define NOTE_C4  262
    #define NOTE_CS4 277
    #define NOTE_D4  294
    #define NOTE_DS4 311
    #define NOTE_E4  330
    #define NOTE_F4  349
    #define NOTE_FS4 370
    #define NOTE_G4  392
    #define NOTE_GS4 415
    #define NOTE_A4  440
    #define NOTE_AS4 466
    #define NOTE_B4  494
    #define NOTE_C5  523
    #define NOTE_CS5 554
    #define NOTE_D5  587
    #define NOTE_DS5 622
    #define NOTE_E5  659
    #define NOTE_F5  698
    #define NOTE_FS5 740
    #define NOTE_G5  784
    #define NOTE_GS5 831
    #define NOTE_A5  880
    #define NOTE_AS5 932
    #define NOTE_B5  988
    #define NOTE_C6  1047
    #define NOTE_CS6 1109
    #define NOTE_D6  1175
    #define NOTE_DS6 1245
    #define NOTE_E6  1319
    #define NOTE_F6  1397
    #define NOTE_FS6 1480
    #define NOTE_G6  1568
    #define NOTE_GS6 1661
    #define NOTE_A6  1760
    #define NOTE_AS6 1865
    #define NOTE_B6  1976
    #define NOTE_C7  2093
    #define NOTE_CS7 2217
    #define NOTE_D7  2349
    #define NOTE_DS7 2489
    #define NOTE_E7  2637
    #define NOTE_F7  2794
    #define NOTE_FS7 2960
    #define NOTE_G7  3136
    #define NOTE_GS7 3322
    #define NOTE_A7  3520
    #define NOTE_AS7 3729
    #define NOTE_B7  3951
    #define NOTE_C8  4186
    #define NOTE_CS8 4435
    #define NOTE_D8  4699
    #define NOTE_DS8 49
