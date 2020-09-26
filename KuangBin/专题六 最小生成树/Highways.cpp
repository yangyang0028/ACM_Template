/*
Highways
POJ - 1751
https://cn.vjudge.net/problem/POJ-1751
最小生成树裸题
*/
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define maxn 5000000
struct node{
	int x,y;
}node[maxn];
struct edge_{
	int u,v;
	double w;
}edge[maxn];
int fa[maxn];
int cnt;
int n,m;
void init(){
	for(int i=0;i<=n;i++){
		fa[i]=i;
	}
	cnt=0;
}
int root(int x){
	return fa[x]==x?x:fa[x]=root(fa[x]);
}
void unite(int x,int y){
	x=root(x);
	y=root(y);
	if(x!=y) fa[x]=y;
}
bool ailke(int x,int y){
	return root(x)==root(y);
}
bool cmp(edge_ a,edge_ b){
  return a.w<b.w;
}
int solve(int num){
  sort(edge,edge+cnt,cmp);
  int ans=0;
  for(int i=0;i<cnt;i++){
    if(!ailke(edge[i].u,edge[i].v)){
			cout<<edge[i].u<<" "<<edge[i].v<<endl;
      unite(edge[i].u,edge[i].v);
      ans+=edge[i].w;
      num++;
    }
    if(num==n-1) break;
  }
  return ans;
}
int main(){
	cin>>n;
	init();
	int u,v;
	for(int i=1;i<=n;i++){
		cin>>node[i].x>>node[i].y;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			edge[cnt].u=i;
			edge[cnt].v=j;
			edge[cnt++].w=sqrt((node[i].x-node[j].x)*(node[i].x-node[j].x)+(node[i].y-node[j].y)*(node[i].y-node[j].y));
		}
	}
	cin>>m;
	int num;
	for(int i=0;i<m;i++){
		cin>>u>>v;
		if(!ailke(u,v)) num++;
		unite(u,v);
	}
	solve(num);
}
