/*
   # *******************************************************
   # Nom ......... : main.c
   # Rôle ........ : Quelques fonctions de base en C
   # Auteur ...... : Jeremy Fouquet
   # Version ..... : V1 2022
   # Compilation :  gcc main.c
   # Execution : ./a.out
   # *******************************************************
*/

typedef struct Doublet element;
struct Doublet
{
    int car;
    struct Doublet * cdr;
};

typedef element * list;

#include <stdio.h> // puts(), printf()
#include <stdlib.h> // exit()
#include <string.h> // strlen()

#define string char *

element * car(element *, int);
element * cdr(element *, list);
list push(list, int);
list copieElement(list);
int estVide(list L);
void usage(const string); // prototype
void compte(const string); // prototype
int fonctionCompte1(string S); // prototype
int fonctionCompte2(string S); // prototype
void parcour(const string); // prototype
void fonctionParcour(string S); // prototype
void egaux(const string); // prototype
int fonctionEgaux(string S, char C); // prototype
void copieChaine(const string titre); // prototype
void compareChaines(const string); // prototype
int my_strcmp(const string S1, const string S2) ;
void contient(const string); // prototype
string strstr(const string Source, const string SousChaine) ;
void occurence(const string) ; // prototype
int my_strstrs(const string S1, const string S2) ;
void positionCaractere(const string) ; // prototype
string my_strchr(char C, string S) ;  // prototype
void fonctionsDesListes(const string); // prototype
void afficherListe(list); // prototype
int compteList(list); // prototype
//list copylist(list L); // prototype
//list garde_superieurs(int, list); // prototype


int main(int argc, const char * argv[]) {
    compte("Compte");
    parcour("Parcour");
    egaux("Egaux");
    copieChaine("Copie Chaine");
    compareChaines("Compare 2 chaines"); // prototype
    contient("Détecter une chaîne dans une autre"); // prototype
    occurence("Nombre d'occurence de chaine"); // prototype
    positionCaractere("Position d’un caractère dans une chaîne");
    fonctionsDesListes("Plusieurs fonctions associées aux listes");
    puts("");
    return 0;
}

void compte(const string titre) {
    //    FONCTION LISP
    //    (defun compte (L)
    //    (cond
    //    ((not L) 0)
    //    ((+ 1 (compte (cdr L)))) ) )
    printf("\n%s\n", titre);
    printf("\n%s\n", "Compte le nombre de caractères d’une chaîne (terminée par le caractère '\\0')");
    puts("");
    string S = "Hello Hello";
    int nb1 = fonctionCompte1(S);
    int nb2 = fonctionCompte2(S);
    printf("%s : %d\n", S, nb1);
    puts("");
    printf("%s : %d\n", S, nb2);
}

int fonctionCompte1(string S) {
    if ((* S) == '\0') return 0 ;
    return 1 + fonctionCompte1(S + 1) ;
}

int fonctionCompte2(string S) {
    if (* S) return 1 + fonctionCompte2(S + 1) ;
    return 0 ;
}

void parcour(const string titre) {
    printf("\n%s\n", titre);
    printf("\n%s\n", "Parcours une chaine en imprimant un ”+” par exemple à chaque caractère parcouru");
    puts("");
    string S = "Hello Hello";
    fonctionParcour(S);
    puts("");
}

void fonctionParcour(string S) {
    if (* S) { printf("+") ;
        fonctionParcour(S + 1) ;
        return ;
    }
    return ;
}

void egaux(const string titre) {
    //    (defun compte-eq (L A)
    //    (cond
    //    ((atom L) 0)
    //    ((eq (car L) A) (+ 1 (compte-eq (cdr L) A)))
    //    ((compte-eq (cdr L) A)) ) )
    printf("\n%s\n", titre);
    printf("\n%s\n", "Compte le nombre de répétition d'un caractère dans une chaine");
    puts("");
    string S = "Hello Hello";
    char c = 'e';
    int nb = fonctionEgaux(S, c);
    printf("%s\n%c : %d", S, c, nb);
    puts("");
}

int fonctionEgaux(string S, char C) {
    if ((* S) == C) return 1 + fonctionEgaux(S + 1, C) ;
    if (* S) return fonctionEgaux(S + 1, C) ;
    return 0 ;
}

void copieChaine(const string titre) {
    printf("\n%s\n", titre);
    printf("\n%s\n", "Copie une chaîne");
    puts("");
    string S = "Hello Hello";
    string SCopie = malloc((sizeof(S)) + 1) ;
    strcpy(SCopie, S);
    printf("Chaine d'origine : %s\nChaine Copié : %s\n", S, SCopie);
    puts("");
}

void compareChaines(const string titre) {
    printf("\n%s\n", titre);
    printf("\n%s\n", "Renvoie un nombre qui est négatif si la première chaîne est inférieure à la deuxième, positif si la première chaîne est plus grande que la deuxième ou zéro si elles sont égales ; une chaîne est plus grande qu’une autre si soit le premier caractère différent est plus grand (en code ascii) ou si elle est plus longue : abc est plus grand que abbbe, et abcd est plus grand que ab.");
    puts("");
    string S1;
    string S2;
    printf("resultat retourné : %d\n", my_strcmp(S1 = "abc", S2 = "abc"));
    printf("resultat retourné : %d\n", my_strcmp(S1 = "abc", S2 = "abbbe"));
    printf("resultat retourné : %d\n", my_strcmp(S1 = "abc", S2 = "abcd"));
}

int my_strcmp(const string S1, const string S2){
    // https://waytolearnx.com/2019/08/comparer-deux-chaines-de-caracteres-en-c.html
    //    Spécification en Lisp :
    //    (string-compare 'abc 'abbbe) => 1
    //    (string-compare 'abc 'abcd) => -1
    //    (string-compare 'abc 'abc) => 0
    int compare = 0;
    int i;
    for(i = 0; S1[i] == S2[i] && S1[i] != '\0'; i++);
    if(S1[i] > S2[i]){
        compare = 1;
        printf("\n%s est superieur à %s\n", S1, S2);
    }
    else if(S1[i] < S2[i]) {
        compare = -1;
        printf("\n%s est inferieur à %s\n", S1, S2);
    }
    else {
        compare = 0;
        printf("\n%s est égale à %s\n", S1, S2);
    }
    return compare;
}

void contient(const string titre) {
    //https://koor.fr/C/cstring/strstr.wp
    printf("\n%s\n", titre);
    printf("\n%s\n", "Renvoi un pointeur visant sa première occurrence, si la sous-chaîne est trouvée dans la chaîne principale. Dans le cas contraire, un pointeur nul (NULL) est renvoyé.");
    string Source = "abbbe";
    string SousChaine = "abc";
    printf("\nRecherche %s dans %s\n", SousChaine, Source);
    printf("\nRetoure de la fonction : %s\n", strstr(Source, SousChaine));
    Source = "ddabcd";
    printf("\nRecherche %s dans %s\n", SousChaine, Source);
    printf("\nRetoure de la fonction : %s\n", strstr(Source, SousChaine));
    puts("");
}

void occurence(const string titre) {
    printf("\n%s\n", titre);
    printf("\n%s\n", "Renvoie le nombre de fois où la sous chaine à été trouvé dans la chaine source");
    string Source = "abbbe";
    string SousChaine = "abc";
    printf("\nIl y a %d occurence(s) de %s dans %s\n", my_strstrs(Source, SousChaine), SousChaine, Source);
    Source = "ddabcdabc";
    printf("\nIl y a %d occurence(s) de %s dans %s\n", my_strstrs(Source, SousChaine), SousChaine, Source);
    puts("");
}

int my_strstrs(const string Source, const string SousChaine) {
    // https://www.developpez.net/forums/d1323227/c-cpp/c/compter-occurrences-d-chaine/
    int i, j, k, compteur = 0;
    for (i=0; Source[i]; i++)
        for (j = i, k =0; Source[j] == SousChaine[k]; j++, k++)
            if (! SousChaine[k + 1])
                compteur++;
    return(compteur);
}

void positionCaractere(const string titre) {
    printf("\n%s\n", titre);
    printf("\n%s\n", "Renvoie le pointeur sur le caractère dans la chaîne, ou NULL si celui ci n'existe pas dans la chaine.");
    char C = 'a';
    string S = "bads";
    printf("\nLa position de %c dans %s est %s\n", C, S, my_strchr(C, S));
    C = 'x';
    S = "bads";
    printf("\nLa position de %c dans %s est %s\n", C, S, my_strchr(C, S));
    puts("");
}

string my_strchr(char C, string S) {
    if (C != * S && * S) return my_strchr(C, S+1) ;
    if (* S == '\0') return NULL;
    else return S;
};

void fonctionsDesListes(const string titre) {
    printf("\n%s\n", titre);
    printf("\n%s\n", "1 - Ajoute un élément dans une liste qu'il soit le premier de celle ci ou non");
    list ma_liste = NULL;
    printf("\n%s\n", "2 - Retourne 1 si la liste est vide et 0 si elle n'est pas vide");
    printf("\nMa liste est vide : %s\n", estVide(ma_liste)? "OUI": "NON");
    printf("\n%s\n", "3 - Affiche tous les élement de la liste les un à la suite des autres");
    ma_liste = push(ma_liste, 500);
    ma_liste = push(ma_liste, 400);
    ma_liste = push(ma_liste, 300);
    ma_liste = push(ma_liste, 200);
    afficherListe(ma_liste);
    puts("");
    printf("\n%s\n", "4 - Compte le nombre d'élément d'une liste");
    printf("\nIl y a %d elements dans la liste\n", compteList(ma_liste));
    printf("\n%s\n", "5 - Copie le premier element de la liste dans un nouvel element");
    list A = copieElement(ma_liste);
    list B = NULL;
    B = push(B, 100);
    printf("%i\n", A->car);
    A = B;
    printf("%i\n", A->car);
    printf("%i\n", B->car);
    puts("");
    afficherListe(ma_liste);
//    puts("");
//    printf("\n%s\n", "6 - Cette fonction modifie directement une liste de nombres en ne gardant que ceux qui sont supérieurs à N");
//    list ma_liste_nb = NULL;
//    ma_liste_nb = push(ma_liste_nb, 10);
//    ma_liste_nb = push(ma_liste_nb, 20);
//    ma_liste_nb = push(ma_liste_nb, 30);
//    ma_liste_nb = garde_superieurs(5, ma_liste_nb);
    puts("");
}

//list garde_superieurs(int N, list L) {
//    if (estVide(L) == 0) {
//        if ( L->car > N) return L->cdr = garde_superieurs(N, L->cdr) ;
//        return garde_superieurs(N, L->cdr) ;
//    }
//    return NULL ;
//}

list car(list nouvelElement, int valeur) {
    nouvelElement->car = valeur;
    return nouvelElement;
}

list cdr(list nouvelElement, list L) {
    nouvelElement->cdr = L;
    return nouvelElement;
}

list push(list L, int valeur) {
    /* On crée un nouvel élément */
    list nouvelElement = malloc(sizeof(element));
    /* On assigne la valeur au nouvel élément */
    nouvelElement = car(nouvelElement, valeur);
    /* On assigne l'adresse de l'élément suivant au nouvel élément */
    nouvelElement = cdr(nouvelElement, L);
    /* On retourne la nouvelle liste, i.e. le pointeur sur le premier élément */
    return nouvelElement;
}

int estVide(list L) {
    return (L == NULL)? 1 : 0;
}

void afficherListe(list L) {
    element * P = L;
    /* Tant que l'on n'est pas au bout de la liste */
    while(estVide(P) == 0) {
        /* On affiche */
        printf("%i\n", P->car);
        /* On avance d'une case */
        P = P->cdr;
    }
}

int compteList(list L) {
    if (estVide(L) == 0) return 1 + compteList(L->cdr) ;
    return 0 ;
    
}

list copieElement(list L) {
    list nouvelElement = malloc(sizeof(element));
    nouvelElement->car = L->car;
    nouvelElement->cdr = L->cdr;
    return nouvelElement;
}

//list copylist(list L) {
//    return (estVide(L)==0) ? push(L->car, copylist(L->cdr)) : NULL ;
//}

void usage(const string D) {
    printf("Erreur en provenance de : %s\n", D);
    exit(1) ;
}
