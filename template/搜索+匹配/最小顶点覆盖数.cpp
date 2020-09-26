/*
Strategic Game
HDU - 1054
https://vjudge.net/problem/HDU-1054
二分图的最小顶点覆盖数
Knoig定理：二分图的最小顶点覆盖数=二分图的最大匹配数。
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
#define maxn 1510
vector<int> edge[maxn];
bool used[maxn];
int linker[maxn];
char mp[maxn][maxn];
int id[maxn][maxn];
void init(int n){
	for(int i=0;i<=n;i++){
		edge[i].clear();
	}
}
bool dfs(int u){
	for(int i=0;i<edge[u].size();i++){
		int v=edge[u][i];
		if(!used[v]){
			used[v]=true;
			if(linker[v]==-1||dfs(linker[v])){
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
		if(dfs(u)) ans++;
	}
	return ans;
}
int main(){
	int n,m;
  int u,v;
	while(~scanf("%d", &n)){
    init(n);
    for(int i=0;i<n;i++){
      scanf("%d:(%d)", &u, &m);
      while(m--){
        scanf("%d", &v);
        edge[u+1].push_back(v+1);
        edge[v+1].push_back(u+1);
      }
    }
    printf("%d\n",hungary(n)/2);
	}
}
