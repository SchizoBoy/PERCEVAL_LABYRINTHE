/* Fichier source contenant la fonction principale de l'exécutable */
/* perceval_labyrinthe */

#include <stdlib.h>
#include <stdio.h>
#include <MLV/MLV_all.h>
#include "labyrinthe.h"
#include "utilitaire.h"
#include "tla.h"
#include "graphique.h"

int main(){
  laby l;

  l = fusion_labyrinthe();

  init_fenetre();

  dessiner_labyrinthe(l);

  exit(0);
}
