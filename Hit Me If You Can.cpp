#include <graphics.h>
#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <time.h>
using namespace std;

class main_circle{
public:
        virtual void show(int A,int B,int C,int D)
        {
            fillellipse(A,B,C,D);
        }
};
class Ycircle:public main_circle{
public:
       void show(int A,int B,int C,int D)
        {
            {
            setfillstyle(1,14);
            setcolor(YELLOW);
            fillellipse(A,B,C,D);
            }
        }
};
class Gcircle:public main_circle{
public:
       void show(int A,int B,int C,int D)
        {
            {
            setfillstyle(1,2);
            setcolor(GREEN);
            fillellipse(A,B,C,D);
            }
        }
};
int main()
{
    DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
    DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);
    initwindow(screenWidth, screenHeight, " ",-3,-3);

    POINT cursorPosition;

    int n,Z=50;
    int color=14;
    time_t t;

    char arr[100];
    char ch1;
    int W,mX,mY,i,j,miss=0,score=0;
    static int flag=1;
    int x = getmaxx();
    int y = getmaxy();
    int X = x/2;
    int Y = y-100;

    for(j=0; ;j++){
        while(flag==1){
            srand((unsigned) time(&t));
            W = (rand() % 2)+1;
            X = rand() % (x+100);
            Y = rand() % (y);
            Z = rand() % 10;
            if(W==1){
                Ycircle YC;
                {
                setfillstyle(1,14);
                setcolor(YELLOW);
                X=X+(3*Z);
                Y=Y+(2*Z);
                YC.show(X,Y,30,30);
                delay(2);
                }
                GetCursorPos(&cursorPosition);
                mX=cursorPosition.x;
                mY=cursorPosition.y;
                if(GetAsyncKeyState(VK_LBUTTON)){
                    if(getpixel(mX,mY)==color){
                        for(int x=0;x<6;x++){
                            for(int y=0;y<6;y++){
                                putpixel(mX+x,mY+y,YELLOW);
                            }
                        }
                    score++;
                    }
                    if(score==0){
                        outtextxy(100,100,"Game Over");
                        sprintf(arr,"%d",score);
                        outtextxy(100,120,arr);
                        getch();
                    }
                    else if(getpixel(mX,mY)!=color){
                        miss++;
                        for(int x=0;x<6;x++){
                            for(int y=0;y<6;y++){
                                putpixel(mX+x,mY+y,YELLOW);
                            }
                        }
                        if(miss>0){
                            outtextxy(100,100,"Game Over");
                            sprintf(arr,"%d",score);
                            outtextxy(100,120,arr);
                            flag=0;
                            getch();
                            DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
                            DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);
                            initwindow(screenWidth, screenHeight, " ",-3,-3);
                        }
                    }
                }
            delay(3);
            cleardevice();
          }
            else if(W==2){
                Gcircle GC;
                {
                setfillstyle(1,2);
                setcolor(GREEN);
                X=X+(3*Z);
                Y=Y+(2*Z);
                GC.show(X,Y,30,30);
                delay(2);
                }
                GetCursorPos(&cursorPosition);
                mX=cursorPosition.x;
                mY=cursorPosition.y;
                if(GetAsyncKeyState(VK_LBUTTON)){
                    if(getpixel(mX,mY)==color){
                        for(int x=0;x<6;x++){
                            for(int y=0;y<6;y++){
                                putpixel(mX+x,mY+y,YELLOW);
                            }
                        }
                    score++;
                    if(score==0){
                        outtextxy(100,100,"Game Over");
                        sprintf(arr,"%d",score);
                        outtextxy(100,120,arr);
                        getch();
                    }
                    }
                    else if(getpixel(mX,mY)!=color){
                        for(int x=0;x<6;x++){
                            for(int y=0;y<6;y++){
                                putpixel(mX+x,mY+y,YELLOW);
                            }
                        }
                        miss++;
                        if(miss>0){
                            outtextxy(100,100,"Game Over");
                            sprintf(arr,"%d",score);
                            outtextxy(100,120,arr);
                            flag=0;
                            getch();
                            DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
                            DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);
                            initwindow(screenWidth, screenHeight, " ",-3,-3);
                        }
                    }
                }
            delay(3);
            cleardevice();
        }
    }
      getch();
      closegraph();
      return 0;
   }
}
