/*
Invitation Cards
POJ - 1511
https://cn.vjudge.net/problem/POJ-1511#author=ty21
题意： 求最短路
输入： 点 边
      u->v w
样例输入：
      2
      2 2
      1 2 13
      2 1 33
      4 6
      1 2 10
      2 1 60
      1 3 20
      3 4 10
      2 4 5
      4 1 50
样例输出：
      46
      210
思路：
双向SPFA
*/
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
#define maxn 1000100
#define INF 0x3f3f3f
struct node{
  int u,v;
  int w;
  int next;
}edge[maxn],uedge[maxn];
int head[maxn],uhead[maxn];
int dis[maxn],udis[maxn];
int cnt,ucnt,n,t;
void init(){
  memset(head,-1,sizeof head);
  memset(uhead,-1,sizeof uhead);
  memset(dis,INF,sizeof dis);
  memset(udis,INF, sizeof udis);
  cnt=0;
  ucnt=0;
}
void add(int u,int v,int w,int &cnt, int *head, node *edge){
  edge[cnt].w=w;
  edge[cnt].u=u;
  edge[cnt].v=v;
  edge[cnt].next=head[u];
  head[u]=cnt++;
}
void spfa(int st,int *dis,int *head, node *edge){
  dis[st]=0;
  queue<int> q;
  q.push(st);
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
}
int main(){
  int T,u,v,w;
  scanf("%d", &T);
  while(T--){
    init();
    scanf("%d %d", &n, &t);
    for(int i=0;i<t;i++){
      scanf("%d %d %d", &u, &v, &w);
      add(u,v,w,cnt,head,edge);
      add(v,u,w,ucnt,uhead,uedge);
    }
    spfa(1,dis,head,edge);
    spfa(1,udis,uhead,uedge);
    long long ans=0;
    for(int i=1;i<=n;i++){
      ans+=(long long)(udis[i]+dis[i]);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
