/*
【模板】最小费用最大流
P3381
https://www.luogu.org/problem/P3381
题面：
		如题，给出一个网络图，以及其源点和汇点，
		每条边已知其最大流量和单位流量费用，
		求出其网络最大流和在最大流情况下的最小费用。
输入：
		第一行包含四个正整数N、M、S、T，分别表示点的个数、
		有向边的个数、源点序号、汇点序号。
		接下来M行每行包含四个正整数ui、vi、wi、fi，
		表示第i条有向边从ui出发，到达vi，边权为wi（即该边最大流量为wi），
		单位流量的费用为fi。
输出；
		一行，包含两个整数，依次为最大流量和在最大流量情况下的最小费用。
样例输入：
			4 5 4 3
			4 2 30 2
			4 3 20 3
			2 3 20 1
			2 1 30 9
			1 3 40 5
样例输出：
			50 280
说明；
			第一条流为4-->3，流量为20，费用为3*20=60。
			第二条流为4-->2-->3，流量为20，费用为（2+1）*20=60。
			第三条流为4-->2-->1-->3，流量为10，费用为（2+9+5）*10=160。
			故最大流量为50，在此状况下最小费用为60+60+160=280。
			故输出50 280。
*/
#include <bits/stdc++.h>
using namespace std;
#define maxn 1000000
#define INF 0x3f3f3f3f
int n,m;
struct node{
	int u,v,w,c;
	int next;
}edge[maxn];
int head[maxn];
int per[maxn];
int dis[maxn];
int q[maxn];
int cnt;
int s,t,ans;
void init(){
	memset(head,-1,sizeof head);
	cnt=0;
}
void add(int u,int v,int w,int c){
	edge[cnt].u=u;
	edge[cnt].v=v;
	edge[cnt].w=w;
	edge[cnt].c=c;
	edge[cnt].next=head[u];
	head[u]=cnt++;

	edge[cnt].u=v;
	edge[cnt].v=u;
	edge[cnt].w=-w;
	edge[cnt].c=0;
	edge[cnt].next=head[v];
	head[v]=cnt++;
}
bool spfa(){
	memset(per,-1,sizeof per);
	memset(dis,INF,sizeof dis);
	dis[s]=0;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=head[u];~i;i=edge[i].next){
			int v=edge[i].v;
			if(edge[i].c>0&&dis[u]+edge[i].w<dis[v]){
				dis[v]=dis[u]+edge[i].w;
				per[v]=i;
				q.push(v);
			}
		}
	}
	return dis[t]!=INF;
}
void MCMF(){
	int flow=0;
	int ans=0;
	while(spfa()){
		int u=t;
		int mini=INF;
		while(u!=s){
			if(edge[per[u]].c<mini){
				mini=edge[per[u]].c;
			}
			u=edge[per[u]].u;
		}
		flow+=mini;
		u=t;
		while(u!=s){
			edge[per[u]].c-=mini;
			edge[per[u]^1].c+=mini;
			u=edge[per[u]].u;
		}
		ans+=mini*dis[t];//mini 单位流量的代价，dis 表示流量
	}
	printf("%d %d\n" ,flow ,ans);
}
int main(){
	init();
	cin>>n>>m>>s>>t;
	int a,b,c,d;
	for(int i=0;i<m;i++){
		cin>>a>>b>>c>>d;
		add(a,b,d,c);
	}
	MCMF();
	return 0;
}
