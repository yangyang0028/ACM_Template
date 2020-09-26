/*
Monkey and Banana
HDU - 1069
https://cn.vjudge.net/problem/HDU-1069
题面：有n种无限多个正方体，问要叠起来最大是多少，叠起来的条件是上面的长宽都要小于下面的长宽
解法：DP
*/
#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 10000
struct node{
  int x,y,z;
  int ans;
}dp[maxn];
bool cmp(node a,node b){
  if(a.x!=b.x) return a.x<b.x;
  return a.y<b.y;
}
int cnt;
int main(){
  int n;
  int x,y,z;
  int T=0;
  while(cin>>n && n){
    cnt=0;
    for(int i=0;i<n;i++){
      cin>>x>>y>>z;
      dp[cnt++]=(node){x,y,z,z};
      dp[cnt++]=(node){x,z,y,y};
      dp[cnt++]=(node){y,x,z,z};
      dp[cnt++]=(node){z,x,y,y};
      dp[cnt++]=(node){z,y,x,x};
      dp[cnt++]=(node){y,z,x,x};
    }
    int ans=0;
    sort(dp,dp+cnt,cmp);
    for(int i=0;i<cnt;i++){
      for(int j=0;j<i;j++){
        if(dp[i].x>dp[j].x&&dp[i].y>dp[j].y){
          dp[i].ans=max(dp[i].ans,dp[j].ans+dp[i].z);
          ans=max(dp[i].ans,ans);
        }
      }
    }
    cout<<"Case "<<++T<<": maximum height = "<<ans<<endl;
  }
  return 0;
}
