/* Fichier header contenant les prototypes des fonctions conernant */

#ifndef LISTE_H_
#define LISTE_H_

typedef struct cellule{
  int obj;
  struct cellule *suivant;
}cellule;

typedef struct cellule *liste;

/* Fonction renvoyant une liste vide */
liste liste_vide();

/* Fonction déterminant si une liste est vide */
int est_liste_vide(liste l);

/* empile un élement sur une liste */
liste empiler(liste l, int elem);

/* Depile une liste et renvoie l'élément dépilé */
int depiler(liste l);

/* Renvoie l'élément courant de la liste */
int element_liste(liste l);

/* détermine si un element est dans une lite */
int est_present(liste l, int elem);

/* Fonction permettant de détruire une liste */
void detruire_liste(liste l);

#endif
