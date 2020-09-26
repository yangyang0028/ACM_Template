/*
Layout
POJ - 3169
https://cn.vjudge.net/problem/POJ-3169
题意：关系好的奶牛想在一起，关系不好的奶牛想远离对方，问1的n的距离
输入：奶牛数 关系好的个数t1 关系不好的个数t2
      t1行 a b 之间最多 d
      t2行 a b 之间最少 d
样例输入：
      4 2 1
      1 3 10
      2 4 20
      2 3 3
样例输出：
      27
解法：
差分约束
关系好： dis[b]-dis[a]<d a<b add(a,b,d)
关系坏： dis[a]-dis[b]<d a>b add(a,b,d)
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
}edge[maxn];
int head[maxn];
int dis[maxn];
int color[maxn];
int cnt,n,t1,t2;
void init(){
  memset(head,-1,sizeof head);
  memset(dis,INF,sizeof dis);
  memset(color,0,sizeof color);
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
  scanf("%d %d %d", &n, &t1, &t2);
  init();
  int u,v,w;
  for(int i=0;i<t1;i++){
    scanf("%d %d %d", &u, &v, &w);
    if(u>v)swap(u,v);
    add(u,v,w);
  }
  for(int i=0;i<t2;i++){
    scanf("%d %d %d", &u, &v, &w);
    if(u<v)swap(u,v);
    add(u,v,-w);
  }
  if(spfa()){
    if(dis[n]==INF){
      printf("-2\n");
    }else{
      printf("%d\n", dis[n]);
    }
  }else{
    printf("-1\n");
  }
  return 0;
}
