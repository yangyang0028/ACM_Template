#include <bits/stdc++.h>
using namespace std;
#define maxn 6010
int N,root,Ri[maxn],F[maxn][2],son[maxn],bro[maxn];
bool is_son[maxn];
void init(){
  int i,j,k;
  scanf("%d", &N);
  for(int i=1;i<=N;i++) scanf("%d", Ri+i);
  memset(son,0,sizeof(son));
  memset(is_son,0,sizeof(is_son));
  for(i=1;i<N;i++){
    scanf("%d %d", &j, &k);
    bro[j]=son[k];
    son[k]=j;
    is_son[j]=true;
  }
  for(int i=1;i<=N;i++){
    if(!is_son[i]) root = i;
  }
}
void dp(int u){
  int v;
  F[u][0]=0;
  F[u][1]=Ri[u];
  for(v=son[u];v;v=bro[v]){
    dp(v);
    F[u][0]+=max(F[v][0],F[v][1]);
    F[u][1]+=F[v][0];
  }
}
void solve(){
  dp(root);
  printf("%d", max(F[root][0],F[root][1]));
}
int main(){
  init();
  solve();
  return 0;
}
