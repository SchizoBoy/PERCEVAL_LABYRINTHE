/* Fichier source contenant la fonction principale de l'exécutable */
/* perceval_labyrinthe */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "jeu.h"

int main(){
  srand(time(NULL));  /* Initialisation de l'horloge (random) */

  jeu();              /* Lancement de la partie */

  exit(0);
}
