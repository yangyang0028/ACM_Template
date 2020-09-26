/*
The Unique MST
POJ - 1679
https://cn.vjudge.net/problem/POJ-1679
题面：  判断最小生成树的唯一性
解法：  次小生成树
*/
#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 5000000
#define INF 0x3f3f3f3f
struct node{
  int u,v,w;
}edge[maxn];
int fa[maxn];
int a[maxn];
int n,m,cnt;
int root(int x){
  return fa[x]==x?x:fa[x]=root(fa[x]);
}
void unite(int x,int y){
  x=root(x);
  y=root(y);
  if(x!=y){
    fa[x]=y;
  }
}
bool alike(int x,int y){
  return root(x)==root(y);
}
bool cmp(node a,node b){
  return a.w<b.w;
}
int solve_1(){
  for(int i=0;i<=n;i++) fa[i]=i;
  cnt=0;
  int num=0,ans=0;
  for(int i=0;i<m;i++){
    if(!alike(edge[i].u,edge[i].v)){
      unite(edge[i].u,edge[i].v);
      num++;
      ans+=edge[i].w;
      a[cnt++]=i;
    }
    if(num==n-1) return ans;
  }
  return 0;
}
int solve_2(){
  int anss=INF;
  for(int k=0;k<cnt;k++){
    for(int i=0;i<=n;i++) fa[i]=i;
    int ans=0,num=0;
    for(int i=0;i<m;i++){
      if(i!=a[k] && !alike(edge[i].u,edge[i].v)){
        unite(edge[i].u,edge[i].v);
        num++;
        ans+=edge[i].w;
      }
      if(num==n-1){
        anss=min(ans,anss);
        break;
      }
    }
  }
  return anss;
}
int main(){
  int T;
  cin>>T;
  while(T--){
    cnt=0;
    cin>>n>>m;
    for(int i=0;i<m;i++){
      cin>>edge[i].u>>edge[i].v>>edge[i].w;
    }
    sort(edge,edge+m,cmp);
    int ans1=solve_1();
    int ans2=solve_2();
    if(ans1!=ans2){
      cout<<ans1<<endl;
    }else{
      cout<<"Not Unique!"<<endl;
    }
  }
  return 0;
}
