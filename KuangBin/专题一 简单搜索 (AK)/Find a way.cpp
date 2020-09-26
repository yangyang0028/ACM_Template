#include <bits/stdc++.h>
using namespace std;
int n,m;
char mp[210][210];
int mp_num[210][210];
int KFC[210][210];
struct node{
  int x;
  int y;
};
int init(){
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
    if(mp[i][j]=='#') mp_num[i][j]=-1;
    else mp_num[i][j]=0;
    }
  }
}
int init_KFC(){
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(mp[i][j]=='@'&&mp_num[i][j]==0){
        KFC[i][j]=0x3f3f3f;
      }
      else if(mp[i][j]=='@'){
        KFC[i][j]+=mp_num[i][j];
      }
    }
  }
}
void print(){
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      printf("%d ", mp_num[i][j]);
      if(j==m-1) printf("\n");
    }
  }
}
queue<node> q;
void bfs(int x,int y){
  node a,b;
  a.x=x,a.y=y;
  mp_num[x][y]=1;
  q.push(a);
  while(!q.empty()){
    a=q.front();
    q.pop();
    if(a.x-1>=0 &&mp_num[a.x-1][a.y]==0){
      mp_num[a.x-1][a.y]=mp_num[a.x][a.y]+1;
      b.x=a.x-1,b.y=a.y;
      q.push(b);
    }
    if(a.y-1>=0 &&mp_num[a.x][a.y-1]==0){
      mp_num[a.x][a.y-1]=mp_num[a.x][a.y]+1;
      b.x=a.x,b.y=a.y-1;
      q.push(b);
    }
    if(a.x+1<n &&mp_num[a.x+1][a.y]==0){
      mp_num[a.x+1][a.y]=mp_num[a.x][a.y]+1;
      b.x=a.x+1,b.y=a.y;
      q.push(b);
    }
    if(a.y+1<m &&mp_num[a.x][a.y+1]==0){
      mp_num[a.x][a.y+1]=mp_num[a.x][a.y]+1;
      b.x=a.x,b.y=a.y+1;
      q.push(b);
    }
  }
}
int main(){
  while(~scanf("%d %d", &n, &m)){
    memset(KFC,0,sizeof(KFC));
    memset(mp_num,0,sizeof(mp_num));
    for(int i=0;i<n;i++){
      scanf("%s", mp[i]);
    }
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        if(mp[i][j]=='Y'){
          init();
          bfs(i,j);
          init_KFC();
        }
        if(mp[i][j]=='M'){
          init();
          bfs(i,j);
          init_KFC();
        }
      }
    }
    int ans=0x3f3f3f;
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        if(mp[i][j]=='@'){
          ans=min(ans,KFC[i][j]);
        }
      }
    }
    printf("%d\n", (ans-2)*11);
  }
  return 0;
}
