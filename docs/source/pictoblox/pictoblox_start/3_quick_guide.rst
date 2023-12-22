.. _sh_guide:

1.3 Guide rapide sur PictoBlox
====================================

Apprenons maintenant comment utiliser PictoBlox dans deux modes.

De plus, il y a une LED intégrée connectée à la broche 13 sur la carte R3, nous allons apprendre à faire clignoter cette LED dans 2 modes différents.

.. image:: img/1_led.jpg
    :width: 500
    :align: center

.. _stage_mode:

Mode Scène
---------------

**1. Connecter à la carte Arduino**

Connectez votre carte Arduino à l'ordinateur avec un câble USB, généralement l'ordinateur reconnaîtra automatiquement votre carte et finalement attribuera un port COM.

Ouvrez PictoBlox, l'interface de programmation Python s'ouvrira par défaut. Et nous devons passer à l'interface des Blocs.

.. image:: img/0_choose_blocks.png

Vous verrez alors le coin supérieur droit pour le changement de mode. Le mode par défaut est le mode Scène, où Tobi se tient sur la scène.

.. image:: img/1_stage_upload.png

Cliquez sur **Board** dans la barre de navigation en haut à droite pour sélectionner la carte.

.. image:: img/1_board.png

Par exemple, choisissez **Arduino Uno**.

.. image:: img/1_choose_uno.png

Une fenêtre de connexion s'ouvrira alors pour que vous sélectionniez le port à connecter, et retournez à la page d'accueil lorsque la connexion est complète. Si vous interrompez la connexion pendant l'utilisation, vous pouvez également cliquer sur **Connect** pour vous reconnecter.

.. image:: img/1_connect.png

En même temps, les palettes liées à l'Arduino Uno, telles que Arduino Uno, Actuators, etc., apparaîtront dans la **Block Palette**.

.. image:: img/1_arduino_uno.png

**2. Télécharger le Firmware**

Comme nous allons travailler dans le mode Scène, nous devons télécharger le firmware sur la carte. Cela garantira une communication en temps réel entre la carte et l'ordinateur. Télécharger le firmware est un processus ponctuel. Pour ce faire, cliquez sur le bouton Télécharger le Firmware.

Après avoir attendu un moment, le message de réussite de téléchargement apparaîtra.

.. note::

    Si vous utilisez cette carte Arduino dans PictoBlox pour la première fois, ou si cet Arduino a été précédemment téléchargé avec l'IDE Arduino. Alors vous devez appuyer sur **Upload Firmware** avant de pouvoir l'utiliser.


.. image:: img/1_firmware.png


**3. Programmation**

* Ouvrir et exécuter le script directement

Bien sûr, vous pouvez ouvrir directement les scripts pour les exécuter, mais veuillez d'abord les télécharger depuis `github <https://github.com/sunfounder/3in1-kit/archive/refs/heads/main.zip>`_.

Vous pouvez cliquer sur **File** dans le coin supérieur droit, puis choisir **Open**.

.. image:: img/0_open.png

Choisissez **Open from Computer**.

.. image:: img/0_dic.png

Allez ensuite dans le chemin de ``3in1-kit\scratch_project\code``, et ouvrez **1. Stage Mode.sb3**. Veuillez vous assurer d'avoir téléchargé le code requis depuis `github <https://github.com/sunfounder/3in1-kit/archive/refs/heads/main.zip>`_.

.. image:: img/0_stage.png

Cliquez directement sur le script pour l'exécuter, certains projets nécessitent de cliquer sur le drapeau vert ou sur le sprite.

.. image:: img/1_more.png

* Programmer étape par étape

Vous pouvez également écrire le script étape par étape en suivant ces étapes.

Cliquez sur la palette **Arduino Uno**.

.. image:: img/1_arduino_uno.png

La LED sur la carte Arduino est contrôlée par la broche numérique 13 (seulement 2 états, HIGH ou LOW), donc glissez le bloc [set digital pin out as] dans la zone de script.

Puisque l'état par défaut de la LED est allumé, réglez maintenant la broche 13 sur LOW et cliquez sur ce bloc et vous verrez la LED s'éteindre.

* [set digital pin out as] : Régler les broches numériques (2~13) au niveau (HIGH/LOW).

.. image:: img/1_digital.png

Pour voir l'effet d'une LED clignotante continue, vous devez utiliser les blocs [Wait 1 seconds] et [forever] dans la palette **Contrôle**. Cliquez sur ces blocs après les avoir écrits, un halo jaune signifie qu'ils sont en cours d'exécution.

* [Wait 1 seconde] : de la palette **Contrôle**, utilisé pour définir l'intervalle de temps entre 2 blocs.
* [forever] : de la palette **Contrôle**, permet au script de continuer à s'exécuter à moins d'être mis en pause manuellement.

.. image:: img/1_more.png

.. _upload_mode:

Mode Téléchargement
-----------------------

**1. Connecter à la carte Arduino**

Connectez votre carte Arduino à l'ordinateur avec un câble USB, généralement l'ordinateur reconnaîtra automatiquement votre carte et finalement attribuera un port COM.

Ouvrez PictoBlox et cliquez sur **Board** dans la barre de navigation en haut à droite pour sélectionner la carte.

.. image:: img/1_board.png

Par exemple, choisissez **Arduino Uno**.

.. image:: img/1_choose_uno.png

Une fenêtre de connexion s'ouvrira alors pour que vous sélectionniez le port à connecter, et retournez à la page d'accueil lorsque la connexion est complète. Si vous interrompez la connexion pendant l'utilisation, vous pouvez également cliquer sur **Connect** pour vous reconnecter.

.. image:: img/1_connect.png

En même temps, les palettes liées à l'Arduino Uno, telles que Arduino Uno, Actuators, etc., apparaîtront dans la **Block Palette**.

.. image:: img/1_upload_uno.png

Après avoir sélectionné le mode Téléchargement, la scène passera à la zone de code Arduino originale.

.. image:: img/1_upload.png

**2. Programmation**

* Ouvrir et exécuter le script directement

Vous pouvez cliquer sur **File** dans le coin supérieur droit.

.. image:: img/0_open.png

Choisissez **Open from Computer**.

.. image:: img/0_dic.png

Ensuite, allez au chemin ``3in1-kit\scratch_project\code``, et ouvrez **1. Upload Mode.sb3**. Veuillez vous assurer d'avoir téléchargé le code requis depuis `github <https://github.com/sunfounder/3in1-kit/archive/refs/heads/main.zip>`_.

.. image:: img/0_upload.png

Enfin, cliquez sur le bouton **Upload Code**.

.. image:: img/1_upload_code.png


* Programmer étape par étape

Vous pouvez également écrire le script étape par étape en suivant ces étapes.

Cliquez sur la palette **Arduino Uno**.

.. image:: img/1_upload_uno.png

Glissez [when Arduino Uno starts up] dans la zone de script, ce qui est requis pour chaque script.

.. image:: img/1_uno_starts.png

La LED sur la carte Arduino est contrôlée par la broche numérique 13 (seulement 2 états HIGH ou LOW), donc glissez le bloc [set digital pin out as] dans la zone de script.

Puisque l'état par défaut de la LED est allumé, réglez maintenant la broche 13 sur LOW et cliquez sur ce bloc et vous verrez la LED s'éteindre.

* [set digital pin out as] : Régler la broche numérique (2~13) au niveau (HIGH/LOW).

.. image:: img/1_upload_digital.png

À ce stade, vous verrez le code Arduino apparaître sur le côté droit, si vous souhaitez éditer ce code, vous pouvez activer le mode Édition.

.. image:: img/1_upload1.png

Pour voir l'effet d'une LED clignotante continue, vous devez utiliser les blocs [Wait 1 seconds] et [forever] dans la palette **Contrôle**. Cliquez sur ces blocs après les avoir écrits, un halo jaune signifie qu'ils sont en cours d'exécution.

* [Wait 1 seconds] : de la palette **Contrôle**, utilisé pour définir l'intervalle de temps entre 2 blocs.
* [forever] : de la palette **Contrôle**, permet au script de continuer à s'exécuter à moins que l'alimentation soit coupée.

.. image:: img/1_upload_more.png

Enfin, cliquez sur le bouton **Upload Code**.

.. image:: img/1_upload_code.png
