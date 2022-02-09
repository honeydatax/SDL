#include <SDL/SDL.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FONTDATAMAX 2048
#define PI 3.1415927
void vline(	SDL_Surface *surfaces,int x,int y,int y2,int b,int g,int r){
	int xx=x;
	int yy=y;
	int count1=1;
	int nexts1=1;
	char *pixels=(char *) surfaces->pixels;
	if(xx<0)xx=0;
	if(yy<0)yy=0;
	if(xx>=surfaces->w)xx=surfaces->w-1;
	if(yy>=surfaces->h)yy=surfaces->h-1;
	count1=y2-yy;
	if (count1+yy>=surfaces->h)count1=surfaces->h-1-yy;
	for(nexts1=yy;nexts1<count1+yy;nexts1++){
		pixels[nexts1*surfaces->w+xx]=(char)(b/85)|((g/85)<<3)|((r/85)<<5);
	}

}
void hline(	SDL_Surface *surfaces,int x,int y,int x2,int b,int g,int r){
	int xx=x;
	int yy=y;
	int count1=1;
	int nexts1=1;
	char *pixels=(char *) surfaces->pixels;
	if(xx<0)xx=0;
	if(yy<0)yy=0;
	if(xx>=surfaces->w)xx=surfaces->w-1;
	if(yy>=surfaces->h)yy=surfaces->h-1;
	count1=x2-xx;
	if (count1+xx>=surfaces->w)count1=surfaces->w-1-xx;
	for(nexts1=xx;nexts1<count1+xx;nexts1++){
		pixels[yy*surfaces->w+nexts1]=(char)(b/85)|((g/85)<<3)|((r/85)<<5);
	}

}
void box(SDL_Surface *surfaces,int x,int y,int x2,int y2,int b,int g,int r){
	int xx=x;
	int yy=y;
	int count1=1;
	int count2=1;
	int nexts1=1;
	int nexts2=1;
	char *pixels=(char *) surfaces->pixels;
	if(xx<0)xx=0;
	if(yy<0)yy=0;
	if(xx>=surfaces->w)xx=surfaces->w-1;
	if(yy>=surfaces->h)yy=surfaces->h-1;
	count1=x2;
	count2=y2;
	if (count1+xx>=surfaces->w)count1=surfaces->w-1-xx;
	if (count2+yy>=surfaces->h)count2=surfaces->h-1-yy;
	for(nexts2=yy;nexts2<count2+yy;nexts2++){
		for(nexts1=xx;nexts1<count1+xx;nexts1++){
			pixels[nexts2*surfaces->w+nexts1]=(char)(b/85)|((g/85)<<3)|((r/85)<<5);
		}
		
	}

}
