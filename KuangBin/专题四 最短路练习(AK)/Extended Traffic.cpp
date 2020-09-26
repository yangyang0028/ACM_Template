/*
Extended Traffic
LightOJ - 1074
https://cn.vjudge.net/problem/LightOJ-1074
题意:每条街道的拥挤度P(x),街a到街b的时间是(p(b)-p(a))^3,找最短路，若无法到达或结果小于3，输出?
输入：T组样例
      城市个数
      1到n的繁荣度
      城市中的道路数量
      单向 u->v
      q个查询
      1到qi
样例输入：
      2
      5
      6 7 8 9 10
      6
      1 2
      2 3
      3 4
      1 5
      5 4
      4 5
      2
      4
      5
      2
      10 10
      1
      1 2
      1
      2
样例输出：
      Case 1:
      3
      4
      Case 2:
      ?
解法：
SPFA判负环
*/

#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <iostream>
#include <cmath>
using namespace std;
#define maxt 1000000
#define maxn 1000
#define INF 0x3f3f3f3f
struct node{
  int u,v,w;
  int next;
}edge[maxt];
int head[maxn];
int dis[maxn];
int d[maxn];
int color[maxn];
int cnt,n,t;
void init(){
  memset(head,-1,sizeof head);
  memset(dis,INF,sizeof dis);
  memset(color,0,sizeof color);
  memset(edge,0,sizeof edge);
  memset(d,0,sizeof d);
  cnt=0;
}
void add(int u,int v,int w){
  edge[cnt].u=u;
  edge[cnt].v=v;
  edge[cnt].w=w;
  edge[cnt].next=head[u];
  head[u]=cnt++;
}
bool spfa(){
  queue<int> q;
  dis[1]=0;
  q.push(1);
  color[1]++;
  while(!q.empty()){
    int u=q.front();
    q.pop();
    for(int i=head[u];~i;i=edge[i].next){
      if(dis[edge[i].v]>dis[u]+edge[i].w){
        dis[edge[i].v]=dis[u]+edge[i].w;
        q.push(edge[i].v);
        if(++color[edge[i].v]>=n) return false;
      }
    }
  }
  return true;
}
int main(){
  int T;
  int q,u,v,w;
  scanf("%d", &T);
  for(int s=1;s<=T;s++){
    init();
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
      scanf("%d", &d[i]);
    }
    scanf("%d", &t);
    for(int i=0;i<t;i++){
      scanf("%d %d", &u, &v);
      add(u,v,(d[v]-d[u])*(d[v]-d[u])*(d[v]-d[u]));
    }
    bool ll=spfa();
    scanf("%d", &q);
    printf("Case %d:\n", s);
    while(q--){
      scanf("%d", &w);
      int ans=dis[w];
      if(ans<3||ans==INF) printf("?\n");
      else printf("%d\n", dis[w]);
    }
  }
  return 0;
}
