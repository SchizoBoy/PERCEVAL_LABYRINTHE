/* Fichier source contenant les fonctions utilitaires */

#include <stdlib.h>
#include <stdio.h>

/* Permet de renvoyer une erreur sur stderr et d'interrompre le programme */
void err_exit(char *error){
  fprintf(stderr, "err_exit : %s\n", error);
  exit(-1);
}

/* Permet de renvoyer une erreur sur stderr sans interrompre le programme */
void err_log(char *error){
  fprintf(stderr, "err_log : %s\n", error);
}

/* Fonction permettant de vérifier une allocation */
void verif_alloc(void *ptr){
  if(ptr == NULL){
    err_exit("erreur d'allocation");
  }
}

/* Fonction permettant d'afficher une matrice d'adjacence */
void affiche_mad(int **mad, int larg, int haut){
  int i, j;
  for(i = 0; i < haut; i++){
    for(j = 0; j < larg; j++){
      printf("%d ", mad[i][j]);
    }
    putchar('\n');
  }
  putchar('\n');
}
