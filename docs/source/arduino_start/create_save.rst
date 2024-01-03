Cómo crear, abrir o guardar un Sketch
=======================================

#. Cuando abres el IDE de Arduino por primera vez o creas un nuevo sketch, verás una página como esta, donde el IDE de Arduino crea un nuevo archivo para ti, que se llama "sketch".

    .. image:: img/sp221014_173458.png

    Estos archivos de sketch tienen un nombre temporal regular, del cual puedes deducir la fecha en que se creó el archivo. ``sketch_oct14a.ino`` significa el primer sketch del 14 de octubre, ``.ino`` es el formato de archivo de este sketch.

#. Ahora intentemos crear un nuevo sketch. Copia el siguiente código en el IDE de Arduino para reemplazar el código original.

        .. image:: img/create1.png

    .. code-block:: C

        void setup() {
            // put your setup code here, to run once:
            pinMode(13,OUTPUT); 
        }

        void loop() {
            // put your main code here, to run repeatedly:
            digitalWrite(13,HIGH);
            delay(500);
            digitalWrite(13,LOW);
            delay(500);
        }

#. Presiona ``Ctrl+S`` o haz clic en **File** -> **Save**. El Sketch se guarda por defecto en: ``C:\Users\{your_user}\Documents\Arduino``, puedes cambiarle el nombre o buscar una nueva ruta para guardarlo.

    .. image:: img/create2.png

#. Después de guardar con éxito, verás que el nombre en el IDE de Arduino se ha actualizado.

    .. image:: img/create3.png

Por favor, continúa con la siguiente sección para aprender cómo subir este sketch creado a tu placa Arduino.
