/*
【模板】二分图匹配
P3386
https://www.luogu.org/problem/P3386
题面：
			给定一个二分图，结点个数分别为n,m，边数为e，求二分图最大匹配
输入
			第一行，n,m,e
			第二至e+1行，每行两个正整数u,v，表示u,v有一条连边
输出
			共一行，二分图最大匹配
*/
#include <bits/stdc++.h>
using namespace std;
#define maxn 5000000
int con_u[maxn];
int con_v[maxn];
bool vis[maxn];
struct node{
	int u,v;
	int next;
}edge[maxn];
int head[maxn];
int cnt;
int n,m,e;
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
int dfs(int u){
	for(int i=head[u];~i;i=edge[i].next){
		int v=edge[i].v;
		if(!vis[v]){
			vis[v]=true;
			if(con_v[v]==-1||dfs(con_v[v])){
				con_u[u]=v;
				con_v[v]=u;
				return 1;
			}
		}
	}
	return 0;
}
int KM(){
	int ans=0;
	memset(con_u,-1,sizeof con_u);
	memset(con_v,-1,sizeof con_v);
	for(int i=1;i<=n;i++){
		memset(vis,false,sizeof vis);
		ans+=dfs(i);
	}
	return ans;
}
int main(){
	cin>>n>>m>>e;
	init();
	int x,y;
	for(int i=1;i<=e;i++){
		cin>>x>>y;
		if(x>=1&&y>=1&&x<=n&&y<=m){
			add(x,y);
		}
	}
	cout<<KM()<<endl;
	return 0;
}
