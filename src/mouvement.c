/* Fichier source contenant les fonctions associées aux mouvements des objets */
/* de jeu */

#include "objets.h"

/* Fonction animant un objet vers la gauche */
void mouvement_gauche(objet *obj){
  obj->x -= 50;
}

/* Fonction animant un objet vers la droite */
void mouvement_droite(objet *obj){
  obj->x += 50;
}

/* Fonction animant un objet vers le haut */
void mouvement_haut(objet *obj){
  obj->y -= 50;
}

/* Fonction animant un objet vers le bas */
void mouvement_bas(objet *obj){
  obj->y += 50;
}
