/*
玉米田Corn Fields
P1879
https://www.luogu.org/problem/P1879
题面：
有一个N×M的田地，0表示贫瘠，1表示肥沃，
只能在肥沃的土地上种玉米，
并且每一颗玉米都不能相邻，问有多少种方法
解法:
状压DP
*/
#include <bits/stdc++.h>
using namespace std;
#define maxn 10000
#define MOD 100000000
long long dp[15][maxn];
long long sit[maxn];
long long maze[maxn];
int n,m,a,len;
int main(){
  cin>>n>>m;
  for(int i=1;i<=n;i++){
    for(int j=0;j<m;j++){
      cin>>a;
      a=1-a;
      maze[i]+=(a<<j);
    }
  }
  len=0;
  for(int i=0;i<(1<<m);i++){
    if(!(i&(i<<1))){
      sit[++len]=i;
    }
  }
  dp[0][1]=1;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=len;j++){
      if(sit[j]&maze[i]) continue;
      for(int k=1;k<=len;k++){
        if(sit[k]&sit[j]) continue;
        if(sit[k]&maze[i-1]) continue;
        dp[i][j]+=dp[i-1][k];
        dp[i][j]%=MOD;
      }
    }
  }
  long long ans=0;
  for(int i=1;i<=len;i++){
    ans+=dp[n][i];
    ans%=MOD;
  }
  cout<<ans<<endl;
  return 0;
}
