#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <windows.h>
#include "header.h"


#define LIG 10
#define COL 10
#define NBL  26
#define MAX_LEN_MOT 20
#define NOMBRE_DE_MOTS 7
#define NB_THEMES 5
#define NB_MIN 5
#define NB_MAX 20


void setColor(int background, int text) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, background * 16 + text);
}

//Procedure pour demander a l'utilisateur DE CHOISIR la taille de la grille,
void ChoisirTailleTab(int *nblignes, int *nbcolonnes)
{
    do {
        printf("\nVeuillez choisir la taille de votre grille de jeu :  \n");
        printf("Entrer le nombre de ligne (entre %d et %d)  : ",NB_MIN, NB_MAX);
        scanf("%d", nblignes);
    }while(*nblignes < NB_MIN || *nblignes > NB_MAX);

      do {
        printf("Entrer le nombre de colonne  (entre %d et %d)  : ",NB_MIN, NB_MAX);
        scanf("%d", nbcolonnes);
    }while(*nbcolonnes < NB_MIN || *nbcolonnes > NB_MAX);
    printf("** Grille de %d lignes par %d colonnes choisie. **\n", *nblignes, *nbcolonnes);
}


char lettreAleatoire() {
    return 'A' + rand() % NBL;
}
//Remplir le tab avec des lettres aleatoires
void Remplit_Tab_Random_lettre(char tab[LIG][COL])
{
    int i,j;
    for(i = 0; i < LIG; i++)
    {
        for(j = 0; j < COL; j++)
            {
                if(tab[i][j] == ' ')
                {
                    tab[i][j] = tolower(lettreAleatoire());
                }
            }
    }
}

void Affiche_Tab(char tab[LIG][COL]) {
    int i, j;
    for(i = 0; i < LIG; i++) {
        for(j = 0; j < COL; j++) {
            if((i + j) % 2 == 0) {
                setColor(15, 0); // Fond gris avec texte noir
            } else {
                setColor(14, 0); // Fond jaune avec texte noir
            }
            printf(" %c ", tab[i][j]);
            setColor(0, 7); // R initialiser les couleurs   fond noir avec texte blanc
        }
        printf("\n");
    }
}

int nbAleatoire(int min, int max)

{
    return min + rand() % (max - min + 1);


}


void initialiserTab( char Tab[LIG][COL])
{
    int i,j;
    for(i = 0; i < LIG; i++)
    {
        for(j = 0; j < COL; j++)
        {
            Tab[i][j] = ' ';
        }
    }
}


int peutPlacerMot(char tab[LIG][COL], const char* mot, int x, int y, int direction) {
    int len = strlen(mot);
    int i;

    switch (direction) {
        case 0: // de gauche   droite
            if (y + len > COL) return 0;
            for (i = 0; i < len; i++) {
                if (tab[x][y + i] != ' ' && tab[x][y + i] != mot[i]) return 0;
            }
            break;
        case 1: // de droite   gauche
            if (y - len < -1) return 0;
            for (i = 0; i < len; i++) {
                if (tab[x][y - i] != ' ' && tab[x][y - i] != mot[i]) return 0;
            }
            break;
        case 2: // de haut en bas
            if (x + len > LIG) return 0;
            for (i = 0; i < len; i++) {
                if (tab[x + i][y] != ' ' && tab[x + i][y] != mot[i]) return 0;
            }
            break;
        case 3: // de bas en haut
            if (x - len < -1) return 0;
            for (i = 0; i < len; i++) {
                if (tab[x - i][y] != ' ' && tab[x - i][y] != mot[i]) return 0;
            }
            break;
    }
    return 1;
}

void placerMot(char tab[LIG][COL], const char* mot, int x, int y, int direction)
{
    int len = strlen(mot);
    int i;

    switch (direction) {
        case 0: // de gauche   droite
            for (i = 0; i < len; i++) {
                tab[x][y + i] = mot[i];
            }
            break;
        case 1: // de droite   gauche
            for (i = 0; i < len; i++) {
                tab[x][y - i] = mot[i];
            }
            break;
        case 2: // de haut en bas
            for (i = 0; i < len; i++) {
                tab[x + i][y] = mot[i];
            }
            break;
        case 3: // de bas en haut
            for (i = 0; i < len; i++) {
                tab[x - i][y] = mot[i];
            }
            break;
    }
}

void placerMotsDansTab(char tab[LIG][COL], const char* mots[], int nombre_mots)
{
    int i, x, y, direction;

    for (i = 0; i < nombre_mots; i++) {
        int place = 0;
        while (!place) {
            x = rand() % LIG;
            y = rand() % COL;
            direction = rand() % 4;
            if (peutPlacerMot(tab, mots[i], x, y, direction)) {
                placerMot(tab, mots[i], x, y, direction);
                place = 1;
            }
        }
    }
}

//fonction pour se deplacer dans le jeux

void BougeCurseur(int *x, int *y, char direction, int TailleTab)
{
    switch(direction)
    {
    case '2': //bas
        if(*x < TailleTab - 1) (*x)++;
        break;
    case '4': //gauche
        if(*y > 0) (*y)--;
        break;
    case '6':
        if(*y < TailleTab - 1) (*y)++;
        break;
    case '8':
        if(*x > 0) (*x)--;
        break;
    default:
        break;
    }
}



/*void BougeCurseur(int *x, int *y, char direction, int TailleTab) {
    int newX = *x, newY = *y;  // Create temporary variables to avoid modifying originals within conditions

    switch (direction) {
        case '2':  // Down
            if (newX < TailleTab - 1) {
                newX++;
            } else {
                // Handle edge case (optional):
                // printf("Error: Cursor already at bottom edge\n");
                // return -1;  // Or return an error code
            }
            break;
        case '4':  // Left
            if (newY > 0) {
                newY--;
            } else {
                // Handle edge case (optional)
            }
            break;
        case '6':  // Right
            if (newY < TailleTab - 1) {
                newY++;
            } else {
                // Handle edge case (optional)
            }
            break;
        case '8':  // Up
            if (newX >  0) {
                newX--;
            } else {
                // Handle edge case (optional)
            }
            break;
        default:
            break;
    }

    *x = newX;  // Update original values only after successful validation
    *y = newY;

    return 0;  // Return success (optional)
}

*/








