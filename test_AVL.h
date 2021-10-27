/**
 * @file test_AVL.h
 * @author TRENY Téo (treny.teojgh@gmail.com // teo.treny@ig2i.centralelille.fr)
 * @brief Fichier header contenant les prototypes des fonctions de test_AVL.c
 * @version 1.0
 * @date 2021-10-27
 * 
 * 
 */
#include "AVL.h"

#ifndef _test_AVL_H_
#define _test_AVL_H_

void test_afficherOrdonne(noeudAVL_t * a);

void test_afficherInverse(noeudAVL_t * a);

void test_estMembre(noeudAVL_t * a);

void test_nbElts(noeudAVL_t * a);

void test_hauteur(noeudAVL_t * a);

noeudAVL_t * test_insererAVL(noeudAVL_t * a);

noeudAVL_t * test_insererXAVL(noeudAVL_t * a);

noeudAVL_t * test_supprimerElt(noeudAVL_t * a);

#endif