.. _ar_lcd1602:

5.11.1 Pantalla de Cristal Líquido
=====================================

Un LCD1602 I2C está compuesto por un LCD1602 y un módulo I2C. El LCD1602 puede utilizarse para mostrar caracteres, números, etc., pero necesita ocupar muchos pines del control principal. Al configurar un módulo I2C, solo se necesitan 2 pines I/O para controlar este LCD1602.

Ahora veamos cómo hacer funcionar este LCD1602 I2C.

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|


**Esquemático**

.. image:: img/circuit_7.1_lcd1602.png

**Cableado**

.. image:: img/lcd_bb.jpg
    :width: 800
    :align: center

.. note::
    Los pines SDA y SCL de la placa R3 son los pines A4 y A5.

**Código**

.. note::

    * Abre el archivo ``5.11.liquid_crystal_display.ino`` en la ruta ``3in1-kit\basic_project\5.11.liquid_crystal_display``.
    * O copia este código en el **Arduino IDE**.
    * Aquí se usa la biblioteca ``LiquidCrystal I2C``, puedes instalarla desde el **Library Manager**.

        .. image:: ../img/lib_liquidcrystal_i2c.png
    

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/e49c4936-2530-4890-b86c-1017d11eae6e/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Una vez que el código se haya cargado con éxito, verás "SunFounder", "Hello World" en el LCD1602 I2C.

.. note::
    Si el código y la conexión están bien, pero el LCD aún no muestra contenido, puedes ajustar el potenciómetro en la parte trasera.

**¿Cómo funciona?**

Al llamar a la biblioteca ``LiquidCrystal_I2C.h``, puedes manejar fácilmente el LCD.

.. code-block:: arduino

    #include "LiquidCrystal_I2C.h"

Funciones de la Biblioteca:

.. code-block:: arduino

    LiquidCrystal_I2C(uint8_t lcd_Addr,uint8_t lcd_cols,uint8_t lcd_rows)

Crea una nueva instancia de la clase ``LiquidCrystal_I2C`` que representa un
LCD particular conectado a tu placa Arduino.

* ``lcd_AddR``: La dirección del LCD por defecto es 0x27.
* ``lcd_cols``: El LCD1602 tiene 16 columnas.
* ``lcd_rows``: El LCD1602 tiene 2 filas.


.. code-block:: arduino

    void init()

Inicializa el lcd.

.. code-block:: arduino

    void backlight()

Enciende la retroiluminación (opcional).

.. code-block:: arduino

    void nobacklight()

Apaga la retroiluminación (opcional).

.. code-block:: arduino

    void display()

Enciende la pantalla del LCD.

.. code-block:: arduino

    void nodisplay()

Apaga rápidamente la pantalla del LCD.

.. code-block:: arduino

    void clear()

Limpia la pantalla y establece la posición del cursor en cero.

.. code-block:: arduino

    void setCursor(uint8_t col,uint8_t row)

Establece la posición del cursor en col, fila.

.. code-block:: arduino

    void print(data,BASE)

Imprime texto en el LCD.

* ``data``: Los datos a imprimir (char, byte, int, long o string).
* ``BASE (opcional)``: La base en la que imprimir números: BIN para binario (base 2), DEC para decimal (base 10), OCT para octal (base 8), HEX para hexadecimal (base 16).

