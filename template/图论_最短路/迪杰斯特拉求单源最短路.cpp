#include <iostream>
#include <string.h>
using namespace std;
const int maxn=100;
const int INF=0x3f3f3f;
int n,mp[maxn][maxn];//邻接矩阵 记录从u->v的边权
int dijkstra(int b,int e){//从1~n的最短路遍历
  int minv;
  int d[maxn];//用于记录起点s到v的最短路
  bool color[maxn];//用来记录访问状态
  memset(d,INF,sizeof(d));
  memset(color,0,sizeof(color));
  d[b]=0;
  while(1){
    minv=INF;
    int u=-1;
    for(int i=1;i<=n;i++){//在当前节点下寻找边权最小的子节点
      if(minv > d[i]&&color[i]!=1){
        u=i;
        minv=d[i];
      }
    }
    if(u==-1) break;//遍历完整棵树
    color[u]=1;//表明u进入目前所生成的最短路，不可修改
    for(int v=1;v<=n;v++){//存u的最短路
      if(color[v]!=1&&mp[u][v]!=INF){
        if(d[v]>d[u]+mp[u][v]){
          d[v]=d[u]+mp[u][v];
        }
      }
    }
  }
  return d[e];
}
int main(){
  cin>>n;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      mp[i][j]=INF;
    }
  }
  int k,c,u,v;
  for(int i=0;i<n;i++){
    cin>>u>>k;
    for(int j=0;j<k;j++){
      cin>>v>>c;
      mp[u][v]=c;
    }
  }
  printf("%d\n", dijkstra(1,n));
}
