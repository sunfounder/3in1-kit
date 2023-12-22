.. _cpn_led:

LED
==========

.. image:: img/LED.png
    :width: 400

La diode électroluminescente (LED) est un type de composant capable de transformer l'énergie électrique en énergie lumineuse via des jonctions PN. Selon la longueur d'onde, elle peut être catégorisée en diode laser, diode électroluminescente infrarouge et diode électroluminescente visible, communément appelée LED. 

La diode a une conductivité unidirectionnelle, donc le courant s'écoulera comme l'indique la flèche dans le symbole de circuit de la figure. Vous ne pouvez fournir que l'anode avec une puissance positive et la cathode avec une négative. Ainsi, la LED s'allumera.

.. image:: img/led_symbol.png

Une LED a deux broches. La plus longue est l'anode et la plus courte, la cathode. Faites attention à ne pas les connecter à l'envers. Il y a une chute de tension directe fixe dans la LED, donc elle ne peut pas être connectée directement au circuit car la tension d'alimentation peut dépasser cette chute et causer la combustion de la LED. La tension directe de la LED rouge, jaune et verte est de 1,8 V et celle de la blanche est de 2,6 V. La plupart des LED peuvent supporter un courant maximal de 20 mA, donc nous devons connecter une résistance limitant le courant en série.

La formule de la valeur de résistance est la suivante :

    R = (Vsupply – VD)/I

**R** représente la valeur de résistance de la résistance limitant le courant, **Vsupply** pour la tension d'alimentation, **VD** pour la chute de tension et **I** pour le courant de travail de la LED.

Voici une introduction détaillée pour la LED : `LED - Wikipédia <https://en.wikipedia.org/wiki/Light-emitting_diode>`_.

**Exemple**

* :ref:`ar_blink` (Projet de base)
* :ref:`ar_fading` (Projet de base)
* :ref:`iot_blink` (Projet IoT)
* :ref:`sh_breathing_led` (Projet Scratch)
* :ref:`sh_table_lamp` (Projet Scratch)

