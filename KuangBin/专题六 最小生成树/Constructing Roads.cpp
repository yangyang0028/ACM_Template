/*
Constructing Roads
POJ - 2421
https://cn.vjudge.net/problem/POJ-2421#author=sunyuhan1998
题面：
    还是最小生成树，但开始就已经有部分路，要求建剩下的路最小的代价
解法：
    最小生成树
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
int n,q;
void init(){
  for(int i=0;i<=n;i++){
    fa[i]=i;
  }
}
int root(int x){
  return fa[x]==x?x:fa[x]=root(fa[x]);
}
void unite(int x, int y){
  x=root(x);
  y=root(y);
  if(x!=y) fa[x]=y;
}
bool cmp(node a,node b){
  return a.w<b.w;
}
bool ailke(int x,int y){
  return root(x)==root(y);
}
int solve(int num){
  sort(edge,edge+cnt,cmp);
  int ans=0;
  for(int i=0;i<cnt;i++){
    if(!ailke(edge[i].u,edge[i].v)){
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
   for(int i=1;i<=n;i++){
     for(int j=1;j<=n;j++){
       edge[cnt].u=i;
       edge[cnt].v=j;
       cin>>edge[cnt++].w;
     }
   }
   int u,v;
   int num=0;
   cin>>q;
   for(int i=0;i<q;i++){
     cin>>u>>v;
     if(!ailke(u,v)) num++;
     unite(u,v);
   }
   cout<<solve(num)<<endl;
  return 0;
}
