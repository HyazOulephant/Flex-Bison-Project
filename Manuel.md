Manuel d’utilisation

Théorie des langages – Turtle Drawing

CARLIER Antoine – CHAIGNES Hyacinthe



Nous pouvons placer des commentaires dans notre programme à l’aide des symboles “//” et “/* texte */”. 

I) Opérations

Dans ce logiciel, nous pouvons réaliser des calculs grâce à certains opérateurs entre des nombres et des variables. Ici, “A" et “B" seront des variables remplaçables dans votre programme par des nombres, une autre opération ou d’autres variables que vous aurez pris le soin d’initialiser auparavant.

    A : Renvoie la valeur de A.

    (A) : Renvoie la valeur de A.

    A + B : Renvoie le résultat de l’addition de A et B.

    A - B : Renvoie le résultat de la soustraction de A par B.

    A * B : Renvoie le résultat de la multiplication de A et B.

    A / B : Renvoie le résultat de la division de A par B.

    A || B : Renvoie 1 si A n’est pas égal à 0 ou si B n’est pas égal à 0. Si A et B sont égaux à 0, renvoie 0.

    A && B : Renvoie 1 si A et B ne sont pas égaux à 0. Si A ou B est égal à 0, renvoie 0.

    A > B : Renvoie 1 si A est strictement supérieur à B. Sinon renvoie 0.

    A >= B : Renvoie 1 si A est supérieur ou égal à B. Sinon renvoie 0.

    A == B : Renvoie 1 si A est égal à B. Sinon renvoie 0.

    A <= B : Renvoie 1 si A inférieur ou égal à B. Sinon renvoie 0.

    A < B : Renvoie 1 si A strictement inférieur à B. Sinon renvoie 0.

    A != B : Renvoie 1 si A est différent de B. Sinon renvoie 0.

    SIN(A) : Renvoie le sinus de A. (En radian)

    COS(A) : Renvoie le cosinus de A. (En radian)

    ASIN(A) : Renvoie l'arc sinus de A. (En radian)

    ACOS(A) : Renvoie l'arc cosinus de A. (En radian)

    RACINE(A) : Renvoie la racine de A.  

Vous pouvez aussi accéder à la constante π en écrivant PI.



II) Instructions

Pour que le programme puisse agir, vous avez une liste d’instructions à votre disposition. Certaines instructions prennent des paramètres, ceux-ci peuvent être des variables, nombres ou opérations comme précédemment. Nous considèrerons “variable" comme étant le nom d’une variable et “A", “B", “C"   comme étant un paramètre passé en argument pour une fonction.

    A : Affiche le paramètre dans la console.

    POSITION(A,B) : Place le curseur de dessin à la position (A,B). (L’axe des ordonnées est inversée)

    AVANCE  A : Avance le curseur de dessin d’une distance de taille A.

    INCLINE  A : Incline l’angle du curseur de dessin de A degrés. (Sens contraire des aiguilles d’une montre)

    COULEUR(A,B,C) : Change la couleur du trait de dessin par son code RGB = (A,B,C).

    POINT : Dessine un point à l’emplacement du curseur selon son épaisseur.

    EPAISSEUR  A : Applique une épaisseur du trait de dessin de rayon A.

    REMPLIR : Rempli l’ensemble de l’écran par la couleur définie par l’instruction COULEUR().

    SAUT  A : Saute A frames d’affichage entre chaque mouvement. (Accélère le dessin)

    DELAI  A : Attend A microsecondes entre chaque mouvement. (Ralenti le dessin)

    ATTENDRE  A : Attend A microseconde avant la prochaine instruction.

    variable = A : Affecte la valeur A à la variable  

    TORTUE  A : Active le tracage si A est différent de 0. Si A est égal à 0, le désactive.

    TORTUE = A : Applique le sprite de la tortue n°A au curseur. Si A est égal à 0, aucun sprite.

    Sprites du curseur disponibles :

    0 : Rien.

    1 : Pinceau.

    2 : Logo ISEN.

    3 : Nyan cat animé.

    4 : Carapace bleue ailée.

    5 : Planète Terre.

    6 : Megaman animé.

    7 : Sanic.



III) Blocs d’instructions

Afin de réaliser des dessins et des formes complexes, des blocs de conditions sont mis à disposition. Ceux-ci doivent commencer sur une ligne et possiblement prendre des arguments, mais ils doivent toujours finir par une ligne explicitant la fin du bloc.



1) Bloc SI :

SI(A)

Instructions...

SINON

Instructions...

FINSI

Si A est différent de 1, nous exécutons les instructions allant de SI(A) à SINON et nous n’exécutons pas les instructions allant de SINON à FINSI. Si A est égal à 0, nous n’exécutons pas les instructions allant de SI(A) à SINON mais nous exécutons les instructions allant de SINON à FINSI.

SI(A)

Instructions...

FINSI

Le SINON est optionnel. Nous pouvons écrire le bloc comme ci-dessus. Auquel cas, si A est égal à 0, nous n’exécutons rien.



2) Bloc REPETE :

REPETE(A)

Instructions...

FINREPETE

Exécute les instructions allant de REPETE(A) à FINREPETE A fois



3) Bloc TANTQUE:

TANTQUE(A)

Instructions...

FINTANTQUE

Exécute les instructions allant de TANTQUE(A) à FINTANTQUE tant que A est différent de 0.



3) Bloc FONCTION:

FONCTION nom()

Instructions...

FINFONCTION

Créé une liste d'instructions qui seront exécutés lors de l’appel du nom de la fonction :

nom()

Ici, notre fonction n’a pas de paramètres mais nous pouvons lui en attribué de telle façons :

FONCTION nom(A,B,C)

Instructions... (possiblement en fonction des paramètres, ici A, B et C)

FINFONCTION

Nous l’appellerons donc en lui donnant des valeurs pour remplacer ces paramètres dans les instructions, ces valeurs peuvent être des nombres, variables ou opérations :

nom2( 42, variable, 56 * 2)



IV) Exemples de programmes



1) Collier Nyan-cat

i = 0

POSITION(500,750)

SAUT(5)

TORTUE = 3



REPETE 360

REPETE 5

EPAISSEUR(sin(pi * i/100)*15 + 25)

AVANCE(1)

COULEUR(sin(pi * i / 255)*128 + 128,sin(pi * 2 * i / 255)*128 + 128,sin(pi * 3 * i / 255)*128 + 128)

i = i+1

FINREPETE

INCLINE(1)

FINREPETE



2) Multiple Carrés

POSITION(500,500)

EPAISSEUR(10)

SAUT(100)



FONCTION carre()

REPETE  4

AVANCE 350

INCLINE 90

FINREPETE

FINFONCTION





REPETE 5

REPETE 4

INCLINE 90

carre()

FINREPETE

INCLINE 36

FINREPETE





3) Symboles PS

FONCTION carre()

COULEUR(150,50,150)

REPETE  4

AVANCE 250

INCLINE 90

FINREPETE

FINFONCTION



FONCTION triangle()

COULEUR(0,200,0)

REPETE  3

AVANCE 290

INCLINE 120

FINREPETE

FINFONCTION



FONCTION cercle()

COULEUR(200,50,0)

REPETE  360

AVANCE 2.3

INCLINE 1

FINREPETE

FINFONCTION



FONCTION croix()

COULEUR(50,50,250)

INCLINE 45

AVANCE 350

INCLINE 0-135

TORTUE FAUX

AVANCE 350/RACINE(2)

INCLINE 0-135

TORTUE VRAI

AVANCE 350

INCLINE 0-135

FINFONCTION



POSITION(100,610)

carre()

POSITION(355,280)

triangle()

POSITION(800,625)

cercle()

POSITION(390,900)

croix()



4) Système solaire

POSITION (500,500)

COULEUR(0,0,0)

REMPLIR



EPAISSEUR 200

TORTUE = 0

SAUT(5)

i = 200



// Soleil

REPETE 200

EPAISSEUR i

COULEUR(i/2+150,i + 50,0)

POINT

i = i - 1

FINREPETE



EPAISSEUR 3

TORTUE FAUX



AVANCE 375



INCLINE 90



TORTUE VRAI

COULEUR(255,255,255)



REPETE 720

INCLINE 0.5

AVANCE 1/4 * PI * 375 / 90

FINREPETE



EPAISSEUR 30

TORTUE = 5

TORTUE FAUX

SAUT(0)

REPETE 720

INCLINE 0.5

AVANCE 1/4 * PI * 375 / 90

FINREPETE



5) Spirale carré

POSITION (500,500)

EPAISSEUR 1

SAUT(1000)

TORTUE = 0



angle = 0.5

pas = 3



i = 0



REPETE 400

i = i+pas

AVANCE 1+i/2

INCLINE 90 - angle

FINREPETE





6) Etoile

POSITION (500,500)

EPAISSEUR 1

SAUT(1000)

TORTUE = 0

r = 490

pas = 10

i = 0



REPETE (r+pas)/pas

INCLINE 90

hypo = RACINE( (r-i)*(r-i) + i*i )

angle = acos(i/hypo)*180/pi

INCLINE 90 - angle

AVANCE hypo

INCLINE 2*angle

AVANCE hypo

INCLINE 180 - 2*angle

AVANCE hypo

INCLINE 2*angle

AVANCE hypo

INCLINE 90 – angle



INCLINE 0-90



TORTUE FAUX

AVANCE pas

TORTUE VRAI



i = i + pas

FINREPETE





7) Arbre

POSITION(500,900)

EPAISSEUR(1)

SAUT(1000)

TORTUE = 0



INCLINE 90



FONCTION arbre(taille,angleg,angled,coeffg,coeffd)

SI (taille >= 10)

AVANCE taille



// Arbre Gauche

INCLINE angleg

arbre(coeffg*taille,angleg,angled,coeffg,coeffd)



TORTUE FAUX

INCLINE 0-180

INCLINE 180 - angleg

TORTUE VRAI



// Arbre Droit

INCLINE 0-angled

arbre(coeffd*taille,angleg,angled,coeffg,coeffd)



TORTUE FAUX

INCLINE 0-180

INCLINE 180 + angled



// Retour arbre precedent

INCLINE 180

AVANCE taille

INCLINE 0-180

TORTUE VRAI

FINSI

FINFONCTION



arbre(200,70,60,0.65,0.75)





8) Cyclone

POSITION (500,500)

TORTUE = 3



i = 1



REPETE 1080 * 4

i = i+1

EPAISSEUR(sin(pi * i/100)*5 + 4)

AVANCE(1+ i /1000)

COULEUR(sin(pi * i / 255)*128 + 128,sin(pi * 2 * i / 255)*128 + 128,sin(pi * 3 * i / 255)*128 + 128)

INCLINE(1+ 80 /i)

FINREPETE





9) Yncrea

SAUT(10)

TORTUE = 2



POSITION(500,500)

EPAISSEUR(400)

COULEUR(0,0,0)

POINT

EPAISSEUR(15)

TORTUE FAUX

AVANCE 375

INCLINE 90



// Cercle Blanc

TORTUE VRAI

COULEUR(255,255,255)

REPETE 720

INCLINE 0.5

AVANCE 1/4 * PI * 375 / 90

FINREPETE



// Bouge

TORTUE FAUX

INCLINE 90

AVANCE 375



// Y GAUCHE

i = 30

TORTUE VRAI

EPAISSEUR i

INCLINE 0-49

AVANCE 200



INCLINE 20

REPETE 29

i = i - 1

EPAISSEUR i

AVANCE 2

FINREPETE



// Bouge

TORTUE FAUX

INCLINE 29+90+10

AVANCE 425



INCLINE 55

TORTUE VRAI

COULEUR(160,160,0)

EPAISSEUR 30



REPETE 90

AVANCE 0.5

INCLINE 1

FINREPETE



AVANCE 400





REPETE 90

AVANCE 0.5

INCLINE 0-1

FINREPETE



TORTUE FAUX

// GROSSISSEMENT

INCLINE 25 // On remet a 0

POSITION(500,750)

j = 30

REPETE 360

j = j+1

EPAISSEUR j/3

INCLINE 2

FINREPETE
