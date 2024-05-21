.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _cpn_uno:



Arduino Uno R4 Minima
=================================

**Overview**

Enhanced and improved, the Arduino UNO R4 Minima is armed with a powerful 32-bit microcontroller courtesy of Renesas. Brace yourself for increased processing power, expanded memory, and a whole new level of on-board peripherals. The best part? Compatibility with existing shields and accessories remains intact, and there's no need to make any changes to the standard form factor or 5 V operating voltage.

Joining the Arduino ecosystem, the UNO R4 is a trusty addition suitable for both beginners and seasoned electronics enthusiasts. Whether you're just starting out or looking to push the boundaries of your projects, this robust board delivers reliable performance every time.

.. image:: img/uno_r4.png

Here's what the UNO R4 Minima brings to the table:

* Hardware compatibility with UNO form factor: The UNO R4 Minima maintains the same form factor, pinout, and 5 V operating voltage as its predecessor, the UNO R3. This ensures a seamless transition for existing shields and projects, leveraging the extensive and unique ecosystem already established for the Arduino UNO.
* Expanded memory and faster clock: Prepare for more precise calculations and the ability to handle complex projects with ease. The UNO R4 Minima boasts increased memory and a faster clock speed, empowering you to tackle demanding tasks effortlessly.
* Extra on-board peripherals: The UNO R4 Minima introduces a range of on-board peripherals, including a 12-bit DAC, CAN BUS, and OP AMP. These additional components provide you with expanded capabilities and flexibility in your designs.
* Extended 24 V tolerance: The UNO R4 Minima now supports a wider input voltage range, allowing power supplies up to 24 V. This enables seamless integration with motors, LED strips, and other actuators, simplifying your projects by utilizing a single power source.
* SWD connector: Debugging is a critical aspect of any project. Simply connect an external debugger to the UNO R4 Minima and effortlessly monitor the inner workings of your system. Stay in control and gain valuable insights.
* HID support: The UNO R4 Minima comes with built-in HID (Human Interface Device) support, enabling it to simulate a mouse or keyboard when connected to a computer via a USB cable. This convenient feature makes it a breeze to send keystrokes and mouse movements to a computer, enhancing usability and functionality.

**Tech specs**

* Board:
    * Name: Arduino® UNO R4 Minima
    * SKU: ABX00080
* Microcontroller: Renesas RA4M1 (Arm® Cortex®-M4)
* USB: USB-C® Programming Port
* Pins:
    * Digital I/O Pins: 14
    * Analog input pin: 6
    * DAC: 1
    * PWM pins: 6
* Communication
    *  UART: Yes, 1x
    * I2C: Yes, 1x
    * SPI: Yes, 1x
    * CAN: Yes 1 CAN Bus
* Power
    * Circuit operating voltage: 5 V
    * Input voltage (VIN): 6-24 V
    * DC Current per I/O Pin: 8 mA
* Clock speed Main core 48 MHz
* Memory RA4M1 256 kB Flash, 32 kB RAM
* Dimensions
    * Width: 68.85 mm
    * Length: 53.34 mm

**Pinout**

.. image:: img/uno_r4_pinsout.png
    :width: 800

* |link_r4_datasheet|
* |link_r4_schematic|
* |link_r4_doc|


.. SunFounder R4 Board
.. ===========================

.. .. image:: img/uno_r3.jpg
..     :width: 600
..     :align: center

.. .. note::

..     The SunFounder R4 board is a mainboard with almost the same functions as the `Arduino Uno <https://store.arduino.cc/products/arduino-uno-rev3/>`_, and the two boards can be used interchangeably.

.. SunFounder R4 board is a microcontroller board based on the ATmega328P (`datasheet <http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf>`_). It has 14 digital input/output pins (of which 6 can be used as PWM outputs), 6 analog inputs, a 16 MHz ceramic resonator (CSTCE16M0V53-R0), a USB connection, a power jack, an ICSP header and a reset button. It contains everything needed to support the microcontroller; simply connect it to a computer with a USB cable or power it with a AC-to-DC adapter or battery to get started.

.. **Technical Parameters**

.. .. image:: img/uno.jpg
..     :align: center

.. * MICROCONTROLLER: ATmega328P
.. * OPERATING VOLTAGE: 5V
.. * INPUT VOLTAGE (RECOMMENDED): 7-12V
.. * INPUT VOLTAGE (LIMIT): 6-20V
.. * DIGITAL I/O PINS: 14 (0-13, of which 6 provide PWM output(3, 5, 6, 9-11))
.. * PWM DIGITAL I/O PINS: 6 (3, 5, 6, 9-11)
.. * ANALOG INPUT PINS: 6 (A0-A5)
.. * DC CURRENT PER I/O PIN: 20 mA
.. * DC CURRENT FOR 3.3V PIN: 50 mA
.. * FLASH MEMORY: 32 KB (ATmega328P) of which 0.5 KB used by bootloader
.. * SRAM: 2 KB (ATmega328P)
.. * EEPROM: 1 KB (ATmega328P)
.. * CLOCK SPEED: 16 MHz
.. * LED_BUILTIN: 13
.. * LENGTH: 68.6 mm
.. * WIDTH: 53.4 mm
.. * WEIGHT: 25 g
.. * I2C Port: A4(SDA), A5(SCL)


.. **What's More**

.. * `Arduino IDE <https://www.arduino.cc/en/software>`_
.. * `Arduino Programming Language Reference <https://www.arduino.cc/reference/en/>`_
.. * :ref:`install_arduino`
.. * `ATmega328P Datasheet <http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf>`_

