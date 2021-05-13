/* Fichier header contenant les prototypes des fonctions concernant les */
/* touches de jeu */

#ifndef TOUCHE_H_
#define TOUCHE_H_

/* Fonction renvoyant 1 si la fleche de gauche est pressée, 0 sinon */
int est_presse_gauche(MLV_Keyboard_button button);

/* Fonction renvoyant 1 si la fleche de droite est pressée, 0 sinon */
int est_presse_droite(MLV_Keyboard_button button);

/* Fonction renvoyant 1 si la fleche de droite est pressée, 0 sinon */
int est_presse_haut(MLV_Keyboard_button button);

/* Fonction renvoyant 1 si la fleche de droite est pressée, 0 sinon */
int est_presse_bas(MLV_Keyboard_button button);

#endif
