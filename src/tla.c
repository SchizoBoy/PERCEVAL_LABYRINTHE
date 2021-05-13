/* Fichier source contenant les fonctions sur les TLA */

#include <stdlib.h>
#include <stdio.h>
#include "utilitaire.h"
#include "liste.h"
#include "tla.h"

/* crée un TLA */
tla creer_tla(int nb_sommet){
  tla t = malloc(nb_sommet * sizeof(liste));
  verif_alloc(t);

  return t;
}

/* Rajoute une arete au TLA */
void ajouter_arete(tla t, int x, int y){
  t[x] = empiler(t[x], y);
  t[y] = empiler(t[y], x);
}

/* Permet d'afficher un TLA */
void affiche_tla(tla t, int nb_sommet){
  int i;
  liste iter;
  for(i = 0; i < nb_sommet; i++){     /* On parcours le TLA */
    iter = t[i];
    printf("successeurs de %d <", i);
    if(est_liste_vide(iter)){         /* Aucun successeurs */
      puts(">");
    }
    else{
      while(!est_liste_vide(iter->suivant)){ /* On parcours les successeurs */
        printf("%d, ", element_liste(iter)); /* On affiche le successeur */
        iter = iter->suivant;                /* On avance */
      }

      printf("%d>\n", iter->obj);           /* On affiche le dernier élément*/
    }
  }
}

/* Fonction vérifiant si une arete existe */
int est_arete(tla t, int x, int y){
  return est_present(t[x], y);
}
