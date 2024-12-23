.. note::

    Bonjour et bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez au cœur de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Assistance experte** : Résolvez les problèmes après-vente et relevez les défis techniques grâce à notre communauté et à notre équipe.
    - **Apprenez et partagez** : Échangez des conseils et des tutoriels pour développer vos compétences.
    - **Aperçus exclusifs** : Bénéficiez d'un accès anticipé aux annonces de nouveaux produits et à des aperçus exclusifs.
    - **Réductions spéciales** : Profitez de remises exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et à des promotions spéciales pour les fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

Règles d'écriture des croquis
==================================

Si vous demandez à un ami d'allumer la lumière, vous pouvez dire « Allume la lumière. » ou « Lumière allumée, mec. », en adoptant le ton que vous voulez.

Cependant, si vous voulez que la carte Arduino exécute une tâche pour vous, vous devez suivre les règles d'écriture des programmes Arduino pour rédiger vos commandes.

Ce chapitre contient les règles fondamentales du langage Arduino et vous aidera à comprendre comment traduire un langage naturel en code.

Bien entendu, c'est un processus qui demande du temps pour être maîtrisé. C'est également la partie la plus sujette aux erreurs pour les débutants. Si vous faites souvent des erreurs, ce n'est pas grave : essayez encore.


Point-virgule ``;``
-------------------

Tout comme un point marque la fin d'une phrase, en langage Arduino, un ``;`` indique la fin d'une commande.

Prenons l'exemple classique du clignotement de la LED intégrée. Un croquis valide devrait ressembler à ceci :

Exemple :

.. code-block:: C

    void setup() {
        // Placez ici votre code de configuration, exécuté une fois :
        pinMode(13,OUTPUT); 
    }

    void loop() {
        // Placez ici votre code principal, exécuté en boucle :
        digitalWrite(13,HIGH);
        delay(500);
        digitalWrite(13,LOW);
        delay(500);
    }

Examinons maintenant deux croquis et devinons s'ils peuvent être correctement interprétés par Arduino avant leur exécution.

Croquis A :

.. code-block:: C
    :emphasize-lines: 8,9,10,11

    void setup() {
        // Placez ici votre code de configuration, exécuté une fois :
        pinMode(13,OUTPUT); 
    }

    void loop() {
        // Placez ici votre code principal, exécuté en boucle :
        digitalWrite(13,HIGH)
        delay(500)
        digitalWrite(13,LOW)
        delay(500)
    }

Croquis B :

.. code-block:: C
    :emphasize-lines: 8,9,10,11,12,13,14,15,16

    void setup() {
        // Placez ici votre code de configuration, exécuté une fois :
        pinMode(13,OUTPUT);
    }
    
    void loop() {
        // Placez ici votre code principal, exécuté en boucle :
        digitalWrite(13,
    HIGH);  delay
        (500
        );
        digitalWrite(13,
        
        LOW);
                delay(500)
        ;
    }

Le résultat : **Croquis A** génère une erreur et **Croquis B** fonctionne.

* Les erreurs dans **Croquis A** sont dues à l'absence de ``;``. Bien qu'il semble correct, Arduino ne peut pas l'interpréter.
* **Croquis B**, bien que maladroitement présenté, est valide pour le compilateur Arduino, car les indentations, sauts de ligne et espaces n'ont pas d'importance.

Cependant, n'écrivez pas votre code comme **Croquis B**, car il est principalement destiné à être lu par des humains. Simplifiez-vous la tâche.


Accolades ``{}``
-------------------

Les accolades ``{}`` sont un élément clé du langage Arduino, et elles doivent apparaître 
par paires. Une bonne pratique consiste à insérer immédiatement une accolade fermante après 
avoir tapé une accolade ouvrante, puis à insérer le code entre les deux.



Commentaires ``//``
----------------------

Les commentaires sont des sections du croquis ignorées par le compilateur. Ils servent souvent à expliquer le fonctionnement du programme.

En écrivant deux barres obliques ``//`` dans une ligne, tout ce qui suit jusqu'à la fin de la ligne est ignoré.

Un nouveau croquis contient par défaut deux commentaires. Les supprimer n'affectera pas le croquis.

.. code-block:: C
    :emphasize-lines: 2,7

    void setup() {
        // Placez ici votre code de configuration, exécuté une fois :

    }

    void loop() {
        // Placez ici votre code principal, exécuté en boucle :

    }


Les commentaires sont très utiles. Voici quelques exemples :

* Usage A : Expliquez ce qu'une section de code réalise.

.. code-block:: C

    void setup() {
        pinMode(13,OUTPUT); // Configure la broche 13 en mode sortie pour contrôler la LED intégrée
    }

    void loop() {
        digitalWrite(13,HIGH); // Active la LED intégrée
        delay(500); // Attente de 500 ms
        digitalWrite(13,LOW); // Éteint la LED intégrée
        delay(500); // Attente de 500 ms
    }

* Usage B : Désactivez temporairement certaines instructions sans les supprimer.

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
    Utilisez ``Ctrl+/`` pour commenter ou décommenter rapidement votre code.

Commentaires ``/**/``
---------------------

Similaires aux ``//``, mais peuvent couvrir plusieurs lignes.

Exemple :

.. code-block:: C
    :emphasize-lines: 1,8,9,10,11

    /* Clignotement */

    void setup() {
        pinMode(13,OUTPUT); 
    }

    void loop() {
        /*
        Le code suivant fait clignoter la LED intégrée.
        Modifiez le nombre dans delay() pour ajuster la fréquence.
        */
        digitalWrite(13,HIGH); 
        delay(500); 
        digitalWrite(13,LOW); 
        delay(500);
    }

``#define``
-------------

Outil utile en C++, ``#define`` remplace un identifiant par une chaîne définie.
.. code-block:: C

    #define identifier token-string

Le compilateur remplace automatiquement ``identifier`` par ``token-string`` lorsqu'il le lit, ce qui est généralement utilisé pour définir des constantes.

À titre d'exemple, voici un croquis utilisant ``define``, ce qui améliore la lisibilité du code.

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

Pour le compilateur, cela revient à ceci.

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

Nous pouvons constater que l'``identifier`` est remplacé et n'existe pas dans le programme final.
Il y a donc plusieurs points importants à noter lors de son utilisation :

1. Une ``token-string`` ne peut être modifiée que manuellement et ne peut pas être transformée en d'autres valeurs par des opérations arithmétiques dans le programme.

2. Évitez d'utiliser des symboles tels que ``;``. Par exemple :

.. code-block:: C
    :emphasize-lines: 1

    #define ONBOARD_LED 13;

    void setup() {
        pinMode(ONBOARD_LED,OUTPUT); 
    }

    void loop() {
        digitalWrite(ONBOARD_LED,HIGH); 
    }

Le compilateur interprétera cela de la manière suivante, ce qui générera une erreur :

.. code-block:: C
    :emphasize-lines: 2,6

    void setup() {
        pinMode(13;,OUTPUT); 
    }

    void loop() {
        digitalWrite(13;,HIGH); 
    }

.. note:: 
    Une convention de nommage pour ``#define`` consiste à écrire ``identifier`` en majuscules afin d'éviter toute confusion avec les variables.
