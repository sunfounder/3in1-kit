.. _ar_guess_number:

6.6 Adivina el Número
=======================

Adivinar Números es un divertido juego de fiesta donde tú y tus amigos
se turnan para introducir un número (0~99). El rango se reducirá con la
introducción del número hasta que un jugador responda correctamente al acertijo. Entonces
el jugador es derrotado y castigado. Por ejemplo, si el número afortunado es
51, que los jugadores no pueden ver, y el jugador 1 introduce 50, el rango
de números cambia a 50~99; si el jugador 2 introduce 70, el rango
de números puede ser 50~70; si el jugador 3 introduce 51, él o ella es el
desafortunado. Aquí, usamos un Controlador Remoto IR para introducir números y usar
LCD para mostrar los resultados.

**Componentes Necesarios**

Para este proyecto, necesitamos los siguientes componentes.

Comprar un kit completo es definitivamente conveniente, aquí está el enlace:

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
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|
    *   - :ref:`cpn_receiver`
        - \-


**Esquemático**

.. image:: img/circuit_guess_number.png
    :align: center

**Cableado**

En este ejemplo, la conexión del LCD1602 y el módulo receptor infrarrojo es
la siguiente.

.. image:: img/wiring_guess_number.png
    :align: center

**Código**

.. note::

    * Puedes abrir directamente el archivo ``6.6.guess_number.ino`` en la ruta ``3in1-kit\basic_project\6.6.guess_number``.
    * O copia este código en Arduino IDE.
    * Aquí se utilizan las bibliotecas ``LiquidCrystal I2C`` y ``IRremote``, puedes instalarlas desde el **Library Manager**.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/6bafb36d-6763-460c-98b7-aba48120e718/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Después de que el código se haya cargado con éxito, los caracteres de bienvenida aparecerán en el LCD1602. Ahora presiona el número según el rango indicado en la pantalla, la visualización se irá reduciendo hasta que adivines ese número afortunado.

.. note::
    Si el código y la conexión están bien, pero el LCD todavía no muestra contenido, puedes girar el potenciómetro en la parte trasera para aumentar el contraste.

**¿Cómo funciona?**

Para que el juego de adivinar números sea vívido y divertido, necesitamos lograr las siguientes funciones:

1. El número afortunado se mostrará cuando iniciemos y reiniciemos el juego, y el rango numérico se restablece a 0 ~ 99.

2. El LCD mostrará el número que se está introduciendo y el rango numérico.

3. Después de introducir dos dígitos, aparecerá automáticamente el juicio del resultado.

4. Si introduces un solo dígito, puedes presionar la tecla CYCLE (la tecla en el centro del Controlador) para iniciar el juicio del resultado.

5. Si la respuesta no se adivina, se mostrará el nuevo rango numérico (si el número afortunado es 51 y tú introduces 50, el rango numérico cambiará a 50~99).

6. El juego se reinicia automáticamente después de adivinar el número afortunado, para que el jugador pueda jugar una nueva ronda.

7. El juego se puede reiniciar presionando directamente el botón POWER (el botón en la esquina superior izquierda).

En conclusión, el flujo de trabajo del proyecto se muestra en el diagrama de flujo.

.. image:: img/Part_three_4_Example_Explanation.png
    :align: center

