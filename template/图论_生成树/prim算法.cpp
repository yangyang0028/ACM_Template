#include <iostream>
#include <algorithm>
#define maxn 1000
#define INF 0x3f3f3f3f
using namespace std;
int n,t;
int m[maxn][maxn];
int prim(){
  int ans=0;
  int min=INF;
  int d[maxn],color[maxn],b[maxn];
  for(int i=0;i<n;i++){
    color[i]=0;//记录改点是否遍历过
    d[i]=m[0][i];//记录初始每个顶点最短路径为到顶点的距离
    b[i]=0;//记录他的上一个节点
  }
  color[0]=1;
  for(int i=1;i<n;i++){
    min=INF;
    int u=-1;
    for(int j=0;j<n;j++){
      if(!color[j]&&d[j]<min){
        min=d[j];
        u=j;
      }
    }
    color[u]=1;
    cout<<u+1<<" "<<b[u]+1<<endl;
    ans+=m[u][b[u]];
    for(int j=1;j<n;j++){
      if(!color[j]&&m[u][j]<d[j]){
        d[j]=m[u][j];
        b[j]=u;
      }
    }
  }
  return ans;
}
int main(){
  n=6;
  for(int i=0;i<=n;i++){
    for(int j=0;j<=n;j++){
      m[i][j]=INF;
    }
  }
  m[0][1]=6,m[0][2]=1,m[0][3]=5;
  m[1][0]=6,m[1][2]=5,m[1][4]=3;
  m[2][0]=1,m[2][1]=5,m[2][3]=5,m[2][4]=6,m[2][5]=4;
  m[3][0]=5,m[3][2]=5,m[3][5]=2;
  m[4][1]=3,m[4][2]=6,m[4][5]=6;
  m[5][3]=2,m[5][2]=4,m[5][4]=6;
  cout<<prim()<<endl;
}
