/*
The Shortest Path in Nya Graph
HDU - 4725
https://cn.vjudge.net/problem/HDU-4725#author=0
题意：求从1到n的最短路,有层数，点可能不在同一层
输入：节点数 额外边数 相邻层移动的成本
样例输入：
      2
      3 3 3
      1 3 2
      1 2 1
      2 3 1
      1 3 3

      3 3 3
      1 3 2
      1 2 2
      2 3 2
      1 3 4
样例输出：
      Case #1: 2
      Case #2: 3
解法：
点与点建边，层与层建边，然后层上的点与相邻层和本层建边
spfa
*/
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <iostream>
#include <cmath>
using namespace std;
#define maxn 1000000
#define INF 0x3f3f3f3f
struct node{
  int u,v,w;
  int next;
}edge[maxn*3];
int head[maxn];
int dis[maxn];
int vv[maxn], lay[maxn];
int cnt,n,t,c;
void init(){
  memset(head,-1,sizeof head);
    memset(vv,0,sizeof(vv));
  memset(dis,INF,sizeof dis);
  cnt=0;
}
void add(int u,int v,int w){
  edge[cnt].u=u;
  edge[cnt].v=v;
  edge[cnt].w=w;
  edge[cnt].next=head[u];
  head[u]=cnt++;
}
void spfa(){
  queue<int> q;
  dis[1]=0;
  q.push(1);
  while(!q.empty()){
    int u=q.front();
    q.pop();
    for(int i=head[u];~i;i=edge[i].next){
      if(dis[edge[i].v]>dis[u]+edge[i].w){
        dis[edge[i].v]=dis[u]+edge[i].w;
        q.push(edge[i].v);
      }
    }
  }
  return ;
}
int main(){
  int T;
  int q,u,v,w;
  scanf("%d", &T);
  for(int s=1;s<=T;s++){
    scanf("%d %d %d", &n, &t, &c);
    init();
    for(int i=1;i<=n;i++){
        scanf("%d", &q);
        lay[i]=q;
        vv[q]=1;
    }
    for(int i = 1; i < n; i++){
        if(vv[i]&&vv[i+1]){
            add(n+i,n+i+1,c);
            add(n+i+1,n+i,c);
        }
    }
    for(int i = 1; i <= n; i++) {
        add(n+lay[i],i,0);
        if(lay[i] > 1)
            add(i,n+lay[i]-1,c);
        if(lay[i] < n)
            add(i,n+lay[i]+1,c);
    }
    for(int i=0;i<t;i++){
      scanf("%d %d %d", &u, &v, &w);
      add(u,v,w);
      add(v,u,w);
    }
    spfa();
    if(dis[n]==INF) dis[n]=-1;
    printf("Case #%d: %d\n", s, dis[n]);
  }
  return 0;
}
