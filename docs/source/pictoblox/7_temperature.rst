.. _sh_low_temperature:

2.7 Alarme de Température Basse
===============================

Dans ce projet, nous allons créer un système d'alarme de basse température. Lorsque la température descend sous un seuil défini, le sprite **Flocon de Neige** apparaîtra sur la scène.

.. image:: img/9_tem.png

Vous Apprendrez
---------------------

- Principe de fonctionnement d'une thermistance
- Opérations multivariables et soustractives

Composants requis
---------------------

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_thermistor`
        - |link_thermistor_buy|

Construisez le Circuit
-----------------------

Une thermistance est un type de résistance dont la résistance dépend fortement de la température, bien plus que dans les résistances standards. Il existe deux types de résistances, PTC (la résistance augmente avec la température) et NTC (la résistance diminue avec la température).

Construisez le circuit selon le schéma suivant.

Une extrémité de la thermistance est connectée à GND, l'autre à A0, et une résistance de 10K est connectée en série à 5V.

La thermistance NTC est utilisée ici, donc lorsque la température augmente, la résistance de la thermistance diminue, la division de tension de A0 diminue, et la valeur obtenue de A0 diminue, et inversement elle augmente.

.. image:: img/circuit/thermistor_circuit.png

Programmation
------------------

**1. Sélectionnez un sprite**

Supprimez le sprite par défaut, cliquez sur le bouton **Choose a Sprite** dans le coin inférieur droit de la zone des sprites, entrez **Snowflake** dans la barre de recherche, puis cliquez pour l'ajouter.

.. image:: img/9_snow.png

**2. Créez 2 variables**

Créez deux variables, **before** et **current**, pour stocker la valeur de A0 dans différents cas.

.. image:: img/9_va.png

**3. Lisez la valeur de A0**

Lorsque le drapeau vert est cliqué, la valeur de A0 est lue et stockée dans la variable **before**.

.. image:: img/9_before.png

**4. Lisez à nouveau la valeur de A0**

Dans [forever], lisez à nouveau la valeur de A0 et stockez-la dans la variable **current**.

.. image:: img/9_current.png

**5. Détermination des changements de température**

Utilisez le bloc [if else] pour déterminer si la valeur actuelle de A0 est supérieure de 50 à celle d'avant, ce qui représente une baisse de température. Dans ce cas, laissez le sprite **Snowflake** apparaître, sinon cachez-le.

* [-] & [>]: opérateurs de soustraction et de comparaison de la palette **Operators**.

.. image:: img/9_show.png
