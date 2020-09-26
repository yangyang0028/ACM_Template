/*
Courses
HDU - 1083
https://vjudge.net/problem/HDU-1083
最大匹配裸题
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
#define maxn 310
vector<int> edge[maxn];
bool used[maxn];
int linker[maxn];
int p,n;
void init(){
	int num=max(n,p);
	for(int i=0;i<=num;i++){
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
int hungary(){
	int ans=0;
	memset(linker,-1,sizeof linker);
	for(int u=1;u<=p;u++){
		memset(used,false,sizeof used);
		if(dfs(u)) ans++;
	}
	return ans;
}
int main(){
	int T;
	int m,u,v;
	scanf("%d", &T);
	while(T--){
		init();
		scanf("%d %d", &p, &n);
		for(int u=1;u<=p;u++){
			scanf("%d", &m);
			while(m--){
				scanf("%d", &v);
				edge[u].push_back(v);
			}
		}
		int ans=hungary();
		if(ans==p)printf("YES\n");
		else printf("NO\n");
	}
}
