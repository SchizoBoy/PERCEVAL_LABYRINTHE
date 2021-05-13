/* Fichier source contenant les fonctions concernant les labyrinthes */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "utilitaire.h"
#include "labyrinthe.h"
#include "liste.h"
#include "tla.h"

/* Fonction de création d'un labyrinthe doté de tous ses murs */
laby creer_labyrinthe(){
  laby l;

  l.nb_sommet = L*H;                    /* Nombre de sommet dans le graphe */
  l.t = creer_tla(l.nb_sommet);         /* Allocation du TLA */

  return l;
}

int *init_partition(int n){
  int i, *part;

  part = malloc(n * sizeof(int));   /* Allocation */
  verif_alloc(part);                /* Vérification */
  for(i = 0; i < n; i++){           /* Initialisation */
    part[i] = i;
  }

  return part;
}

void fusion(int *part, int nb_sommet, int x, int y){
  int i, px, py;

  px = part[x];
  py = part[y];

  for(i = 0; i < nb_sommet; i++){   /* Pour toutes les partitions */
    if(part[i] == py){              /* Si une partition est égale à y */
      part[i] = px;                 /* Elle est désormais égale à x */
    }
  }
}

/* Fonction permettant de créer un labyrinthe connexe */
laby fusion_labyrinthe(){
  laby l;
  int *part;
  int x, y, nb_partition, part_act, sommet_act, pos_marteau;

  l = creer_labyrinthe();       /* Création du labyrinthe */

  /* Nombre de partition (nombre de sommet pour l'instant) */
  nb_partition = l.nb_sommet;

  /* Création et initialisation du tableau contenant les partitions */
  part = init_partition(nb_partition);

  while(nb_partition != 1){     /* On réduit le nombre de partition à 1 */
    x = rand()%H;
    y = rand()%L;
    pos_marteau = rand()%4;

    sommet_act = x*L+y;           /* Index de la partition actuelle */
    part_act = part[sommet_act];  /* Partition actuelle */

    /* choix du mur à casser */
    switch(pos_marteau){          /* On casse un mur  */
      case 0: /* Haut */
        if(sommet_act > L){
          if(!est_present(l.t[sommet_act], sommet_act-L)){
            if(part_act != part[sommet_act-L]){
              ajouter_arete(l.t, sommet_act, sommet_act-L);
              fusion(part, l.nb_sommet, part_act, part[sommet_act-L]);
              nb_partition--;
            }
          }
        }
        break;
      case 1: /* Droite */
        if((sommet_act % L) != (L-1)){
          if(!est_present(l.t[sommet_act], sommet_act+1)){
            if(part_act != part[sommet_act+1]){
              ajouter_arete(l.t, sommet_act, sommet_act+1);
              fusion(part, l.nb_sommet, part_act, part[sommet_act+1]);
              nb_partition--;
            }
          }
        }
        break;
      case 2: /* Bas */
        if(sommet_act < (H-1)*L){
          if(!est_present(l.t[sommet_act], sommet_act+L)){
            if(part_act != part[sommet_act+L]){
              ajouter_arete(l.t, sommet_act, sommet_act+L);
              fusion(part, l.nb_sommet, part_act, part[sommet_act+L]);
              nb_partition--;
            }
          }
        }
        break;
      case 3: /* Gauche */
        if((sommet_act % L) != 0){
          if(!est_present(l.t[sommet_act], sommet_act-1)){
            if(part_act != part[sommet_act-1]){
              ajouter_arete(l.t, sommet_act, sommet_act-1);
              fusion(part, l.nb_sommet, part_act, part[sommet_act-1]);
              nb_partition--;
            }
          }
        }
        break;
    }
  }
  free(part);
  return l;
}
