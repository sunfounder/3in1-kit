.. note::

    Bonjour et bienvenue dans la Communauté Facebook des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez [|link_sf_facebook|] et rejoignez-nous aujourd'hui !

Comment télécharger un sketch sur la carte ?
=============================================

Dans cette section, vous apprendrez comment télécharger le sketch créé précédemment sur la carte Arduino, ainsi que quelques considérations.

**1. Choisir la Carte et le port**

Les cartes de développement Arduino sont généralement fournies avec un câble USB. Vous pouvez l'utiliser pour connecter la carte à votre ordinateur.

Sélectionnez la **Carte** et le **Port** corrects dans l'IDE Arduino. Normalement, les cartes Arduino sont automatiquement reconnues par l'ordinateur et se voient attribuer un port, que vous pouvez donc sélectionner ici.

    .. image:: img/board_port.png

Si votre carte est déjà branchée mais n'est pas reconnue, vérifiez si le logo **INSTALLED** apparaît dans la section **Arduino AVR Boards** du **Boards Manager**, si ce n'est pas le cas, faites défiler un peu vers le bas et cliquez sur **INSTALL**.

    .. image:: img/upload1.png

La réouverture de l'IDE Arduino et le rebranchement de la carte Arduino résoudront la plupart des problèmes. Vous pouvez également cliquer sur **Tools** -> **Board** ou **Port** pour les sélectionner.

**2. Vérifier le Sketch**

Après avoir cliqué sur le bouton Vérifier, le sketch sera compilé pour voir s'il y a des erreurs.

    .. image:: img/sp221014_174532.png

Vous pouvez l'utiliser pour trouver des erreurs si vous supprimez des caractères ou tapez quelques lettres par erreur. Depuis la barre de messages, vous pouvez voir où et quel type d'erreurs se sont produites.

    .. image:: img/sp221014_175307.png

S'il n'y a pas d'erreurs, vous verrez un message comme celui ci-dessous.

    .. image:: img/sp221014_175512.png

**3. Télécharger le sketch**

Après avoir complété les étapes ci-dessus, cliquez sur le bouton **Upload** pour charger ce sketch sur la carte.

    .. image:: img/sp221014_175614.png

Si le téléchargement est réussi, vous pourrez voir l'invite suivante.

.. image:: img/sp221014_175654.png

En même temps, la LED intégrée à la carte clignotera.

.. image:: img/1_led.jpg

La carte Arduino exécutera automatiquement le sketch après l'application de l'alimentation une fois le sketch téléchargé. Le programme en cours peut être écrasé en téléchargeant un nouveau sketch.

