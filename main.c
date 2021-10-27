/**
 * @file main.c
 * @author TRENY Téo (treny.teojgh@gmail.com // teo.treny@ig2i.centralelille.fr)
 * @brief Fichier main, utilisant un menu pour manipuler un arbre
 * @version 1.0
 * @date 2021-10-27
 * 
 * 
 */
#include <stdio.h>
#include <stdlib.h>

#include "AVL.h"
#include "test_AVL.h"

int main(void) {
    int choix;
    noeudAVL_t * test = NULL;
    
    // MENU

    // test = insererAVL(12, test);
    // test = insererAVL(5, test);
    // test = insererAVL(20, test);


    do {
        printf("\t --- MENU ---\n");
        printf("1-Affichage ordonne\n");
        printf("2-Affichage inverse\n");
        printf("3-Est dans l'arbre\n");
        printf("4-Nombre elements\n");
        printf("5-Hauteur de l'arbre\n");
        printf("6-Inserer un element\n");
        printf("7-Inserer X elements aleatoirement\n");
        printf("8-Supprimer un element\n");
        printf("9-Generer png\n");
        printf("0-Quitter\n\n");
        printf(">>");
        fflush(stdout);
        scanf("%d", &choix);

        switch(choix) {
            case 1 : 
                test_afficherOrdonne(test);
            break;

            case 2 :
                test_afficherInverse(test);
            break;

            case 3 :
                test_estMembre(test);
            break;

            case 4 :
                test_nbElts(test);
            break;

            case 5 :
                test_hauteur(test);
            break;

            case 6 :
                test = test_insererAVL(test);
            break;

            case 7 :
                test = test_insererXAVL(test);
            break;

            case 8 :
                test = test_supprimerElt(test);
            break;

            case 9 :
                creerDotAVL(test, "AVL");
            break;
        }

    } while (choix != 0); 

    return 0;
}