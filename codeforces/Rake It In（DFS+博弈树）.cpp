/*
Rake It In
ICPC Asia Nanning 2017
https://nanti.jisuanke.com/t/A1538
题面：
    Alice 和 Bob 玩游戏 在一个4x4 的方格上 每个人 每次选择2x2的区域
    将里面的四个值求和加到最后的分数当中(两个人共用一个分数)，然后逆时针翻转他们，
    Alice 想要分数尽量打 Bob 想要分数尽量小 两个人每次的选择 都是最优的
    求最后的分数
样例输入
    4
    1
    1 1 2 2
    1 1 2 2
    3 3 4 4
    3 3 4 4
    2
    1 2 3 4
    1 2 3 4
    1 2 3 4
    1 2 3 4
    3
    1 1 4 4
    4 4 1 1
    1 1 4 4
    1 4 1 4
    3
    1 2 3 4
    5 1 2 3
    4 5 1 2
    3 4 5 1
样例输出
    20
    40
    63
    71
解法：
    暴力DFS（博弈树？？）
*/
#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
int T,k;
int mp[5][5];
void solve_l(int x,int y){
  swap(mp[x][y],mp[x][y+1]);
  swap(mp[x][y+1],mp[x+1][y+1]);
  swap(mp[x+1][y+1],mp[x+1][y]);
}
void solve_r(int x,int y){
  swap(mp[x][y],mp[x+1][y]);
  swap(mp[x+1][y],mp[x+1][y+1]);
  swap(mp[x+1][y+1],mp[x][y+1]);
}
int sum(int i,int j){
  return mp[i][j]+mp[i][j+1]+mp[i+1][j]+mp[i+1][j+1];
}
int dfs(int d){
  if(d==k*2){
    int minn=INF;
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
        if(minn>sum(i,j)) minn=sum(i,j);
      }
    }
    return minn;
  }else if(d%2==1){
    int maxx=-INF;
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
        solve_l(i,j);
        int ans=sum(i,j)+dfs(d+1);
        maxx=max(maxx,ans);
        solve_r(i,j);
      }
    }
    return maxx;
  }else{
    int minn=INF;
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
        solve_l(i,j);
        int ans=sum(i,j)+dfs(d+1);
        minn=min(minn,ans);
        solve_r(i,j);
      }
    }
    return minn;
  }
}
int main(){
  cin>>T;
  while(T--){
    cin>>k;
    for(int i=0;i<4;i++){
      for(int j=0;j<4;j++){
        cin>>mp[i][j];
      }
    }
    cout<<dfs(1)<<endl;
  }
  return 0;
}
