#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
int mp[1005][1005];
int main(){
  int n,m,x;
scanf("%d %d %d", &n, &m, &x);
  int u,v,k;
  for(int i=0;i<=n;i++){
    for(int j=0;j<=n;j++){
      mp[i][j]=0x3f3f3f;
    }
  }
  for(int i=0;i<=n;i++){
    mp[i][i]=0;
  }
  for(int i=0;i<m;i++){
    scanf("%d %d %d", &u, &v, &k);
    mp[u][v]=k;
  }
  for(int k=1;k<=n;k++){
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        mp[i][j]=min(mp[i][k]+mp[k][j],mp[i][j]);
      }
    }
  }
  int ans=0;
  for(int i=1;i<=n;i++){
    ans=max(mp[i][x]+mp[x][i],ans);
  }
  printf("%d\n", ans);
  return 0;
}
