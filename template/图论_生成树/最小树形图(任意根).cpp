#include <bits/stdc++.h>
using namespace std;
#define maxn 10010
#define INF 0x3f3f3f3f
struct Edge{
  int u,v,w;
}edge[maxn];
int pos;
int vis[maxn];
int id[maxn];
int in[maxn];
int pre[maxn];
int ZhuLiu(int root,int V,int E){//求解任意根最小树形图
  int res=0;
  while(true){
    for(int i=0;i<V;i++){
      in[i]=INF;
    }
    for(int i=0;i<E;i++){
      int u=edge[i].u;
      int v=edge[i].v;
      if(edge[i].w<in[v]&&u!=v){
        pre[v]=u;
        in[v]=edge[i].w;
        if(root==u) pos=i;
      }
    }
    for(int i=0;i<V;i++){
      if(i==root) continue;
      if(in[i]==INF) return -1;
    }
    int cnt=0;
    in[root]=0;
    memset(id,-1,sizeof id);
    memset(vis,-1,sizeof vis);
    for(int i=0;i<V;i++){
      res+=in[i];
      int v=i;
      while(vis[v]!=i&&id[v]==-1&&v!=root){
        vis[v]=i;
        v=pre[v];
      }
      if(v!=root&&id[v]==-1){
        for(int u=pre[v];u!=v;u=pre[u]){
          id[u]=cnt;
        }
        id[v]=cnt++;
      }
    }
    if(cnt==0) break;
    for(int i=0;i<V;i++){
      if(id[i]==-1) id[i]=cnt++;
    }
    for(int i=0;i<E;i++){
      int u=edge[i].u;
      int v=edge[i].v;
      edge[i].u=id[u];
      edge[i].v=id[v];
      if(id[u]!=id[v]) edge[i].w-=in[v];
    }
    V=cnt;
    root=id[root];
  }
  return res;
}
int main(){
  int n,m;
  while(~scanf("%d %d", &n, &m)){
    int sum=0;
    for(int i=0;i<m;i++){
      scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);
      edge[i].u++;
      edge[i].v++;
      sum+=edge[i].w;
    }
    sum++;
    for(int i=m;i<m+n;i++){
      edge[i].u=0;
      edge[i].v=i-m+1;
      edge[i].w=sum;
    }
    int res=ZhuLiu(0,n+1,m+n);
    if(res==-1)
        printf("impossible\n");
    else if(res-sum>=sum)//若差值大于sum说明结点0的出度不止为1,即原图不是连通图
        printf("impossible\n");
    else
        printf("%d %d\n",res-sum,pos-m);
    printf("\n");
  }
  return 0;
}
