#include<iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;
int mp[5][5];
int m[5][5];
int ans=0;
struct node{
	int x,y;
}f[100];
int judge(int x,int y){
	if(mp[x][y]==ans){
		if(mp[x+1][y]==0&&x+1<5) mp[x+1][y]=ans-1;
		if(mp[x][y+1]==0&&y+1<5) mp[x][y+1]=ans-1;
		if(mp[x][y-1]==0&&y-1>=0) mp[x][y-1]=ans-1;
		if(mp[x-1][y]==0&&x-1>=0) mp[x-1][y]=ans-1;
	}
	return 0;
}
void bfs(){
	if(mp[4][4]!=0) return;
	ans--;
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			if(ans==mp[i][j]) judge(i,j);
	bfs();
}
int dfs(int x,int y){
	if(x==4&&y==4) return 1;
	if(mp[x][y-1]==mp[x][y]-1){
		f[-mp[x][y-1]].x=x,f[-mp[x][y-1]].y=y;
		if(dfs(x,y-1)==1) return 1;
	}
	if(mp[x][y+1]==mp[x][y]-1){
		f[-mp[x][y+1]].x=x,f[-mp[x][y+1]].y=y;
		if(dfs(x,y+1)==1) return 1;
	}
	if(mp[x+1][y]==mp[x][y]-1){
		f[-mp[x+1][y]].x=x,f[-mp[x+1][y]].y=y;
		if(dfs(x+1,y)==1) return 1;
	}
	if(mp[x-1][y]==mp[x][y]-1){
		f[-mp[x-1][y]].x=x,f[-mp[x-1][y]].y=y;
		if(dfs(x-1,y)==1) return 1;
	}
	return 0;
}
int main() {
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			scanf("%d", &mp[i][j]);
		}
	}
	mp[0][0]=-1;
	bfs();
	dfs(0,0);
	for(int i=2;i<=-ans+1;i++) printf("(%d, %d)\n", f[i].x, f[i].y);
	printf("(4, 4)\n");
	return 0;
}
