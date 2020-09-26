#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
#define INF 0x3f3f3f
#define maxn 1005
using namespace std;
int n;
vector< pair<int,int> >mp[maxn];
int dijkstra(int b,int e){
  priority_queue< pair<int,int> > p;//有限队列存存最小节点（默认优先级较大）
  int d[maxn];//用于记录起点s到v的最短路
  bool color[maxn];//用来记录访问状态
  memset(d,INF,sizeof(d));
  memset(color,0,sizeof(color));
  d[b]=0;
  p.push(make_pair(0,b));//起点
  while(!p.empty()){
    pair<int,int> f = p.top();
    p.pop();
    int u=f.second;
    color[u]=1;//取出最小值，若不是最短路则忽略
    if(d[u] < f.first*(-1)) continue;
    for(int j=0; j<mp[u].size(); j++){
      int v=mp[u][j].first;
      if(color[v]==1) continue;
      if(d[v]>d[u]+mp[u][j].second){
        d[v]=d[u]+mp[u][j].second;
        p.push(make_pair(d[v]*(-1),v));//  priority_queue（默认优先级较大）所以要*-1；
      }
    }
  }
  return d[e];
}
int main(){
  cin>>n;
  int k,c,u,v;
  for(int i=0;i<n;i++){
    cin>>u>>k;
    for(int j=0;j<k;j++){
      cin>>v>>c;
      mp[u].push_back(make_pair(v,c));
    }
  }
  printf("%d\n", dijkstra(1,n));
  return 0;
}
