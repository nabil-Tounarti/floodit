#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define COULEUR 5
#define TAILLE 12
#include "jeux.h"


void initialiser(int tab[TAILLE][TAILLE])
{
    /* initialisation du tableau avec des couleurs aléatoires */
    srand(time(NULL));
    int r;
    for(int i = 0; i<TAILLE; i++)
    {
        for(int j=0; j<TAILLE; j++)
        {
            r = rand()%COULEUR;
            tab[i][j] = r;
        }
    }
}

void affichage(int tab[TAILLE][TAILLE])
{
    /* Affichage de chacune des cases de notre tableau de jeu */
    int i,j;
    for(i=0; i<TAILLE; i++)
    {   
        printf("|");
        for(j=0; j<TAILLE; j++)
        {
            printf(" %d |", tab[i][j]);
        }
        printf(" \n");
    }
}

int fin(int tab[TAILLE][TAILLE])
{
    /* Détermine si le jeu est terminé (toute les cases sont de la même couleur) */
    /* Retourne 1 si toutes les cases sont de même couleur, 0 sinon */
    int i, j;
    int couleur = tab[0][0];
    for(i=0; i<TAILLE; i++)
    {   
        for(j=0; j<TAILLE; j++)
        {
            if(tab[i][j] != couleur)
            {
                return 0;
            }
        }
    }
    return 1;
}





//Méthode recursive:

void remplir(int tab[TAILLE][TAILLE], int couleur_avant, int couleur_apres, int i, int j)
{
    //Fonction a appelé avec les coordonnées 0,0 pour faire la propagation de manière correcte.
    //Vérification des coordonnées:
    
    if(i<0 || i>=TAILLE || j<0 || j>=TAILLE )
    {
        printf("%d %d\n",tab[i][j],tab[0][0]);
        printf("Erreur coordonnées\n");
    }else{
        
        //On regarde TOUTES les cellules adjacentes dans les 4 directions.
        //Même si recursif, on ne passera jamais 2* dans la même case puisqu'elle aura changer de couleur
        tab[i][j] = couleur_apres;

        if(j+1<TAILLE)
        {
            //On regarde la couleur à droite
            if(tab[i][j+1] == couleur_avant)
            {
                //On propage à droite
                remplir(tab, couleur_avant, couleur_apres, i, j+1);
            }
        }

        if(j-1>=0)
        {
            //On regarde la couleur à gauche
            if(tab[i][j-1] == couleur_avant)
            {
                //On propage à gauche
                remplir(tab, couleur_avant, couleur_apres, i, j-1);
            }
        }

        if(i+1<TAILLE)
        {
            //On regarde la couleur en bas
            if(tab[i+1][j] == couleur_avant)
            {
                //On propage en bas
                remplir(tab, couleur_avant, couleur_apres, i+1, j);
            }
        }

        if(i-1>=0)
        {
            //On regarde la couleur en haut
            if(tab[i-1][j] == couleur_avant)
            {
                //On propage en haut
                remplir(tab, couleur_avant, couleur_apres, i-1, j);
            }
        }
    }
}

void afficher_sdl(int tab[TAILLE][TAILLE],SDL_Window   * window,SDL_Renderer *renderer) {
    
    SDL_Rect rect;
    /* couleur de fond */
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    for(int j=0;j<TAILLE;j++){
        for(int i=0;i<TAILLE;i++){

            /* dessiner en blanc */
            SDL_SetRenderDrawColor(renderer, (tab[j][i]-3)*40+i+j, (tab[j][i]-1)*40+i+j, (tab[j][i]-4)*40+i+j,(tab[j][i]-5)*40+i+j);
            rect.x = (1000/TAILLE)*i;
            rect.y = (1000/TAILLE)*j;
            rect.w = rect.h = 1000/TAILLE;
            SDL_RenderFillRect(renderer, &rect );
            /* afficher à l'ecran */
            SDL_RenderPresent(renderer);
            
        }
    }

    
    

}
void youwin(SDL_Window   * window,SDL_Renderer *renderer){
    printf("fffffffff");
    SDL_Surface *tmp = NULL; 
	SDL_Texture *texture = NULL;
	tmp = SDL_LoadBMP("youwin.bmp");
	
	texture = SDL_CreateTextureFromSurface(renderer, tmp);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);
    int p=1;
    SDL_Event event;
	while(p){
        if (SDL_PollEvent(&event)){                 
            switch(event.type){ 
                case SDL_QUIT : p=0;SDL_DestroyWindow(window); break;
                default: break;
            }
        }
    }
	SDL_FreeSurface(tmp); 

}
