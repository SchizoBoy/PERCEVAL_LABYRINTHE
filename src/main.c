/* Fichier source contenant la fonction principale de l'exécutable */
/* perceval_labyrinthe */

#include <stdlib.h>
#include <stdio.h>
#include <MLV/MLV_all.h>
#include "labyrinthe.h"
#include "utilitaire.h"
#include "tla.h"
#include "graphique.h"
#include "objets.h"
#include "mouvement.h"
#include "touche.h"

int main(){
  laby l;
  objet perceval, graine;
  MLV_Keyboard_button button;

  l = fusion_labyrinthe();

  init_fenetre();

  perceval = creer_objet("./ressources/img/perceval_droite.png",
                          50, 50, 2, 252, 50
                        );
  graine = creer_objet("./ressources/img/seed.png",
                        42, 42, 454, 254, 59
                      );

  dessiner_labyrinthe(l);
  affiche_objet(perceval);
  affiche_objet(graine);

  while(1){
    MLV_wait_keyboard(&button, NULL, NULL);

    if(est_presse_gauche(button)){
      mouvement_gauche(&perceval);
    }
    else if(est_presse_droite(button)){
      mouvement_droite(&perceval);
    }
    else if(est_presse_haut(button)){
      mouvement_haut(&perceval);
    }
    else if(est_presse_bas(button)){
      mouvement_bas(&perceval);
    }
    affiche_objet(perceval);
    MLV_actualise_window();
  }
  exit(0);
}
