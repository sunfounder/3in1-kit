.. _ar_ultrasonic:

5.8 User-defined Function
======================================


In c, we can divide a large program into the basic building blocks known as function. 
The function contains the set of programming statements enclosed by {}. 
A function can be called multiple times to provide reusability and modularity to the C program. 
In other words, we can say that the collection of functions creates a program. 
The function is also known as procedureor subroutinein other programming languages.

There are the following advantages of functions.

* By using functions, we can avoid rewriting same logic/code again and again in a program.
* We can call C functions any number of times in a program and from any place in a program.
* We can track a large C program easily when it is divided into multiple functions.
* Reusability is the main achievement of C functions.
* However, Function calling is always a overhead in a C program.


There are two types of functions in C programming:

* **Library Functions**: the functions which are declared in the C header files.
* **User-defined functions**: the functions which are created by the C programmer, so that he/she can use it many times. It reduces the complexity of a big program and optimizes the code.

In this project, define a function to read the value of the ultrasonic module.

**Schematic**

.. image:: img/circuit_6.3_ultrasonic.png

**Wiring**

.. image:: img/5.8_ultrasonic_bb.png
    :width: 600
    :align: center

* :ref:`cpn_uno`
* :ref:`cpn_wires`
* :ref:`cpn_ultrasonic`

**Code**

.. note::

    * Open the ``5.8.user_function.ino`` file under the path of ``3in1-kit\learning_project\5.8.user_function``.
    * Or copy this code into **Arduino IDE**.
    
    * Or upload the code through the `Arduino Web Editor <https://docs.arduino.cc/cloud/web-editor/tutorials/getting-started/getting-started-web-editor>`_.


.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/11717782-3ee6-4eca-bbb9-094385d9eb4b/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    

After the code is successfully uploaded, the serial monitor will print out the distance between the ultrasonic sensor and the obstacle ahead.

**How it works?**

About the application of ultrasonic sensor, we can directly check the subfunction.

.. code-block:: arduino

    float readSensorData(){// ...}

The ``trigPin`` of the ultrasonic module transmits a 10us square wave signal every 2us

.. code-block:: arduino

    digitalWrite(trigPin, LOW); 
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH); 
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW); 


The ``echoPin`` receives a high level signal if there is an obstacle within the range and use the ``pulseIn()`` function to record the time from sending to receiving.

.. code-block:: arduino

    microsecond=pulseIn(echoPin, HIGH);

The speed of sound is 340 m/s or 29 microseconds per centimeter.

This gives the distance travelled by the square wave, outbound and return, so
we divide by 2 to get the distance of the obstacle.

.. code-block:: arduino

    float distance = microsecond / 29.00 / 2;  


Note that the ultrasonic sensor will pause the program when it is working, which may cause some lagging when writing complex projects.
