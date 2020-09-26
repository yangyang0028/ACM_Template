/*
Oil Deposits
HDU - 1241
https://cn.vjudge.net/problem/HDU-1241
输入
			输入可能有多个矩形区域（即可能有多组测试）。
			每个矩形区域的起始行包含 n 和 m，表示行和列的数量，1<=n,m<=100，
			如果 m =0 表示输入的结束，接下来是n行，每行m个字符。
			每个字符对应一个小方格，并且要么是 '*'，代表没有油，要么是 '@'，表示有油。
输出
			对于每一个矩形区域，输出油藏的数量。
			两个小方格是相邻的，当且仅当他们水平或者垂直或者对角线相邻（即8个方向）。
样例输入：
			1 1
			*
			3 5
			*@*@*
			**@**
			*@*@*
			1 8
			@@****@*
			5 5
			****@
			*@@*@
			*@**@
			@@@*@
			@@**@
			0 0
样例输出：
			0
			1
			2
			2
*/
#include <bits/stdc++.h>
using namespace std;
char mp[105][105];
int n,m;
int dfs(int x,int y){
	if(mp[x][y]=='@'&&x<n&&x>=0&&y<m&&y>=0){//判断边界
		mp[x][y]='*';
		dfs(x+1,y),dfs(x-1,y),dfs(x,y+1),dfs(x,y-1);//向八个方向搜索
		dfs(x+1,y+1),dfs(x-1,y-1),dfs(x-1,y+1),dfs(x+1,y-1);
		return 1;
	}
	return 0;
}
int main() {
	while(~scanf("%d %d", &n, &m)&&(m||n)){
		memset(mp,0,sizeof(mp));
		for(int i=0;i<n;i++){
				scanf("%s", mp[i]);
		}
		int ans=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				ans+=dfs(i,j);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
