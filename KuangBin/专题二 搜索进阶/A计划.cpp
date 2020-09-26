//https://cn.vjudge.net/problem/HDU-2102
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
char mp_c[2][15][15];
int mp[2][15][15];
int n,m,t;
struct node{
  int x=0,y=0,z=0;
};
void print(){
  for(int k=0;k<2;k++){
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        printf("%3d", mp[k][i][j]);
      }
      cout<<endl;
    }
    cout<<endl;
  }
}
void init(){
  for(int k=0;k<2;k++){
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        if(mp_c[k][i][j]=='S'){
          mp[i][j][k]=1;
        }else if(mp_c[k][i][j]=='*'){
          mp[k][i][j]=-1;
        }else if(mp_c[k][i][j]=='P'){
          mp[k][i][j]=0;
        }else mp[k][i][j]=0;
      }
    }
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(mp_c[0][i][j]=='#'&&mp_c[1][i][j]=='#'){
        mp_c[0][i][j]=mp_c[1][i][j]='*';
        mp[0][i][j]=mp[1][i][j]=-1;
      }
      if(mp_c[0][i][j]=='*'&&mp_c[1][i][j]=='#'){
        mp_c[0][i][j]=mp_c[1][i][j]='*';
        mp[0][i][j]=mp[1][i][j]=-1;
      }
      if(mp_c[0][i][j]=='#'&&mp_c[1][i][j]=='*'){
        mp_c[0][i][j]=mp_c[1][i][j]='*';
        mp[0][i][j]=mp[1][i][j]=-1;
      }
    }
  }
}

int bfs(){
  queue<node> q;
  node a,b;
  a.x=0;
  a.y=0;
  a.z=0;
  q.push(a);
  while(!q.empty()){
    b=q.front();
    q.pop();
    if(mp_c[b.z][b.x][b.y]=='P'){
      return mp[b.z][b.x][b.y];
    }
    if(mp_c[b.z][b.x][b.y]=='#'&&mp[(b.z+1)%2][b.x][b.y]==0){
      mp[(b.z+1)%2][b.x][b.y]=mp[b.z][b.x][b.y];
      a.x=b.x;
      a.y=b.y;
      a.z=(b.z+1)%2;
      q.push(a);
      continue;
    }
    if(b.x+1<n&&mp[b.z][b.x+1][b.y]==0){
      mp[b.z][b.x+1][b.y]=mp[b.z][b.x][b.y]+1;
      a.x=b.x+1;
      a.y=b.y;
      a.z=b.z;
      q.push(a);
    }
    if(b.x-1>=0&&mp[b.z][b.x-1][b.y]==0){
      mp[b.z][b.x-1][b.y]=mp[b.z][b.x][b.y]+1;
      a.x=b.x-1;
      a.y=b.y;
      a.z=b.z;
      q.push(a);
    }
    if(b.y+1<m&&mp[b.z][b.x][b.y+1]==0){
      mp[b.z][b.x][b.y+1]=mp[b.z][b.x][b.y]+1;
      a.x=b.x;
      a.y=b.y+1;
      a.z=b.z;
      q.push(a);
    }
    if(b.y-1>=0&&mp[b.z][b.x][b.y-1]==0){
      mp[b.z][b.x][b.y-1]=mp[b.z][b.x][b.y]+1;
      a.x=b.x;
      a.y=b.y-1;
      a.z=b.z;
      q.push(a);
    }
  }
  return -1;
}
int main(){
  int T;
  scanf("%d", &T);
  while(T--){
    memset(mp_c,0,sizeof mp_c);
    memset(mp,0,sizeof mp);
    scanf("%d %d %d", &n, &m, &t);
    for(int i=0;i<n;i++){
      scanf("%s", mp_c[0][i]);
    }

    for(int i=0;i<n;i++){
      scanf("%s", mp_c[1][i]);
    }
    init();
    //print();
    mp[0][0][0]=1;
    int ans=bfs()-1;
    //print();
    //cout<<ans<<endl;
    if(ans<0||ans>t){
      printf("NO\n");
    }else printf("YES\n");
  }
}
