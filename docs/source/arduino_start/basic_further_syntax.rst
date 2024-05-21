.. note::

    Bonjour et bienvenue dans la Communauté Facebook des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez [|link_sf_facebook|] et rejoignez-nous aujourd'hui !

Règle de Rédaction d'un Sketch
================================

Si vous demandez à un ami d'allumer les lumières pour vous, vous pouvez dire "Allume les lumières.", ou "Lumières allumées, mon pote.", vous pouvez utiliser n'importe quel ton de voix que vous souhaitez.

Cependant, si vous voulez que la carte Arduino fasse quelque chose pour vous, vous devez suivre les règles de rédaction des programmes Arduino pour taper les commandes.

Ce chapitre contient les règles de base du langage Arduino et vous aidera à comprendre comment traduire le langage naturel en code.

Bien sûr, c'est un processus qui prend du temps pour se familiariser, et c'est aussi la partie du processus la plus sujette aux erreurs pour les débutants, donc si vous faites souvent des erreurs, c'est normal, essayez juste quelques fois de plus.


Point-virgule ``;``
---------------------

Tout comme l'écriture d'une lettre, où vous mettez un point à la fin de chaque phrase comme fin, le langage Arduino vous demande d'utiliser ``;`` pour indiquer à la carte la fin de la commande.

Prenons l'exemple familier du "clignotement de la LED intégrée". Un sketch correct devrait ressembler à ceci.

Exemple :

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

Ensuite, examinons les deux sketches suivants et devinons s'ils peuvent être correctement reconnus par Arduino avant de les exécuter.

Sketch A :

.. code-block:: C
    :emphasize-lines: 8,9,10,11

    void setup() {
        // put your setup code here, to run once:
        pinMode(13,OUTPUT); 
    }

    void loop() {
        // put your main code here, to run repeatedly:
        digitalWrite(13,HIGH)
        delay(500)
        digitalWrite(13,LOW)
        delay(500)
    }

Sketch B :

.. code-block:: C
    :emphasize-lines: 8,9,10,11,12,13,14,15,16

    void setup() {
        // put your setup code here, to run once:
        pinMode(13,OUTPUT);
    }
    
    void loop() {
        // put your main code here, to run repeatedly:
        digitalWrite(13,
    HIGH);  delay
        (500
        );
        digitalWrite(13,
        
        LOW);
                delay(500)
        ;
    }

Le résultat est que le **Sketch A** signale une erreur et le **Sketch B** fonctionne.

* Les erreurs dans le **Sketch A** sont dues à l'absence de ``;`` et bien qu'il semble normal, l'Arduino ne peut pas le lire.
* Le **Sketch B**, bien qu'il paraisse anti-humain, est en fait compréhensible pour l'Arduino. En effet, l'indentation, les sauts de ligne et les espaces dans les instructions sont des éléments qui n'existent pas dans les programmes Arduino, donc pour le compilateur Arduino, il apparaît identique à l'exemple.

Cependant, veuillez ne pas écrire votre code comme le **Sketch B**, car ce sont généralement des personnes naturelles qui écrivent et consultent le code, donc ne vous compliquez pas la tâche.


Accolades ``{}``
------------------

Les ``{}`` sont un composant principal du langage de programmation Arduino, et elles doivent apparaître par paires. 
Une meilleure convention de programmation est d'insérer une structure nécessitant des accolades en tapant l'accolade droite juste après avoir tapé l'accolade gauche, puis en déplaçant le curseur entre les accolades pour insérer l'instruction.



Commentaire ``//``
------------------

Le commentaire est la partie du sketch que le compilateur ignore. Ils sont généralement utilisés pour expliquer aux autres comment fonctionne le programme.

Si nous écrivons deux barres obliques adjacentes dans une ligne de code, le compilateur ignorera tout jusqu'à la fin de la ligne.

Si nous créons un nouveau sketch, il est livré avec deux commentaires, et si nous supprimons ces deux commentaires, le sketch ne sera en aucun cas affecté.


.. code-block:: C
    :emphasize-lines: 2,7

    void setup() {
        // put your setup code here, to run once:

    }

    void loop() {
        // put your main code here, to run repeatedly:

    }


Le commentaire est très utile en programmation, et plusieurs utilisations courantes sont listées ci-dessous.

* Utilisation A : Se dire à soi-même ou à d'autres ce que cette section de code fait.

.. code-block:: C

    void setup() {
        pinMode(13,OUTPUT); //Set pin 13 to output mode, it controls the onboard LED
    }

    void loop() {
        digitalWrite(13,HIGH); // Activate the onboard LED by setting pin 13 high
        delay(500); // Status quo for 500 ms
        digitalWrite(13,LOW); // Turn off the onboard LED
        delay(500);// Status quo for 500 ms
    }

* Utilisation B : Invalider temporairement certaines déclarations (sans les supprimer) et les décommenter lorsque vous avez besoin de les utiliser, pour ne pas avoir à les réécrire. Cela est très utile lors du débogage du code et de la tentative de localisation des erreurs du programme.

.. code-block:: C
    :emphasize-lines: 3,4,5,6

    void setup() {
        pinMode(13,OUTPUT);
        // digitalWrite(13,HIGH);
        // delay(1000);
        // digitalWrite(13,LOW);
        // delay(1000);
    }

    void loop() {
        digitalWrite(13,HIGH);
        delay(200);
        digitalWrite(13,LOW);
        delay(200);
    }    

.. note:: 
    Utilisez le raccourci ``Ctrl+/`` pour vous aider à commenter ou décommenter rapidement votre code.

Commentaire ``/**/``
-----------------------

Comme ``//`` pour les commentaires. Ce type de commentaire peut s'étendre sur plus d'une ligne, et une fois que le compilateur lit ``/*``, il ignore tout ce qui suit jusqu'à ce qu'il rencontre ``*/``.

Exemple 1 :

.. code-block:: C
    :emphasize-lines: 1,8,9,10,11

    /* Blink */

    void setup() {
        pinMode(13,OUTPUT); 
    }

    void loop() {
        /*
        The following code will blink the onboard LED
        You can modify the number in delay() to change the blinking frequency
        */
        digitalWrite(13,HIGH); 
        delay(500); 
        digitalWrite(13,LOW); 
        delay(500);
    }


``#define``
--------------

C'est un outil utile de C++.

.. code-block:: C

    #define identifier token-string

Le compilateur remplace automatiquement ``identifier`` par ``token-string`` lorsqu'il le lit, ce qui est généralement utilisé pour des définitions constantes.

Par exemple, voici un sketch qui utilise define, ce qui améliore la lisibilité du code.

.. code-block:: C
    :emphasize-lines: 1,2

    #define ONBOARD_LED 13
    #define DELAY_TIME 500

    void setup() {
        pinMode(ONBOARD_LED,OUTPUT); 
    }

    void loop() {
        digitalWrite(ONBOARD_LED,HIGH); 
        delay(DELAY_TIME); 
        digitalWrite(ONBOARD_LED,LOW); 
        delay(DELAY_TIME);
    }

Pour le compilateur, cela ressemble réellement à ceci.

.. code-block:: C

    void setup() {
        pinMode(13,OUTPUT); 
    }

    void loop() {
        digitalWrite(13,HIGH); 
        delay(500); 
        digitalWrite(13,LOW); 
        delay(500);
    }

Nous pouvons voir que l'``identifiant`` est remplacé et n'existe pas dans le programme.
Par conséquent, il y a plusieurs mises en garde lors de son utilisation.

1. Une ``token-string`` ne peut être modifiée manuellement et ne peut pas être convertie en d'autres valeurs par arithmétique dans le programme.

2. Évitez d'utiliser des symboles tels que ``;``. Par exemple.

.. code-block:: C
    :emphasize-lines: 1

    #define ONBOARD_LED 13;

    void setup() {
        pinMode(ONBOARD_LED,OUTPUT); 
    }

    void loop() {
        digitalWrite(ONBOARD_LED,HIGH); 
    }

Le compilateur le reconnaîtra comme suit, ce qui sera signalé comme une erreur.

.. code-block:: C
    :emphasize-lines: 2,6

    void setup() {
        pinMode(13;,OUTPUT); 
    }

    void loop() {
        digitalWrite(13;,HIGH); 
    }

.. note:: 
    Une convention de nommage pour ``#define`` est de mettre en majuscule l'``identifier`` pour éviter la confusion avec les variables.
