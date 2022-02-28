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
	clears(sss,150,150,150);
	
	gputs(sss,20,20,0,0,0,"hello World...");
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
