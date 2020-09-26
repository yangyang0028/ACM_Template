#include <bits/stdc++.h>
using namespace std;
#define maxn 1020
#define INF 0x3f3f3f
int f[maxn][maxn];
int cap[maxn][maxn];
int pre[maxn];
int n,m,k;
int S,T;
bool bfs(){
  memset(pre,0,sizeof(pre));
  queue<int> q;
  q.push(S);
  pre[S]=1;
  while(!q.empty()){
    int a=q.front();
    q.pop();
    for(int i=1;i<=n;i++){
      if(!pre[i]&&cap[a][i]>f[a][i]){
        pre[i]=pre[a]+1;
        q.push(i);
      }
    }
  }
  return pre[T]!=0;
}
int dfs(int a,int cp){
  if(a==T) return cp;
  int num=cp;
  for(int i=1;i<=n;i++){
    if(pre[a]+1==pre[i]){
      if(cap[a][i]>f[a][i]){
        int minn=min(num,cap[a][i]-f[a][i]);
        int now_num=dfs(i,minn);
        f[a][i] += now_num;
        f[i][a] -= now_num;
        num-=now_num;
      }
    }
    if(num==0) break;
  }
  return cp-num;
}
int dinic(){
  int ans=0,num=0;
  while(bfs()){
    while(num=dfs(1,INF)){
      ans+=num;
    }
  }
  return ans;
}
int main(){
  int a,b,c;
  while(~scanf("%d", &k),k){
    scanf("%d %d", &n, &m);
    memset(cap,0,sizeof(cap));
    memset(f,0,sizeof(f));
    for(int i=0;i<k;i++){
      scanf("%d %d", &a, &b);
      cap[a+1][b+n+1]=1;
      cap[1][a+1]=1;
      cap[b+n+1][n+m+2]=1;
    }
    n=n+m+2;
    S=1,T=n;
    printf("%d\n", dinic());
  }
  return 0;
}
