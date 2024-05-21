.. note::

    Bonjour et bienvenue dans la Communauté Facebook des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez [|link_sf_facebook|] et rejoignez-nous aujourd'hui !

Comment créer, ouvrir ou enregistrer un sketch ?
====================================================

#. Lorsque vous ouvrez l'IDE Arduino pour la première fois ou créez un nouveau sketch, vous verrez une page comme celle-ci, où l'IDE Arduino crée un nouveau fichier pour vous, appelé "sketch".

    .. image:: img/sp221014_173458.png

    Ces fichiers de sketch ont un nom temporaire régulier, à partir duquel vous pouvez déterminer la date de création du fichier. ``sketch_oct14a.ino`` signifie le premier sketch du 14 octobre, ``.ino`` est le format de fichier de ce sketch.

#. Essayons maintenant de créer un nouveau sketch. Copiez le code suivant dans l'IDE Arduino pour remplacer le code original.


        .. image:: img/create1.png

    .. code-block:: C

        void setup() {
            // put your setup code here, to run once:
            pinMode(13,OUTPUT); 
        }

        void loop() {
            // put your main code here, to run repeatedly:
            digitalWrite(13,HIGH);
            delay(500);
            digitalWrite(13,LOW);
            delay(500);
        }

#. Appuyez sur ``Ctrl+S`` ou cliquez sur **File** -> **Save**. Le Sketch est enregistré dans : ``C:\Users\{votre_utilisateur}\Documents\Arduino`` par défaut, vous pouvez le renommer ou trouver un nouveau chemin pour l'enregistrer.

    .. image:: img/create2.png

#. Après l'enregistrement réussi, vous verrez que le nom dans l'IDE Arduino a été mis à jour.

    .. image:: img/create3.png

Veuillez continuer avec la section suivante pour apprendre à télécharger ce sketch créé sur votre carte Arduino.
