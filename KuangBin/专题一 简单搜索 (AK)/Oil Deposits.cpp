#include <bits/stdc++.h>
using namespace std;
int n,m;
char mp[100][100];
void dfs(int x,int y){
    mp[x][y]='0';
    if(x+1<n&&mp[x+1][y]=='@'){
        dfs(x+1,y);
    }
    if(x-1>=0&&mp[x-1][y]=='@'){
        dfs(x-1,y);
    }
    if(y+1<m&&mp[x][y+1]=='@'){
        dfs(x,y+1);
    }
    if(y-1>=0&&mp[x][y-1]=='@'){
        dfs(x,y-1);
    }
    ////////////////////////////////////
    if(x+1<n&&y+1<m&&mp[x+1][y+1]=='@'){
        dfs(x+1,y+1);
    }
    if(x-1>=0&&y+1<m&&mp[x-1][y+1]=='@'){
        dfs(x-1,y+1);
    }
    if(y-1>=0&&x+1<n&&mp[x+1][y-1]=='@'){
        dfs(x+1,y-1);
    }
    if(y-1>=0&&x-1>=0&&mp[x-1][y-1]=='@'){
        dfs(x-1,y-1);
    }
}
int main(){
    while(~scanf("%d %d", &n, &m)&&n){
        memset(mp,0,sizeof(mp));
        int ans=0;
        for(int i=0;i<n;i++)
            scanf("%s", mp[i]);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                if(mp[i][j]=='@'){
                    //printf("AAA===%d %d\n", i, j);
                    dfs(i,j);
                    ans++;
                }
            }
        getchar();
        printf("%d\n", ans);
    }
    return 0;
}
