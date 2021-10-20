#ifndef _AVL_H_
#define _AVL_H_

typedef int elt_t;

typedef struct noeudAVL noeudAVL_t;

struct noeudAVL {
    elt_t elt;
    struct noeudAVL * gauche;
    struct noeudAVL * droite;
};

void afficherOrdonne(noeudAVL_t * a);

void afficherInverse(noeudAVL_t * a);

int estMembre(noeudAVL_t * a);

int nbElts(noeudAVL_t * a);

int hauteur(noeudAVL_t * a);

noeudAVL_t * inserer1Elt(noeudAVL_t * a);

noeudAVL_t * supprimer1Elt(noeudAVL_t * a);

#endif
