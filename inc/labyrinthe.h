/* Fichier header contenant les prototypes des fonctions concernant les */
/* labyrinthes */

#ifndef LABYRINTHE_H_
#define LABYRINTHE_H_

#include "tla.h"

#define L 10          /* Largeur du labyrinthe */
#define H 10          /* Hauteur du labyrinthe */

/* Définition de la structure du labyrinthe */
typedef struct laby{
  tla t;              /* TLA du labyrinthe */
  int nb_sommet;      /* Nombre de sommet dans le graphe */
}laby;

/* Fonction permettant de créer un labyrinthe connexe */
laby fusion_labyrinthe();

#endif
