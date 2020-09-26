#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <limits.h>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
char mp[15][15];
int mp_num[15][15];
int n,m;
struct node{
  int x,y;
};
queue<node> q;
queue<node> p;
void init(){
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(mp[i][j]=='#') mp_num[i][j]=0;
      else mp_num[i][j]=-1;
    }
  }
}
void dfs(int x,int y){
  node a;
  a.x=x,a.y=y;
  p.push(a);
  if(x+1< n&&mp[x+1][y]=='#') mp[x+1][y]='0',dfs(x+1,y);
  if(y+1< m&&mp[x][y+1]=='#') mp[x][y+1]='0',dfs(x,y+1);
  if(x-1>=0&&mp[x-1][y]=='#') mp[x-1][y]='0',dfs(x-1,y);
  if(y-1>=0&&mp[x][y-1]=='#') mp[x][y-1]='0',dfs(x,y-1);
}
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
void bfs_d(int x,int y,int x1,int y1){
  node a,b;
  a.x=x,a.y=y;
  mp_num[x][y]=1;
  q.push(a);
    a.x=x1,a.y=y1;
    mp_num[x1][y1]=1;
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
int solve(){
  int ans=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      ans=max(ans,mp_num[i][j]-1);
    }
  }
  return ans;
}
int main(){
  int t;
  scanf("%d", &t);
  for(int s=1;s<=t;s++){
    int num=0x3f3f3f;
    int num1=0x3f3f3f;
    node c,a;
    c.x=-1,c.y=-1;
    while(!p.empty()) p.pop();
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++){
      scanf("%s", mp[i]);
    }
    int ans=0;
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        if(mp[i][j]=='#') ans++,dfs(i,j),p.push(c);
      }
    }
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        if(mp[i][j]=='0') mp[i][j]='#';
      }
    }
    if(ans>2){
      printf("Case %d: -1\n", s);
      continue;
    }
    if(ans==1){
      node f[100];
      memset(f,0,sizeof(f));
      int numm=0;
      while(!p.empty()){
        a=p.front();
        p.pop();
        if(a.x==-1&&a.y==-1) break;
        f[numm++]=a;
      }
      for(int i=0;i<numm;i++){
        //printf("%d %d\n", f[i].x, f[i].y);
      }
      for(int i=0;i<numm;i++){
        for(int j=i;j<numm;j++){
          init();
          bfs_d(f[j].x,f[j].y,f[i].x,f[i].y);
          int aa=solve();
          //printf("%d %d == %d \n", i, j, aa);
          num=min(num,aa);
        }
      }
    }
    if(ans==2){
      while(!p.empty()){
        a=p.front();
        p.pop();
        if(a.x==-1&&a.y==-1) break;
        init();
        bfs(a.x,a.y);
        num=min(num,solve());
      }
      while(!p.empty()){
        a=p.front();
        p.pop();
        if(a.x==-1&&a.y==-1) break;
        init();
        bfs(a.x,a.y);
        num1=min(num1,solve());
      }
      if(num1==0x3f3f3f) num1=0;
      if(num==0x3f3f3f) num=0;
      num=max(num,num1);
    }
    printf("Case %d: %d\n", s, num);
  }
  return 0;
}
