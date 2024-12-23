.. note:: 

    Bonjour et bienvenue dans la communauté Facebook des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 ! Plongez dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions spéciales.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_74hc595:

74HC595
===========

.. image:: img/74HC595.png

Le 74HC595 est composé d'un registre à décalage de 8 bits et d'un registre de stockage avec des sorties parallèles à trois états. Il convertit une entrée série en une sortie parallèle, ce qui permet d'économiser des ports IO d'un microcontrôleur (MCU).
Lorsque MR (broche 10) est à niveau haut et OE (broche 13) est à niveau bas, les données sont saisies sur le front montant de SHcp et sont transférées dans le registre mémoire via le front montant de SHcp. Si les deux horloges sont connectées ensemble, le registre à décalage est toujours un impulsion en avance par rapport au registre mémoire. Le registre mémoire dispose d'une broche d'entrée série (Ds), d'une broche de sortie série (Q) et d'un bouton de réinitialisation asynchrone (niveau bas). Le registre mémoire sort un bus parallèle 8 bits à trois états. Lorsque OE est activé (niveau bas), les données dans le registre mémoire sont sorties vers le bus.

* `Fiche technique du 74HC595 <https://www.ti.com/lit/ds/symlink/cd74hc595.pdf?ts=1617341564801>`_

.. image:: img/74hc595_pin.png
    :width: 600

Broches du 74HC595 et leurs fonctions :

* **Q0-Q7** : Broches de sortie de données parallèles 8 bits, capables de contrôler directement 8 LED ou 8 broches d'un affichage à 7 segments.
* **Q7’** : Broche de sortie série, connectée à DS d'un autre 74HC595 pour connecter plusieurs 74HC595 en série.
* **MR** : Broche de réinitialisation, active à niveau bas.
* **SHcp** : Entrée de séquence temporelle du registre à décalage. Sur le front montant, les données dans le registre à décalage se déplacent successivement d'un bit, par exemple, les données dans Q1 se déplacent vers Q2, et ainsi de suite. Sur le front descendant, les données dans le registre à décalage restent inchangées.
* **STcp** : Entrée de séquence temporelle du registre de stockage. Sur le front montant, les données dans le registre à décalage passent dans le registre mémoire.
* **CE** : Broche d'activation de sortie, active à niveau bas.
* **DS** : Broche d'entrée de données série.
* **VCC** : Tension d'alimentation positive.
* **GND** : Masse.

**Exemple**

* :ref:`ar_shiftout` (Projet de base)
* :ref:`ar_segment` (Projet de base)
* :ref:`iot_gate` (Projet IoT)




