/*
Frogger
POJ - 2253
https://cn.vjudge.net/problem/POJ-2253#author=541607120101
题意：求一条1~2的路径 使得路径上的最大边权最小.
输入：石头数量 x y
样例输入：
      2
      0 0
      3 4
      3
      17 4
      19 4
      18 5
      0
样例输出：
      Scenario #1
      Frog Distance = 5.000

      Scenario #2
      Frog Distance = 1.414
思路：
dijkstra 计算边权最小即可
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <cmath>a
#define maxn 1005
#define INF 0x3f3f3f
using namespace std;
struct node{
  int x,y;
}num[maxn];
double mp[maxn][maxn];
double calc(int i, int j) {
    return (sqrt(pow((double)num[i].x-num[j].x, 2)+pow((double)num[i].y-num[j].y, 2)));
}
int n;
double dijkstra() {
    bool vis[maxn];
    double d[maxn];
    memset(vis, false, sizeof(vis));
    for(int i=0; i<n; i++) {
        d[i] = mp[0][i];
    }
    d[0] = 0;
    vis[0] = true;
    for(int i=0; i<n-1; i++) {
        double m = INF; int x;
        for(int y=0; y<n; y++) if(!vis[y] && m >= d[y]) m = d[x=y];
        vis[x] = true;
        for(int y=0; y<n; y++){
            if(!vis[y]) {
                double maxx = max(d[x], mp[x][y]);
                if(d[y] > maxx) d[y] = maxx;
            }
        }
    }
    return d[1];
}
int main(){
  int m=0;
  while(cin>>n,n){
    m++;
    for(int i=0;i<n;i++) cin>>num[i].x>>num[i].y;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        mp[i][j]=mp[j][i]=calc(i,j);
      }
      mp[i][i]=0;
    }
    printf("Scenario #%d\n", m);
    printf("Frog Distance = %.3lf\n\n", dijkstra());
  }
  return 0;
}
