/*
Cell Phone Network
POJ - 3659
https://cn.vjudge.net/problem/POJ-3659
题面：最小支配集
解法: 树状DP
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
#define maxn 500000
#define INF 0x3f3f3f3f
struct node{
  int u,v;
  int next;
}edge[maxn];
int head[maxn];
int dp[maxn][3];
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
  dp[u][0]=1;
  dp[u][1]=0;
  dp[u][2]=0;
  int sum=0,inc=INF;
  bool judge=false;
  for(int i=head[u];~i;i=edge[i].next){
    int v=edge[i].v;
    if(v!=fa){
      dfs(v,u);
      dp[u][0]+=min(dp[v][0],min(dp[v][1],dp[v][2]));
      if(dp[v][0]<=dp[v][1]){
        sum+=dp[v][0];
        judge=true;
      }else{
        sum+=dp[v][1];
        inc=min(inc,dp[v][0]-dp[v][1]);
      }
      if(dp[v][1]!=INF&&dp[u][2]!=INF) dp[u][2]+=dp[v][1];
      else dp[u][2]=INF;
      dp[u][1]+=min(dp[v][0],dp[v][1]);
    }
  }
  if(inc==INF&&!judge) dp[u][1]=INF;
  else {
    dp[u][1]=sum;
    if(!judge) dp[u][1]+=inc;
  }
}
int main(){
  int n,u,v;
  while(cin>>n){
    init();
    for(int i=1;i<n;i++){
      cin>>u>>v;
      add(u,v);
      add(v,u);
    }
    dfs(1,1);
    cout<<min(dp[1][0],min(dp[1][1],dp[1][2]+1))<<endl;
  }
  return 0;
}
