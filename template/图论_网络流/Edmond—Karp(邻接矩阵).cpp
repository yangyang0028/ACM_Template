#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#define maxn 1000
#define INF 0x3f3f3f
int cap[maxn][maxn];
int f[maxn][maxn];
int n,k;
int EK(){
  int per[maxn];
  int p[maxn];
  queue<int> q;
  int ans=0;
  memset(f,0,sizeof f);
  while(1){
    memset(p,0,sizeof p);
    p[1]=INF;
    q.push(1);
    while(!q.empty()){
      int u=q.front();
      q.pop();
      for(int v=1;v<=n;v++){
        if(!p[v]&&cap[u][v]>f[u][v]){
          per[v]=u;
          q.push(v);
          p[v]=min(p[u],cap[u][v]-f[u][v]);
        }
      }
    }
    if(p[n]==0) break;
    for(int u=n;u!=1;u=per[u]){
      f[per[u]][u]+=p[n];
      f[u][per[u]]-=p[n];
    }
    ans+=p[n];
  }
  return ans;
}
int main(){
  int u,v,w;
  while(~scanf("%d %d", &k, &n)){
    memset(cap,0,sizeof cap);
    for(int i=0;i<k;i++){
      scanf("%d %d %d", &u, &v, &w);
      cap[u][v]+=w;
    }
    printf("%d\n", EK());
  }
  return 0;
}
