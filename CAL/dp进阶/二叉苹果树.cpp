/*
Binary Apple Tree
URAL - 1018
https://cn.vjudge.net/problem/URAL-1018
题面：有一棵二叉苹果树，每个节点都有苹果，现在让你保留下来ｍ条枝头，问最多可以剩余多少个苹果
解法：
树状DP + 01背包
*/
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define maxn 1000
int f[maxn][maxn];
int as[maxn];
struct node{
	int u,v,w;
	int next;
}edge[maxn];
int head[maxn];
int cnt;
int n,m;
void init(){
	memset(head,-1,sizeof head);
	memset(f,0,sizeof f);
	cnt=0;
}
int max(int a,int b){
	if(a>b) return a;
	return b;
}
void add(int u,int v,int w){
	edge[cnt].u=u;
	edge[cnt].v=v;
	edge[cnt].w=w;
	edge[cnt].next=head[u];
	head[u]=cnt++;
}
void dfs(int u,int fa){
	for(int i=head[u];~i;i=edge[i].next){
		int v=edge[i].v;
		if(v!=fa){
			dfs(v,u);
			for(int k=m;k>=0;k--){
				for(int j=1;j<=k;j++){
          if(f[u][k]<f[u][k-j]+f[v][j-1]+edge[i].w)
          f[u][k]=f[u][k-j]+f[v][j-1]+edge[i].w;
				}
			}
		}
	}
}
int main(){
	int a,b,c;
	while(cin>>n>>m){
		init();
		for(int i=1;i<n;i++){
			cin>>a>>b>>c;
			add(a,b,c);
			add(b,a,c);
		}
		dfs(1,1);
		printf("%d\n",f[1][m]);
	}
	return 0;
}
