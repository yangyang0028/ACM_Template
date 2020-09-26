/*
Can you answer these queries?
HDU - 4027
https://vjudge.net/problem/HDU-4027
题面：
  1：0 l r 表示区间[l, r]的每个数都开平方
  2：0 l r 表示区间[l, r]的和
解法：
  线段树单点更新
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
#include<algorithm>
using namespace std;
#define maxn 100010
#define ll long long
struct node{
  ll num;
}tree[maxn<<2];
ll a[maxn];
void build(int now,int l,int r){
  if(l==r){
    tree[now].num=a[l];
    return ;
  }
  int mid=(l+r)>>1;
  build(now<<1,l,mid);
  build(now<<1|1,mid+1,r);
  tree[now].num=tree[now<<1].num+tree[now<<1|1].num;
}
void change(int now,int l,int r,int i,int j){
  if(l==r){
    tree[now].num=sqrt(1.0*tree[now].num);
    return ;
  }
  if(i<=l&&r<=j&&tree[now].num==(r-l+1)) return ;
  int mid=(l+r)>>1;
  if(i<=mid) change(now<<1,l,mid,i,j);
  if(j>mid) change(now<<1|1,mid+1,r,i,j);
  tree[now].num=tree[now<<1].num+tree[now<<1|1].num;
}
ll query(int now,int l,int r,int i,int j){
  if(i<=l&&r<=j){
    return tree[now].num;
  }
  ll ans=0;
  int mid=(l+r)>>1;
  if(i<=mid) ans+=query(now<<1,l,mid,i,j);
  if(j>mid) ans+=query(now<<1|1,mid+1,r,i,j);
  return ans;
}
int main(){
  int n,m;
  int q,l,r;
  int t=0;
  while(~scanf("%d", &n)){
    printf("Case #%d:\n", ++t);
    for(int i=1;i<=n;i++){
      scanf("%lld", &a[i]);
    }
    build(1,1,n);
    scanf("%d", &m);
    while(m--){
      scanf("%d %d %d", &q, &l, &r);
      if(r<l) swap(l,r);
      if(q==0){
        change(1,1,n,l,r);
      }else{
        printf("%lld\n", query(1,1,n,l,r));
      }
    }
	  puts("");
  }
  return 0;
}
