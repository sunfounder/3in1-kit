Learning Projects
========================

This chapter is used to learn how to control electronic circuits using Arduino.

Depending on the components, the basic control methods of Arduino can be divided into four types:

* :ref:`ar_digital_write`: Set the output voltage of the pin to be high or low, which can be used to turn the light on and off.
* :ref:`ar_analog_write`: Write the analog value (`PWM wave <https://docs.arduino.cc/learn/microcontrollers/analog-output>`_) to the pin, which can be used to adjust the brightness of the light.
* :ref:`ar_digital_read`: Read the level signal of the digital pin, which can be used to read the working condition of the switch.
* :ref:`ar_analog_read`: Read the voltage of the analog pin, which can be used to read the working condition of the knob.

In addition, there are some components with more complex usage that can be found in the :ref:`ar_others` section.
There are also some components that require additional libraries for use, and these are grouped under the section :ref:`ar_add_libraries`.

Finally, the kit also provides some :ref:`ar_funny_project`, which includes many simple and useful manipulations.
Try this section of code and you will understand how most simple projects work.


.. toctree::
    :maxdepth: 2

    ard_digital_write
    ard_analog_write
    ard_digital_read
    ard_analog_read
    ard_others
    ard_add_libraries
    ard_funny_example


