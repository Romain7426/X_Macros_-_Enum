# [X Macros](https://en.wikipedia.org/wiki/X_Macro) pour la génération automatique de type [enum](https://fr.wikipedia.org/wiki/Type_%C3%A9num%C3%A9r%C3%A9#Langage_C) 

[GLOBISH: README.eng.md](README.eng.md)

Bonjour tout le monde! ☺ 

J'en suis venu à cette problématique pour: 
 - pour générer automatiquement des types [enums](https://fr.wikipedia.org/wiki/Type_%C3%A9num%C3%A9r%C3%A9#Langage_C) 
 - puissance du langage de macros (en l'espèce, les [X Macros](https://en.wikipedia.org/wiki/X_Macro)) 


À ÉCRIRE 
 
Le plus simple est de consulter directement le fichier [main.c](src/main.c) puis le fichier [decimal.h](src/decimal.h). 



## Installation et compilation

La procédure: 

<pre>
$ echo "clang" > ./CC        # Ou votre compilateur préféré. 
$ sh ./configure.sh          # Génère d'abord les outils puis le Makefile. 
$ make 
$ make install 
</pre>
 
Personnalisation 
 - Choix du [compilateur](https://fr.wikipedia.org/wiki/Compilateur) — par défaut, le [compilateur](https://fr.wikipedia.org/wiki/Compilateur) utilisé est 'cc'; pour utiliser votre [compilateur](https://fr.wikipedia.org/wiki/Compilateur) préféré, il faut en indiquer le chemin dans le fichier ['./CC'](CC) (par exemple, «$ echo "/usr/local/bin/x86_64-unknown-openbsd7.0-gcc-11.2.0" > ./CC»). 
 - Choix du répertoire d'installation — par défaut, le répertoire d'installation est './destroot'; pour indiquer votre lieu préféré, il faut éditer le [Makefile](https://fr.wikipedia.org/wiki/Make#Makefile) généré, voire éditer le fichier ['./Makefile-gen.mkf'](Makefile-gen.mkf) (il est aussi possible de simplement créer un lien symbolique vers './destroot', ou de copier les fichiers depuis './destroot' vers le lieu d'installation voulu). 
 - Aucune autre configuration possible. (Toutefois, vous pouvez toujours modifier le fichier ['./Makefile-gen.mkf'](Makefile-gen.mkf) à votre convenance.) 
 
Architecture de la configuration 
 - La configuration n'est pas basée sur [GNU Autohell](https://en.wikipedia.org/wiki/Autohell). 
 - L'idée est de générer un [Makefile](https://fr.wikipedia.org/wiki/Make#Makefile) qui soit le plus standard possible, parfaitement prévisible et ennuyeux (exemple: [Makefile](Makefile)), afin de pouvoir être lu par n'importe quelle version exotique de [Make](https://fr.wikipedia.org/wiki/Make). Un tel [Makefile](https://fr.wikipedia.org/wiki/Make#Makefile) est beaucoup plus lisible, plus simple à déboguer, plus compréhensible, et évite au programme [Make](https://fr.wikipedia.org/wiki/Make) de prendre des initiatives (en inférant on ne sait pas quelle règle ésotérique). (En sus, en théorie, un tel [Makefile](https://fr.wikipedia.org/wiki/Make#Makefile) serait distribuable — dans les faits, ceci est improbable dû aux spécificités de chaque [compilateur](https://fr.wikipedia.org/wiki/Compilateur), de chaque [système](https://fr.wikipedia.org/wiki/Syst%C3%A8me_d%27exploitation), etc., spécificités que il faut donc détecter en amont.) 
 - Pour générer un tel [Makefile](https://fr.wikipedia.org/wiki/Make#Makefile) ennuyeux, nous utilisons le fichier ['./Makefile-gen.mkf'](Makefile-gen.mkf) qui est un script écrit dans le langage [GNU Make](https://en.wikipedia.org/wiki/GNU_make) (le langage de [GNU Make](https://en.wikipedia.org/wiki/GNU_make) étant beaucoup plus sympathique que le [shell standard](https://fr.wikipedia.org/wiki/Bourne_shell)). 
 - Ce script ['./Makefile-gen.mkf'](Makefile-gen.mkf) nécessite des outils extérieurs qui se trouvent dans le sous-répertoire ['./tools'](https://github.com/Romain7426/X_Macros_-_Enum/tree/main/tools). Avant d'exécuter le script ['./Makefile-gen.mkf'](Makefile-gen.mkf), il faut générer ces outils. Cela est fait par le script [shell](https://fr.wikipedia.org/wiki/Bourne_shell) ['./tools-compile.sh'](tools-compile.sh). (Notons que ces outils devraient compiler sans problème.) 
 - Et c'est tout. Tout cela est automatiquement réalisé par le script [shell](https://fr.wikipedia.org/wiki/Bourne_shell) ['./configure.sh'](configure.sh). 
 
Plaintes 
 - Si le script ['./configure.sh'](configure.sh) se plaint que il ne trouve pas [GNU Make](https://en.wikipedia.org/wiki/GNU_make), éditez le fichier ['./configure.sh'](configure.sh) pour lui indiquer où trouver [GNU Make](https://en.wikipedia.org/wiki/GNU_make). 
 - Tout le code source suppose que le [compilateur](https://fr.wikipedia.org/wiki/Compilateur) est compatible avec la norme [C99](https://fr.wikipedia.org/wiki/C_(langage)#Normalisation). 
 - Pour les autres plaintes, a priori, je ne sais pas. 
 
[Compilateurs](https://fr.wikipedia.org/wiki/Compilateur) testés: 
 - [clang](https://fr.wikipedia.org/wiki/Clang): 86k 
 - [gcc11](https://fr.wikipedia.org/wiki/GNU_Compiler_Collection): 170k 
 - [tcc](https://en.wikipedia.org/wiki/Tiny_C_Compiler): 134k 
 - [pcc](https://en.wikipedia.org/wiki/Portable_C_Compiler): 82k 
 - [lacc](https://github.com/larmel/lacc): échoue à compiler les outils 
 - D'autres? 

[Systèmes](https://fr.wikipedia.org/wiki/Syst%C3%A8me_d%27exploitation) testés: 
 - [OpenBSD](https://fr.wikipedia.org/wiki/OpenBSD) 
 - Les autres systèmes [BSD](https://fr.wikipedia.org/wiki/Berkeley_Software_Distribution) devraient fonctionner sans problème. 
 - Il devrait fonctionner sous [MacOSX](https://fr.wikipedia.org/wiki/MacOS). 
 - Les systèmes compatibles avec [Unix](https://fr.wikipedia.org/wiki/Unix) devraient fonctionner. 
 - Sur [Windows](https://fr.wikipedia.org/wiki/Microsoft_Windows), nous ne savons pas, nous n'avons pas essayé, mais le programme devrait pouvoir fonctionner à travers [Cygwin](https://fr.wikipedia.org/wiki/Cygwin), [MinGW](https://fr.wikipedia.org/wiki/MinGW), etc. 
 
Dépendances: 
 - Un [compilateur](https://fr.wikipedia.org/wiki/Compilateur) compatible avec la norme [C99](https://fr.wikipedia.org/wiki/C_(langage)#Normalisation). 
 - [GNU Make](https://en.wikipedia.org/wiki/GNU_make). 
 
Nota bene: 
 - Si la compilation des outils prend trop de temps, on peut l'éviter et passer directement à la génération du [Makefile](https://fr.wikipedia.org/wiki/Make#Makefile): 
    <br> $ gmake -r -R -S -j 1 --warn-undefined-variables -f ./Makefile-gen.mkf  


## Auteurs  
 
Auteurs: 
 - [Romain: https://github.com/Romain7426](https://github.com/Romain7426)


## [Propriété intellectuelle](https://fr.wikipedia.org/wiki/Propri%C3%A9t%C3%A9_intellectuelle) 
 
Nous ne portons aucun intérêt à la [propriété intellectuelle](https://fr.wikipedia.org/wiki/Propri%C3%A9t%C3%A9_intellectuelle) du présent programme (ni en général, sauf pour en étudier les principes et exprimer que nous désapprouvons ces principes et la [propriété intellectuelle](https://fr.wikipedia.org/wiki/Propri%C3%A9t%C3%A9_intellectuelle) en général). Vous pouvez faire ce que il vous plaît avec ce programe. 

Nous aurions bien laissé ce programme dans le [domaine public](https://fr.wikipedia.org/wiki/Domaine_public_(propri%C3%A9t%C3%A9_intellectuelle)), mais il semblerait que il existerait une possibilité pour s'approprier du matériel qui serait dans le domaine public, et d'en restreindre rétro-activement l'accès. Afin de prévenir ce cas dégénéré, ce programme a été publié sous une licence équivalente à la [licence ISC](https://fr.wikipedia.org/wiki/Licence_ISC), mais en plus relâchée (cf. le fichier [COPYING](COPYING) pour la consulter in extenso). En ce qui nous concerne, vous pouvez faire ce que vous voulez avec ce programme et son code, dans la mesure vous n'empêchez personne de l'utiliser, y compris nous-mêmes. 
 
A posteriori, nous venons de nous rendre compte que nous avions réalisé l'équivalent d'une licence [0BSD](https://en.wikipedia.org/wiki/BSD_licenses#0-clause_license_("BSD_Zero_Clause_License")). 



## Merci 

Merci!! :smile: 

Et nous vous aimons tous. :kissing_heart: 

 

