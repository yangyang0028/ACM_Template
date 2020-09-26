/*
Silver Cow Party
POJ - 3268
https://cn.vjudge.net/problem/POJ-3268#author=chenchonghan
题意:n个点m条边牛全要到x参加聚会然后在回家，问任意一台奶牛行走的最长时间
输入： 点 边 聚会地点
      u -> v  w
样例输入：
      4 8 2
      1 2 4
      1 3 2
      1 4 7
      2 1 1
      2 3 5
      3 1 2
      3 4 4
      4 2 3
样例输出：
      10
直接跑两边spfa即可
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
int cnt,ucnt,n,t,st;
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
    scanf("%d %d %d", &n, &t, &st);
    int u,v,w;
    init();
    for(int i=0;i<t;i++){
      scanf("%d %d %d", &u, &v, &w);
      add(u,v,w,cnt,head,edge);
      add(v,u,w,ucnt,uhead,uedge);
    }
    spfa(st,dis,head,edge);
    spfa(st,udis,uhead,uedge);
    int ans=0;
    for(int i=1;i<=n;i++){
      ans=max(ans,udis[i]+dis[i]);
    }
    printf("%d\n", ans);
  return 0;
}
