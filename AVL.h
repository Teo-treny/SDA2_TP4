/**
 * @file AVL.h
 * @author TRENY Téo (treny.teojgh@gmail.com // teo.treny@ig2i.centralelille.fr)
 * @brief Fichier header contenant les prototypes des fonctions de AVL.c
 * @version 1.0
 * @date 2021-10-27
 * 
 * 
 */
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

/**
 * @brief       Affichage ordonne d'un arbre
 * @author      Téo Trény
 * @param a     Arbre
 */
void afficherOrdonne(noeudAVL_t * a);

/**
 * @brief       Affichage inverse d'un arbre
 * @author      Téo Trény
 * @param a     Arbre
 */
void afficherInverse(noeudAVL_t * a);

/**
 * @brief       Indique si un element est dans l'arbre
 * @author      Téo Trény
 * @param a     Arbre
 * @param e     Element a chercher
 * @return int  1 : element trouve, 0 : element non trouve
 */
int estMembre(noeudAVL_t * a, elt_t e);

/**
 * @brief       Renvoie le nombre de noeuds
 * @author      Téo Trény
 * @param a     Arbre
 * @return int  Nombre de noeuds
 */
int nbElts(noeudAVL_t * a);

/**
 * @brief       Renvoie la hauteur d'un arbre
 * @author      Téo Trény
 * @param a     Arbre
 * @return int  Hauteur de l'arbre
 */
int hauteur(noeudAVL_t * a);

/**
 * @brief                   Execute une rotation gauche sur un arbre
 * @author                  Téo Trény
 * @param a                 Arbre
 * @return noeudAVL_t *      Arbre apres rotation
 */
noeudAVL_t * rotationGauche(noeudAVL_t * a);

/**
 * @brief                   Execute une rotation droite sur un arbre
 * @author                  Téo Trény
 * @param a                 Arbre
 * @return noeudAVL_t *      Arbre apres rotation
 */
noeudAVL_t * rotationDroite(noeudAVL_t * a);

/**
 * @brief                   Fonction qui permet d'equilibrer un arbre en faisant des rotations
 * @author                  Téo Trény
 * @param a                 Arbre
 * @return noeudAVL_t *      Arbre equilibre
 */
noeudAVL_t * equilibrer (noeudAVL_t * a);

/**
 * @brief                   Permet d'ajouter un noeud à un arbre
 * @author                  Téo Trény
 * @param e                 Element du noeud
 * @param g                 Adresse du noeud gauche
 * @param d                 Adresse du noeud droit
 * @return noeudAVL_t *      Nouveau noeud
 */
noeudAVL_t * creer1Noeud(elt_t e, noeudAVL_t * g, noeudAVL_t * d);

/**
 * @brief                   Permet d'inserer une valeur dans un arbre en respectant l'equilibre
 * @author                  Téo Trény    
 * @param e                 Element a ajouter
 * @param a                 Arbre auquel il faut ajouter l'element
 * @return noeudAVL_t *      Arbre modifie
 */
noeudAVL_t * insererAVL(elt_t e, noeudAVL_t * a);

/**
 * @brief                   Permet de supprimer un element dans l'arbre en respectant l'equilibre (NE FONCTIONNE PAS)
 * @author                  Téo Trény / Urban Prevost
 * @param e                 Element a supprimer
 * @param a                 Arbre auquel il faut supprimer l'element
 * @return noeudAVL_t *      Arbre modifie
 */
noeudAVL_t * supprimerElt(elt_t e, noeudAVL_t * a);

/**
 * @brief                   Permet de generer un .dot pour en suite generer un .png
 * @author                  Samir El Khattabi
 * @param arbre             Arbre
 * @param basename          Nom du fichier
 */
void creerDotAVL(const noeudAVL_t * arbre, const char *basename);

/**
 * @brief                   Permet de generer un .png representant la structure de l'arbre
 * @author                  Téo Trény
 * @param a                 Arbre à afficher
 * @param fp                Pointeur fichier
 */
void genererDotPng(const noeudAVL_t * a, FILE *fp);

// MACROS

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
