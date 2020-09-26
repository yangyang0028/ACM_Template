/*
Heavy Transportation
POJ - 1797
https://cn.vjudge.net/problem/POJ-1797
题面 找出从1到n的路，使其称重最大
输入：T组样例 点个数和边个数
      u -> v  w
样例输入：
      1
      3 3
      1 2 3
      1 3 4
      2 3 5
样例输出：
      Scenario #1:
思路：
dijkstra
*/
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;
int w[1010][1010];
int d[1010];
bool vis[1010];
int n,m;
void djs()
{
    for(int i=1; i<=n; i++)
    {
        d[i]=w[1][i];
        vis[i]=0;
    }
    for(int i=1; i<=n; i++)
    {
        int m=-1;
        int x=-1;
        for(int j=1; j<=n; j++)
            if(!vis[j]&&d[j]>m)
                m=d[x=j];
        if(x!=-1)
        {
            vis[x]=1;
            for(int j=1; j<=n; j++)
                if(!vis[j]&&d[j]<min(d[x],w[x][j]))
                    d[j]=min(d[x],w[x][j]);//维护d数组
        }
    }
}
int main()
{
    int T,t=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                w[i][j]=i==j?0:-1;
        for(int i=1; i<=m; i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            if(w[x][y]<z)
                w[x][y]=w[y][x]=z;
        }
        djs();
        printf("Scenario #%d:\n%d\n\n",t++,d[n]);
    }
}
