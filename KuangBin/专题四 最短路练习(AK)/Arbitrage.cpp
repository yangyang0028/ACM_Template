/*
Arbitrage
POJ - 2240
https://cn.vjudge.net/problem/POJ-2240#author=0
题意： 通过货币汇率的差异来赚钱
输入: 货币种类的数目n
      下面n行是货币名称
      货币交换的数目t
      下面t行是 u -> v w
      n为0时结束
样例输入：
      3
      USDollar
      BritishPound
      FrenchFranc
      3
      USDollar 0.5 BritishPound
      BritishPound 10.0 FrenchFranc
      FrenchFranc 0.21 USDollar

      3
      USDollar
      BritishPound
      FrenchFranc
      6
      USDollar 0.5 BritishPound
      USDollar 4.9 FrenchFranc
      BritishPound 10.0 FrenchFranc
      BritishPound 1.99 USDollar
      FrenchFranc 0.09 BritishPound
      FrenchFranc 0.19 USDollar

      0
样例输出：
      Case 1: Yes
      Case 2: N
解法：
map 映射 + spfa
*/
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <map>
#include <iostream>
using namespace std;
#define maxn 100000
#define INF 0x3f3f3f
map<string,int> mp;
struct node{
  int u,v;
  double w;
  int next;
}edge[maxn];
int head[maxn];
double dis[maxn];
string a,b;
int cnt,n,t;
int B=1;
void init(){
  memset(dis,0,sizeof dis);
  memset(head,-1,sizeof head);
  cnt=0;
}
void add(int u,int v,double w){
  edge[cnt].w=w;
  edge[cnt].u=u;
  edge[cnt].v=v;
  edge[cnt].next=head[u];
  head[u]=cnt++;
}
bool spfa(int B){
  dis[B]=1;
  queue<int> q;
  q.push(B);
  while(!q.empty()){
    int u=q.front();
    q.pop();
    for(int i=head[u];~i;i=edge[i].next){
      if(dis[edge[i].v]<dis[u]*edge[i].w){
        dis[edge[i].v]=dis[u]*edge[i].w;
        if(dis[B]>1) return true;
        q.push(edge[i].v);
      }
    }
  }
  return false;
}
int main(){
  int T=1;
  while(~scanf("%d", &n)&&n){
    init();
    for(int i=1;i<=n;i++){
      cin>>a;
      mp[a]=i;
    }
    scanf("%d", &t);
    double w;
    for(int i=0;i<t;i++){
      cin>>a>>w>>b;
      add(mp[a],mp[b],w);
    }
    printf("Case %d: ", T++);
    if(spfa(B)) printf("Yes\n");
    else printf("No\n");
  }
}
