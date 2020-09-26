/*
Organising the Organisation
UVA - 10766
https://vjudge.net/problem/UVA-10766
生成树计数
Matrix−Tree定理:
对于一个无向图G，
它的生成树个数等于其
Kirchhoff矩阵任何一个n-1阶主子式的行列式的绝对值

	度数矩阵D：是一个N×N的矩阵，其中
	D[i][j]=0(i≠j)，D[i][i]=i号点的度数
	邻接矩阵A：是一个N×N的矩阵，其中
	A[i][i]=0,A[i][j]=A[j][i]=i,j之间的边数
	Kirchhoff矩阵K=D−A

	然后高斯消元优化为O(n3)
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll A[60][60];//邻接矩阵
ll K[60][60];//Kirchhoff矩阵
ll TreeSum(int n){
  ll ret=1;
  for(int i=1;i<=n;i++){
    if(!K[i][i]){
      bool b=0;
      for(int j=i+1;j<=n;j++){
        if(K[j][i]){
          b=1;
          for(int k=1;k<=n;k++){
            swap(K[i][k],K[j][k]);
          }
          ret=-ret;
          break;
        }
      }
      if(!b) return 0;
    }
    for(int j=i+1;j<=n;j++){
      while(K[j][i]){
        ll t=K[i][i]/K[j][i];
        for(int k=i;k<=n;k++){
          K[i][k]-=t*K[j][k];
          swap(K[i][k],K[j][k]);
        }
        ret=-ret;
      }
    }
    ret*=K[i][i];
  }
  return ret;
}
int main(){
  int n,m,k;
  while(~scanf("%d %d %d", &n, &m, &k)){
    memset(A,0,sizeof A);
    memset(K,0,sizeof K);
    for(int i=1;i<=m;i++){
      int x,y;
      scanf("%d %d", &x, &y);
      A[x][y]=A[y][x]=1;
    }
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        if(i!=j&&!A[i][j]){
          K[i][i]++;
          K[i][j]--;
        }
      }
    }
    printf("%lld\n", TreeSum(n-1));
  }
  return 0;
}
