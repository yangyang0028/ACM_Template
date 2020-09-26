#include <stdio.h>
int n,k;
int ans;
int anss;
char mp[15][15];
bool judge(int x,int y){
    //printf("%d %d\n", x, y);
    int anss=0;
    for(int i=0;i<n;i++){
        if(mp[i][y]=='0') anss++;
    }
    for(int i=0;i<n;i++){
        if(mp[x][i]=='0') anss++;
    }
    if(anss==0) return 1;
    return 0;
}
void dfs(int x){
    //printf("%d\n", x);
    if(x>n) return ;
    if(anss==k){
        ans++;
        return ;
    }
    for(int i=0;i<n;i++){
        if(mp[x][i]=='#'&&judge(x,i)){
            mp[x][i]='0';
            anss++;
            dfs(x+1);
            anss--;
            mp[x][i]='#';
        }
    }
    dfs(x+1);
}
int main(){
    while(~scanf("%d %d", &n, &k)&&n!=-1){
        ans=0;
        anss=0;
        for(int i=0;i<n;i++){
            scanf("%s", mp[i]);
        }
        if(k==1){
            //printf("%d\n", ans);
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(mp[i][j]=='#') ans++;
                }
            }
            printf("%d\n", ans);
        }else {
            dfs(0);
            printf("%d\n", ans);
        }
    }
    return 0;
}
