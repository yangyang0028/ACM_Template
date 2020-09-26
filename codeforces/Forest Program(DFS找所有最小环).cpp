/*
Forest Program
2019 ccpc (秦皇岛) f
http://codeforces.com/gym/102361/problem/F
题意： 给定一个仙人掌，删去一些边可以让它变成一个森林（一棵树也是森林），求方案数。
input
    6 6
    1 2
    2 3
    3 1
    2 4
    4 5
    5 2
output
    49
解法：
      找出所有最小环 2^size-1
      不在环上的边为m条，可以随便删，方案数就是2^resm。
*/
#include <bits/stdc++.h>
using namespace std;
#define maxn 3000010
#define MOD 998244353
#define ll long long
struct node{
  int u,v;
  int next;
}edge[maxn];
int head[maxn];
int dfn[maxn],low[maxn];
int n,m;
int cnt,top;
ll mulit(ll a,ll b){
  ll ans=0;
  ll res=a;
  while(b){
    if(b&1) ans=(ans+res)%MOD;
    res=(res+res)%MOD;
    b>>=1;
  }
  return ans;
}
ll pow1(ll x,int n){
  ll res=1;
  while(n>0){
    if(n%2==1){
      res=mulit(res,x);
    }
    x=mulit(x,x);
    n>>=1;
  }
  return res;
}
ll ans;
void init(){
  memset(head,-1,sizeof head);
  cnt=top=0;
  ans=1;
}
void add(int u,int v){
  edge[cnt].u=u;
  edge[cnt].v=v;
  edge[cnt].next=head[u];
  head[u]=cnt++;
}
stack<int> st;
void dfs(int u,int fa,int d){
  dfn[u]=d;
  for(int i=head[u];~i;i=edge[i].next){
    int v=edge[i].v;
    if(v==fa||dfn[v]>d) continue;
    if(dfn[v]>0&&dfn[v]<dfn[u]){
      st.push(dfn[u]-dfn[v]+1);
    }else{
      dfs(v,u,d+1);
    }
  }
  return ;
}
int main(){
  int u,v;
  scanf("%d %d", &n, &m);
  init();
  for(int i=0;i<m;i++){
    scanf("%d %d", &u, &v);
    add(u,v);
    add(v,u);
  }
  for(int i=1;i<=n;i++){
    if(!dfn[i]){
      dfs(i,0,1);
    }
  }
  while(!st.empty()){
    ans=mulit(ans,(pow1(2,st.top())-1)%MOD);
    m-=st.top();
    st.pop();
  }
  ans=mulit(ans,(pow1(2,m)));
  printf("%lld\n", ans);
  return 0;
}
