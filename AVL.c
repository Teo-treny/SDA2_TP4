#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

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
    if (e < ELT(a)) return estMembre(GAUCHE(a), e);
    return estMembre(DROITE(a), e);
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

/* 
On a deux rotations :
    - Rotation droite
    - Rotation gauche
*/

noeudAVL_t * rotationGauche(noeudAVL_t * a) {
    noeudAVL_t * b = DROITE(a);
    DROITE(a) = GAUCHE(b);
    GAUCHE(b) = a;
    BAL(a) = hauteur(DROITE(a)) - hauteur(GAUCHE(a));
    BAL(b) = hauteur(DROITE(b)) - hauteur(GAUCHE(b));
    a = b;
    return b;
}

noeudAVL_t * rotationDroite(noeudAVL_t * a) {
    noeudAVL_t * b = GAUCHE(a);
    GAUCHE(a) = DROITE(b);
    DROITE(b) = a;
    BAL(a) = hauteur(DROITE(a)) - hauteur(GAUCHE(a));
    BAL(b) = hauteur(DROITE(b)) - hauteur(GAUCHE(b));
    a = b;
    return b;
}

/*
On est en déséquilibre quand BAL(a) = -2 ou 2.
Ce qui veut dire que la différence de hauteur
entre l'arbre de droite, et l'arbre gauche vaut 2 ou -2.
Si il vaut 2, alors on penche à droite, sinon on penche à gauche.
*/

noeudAVL_t * equilibrer(noeudAVL_t * a) {
    // déséquilibre à gauche
    if(BAL(a) == -2) {
        #ifdef DEBUG
            printf("\033[0;31m");
            printf("Desequilibre a gauche !\n");
            printf("\033[0m");
        #endif
        // cas d'une double rotation
        if(BAL(GAUCHE(a)) == 1) {
            #ifdef DEBUG
                printf("\033[0;31m");
                printf("Rotation gauche sur enfant gauche !\n");
                printf("\033[0m");
            #endif
            // creerDotAVL(a, "AVL_AV_rotG");
            GAUCHE(a) = rotationGauche(GAUCHE(a));
            // creerDotAVL(a, "AVL_AP_rotG");
        }
        // rotation effectuée peu importe le cas
        #ifdef DEBUG
            printf("\033[0;31m");
            printf("Rotation droite !\n");
            printf("\033[0m");
        #endif
        // creerDotAVL(a, "AVL_AV_rotD");
        a = rotationDroite(a);
        // creerDotAVL(a, "AVL_AP_rotD");
    }
    // déséquilibre à droite
    if(BAL(a) == 2) {
        #ifdef DEBUG
            printf("\033[0;31m");
            printf("Desequilibre a droite !\n");
            printf("\033[0m");
        #endif
        // cas d'une double rotation
        if(BAL(DROITE(a)) == -1) {
            #ifdef DEBUG
                printf("\033[0;31m");
                printf("Rotation droite sur enfant droite !\n");
                printf("\033[0m");
            #endif
            // creerDotAVL(a, "AVL_AV_rotD");
            DROITE(a) = rotationDroite(DROITE(a));
            // creerDotAVL(a, "AVL_AP_rotD");
        }
        // rotation effectuée peu importe le cas
        #ifdef DEBUG
            printf("\033[0;31m");
            printf("Rotation gauche !\n");
            printf("\033[0m");
        #endif
        // creerDotAVL(a, "AVL_AV_rotG");
        a = rotationGauche(a);
        // creerDotAVL(a, "AVL_AP_rotG");
    }
    return a;
}

noeudAVL_t * creer1Noeud(elt_t e, noeudAVL_t * g, noeudAVL_t * d) {
    noeudAVL_t * p;
    p = (noeudAVL_t *)malloc(sizeof(noeudAVL_t));
    if (p != NULL) {
        p->elt = e;
        p->gauche = g;
        p->droite = d;
        p->bal = 0;
    }
    return p;
}

noeudAVL_t * insererAVL(elt_t e, noeudAVL_t * a) {
    if (estMembre(a, e)) return a;
    if VIDE(a) {
        #ifdef DEBUG
            printf("\033[0;31m");
            printf("Le noeud actuel est vide !\n");
            printf("\033[0m");
        #endif
        return creer1Noeud(e, NULL, NULL);
    }
    else if (e < ELT(a)) {
        #ifdef DEBUG
            printf("\033[0;31m");
            printf("On descend a gauche !\n");
            printf("\033[0m");
        #endif
        GAUCHE(a) = insererAVL(e, GAUCHE(a));
    }
    else {
        #ifdef DEBUG
            printf("\033[0;31m");
            printf("On descend a droite !\n");
            printf("\033[0m");
        #endif
        DROITE(a) = insererAVL(e, DROITE(a));
    }
    BAL(a) = hauteur(DROITE(a)) - hauteur(GAUCHE(a));
    a = equilibrer(a);
    return a;
}

noeudAVL_t * supprimerElt(elt_t e, noeudAVL_t * a) {
    return NULL;
}

void genererDotPng(const noeudAVL_t * a, FILE *fp) {
    if PASVIDE(a) {

        fprintf(fp, "%d [label = \"{<c> %d | {", ELT(a), ELT(a));
        
        // affichage gauche
        if (PASVIDE(GAUCHE(a)))
            fprintf(fp, "<g> | ");
        else
            fprintf(fp, "<g> NULL | ");

        // affichage droite
        if (PASVIDE(DROITE(a)))
            fprintf(fp, "<d>");
        else
            fprintf(fp, "<d> NULL");

        fprintf(fp,"} | { <c> bal = %d}}\"];\n",a->bal);

        // on ne peut pas gérer l'affichage et l'exploration en meme temps
        // sinon on passe au noeud suivant sans avoir fini d'écrire le premier

        if (PASVIDE(GAUCHE(a))) {
            fprintf(fp, "%d:g -> %d;\n", ELT(a), ELT(GAUCHE(a)));
            genererDotPng(GAUCHE(a), fp);
        }
        if (PASVIDE(DROITE(a))) {
            fprintf(fp, "%d:d -> %d;\n", ELT(a), ELT(DROITE(a)));
            genererDotPng(DROITE(a), fp);
        }        
    }
}

void creerDotAVL(const noeudAVL_t * arbre, const char *basename) {
    static char oldBasename[FILENAME_MAX + 1] = "";
    char fnameDot [FILENAME_MAX + 1];
    char fnamePng [FILENAME_MAX + 1];
    static unsigned int noVersion = 0;
    char	cmdLine [2 * FILENAME_MAX + 20];
    FILE *fp;
    
    /*
     *	Au premier appel, création (si nécessaire) des répertoires
     *	où seront rangés les fichiers .dot et .png générés par cette
     *	fonction
     */
    if (oldBasename[0] == '\0')
    {
        mkdir(DOSSIER_PNG,	S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
        mkdir(DOSSIER_DOT,	S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
    }
    /*
     *	S'il y a changement de nom de base alors recommencer
     *	à zéro, la numérotation des fichiers
     */
    if (strcmp(oldBasename, basename) != 0)
    {
        noVersion = 0;
        strcpy(oldBasename, basename);
    }
    sprintf(fnameDot, "%s%s_v%02u.dot", DOSSIER_DOT, basename, noVersion);
    sprintf(fnamePng, "%s%s_v%02u.png", DOSSIER_PNG, basename, noVersion);
    if ( (fp = fopen(fnameDot, "w")) == NULL)
    {
        fprintf(stderr, "Impossible de creer le fichier \"%s\"\n", fnameDot);
        exit(EXIT_FAILURE);
    }
    
    noVersion ++;
    fprintf(fp, "digraph %s {\n", basename);
    fprintf(fp,
            "\tnode [\n"
            "\t\tfontname  = \"Arial bold\" \n"
            "\t\tfontsize  = \"14\"\n"
            "\t\tfontcolor = \"red\"\n"
            "\t\tstyle     = \"rounded, filled\"\n"
            "\t\tshape     = \"record\"\n"
            "\t\tfillcolor = \"grey90\"\n"
            "\t\tcolor     = \"blue\"\n"
            "\t\twidth     = \"2\"\n"
            "\t]\n"
            "\n"
            "\tedge [\n"
            "\t\tcolor     = \"blue\"\n"
            "\t]\n\n"
            );
    
    if (arbre == NULL)
        fprintf(fp, "\n");
    else
        genererDotPng(arbre, fp);
    
    fprintf(fp, "}\n");	
    fclose(fp);
    
    sprintf(cmdLine, "%s -Tpng  %s -o %s", DOT_CMD, fnameDot, fnamePng);
    system(cmdLine);
    
    printf("Creation de '%s' et '%s' ... effectuee\n", fnameDot, fnamePng);
}