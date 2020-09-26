/*
0 or 1
HDU - 4370
https://cn.vjudge.net/problem/HDU-4370#author=0
题意： 给你一个n*n矩阵，让你新建一个只有0和1的n*n矩阵，满足新建的这个矩阵与原来那个矩阵对应位置相乘最小，
      新建的这个矩阵满足一下条件
      1.X12+X13+...X1n=1
      2..X1n+X2n+...Xn-1n=1
      3.∑Xki =∑Xij
输入：n 和 n*n的矩阵
样例输入：
      4
      1 2 4 10
      2 0 1 1
      2 2 0 5
      6 3 1 2
样例输出：
      3
思路：
1.X12+X13+...X1n=1 于是1号节点的出度为1
2..X1n+X2n+...Xn-1n=1 于是n号节点的入度为1
3.∑Xki =∑Xij 于是2~n-1号节点的入度必须等于出度
所以建图，跑最短路，或者是最小环
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#define maxn 310
#define INF 0x3f3f3f3f
int mp[maxn][maxn];
int dis[maxn];
int n;
void spfa(int st){
  queue<int> q;
  for(int i=1;i<=n;i++){
    if(i==st){
      dis[i]=INF;
    }else{
      dis[i]=mp[st][i];
      q.push(i);
    }
  }
  while(!q.empty()){
    int u=q.front();
    q.pop();
    for(int i=1;i<=n;i++){
      if(dis[i]>dis[u]+mp[u][i]){
        dis[i]=dis[u]+mp[u][i];
        q.push(i);
      }
    }
  }
}
int main(){
  while(~scanf("%d", &n)){
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        scanf("%d", &mp[i][j]);
      }
    }
    spfa(1);
    int ans=dis[n];
    int c1=dis[1];
    spfa(n);
    int c2=dis[n];
    printf("%d\n", min(ans,c1+c2));
  }
  return 0;
}
