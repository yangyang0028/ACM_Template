#include <bits/stdc++.h>
using namespace std;
#define maxn 100000
int n,m;
int u,v,k;
int fa[maxn];
void init(){
    for(int i=0;i<=n;i++)
        fa[i]=i;
}
int root(int x){
  return fa[x]==x?x:fa[x]=root(fa[x]);
}
void unite(int u,int v){
    u=root(u);
    v=root(v);
    if(u!=v)
        fa[v]=u;
}
bool ailke(int u,int v){
    return root(u)==root(v);
}
int main(){
  cin>>n>>m;
  init();
  for(int i=0;i<m;i++){
    cin>>k>>u>>v;
    if(k==1) unite(u,v);
    if(k==2){
      if(ailke(u,v)){
        cout<<"Y"<<endl;
      }else{
        cout<<"N"<<endl;
      }
    }
  }
  return 0;
}
