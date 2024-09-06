.. note::

    Ciao, benvenuto nella Community di appassionati di SunFounder per Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 con altri appassionati.

    **Perché unirti a noi?**

    - **Supporto di esperti**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci dei nuovi prodotti e alle anteprime esclusive.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a omaggi e promozioni speciali durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!

.. _cpn_l298n:

Modulo L298N
==================================

Il modulo driver motore L298N è un driver di potenza elevata per controllare motori DC e motori passo-passo. Questo modulo include un IC driver L298 e un regolatore 78M05 a 5V. Il modulo L298N può controllare fino a 4 motori DC, o 2 motori DC con controllo di direzione e velocità.

.. image:: img/l298n_pin.jpg
    :width: 400
    :align: center

* **IN1 & IN2**: Pin di ingresso del motore A. Utilizzati per controllare la direzione di rotazione del motore A.
* **IN3 & IN4**: Pin di ingresso del motore B. Utilizzati per controllare la direzione di rotazione del motore B.
* **ENA**: Abilita il segnale PWM per il motore A. Qui è collegato a 5V con un jumper.
* **ENB**: Abilita il segnale PWM per il motore B. Qui è collegato a 5V con un jumper.
* **OUT1 & OUT2**: Pin di uscita del motore A.
* **OUT3 & OUT4**: Pin di uscita del motore B.
* **12V**: Ingresso 12V da una fonte di alimentazione DC.
* **5V**: Fornisce alimentazione per il circuito logico interno dell'IC L298N.
* **GND**: Pin di massa.

**Caratteristiche**

* Modello driver: L298N 2A
* Chip driver: Ponte H doppio L298N
* Tensione di alimentazione del motore (massima): 46V
* Corrente di alimentazione del motore (massima): 2A
* Tensione logica: 5V
* Tensione di alimentazione del driver: 5-35V
* Corrente del driver: 2A
* Corrente logica: 0-36mA
* Potenza massima (W): 25W
* Rilevamento di corrente per ogni motore
* Dissipatore di calore per migliori prestazioni
* Indicatore LED di accensione

**Principio di funzionamento**

Il modulo driver può controllare due motori. I terminali abilitati ENA e ENB sono efficaci a livello alto.

La relazione di funzionamento tra ENA e IN1, IN2 è la seguente:


.. list-table:: 
    :widths: 25 25 25 50
    :header-rows: 1

    * - ENA
      - IN1
      - IN2
      - Stato del motore A
    * - 0
      - X
      - X
      - Stop
    * - 1
      - 0
      - 0
      - Freno
    * - 1
      - 0
      - 1
      - Rotazione oraria
    * - 1
      - 1
      - 0
      - Rotazione antioraria
    * - 1
      - 1
      - 1
      - Freno

La relazione di funzionamento tra ENB e IN3, IN4 è la seguente.

.. list-table:: 
    :widths: 25 25 25 50
    :header-rows: 1

    * - ENB
      - IN3
      - IN4
      - Stato del motore B
    * - 0
      - X
      - X
      - Stop
    * - 1
      - 0
      - 0
      - Freno
    * - 1
      - 0
      - 1
      - Rotazione oraria
    * - 1
      - 1
      - 0
      - Rotazione antioraria
    * - 1
      - 1
      - 1
      - Freno


**Informazioni sul cappuccio di abilitazione a 5V**

Il modulo driver motore L298N include un IC driver motore L298, un regolatore di tensione 78M05, resistenze, condensatore, LED di alimentazione e jumper 5V in un circuito integrato.

.. image:: img/l298n_introduce.jpg
    :width: 500
    :align: center

Il regolatore di tensione 78M05 sarà abilitato solo quando il jumper è inserito. Quando l'alimentazione è inferiore o uguale a 12V, il circuito interno sarà alimentato dal regolatore di tensione e il pin 5V può essere utilizzato come pin di uscita per alimentare il microcontrollore.

Il jumper non deve essere inserito quando l'alimentazione supera i 12V e deve essere fornita un'alimentazione separata di 5V tramite il terminale 5V per alimentare il circuito interno.


* `L298N datasheet <https://www.yerical.com/product/L298N?product/XXXXX?source=adg&gclid=CjwKCAjwkYGVBhArEiwA4sZLuKEC19ydceKs396z1JENqjcbJDEvedRkcsza1aH_swhuNPWzL-CYfRoCMTMQAvD_BwE#g-pd-res>`_


**Esempio**

* :ref:`ar_motor` (Basic Project)
* :ref:`car_move` (Car Project)
* :ref:`car_speed` (Car Project)
* :ref:`iot_car` (IoT Project)
* :ref:`sh_test` (Scratch Project)


