#include <stdio.h>
#include <string.h>
#include<queue>
using namespace std;
int mp[100005];
int n,k;
queue<int>q;
int bfs(int n,int k){
    int i,m,date,d;
    q.push(n);
    mp[n]=1;
    while(!q.empty()){
        date=q.front();
        q.pop();
        for(int i=0;i<=2;i++){
            if(i==0) d=date-1;
            if(i==1) d=date+1;
            if(i==2) d=date*2;
            if(d>=0&&d<100005&&mp[d]==0){
                q.push(d);
                mp[d]=mp[date]+1;
                if(d==k)
                    return mp[d]-1;
            }
        }
    }
}
int main(){
    scanf("%d %d", &n, &k);
        memset(mp,0,sizeof(mp));
        if(n>k) printf("%d\n", n-k);
        else{
            printf("%d\n", bfs(n,k));
        }
    return 0;
}
