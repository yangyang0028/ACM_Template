/*
Magical Girl Haze
ACM-ICPC 2018 南京赛区网络预赛 L.
https://nanti.jisuanke.com/t/A1958
题意：n个点m条边 至多K条边的边权变为0 从1到n的最短路
解法：
分层图最短路
DP+spfa+优先队列
*/
#include <bits/stdc++.h>
using namespace std;
#define maxn 1000000
#define ll long long
struct node{
	int u,v,w;
	int next;
}edge[maxn];
struct node1{
	int n,m;
	friend bool operator<(node1 a,node1 b)
	{
		return a.n>b.n;//按x从小到大排
	}
};
int head[maxn];
int dis[maxn][12];
int cnt,n,m,k;
void init(){
	memset(head,-1,sizeof head);
	memset(dis,0x3f3f3f3f,sizeof dis);
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
	priority_queue<node1> q;
	q.push(node1{1,0});
	dis[1][0]=0;
	while(!q.empty()){
		node1 st=q.top();
		q.pop();
		for(int i=head[st.n];~i;i=edge[i].next){
			int v=edge[i].v;
			if(dis[v][st.m]>dis[st.n][st.m]+edge[i].w){
				dis[v][st.m]=dis[st.n][st.m]+edge[i].w;
				q.push(node1{v,st.m});
			}
			if(st.m+1<=k){
				if(dis[v][st.m+1]>dis[st.n][st.m]){
					dis[v][st.m+1]=dis[st.n][st.m];
					q.push(node1{v,st.m+1});
				}
			}
		}
	}
}
int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		init();
		int u,v,w;
		scanf("%d %d %d", &n, &m, &k);
		for(int i=0;i<m;i++){
			scanf("%d %d %d", &u, &v, &w);
			add(u,v,w);
		}
		spfa();
		printf("%d\n", dis[n][k]);
	}
	return 0;
}
