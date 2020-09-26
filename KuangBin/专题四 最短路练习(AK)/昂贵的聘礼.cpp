/*
昂贵的聘礼
POJ - 1062
https://cn.vjudge.net/problem/POJ-1062
题意：他和酋长买东西，他可以通过和别人交换来找减少自己最少要花费的金币，但只能在等级差内交易
输入  等级差距 N个物品的总数
      物品价格 主人地位 代替品总数
      代替品的编号，优惠价格
样例输入：
      1 4
      10000 3 2
      2 8000
      3 5000
      1000 2 1
      4 200
      3000 2 1
      4 200
      50 2 0
样例输出：
      5250
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
#define maxn 100000
#define INF 0x3f3f3f
struct node{
  int u,v,w;
  int next;
}edge[maxn];
int head[maxn];
int dis[maxn];
int cnt,m,n;
bool color[maxn];
int l[maxn];
void init(){
  memset(head,-1,sizeof head);
  memset(dis,INF,sizeof dis);
  memset(color,true,sizeof color);
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
  q.push(0);
  dis[0]=0;
  while(!q.empty()){
    int st=q.front();
    q.pop();
    for(int i=head[st];~i;i=edge[i].next){
      if(dis[st]+edge[i].w<dis[edge[i].v]&&color[edge[i].v]){
        dis[edge[i].v]=dis[st]+edge[i].w;
        q.push(edge[i].v);
      }
    }
  }
}
int solve(){
  int ans=INF;
  for(int i=1;i<=n;i++){
    memset(dis,INF,sizeof dis);
    memset(color,true,sizeof color);
    int minle=l[i];
    for(int j=1;j<=n;j++){
      if(l[j]<minle||l[j]-minle>m){
          color[j]=false;
      }
    }
    spfa();
    ans=min(ans,dis[1]);
  }
  return ans;
}
int main(){
  init();
  scanf("%d %d", &m, &n);
  int p,x;
  int t,v;
  for(int i=1;i<=n;i++){
    scanf("%d %d %d", &p, &l[i], &x);
    add(0,i,p);
    while(x--){
      scanf("%d %d",&t, &v);
      add(t,i,v);
    }
  }
  printf("%d\n", solve());
  return 0;
}
