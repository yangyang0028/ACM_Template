#include<bits/stdc++.h>
#include<windows.h>
#include <conio.h>
using namespace std;
#define maxn 5000000
struct node{
  short x,y;
}a[maxn];
int b[200][200];
#define X 55
#define Y 29
int cnt,ans,L;
void build(){
  short x,y;
    for(x=0;x<X;x++){
      y=0;
      COORD pos={x,y};
      b[x][y]=-1;
      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
      printf("#");
    }
    for(x=0;x<X;x++){
      y=Y;
      COORD pos={x,y};
      b[x][y]=-1;
      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
      printf("#");
    }
    for(y=0;y<Y;y++){
      x=0;
      COORD pos={x,y};
      b[x][y]=-1;
      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
      printf("#");
    }
    for(y=0;y<Y;y++){
      x=X;
      COORD pos={x,y};
      b[x][y]=-1;
      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
      printf("#");
    }
}
void init(){
    memset(b,0,sizeof b);
    cnt=1;
    ans=0;
    L=2;
    build();
}
void run(){
  short x=X/2,y=Y/2,dx=0,dy=0,cx=0,cy=0,sx=0,sy=0;
  char c;
  kbhit();
  c = getch();
  sx=(short)rand()%(X-3)+1;
  sy=(short)rand()%(Y-3)+1;
  while(b[sx][sy]!=0){
    sx=(short)rand()%(X-3)+1;
    sy=(short)rand()%(Y-3)+1;
  }
  COORD spos={sx,sy};
  b[sx][sy]=-2;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),spos);
  printf("$");
  while(1){
    switch(c){
      case 'w': dx = 0, dy = -1; break;
      case 's': dx = 0, dy = 1; break;
      case 'a': dx = -1, dy = 0; break;
      case 'd': dx = 1, dy = 0; break;
    }
    COORD pos={x=x+dx,y=y+dy};
    if(x==sx&&y==sy){
      b[(int)sx][(int)sy]=0;
      ans++;
      L++;
      sx=(short)rand()%(X-3)+1;
      sy=(short)rand()%(Y-3)+1;
      while(b[sx][sy]!=0){
        sx=(short)rand()%(X-3)+1;
        sy=(short)rand()%(Y-3)+1;
      }
      COORD spos={sx,sy};
      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),spos);
      printf("$");
    }
    if(b[x][y]==-1){
      //system("cls");
      COORD pos={X/2,Y/2};
      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x01|0x05);
      cout<<"Score is "<<ans<<endl;
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
      return ;
    }
    b[x][y]=-1;
    a[++cnt].x=x;
    a[cnt].y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
    printf("*");
    cx=a[cnt-L-1].x;
    cy=a[cnt-L-1].y;
    COORD cpos={cx,cy};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cpos);
    printf(" ");
    b[cx][cy]=0;
    Sleep(100);
    for(;kbhit();) c = getch();
  }
}
int main(){
  srand(time(NULL));
  init();
  run();
  return 0;
}
