#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "jeux.h"

int main() {
    int o=1;
    //Creat and open the window
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window   * window;
    window = SDL_CreateWindow("SDL2 Programme 0.1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 1000, SDL_WINDOW_RESIZABLE);
    
    SDL_Renderer *renderer; //Initialisation of the renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED ); //Creat the renderer

    //the game boucle
    while(o){

    
    //Creat the surface
    SDL_Surface *tmp = NULL; 
	SDL_Texture *texture = NULL;    //Creat the texture
	tmp = SDL_LoadBMP("start.bmp");  //télechargement de l'image 
	
    
    
	texture = SDL_CreateTextureFromSurface(renderer, tmp); //put the image on the texture
    
	SDL_RenderCopy(renderer, texture, NULL, NULL); //put the texture on the rendrer
    
	SDL_RenderPresent(renderer); // show the render on the window (scren)
    int p=1,e=1;
    SDL_Event event; // Creat  the variabele Event  
	while(e && p){
        if (SDL_PollEvent(&event)){                 
            switch(event.type){  // the cases of the events
                case SDL_MOUSEBUTTONDOWN : e=0;break; // if we click the right button
                case SDL_QUIT : p = 0;o=0;  break; // if we cilck the X button
                default: break;
            }
        }
    }
	

               
    
    
    int tab[TAILLE][TAILLE];
    int a,b;
    initialiser(tab);
    int z=0;

    while(!fin(tab) && p){
        
        afficher_sdl(tab,window,renderer); // show the game table on the window
        int t=1;
        while(t && p){
            if (SDL_PollEvent(&event)){                 
                switch(event.type){ // the cases of the event 
                    case SDL_MOUSEBUTTONDOWN : b=(int)event.button.x/(1000/TAILLE); a=(int) event.button.y/(1000/TAILLE);t=0; break;
                    case SDL_QUIT : p = 0;o=0; break;

                    default: break;
                }
            }
        }
        if(tab[a][b]!=tab[0][0])remplir(tab,tab[0][0],tab[a][b],a, b);
        
        z++;
        

    }

    if(z<=TAILLE*TAILLE/2 && fin(tab)){
        tmp = SDL_LoadBMP("youwin.bmp"); // downlod the image
	

	    texture = SDL_CreateTextureFromSurface(renderer, tmp); //put the image on the texture
	    SDL_RenderCopy(renderer, texture, NULL, NULL); // put the texture on the renderer 
	    SDL_RenderPresent(renderer); //show the renderer on the scren
        p=1;
        while(p){
            if(SDL_PollEvent(&event)){
                switch(event.type){
                    case SDL_MOUSEBUTTONDOWN : p=0;break;
                    case SDL_QUIT : p=0;o=0;SDL_DestroyWindow(window);break;
                    default : break;
                }
            }
        }
        

    }else{
        tmp = SDL_LoadBMP("youlose.bmp");
	

	    texture = SDL_CreateTextureFromSurface(renderer, tmp);
	    SDL_RenderCopy(renderer, texture, NULL, NULL);
	    SDL_RenderPresent(renderer);
        p=1;
        while(p){
            if(SDL_PollEvent(&event)){
                switch(event.type){
                    case SDL_MOUSEBUTTONDOWN : p=0;break;
                    case SDL_QUIT :p=0;o=0;SDL_DestroyWindow(window);break;
                    default : break;
                }
            }
        }
    }
    SDL_FreeSurface(tmp);

}

    
}