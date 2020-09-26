/*
Arctic Network
POJ - 2349
https://cn.vjudge.net/problem/POJ-2349#author=clzls
题面：
    有两种通信方式
    A 第一种没有距离限制，但只要个别观察站站有
    B 传输距离最大为D,但每个观察站都有
    问D最小是多少
解法：
    Kruskal算法
*/
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <math.h>
using namespace std;
#define maxn 1000000
struct node{
  int x,y;
}node[maxn];
struct edge_{
  int u,v;
  double w;
}edge[maxn];
int n,m,cnt;
int fa[maxn];
void init(){
  for(int i=0;i<=m;i++){
    fa[i]=i;
  }
  cnt=0;
}
void read(){
  for(int i=0;i<m;i++){
    cin>>node[i].x>>node[i].y;
  }
  for(int i=0;i<m;i++){
    for(int j=i+1;j<m;j++){
      edge[cnt].u=i;
      edge[cnt].v=j;
      edge[cnt++].w=pow((node[i].x-node[j].x)*(node[i].x-node[j].x)+(node[i].y-node[j].y)*(node[i].y-node[j].y),0.5);
    }
  }
}
int root(int x){
  return fa[x]==x?x:fa[x]=root(fa[x]);
}
bool ailke(int x,int y){
  return root(x)==root(y);
}
void unite(int x,int y){
  x=root(x);
  y=root(y);
  if(x!=y) fa[x]=y;
}
bool cmp(edge_ a,edge_ b){
  return a.w<b.w;
}
double solve(){
  sort(edge,edge+cnt,cmp);
  double ans=0;
  int num=0;
  for(int i=0;i<cnt;i++){
    //cout<<edge[i].u<<"  "<<edge[i].v<<" "<<edge[i].w<<endl;
    if(!ailke(edge[i].u, edge[i].v)){
      unite(edge[i].u, edge[i].v);
      ans=edge[i].w;
      num++;
    }
    if(num==m-n) break;
  }
  return ans;
}
int main(){
  int T;
  cin>>T;
  while(T--){
    cin>>n>>m;
    init();
    read();
    printf("%.2lf\n", solve());
  }
  return 0;
}
