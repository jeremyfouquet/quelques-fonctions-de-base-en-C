//
//  main.c
//  fonctions de base
//
//  Created by Jeremy Fouquet on 01/04/2022.
//

#include <stdio.h> // puts(), printf()
#include <stdlib.h> // exit()
#include <string.h> // strlen()

#define string char *

void usage(const string); // prototype
void compte(const string); // prototype
int fonctionCompte1(string S); // prototype
int fonctionCompte2(string S); // prototype
void parcour(const string); // prototype
void fonctionParcour(string S); // prototype
void egaux(const string); // prototype
int fonctionEgaux(string S, char C); // prototype
//void copieChaine(const string titre); // prototype
//void fonctionCopieChaine(string Destination, string Source); // prototype

int main(int argc, const char * argv[]) {
    compte("Compte");
    parcour("Parcour");
    egaux("Egaux");
//    copieChaine("Copie Chaine");
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
    printf("\n%s\n", "Compter le nombre de caractères d’une chaîne (terminée par le caractère '\\0')");
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
    printf("\n%s\n", "action de simple parcours en imprimant un ”+” par exemple à chaque caractère parcouru");
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
    printf("\n%s\n", "compte le nombre de caractères égaux à son deuxième argument ");
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

//void copieChaine(const string titre) {
//    printf("\n%s\n", titre);
//    printf("\n%s\n", "fonction qui copie une chaîne");
//    puts("");
//    string S = "Hello Hello";
//    string SCopie = malloc((sizeof(S)) + 1) ;
//    fonctionCopieChaine(SCopie, S);
//    printf("Chaine d'origine : %s\nChaine Copié : %s\n", S, SCopie);
//    puts("");
//}

//void fonctionCopieChaine(string Destination, string Source) {
//    while (* Source) (* Destination) = (* Source) ;
//    (* Destination) = '\0' ;
//}

void usage(const string D) {
    printf("Erreur en provenance de : %s\n", D);
    exit(1) ;
}
