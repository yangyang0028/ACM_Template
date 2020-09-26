/*
Balanced Lineup
POJ - 3264
https://cn.vjudge.net/problem/POJ-3264#author=henuacm
解法：同时维护两颗线段树 max min
*/
#include <cstdio>
#include <algorithm>
using namespace std;
#define maxn 1000000
#define INF 0x3f3f3f3f
int a[maxn];
struct node{
  int maxx;
  int minn;
}tree[maxn<<4];
void update_maxx(int now){
  tree[now].maxx=max(tree[now<<1].maxx,tree[now<<1|1].maxx);
}
void update_minn(int now){
  tree[now].minn=min(tree[now<<1].minn,tree[now<<1|1].minn);
}
void build(int now,int l,int r){
  if(l==r){
    tree[now].maxx=a[l];
    tree[now].minn=a[l];
    return ;
  }
  int mid=(l+r)>>1;
  build(now<<1,l,mid);
  build(now<<1|1,mid+1,r);
  update_maxx(now);
  update_minn(now);
}
int seartch_maxx(int now,int l,int r,int i,int j){
  if(i<=l&&r<=j){
    return tree[now].maxx;
  }
  int ans=-INF;
  int mid=(l+r)>>1;
  if(i<=mid) ans=max(ans,seartch_maxx(now<<1,l,mid,i,j));
  if(j>mid) ans=max(ans,seartch_maxx(now<<1|1,mid+1,r,i,j));
  return ans;
}
int seartch_minn(int now,int l,int r,int i,int j){
  if(i<=l&&r<=j){
    return tree[now].minn;
  }
  int ans=INF;
  int mid=(l+r)>>1;
  if(i<=mid) ans=min(ans,seartch_minn(now<<1,l,mid,i,j));
  if(j>mid) ans=min(ans,seartch_minn(now<<1|1,mid+1,r,i,j));
  return ans;
}
int main(){
  int n,m;
  scanf("%d %d", &n, &m);
  for(int i=1;i<=n;i++){
    scanf("%d", &a[i]);
  }
  build(1,1,n);
  int l,r;
  while(m--){
    scanf("%d %d", &l, &r);
    printf("%d\n", seartch_maxx(1,1,n,l,r)-seartch_minn(1,1,n,l,r));
  }
}
