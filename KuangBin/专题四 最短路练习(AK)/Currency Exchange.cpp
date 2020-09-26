/*
Currency Exchange
POJ - 1860
https://cn.vjudge.net/problem/POJ-1860
题意： 兑换货币
      每个地方倒每个地方的兑换汇率和佣金都不一样
      他要是回到出发点时自己的钱增加了，就输出YES否NO
输入：
      第一行是  : 点个数,边个数,出发点，开始的钱
      下面m行是 : 从u->v u->v的汇率 u->v的佣金 v->u的汇率 v->u的佣金
样例输入：
      3 2 1 20.0
      1 2 1.00 1.00 1.00 1.00
      2 3 1.10 1.00 1.10 1.00
样例输出：
      YES
解法：
      直接跑spfa要是发现开始的价值增加了，那就是YES否则NO
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<iostream>
using namespace std;
#define INF 0x3f3f3f
#define maxn 10010
struct node{
  double wa, a;
  int e;
  int next;
}edge[maxn];
int cnt;
int head[maxn];
int n,t,lei;
double num;
void init(){
  memset(head,0,sizeof head);
  cnt=1;
}
void add(int u,int v,double a, double wa){
  edge[cnt].wa=wa;
  edge[cnt].a=a;
  edge[cnt].e=v;
  edge[cnt].next=head[u];
  head[u]=cnt++;
}
bool spfa(int sb){
  queue<int> q;
  bool color[maxn];
  double d[maxn];
  memset(d,0,sizeof d);
  memset(color,true,sizeof color);
  q.push(sb);
  d[sb]=num;
  color[sb]=false;
  while(!q.empty()){
    int st=q.front();
    q.pop();
    color[st]=true;
    for(int i=head[st];i!=0;i=edge[i].next){
      if((d[st]-edge[i].wa)*edge[i].a>d[edge[i].e]){
        d[edge[i].e]=(d[st]-edge[i].wa)*edge[i].a;
            if(d[sb]>num) return true;
        if(color[edge[i].e]){
            q.push(edge[i].e);
            color[edge[i].e]=false;
        }
      }
    }
  }
  return false;
}
int main(){
  scanf("%d %d %d %lf", &n, &t, &lei, &num);
  init();
  int u,v;
  double a,b,wa,wb;
  for(int i=0;i<t;i++){
    scanf("%d %d %lf %lf %lf %lf", &u, &v, &a, &wa, &b, &wb);
    add(u, v, a, wa);
    add(v, u, b, wb);
  }
  if(spfa(lei)) printf("YES\n");
  else printf("NO\n");
  return 0;
}
