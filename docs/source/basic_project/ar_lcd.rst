.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos nouveaux produits.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et à des promotions festives.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _ar_lcd1602:

5.11.1 Afficheur à Cristaux Liquides
========================================

Un écran I2C LCD1602 est composé d'un LCD1602 et d'un module I2C. Le LCD1602 peut afficher des caractères, des chiffres, etc., mais nécessite beaucoup de broches du contrôleur principal. Une fois configuré avec un module I2C, seulement 2 broches d'entrée/sortie sont nécessaires pour piloter ce LCD1602.

Voyons maintenant comment faire fonctionner cet I2C LCD1602.

**Composants nécessaires**

Dans ce projet, nous avons besoin des composants suivants :

C'est pratique d'acheter un kit complet, voici le lien :

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nom
        - ARTICLES DANS CE KIT
        - LIEN
    *   - Kit de démarrage 3 en 1
        - 380+
        - |link_3IN1_kit|

Vous pouvez également les acheter séparément via les liens ci-dessous.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUCTION DES COMPOSANTS
        - LIEN D'ACHAT

    *   - :ref:`cpn_uno`
        - \-
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|

**Schéma**

.. image:: img/circuit_7.1_lcd1602.png

**Câblage**

.. image:: img/5.11_lcd_bb.png
    :width: 800
    :align: center

.. note::
    Les broches SDA et SCL de la carte R4 sont respectivement les broches A4 et A5.

**Code**

.. note::

    * Ouvrez le fichier ``5.11.liquid_crystal_display.ino`` dans le répertoire ``3in1-kit\learning_project\5.11.liquid_crystal_display``.
    * Ou copiez ce code dans l'IDE Arduino.
    * La bibliothèque ``LiquidCrystal I2C`` est utilisée ici, vous pouvez l'installer depuis le **Library Manager**.

        .. image:: ../img/lib_liquidcrystal_i2c.png
    

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/e49c4936-2530-4890-b86c-1017d11eae6e/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Après le téléversement réussi du code, vous verrez "SunFounder" et "Hello World" sur l'I2C LCD1602.

.. note::
    Si le code et le câblage sont corrects, mais que le LCD n'affiche toujours pas de contenu, vous pouvez ajuster le potentiomètre situé à l'arrière.

**Comment ça fonctionne ?**

En appelant la bibliothèque ``LiquidCrystal_I2C.h``, vous pouvez facilement piloter le LCD.

.. code-block:: arduino

    #include "LiquidCrystal_I2C.h"

Fonctions de la bibliothèque :

.. code-block:: arduino

    LiquidCrystal_I2C(uint8_t lcd_Addr,uint8_t lcd_cols,uint8_t lcd_rows)

Crée une nouvelle instance de la classe ``LiquidCrystal_I2C`` représentant un LCD spécifique connecté à votre carte Arduino.

* ``lcd_AddR`` : L'adresse du LCD par défaut est 0x27.
* ``lcd_cols`` : Le LCD1602 dispose de 16 colonnes.
* ``lcd_rows`` : Le LCD1602 dispose de 2 lignes.

.. code-block:: arduino

    void init()

Initialise le LCD.

.. code-block:: arduino

    void backlight()

Active le rétroéclairage (optionnel).

.. code-block:: arduino

    void nobacklight()

Désactive le rétroéclairage (optionnel).

.. code-block:: arduino

    void display()

Active l'affichage du LCD.

.. code-block:: arduino

    void nodisplay()

Désactive rapidement l'affichage du LCD.

.. code-block:: arduino

    void clear()

Efface l'affichage et positionne le curseur à zéro.

.. code-block:: arduino

    void setCursor(uint8_t col,uint8_t row)

Positionne le curseur à la colonne et ligne spécifiées.

.. code-block:: arduino

    void print(data,BASE)

Imprime du texte sur le LCD.

* ``data`` : Les données à imprimer (char, byte, int, long ou string).
* ``BASE (optionnel)`` : La base pour imprimer les nombres : BIN pour binaire (base 2), DEC pour décimal (base 10), OCT pour octal (base 8), HEX pour hexadécimal (base 16).
