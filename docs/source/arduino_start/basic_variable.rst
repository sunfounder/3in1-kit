.. note::

    Bonjour, bienvenue dans la communauté SunFounder dédiée aux passionnés de Raspberry Pi, Arduino et ESP32 sur Facebook ! Explorez plus en profondeur Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes post-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et à des aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions spéciales.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

Variable
========

La variable est l'un des outils les plus puissants et essentiels d'un programme. Elle nous permet de stocker et d'utiliser des données dans nos programmes.

Le sketch suivant utilise des variables. Il stocke le numéro de la broche de la LED intégrée dans la variable ``ledPin`` et un nombre "500" dans la variable ``delayTime``.

.. code-block:: C
    :emphasize-lines: 1,2

    int ledPin = 13;
    int delayTime = 500;

    void setup() {
        pinMode(ledPin,OUTPUT); 
    }

    void loop() {
        digitalWrite(ledPin,HIGH); 
        delay(delayTime); 
        digitalWrite(ledPin,LOW); 
        delay(delayTime);
    }

Attendez, est-ce un doublon avec ce que fait ``#define`` ? La réponse est NON.

* Le rôle de ``#define`` est de simplement remplacer du texte ; il n'est pas considéré par le compilateur comme faisant partie du programme. 
* Une ``variable``, en revanche, existe au sein du programme et est utilisée pour stocker et appeler une valeur. Une variable peut également modifier sa valeur dans le programme, ce qu'un ``define`` ne peut pas faire.

Le sketch ci-dessous s'auto-incrémente dans la variable, ce qui allonge progressivement le temps d'allumage de la LED intégrée à chaque clignotement.

.. code-block:: C

    int ledPin = 13;
    int delayTime = 500;

    void setup() {
        pinMode(ledPin,OUTPUT); 
    }

    void loop() {
        digitalWrite(ledPin,HIGH); 
        delay(delayTime); 
        digitalWrite(ledPin,LOW); 
        delay(delayTime);
        delayTime = delayTime+200; // À chaque exécution, la valeur est incrémentée de 200
    }

Déclarer une variable
----------------------

Déclarer une variable signifie créer une variable.

Pour déclarer une variable, vous avez besoin de deux éléments : le type de données et le nom de la variable. Le type de données doit être séparé du nom de la variable par un espace, et la déclaration doit être terminée par un ``;``.

Prenons cet exemple de variable.

.. code-block:: C

    int delayTime;

**Type de données**

Ici, ``int`` est un type de données appelé entier, qui peut stocker des nombres entiers allant de -32768 à 32766. Il ne peut pas être utilisé pour stocker des nombres décimaux.

Les variables peuvent contenir différents types de données autres que des entiers. Le langage Arduino (qui, rappelons-le, est du C++) prend en charge plusieurs types de données intégrés (seuls les plus fréquemment utilisés et utiles sont listés ici) :

* ``float`` : Stocke un nombre décimal, par exemple 3.1415926.
* ``byte`` : Peut contenir des nombres de 0 à 255.
* ``boolean`` : Contient seulement deux valeurs possibles, ``True`` ou ``False``, bien qu'il occupe un octet en mémoire.
* ``char`` : Contient un nombre de -127 à 127. Parce qu'il est marqué comme un ``char``, le compilateur essaiera de le faire correspondre à un caractère de la table ASCII |link_ascii|.
* ``string`` : Peut contenir une chaîne de caractères, par exemple ``Halloween``.

**Nom de la variable**

Vous pouvez attribuer à la variable n'importe quel nom, comme ``i``, ``apple``, ``Bruce``, ``R2D2``, ``Sectumsempra``, mais il y a quelques règles de base à suivre.

1. Décrivez son utilisation. Ici, j'ai nommé la variable ``delayTime``, pour que vous compreniez facilement son rôle. Cela fonctionnerait aussi avec un nom comme ``barryAllen``, mais cela pourrait désorienter la personne qui lit le code.

2. Utilisez une nomenclature régulière. Vous pouvez utiliser CamelCase, comme je l'ai fait avec le T majuscule dans ``delayTime`` pour indiquer facilement que la variable est composée de deux mots. Vous pouvez aussi utiliser l'UnderScoreCase, en écrivant la variable ``delay_time``. Cela n'affecte pas l'exécution du programme, mais cela aide le programmeur à lire le code si vous êtes cohérent.

3. N'utilisez pas de mots-clés. Comme lorsque vous tapez "int", l'IDE Arduino le colore pour vous rappeler que c'est un mot à usage spécial, qui ne peut pas être utilisé comme nom de variable. Changez le nom de la variable si elle est colorée.

4. Les symboles spéciaux ne sont pas autorisés. Par exemple, les espaces, #, $, /, +, %, etc. La combinaison de lettres anglaises (sensibles à la casse), d'underscores et de chiffres (mais les chiffres ne peuvent pas être utilisés comme premier caractère d'un nom de variable) est suffisamment riche.

**Attribuer une valeur à une variable**

Une fois la variable déclarée, il est temps de lui attribuer des données. Nous utilisons l'opérateur d'affectation (i.e. ``=``) pour placer une valeur dans la variable.

Nous pouvons attribuer une valeur à la variable dès sa déclaration.

.. code-block:: C

    int delayTime = 500;

Il est également possible de lui attribuer une nouvelle valeur ultérieurement.

.. code-block:: C

    int delayTime; // pas de valeur
    delayTime = 500; // valeur : 500
    delayTime = delayTime +200; // valeur : 700
