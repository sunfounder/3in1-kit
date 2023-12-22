.. _ar_lcd1602:

5.11.1 Affichage à Cristaux Liquides
====================================

Un LCD1602 I2C est composé d'un LCD1602 et d'un module I2C. Le LCD1602 peut être utilisé pour afficher des caractères, des nombres, etc., mais nécessite l'utilisation de nombreux pins du contrôleur principal. Après configuration d'un module I2C, seulement 2 pins I/O sont nécessaires pour piloter ce LCD1602.

Voyons maintenant comment faire fonctionner ce LCD1602 I2C.

**Composants requis**

Pour ce projet, nous aurons besoin des composants suivants.

Il est certainement pratique d'acheter un kit complet, voici le lien :

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nom	
        - ÉLÉMENTS DE CE KIT
        - LIEN
    *   - 3 in 1 Starter Kit
        - 380+
        - |link_3IN1_kit|

Vous pouvez également les acheter séparément via les liens ci-dessous.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUCTION DES COMPOSANTS
        - LIEN D'ACHAT

    *   - :ref:`cpn_uno`
        - |link_Uno_R3_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|


**Schéma**

.. image:: img/circuit_7.1_lcd1602.png

**Câblage**

.. image:: img/lcd_bb.jpg
    :width: 800
    :align: center

.. note::
    Les pins SDA et SCL de la carte R3 sont les pins A4 et A5.

**Code**

.. note::

    * Ouvrez le fichier ``5.11.liquid_crystal_display.ino`` situé dans le dossier ``3in1-kit\basic_project\5.11.liquid_crystal_display``.
    * Ou copiez ce code dans **Arduino IDE**.
    * La bibliothèque ``LiquidCrystal I2C`` est utilisée ici, vous pouvez l'installer depuis le **Library Manager**.

        .. image:: ../img/lib_liquidcrystal_i2c.png
    

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/e49c4936-2530-4890-b86c-1017d11eae6e/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Après le téléversement réussi du code, vous verrez "SunFounder", "Hello World" sur le LCD1602 I2C.

.. note::
    Si le code et le câblage sont corrects, mais que l'écran LCD n'affiche toujours pas de contenu, vous pouvez tourner le potentiomètre situé à l'arrière.

**Comment ça fonctionne ?**

En appelant la bibliothèque ``LiquidCrystal_I2C.h``, vous pouvez facilement piloter l'écran LCD.

.. code-block:: arduino

    #include "LiquidCrystal_I2C.h"

Fonctions de la bibliothèque : 

.. code-block:: arduino

    LiquidCrystal_I2C(uint8_t lcd_Addr,uint8_t lcd_cols,uint8_t lcd_rows)

Crée une nouvelle instance de la classe ``LiquidCrystal_I2C`` qui représente un
écran LCD particulier connecté à votre carte Arduino.

* ``lcd_AddR`` : L'adresse de l'écran LCD est par défaut 0x27.
* ``lcd_cols`` : Le LCD1602 a 16 colonnes.
* ``lcd_rows`` : Le LCD1602 a 2 lignes.


.. code-block:: arduino

    void init()

Initialise l'écran LCD.

.. code-block:: arduino

    void backlight()

Allume le rétroéclairage (optionnel).

.. code-block:: arduino

    void nobacklight()

Éteint le rétroéclairage (optionnel).

.. code-block:: arduino

    void display()

Allume l'affichage de l'écran LCD.

.. code-block:: arduino

    void nodisplay()

Éteint rapidement l'affichage de l'écran LCD.

.. code-block:: arduino

    void clear()

Efface l'écran et positionne le curseur à zéro.

.. code-block:: arduino

    void setCursor(uint8_t col,uint8_t row)

Positionne le curseur à la colonne col et à la ligne row.

.. code-block:: arduino

    void print(data,BASE)

Affiche du texte sur l'écran LCD.

* ``data`` : Les données à afficher (char, byte, int, long ou string).
* ``BASE (optionnel)`` : La base dans laquelle afficher les nombres : BIN pour binaire (base 2), DEC pour décimal (base 10), OCT pour octal (base 8), HEX pour hexadécimal (base 16).

