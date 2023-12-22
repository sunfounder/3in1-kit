Structure du Programme Arduino
================================

Jetons un coup d'œil au nouveau fichier de sketch. Bien qu'il ait quelques lignes de code, c'est en réalité un sketch "vide". 
Le téléchargement de ce sketch sur la carte de développement ne provoquera aucun effet.

.. code-block:: C

    void setup() {
    // put your setup code here, to run once:

    }

    void loop() {
    // put your main code here, to run repeatedly:

    }

Si nous supprimons ``setup()`` et ``loop()`` pour rendre le sketch vraiment ``blank``, vous constaterez qu'il ne passe pas la vérification. 
Ils sont l'équivalent du squelette humain, et sont indispensables.

Lors de la création d'un sketch, ``setup()`` est exécuté en premier, et le code à l'intérieur (dans ``{}``) est exécuté après que la carte soit alimentée ou réinitialisée et seulement une fois. 
``loop()`` est utilisé pour écrire la fonction principale, et le code à l'intérieur s'exécute en boucle après l'exécution de ``setup()``.

Pour mieux comprendre setup() et loop(), utilisons quatre sketches. Leur but est de faire clignoter la LED intégrée de l'Arduino. Veuillez exécuter chaque expérience à tour de rôle et enregistrer leurs effets spécifiques.

* Sketch 1 : Faire clignoter la LED intégrée en continu.

.. code-block:: C
    :emphasize-lines: 8,9,10,11

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

* Sketch 2 : Faire clignoter la LED intégrée une seule fois. 

.. code-block:: C
    :emphasize-lines: 4,5,6,7

    void setup() {
        // put your setup code here, to run once:
        pinMode(13,OUTPUT);
        digitalWrite(13,HIGH);
        delay(500);
        digitalWrite(13,LOW);
        delay(500);
    }

    void loop() {
        // put your main code here, to run repeatedly:
    }

* Sketch 3 : Faire clignoter lentement la LED intégrée une fois, puis rapidement. 

.. code-block:: C
    :emphasize-lines: 4,5,6,7,12,13,14,15

    void setup() {
        // put your setup code here, to run once:
        pinMode(13,OUTPUT);
        digitalWrite(13,HIGH);
        delay(1000);
        digitalWrite(13,LOW);
        delay(1000);
    }

    void loop() {
        // put your main code here, to run repeatedly:
        digitalWrite(13,HIGH);
        delay(200);
        digitalWrite(13,LOW);
        delay(200);
    }    

* Sketch 4 : Signaler une erreur.

.. code-block:: C
    :emphasize-lines: 6,7,8,9

    void setup() {
        // put your setup code here, to run once:
        pinMode(13,OUTPUT);
    }

    digitalWrite(13,HIGH);
    delay(1000);
    digitalWrite(13,LOW);
    delay(1000);

    void loop() {
        // put your main code here, to run repeatedly:
    }    

Avec l'aide de ces sketches, nous pouvons résumer plusieurs caractéristiques de ``setup-loop``.

* ``loop()`` s'exécute de manière répétée après que la carte soit alimentée. 
* ``setup()`` s'exécute une seule fois après que la carte soit alimentée. 
* Après que la carte soit alimentée, ``setup()`` s'exécute en premier, suivi par ``loop()``. 
* Le code doit être écrit à l'intérieur du cadre ``{}`` de ``setup()`` ou ``loop()``, en dehors du cadre, il y aura une erreur.

.. note::  
    Des instructions telles que ``digitalWrite(13,HIGH)`` sont utilisées pour contrôler la LED intégrée, et nous parlerons de leur utilisation en détail dans les chapitres suivants.



