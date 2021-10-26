#include <stdlib.h>
#include <time.h>

#include "test_AVL.h"
#include "AVL.h"

void test_afficherOrdonne(noeudAVL_t * a) {
    printf("AFFICHAGE ORDONNE :\n");
    afficherOrdonne(a);
    printf("\n\n");
}

void test_afficherInverse(noeudAVL_t * a) {
    printf("AFFICHAGE INVERSE :\n");
    afficherInverse(a);
    printf("\n\n");
}

void test_estMembre(noeudAVL_t * a) {
    elt_t e;
    printf("Element a chercher : ");
    fflush(stdout);
    scanf("%d", &e);
    printf("%d est membre de l'arbre ? %s\n\n", e, estMembre(a, e) ? "OUI" : "NON");
}

void test_nbElts(noeudAVL_t * a) {
    printf("L'arbre contient %d elements\n\n", nbElts(a));
}

void test_hauteur(noeudAVL_t * a) {
    printf("L'arbre est de hauteur %d\n\n", hauteur(a));
}

noeudAVL_t * test_insererAVL(noeudAVL_t * a) {
    elt_t e;
    printf("Element a inserer : ");
    fflush(stdout);
    scanf("%d", &e);
    a = insererAVL(e, a);
    return a;
}

noeudAVL_t * test_insererXAVL(noeudAVL_t * a) {
    int nb, choix, val;

    srand((unsigned int)time(NULL));

    printf("Nombre d'insertion aleatoire : ");
    fflush(stdout);
    scanf("%d", &nb);
    printf("Creer un png a chaque insertion ? (Deconseille si nb > 20)\n(1 : oui / 0 : non)\n>>");
    fflush(stdout);
    scanf("%d", &choix);
    
    for (int i = 0 ; i < nb ; i++) {
        val = 1 + rand() % nb;
        printf("Insertion de : %d\n", val);
        a = insererAVL(val, a);
        if (choix) creerDotAVL(a, "AVL_inser");
    }
    return a;
}

void test_supprimerElt(noeudAVL_t * a) {
    elt_t e;
    printf("Element a supprimer : ");
    fflush(stdout);
    scanf("%d", &e);
    a = supprimerElt(e, a);
}