/*
Networking
POJ - 1287
https://cn.vjudge.net/problem/POJ-1287
最短生成树裸题
*/
#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 100000
struct node{
  int u,v,w;
}edge[maxn];
int fa[maxn];
int cnt;
int n,m;
void init(){
  cnt=0;
}
void add(int u,int v,int w){
  edge[u].u=u;
  edge[u].v=v;
  edge[u].w=w;
}
bool cmp(node a,node b){
  return a.w<b.w;
}
int root(int x){
  return fa[x]==x?x:fa[x]=root(fa[x]);
}
void unite(int x,int y){
  x=root(x);
  y=root(y);
  if(x!=y) fa[y]=x;
}
bool ailke(int x,int y){
  return root(x)==root(y);
}
int solve(){
  sort(edge,edge+m,cmp);
  for(int i=0;i<=n;i++) fa[i]=i;
  int ans=0,num=0;
  for(int i=0;i<m;i++){
    if(!ailke(edge[i].u,edge[i].v)){
      //cout<<edge[i].u<<" "<<edge[i].v<<"  "<<edge[i].w<<endl;
      unite(edge[i].u,edge[i].v);
      ans+=edge[i].w;
      num++;
    }
    if(num==n-1) break;
  }
  return ans;
}
int main(){
  while(cin>>n&&n){
    init();
    cin>>m;
    for(int i=0;i<m;i++){
      cin>>edge[i].u>>edge[i].v>>edge[i].w;
    }
    cout<<solve()<<endl;
  }
}
