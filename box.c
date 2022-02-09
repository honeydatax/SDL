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
	short int *pixels=(short int*) sss->pixels;
	for(n=0;n<4;n++){
		box(sss,0,n*120,640,120,255,n*63,n*63);
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
