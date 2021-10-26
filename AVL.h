#include <stdio.h>

#ifndef _AVL_H_
#define _AVL_H_

#define	DOSSIER_DOT	"./Dot/"
#define	DOSSIER_PNG	"./Png/"
#define	DOT_CMD		"dot"


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

noeudAVL_t * rotationGauche(noeudAVL_t * a);

noeudAVL_t * rotationDroite(noeudAVL_t * a);

noeudAVL_t * equilibrer (noeudAVL_t * a);

noeudAVL_t * creer1Noeud(elt_t e, noeudAVL_t * g, noeudAVL_t * d);

noeudAVL_t * insererAVL(elt_t e, noeudAVL_t * a);

noeudAVL_t * supprimerElt(elt_t e, noeudAVL_t * a);

void creerDotAVL(const noeudAVL_t * arbre, const char *basename);

void genererDotPng(const noeudAVL_t * a, FILE *fp);

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
