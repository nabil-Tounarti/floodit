#ifndef HEADER_FILE
#define HEADER_FILE
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#define COULEUR 5
#define TAILLE 12
#include "jeux.h"


void initialiser(int tab[TAILLE][TAILLE]);
void affichage(int tab[TAILLE][TAILLE]);
int fin(int tab[TAILLE][TAILLE]);
void remplir(int tab[TAILLE][TAILLE], int couleur_avant, int couleur_apres, int i, int j);
void afficher_sdl(int tab[TAILLE][TAILLE], SDL_Window   * window ,SDL_Renderer *renderer);
void youwin(SDL_Window   * window,SDL_Renderer *renderer);

#endif