.. _sh_guide:

1.3 Guía Rápida sobre PictoBlox
====================================

Ahora aprendamos a utilizar PictoBlox en dos modos.

Además, hay un LED a bordo conectado al Pin 13 en la placa R3, aprenderemos a hacer parpadear este LED en 2 modos diferentes.

.. image:: img/1_led.jpg
    :width: 500
    :align: center

.. _stage_mode:

Modo Escenario
---------------

**1. Conectar a la Placa Arduino**

Conecta tu placa Arduino al ordenador con un cable USB, generalmente el ordenador reconocerá automáticamente tu placa y finalmente asignará un puerto COM.

Abre PictoBlox, la interfaz de programación de Python se abrirá por defecto. Y necesitamos cambiar a la interfaz de Bloques.

.. image:: img/0_choose_blocks.png

Entonces verás en la esquina superior derecha para cambiar de modo. El modo predeterminado es el Modo Escenario, donde Tobi está parado en el escenario.

.. image:: img/1_stage_upload.png

Haz clic en **Board** en la barra de navegación superior derecha para seleccionar la placa.

.. image:: img/1_board.png

Por ejemplo, elige **Arduino Uno**.

.. image:: img/1_choose_uno.png

Entonces aparecerá una ventana de conexión para que selecciones el puerto a conectar, y volverás a la página principal cuando se complete la conexión. Si rompes la conexión durante el uso, también puedes hacer clic en **Connect** para reconectar.

.. image:: img/1_connect.png

Al mismo tiempo, aparecerán paletas relacionadas con Arduino Uno, como Arduino Uno, Actuadores, etc., en la **Paleta de Bloques**.

.. image:: img/1_arduino_uno.png

**2. Subir Firmware**

Dado que vamos a trabajar en el Modo Escenario, debemos subir el firmware a la placa. Esto garantizará la comunicación en tiempo real entre la placa y el ordenador. Subir el firmware es un proceso único. Para hacerlo, haz clic en el botón Subir Firmware.

Después de esperar un rato, aparecerá el mensaje de éxito de la carga.

.. note::

    Si estás usando esta placa Arduino en PictoBlox por primera vez, o si esta Arduino fue previamente cargada con el IDE de Arduino. Entonces necesitas pulsar **Upload Firmware** antes de poder usarla.


.. image:: img/1_firmware.png


**3. Programación**

* Abrir y ejecutar el script directamente

Por supuesto, puedes abrir los scripts directamente para ejecutarlos, pero por favor descárgalos primero de `github <https://github.com/sunfounder/3in1-kit/archive/refs/heads/main.zip>`_.

Puedes hacer clic en **File** en la esquina superior derecha y luego elegir **Open**.

.. image:: img/0_open.png

Elige **Open from Computer**.

.. image:: img/0_dic.png

Luego ve a la ruta de ``3in1-kit\scratch_project\code``, y abre **1. Stage Mode.sb3**. Por favor, asegúrate de haber descargado el código requerido de `github <https://github.com/sunfounder/3in1-kit/archive/refs/heads/main.zip>`_.

.. image:: img/0_stage.png

Haz clic directamente en el script para ejecutarlo, algunos proyectos son hacer clic en la bandera verde o hacer clic en el sprite.

.. image:: img/1_more.png

* Programar paso a paso

También puedes escribir el script paso a paso siguiendo estos pasos.

Haz clic en la paleta **Arduino Uno**.

.. image:: img/1_arduino_uno.png

El LED en la placa Arduino está controlado por el pin digital 13 (solo 2 estados, ALTO o BAJO), así que arrastra el bloque [set digital pin out as] al área de scripts.

Dado que el estado predeterminado del LED es encendido, ahora configura el pin 13 a BAJO y haz clic en este bloque y verás que el LED se apaga.

* [set digital pin out as]: Establece los pines digitales (2~13) a nivel (ALTO/BAJO).

.. image:: img/1_digital.png

Para ver el efecto de un LED parpadeando continuamente, necesitas usar los bloques [Wait 1 seconds] y [forever] en la paleta **Control**. Haz clic en estos bloques después de escribir, un halo amarillo significa que está corriendo.

* [Wait 1 seconds]: de la paleta **Control**, se utiliza para establecer el intervalo de tiempo entre 2 bloques.
* [forever]: de la paleta **Control**, permite que el script siga ejecutándose a menos que se pause manualmente.

.. image:: img/1_more.png

.. _upload_mode:

Modo de Carga
---------------

**1. Conectar a la Placa Arduino**

Conecta tu placa Arduino al ordenador con un cable USB, generalmente el ordenador reconocerá automáticamente tu placa y finalmente asignará un puerto COM.

Abre PictoBlox y haz clic en **Board** en la barra de navegación superior derecha para seleccionar la placa.

.. image:: img/1_board.png

Por ejemplo, elige **Arduino Uno**.

.. image:: img/1_choose_uno.png

Entonces aparecerá una ventana de conexión para que selecciones el puerto a conectar, y volverás a la página principal cuando se complete la conexión. Si rompes la conexión durante el uso, también puedes hacer clic en **Connect** para reconectar.

.. image:: img/1_connect.png

Al mismo tiempo, aparecerán paletas relacionadas con Arduino Uno, como Arduino Uno, Actuadores, etc., en la **Paleta de Bloques**.

.. image:: img/1_upload_uno.png

Después de seleccionar el Modo de Carga, el escenario cambiará al área de código Arduino original.

.. image:: img/1_upload.png

**2. Programación**

* Abrir y ejecutar el script directamente

Puedes hacer clic en **File** en la esquina superior derecha.

.. image:: img/0_open.png

Elige **Open from Computer**.

.. image:: img/0_dic.png

Luego ve a la ruta de ``3in1-kit\scratch_project\code``, y abre **1. Upload Mode.sb3**. Por favor, asegúrate de haber descargado el código requerido de `github <https://github.com/sunfounder/3in1-kit/archive/refs/heads/main.zip>`_.

.. image:: img/0_upload.png

Finalmente, haz clic en el botón **Upload Code**.

.. image:: img/1_upload_code.png


* Programar paso a paso

También puedes escribir el script paso a paso siguiendo estos pasos.

Haz clic en la paleta **Arduino Uno**.

.. image:: img/1_upload_uno.png

Arrastra [when Arduino Uno starts up] al área de script, que es necesario para cada script.

.. image:: img/1_uno_starts.png

El LED en la placa Arduino está controlado por el pin digital13 (solo 2 estados ALTO o BAJO), así que arrastra el bloque [set digital pin out as] al área de script.

Dado que el estado predeterminado del LED es encendido, ahora configura el pin 13 a BAJO y haz clic en este bloque y verás que el LED se apaga.

* [set digital pin out as]: Establece el pin digital (2~13) a nivel (ALTO/BAJO).

.. image:: img/1_upload_digital.png

En este punto verás aparecer el código Arduino en el lado derecho, si quieres editar este código, entonces puedes activar el Modo de Edición.

.. image:: img/1_upload1.png

Para ver el efecto de un LED parpadeando continuamente, necesitas usar los bloques [Wait 1 seconds] y [forever] en la paleta **Control**. Haz clic en estos bloques después de escribir, un halo amarillo significa que está corriendo.

* [Wait 1 seconds]: de la paleta **Control**, se utiliza para establecer el intervalo de tiempo entre 2 bloques.
* [forever]: de la paleta **Control**, permite que el script siga corriendo a menos que se apague la alimentación.

.. image:: img/1_upload_more.png

Finalmente, haz clic en el botón **Upload Code**.

.. image:: img/1_upload_code.png
