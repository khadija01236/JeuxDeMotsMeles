#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

// Liste des mots à trouver
const char *mots[] =
{
    "chat",
    "chien",
    "oiseau",
    "renart",
    "poule",
    "lion",
    "panthere",
    // Ajoutez d'autres mots ici
};

int main() {

    char grille[LIG][COL];
    char themechoisi[20];
    int i, j;
    char direction;
    int TailleTab = 10;
    int nblignes = LIG,  nbcolonnes = COL;
    srand(time(NULL));


    //choisir la taille de la grille
    ChoisirTailleTab(&nblignes, &nbcolonnes);
    //Initialiser la grille
    initialiserTab(grille);
    // Placer les mots dans la grille
    placerMotsDansTab(grille,mots,NOMBRE_DE_MOTS);
    //Remplir les cases vides avec des nbr aleatoire
    Remplit_Tab_Random_lettre(grille);
    // Afficher la grille
    Affiche_Tab(grille);
   // BougeCurseur(&i, &j, direction,TailleTab);

   printf("*----------------------------------------*\n");
   printf("| 9 mots à rechercher dans la grille     |\n");
   printf("*----------------------------------------*\n");
   for(i = 0; i < 9; i++)
   {
       printf("-Bahamas       -chili\n");
   }
printf("%d", NB_MAX);

    return 0;
}

/*
int main() {
  printf("         *       *       *       *       *       *       *\n");
  printf("        * *     * *     * *     * *     * *     * *     *\n");
  printf("       *   *   *   *   *   *   *   *   *   *   *   *\n");
  printf("      * * * * * * * * * * * * * * * * * * * * * * * *\n");
  printf("     * J E U   D E   M O T S   M E L E S * \n");
  printf("      * * * * * * * * * * * * * * * * * * * * * * * *\n");
  printf("       *   *   *   *   *   *   *   *   *   *   *   *\n");
  printf("        * *     * *     * *     * *     * *     * *     *\n");
  printf("         *       *       *       *       *       *       *\n");

  return 0;
}
*/
