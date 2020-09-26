/*
Wormholes
POJ - 3259
https://cn.vjudge.net/problem/POJ-3259#author=SCU2018
题意： 通过虫洞回到这个原点之前的时间
      虫洞路径分为两种，双向的时间是正方向，单向的时间是反方向
输入：
      T组样例
      点，双向路径， 单向路径
      u v w
样例输入：
      2
      3 3 1
      1 2 2
      1 3 4
      2 3 1
      3 1 3

      3 2 1
      1 2 3
      2 3 4
      3 1 8
样例输出：
      NO
      YES
思路：
SPFA直接跑，要是发现原点时间减小了，就输出YES否NO
*/
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
#define maxn  100010
#define INF 0x3f3f3f
struct node{
  int u,v,w;
  int next;
}edge[maxn];
int head[maxn];
int dis[maxn];
int n,m1,m2;
int cnt,B=1,E=n;
void init(){
  memset(head,-1,sizeof head);
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
bool spfa(int B){
  dis[B]=0;
  queue<int> q;
  q.push(B);
  while(!q.empty()){
    int u=q.front();
    q.pop();
    for(int i=head[u];~i;i=edge[i].next){
      if(dis[edge[i].v]>dis[u]+edge[i].w){
        dis[edge[i].v]=dis[u]+edge[i].w;
        if(dis[B]<0) return true;
        q.push(edge[i].v);
      }
    }
  }
  return false;
}
int main(){
  int T;
  scanf("%d", &T);
  while(T--){
    scanf("%d %d %d", &n, &m1, &m2);
    init();
    int u,v,w;
    for(int i=0;i<m1;i++){
      scanf("%d %d %d", &u, &v, &w);
      add(u,v,w);
      add(v,u,w);
    }
    for(int i=0;i<m2;i++){
      scanf("%d %d %d", &u, &v, &w);
      add(u,v,-w);
    }
    if(spfa(B)) printf("YES\n");
    else printf("NO\n");
  }
  return 0;
}
