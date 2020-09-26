/*
Borg Maze
POJ - 3026
https://vjudge.net/problem/POJ-3026
题面：要从s到所有A找出一条最短路
解法： BFS+最小生成树
PS：是m行，且在输入时 n m后面有数量未知的空格 （我服了，出题人）
*/
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<queue>
#include <iostream>
using namespace std;
#define maxn 1000000
char mp_c[550][550];
int mp[550][550];
struct node{
  int x,y;
}b,a[maxn];
struct edge_{
  int u,v,w;
}edge[maxn];
int fa[maxn];
int cnt,cnte;
int n,m;
void bfs(int xx,int yy){
  b.x=xx;
  b.y=yy;
  mp[xx][yy]=1;
  queue<node> q;
  q.push(b);
  while(!q.empty()){
    int x=q.front().x;
    int y=q.front().y;
    q.pop();
    if(x-1>=0&&mp[x-1][y]==0){
      mp[x-1][y]=mp[x][y]+1;
      b.x=x-1;
      b.y=y;
      q.push(b);
    }
    if(x+1<n&&mp[x+1][y]==0){
      mp[x+1][y]=mp[x][y]+1;
      b.x=x+1;
      b.y=y;
      q.push(b);
    }
    if(y-1>=0&&mp[x][y-1]==0){
      mp[x][y-1]=mp[x][y]+1;
      b.x=x;
      b.y=y-1;
      q.push(b);
    }
    if(y+1<m&&mp[x][y+1]==0){
      mp[x][y+1]=mp[x][y]+1;
      b.x=x;
      b.y=y+1;
      q.push(b);
    }
  }
}
void init(){
  cnt=1;
  cnte=0;
  memset(mp,0,sizeof mp);
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      if(mp_c[i][j]=='A'){
        a[cnt].x=i;
        a[cnt++].y=j;
      }
      if(mp_c[i][j]=='S'){
        a[cnt].x=i;
        a[cnt++].y=j;
      }
    }
  }
  for(int k=1;k<cnt;k++){
    memset(mp,0,sizeof mp);
    for(int i=0;i<m;i++){
      for(int j=0;j<n;j++){
        if(mp_c[i][j]=='#') mp[i][j]=-1;
      }
    }
    bfs(a[k].x, a[k].y);
    for(int i=1;i<cnt;i++){
      if(i!=k){
        edge[cnte].u=k;
        edge[cnte].v=i;
        edge[cnte++].w=mp[a[i].x][a[i].y]-1;
      }
    }
  }
}
int root(int x){
  return fa[x]==x?x:fa[x]=root(fa[x]);
}
void unite(int x,int y){
  x=root(x);
  y=root(y);
  if(x!=y) fa[x]=y;
}
bool alike(int x,int y){
  return root(x)==root(y);
}
bool cmp(edge_ a,edge_ b){
  return a.w<b.w;
}
int solve(){
  for(int i=0;i<=cnt;i++) fa[i]=i;
  sort(edge,edge+cnte,cmp);
  int num=0,ans=0;
  for(int i=0;i<cnte;i++){
    if(!alike(edge[i].u,edge[i].v)){
      unite(edge[i].u,edge[i].v);
      num++;
      ans+=edge[i].w;
    }
    if(num==cnt-2) return ans;
  }
  return 0;
}
int main(){
  int T;
    scanf("%d", &T);
  while(T--){
    scanf("%d %d ", &n, &m);
    for(int i=0;i<m;i++){
      gets(mp_c[i]);
    }
    init();
    cout<<solve()<<endl;;
  }
  return 0;
}
