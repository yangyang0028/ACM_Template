#include<bits/stdc++.h>
#include<windows.h>
#include <conio.h>
using namespace std;
#define INF 0x3f3f
#define maxn 5000000
struct node{
  short x,y;
}a[maxn],u,v;
stack <node> st;
queue <node> q;
int b[200][200];
int mp[200][200];
#define X 55
#define Y 29
int cnt,ans,L;
short bx,by,ex,ey;
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
void init_mp(){
  short x,y;
  for(int i=0;i<X;i++){
    for(int j=0;j<Y;j++){
      if(b[i][j]==-1) mp[i][j]=INF;
      else mp[i][j]=0;
    }
  }
}
void bfs(){
  q.push((node){bx,by});
  while(!q.empty()){
    u=q.front(),v;
    q.pop();
    //cout<<u.x<<"  "<<u.y<<endl;
    if(u.x-1>0&&mp[u.x-1][u.y]==0){
      mp[u.x-1][u.y]=mp[u.x][u.y]+1;
      v.x=u.x-1;
      v.y=u.y;
      q.push(v);
    }
    if(u.x+1<X&&mp[u.x+1][u.y]==0){
      mp[u.x+1][u.y]=mp[u.x][u.y]+1;
      v.x=u.x+1;
      v.y=u.y;
      q.push(v);
    }
    if(u.y-1>0&&mp[u.x][u.y-1]==0){
      mp[u.x][u.y-1]=mp[u.x][u.y]+1;
      v.x=u.x;
      v.y=u.y-1;
      q.push(v);
    }
    if(u.y+1<Y&&mp[u.x][u.y+1]==0){
      mp[u.x][u.y+1]=mp[u.x][u.y]+1;
      v.x=u.x;
      v.y=u.y+1;
      q.push(v);
    }
  }
}
bool dfs(int x,int y){
  v.x=x;
  v.y=y;
    st.push(v);
  if(x==bx&&y==by) return true;
  if(x-1>0&&mp[x-1][y]+1==mp[x][y]){
    if(dfs(x-1,y)){
      return true;
    }
  }
  if(x+1<X&&mp[x+1][y]+1==mp[x][y]){
    v.x=x+1;
    v.y=y;
    if(dfs(x+1,y)){
      return true;
    }
  }
  if(y-1>0&&mp[x][y-1]+1==mp[x][y]){
    v.x=x;
    v.y=y-1;
    if(dfs(x,y-1)){
      return true;
    }
  }
  if(y+1<X&&mp[x][y+1]+1==mp[x][y]){
    v.x=x;
    v.y=y+1;
    if(dfs(x,y+1)){
      return true;
    }
  }
}
bool solve(){
  init_mp();
  mp[bx][by]=1;
  bfs();
  if(mp[ex][ey]==0) return false;
  dfs(ex,ey);
  return true;
}
void run(){
  short x=X/2,y=Y/2,dx=0,dy=0,cx=0,cy=0,sx=0,sy=0;
  while(1){
    if(cnt>4500000) cnt=0;
    bx=x;
    by=y;
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
    ex=sx;
    ey=sy;
    ans++;
    if(!solve()){
      COORD pos={X+2,Y/2};
      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x01|0x05);
      cout<<"Score is "<<ans<<endl;
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
      return ;
    }
    while(!st.empty()){
      Sleep(20);
      u=st.top();
      st.pop();
      COORD pos={u.x, u.y};
      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
      printf("*");
      a[++cnt]=u;
      b[u.x][u.y]=-1;
      cx=a[cnt-L-1].x;
      cy=a[cnt-L-1].y;
      b[cx][cy]=0;
      COORD cpos={cx,cy};
      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cpos);
      printf(" ");
    }
    L++;
    x=ex;
    y=ey;
  }
}
int main(){
  int i=10;
  while(i--){
    srand(time(NULL));
    init();
    solve();
    run();
    Sleep(3000);
    system("cls");
  }
  return 0;
}
