/* Fichier source contenant les fonctions concernant le graphisme */

#include <MLV/MLV_all.h>
#include "labyrinthe.h"
#include "liste.h"
#include "tla.h"

/* Fonction permettant d'initialiser la fenetre MLV */
void init_fenetre(){
  MLV_create_window("PERCEVAL_LABYRINTHE", "PERCEVAL_LABYRINTHE", 500, 500);
  MLV_clear_window(MLV_COLOR_BLACK);
}

void dessiner_labyrinthe(laby l){
  int i;
  liste iter;
  int src, dest;

  for(i = 0; i < l.nb_sommet; i++){
    iter = l.t[i];
    src = i;
    while(iter != NULL){
      dest = element_liste(iter);
      printf("%d %d\n", src, dest);

      if(dest == src+L){
          MLV_draw_filled_rectangle((src%L)*50+4,
                                    (src/L)*50+4,
                                    42, 92,
                                    MLV_COLOR_WHITE
                                  );
      }else if(dest == src+1){
          MLV_draw_filled_rectangle((src%L)*50+4,
                                    (src/L)*50+4,
                                    92, 42,
                                    MLV_COLOR_WHITE
                                  );
      }
      iter = iter->suivant;
      MLV_actualise_window();
    }
  }
  MLV_actualise_window();
  MLV_wait_mouse(NULL, NULL);
}
