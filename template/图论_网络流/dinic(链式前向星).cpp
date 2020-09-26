#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
#define maxn 1000000
#define INF 0x3f3f3f3f
int B,E;
int dis[maxn];
struct node{
	int u,v,w;
	int next;
}edge[maxn];
int head[maxn];
int cnt;
inline int read()//快读
{
    int x=0,f=1;char c=getchar();
    while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
    while(isdigit(c)){x=x*10+c-48;c=getchar();}
    return x*f;
}
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
  int n,m,k;
	scanf("%d %d %d", &n, &m, &k);
	init();
	B=0;
	E=n+m+1;
  int u,v;
  for(int i=1;i<=n;i++){
    add(0,i);
  }
  for(int i=1;i<=m;i++){
    add(i+n,E);
  }
	for(int i=0;i<k;i++){
    u=read();
    v=read();
    if(u>=1&&v>=1&&u<=n&&v<=m){
			add(u,v+n);
		}
  }
	printf("%d\n", dinic());
	return 0;
}
