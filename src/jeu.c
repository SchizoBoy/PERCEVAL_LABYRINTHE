/* Fichier source contenant les fonctions concernant le jeu */

#include <MLV/MLV_all.h>
#include "labyrinthe.h"
#include "utilitaire.h"
#include "tla.h"
#include "graphique.h"
#include "objets.h"
#include "mouvement.h"
#include "touche.h"

/* Fonction de début de jeu */
void debut_jeu(){
  MLV_Font *font;

  font = MLV_load_font("./ressources/font/Bubblegum.ttf", 40);
  MLV_clear_window(MLV_COLOR_WHITE);
  MLV_draw_text_with_font(80, 180, "Les avantures de", font, MLV_COLOR_BLACK);
  MLV_draw_text_with_font(160, 220, "Perceval", font, MLV_COLOR_BLACK);

  font = MLV_load_font("./ressources/font/Bubblegum.ttf", 30);
  MLV_draw_text_with_font(110, 290, "Ep2: Le labyrinthe", font, MLV_COLOR_BLACK);

  MLV_actualise_window();
  MLV_wait_keyboard_or_seconds(NULL, NULL, NULL, 3);

  font = MLV_load_font("./ressources/font/Bubblegum.ttf", 40);
  MLV_clear_window(MLV_COLOR_BLACK);
  MLV_draw_text_with_font(80, 200, "Mangez la graine", font, MLV_COLOR_WHITE);

  MLV_actualise_window();
  MLV_wait_keyboard_or_seconds(NULL, NULL, NULL, 3);

  MLV_clear_window(MLV_COLOR_BLACK);
  MLV_free_font(font);
}

/* Fonction de fin de jeu */
void fin_jeu(){
  MLV_Font *font;
  MLV_Image *fin;

  fin = MLV_load_image("./ressources/img/perceval_fin.png");
  MLV_resize_image_with_proportions(fin, 480, 480);

  MLV_clear_window(MLV_COLOR_WHITE);
  MLV_draw_image(fin, 70, 0);

  font = MLV_load_font("./ressources/font/Bubblegum.ttf", 30);
  MLV_draw_text_with_font(120, 400, "Merci beaucoup !", font, MLV_COLOR_BLACK);
  font = MLV_load_font("./ressources/font/Bubblegum.ttf", 24);
  MLV_draw_text_with_font(160, 450, "Dessin : Manonz", font, MLV_COLOR_BLACK);

  MLV_actualise_window();
  MLV_wait_keyboard(NULL, NULL, NULL);

  MLV_free_font(font);
  MLV_free_image(fin);
  MLV_free_window();
}

/* Fonction permettant de lancer une partie */
void jeu(){
  MLV_Keyboard_button button;
  MLV_Font *font;
  MLV_Image *gauche, *droite, *haut, *bas;
  laby l;
  objet perceval, graine;
  int fini = 0;

  l = fusion_labyrinthe();  /* Génération du labyrinthe */
  init_fenetre();           /* Initialisation de la fenêtre */

  /* Initialisation des images de Perceval */
  gauche = MLV_load_image("./ressources/img/perceval_gauche.png");
  MLV_resize_image_with_proportions(gauche, 50, 50);
  droite = MLV_load_image("./ressources/img/perceval_droite.png");
  MLV_resize_image_with_proportions(droite, 50, 50);
  haut = MLV_load_image("./ressources/img/perceval_haut.png");
  MLV_resize_image_with_proportions(haut, 50, 50);
  bas = MLV_load_image("./ressources/img/perceval_bas.png");
  MLV_resize_image_with_proportions(bas, 50, 50);


  /* Initialisation de la police */
  font = MLV_load_font("./ressources/font/Bubblegum.ttf", 40);
  /* Initialisation de l'objet Perceval */
  perceval = creer_objet("./ressources/img/perceval_droite.png",
                          50, 50, 2, 252, 50
                        );
  /* Initialisation de l'objet graine */
  graine = creer_objet("./ressources/img/seed.png",
                        42, 42, 454, 254, 59
                      );

  debut_jeu();

  dessiner_labyrinthe(l);     /* On place le labyrinthe */
  affiche_objet(perceval);    /* On place Perceval */
  affiche_objet(graine);      /* On place la graine */

  while(!fini){
    /* On attend qu'une touche soit préssée */
    MLV_wait_keyboard(&button, NULL, NULL);

    /* Flèche de gauche */
    if(est_presse_gauche(button) && (perceval.sommet % L) != 0){
      if(est_arete(l.t, perceval.sommet, perceval.sommet-1)){
        MLV_draw_filled_rectangle(perceval.x+6,
                                  perceval.y+6,
                                  36, 36,
                                  MLV_COLOR_WHITE
                                );
        mouvement_gauche(&perceval);
        perceval.img = gauche;
      }
    }
    /* Flèche de droite */
    else if(est_presse_droite(button) && (perceval.sommet % L) != (L-1)){
      if(est_arete(l.t, perceval.sommet, perceval.sommet+1)){
        MLV_draw_filled_rectangle(perceval.x+6,
                                  perceval.y+6,
                                  36, 36,
                                  MLV_COLOR_WHITE
                                );
        mouvement_droite(&perceval);
        perceval.img = droite;
      }
    }
    /* Flèche du haut */
    else if(est_presse_haut(button) && perceval.sommet > L){
      if(est_arete(l.t, perceval.sommet, perceval.sommet-L)){
        MLV_draw_filled_rectangle(perceval.x+6,
                                  perceval.y+6,
                                  36, 36,
                                  MLV_COLOR_WHITE
                                );
        mouvement_haut(&perceval);
        perceval.img = haut;
      }
    }
    /* Flèche du bas */
    else if(est_presse_bas(button) && perceval.sommet < (H-1)*L){
      if(est_arete(l.t, perceval.sommet, perceval.sommet+L)){
        MLV_draw_filled_rectangle(perceval.x+6,
                                  perceval.y+6,
                                  36, 36,
                                  MLV_COLOR_WHITE
                                );
        mouvement_bas(&perceval);
        perceval.img = bas;
      }
    }
    affiche_objet(perceval);
    MLV_actualise_window();

    fini = est_en_contact(perceval, graine);  /* Actualisation de fini */
  }
  MLV_free_font(font);
  MLV_free_image(gauche);
  MLV_free_image(droite);
  MLV_free_image(haut);
  MLV_free_image(bas);

  fin_jeu();
  detruire_tla(l.t, l.nb_sommet);
}
