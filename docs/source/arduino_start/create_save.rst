.. note::

    Bonjour, bienvenue dans la communauté SunFounder dédiée aux passionnés de Raspberry Pi, Arduino et ESP32 sur Facebook ! Explorez plus en profondeur Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes post-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et à des aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions spéciales.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

Comment créer, ouvrir ou enregistrer un Sketch ?
====================================================

#. Lorsque vous ouvrez l'Arduino IDE pour la première fois ou créez un nouveau sketch, vous verrez une page comme celle-ci, où l'IDE Arduino crée un nouveau fichier pour vous, appelé "sketch".

    .. image:: img/sp221014_173458.png

    Ces fichiers de sketch portent un nom temporaire standard, à partir duquel vous pouvez deviner la date de création du fichier. Par exemple, ``sketch_oct14a.ino`` signifie "premier sketch du 14 octobre", et ``.ino`` est le format de fichier de ce sketch.

#. Essayons maintenant de créer un nouveau sketch. Copiez le code suivant dans l'Arduino IDE pour remplacer le code original.

    .. image:: img/create1.png

    .. code-block:: C

        void setup() {
            // mettre votre code de configuration ici, à exécuter une seule fois :
            pinMode(13,OUTPUT); 
        }

        void loop() {
            // mettre votre code principal ici, à exécuter en boucle :
            digitalWrite(13,HIGH);
            delay(500);
            digitalWrite(13,LOW);
            delay(500);
        }

#. Appuyez sur ``Ctrl+S`` ou cliquez sur **Fichier** -> **Enregistrer**. Par défaut, le sketch est enregistré dans : ``C:\Users\{votre_utilisateur}\Documents\Arduino``. Vous pouvez renommer le fichier ou choisir un autre chemin pour l'enregistrer.

    .. image:: img/create2.png

#. Après un enregistrement réussi, vous verrez que le nom dans l'Arduino IDE a été mis à jour.

    .. image:: img/create3.png

Veuillez continuer avec la section suivante pour apprendre à téléverser ce sketch créé sur votre carte Arduino.
