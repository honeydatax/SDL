//g++ door.c  -o door -lSDL
#include <SDL/SDL.h>
#include "SDLs.h"
int main(int argc,char *argv[]){
	int n;
	int nn;
	SDL_Surface *sss;
	SDL_Event event;
	SDL_Init(SDL_INIT_VIDEO);
	atexit(SDL_Quit);
	sss=SDL_SetVideoMode(640,480,8,0);
	clears(sss,255,250,250);
	
	//circle(sss,320,240,50,0,0,0);
	

	for(n=60;n>3;n=n-6){
		ball(sss,320,240,n,255,n*4,n*4);
	}

	SDL_Flip(sss);
	SDL_WM_SetCaption("vline...",NULL);
	while(1){
		if(SDL_PollEvent(&event)){
			if(event.type==SDL_KEYDOWN){
				if(event.key.keysym.sym==SDLK_ESCAPE)break;

			}
			else if (event.type==SDL_QUIT){
				break;
				
			}
			
		}
	}
	return 0;
}