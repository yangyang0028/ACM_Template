/*
MPI Maelstrom
POJ - 1502
https://cn.vjudge.net/problem/POJ-1502#author=weissice
题意：
      求从一台电脑发出的消息到最后一台电脑收到的最短时间
输入：
      n台计算机
      以矩阵形式输出相邻电脑通讯需要的时间，只有矩阵的下三角
样例输入：
      5
      50
      30 5
      100 20 50
      10 x x 10
样例输出：
      35
注意：
stoi()不是标准库里面的函数，会 Compile Error
*/
#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define INF 0x3f3f3f
#define maxn 110
int mp[maxn][maxn];
int dis[maxn];
int n,B=1;
int return_int(char *a){
  int ans=0;
  int len=strlen(a);
  for(int i=0;i<len;i++){
    ans=a[i]-'0'+ans*10;
  }
  return ans;
}
void init(){
  memset(mp,INF,sizeof mp);
  memset(dis,INF,sizeof dis);
}
void spfa(int B){
  dis[B]=0;
  queue<int> q;
  q.push(B);
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
  return ;
}
int main(){
  scanf("%d", &n);
  init();
  char a[10];
  for(int i=1;i<=n;i++){
    for(int j=1;j<i;j++){
      scanf("%s", a);
      if(a[0]!='x') mp[i][j]=mp[j][i]=return_int(a);
    }
  }
  spfa(B);
  int ans=0;
  for(int i=1;i<=n;i++){
    if(ans<dis[i]) ans=dis[i];
  }
  printf("%d\n", ans);
  return 0;
}
