/*
Cow Contest
POJ - 3660
https://cn.vjudge.net/problem/POJ-3660#author=freeloop
题意 ：从n的同学参加比赛,有m条实力信息，问最后有多少名同学可以确定他的排名，保证合法
输入 ：n   m
      A > B
样例输入：
      5 5
      4 3
      4 2
      3 2
      1 2
      2 5
样例输出：
      2
解法:
(Floyed-Warshall)传递闭包
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define maxn 110
#define INF 0x3f3f3f
int mp[maxn][maxn];
int n,t;
void init(){
  memset(mp,0,sizeof mp);
}
int main(){
  scanf("%d %d", &n, &t);
  init();
  int u,v;
  for(int i=0;i<t;i++){
    scanf("%d %d", &u, &v);
    mp[u][v]=1;
  }
  for(int k=1;k<=n;k++){
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
          if(mp[i][k]&&mp[k][j]) mp[i][j]=1;
      }
    }
  }
  int ans=0;
  for(int i=1;i<=n;i++){
    int j;
    for(j=1;j<=n;j++){
      if(i==j) continue;
      if(!mp[i][j]&&!mp[j][i]) break;
    }
    if(j>n) ans++;
  }
  printf("%d\n", ans);
  return 0;
}
