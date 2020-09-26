/*
Caocao's Bridges
HDU - 4738
https://vjudge.net/problem/HDU-4738
割边裸题（有重边）
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define maxn 1005
#define maxm 2000010
#define INF 0x3f3f3f3f
struct node{
	int u,v,w;
	int next;
}edge[maxm];
int ans;
int dfn[maxn],low[maxn];
int head[maxn];
int cnt,total;
void init(){
	memset(head,-1,sizeof head);
	memset(dfn,0,sizeof dfn);
	memset(low,0,sizeof low);
	cnt=0;
	total=0;
	ans=INF;
}
void add(int u,int v,int w){
	edge[cnt].u=u;
	edge[cnt].w=w;
	edge[cnt].v=v;
	edge[cnt].next=head[u];
	head[u]=cnt++;
}
void tarjan(int u,int id){
	dfn[u]=low[u]=++total;
	for(int i=head[u];~i;i=edge[i].next){
		if(i==(id^1)) continue;
		int v=edge[i].v;
		if(!dfn[v]){
			tarjan(v,i);
			low[u]=min(low[u],low[v]);
			if(low[v]>dfn[u]){
				ans=min(ans,edge[i].w);
			}
		}else low[u]=min(low[u],dfn[v]);
	}
}
int main(){
	int u,v,w;
	int n,m;
	while(~scanf("%d %d", &n, &m)&&(n+m)){
		init();
		int num=0;
		for(int i=0;i<m;i++){
			scanf("%d %d %d", &u, &v, &w);
			add(u,v,w);
			add(v,u,w);
		}
		for(int i=1;i<=n;i++)
			if(!dfn[i]){
				num++;
				tarjan(i,-1);
			}
		if(num>1) ans=0;
		else if(ans==0) ans=1;
		else if(ans==INF) ans=-1;
		printf("%d\n", ans);
	}
	return 0;
}
