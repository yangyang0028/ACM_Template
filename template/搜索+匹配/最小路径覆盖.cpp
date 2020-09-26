/*
Air Raid
HDU - 1151
https://vjudge.net/problem/HDU-1151
最小路径覆盖
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
  int T;
  cin>>T;
	while(T--){
    scanf("%d %d", &n, &m);
    init(n);
    for(int i=0;i<m;i++){
      scanf("%d %d", &u, &v);
      edge[u].push_back(v);
    }
    printf("%d\n",n-hungary(n));
	}
}
