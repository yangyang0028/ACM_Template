/*
Dining
POJ - 3281
https://cn.vjudge.net/problem/POJ-3281
输入：
			第一行输入三个整数N, F, D
			接下来n行，每行先输入两个整数 Fi 和 Di，分别表示编号为 i 的牛喜欢的食物和饮料的数量，
			接下来的Fi个整数表示第i头牛喜欢的食物的编号，最后Di个整数表示第i头牛喜欢的饮料的编号。
输出：
			输出同时得到喜欢的食物和饮料的牛的数量的最大值。
样例输入：
		4 3 3
		2 2 1 2 3 1
		2 2 2 3 1 2
		2 2 1 3 1 2
		2 1 1 3 3
样例输出：
		3
解法：
		dinic算法
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
#define maxn 1000000
#define INF 0x3f3f3f3f
int n,m,k;
int a,b,c;
int B,E;
int dis[maxn];
struct node{
	int u,v,w;
	int next;
}edge[maxn];
int head[maxn];
int cnt;
void init(){
	memset(head,-1,sizeof head);
	cnt=0;
}
void add(int u,int v){
	edge[cnt].u=u;
	edge[cnt].v=v;
	edge[cnt].w=1;
	edge[cnt].next=head[u];
	head[u]=cnt++;

	edge[cnt].u=v;
	edge[cnt].v=u;
	edge[cnt].w=0;
	edge[cnt].next=head[v];
	head[v]=cnt++;
}
bool bfs(){
	memset(dis,-1,sizeof dis);
	queue<int> q;
	dis[B]=0;
	q.push(B);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=head[u];~i;i=edge[i].next){
			int v=edge[i].v;
			if(dis[v]==-1&&edge[i].w>0){
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
	return dis[E]!=-1;
}
int dfs(int u,int w){
	int ans=0;
	if(u==E) return w;
	for(int i=head[u];~i;i=edge[i].next){
		if(edge[i].w>0&&dis[edge[i].v]==dis[u]+1){
			int num=min(edge[i].w,w-ans);
			num=dfs(edge[i].v,num);
			ans+=num;
			edge[i].w-=num;
			edge[i^1].w+=num;
		}
	}
	if(!ans) dis[u]=-2;
	return ans;
}
int dinic(){
	int ans=0;
	int num;
	while(bfs()){
		while(num=dfs(B,INF)) ans+=num;
	}
	return ans;
}
int main(){
	cin>>n>>m>>k;
	init();
	B=0;
	E=n+n+m+k+1;
	for(int i=1;i<=m;i++){
		add(B,n+i);
	}
	for(int i=1;i<=k;i++){
		add(n+m+i,E);
	}
	for(int i=1;i<=n;i++){
		add(i,n+m+k+i);
		cin>>a>>b;
		while(a--){
			cin>>c;
			add(n+c,i);
		}
		while(b--){
			cin>>c;
			add(n+m+k+i,n+m+c);
		}
	}
	printf("%d\n", dinic());
	return 0;
}
