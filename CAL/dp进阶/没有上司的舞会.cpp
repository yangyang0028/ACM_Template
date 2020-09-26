/*
没有上司的舞会
P1352
https://www.luogu.org/problem/P1352
题意：有一场舞会，每一个人都有一个快乐值，但不能和上司同时出现在舞会中，问这个舞会的快乐值最大为多少
解法：
树状DP
*/
#include <bits/stdc++.h>
using namespace std;
#define maxn 100000
struct node{
	int u,v;
	int next;
}edge[maxn];
int head[maxn],cnt;
int dp[maxn][2];
int a[maxn];
void init(){
	memset(head,-1,sizeof head);
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
	dp[u][1]=a[u];
	for(int i=head[u];~i;i=edge[i].next){
		int v=edge[i].v;
		if(v!=fa){
			dfs(v, u);
			dp[u][0]+=max(dp[v][0],dp[v][1]);
			dp[u][1]+=dp[v][0];
		}
	}
}
int main(){
	int n,u,v;
	cin>>n;
	init();
	for(int i=1;i<=n;i++) cin>>a[i];
	while(cin>>u>>v&&u+v){
		add(u,v);
		add(v,u);
	}
	dfs(1,-1);
	cout<<max(dp[1][0],dp[1][1])<<endl;
	return 0;
}
