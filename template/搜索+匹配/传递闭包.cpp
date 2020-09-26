/*
Treasure Exploration
POJ - 2594
https://vjudge.net/problem/POJ-2594
一个点可以被多个机器人经过（这就是和单纯的最小路径覆盖的区别）
最小路径覆盖+floyd传递闭包
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
#define maxn 510
int edge[maxn][maxn];
bool used[maxn];
int linker[maxn];
char mp[maxn][maxn];
int id[maxn][maxn];
void init(int n){
  memset(edge,0,sizeof edge);
}
bool dfs(int u,int n){
	for(int i=1;i<=n;i++){
		if(!used[i]&&edge[u][i]){
      int v=i;
			used[v]=true;
			if(linker[v]==-1||dfs(linker[v],n)){
				linker[v]=u;
				return true;
			}
		}
	}
	return false;
}
int hungary(int n){
	int ans=0;
	memset(linker,-1,sizeof linker);
	for(int u=1;u<=n;u++){
		memset(used,false,sizeof used);
		if(dfs(u,n)) ans++;
	}
	return ans;
}
void floyd(int n){
  int v,k;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      for(int k=1;k<=n;k++){
        if(edge[i][j]&&edge[j][k]){
          edge[i][k]=1;
        }
      }
    }
  }
}
int main(){
	int n,m;
  int u,v;
	while(~scanf("%d %d", &n, &m)&&(n+m)){
    init(n);
    for(int i=0;i<m;i++){
      scanf("%d %d", &u, &v);
      edge[u][v]=1;
    }
    floyd(n);
    printf("%d\n",n-hungary(n));
	}
}
