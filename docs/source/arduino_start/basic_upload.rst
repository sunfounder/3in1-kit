.. note::

    Bonjour, bienvenue dans la communauté SunFounder dédiée aux passionnés de Raspberry Pi, Arduino et ESP32 sur Facebook ! Explorez plus en profondeur Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes post-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et à des aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions spéciales.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

Comment téléverser un sketch sur la carte ?
===============================================

Dans cette section, vous apprendrez à téléverser le sketch créé précédemment sur la carte Arduino, ainsi que quelques considérations importantes.

**1. Choisir la carte et le port**

Les cartes de développement Arduino sont généralement fournies avec un câble USB. Utilisez-le pour connecter la carte à votre ordinateur.

Sélectionnez la **Carte** et le **Port** appropriés dans l'Arduino IDE. En général, les cartes Arduino sont automatiquement reconnues par l'ordinateur et un port leur est assigné, que vous pouvez sélectionner ici.

    .. image:: img/board_port.png

Si votre carte est déjà branchée mais non reconnue, vérifiez si le logo **INSTALLED** apparaît dans la section **Arduino UNO R4 Boards** du **Gestionnaire de cartes**. Si ce n'est pas le cas, faites défiler un peu et cliquez sur **INSTALL**.

    .. image:: img/upload1.png

Réouvrir l'Arduino IDE et rebrancher la carte Arduino résout la plupart des problèmes. Vous pouvez également cliquer sur **Outils** -> **Carte** ou **Port** pour les sélectionner.


**2. Vérifiez le sketch**

Après avoir cliqué sur le bouton Vérifier, le sketch sera compilé pour vérifier s'il y a des erreurs.

    .. image:: img/sp221014_174532.png

Utilisez cette fonction pour corriger des erreurs si vous avez supprimé des caractères ou tapé accidentellement des lettres. Dans la barre de messages, vous pouvez voir où et quel type d'erreurs se sont produites.

    .. image:: img/sp221014_175307.png

S'il n'y a pas d'erreurs, un message comme celui-ci s'affichera.

    .. image:: img/sp221014_175512.png


**3. Téléverser le sketch**

Après avoir complété les étapes ci-dessus, cliquez sur le bouton **Téléverser** pour téléverser ce sketch sur la carte.

    .. image:: img/sp221014_175614.png

En cas de succès, vous verrez l'invite suivante.

    .. image:: img/sp221014_175654.png

Simultanément, la LED intégrée clignotera.

    .. image:: img/1_led.jpg

La carte Arduino exécutera automatiquement le sketch après l'application de l'alimentation, une fois le sketch téléversé. Le programme en cours peut être écrasé en téléversant un nouveau sketch.
