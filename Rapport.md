Mini-Rapport de Projet

Théorie des langages – Turtle Drawing

CARLIER Antoine – CHAIGNES Hyacinthe



Présentation du projet

Ce projet a pour but de réaliser un mini langage de programmation permettant à l’utilisateur de dessiner dans une zone graphique un dessin à l’aide d’une tortue, curseur permettant de dessiner. Pour ce faire, celui-ci a accès à trois commandes :  

    Avancer – Commande faisant avancer la tortue d’une certaine distance.

    Tourner – Commande changeant l’angle de la direction de la tortue.

    Lever / Baisser le crayon – Commande permettant d’activer ou non le tracé de la tortue.

Dans notre cas, nous avons aussi choisi de rajouter des fonctionnalités à notre programme afin de permettre des formes encore plus détaillées. Nous nous sommes décidés à travailler en langage C++ avec la librairie SDL car nous avons déjà travaillé dessus par le passé et nous connaissons bien ce langage. Pour la partie grammaticale du langage que l’on va créer, nous utiliseront les bibliothèques Flex et Bison.

Afin de bien nous répartir les tâches, nous avons décidé de séparer notre charge de travail en deux parties Hyacinthe s’est mis à travailler sur la partie graphique et Antoine sur la partie grammaticale. Pour réussir à travailler ensemble, nous avons choisi de travailler sur linux afin de faciliter l’utilisation des bibliothèques que nous utilisons et à l’aide de Github pour maintenir les avancées de notre projet.



Développement du projet



I) Implémentation de la SDL et des opérateurs

Il nous a d’abord fallu implémenter la bibliothèque SDL pour que notre programme puisse fonctionner, nous avons donc cherché différents moyens pour l’initialiser et la mettre en place. Pour rendre notre programme plus compréhensible nous avons commencé à le séparer en plusieurs fichiers. Toutes nos fonctions pour interagir avec la partie graphique seront situées dans un fichier à part afin de faciliter les modifications.

Pour commencer, nous avons déjà implémenté des fonctions très simples en SDL pour permettre de tracer des traits, bien que ceux-ci ne dépendent pas du sens du curseur mais seulement de sa position. Nous avions alors des fonctions nous permettant de nous déplacer dans quatre directions (haut, bas, gauche et droite). Ainsi nous avons pu commencer à développer notre langage autour de ces méthodes.

La première implémentation dans la partie grammaticale fut de rajouter des opérateurs pour que l’on puisse augmenter les possibilités de calcul du langage (&&, ==, >…). Ce ne fut pas un problème car nous avions déjà la forme des expressions d’opérations, il fallait seulement préciser au langage de faire les opérations par la gauche pour éviter les conflits de génération. Nous avons ensuite pu implémenter des débuts d’instruction comme “DROITE” qui lançait l’instruction de la SDL permettant de mouvoir la tortue vers la droite.



II) Implémentation de la Tortue

A partir de maintenant, nous avions déjà un programme répondant à des instructions basiques qui pouvait reproduire des formes très simples. Evidemment, notre tortue n’était pas encore totalement implémentée, nous avons donc établi de nouvelle fonction pour répondre à cela. Nous nous sommes débarrassé des fonctions de déplacement pour les remplacer par la fonction nous permettant de changer l’angle de la tortue et celle permettant de la faire avancer dans cette direction. Pour cela, nous avons dû inclure une autre librairie pour réaliser nos calculs : math.h. Grace à celle-ci, nous pouvions réaliser des calculs de trigonométrie pour déterminer vers où la tortue devait se déplacer en fonction de son angle et la distance à parcourir.

Cette partie ne posa pas de problèmes, mais nous voulions que nous puissions voir notre curseur bouger, pour cela nous ne devions plus utiliser la fonction de base inclue dans la SDL permettant de faire des traits mais nous devions les faire nous-même en déplaçant la tortue pixel par pixel, nous pourrions ainsi inclure un délai entre chaque mouvement pour la voir bouger. Nous avons dû trouver une méthode permettant de calculer efficacement ces déplacements. En effet, la position de notre tortue est mesurée au pixel et ainsi son abscisse et son ordonnée sont des nombres entiers, nous ne pouvions pas lui additionner des nombres décimaux inférieur à 1 sinon ceux-ci n’augmenteraient pas. Nous avons dû passer toutes nos positions en nombre décimal afin de ne faire la conversion en entier seulement au moment de l’affichage. Maintenant notre fonction avancer était devenu une boucle faisant avancer la tortue d’une distance de 1 à chaque tour de boucle permettant d’obtenir un mouvement.

Nous sommes ensuite partis à la recherche de précision en permettant à l’utilisateur d’entrer une distance et une inclinaison décimale dans les instructions. Ces instructions, seules, peuvent ne pas être représentée sur la partie graphique : en effet en demandant au programme d’avancer de 0,1 pixel, nous ne verrons pas de différence à l’écran mais nous prendrons bien en compte la nouvelle position de la tortue. Ainsi, si l’on réalise 10 fois cette instruction, nous verrons notre tortue avancer de 1 pixel car la conversion n’est plus réalisée dans la position de la tortue mais seulement à l’affichage.



III) Implémentation des blocs “SI” et “REPETE”

Maintenant que notre partie graphique fut fonctionnelle, on s’attaqua à la partie grammaticale dans le but de rajouter des blocs conditionnels. En faisant quelques tests, on se rendu compte que Bison créé les lignes d’instruction directement après les avoir lues. On essaya donc de créer le début des blocs lorsque l’on lit le premier mot-clé, par exemple : “SI”, et la fin du bloc en voyant “FINSI”. Cette technique ne pouvait pas fonctionner, il nous a donc fallu trouver une autre méthode. Nous avons donc créé une classe Instruction qui contient l’ID d’une instruction ainsi que les paramètres qui lui ont été donné. Lorsque Bison trouve une de ces instructions il la rajoutera avec ses paramètres dans un tableau. Ce tableau représentera les adresses des instructions de notre code, comme en langage assembleur. Ainsi, lorsque l’on lit l’instruction “SI”, nous ajoutons au tableau une instruction avec un ID “SI” et la condition en paramètre, nous ajouterons plus tard l’instruction FINSI qui elle ne prendra pas de paramètres.

Pour exécuter tout le programme, nous utilisons un switch qui parcours notre tableau et exécute l’instruction demandée selon l’ID et ses paramètres. Si l’exécution voit un “SI” il n’exécutera la suite des instructions jusqu’aux “FINSI” ou “SINON” que si le paramètre est vrai. Si ce n’est pas le cas, il incrémente la variable parcourant le tableau jusqu’à trouver un “FINSI” ou un “SINON” à condition que ce mot clé soit bien celui de ce bloc conditionnel (Nous pouvons imbriquer des “SI” auquel cas nous évitons les conflits), puis il exécute le code à sa suite.

Pour bien faire fonctionner nos blocs conditionnels, nous réexécutons le programme de parcours de tableau de façon récursive. Si nous avons un “REPETE”, nous voulons que le programme exécute l’ensemble des instructions suivante un certain nombre de fois. Pour cela, en repérant un “REPETE”, nous lançons une boucle qui exécutera autant de fois qu’on l’a demandé, le code entre le début et la fin du bloc. Nous demandons donc de exécuter le code à partir de la première instruction et l’exécution se termine dès qu’elle aperçois le “FINREPETE” qui opère un return i; renvoyant la position du fin du bloc. Si nous voulons encore répéter le programme nous recommençons la manipulation, sinon nous continuons l’exécution du programme à partir de la position de ce que la fonction nous a renvoyé (La position du “FINREPETE”).



IV) Implémentation des variables

Pour pouvoir utiliser toute la puissance de nos blocs d’instructions, il nous fallait implémenter des variables pour permettre les formes complexes. Malheureusement, avec notre programme actuel, les opérations se calculaient directement depuis Bison, et nous envoyons les résultats aux instructions. Si l’on souhaite mettre des variables, il faut que les opérations ne se calculent qu’au moment où l’on arrive à l’instruction et non pas avant même que l’exécution n’est commencée.

Notre idée fut de créer une seconde classe Numerique nous renvoyant une valeur selon les paramètres donnés dans son constructeur :

    Nous la créons avec un nombre en paramètre, auquel cas nous récupéreront ce même nombre si l’on demande la valeur de l’objet.

    Nous passons une chaîne de caractère en paramètre, cette fois, si nous demandons la valeur à l’objet, nous récupèreront le nombre associé à cette chaîne dans une map que nous avons défini au début du programme pour stocker les variables.

    Finalement, nous pouvons générer un objet Numerique en passant deux autres objets de la même classe ainsi qu’un ID d’opérateur (+, -, &&, >, ==…) que l’on a créé tout comme pour les IDs d’instructions. En demandant la valeur de l’objet, le programme nous renvoie l’opération selon l’ID de l’opérateur demandé des deux objets Numerique passés en paramètres.

Par exemple, “1 == a” créé trois objets :  

    (1) = Numerique (1) : Renvoie la valeur 1.

    (2) = Numerique (“a”) : Renvoie la valeur associée à “a” dans la map de variables.

    (3) = Numerique ( (1), ID (“==”), (2) ) : Renvoie le résultat de la valeur du premier objet égale a la valeur du second objet.

Au final, avec cette technique, nous avons un arbre d’opérations. De plus, tant que nous ne demandons pas la valeur d’un objet, celle-ci est encore inconnue au programme : la partie de Bison pourra alors donner en paramètre d’une instruction un objet associé à un nom de variable, ainsi si celui-ci est amené à changer, chaque fois que l’instruction appellera la valeur de l’objet, nous récupèrerons la nouvelle valeur de la variable car nous recalculons l’opération plutôt que de la fixer comme une constante.

Ici, nous avons quand même eu un problème pour permettre aux expressions dans Bison de prendre la valeur de la classe Numerique plutôt que de leur donner une valeur double. En effet, quand on souhaite donner une valeur à un token de Bison, celle-ci doit être une valeur basique du C++ (Donc pas de classe ou de Standard Templates Library comme les vector). Nous avons finalement trouvé une solution en demandant au Bison d’ajouter le fichier source de la classe dans son code d’en-tête avec l’instruction %code requires { … }. Cela nous a aussi permis d’ajouter les string et vector en tant que valeurs possibles des token pour plus tard. Maintenant, notre code pouvait fonctionner avec des boucles et des variables sans problèmes.



V) Implémentation d’un sprite pour la Tortue

Nous étions maintenant dans l’optique d’améliorer notre programme, celui-ci, présentait déjà les demandes du cahier des charges. Nous avons voulu ajouter un sprite là où se trouvaient notre curseur afin de représenter la tortue. Néanmoins, pour ce faire, nous avons dû changer l’ensemble de fonctionnement de notre programme : Nous avons ajouté une fonction permettant d’afficher le rendu pour qu’elle soit la seule à avoir le contrôle sur l’affichage.

Nous n’arrivions pas à faire simplement apparaître le sprite sans détruire le dessin derrière. Après s’être renseigné, nous avons vu que sur SDL, nous n’avons pas de différentes couches d’affichage, contrairement aux autres bibliothèques graphiques. Nous avons donc généré notre propre affichage de couche en utilisant les textures de SDL : Lorsque l’on dessine sur SDL, le dessin est réalisé sur un objet SDL_Render et celui-ci est affiché avec la commande SDL_RenderPresent();. Mais nous avons trouvé un moyen pour que l’objet dessine sur un autre objet SDL_Texture en changeant la cible du SDL_Render avec SDL_SetRenderTarget();. A chaque fois que l’on appelle cette commande nous dessinons sur d’autres rendus de la SDL, nous avons donc créé une texture pour le dessin et une autre pour le sprite. Notre fonction d’affichage gère ainsi le ciblage du rendu pour copier les deux textures et les afficher à l’écran et ainsi simuler les couches d’affichage.  

Nous avons aussi pu utiliser cette commande pour régler un autre problème auquel nous étions confrontés. Notre programme devenait de plus en plus lent, du fait que celui-ci lance un affichage à chaque pixel dessiné et l’affichage est la partie la plus lente du programme (cela dépend des cartes graphiques utilisées). Nous avons alors implémenté une instruction permettant de sauter des frames d’affichage pour permettre un affichage bien plus rapide en gardant le même nombre de frames à la seconde.

Avec l’affichage et le sprite opérationnels, nous avons aussi ajouté la possibilité de changer de sprite pendant le programme (et le désactiver) en en implémentant plusieurs, dont certains animés. 



VI) Implémentation des fonctions

Enfin, nous avons fini notre programme en implémentant la possibilité de faire des fonctions. La première étape fut très simple, notre programme lit le mot-clé d’une fonction et garde sa position en mémoire dans une map en fonction du nom de celle-ci. Quand celle-ci est appelée, nous stockons notre position dans le programme et nous exécutons les instructions situées à la position de la fonction dans le programme. Dès que nous lisons le mot-clé “FINFONCTION” nous revenons là où notre programme avais appelé la fonction à l’origine.

Pour implémenter les paramètres, cela fut plus dur. Il nous fallait en plus de stocker le nom de la fonction, le nombre ainsi que les noms des paramètres qu’elle prend. Notre map ne prenait plus simplement un nom de fonction en mot-clé pour accéder à son emplacement mais aussi le nombre de paramètre et elle renvoyait en plus un vecteur contenant leurs noms.

Lorsque la fonction est appelée avec le bon nombre de paramètre (si ce n’est pas le cas la fonction n’est pas reconnue), avant d’exécuter ses instructions, nous stockons l’adresse à laquelle nous nous situons pour y revenir à la fin de la fonction mais, nous gardons aussi dans une variable temporaire les noms et valeurs associées des variables externes à la fonction portant le même nom que les paramètres. Si nous ne faisions pas ça, nous risquions de perdre des données en cours d’exécution et nous ne pourrions pas faire de fonctions récursives (elles utilisent obligatoirement les mêmes noms de paramètres). Une fois les valeurs sauvegardées, nous remplaçons les valeurs des variables portant le même nom que les paramètres par les valeurs que nous avons donné aux paramètres et nous exécutons la fonction qui considèrera alors que les paramètres que nous lui avons donnés sont des variables globales. Si nous rappelons la même fonction à l’intérieur de celle-ci, ses paramètres seront sauvegardés de la même façon. Enfin, à la fin de son exécution, nous rétablissons les anciennes valeurs des variables et nous continuons l’exécution du programme.



Fin du projet

A l’aide de Flex et Bison, nous avons pu réaliser un vrai langage de programmation en recréant les mêmes fonctionnalités que l’on retrouve dans les langages de programmation courants. Nous avons aussi créé notre propre système dessin et de couches pour permettre de donner de la vie à notre programme et augmenter ses capacités techniques et visuelles.
