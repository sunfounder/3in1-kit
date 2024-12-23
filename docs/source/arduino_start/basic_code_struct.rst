.. note::

    Bonjour et bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Explorez plus en profondeur Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Assistance experte** : Résolvez les problèmes après-vente et les défis techniques grâce à notre communauté et à notre équipe.
    - **Apprenez et partagez** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus exclusifs.
    - **Réductions spéciales** : Profitez de remises exclusives sur nos derniers produits.
    - **Promotions et concours festifs** : Participez à des concours et à des promotions de fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

Structure d'un programme Arduino
=====================================

Examinons un nouveau fichier de croquis. Bien qu'il ne contienne que quelques lignes de code, il s'agit en fait d'un croquis « vide ». 
Téléverser ce croquis sur la carte de développement n'aura aucun effet.

.. code-block:: C

    void setup() {
    // placez ici votre code de configuration, à exécuter une fois :

    }

    void loop() {
    // placez ici votre code principal, à exécuter en boucle :

    }

Si nous supprimons ``setup()`` et ``loop()`` et rendons le croquis véritablement « vide », vous constaterez qu'il ne passe pas la vérification. 
Ils sont l'équivalent du squelette humain, et ils sont indispensables.

Lors de l'écriture d'un croquis, ``setup()`` est exécuté en premier, et le code qu'il contient (entre ``{}``) est exécuté une fois lorsque la carte est alimentée ou réinitialisée. 
``loop()`` est utilisé pour écrire les fonctionnalités principales, et le code qu'il contient sera exécuté en boucle après ``setup()``.

Pour mieux comprendre ``setup()`` et ``loop()``, utilisons quatre croquis. Leur objectif est de faire clignoter la LED intégrée de l'Arduino. Veuillez exécuter chaque expérience à tour de rôle et observer leurs effets spécifiques.

* Croquis 1 : Faire clignoter la LED intégrée en continu.

.. code-block:: C
    :emphasize-lines: 8,9,10,11

    void setup() {
        // placez ici votre code de configuration, à exécuter une fois :
        pinMode(13,OUTPUT); 
    }

    void loop() {
        // placez ici votre code principal, à exécuter en boucle :
        digitalWrite(13,HIGH);
        delay(500);
        digitalWrite(13,LOW);
        delay(500);
    }

* Croquis 2 : Faire clignoter la LED intégrée une seule fois.

.. code-block:: C
    :emphasize-lines: 4,5,6,7

    void setup() {
        // placez ici votre code de configuration, à exécuter une fois :
        pinMode(13,OUTPUT);
        digitalWrite(13,HIGH);
        delay(500);
        digitalWrite(13,LOW);
        delay(500);
    }

    void loop() {
        // placez ici votre code principal, à exécuter en boucle :
    }

* Croquis 3 : Faire clignoter lentement la LED intégrée une fois, puis rapidement.

.. code-block:: C
    :emphasize-lines: 4,5,6,7,12,13,14,15

    void setup() {
        // placez ici votre code de configuration, à exécuter une fois :
        pinMode(13,OUTPUT);
        digitalWrite(13,HIGH);
        delay(1000);
        digitalWrite(13,LOW);
        delay(1000);
    }

    void loop() {
        // placez ici votre code principal, à exécuter en boucle :
        digitalWrite(13,HIGH);
        delay(200);
        digitalWrite(13,LOW);
        delay(200);
    }    

* Croquis 4 : Provoquer une erreur.

.. code-block:: C
    :emphasize-lines: 6,7,8,9

    void setup() {
        // placez ici votre code de configuration, à exécuter une fois :
        pinMode(13,OUTPUT);
    }

    digitalWrite(13,HIGH);
    delay(1000);
    digitalWrite(13,LOW);
    delay(1000);

    void loop() {
        // placez ici votre code principal, à exécuter en boucle :
    }    

Grâce à ces croquis, nous pouvons résumer plusieurs caractéristiques de ``setup-loop``.

* ``loop()`` sera exécuté en boucle après l'alimentation de la carte.
* ``setup()`` sera exécuté une seule fois après l'alimentation de la carte.
* Après l'alimentation de la carte, ``setup()`` sera exécuté en premier, suivi de ``loop()``.
* Le code doit être écrit dans le champ de ``{}`` de ``setup()`` ou ``loop()``, en dehors de ce cadre, il générera une erreur.

.. note::  
    Les instructions telles que ``digitalWrite(13,HIGH)`` servent à contrôler la LED intégrée, et nous détaillerons leur usage dans les chapitres suivants.
