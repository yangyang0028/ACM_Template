/*
Maze Designer
ACM-ICPC 2018 徐州赛区网络预赛 J.
https://nanti.jisuanke.com/t/A2009
题面：有一个n*m的空地，可以在每个空地之间建墙，多个询问，问从某一点到另外一点的有且只有一条路并且建墙的总代价最小路径长度
思路：假设开始所有的墙都已经建好了，现在开始拆墙，保证拆的墙一定是最大的，然后算两点之间的距离
解法：拆墙就是找最大生成树，算两点之间的距离就哟个LCA 因为有多组询问
*/
#include <bits/stdc++.h>
using namespace std;
#define maxn 700000
struct node{
	int u,v,w;
	int next;
}edge[maxn],edgek[maxn];
int head[maxn],fa[maxn],deep[maxn];
int anc[maxn][25];
int cnt,cntk,n,m,k,q;
char c;
void init(){
	memset(head,-1,sizeof head);
	cnt=cntk=0;
}
void add(int u,int v,int w){
	edge[cnt].u=u;
	edge[cnt].v=v;
	edge[cnt].w=w;
	edge[cnt].next=head[u];
	head[u]=cnt++;
}
int root(int x){
    return fa[x]==x?x:fa[x]=root(fa[x]);
}
void unite(int x,int y){
    x=root(x);
    y=root(y);
    if(x!=y)
        fa[y]=x;
}
int alike(int x,int y){
    return root(x)==root(y);
}
bool cmp(node a,node b){
	return a.w>b.w;
}
void kruskal(){
	for(int i=0;i<=(n*m);i++) fa[i]=i;
	sort(edgek,edgek+cntk,cmp);
	int num=0;
	for(int i=0;i<cntk;i++){
		if(!alike(edgek[i].u,edgek[i].v)){
			unite(edgek[i].u,edgek[i].v);
			num++;
			add(edgek[i].u,edgek[i].v,edgek[i].w);
			add(edgek[i].v,edgek[i].u,edgek[i].w);
		}
	}
}
void dfs(int u,int fa){
	anc[u][0]=fa;
	for(int i=1;i<=22;i++){
		anc[u][i]=anc[anc[u][i-1]][i-1];
	}
	for(int i=head[u];~i;i=edge[i].next){
		int v=edge[i].v;
		if(v!=fa){
			deep[v]=deep[u]+1;
			dfs(v,u);
		}
	}
}
void solve(){
	deep[0]=1;
	dfs(0,0);
}
int lca(int x,int y) {
    if (deep[x]<deep[y]) swap(x,y);
    for (int i=22;i>=0;i--) {
        if (deep[y]<=deep[anc[x][i]]) {
            x=anc[x][i];
        }
    }
    if (x==y) return x;
    for (int i=22;i>=0;i--){
        if (anc[x][i]!=anc[y][i]) {
            x=anc[x][i];
            y=anc[y][i];
        }
    }
    return anc[x][0];
}
int main(){
	cin>>n>>m;
	init();
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>c>>k;
			if(c=='D'){
				edgek[cntk].u=i*m+j;
				edgek[cntk].v=i*m+m+j;
				edgek[cntk++].w=k;
			}
			cin>>c>>k;
			if(c=='R'){
				edgek[cntk].u=i*m+j;
				edgek[cntk].v=i*m+1+j;
				edgek[cntk++].w=k;
			}
		}
	}
	kruskal();
	solve();
	cin>>q;
	int u1,v1,u2,v2,u,v;
	while(q--){
		cin>>u1>>v1>>u2>>v2;
		u=(u1-1)*m+v1-1;
		v=(u2-1)*m+v2-1;
		cout<<deep[u]+deep[v]-2*deep[lca(u,v)]<<endl;
	}
	return 0;
}
