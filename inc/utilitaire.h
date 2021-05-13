/* Fichier header contenant les prototypes des fonctions utilitaires */

#ifndef UTILITAIRE_H_
#define UTILITAIRE_H_

/* Permet de renvoyer une erreur sur stderr et d'interrompre le programme */
void err_exit(char *error);

/* Permet de renvoyer une erreur sur stderr sans interrompre le programme */
void err_log(char *error);

/* Fonction permettant de vérifier une allocation */
void verif_alloc(void *ptr);

/* Fonction permettant d'afficher une matrice d'adjacence */
void affiche_mad(int **mad, int larg, int haut);

#endif
