/*
Tram
POJ - 1847
https://cn.vjudge.net/problem/POJ-1847
题意：从A到B要选择开关的次数，开关默认指向第一个交叉点
输入：N个交叉点数，从A到B
      第i行第一个数表示第i个交叉节点可以连其他节点的个数，Ki表示连接的节点
样例输入：
      3 2 1
      2 2 3
      2 3 1
      2 1 2
样例输出：
      0
解法
建图，直接跑Floyed——warshall
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define maxn 110
#define INF 0x3f3f3f3f
int mp[maxn][maxn];
int N,A,B;
int main(){
  while(~ scanf("%d %d %d", &N, &A, &B)){
    memset(mp,INF,sizeof mp);
    for(int i=1;i<=N;i++){
      int n,m;
      scanf("%d", &n);
      if(n==0) continue;
      scanf("%d", &m);
      mp[i][m]=0;
      n--;
      while(n--){
        scanf("%d", &m);
        mp[i][m]=min(1,mp[i][m]);
        mp[m][i]=min(1,mp[m][i]);
      }
    }
    for(int k=1;k<=N;k++){
      for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
          if(mp[i][j]>mp[i][k]+mp[k][j])
            mp[i][j]=mp[i][k]+mp[k][j];
        }
      }
    }
    if(mp[A][B] == INF) printf("-1\n");
    else printf("%d\n", mp[A][B]);
  }
  return 0;
}
