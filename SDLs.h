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
void clears(SDL_Surface *surfaces,int b,int g,int r){
	box(surfaces,0,0,surfaces->w-1,surfaces->h-1,b,g,r);
}
void setPixel(SDL_Surface *surfaces,int x,int y,int b,int g,int r){
	char *pixels=(char *) surfaces->pixels;
	if(x<surfaces->w-1 && y<surfaces->h-1 && y>-1 && x>-1){
		pixels[y*surfaces->w+x]=(char)(b/85)|((g/85)<<3)|((r/85)<<5);
	}

}
void lineR(SDL_Surface *surfaces, int x,int y,int x2,int y2,char bc,char g,char r){
long l1=0,l2=0,l3=0,l4=0,l5=0;
	int i4=0;
	int xx=x;
	int yy=y;
	int xxx=x2;
	int yyy=y2;
	int c=0;
	int c2=0;
	if (xx>xxx){
		i4=xxx;
		xxx=xx;
		xx=i4;
	}
	if (yy>yyy){
		i4=yyy;
		yyy=yy;
		yy=i4;
	}

	int i1=xxx-xx;
	int i2=yyy-yy;
	int i3;
	int i5;
	int i6;
	int i8;
	int b=0;
	int ty=0;
	if (i1>i2){
		l1=(long)i1;
		l2=(long)i2;
		if(l1==0){
			l1=1;
		}
		l4=(l2*10000/l1);
		l3=0;
		i6=0;
		c=0;
		c2=0;
		for(i5=0;i5<i1+1;i5++){
			l5=l3/10000;
			i3=(int)l5;
			setPixel(surfaces,xx+i5,y+(i3),bc,g,r);
			l3=l3+l4;
		}
	}else{
		l1=(long)i1;
		l2=(long)i2;
		if(l2==0){
			l2=1;
		}
		l4=(l1*10000/l2);
		l3=0;
		i6=0;
		c=0;
		c2=0;
		for(i5=0;i5<i2+1;i5++){
		l5=l3/10000;
		i3=(int)l5;
		setPixel(surfaces,xx+i3,y+(i5),bc,g,r);
		l3=l3+l4;
	
		} 
	}
}

void lineL(SDL_Surface *surfaces,int x,int y,int x2,int y2,char bc,char g,char r){
	long l1=0,l2=0,l3=0,l4=0,l5=0;
	int i4=0;
	int xx=x;
	int yy=y;
	int xxx=x2;
	int yyy=y2;
	int c=0;
	int c2=0;
	if (xx>xxx){
		i4=xxx;
		xxx=xx;
		xx=i4;
	}
	if (yy<yyy){
		i4=yyy;
		yyy=yy;
		yy=i4;
	}

	int i1=xxx-xx;
	int i2=yy-yyy;
	int i3;
	int i5;
	int i6;
	int i8;
	int b=0;
	int ty=0;
	if (i1>i2){
		l1=(long)i1;
		l2=(long)i2;
		if(l1==0){
			l1=1;
		}
		
		l4=(l2*10000/l1);
		l3=0;
		i6=0;
		c=0;
		c2=0;
		for(i5=0;i5<i1+1;i5++){
			l5=l3/10000;
			i3=(int)l5;
			setPixel(surfaces,xx+i5,y-(i3),bc,g,r);
			l3=l3+l4;
		}
	}else{
		l1=(long)i1;
		l2=(long)i2;
		if(l2==0){
			l2=1;
		}
		l4=(l1*10000/l2);
		l3=0;
		i6=0;
		c=0;
		c2=0;
		for(i5=0;i5<i2+1;i5++){
			l5=l3/10000;
			i3=(int)l5;
			setPixel(surfaces,xx+i3,yy-i5,bc,g,r);
			l3=l3+l4;
		}
	} 
}

void line(SDL_Surface *surfaces,int x,int y,int x2,int y2,char b,char g,char r){
	int i=-1;
	if(x>x2 && y<y2)i=5;
	if(x>x2 && y>y2)i=4;
	if(x<x2 && y<y2)i=3;
	if(x<x2 && y>y2)i=2;
	if(y==y2)i=0;
	if(x==x2)i=1;
	if (i==0)hline(surfaces,x,y,x2,b,g,r);
	if (i==1)vline(surfaces,x,y,y2,b,g,r);
	if (i==2)lineL(surfaces,x,y,x2,y2,b,g,r);
	if (i==3)lineR(surfaces,x,y,x2,y2,b,g,r);
	if (i==4)lineR(surfaces,x2,y2,x,y,b,g,r);
	if (i==5)lineL(surfaces,x2,y2,x,y,b,g,r);
}
void circle(SDL_Surface *surfaces,int xx,int yy ,int rr,char bcc,char gcc,char rcc){
	long double rrr=(long double)rr,dx=(long double)xx,dy=(long double)yy,ddddd=0.0,d1=0.0,dd1=0,d=0.0,dd=0.0,ddd=0.0,pi=(long double)PI;
	long double xyr=rrr*2;
	int x=1,y=1,bc=0,c=7,x1=0,y1=0;
	long double rrr1=rrr*2;
	long double rrr2=xyr/2;
	for (ddd=0.0;ddd<xyr+1.0;ddd=ddd+1.0){
		dd=dy-rrr1*(cos)(ddd/rrr2*pi);
		d=dx+rrr1*(sin)(ddd/rrr2*pi);
		ddddd=ddd+1.0;
		if (ddddd>xyr + 1.0)ddddd=0;
		dd1=dy-rrr1*(cos)(ddddd/rrr2*pi);
		d1=dx+rrr1*(sin)(ddddd/rrr2*pi);
		bc=(int)ddd;
		x=(int)d;
		y=(int)dd;
		x1=(int)d1;
		y1=(int)dd1;
		line(surfaces,x,y,x1,y1,bcc,gcc,rcc);
	}

}
