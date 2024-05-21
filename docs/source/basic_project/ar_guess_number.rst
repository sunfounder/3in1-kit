.. note::

    Bonjour et bienvenue dans la Communauté Facebook des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez [|link_sf_facebook|] et rejoignez-nous aujourd'hui !

.. _ar_guess_number:

6.6 Devinez le Nombre
=====================

Devinez le Nombre est un jeu de société amusant où vous et vos amis prenez
à tour de rôle l'initiative de saisir un nombre (0~99). La plage sera plus petite avec la
saisie du nombre jusqu'à ce qu'un joueur réponde correctement à l'énigme. Ensuite,
le joueur est battu et puni. Par exemple, si le nombre chanceux est
51, que les joueurs ne peuvent pas voir, et que le joueur 1 saisit 50, l'invite
de la plage de nombres change pour 50~99; si le joueur 2 saisit 70, la plage
de nombre peut être de 50~70; si le joueur 3 saisit 51, il ou elle est le
malchanceux. Ici, nous utilisons une télécommande IR pour saisir les nombres et un
LCD pour afficher les résultats.

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|
    *   - :ref:`cpn_receiver`
        - \-


**Schéma**

.. image:: img/circuit_guess_number.png
    :align: center

**Câblage**

Dans cet exemple, le câblage du LCD1602 et du module de réception infrarouge est
le suivant.

.. image:: img/wiring_guess_number.png
    :align: center


**Code**


.. note::

    * Vous pouvez ouvrir le fichier ``6.6.guess_number.ino`` sous le chemin de ``3in1-kit\basic_project\6.6.guess_number`` directement.
    * Ou copiez ce code dans Arduino IDE .
    * Les bibliothèques ``LiquidCrystal I2C`` et ``IRremote`` sont utilisées ici, vous pouvez les installer depuis le **Library Manager**.


.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/6bafb36d-6763-460c-98b7-aba48120e718/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Après le téléchargement réussi du code, les caractères de bienvenue apparaîtront sur le LCD1602. Appuyez maintenant sur le nombre selon l'invite de plage sur l'écran, l'affichage deviendra de plus en plus petit à moins que vous ne deviniez ce nombre chanceux.

.. note::
    Si le code et le câblage sont corrects, mais que le LCD n'affiche toujours pas de contenu, vous pouvez tourner le potentiomètre à l'arrière pour augmenter le contraste.

**Comment ça fonctionne ?**

Pour rendre le jeu de devinettes de nombres vivant et amusant, nous
devons réaliser les fonctions suivantes :

1. Le nombre chanceux sera affiché lorsque nous commençons et réinitialisons le jeu,
   et l'invite de plage de nombres est réinitialisée à 0 ~ 99.

2. Le LCD affichera le nombre saisi et l'invite de plage de nombres.

3. Après avoir saisi deux chiffres, un jugement de résultat apparaît
   automatiquement.

4. Si vous saisissez un seul chiffre, vous pouvez appuyer sur la touche CYCLE (la touche au
   centre de la télécommande) pour démarrer le jugement de résultat.

5. Si la réponse n'est pas devinée, la nouvelle invite de plage de nombres sera
   affichée (si le nombre chanceux est 51 et que vous entrez 50, l'invite
   de plage de nombres changera pour 50~99).

6. Le jeu est automatiquement réinitialisé après avoir deviné le nombre chanceux, pour
   que le joueur puisse jouer une nouvelle manche.

7. Le jeu peut être réinitialisé en appuyant directement sur le bouton POWER (le
   bouton dans le coin supérieur gauche).

En conclusion, le flux de travail du projet est illustré dans le diagramme de flux.

.. image:: img/Part_three_4_Example_Explanation.png
    :align: center




