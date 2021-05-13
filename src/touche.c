/* Fichier source contenant les fonctions concernant les touches de jeu */

#include <MLV/MLV_all.h>

/* Fonction renvoyant 1 si la fleche de gauche est pressée, 0 sinon */
int est_presse_gauche(MLV_Keyboard_button button){
  return (button == MLV_KEYBOARD_LEFT);
}

/* Fonction renvoyant 1 si la fleche de droite est pressée, 0 sinon */
int est_presse_droite(MLV_Keyboard_button button){
  return (button == MLV_KEYBOARD_RIGHT);
}

/* Fonction renvoyant 1 si la fleche de droite est pressée, 0 sinon */
int est_presse_haut(MLV_Keyboard_button button){
  return (button == MLV_KEYBOARD_UP);
}

/* Fonction renvoyant 1 si la fleche de droite est pressée, 0 sinon */
int est_presse_bas(MLV_Keyboard_button button){
  return (button == MLV_KEYBOARD_DOWN);
}
