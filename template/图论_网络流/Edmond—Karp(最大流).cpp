#include <bits/stdc++.h>
using namespace std;
#define maxn 1000
#define INF 0x3f3f3f
int cap[maxn][maxn];
int f[maxn][maxn];
int pre[maxn],p[maxn];
int k,m,n;
int EK(int s,int t){
  int v,u;
  int ans=0;
  queue<int> q;
  memset(f,0,sizeof(f));
  while(1){
    memset(p,0,sizeof(p));
    p[s]=INF;
    q.push(s);
    while(!q.empty()){
      u=q.front();
      q.pop();
      for(v=1 ;v<=n ;v++){
        if(!p[v]&&cap[u][v]>f[u][v]){
          pre[v]=u;
          q.push(v);
          p[v]=min(p[u],cap[u][v]-f[u][v]);
        }
      }
    }
    if(p[t]==0) break;
    for(u=t;u!=s;u=pre[u]){
      f[pre[u]][u] += p[t];
      f[u][pre[u]] -= p[t];
    }
    ans+=p[t];
  }
  return ans;
}
int main(){
  int a,b,c;
  while(~scanf("%d %d", &k, &n)){
    memset(cap,0,sizeof(cap));
    for(int i=0;i<k;i++){
      scanf("%d %d %d", &a, &b, &c);
      cap[a][b]+=c;
    }
    printf("%d\n", EK(1,n));
  }
  return 0;
}
