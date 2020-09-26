/*
Building a Space Station
POJ - 2031
https://cn.vjudge.net/problem/POJ-2031#author=jack10086
题意：
    给你n个球，让你找到连接这些球的最小距离
解法：
    计算每个球到其他球直接的距离+最小生成树
*/
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
#define maxn 100000
int n;
int fa[maxn];
struct node{
  double x,y,z,r;
}node[maxn];
struct edge_{
  int u,v;
  double w;
}edge[maxn];
int cnt;
void init(){
  cnt=0;
  for(int i=0;i<=n;i++){
    fa[i]=i;
  }
}
double max_double(double a, double b){
  if(a>b) return a;
  return b;
}
void read(){
  for(int i=0;i<n;i++){
    scanf("%lf%lf%lf%lf", &node[i].x, &node[i].y, &node[i].z, &node[i].r);
  }
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      edge[cnt].u=i;
      edge[cnt].v=j;
      edge[cnt++].w=max_double(0,(sqrt((node[i].x-node[j].x)*(node[i].x-node[j].x)+(node[i].y-node[j].y)*(node[i].y-node[j].y)+(node[i].z-node[j].z)*(node[i].z-node[j].z))-node[i].r-node[j].r));
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
    if(num==n-1) break;
    if(!ailke(edge[i].u, edge[i].v)){
      unite(edge[i].u, edge[i].v);
      ans+=edge[i].w;
      num++;
    }
  }
  return ans;
}
int main(){
  while(cin>>n&&n){
    init();
    read();
    printf("%.3lf\n", solve());
  }
  return 0;
}
