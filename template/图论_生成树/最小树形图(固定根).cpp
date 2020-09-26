/*
Command Network
POJ - 3164
https://vjudge.net/problem/POJ-3164
题意：在有向图中找出最小生成树（最小树形图）
解法：朱,刘算法
算法思路：
1：确定一个根
2：找到除根外每一个点的最小入边，若这些边构成了环，则缩环成点，并将环内的每一个点的其他入边都减去环内的入边
3：重复步骤2直到没有环出现（构成了树）。
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
#define maxn 10000
#define INF 0x3f3f3f3f
int X[maxn],Y[maxn];
double IN[maxn];
int PRE[maxn];
int ID[maxn];
int VIS[maxn];
int n,m,cnt;
struct node{
  int u,v;
  double w;
}edge[maxn];
double dtc(int a,int b){
  return sqrt((double)((X[a]-X[b])*(X[a]-X[b])+(Y[a]-Y[b])*(Y[a]-Y[b])));
}
void add(int u,int v){
  edge[cnt].u=u;
  edge[cnt].v=v;
  edge[cnt++].w=dtc(u,v);
}
double zhuliu(int root){
  double ans=0;
  while(1){
    for(int i=1;i<=n;i++){
      IN[i]=INF;
    }
    for(int i=0;i<cnt;i++){
      if(edge[i].v==edge[i].u) continue;
      else if(IN[edge[i].v]>edge[i].w){
        PRE[edge[i].v]=edge[i].u;//记录每个点的最小入边
        IN[edge[i].v]=edge[i].w;//记录每个点的最小入边的边权
      }
    }
    for(int i=1;i<=n;i++){
      if(i!=root&&IN[i]==INF) return -1;
    }
    int num=0;
    memset(ID,0,sizeof ID);
    memset(VIS,0,sizeof VIS);
    //ID数组的初始化要与cnt记录的环数相匹配, 这里ID用0初始化, 则cnt从1开始记录, 也可以用-1初始化, 让cnt从0开始记录
    //初始化要注意, 因为这里的节点是从1开始编号的, 所以VIS数组中不会出现0, 可以用0来初始化, 若节点是从0开始编号, 则VIS中会有0, 不能用0初始化
    IN[root]=0;
    for(int i=1;i<=n;i++){
      ans+=IN[i];
      int v=i;
      while(!ID[v]&&v!=root&&VIS[v]!=i){
        VIS[v]=i;
        v=PRE[v];
      }
      if(v!=root&&!ID[v]){
        ID[v]=++num;
        for(int j=PRE[v];j!=v;j=PRE[j]){
          ID[j]=num;
        }
      }
    }
    if(!num) break;//没有环, 树成立
    for(int i=1;i<=n;i++){
      if(!ID[i]){
        ID[i]=++num;
      }
    }
    for(int i=0;i<m;i++){
      int x=edge[i].u,y=edge[i].v;
      edge[i].u=ID[x];
      edge[i].v=ID[y];
      if(ID[x]!=ID[y]){
        edge[i].w-=IN[y];
      }
    }
    n=num;
    root=ID[root];//维护新的点数目和根
  }
  return ans;
}
int main(){
  int u,v;
  while(~scanf("%d %d", &n, &m)){
    cnt=0;
    for(int i=1;i<=n;i++){
      scanf("%d%d", &X[i], &Y[i]);
    }
    for(int i=0;i<m;i++){
      scanf("%d%d", &u, &v);
      if(u!=v) add(u,v);
    }
    double ans=zhuliu(1);
    if (ans == -1) printf("poor snoopy\n");
    else printf("%.2f\n", ans);
  }
  return 0;
}
