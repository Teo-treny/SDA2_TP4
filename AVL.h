#ifndef _AVL_H_
#define _AVL_H_

typedef int elt_t;

typedef struct noeudAVL noeudAVL_t;

struct noeudAVL {
    elt_t elt;
    struct noeudAVL * gauche;
    struct noeudAVL * droite;
    int bal;
};

void afficherOrdonne(noeudAVL_t * a);

void afficherInverse(noeudAVL_t * a);

int estMembre(noeudAVL_t * a, elt_t e);

int nbElts(noeudAVL_t * a);

int hauteur(noeudAVL_t * a);

noeudAVL_t * inserer1Elt(noeudAVL_t * a);

noeudAVL_t * supprimer1Elt(noeudAVL_t * a);

noeudAVL_t * rotationGauche(noeudAVL_t * a);

noeudAVL_t * rotationDroite(noeudAVL_t * a);

noeudAVL_t * equilibrer (noeudAVL_t * a);

#define	MAX(a,b)	(((a) >= (b)) ? (a) : (b))
#define VIDE(a) ((a) == NULL)
#define PASVIDE(a) ((a) != NULL)
#define ELT(a) ((a)->elt)
#define BAL(a) ((a)->bal)
#define GAUCHE(a) ((a)->gauche)
#define DROITE(a) ((a)->droite)
#define ESTFEUILLE(a) ((a)->droite == NULL && (a)->gauche == NULL)
#define A_UN_ENFANT(a) ((a)->droite != NULL ^ (a)->gauche != NULL)

#endif
