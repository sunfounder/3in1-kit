.. _car_remote_plus:

10. Arranque con un Toque
=============================

En este proyecto, hemos integrado los proyectos anteriores - seguimiento de línea, seguimiento, evitación de obstáculos, conducción autónoma, etc., juntos. Se pueden cambiar mediante botones en el control remoto, así que puedes arrancar el coche y experimentar todas las funciones a la vez.

**Cableado**

.. image:: img/car_10.png
    :width: 800

**Código**

.. note::

    * Abre el archivo ``10.one_touch_start.ino`` en la ruta ``3in1-kit\car_project\10.one_touch_start``.
    * O copia este código en el **Arduino IDE**.
    * Aquí se utiliza la biblioteca ``IRremote``, puedes instalarla desde el **Library Manager**.
  
        .. image:: ../img/lib_irremote.png
    

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/d873724f-120e-4679-b4ec-8d72ad583c8c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Una vez subido el código con éxito, el LED parpadeará rápidamente 3 veces por cada señal recibida del control remoto por el receptor IR. Puedes presionar las siguientes teclas para operar el carro.

* **+**: Acelerar
* **-**: Desacelerar
* **1**: Moverse hacia el frente izquierdo
* **2**: Hacia adelante
* **3**: Moverse hacia la derecha
* **4**: Girar a la izquierda
* **6**: Girar a la derecha
* **7**: Hacia atrás a la izquierda
* **8**: Hacia atrás
* **9**: Hacia atrás a la derecha
* **CYCLE**: Seguir la línea
* **U/SD**: Conducción autónoma
* **▷▷|**: Evitación de obstáculos con módulo ultrasónico
* **|◁◁**: Evitación de obstáculos con módulo IR Obstacle
* **EQ**: Seguir tu mano
* **0**: Detener

