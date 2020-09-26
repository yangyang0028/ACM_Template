/*
Strategic game
POJ - 1463
https://cn.vjudge.net/problem/POJ-1463
题面：最小点覆盖
解法: 树状DP
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
#define maxn 100000
struct node{
  int u,v;
  int next;
}edge[maxn];
int head[maxn];
int dp[maxn][2];
int cnt;
void init(){
	memset(head,-1,sizeof head);
	memset(dp,0,sizeof dp);
	cnt=0;
}
void add(int u,int v){
	edge[cnt].u=u;
	edge[cnt].v=v;
	edge[cnt].next=head[u];
	head[u]=cnt++;
}
void dfs(int u,int fa){
  dp[u][0]=0;
  dp[u][1]=1;
  for(int i=head[u];~i;i=edge[i].next){
    int v=edge[i].v;
    if(v!=fa){
      dfs(v,u);
      dp[u][0]+=dp[v][1];
      dp[u][1]+=min(dp[v][0],dp[v][1]);
    }
  }
}
int main(){
  int n,m,k,a;
  while(cin>>n){
    init();
    for(int i=0;i<n;i++){
      scanf("%d:(%d)", &m, &k);
      for(int i=0;i<k;i++){
        cin>>a;
        add(m,a);
        add(a,m);
      }
    }
    dfs(0,0);
    cout<<min(dp[0][0],dp[0][1])<<endl;
  }
  return 0;
}
