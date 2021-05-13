/* Fichier header contenant les prototypes des fonctions concernant les TLA */

#ifndef TLA_H_
#define TLA_H_

#include "liste.h"

typedef liste *tla;

/* crée un TLA */
tla creer_tla(int nb_sommet);

/* Rajoute une arete au TLA */
void ajouter_arete(tla t, int x, int y);

/* Permet d'afficher un TLA */
void affiche_tla(tla t, int nb_sommet);

#endif
