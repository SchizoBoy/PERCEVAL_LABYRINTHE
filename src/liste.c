/* Fichier source contenant les fonctions sur les listes */

#include <stdlib.h>
#include <stdio.h>
#include "utilitaire.h"
#include "liste.h"

/* Fonction renvoyant une liste vide */
liste liste_vide(){
  return NULL;
}

/* Fonction déterminant si une liste est vide */
int est_liste_vide(liste l){
  return (l == NULL);
}

/* empile un élement sur une liste */
liste empiler(liste l, int elem){
  liste new;

  new = malloc(sizeof(struct cellule)); /* Allocation */
  verif_alloc(new);                     /* Vérification */

  new->obj = elem;
  new->suivant = NULL;

  if(est_liste_vide(l)){  /* Si la liste est vide */
    return new;           /* On retourne le nouvel élément */
  }
  else{                   /* Sinon */
    new->suivant = l;     /* On empile */
    return new;           /* On retourne la nouvelle liste */
  }
}

/* Depile une liste et renvoie l'élément dépilé */
int depiler(liste l){
  int elem;

  if(est_liste_vide(l)){  /* Impossible de dépiler une liste vide */
    err_exit("depiler : impossible de dépiler une liste vide");
  }

  elem = l->obj;          /* On récupère l'élément */
  l = l->suivant;         /* On dépile la liste */

  return elem;            /* On retourne l'élément */
}

/* Renvoie l'élément courant de la liste */
int element_liste(liste l){
  if(est_liste_vide(l)){    /* Liste vide donc pas d'élément */
    err_exit("element_liste : liste vide donc pas d'élément à renvoyer");
  }

  return l->obj;
}

/* détermine si un element est dans une lite */
int est_present(liste l, int elem){
  liste iter;
  int present = 0;

  iter = l;
  while(iter != NULL && !present){
    if(iter->obj == elem){
      present = 1;
    }
    iter = iter->suivant;
  }

  return present;
}
