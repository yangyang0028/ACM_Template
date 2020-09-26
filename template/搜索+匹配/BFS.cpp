/*
Robot
POJ - 1376
https://cn.vjudge.net/problem/POJ-1376
题意:
      求机器人从起点到终点的一条用时最短的路径，机器人可以执行如下步骤
      向机器人面对的方向走1,2,3步
      向左转，向右转
      每个步骤耗时为1
样例输入：
      9 10
      0 0 0 0 0 0 1 0 0 0
      0 0 0 0 0 0 0 0 1 0
      0 0 0 1 0 0 0 0 0 0
      0 0 1 0 0 0 0 0 0 0
      0 0 0 0 0 0 1 0 0 0
      0 0 0 0 0 1 0 0 0 0
      0 0 0 1 1 0 0 0 0 0
      0 0 0 0 0 0 0 0 0 0
      1 0 0 0 0 0 0 0 1 0
      7 2 2 7 south
      0 0
样例输出：
      12
思路：
      这道题的坑
      只能向左转向右转，不能向后转
      若第一步走不了，第二步和第三步一定走不了
      机器人很胖，不能走边界
      障碍物是障碍物，路线是路线
      有可能起始位置有障碍物
      有可能终点位置有障碍物
      若没有路径一定要跳出来
      障碍物不可以走，但走过的路还是可以走的
      有可能起始位置就是终点位置
*/
#include <cstdio>
#include <cstring>
using namespace std;
int bx,by,ex,ey,bs,n,m;
char bf[10];
int mp[100][100][4];
int ans;
void bl(int x,int y,int z){
	if(z==0){//向这个方向前进1,2,3步，若第一步有障碍，则1,2,3走不了
		if(x-1>=0&&mp[x-1][y][z]==0)                    mp[x-1][y][z]=ans+1;
		if(x-2>=0&&mp[x-2][y][z]==0&&mp[x-1][y][z]!=-1) mp[x-2][y][z]=ans+1;
		if(x-3>=0&&mp[x-3][y][z]==0&&mp[x-1][y][z]!=-1) mp[x-3][y][z]=ans+1;
	}
	if(z==2){
		if(x+1<=n&&mp[x+1][y][z]==0)                    mp[x+1][y][z]=ans+1;
		if(x+2<=n&&mp[x+2][y][z]==0&&mp[x+1][y][z]!=-1) mp[x+2][y][z]=ans+1;
		if(x+3<=n&&mp[x+3][y][z]==0&&mp[x+1][y][z]!=-1) mp[x+3][y][z]=ans+1;
	}
	if(z==1){
		if(y-1>=0&&mp[x][y-1][z]==0)                    mp[x][y-1][z]=ans+1;
		if(y-2>=0&&mp[x][y-2][z]==0&&mp[x][y-1][z]!=-1) mp[x][y-2][z]=ans+1;
		if(y-3>=0&&mp[x][y-3][z]==0&&mp[x][y-1][z]!=-1) mp[x][y-3][z]=ans+1;
	}
	if(z==3){
		if(y+1<=m&&mp[x][y+1][z]==0)                    mp[x][y+1][z]=ans+1;
		if(y+2<=m&&mp[x][y+2][z]==0&&mp[x][y+1][z]!=-1) mp[x][y+2][z]=ans+1;
		if(y+3<=m&&mp[x][y+3][z]==0&&mp[x][y+1][z]!=-1) mp[x][y+3][z]=ans+1;
	}
	if(mp[x][y][(z+1+4)%4]==0) mp[x][y][(z+1+4)%4]=ans+1;//转向
	if(mp[x][y][(z-1+4)%4]==0) mp[x][y][(z-1+4)%4]=ans+1;
}
int bfs(){
	for(int i=0;i<4;i++){//判断是否找到终点
		if(mp[ex][ey][i]!=0){
			return mp[ex][ey][i];
		}
	}
    int a=0;
	ans++;
	for(int i=0;i<=n;i++){//找下一步所有可能的情况并记录最小步数
		for(int j=0;j<=m;j++){
			for(int k=0;k<4;k++){
				if(ans==mp[i][j][k]){
                    bl(i,j,k);
                    a=1;
                }
			}
		}
	}
    if(a==0)//从起点遍历完都没有找到终点
    return 0;
	bfs();//这是一个循环，不断的找下步可能的情况，直到找到终点或者遍历完
}
int main() {
	int a;
	while(~scanf("%d %d", &n, &m)&&(n||m)){
		memset(mp,0,sizeof(mp));
		ans=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				scanf("%d", &a);
				if(a==0) for(int k=0;k<4;k++){//这里是将点转化为路线
                    if(mp[i][j][k]==0)     mp[i][j][k]=0;
                    if(mp[i+1][j][k]==0)   mp[i+1][j][k]=0;
                    if(mp[i+1][j+1][k]==0) mp[i+1][j+1][k]=0;
                    if(mp[i][j+1][k]==0)   mp[i][j+1][k]=0;
                }
				else     for(int k=0;k<4;k++) mp[i][j][k]=-1,mp[i+1][j][k]=-1,mp[i+1][j+1][k]=-1,mp[i][j+1][k]=-1;
			}
		}
		scanf("%d %d %d %d %s", &bx, &by, &ex, &ey, bf);
		for(int i=0;i<=m;i++){//处理边界，机器人太胖，不能走边界
			for(int k=0;k<4;k++){
				mp[0][i][k]=-1;
				mp[n][i][k]=-1;
			}
		}
		for(int i=0;i<=n;i++){
			for(int k=0;k<4;k++){
				mp[i][0][k]=-1;
				mp[i][m][k]=-1;
			}
		}
		if(bf[0]=='n') bs=0;//初始方向
		if(bf[0]=='s') bs=2;
		if(bf[0]=='w') bs=1;
		if(bf[0]=='e') bs=3;
		mp[bx][by][bs]=1;
		if(mp[ex][ey][0]==-1||mp[bx][by][0]==-1)//有可能开始或终点处有障碍物
		printf("-1\n");
		else
		printf("%d\n", bfs()-1);
	}
	return 0;
}
