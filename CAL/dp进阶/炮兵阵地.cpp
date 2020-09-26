/*
炮兵阵地
P2704
https://www.luogu.org/problem/P2704
解法：
状压DP
由于当前行和前两行有关系，所以得用3维矩阵来保存一个状态下最多的炮兵个数
dp[i][curst][prest]表示当前第i行状态对curst，前一行状态为prest的最大炮兵数
dp[i][curst][prest]=max{dp[i-1][prest][preprest]
这样求到最后一行之后，答案就是最后一行所有状态中最大的那个。
程序初始化的时候需要对第一行
*/
#include <bits/stdc++.h>
using namespace std;
int dp[115][70][70];
int maze[105];
int sit[70];
int sta[70];
int n,m,len;
char str[111];
int main(){
  while(cin>>n>>m){
    memset(dp,0,sizeof dp);
    memset(maze,0,sizeof maze);
    memset(sit,0,sizeof sit);
    memset(sta,0,sizeof sta);
    for(int i=1;i<=n;i++){
      scanf("%s", str);
      for(int j=0;j<m;j++){
        if(str[j]=='H'){
          maze[i]+=(1<<j);
        }
      }
    }
    len=0;
    for(int i=0;i<(1<<m);i++){
      if(!(i&(i<<1)) && !(i&(i<<2))){
        int k=i,sum=0;
        while(k){
          if(k&1) sum++;
          k>>=1;
        }
        sta[++len]=sum;
        sit[len]=i;
      }
    }
    len++;
    for(int i=1;i<=len;i++){
      if(!(sit[i]&maze[1])){
        dp[1][i][1]=sta[i];
      }
    }
    for(int i=2;i<=n;i++){
      for(int j=1;j<=len;j++){
        if(sit[j]&maze[i]) continue;
        for(int k=1;k<=len;k++){
          if(sit[k]&sit[j]) continue;
          if(sit[k]&maze[i-1]) continue;
          for(int t=1;t<=len;t++){
            if(sit[t]&sit[j]) continue;
            if(sit[t]&sit[k]) continue;
            if(sit[t]&maze[i-2]) continue;
            dp[i][j][k]=max(dp[i][j][k],dp[i-1][k][t]+sta[j]);
          }
        }
      }
    }
    int ans=0;
    for(int i=1;i<=len;i++){
      for(int j=1;j<=len;j++){
        ans=max(ans,dp[n][i][j]);
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
