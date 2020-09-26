/*
Swap
HDU - 2819
https://vjudge.net/problem/HDU-2819
二分图匹配+路径打印
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
#define maxn 310
int mp[maxn][maxn];
bool used[maxn];
int linker[maxn];
int a[maxn*maxn],b[maxn*maxn];
int n;
void init(){
	memset(mp,0,sizeof mp);
	memset(a,0,sizeof a);
	memset(b,0,sizeof b);
}
bool dfs(int u){
	for(int v=1;v<=n;v++){
		if(!used[v]&&mp[u][v]){
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
	for(int u=1;u<=n;u++){
		memset(used,false,sizeof used);
		if(dfs(u)) ans++;
	}
	return ans;
}
int main(){
	while(~scanf("%d", &n)){
		init();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				scanf("%d", &mp[i][j]);
			}
		}
		int ans=hungary();
		if(ans<n){
			printf("-1\n");
			continue;
		}
		int num=0;
		for(int i=1;i<=n;i++){
			int j;
			for(j=i;j<=n;j++)
				if(linker[j]==i) break;
			if(j!=i){
				a[num]=i;
				b[num++]=j;
				swap(linker[i],linker[j]);
			}
		}
		printf("%d\n", num);
		for(int i=0;i<num;i++){
			printf("C %d %d\n", a[i], b[i]);
		}
	}
}
