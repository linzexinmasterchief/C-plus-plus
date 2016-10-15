#include <stdlib.h> 
#include<windows.h>     
#include <time.h>
#include<conio.h>
#include <iostream> 
#include <mmsystem.h> 
#include "SDL\SDL_image.h"
#include "SDL\SDL_ttf.h"
#include "SDL\SDL.h"
using namespace std;
#pragma comment(lib, "winmm.lib") 
#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"") 
 int iii=0;
 int score =0;
 int y=0;
 int posi[3][2]= {{640,-300},{940,-300},{1240,-300}};
int i=0,n=3;
SDL_Color textColor_1 = { 37, 134, 108 };
SDL_Color textColor_2 = { 255, 255, 255 };
SDL_Color textColor_3 = { 0, 88, 132 };
class Event
{
public:
    SDL_Event event;
    Uint8 *keystates;
    Event()
    {
        keystates=SDL_GetKeyState( NULL );
    }
 
 
};
Event thing;
class Data
{
public:
    int bird_y;
    int score;
    int posi[20][2];
    SDL_Rect bird_1;
    SDL_Rect bird_2;
    SDL_Rect bg;
    SDL_Rect welcome;
    SDL_Rect pipe_up;
    SDL_Rect pipe_down;
    SDL_Rect bird_cls;
    SDL_Rect foot;
 
    SDL_Surface* load_imag(char *s)
    {
        SDL_Surface* temp;
        temp=IMG_Load(s);
 
        bg.x=0;
        bg.y=0;
        bg.w=640;
        bg.h=480;
 
        welcome.x=681;
        welcome.y=0;
        welcome.w=640;
        welcome.h=480;
 
        bird_1.x=17;
        bird_1.y=508;
        bird_1.w=52;
        bird_1.h=34;
 
        bird_2.x=461;
        bird_2.y=531;
        bird_2.w=52;
        bird_2.h=33;
 
        bird_cls.w=52;
        bird_cls.h=33;
        bird_cls.x=0;
        bird_cls.y=0;
         
        pipe_up.x=1361;
        pipe_up.y=11;
        pipe_up.w=103;
        pipe_up.h=410;
 
        pipe_down.x=1487;
        pipe_down.y=14;
        pipe_down.w=103;
        pipe_down.h=443;
 
        foot.x=0;
        foot.y=404;
        foot.w=640;
        foot.h=80;
        
        return temp;
    }
 
    TTF_Font* load_font()
    {
        SDL_Init( SDL_INIT_EVERYTHING );
        TTF_Init();
        return TTF_OpenFont( "main_1.dat", 36 );
 
    }
};
 
Data data;
 
class Pri
{
 
public:
    SDL_Surface* out;
    SDL_Surface* main ;
    TTF_Font *font;
    SDL_Rect a;
    SDL_Surface*bird;
    SDL_Rect xy;
    SDL_Surface*font_1;
    SDL_Surface*font_2;
    SDL_Surface*font_11;
    SDL_Surface*font_22;
 
 
    Pri()
    {
            TTF_Font *font = NULL;
            init();
         
    }
 
    int init()
    {
        SDL_Init( SDL_INIT_EVERYTHING );
        TTF_Init();
        main= SDL_SetVideoMode( 640, 478, 32, SDL_SWSURFACE );
        SDL_WM_SetCaption("Flappy bird",NULL);
        font=data.load_font();
        out=data.load_imag("main_2.dat");
        y=150;
     
        posi[0][0]=640;
        posi[0][1]=-300;
        posi[1][0]=940;
        posi[1][1]=-300;
        posi[2][0]=1240;
        posi[2][1]=-300;
        return 1;
    }
 
    int pipe()
    {
 
    }
 
    int bir(int y)//x=150
    {int ii;
    i+=1;
    xy.x=150;
    xy.y=y;
    if(i<14)
     
        {
            xy.x=150;
            xy.y=y;
            SDL_BlitSurface(out,&data.bg,main,NULL);
 
             
            for(ii=0;ii<n;ii++)
            {
                xy.x=posi[ii][0];
                xy.y=posi[ii][1];
                SDL_BlitSurface(out,&data.pipe_down,main,&xy);
                xy.x=posi[ii][0];
                xy.y=posi[ii][1]+600;
                SDL_BlitSurface(out,&data.pipe_up,main,&xy);
 
            }
 
 
 
 
 
            xy.x=150;
            xy.y=y;
            SDL_BlitSurface(out,&data.bird_1,main,&xy);
        xy.x=0;
            xy.y=404;
            SDL_BlitSurface(out,&data.foot,main,&xy);
     
        }
     
         
    else
        {
            xy.x=150;
            xy.y=y;
            SDL_BlitSurface(out,&data.bg,main,NULL);
            for(ii=0;ii<n;ii++)
            {
                xy.x=posi[ii][0];
                xy.y=posi[ii][1];
                SDL_BlitSurface(out,&data.pipe_down,main,&xy);
 
                xy.x=posi[ii][0];
                xy.y=posi[ii][1]+600;
                SDL_BlitSurface(out,&data.pipe_up,main,&xy);
 
            }
 
            xy.x=150;
            xy.y=y;
            SDL_BlitSurface(out,&data.bird_2,main,&xy);
            xy.x=0;
            xy.y=404;
            SDL_BlitSurface(out,&data.foot,main,&xy);
            if(i>28)i=0;
        }
        return 0;
         
 
    }
 
    int bg()
    {
            SDL_BlitSurface(out,&data.bg,main,&xy);
             
            return 0;
    }
 
    int over()
    {
        int x=0,y=0,i=0;
 
        xy.x=250;
        xy.y=150;
        font_1=TTF_RenderText_Solid( font, "Game over !", textColor_3);
        SDL_BlitSurface( font_1 , NULL, main, &xy);
 
        SDL_Flip(main);
 
        xy.x=350;
        xy.y=200;
        font_1=TTF_RenderText_Solid( font, "Retry game", textColor_1 );
        font_11=TTF_RenderText_Solid( font, "Retry game", textColor_2 );
        SDL_BlitSurface( font_1 , NULL, main, &xy); 
         
 
        xy.x=350;
        xy.y=280;
 
        font_2=TTF_RenderText_Solid( font, " Exit game", textColor_1 );
        font_22=TTF_RenderText_Solid( font, " Exit game", textColor_2 );
        SDL_BlitSurface( font_2 , NULL, main, &xy); 

        while(SDL_PollEvent( &thing.event ), 1)
        {
            i+=2;
            Sleep(1);
            if( thing.keystates[ SDLK_ESCAPE] )exit(0);
            if( thing.event.type == SDL_QUIT )
            {
                exit(0);
            } 
 
 
            if((x>350&&x<540)&&(y<240)&&(y>200))
            {
                if(thing. event.type == SDL_MOUSEBUTTONDOWN)
                    if(thing.event.button.button== SDL_BUTTON_LEFT )
                    {
                        SDL_FreeSurface(font_1);
                        SDL_FreeSurface(font_11);
                        SDL_FreeSurface(font_22);
                        SDL_FreeSurface(font_2);
                    WinExec("Flappy bird.exe",NULL);
                    exit(0);
                        return 11;
                    }
 
 
            }
            else
            {
 
 
            }
 
 
 
            if((x>350&&x<540)&&(y<320)&&(y>280))
            {
                if(thing. event.type == SDL_MOUSEBUTTONDOWN)
                    if(thing.event.button.button== SDL_BUTTON_LEFT )exit(0);
 
            }
 
 
            if(thing. event.type == SDL_MOUSEMOTION )
            {
                x=thing.event.motion.x;
                y=thing.event.motion.y;
 
                if((thing.event.motion.x>350&&thing.event .motion .x<540)&&(thing.event.motion.y<240)&&(thing.event.motion.y>200))
                {
                    xy.x=350;
                    xy.y=200;
                    SDL_BlitSurface( font_11, NULL, main, &xy); 
                    SDL_Flip(main);
                }
                else
                {
                    xy.x=350;
                    xy.y=200;
                    SDL_BlitSurface( font_1 , NULL, main, &xy); 
                    SDL_Flip(main);
                }
 
 
 
                if((thing.event.motion.x>350&&thing.event .motion .x<540)&&(thing.event.motion.y<320)&&(thing.event.motion.y>280))
                {
                    xy.x=350;
                    xy.y=280;
                    SDL_BlitSurface( font_22 , NULL, main, &xy); 
                    SDL_Flip(main);
 
 
                }
                else
                {
                    xy.x=350;
                    xy.y=280;
                    SDL_BlitSurface( font_2 , NULL, main, &xy); 
                    SDL_Flip(main);
                }
            }
 
 
 
        }
        return 0;
    }
 
    int welcome()
    {       
 
        int x=0,y=0,i=0;
 
 
        SDL_BlitSurface(out,&data.welcome,main,NULL);
        bird=out;
        xy.x=350;
        xy.y=200;
        font_1=TTF_RenderText_Solid( font, "Start game", textColor_1 );
        font_11=TTF_RenderText_Solid( font, "Start game", textColor_2 );
        SDL_BlitSurface( font_1 , NULL, main, &xy); 
 
        xy.x=350;
        xy.y=280;
 
        font_2=TTF_RenderText_Solid( font, " Exit game", textColor_1 );
        font_22=TTF_RenderText_Solid( font, " Exit game", textColor_2 );
        SDL_BlitSurface( font_2 , NULL, main, &xy); 
 
        xy.x=10;
        xy.y=440;
        SDL_BlitSurface( TTF_RenderText_Solid( font, "Esc:exit game   Space:to jump  hekun ", textColor_1 ) , NULL, main, &xy); 
        SDL_Flip( main );
         
 
        while(SDL_PollEvent( &thing.event ), 1)
        {
            i+=2;
            Sleep(1);
            if( thing.keystates[ SDLK_ESCAPE] )exit(0);
            if( thing.event.type == SDL_QUIT )
            {
                exit(0);
            } 
 
 
            if((x>350&&x<540)&&(y<240)&&(y>200))
            {
                if(thing. event.type == SDL_MOUSEBUTTONDOWN)
                    if(thing.event.button.button== SDL_BUTTON_LEFT )
                    {
                        SDL_FreeSurface(font_1);
                        SDL_FreeSurface(font_11);
                        SDL_FreeSurface(font_22);
                        SDL_FreeSurface(font_2);
                        return 0;
                    }
         
             
            }
            else
            {
                 
             
            }
 
 
 
            if((x>350&&x<540)&&(y<320)&&(y>280))
            {
                if(thing. event.type == SDL_MOUSEBUTTONDOWN)
                    if(thing.event.button.button== SDL_BUTTON_LEFT )exit(0);
 
            }
         
 
            if(thing. event.type == SDL_MOUSEMOTION )
            {
                x=thing.event.motion.x;
                y=thing.event.motion.y;
 
                if((thing.event.motion.x>350&&thing.event .motion .x<540)&&(thing.event.motion.y<240)&&(thing.event.motion.y>200))
                {
                    xy.x=350;
                    xy.y=200;
                    SDL_BlitSurface( font_11, NULL, main, &xy); 
                    SDL_Flip(main);
                }
                else
                {
                    xy.x=350;
                    xy.y=200;
                    SDL_BlitSurface( font_1 , NULL, main, &xy); 
                    SDL_Flip(main);
                }
 
 
 
                 if((thing.event.motion.x>350&&thing.event .motion .x<540)&&(thing.event.motion.y<320)&&(thing.event.motion.y>280))
                {
                    xy.x=350;
                    xy.y=280;
                    SDL_BlitSurface( font_22 , NULL, main, &xy); 
                    SDL_Flip(main);
             
 
                }
                else
                {
                    xy.x=350;
                    xy.y=280;
                    SDL_BlitSurface( font_2 , NULL, main, &xy); 
                    SDL_Flip(main);
                }
            }
             
 
            if(i==400)
            {
                xy.x=150;
                xy.y=250;
                SDL_BlitSurface(bird,&data.bird_1,main,&xy);
                SDL_Flip(main);
            }
 
 
         
            if(i==800)
            {
                xy.x=150;
                xy.y=250;
                SDL_BlitSurface(bird,&data.bird_2,main,&xy);
                i=0;
                SDL_Flip(main);
            }
 
 
        }
        return 0;
     
    }
 
 
 
};
 
Pri pri;
 
 
 
int game_judge()
{int i=0;
    if(y>370||y<-10)
    {
        if(pri.over()==11)return 12;
 
    }
 
    for(i=0;i<3;i++)
    {
        if(posi[i][0]<202 &&posi[i][0]>50)
        {
            if(y<posi[i][1]+ 420 ||y>posi[i][1]+570)
            {if(pri.over()==11)return 12;}
        }
 
    }
 
 
    return 0;
}
 
 
 
int game_loop()
{ y=150,i=0;
    int ii=0,iii=0;
    SDL_Surface *font;
    pri.bg();
 
    char s[50];
    Uint32 start = 0;
    sprintf(s," FPS:%d\t\t\t\t\t\t\t\tScore:%d",1000/(SDL_GetTicks()-start),score);
 
    int q=0;
while(SDL_PollEvent( &thing.event ), 1)
{
 
    start = SDL_GetTicks();
    i++;
    Sleep(1);
    SDL_Flip(pri.main);
    y+=4;
    if(y>430)y=100;
 
    if(thing.event.button.state==SDL_PRESSED)y-=20;
    if( thing.keystates[ SDLK_SPACE] )y-=20;
    if( thing.keystates[ SDLK_ESCAPE] )exit(0);
    if( thing.event.type == SDL_QUIT )
    {
        exit(0);
    } 
     
    if(game_judge()==12)return 0;
 
        pri.bir(y);
     
        ii++;
        if(ii>20)    
        {
            sprintf(s," FPS:%d\t\t\t\t\t\t\t\tScore:%d",1000/(SDL_GetTicks()-start)+rand()%5,score);
            ii=0;
        }
         
             
            font=TTF_RenderText_Solid( pri.font, s, textColor_2 );
            SDL_BlitSurface(font , NULL,pri. main, NULL); 
            SDL_Flip(pri.main);
            SDL_FreeSurface(font);
 
            posi[0][0]-=2;
            posi[1][0]-=2;
            posi[2][0]-=2;
 
            if(posi[0][0]<=(-110))
            {posi[0][0]=posi[2][0]+300;posi[0][1]=-(rand()%180)-220;}
     
            if(posi[1][0]<=(-110))
            {posi[1][0]=posi[0][0]+300;posi[1][1]=-(rand()%180)-220;}
 
 
            if(posi[2][0]<=(-110))
            {posi[2][0]=posi[1][0]+300;posi[2][1]=-(rand()%180)-220;}
             
 
         
            iii++;
            if(iii>50)
 
            for(iii=0;iii<3;iii++)
            {
                if(posi[iii][0]<50);
                score++;
                iii=0;
                break;
            }
 
}
 
    return 0;
 
}
 
int main(int argc, char* argv[])
{
     
    while(1)
    {
     
        pri.init();
        pri.welcome();
        game_loop();
     
    }
    return 0;
}
  
