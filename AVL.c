#include <stdlib.h>
#include <stdio.h>
#include "AVL.h"

// Protos fonctions locales
void afficherElt(elt_t e);

void afficherElt(elt_t e) {
    printf("%d\t", e);
}

/* ------------------------------
 * 1ERE PARTIE                  *
 ----------------------------- */

void afficherOrdonne(noeudAVL_t * a) {
    if PASVIDE(a) {
        afficherOrdonne(GAUCHE(a));
        afficherElt(ELT(a));
        afficherOrdonne(DROITE(a));
    }
}

void afficherInverse(noeudAVL_t * a) {
    if PASVIDE(a) {
        afficherOrdonne(DROITE(a));
        afficherElt(ELT(a));
        afficherOrdonne(GAUCHE(a));
    }
}

int estMembre(noeudAVL_t * a, elt_t e) {
    if VIDE(a) return 0;
    if (ELT(a) == e) return 1;
    if (e < ELT(a)) return estDansABR(e, GAUCHE(a));
    return estDansABR(e, DROITE(a));
}

int nbElts(noeudAVL_t * a) {
    if VIDE(a) return 0;
    return 1 + nbElts(GAUCHE(a)) + nbElts(DROITE(a));
}

int hauteur(noeudAVL_t * a) {
    if VIDE(a) return -1;
    int g = hauteur(GAUCHE(a));
    int d = hauteur(DROITE(a));
    return 1 + MAX(g,d);
}

/* ------------------------------
 * 2EME PARTIE                  *
 ----------------------------- */

 