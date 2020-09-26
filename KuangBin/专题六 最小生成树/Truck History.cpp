/*
Truck History
POJ - 1789
https://cn.vjudge.net/problem/POJ-1789#author=jack10086
题面：
    给定N个字符串，某个字符串转为另一个字符串的花费为他们每一位不相同的字符数。 求最小花费Q。
解法:
kruskal算法对于稠密图来说比较慢
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
#define maxn 4000010
struct node{
  int u,v,w;
}edge[maxn];
int fa[2100];
int cnt;
int n;
void init(){
  cnt=0;
  for(int i=0;i<=n;i++){
    fa[i]=i;
  }
}
char c[2100][8];
void read(){
  for(int i=0;i<n;i++){
    scanf("%s", c[i]);
  }
  int num;
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      edge[cnt].u=i;
      edge[cnt].v=j;
      num=0;
      for(int k=0;k<7;k++){
        if(c[i][k]!=c[j][k]) num++;
      }
      edge[cnt++].w=num;
    }
  }
}
int root(int x){
  return fa[x]==x?x:fa[x]=root(fa[x]);
}
void unite(int x, int y){
  x=root(x);
  y=root(y);
  if(x!=y) fa[x]=y;
}
bool ailke(int x,int y){
  return root(x)==root(y);
}
bool cmp(node a,node b){
  return a.w<b.w;
}
int solve(int num){
  sort(edge,edge+cnt,cmp);
  int ans=0;
  for(int i=0;i<cnt;i++){
    if(!ailke(edge[i].u,edge[i].v)){
      unite(edge[i].u,edge[i].v);
      ans+=edge[i].w;
      num++;
    }
    if(num==n-1) break;
  }
  return ans;
}
int main(){
  while(cin>>n&&n){
    init();
    read();
    printf("The highest possible quality is 1/%d.\n", solve(0));
  }
  return 0;
}
/*
Truck History
POJ - 1789
https://cn.vjudge.net/problem/POJ-1789#author=jack10086
题面：
    给定N个字符串，某个字符串转为另一个字符串的花费为他们每一位不相同的字符数。 求最小花费Q。
解法:
kruskal算法对于稠密图来说比较慢
prim算法来说比较快
但我看时间差的真心不多。。。
不知道大佬们是怎么优化的
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#define maxn 2010
#define INF 0x3f3f3f3f
using namespace std;
int n,t;
int m[maxn][maxn];
char c[maxn][8];
int cnt;
void init(){
  cnt=0;
  memset(m,INF,sizeof m);
}
void read(){
  for(int i=0;i<n;i++){
    scanf("%s", c[i]);
  }
  int num;
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      num=0;
      for(int k=0;k<7;k++){
        if(c[i][k]!=c[j][k]) num++;
      }
      m[i][j]=num;
      m[j][i]=num;
    }
  }
}
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
  while(cin>>n&&n){
    init();
    read();
    printf("The highest possible quality is 1/%d.\n", prim());
  }
  return 0;
}
