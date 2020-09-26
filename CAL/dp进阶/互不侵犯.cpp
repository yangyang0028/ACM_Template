/*
互不侵犯King
HYSBZ - 1087
https://cn.vjudge.net/problem/HYSBZ-1087
题意：n×n的矩阵里放k个国王，每个国王的周边8个格子不能放其他国王，问有有多少方法
解法：
f[i][j][l] 表示前i行状态为j上有k个国王时的最优解
状压dp，用数字的二进制来表示这一行上的国王分布
然后记录在一行中，可以有效表达国王分布的数字并记录
设当前行的状态为j，上一行的状态为x，可以得到下面的转移方程：
f[i][j][l]=f[i-1][x][l-sta[x]]
*/
#include <algorithm>
#include <iostream>
using namespace std;
#define maxn 2005
long long sit[maxn];//记录一行中所有的合法状态
long long sta[maxn];//记录合法状态下的国王数
long long f[15][maxn][105];//f[i][j][l] 表示前i行状态为j上有k个国王时的最优解
int n, k, cnt;
void dfs(int x,int num,int cur){//x表示这一行的状态 num记录国王数 cur记录状态长度
  if(cur>=n){
    sit[++cnt]=x;
    sta[cnt]=num;
    return ;
  }
  dfs(x,num,cur+1);//cur位置不放国王
  dfs(x+(1<<cur),num+1,cur+2);//cur位置放国王，与它相邻的位置不能再放国王
}
int main(){
  cin>>n>>k;
  dfs(0,0,0);//先预处理一行的所有合法状态
  for(int i=1; i<=cnt;i++) f[1][i][sta[i]]++;
  for(int i=2;i<=n;i++){
    for(int j=1;j<=cnt;j++){
      for(int l=1;l<=cnt;l++){
        if(sit[j]&sit[l]) continue;
        if((sit[j]<<1)&sit[l]) continue;
        if(sit[j]&(sit[l]<<1)) continue;
        //排除不合法转移
        for(int p=sta[j];p<=k;p++){
          f[i][j][p]+=f[i-1][l][p-sta[j]];
        }
      }
    }
  }
  long long ans=0;
  for(int i=1;i<=cnt;i++) ans+=f[n][i][k];
  cout<<ans<<endl;
  return 0;
}
