.. _ar_guess_number:

6.6 Guess Number
==================


Guessing Numbers is a fun party game where you and your friends take
turns inputting a number (0~99). The range will be smaller with the
inputting of the number till a player answers the riddle correctly. Then
the player is defeated and punished. For example, if the lucky number is
51 which the players cannot see, and the player 1 inputs 50, the prompt
of number range changes to 50~99; if the player 2 inputs 70, the range
of number can be 50~70; if the player 3 inputs 51, he or she is the
unlucky one. Here, we use IR Remote Controller to input numbers and use
LCD to output outcomes.

**Schematic Diagram**

.. image:: img/wiring_guess_number.png
    :align: center


**Fritzing Circuit**

In this example, the wiring of LCD1602 and infrared receiving module is
as follows.

.. image:: img/circuit_guess_number.png
    :align: center


**Code**


.. note::

    * You can open the file ``6.6.guess_number.ino`` under the path of ``3in1-kit\basic_project\6.6.guess_number`` directly.
    * Or copy this code into Arduino IDE 1/2.
    * The ``LiquidCrystal I2C`` and ``IRremote libraries`` are used here, you can install them from the **Library Manager**.


.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/6bafb36d-6763-460c-98b7-aba48120e718/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


After the code is successfully uploaded, the welcome characters will appear on the LCD1602. Now press the number according to the range prompt on the screen, the display will get smaller and smaller unless you guess that lucky number.

.. note::
    If the code and wiring are fine, but the LCD still does not display content, you can turn the potentiometer on the back to increase the contrast.


**How it works?**

In order to make the number guessing game become vivid and funny, we
need to achieve the following functions:

1. The lucky number will be displayed when we start and reset the game,
   and the number range prompt is reset to 0 ~ 99.

2. LCD will display the number being input and the number range prompt.

3. After inputting two digits, there appears result judgment
   automatically.

4. If you input a single digit, you can press the CYCLE key (the key at
   the center of the Controller) to start the result judgment.

5. If the answer is not guessed, the new number range prompt will be
   displayed (if the lucky number is 51 and you enter 50, the number
   range prompt will change to 50~99).

6. The game is automatically reset after the lucky number is guessed, so
   that the player can play a new round.

7. The game can be reset by directly pressing the POWER button (the
   button in the upper left corner).

In conclusion, the work flow of the project is shown in the flow chart.

.. image:: img/Part_three_4_Example_Explanation.png
    :align: center



