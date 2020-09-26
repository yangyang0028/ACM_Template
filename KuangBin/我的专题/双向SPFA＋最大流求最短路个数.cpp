/*
Marriage Match IV
HDU - 3416
https://cn.vjudge.net/problem/HDU-3416
题意:  找出所有最短路的个数
输入 ：
      T组样例
      点 边
      u->v w
      B E
样例输入：
      2
      7 8
      1 2 1
      1 3 1
      2 4 1
      3 4 1
      4 5 1
      4 6 1
      5 7 1
      6 7 1
      1 7

      2 2
      1 2 1
      1 2 2
      1 2
样例输出：
      2
      1
解法：
双向SPFA枚举每条边找出最短路的连通图
最大流求最短路的个数
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<iostream>
using namespace std;
#define INF 0x3f3f3f
#define maxn 100010
struct node{
  int u, v, w;
  int next;
}edge[maxn], uedge[maxn], wedge[maxn*2];
int head[maxn], uhead[maxn], whead[maxn];
int cnt, ucnt, wcnt;
int dis[maxn], udis[maxn];
int d[maxn];
int t,n,B,E;
void init(){
  memset(head, -1, sizeof head);
  memset(uhead, -1, sizeof uhead);
  memset(whead, -1, sizeof whead);
  memset(dis, INF, sizeof dis);
  memset(udis, INF, sizeof udis);
  cnt = ucnt = wcnt = 0;
}
void add(int u, int v, int w, node edge[], int  &cnt, int *head){
  edge[cnt].w=w;
  edge[cnt].u=u;
  edge[cnt].v=v;
  edge[cnt].next=head[u];
  head[u]=cnt++;
}
void add_dinic(int u,int v,int w){
  wedge[wcnt].w=w;
  wedge[wcnt].u=u;
  wedge[wcnt].v=v;
  wedge[wcnt].next=whead[u];
  whead[u]=wcnt++;

  wedge[wcnt].w=0;
  wedge[wcnt].u=v;
  wedge[wcnt].v=u;
  wedge[wcnt].next=whead[v];
  whead[v]=wcnt++;
}
void spfa(int st, int *dis, int *head, node edge[]){
  queue<int> q;
  q.push(st);
  dis[st]=0;
  while(!q.empty()){
    int u=q.front();
    q.pop();
    for(int i=head[u];~i;i=edge[i].next){
      if(dis[u]+edge[i].w<dis[edge[i].v]){
        dis[edge[i].v]=dis[u]+edge[i].w;
        q.push(edge[i].v);
      }
    }
  }
}
bool bfs(int B,int E){
  memset(d,-1,sizeof d);
  queue<int> q;
  d[B]=0;
  q.push(B);
  while(!q.empty()){
    int st=q.front();
    q.pop();
    for(int i=whead[st];~i;i=wedge[i].next){
      if(d[wedge[i].v]==-1&&wedge[i].w>0){
        d[wedge[i].v]=d[st]+1;
        q .push(wedge[i].v);
      }
    }
  }
  return d[E]!=-1;
}
int dfs(int a,int b){
  int r=0;
  if(a==E) return b;
  for(int i=whead[a];~i;i=wedge[i].next){
    if(wedge[i].w>0&&d[wedge[i].v]==d[a]+1){
      int x=min(wedge[i].w,b-r);
      x=dfs(wedge[i].v,x);
      r+=x;
      wedge[i].w-=x;
      wedge[i^1].w+=x;
    }
  }
  if(!r) d[a]=-2;
  return r;
}
int dinic(int B,int E){
  int ans=0;
  int t;
  while(bfs(B,E)){
    while(t=dfs(B,INF)) ans+=t;
  }
  return ans;
}
int main(){
  scanf("%d %d", &n, &t);
  init();
  for(int i=0;i<t;i++){
    int u,v,w;
    scanf("%d %d %d", &u, &v, &w);
    add(u, v, w, edge, cnt, head);
    add(v, u, w, uedge, ucnt, uhead);
  }
  scanf("%d %d", &B ,&E);
  spfa(B, dis, head, edge);
  if(dis[E]==INF){
    printf("0\n");
    return 0;
  }
  long long tmp = dis[E];
  spfa(E, udis, uhead, uedge);
  for(int i=0;i<t;i++){
    int u=edge[i].u,v=edge[i].v;
    if(edge[i].w&&dis[u]+udis[v]+edge[i].w==tmp){
      add_dinic(u,v,1);
    }
  }
  printf("%d\n", dinic(B,E));
  return 0;
}
