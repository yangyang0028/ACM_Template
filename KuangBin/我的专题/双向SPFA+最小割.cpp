/*
Path
HDU - 6582
https://cn.vjudge.net/problem/HDU-6582
题意：割断所有的最短路所需要的代价
输入：
      T组样例
      点 边
      u->v w
样例输入：
      1
      3 4
      1 2 1
      2 3 1
      1 3 2
      1 3 3
样例输出：
      3
解法：
双向SPFA枚举每条边找出最短路的连通图
最小割来计算代价
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<iostream>
using namespace std;
#define INF 0x3f3f3f
#define maxn 100100
#define ll long long
struct node{
  int u, v, w;
  int next;
}edge[maxn], uedge[maxn], wedge[maxn];
int head[maxn], uhead[maxn], whead[maxn];
int cnt, ucnt, wcnt;
ll dis[maxn], udis[maxn];
int d[maxn];
int t,n;
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
void spfa(int st, ll *dis, int *head, node edge[]){
  dis[st]=0;
  queue<int> q;
  q.push(st);
  while(!q.empty()){
    int u=q.front();
    q.pop();
    for(int i = head[u]; ~i; i = edge[i].next ){
      int v=edge[i].v;
      if(dis[v] > dis[u] + (ll)edge[i].w){
        dis[v] = dis[u] + (ll)edge[i].w;
        q.push(v);
      }
    }
  }
  return ;
}
bool bfs(){
  memset(d,-1,sizeof d);
  queue<int> q;
  d[1]=0;
  q.push(1);
  while(!q.empty()){
    int st=q.front();
    q.pop();
    for(int i=whead[st];~i;i=wedge[i].next){
      if(d[wedge[i].v]==-1&&wedge[i].w>0){
        d[wedge[i].v]=d[st]+1;
        q.push(wedge[i].v);
      }
    }
  }
  return d[n]!=-1;
}
int dfs(int a,int b){
  int r=0;
  if(a==n) return b;
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
ll dinic(){
  ll ans=0;
  int t;
  while(bfs()){
    while(t=dfs(1,INF)) ans+=(ll)t;
  }
  return ans;
}
int main(){
  int T;
  scanf("%d", &T);
  while(T--){
    scanf("%d %d", &n, &t);
    init();
    for(int i=0;i<t;i++){
      int u,v,w;
      scanf("%d %d %d", &u, &v, &w);
      add(u, v, w, edge, cnt, head);
      add(v, u, w, uedge, ucnt, uhead);
    }
    spfa(1, dis, head, edge);
    if(dis[n]==INF){
      printf("0\n");
      continue;
    }
    long long tmp = dis[n];
    spfa(n, udis, uhead, uedge);
    for(int i=0;i<t;i++){
      int u=edge[i].u,v=edge[i].v;
      if(dis[u]+udis[v]+edge[i].w==tmp){
        add_dinic(u,v,edge[i].w);
      }
    }
    printf("%lld\n", dinic());
  }
  return 0;
}
