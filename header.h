
#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define LIG 10
#define COL 10
#define NBL  26
#define MAX_LEN_MOT 20
#define NOMBRE_DE_MOTS 7
#define NB_THEMES 5
#define NB_MIN 5
#define NB_MAX 20



// Liste des mots à trouver
const char *themes[NB_THEMES] = {
    "Animaux",
    "Pays",
    "Prenom",
    "Objets",
    "Sports"
};

void ChoisirTailleTab(int *nblignes, int *nbcolonnes);
char lettreAleatoire();
void placerMots(char grille[LIG][COL]);
void Remplit_Tab_Random_lettre(char tab[LIG][COL]);
void Affiche_Tab(char tab[LIG][COL]);
void initialiserTab( char Tab[LIG][COL]);
int peutPlacerMot(char tab[LIG][COL], const char* mot, int x, int y, int direction);
void placerMot(char tab[LIG][COL], const char* mot, int x, int y, int direction);
void placerMotsDansTab(char tab[LIG][COL], const char* mots[], int nombre_mots);
void BougeCurseur(int *x, int *y, char direction, int TailleTab);
#endif // HEADER_H

