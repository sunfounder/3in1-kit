.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _ar_dht11:


5.11.3 Temperatur - Luftfeuchtigkeit
=======================================

Temperatur und Luftfeuchtigkeit sind sowohl von der physikalischen Größe her als auch im täglichen Leben der Menschen eng miteinander verbunden. 
Die Temperatur und Luftfeuchtigkeit unserer Umgebung beeinflusst direkt die thermoregulatorische Funktion und den Wärmeübertragungseffekt des menschlichen Körpers. 
Dies kann weiterhin die Denkaktivität und den mentalen Zustand beeinflussen und somit unsere Lern- und Arbeitsleistung beeinträchtigen.

Die Temperatur ist eine der sieben grundlegenden physikalischen Größen im Internationalen Einheitensystem und dient zur Messung des Wärmezustands eines Objekts. 
Das Grad Celsius ist eine der weltweit am häufigsten verwendeten Temperaturskalen und wird durch das Symbol "℃" ausgedrückt.

Die Luftfeuchtigkeit gibt die Konzentration des in der Luft enthaltenen Wasserdampfs an. 
Die relative Luftfeuchtigkeit, häufig im Alltag verwendet, wird in %RH ausgedrückt. Sie hängt eng mit der Temperatur zusammen. 
Für ein bestimmtes Volumen eingeschlossenen Gases gilt: Je höher die Temperatur, desto niedriger die relative Luftfeuchtigkeit und umgekehrt.

.. image:: img/Dht11.png

Das im Kit enthaltene dht11 ist ein digitaler Temperatur- und Luftfeuchtigkeitssensor. Er nutzt einen kapazitiven Feuchtigkeitssensor und einen Thermistor, um die Umgebungsluft zu messen und gibt ein digitales Signal am Datenpin aus.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist definitiv praktisch, ein ganzes Kit zu kaufen, hier ist der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ARTIKEL IN DIESEM KIT
        - LINK
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

Sie können diese auch einzeln über die untenstehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - KOMPONENTENBESCHREIBUNG
        - KAUF-LINK

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_dht11`
        - \-

**Schaltplan**

.. image:: img/circuit_7.3_dht11.png

**Verdrahtung**

.. image:: img/dht11_bb.jpg

**Code**

.. note::

    * Öffnen Sie die Datei ``5.11.temperature_humidity.ino`` im Pfad ``3in1-kit\basic_project\5.11.temperature_humidity``.
    * Oder kopieren Sie diesen Code in die **Arduino IDE**.
    * Hier wird die ``DHT Sensorbibliothek`` verwendet, die Sie im **Library Manager** installieren können.

        .. image:: ../img/lib_dht11.png

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/c5b4c902-f39d-45a6-9a17-1308056041a8/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Nachdem der Code erfolgreich hochgeladen wurde, werden Sie sehen, dass der Serielle Monitor kontinuierlich Temperatur und Luftfeuchtigkeit ausgibt. Mit fortschreitender Laufzeit des Programms werden diese Werte immer genauer.


**Wie funktioniert das?**

#. Fügt die ``DHT.h``-Bibliothek hinzu, die Funktionen zur Interaktion mit den DHT-Sensoren bereitstellt. Anschließend legen Sie den Pin und den Typ für den DHT-Sensor fest.

    .. code-block:: arduino

        #include "DHT.h"

        #define DHTPIN 11  // Legt den mit dem DHT11-Datenpin verbundenen Pin fest
        #define DHTTYPE DHT11 // DHT 11 

        DHT dht(DHTPIN, DHTTYPE);

#. Initialisiert die serielle Kommunikation mit einer Baudrate von 115200 und initialisiert den DHT-Sensor.

    .. code-block:: arduino

        void setup() {
            Serial.begin(115200);
            Serial.println("DHT11 Test!");
            dht.begin();
        }

#. In der Funktion ``loop()`` werden die Temperatur- und Luftfeuchtigkeitswerte vom DHT11-Sensor gelesen und auf dem seriellen Monitor ausgegeben.

    .. code-block:: arduino

        void loop() {
            // Wait a few seconds between measurements.
            delay(2000);

            // Reading temperature or humidity takes about 250 milliseconds!
            // Sensor readings may also be up to 2 seconds 'old' (it's a very slow sensor)
            float humidity = dht.readHumidity();
            // Read temperature as Celsius (the default)
            float temperture = dht.readTemperature();

            // Check if any reads failed and exit early (to try again).
            if (isnan(humidity) || isnan(temperture)) {
                Serial.println("Failed to read from DHT sensor!");
                return;
            }
            // Print the humidity and temperature
            Serial.print("Humidity: ");
            Serial.print(humidity);
            Serial.print(" %\t");
            Serial.print("Temperature: ");
            Serial.print(temperture);
            Serial.println(" *C");
        }

    * Die Funktion ``dht.readHumidity()`` wird aufgerufen, um den Luftfeuchtigkeitswert vom DHT-Sensor zu lesen.
    * Die Funktion ``dht.readTemperature()`` wird aufgerufen, um den Temperaturwert vom DHT-Sensor zu lesen.
    * Die Funktion ``isnan()`` wird verwendet, um zu überprüfen, ob die Messwerte gültig sind. Wenn entweder der Luftfeuchtigkeits- oder Temperaturwert NaN (keine Zahl) ist, zeigt dies ein fehlerhaftes Lesen des Sensors an, und eine Fehlermeldung wird ausgegeben.

