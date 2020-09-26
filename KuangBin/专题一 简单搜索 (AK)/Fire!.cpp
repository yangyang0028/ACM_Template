#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define maxn 1010
#define INF 0x3f3f3f
char mp_c[maxn][maxn];
int mp_f[maxn][maxn];
int mp[maxn][maxn];
int n,m;
struct node{
  int x,y;
};
void init(){
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(mp_c[i][j]=='#'){
        mp_f[i][j]=-1;
      }else if(mp_c[i][j]=='F'){
        mp_f[i][j]=1;
      }else mp_f[i][j]=0;
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(mp_c[i][j]=='#'){
        mp[i][j]=-1;
      }else if(mp_c[i][j]=='J'){
        mp[i][j]=1;
      }else mp[i][j]=0;
    }
  }
}
void bfs_1(){
  queue<node> q;
  node a,b;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(mp_c[i][j]=='F'){
        a.x=i;
        a.y=j;
        q.push(a);
      }
    }
  }
  while(!q.empty()){
    a=q.front();
    q.pop();
    int x=a.x;
    int y=a.y;
    if(x-1>=0&&mp_f[x-1][y]==0){
      mp_f[x-1][y]=mp_f[x][y]+1;
      b.x=x-1;
      b.y=y;
      q.push(b);
    }
    if(x+1<n&&mp_f[x+1][y]==0){
      mp_f[x+1][y]=mp_f[x][y]+1;
      b.x=x+1;
      b.y=y;
      q.push(b);
    }
    if(y-1>=0&&mp_f[x][y-1]==0){
      mp_f[x][y-1]=mp_f[x][y]+1;
      b.x=x;
      b.y=y-1;
      q.push(b);
    }
    if(y+1>=0&&mp_f[x][y+1]==0){
      mp_f[x][y+1]=mp_f[x][y]+1;
      b.x=x;
      b.y=y+1;
      q.push(b);
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(mp_f[i][j]==0) mp_f[i][j]=INF;
    }
  }
}
int bfs_2(){
  queue<node> q;
  node a,b;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(mp_c[i][j]=='J'){
        a.x=i;
        a.y=j;
        q.push(a);
      }
    }
  }
  while(!q.empty()){
    a=q.front();
    q.pop();
    int x=a.x;
    int y=a.y;
    if(x==0||x==n-1||y==0||y==m-1) return mp[x][y];
    if(x-1>=0&&mp[x-1][y]==0&&mp[x][y]+1<mp_f[x-1][y]){
      mp[x-1][y]=mp[x][y]+1;
      b.x=x-1;
      b.y=y;
      q.push(b);
    }
    if(x+1<n&&mp[x+1][y]==0&&mp[x][y]+1<mp_f[x+1][y]){
      mp[x+1][y]=mp[x][y]+1;
      b.x=x+1;
      b.y=y;
      q.push(b);
    }
    if(y-1>=0&&mp[x][y-1]==0&&mp[x][y]+1<mp_f[x][y-1]){
      mp[x][y-1]=mp[x][y]+1;
      b.x=x;
      b.y=y-1;
      q.push(b);
    }
    if(y+1<m&&mp[x][y+1]==0&&mp[x][y]+1<mp_f[x][y+1]){
      mp[x][y+1]=mp[x][y]+1;
      b.x=x;
      b.y=y+1;
      q.push(b);
    }
  }
  return -1;
}
int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++){
      scanf("%s", mp_c[i]);
    }
    init();
    bfs_1();
    int ans=bfs_2();
    //print();
    if(ans==-1) printf("IMPOSSIBLE\n");
		else printf("%d\n", ans);
  }
  return 0;
}
