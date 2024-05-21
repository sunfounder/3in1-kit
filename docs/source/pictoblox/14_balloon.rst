.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _sh_balloon:

2.14 GAME - Inflating the Balloon
=========================================

Here, we will play a game of ballooning.

After clicking the green flag, the balloon will become bigger and bigger. If the balloon is too big, it will be blown up; if the balloon is too small, it will fall down; you need to judge when to press the button to make it fly upwards.

.. image:: img/13_balloon0.png

You Will Learn
---------------------

- Paint costume for the sprite

Required Components
---------------------

In this project, we need the following components. 

It's definitely convenient to buy a whole kit, here's the link: 

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ITEMS IN THIS KIT
        - LINK
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

You can also buy them separately from the links below.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - COMPONENT INTRODUCTION
        - PURCHASE LINK

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_capacitor`
        - |link_capacitor_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|

Build the Circuit
-----------------------

The button is a 4-pin device, since the pin 1 is connected to pin 2, and pin 3 to pin 4, when the button is pressed, the 4 pins are connected, thus closing the circuit.

.. image:: img/5_buttonc.png

Build the circuit according to the following diagram.

* Connect one of the pins on the left side of the button to pin 12, which is connected to a pull-down resistor and a 0.1uF (104) capacitor (to eliminate jitter and output a stable level when the button is working).
* Connect the other end of the resistor and capacitor to GND, and one of the pins on the right side of the button to 5V.

.. image:: img/circuit/button_circuit.png

Programming
------------------

**1. Add a sprite and a backdrop**

Delete the default sprite, click the **Choose a Sprite** button in the lower right corner of the sprite area, then select the **Balloon1** sprite.

.. image:: img/13_balloon1.png

Add a **Boardwalk** backdrop via the **Choose a backdrop** button, or other backbackdrops you like.

.. image:: img/13_balloon2.png

**2. Paint a costume for the Balloon1 sprite**

Now let's draw an exploding effect costume for the balloon sprite.

Go to the **Costumes** page for the **Balloon1** sprite, click the **Choose a Costume** button in the bottom left corner, and select **Paint** to bring up a blank **Costume**.

.. image:: img/13_balloon7.png

Select a color and then use the **Brush** tool to draw a pattern.

.. image:: img/13_balloon3.png

Select a color again, click the Fill tool, and move the mouse inside the pattern to fill it with a color.

.. image:: img/13_balloon4.png

Finally, write the text BOOM, so that an explosion effect costume is complete.

.. image:: img/13_balloon5.png

**3. Scripting the Balloon sprite**

Set the initial position and size of the **Balloon1** sprite.

.. image:: img/13_balloon6.png

Then let the **Balloon** sprite slowly get bigger.

.. image:: img/13_balloon8.png

When the button is pressed (value is 1), the size of the **Balloon1** sprite stops getting bigger.

* When the size is less than 90, it will fall (y coordinate decreases).
* When the size is bigger than 90 and smaller than 120, it will fly to the sky (y coordinate increases).

.. image:: img/13_balloon9.png

If the button has not been pressed, the balloon slowly gets bigger and when the size is bigger than 120, it will explode (switch to the explode effect costume).

.. image:: img/13_balloon10.png



