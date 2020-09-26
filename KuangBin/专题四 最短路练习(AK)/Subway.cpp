/*
Subway
POJ - 2502
https://cn.vjudge.net/problem/POJ-2502#author=0
题面： 从家到学校，可以选择坐（40km/s）地铁或（10km/s）步行，求最短时间
输入  第一行 起点坐标，终点坐标
      下面是每个地铁经过的站 知道-1 -1结束
样例输入：
      0 0 10000 1000
      0 200 5000 200 7000 200 -1 -1
      2000 600 5000 600 10000 600 -1 -1
样例输出：
      21
解法：
      建图，跑一遍Floyed-Warshall
*/
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
#define maxn 1000
#define INF 0x3f3f3f
struct node{
  double x,y;
  int kid;
}poi[maxn];
double mp[maxn][maxn];
int cnt=0;
void build(double x,double y,int kid){
  poi[cnt].x=x;
  poi[cnt].y=y;
  poi[cnt].kid=kid;
  cnt++;
}
int main(){
  double x,y;
  int kid=0;
  scanf("%lf %lf", &x, &y);
  build(x,y,kid++);
  scanf("%lf %lf", &x, &y);
  build(x,y,kid++);
  while(~scanf("%lf %lf", &x, &y)) {
    if(x<0&&y<0){
      kid++;
      continue;
    }
    build(x,y,kid);
  }
  for(int i=0;i<cnt;i++){
    for(int j=0;j<cnt;j++){
      mp[i][j]=sqrt((poi[i].x-poi[j].x)*(poi[i].x-poi[j].x)+(poi[i].y-poi[j].y)*(poi[i].y-poi[j].y))/(10000.0/60);
    }
  }
  for(int i=0;i<cnt-1;i++){
    if(poi[i].kid==poi[i+1].kid){
      mp[i][i+1]=mp[i+1][i]=sqrt((poi[i].x-poi[i+1].x)*(poi[i].x-poi[i+1].x)+(poi[i].y-poi[i+1].y)*(poi[i].y-poi[i+1].y))/(40000.0/60);
    }
  }
  for(int k=0;k<cnt;k++){
    for(int i=0;i<cnt;i++){
      for(int j=0;j<cnt;j++){
        mp[i][j]=min(mp[i][k]+mp[k][j],mp[i][j]);
      }
    }
  }
  printf("%d\n", (int)(mp[0][1]+0.5));
  return 0;
}
