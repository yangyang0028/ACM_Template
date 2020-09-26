/*
Candies
POJ - 3159
https://cn.vjudge.net/problem/POJ-3159#author=xym000
题意：求最大的差异
输入：n个孩子，t个关系
      a相信b永远不会比他自己多c个糖果
样例输入：
      2 2
      1 2 5
      2 1 4
样例输出;
      5
解法：
让第一个孩子拿到的糖果为0，然后跑一边spfa，保证所以的孩子能满足他们之间的关系，然后输出dis[n]
注意：
后台数据卡queue但是不卡stack
*/
#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
#define maxn 30010
#define maxm 150010
#define INF 0x3f3f3f
struct node{
  int u,v,w;
  int next;
}edge[maxm];
int head[maxn];
int dis[maxn];
bool color[maxn];
int cnt,n,t;
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
void spfa(){
  memset(color,true,sizeof color);
  stack<int> q;
  dis[1]=0;
  q.push(1);
  color[1]=false;
  while(!q.empty()){
    int u=q.top();
    q.pop();
    color[u]=true;
    for(int i=head[u];~i;i=edge[i].next){
      if(dis[edge[i].v]>dis[u]+edge[i].w){
        dis[edge[i].v]=dis[u]+edge[i].w;
        if(color[edge[i].v]){
          q.push(edge[i].v);
          color[edge[i].v]=false;
        }
      }
    }
  }
  return;
}
int main(){
  while(~scanf("%d %d", &n, &t)){
    init();
    int u,v,w;
    for(int i=0;i<t;i++){
      scanf("%d %d %d", &u, &v, &w);
      add(u,v,w);
    }
    spfa();
    printf("%d\n", dis[n]);
  }
  return 0;
}
