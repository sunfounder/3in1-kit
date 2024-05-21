.. note::

    Bonjour et bienvenue dans la Communauté Facebook des passionnés de Raspberry Pi, Arduino et ESP32 de SunFounder ! Plongez plus profondément dans l'univers des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux aperçus.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez [|link_sf_facebook|] et rejoignez-nous aujourd'hui !

Variable
========

La variable est l'un des outils les plus puissants et cruciaux dans un programme. Elle nous aide à stocker et à appeler des données dans nos programmes.

Le fichier de sketch suivant utilise des variables. Il stocke les numéros de broche de la LED intégrée dans la variable ``ledPin`` et un nombre "500" dans la variable ``delayTime``.

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

Attendez, est-ce un doublon de ce que fait ``#define`` ? La réponse est NON.

* Le rôle de ``#define`` est de remplacer simplement et directement le texte, il n'est pas considéré par le compilateur comme faisant partie du programme. 
* Une ``variable``, en revanche, existe au sein du programme et est utilisée pour stocker et appeler des valeurs. Une variable peut également modifier sa valeur dans le programme, ce qu'un define ne peut pas faire.

Le fichier de sketch ci-dessous ajoute lui-même à la variable et cela fera clignoter la LED intégrée plus longtemps après chaque clignotement.

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
        delayTime = delayTime+200; //Each execution increments the value by 200
    }

Déclarer une variable
---------------------------

Déclarer une variable signifie créer une variable. 

Pour déclarer une variable, vous avez besoin de deux choses : le type de données et le nom de la variable. Le type de données doit être séparé de la variable par un espace, et la déclaration de la variable doit être terminée par un ``;``.

Utilisons cette variable comme exemple.

.. code-block:: C

    int delayTime;

**Type de Donnée**

Ici, ``int`` est un type de donnée appelé type entier, qui peut être utilisé pour stocker des entiers de -32768 à 32766. Il ne peut pas être utilisé pour stocker des décimales.

Les variables peuvent contenir différents types de données autres que des entiers. Le langage Arduino (qui, rappelons-le, est du C++) offre un support intégré pour quelques-uns d'entre eux (seuls les plus fréquemment utilisés et utiles sont listés ici) :

* ``float`` : Stocke un nombre décimal, par exemple 3.1415926.
* ``byte`` : Peut contenir des nombres de 0 à 255.
* ``boolean`` : Ne détient que deux valeurs possibles, ``True`` ou ``False``, même s'il occupe un octet en mémoire.
* ``char`` : Contient un nombre de -127 à 127. Comme il est marqué comme un ``char``, le compilateur essaiera de le faire correspondre à un caractère du |link_ascii|.
* ``string`` : Peut stocker une chaîne de caractères, par exemple ``Halloween``.


**Nom de Variable**

Vous pouvez donner à la variable le nom que vous voulez, comme ``i``, ``apple``, ``Bruce``, ``R2D2``, ``Sectumsempra``, mais il y a quelques règles de base à suivre.

1. Décrire à quoi elle sert. Ici, j'ai nommé la variable delayTime, donc vous pouvez facilement comprendre ce qu'elle fait. Ça fonctionnerait si je nommais la variable ``barryAllen``, mais cela confondrait la personne qui regarde le code.

2. Utiliser une nomenclature régulière. Vous pouvez utiliser CamelCase comme je l'ai fait, avec le T initial dans ``delayTime`` pour qu'il soit facile de voir que la variable est composée de deux mots. Aussi, vous pouvez utiliser UnderScoreCase pour écrire la variable comme ``delay_time``. Cela n'affecte pas le fonctionnement du programme, mais cela aiderait le programmeur à lire le code si vous utilisez la nomenclature que vous préférez.

3. Ne pas utiliser des mots-clés. De manière similaire à ce qui se passe lorsque nous tapons "int", l'IDE Arduino le coloriera pour vous rappeler que c'est un mot avec un but spécial et ne peut pas être utilisé comme nom de variable. Changez le nom de la variable si elle est colorée.

4. Les symboles spéciaux ne sont pas autorisés. Par exemple, l'espace, #, $, /, +, %, etc. La combinaison de lettres anglaises (sensibles à la casse), de soulignements et de nombres (mais les nombres ne peuvent pas être utilisés comme premier caractère d'un nom de variable) est assez riche.


**Attribuer une valeur à une variable**

Une fois que nous avons déclaré la variable, il est temps de stocker les données. Nous utilisons l'opérateur d'affectation (c'est-à-dire ``=``) pour mettre de la valeur dans la variable.

Nous pouvons attribuer des valeurs à la variable dès que nous la déclarons.


.. code-block:: C

    int delayTime = 500;

Il est également possible de lui attribuer une nouvelle valeur à un moment donné.

.. code-block:: C

    int delayTime; // no value
    delayTime = 500; // value is 500
    delayTime = delayTime +200; // value is 700