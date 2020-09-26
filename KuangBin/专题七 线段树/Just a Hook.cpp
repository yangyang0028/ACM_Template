/*
Just a Hook
HDU - 1698
https://cn.vjudge.net/problem/HDU-1698#author=0
题面：开始都是1，每次将一段区间内的所有数字都变为c
样例输入：
			1
			10
			2
			1 5 2
			5 9 3
样例输出：
			24
解法：线段树+lazy
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 500000
#define ll long long
ll tree[maxn<<2];
ll lazy[maxn<<2];
int n,m;
void update(int now){
	tree[now]=tree[now<<1]+tree[now<<1|1];
}
void update_lazy(int now,int d){
	if(lazy[now]!=0){
		tree[now<<1]=lazy[now]*(d-d/2);
		tree[now<<1|1]=lazy[now]*(d/2);
		lazy[now<<1]=lazy[now];
		lazy[now<<1|1]=lazy[now];
		lazy[now]=0;
	}
}
void build(int l, int r, int now){
	if(l==r){
		tree[now]=1;
		return ;
	}
	int mid=(l+r)/2;
	build(l, mid, now<<1);
	build(mid+1, r, now<<1|1);
	update(now);
}
void change_lazy(int l, int r, int now, int i, int j, ll c){
	if(i<=l&&r<=j){
		tree[now]=c*(r-l+1);
		lazy[now]=c;
		return;
	}
	update_lazy(now,(r-l+1));
	int mid=(l+r)/2;
	if(i<=mid) change_lazy(l, mid, now<<1, i, j, c);
	if(j>mid) change_lazy(mid+1, r, now<<1|1, i, j, c);
	update(now);
}
ll seartch(int l, int r, int now, int i, int j){
	if(i<=l&&r<=j) return tree[now];
	update_lazy(now,r-l+1);
	ll ans=0;
	int mid=(l+r)/2;
	if(i<=mid) ans+=seartch(l, mid, now<<1, i, j);
	if(j>mid) ans+=seartch(mid+1, r, now<<1|1, i, j);
	return ans;
}
int main(){
  int T,t=1;
  scanf("%d", &T);
  while(T--){
    memset(tree,0,sizeof tree);
    memset(lazy,0,sizeof lazy);
  	scanf("%d %d",  &n, &m);
  	build(1, n, 1);
  	ll a, b, d;
  	while(m--){
      scanf("%lld %lld %lld",  &a,  &b, &d);
  		change_lazy(1, n, 1, (int)a, (int)b, d);
  	}
    printf("Case %d: The total value of the hook is %lld.\n", t++, seartch(1, n, 1, 1, n));
  }
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define maxn 510000
struct node{
  int lazy;
  int num;
}tree[maxn];
void update(int now,int d){
  if(tree[now].lazy!=0){
    tree[now<<1].num=tree[now].lazy*(d-d/2);
    tree[now<<1|1].num=tree[now].lazy*(d/2);
    tree[now<<1].lazy=tree[now].lazy;
    tree[now<<1|1].lazy=tree[now].lazy;
    tree[now].lazy=0;
  }
}
void build(int now,int l,int r){
  tree[now].lazy=0;
  if(l==r){
    tree[now].num=1;
    return ;
  }
  int mid=(l+r)>>1;
  build(now<<1,l,mid);
  build(now<<1|1,mid+1,r);
  tree[now].num=tree[now<<1].num+tree[now<<1|1].num;
}
void change(int now,int l,int r,int i,int j,int c){
  if(i<=l&&r<=j){
    tree[now].num=c*(r-l+1);
    tree[now].lazy=c;
    return ;
  }
  update(now,r-l+1);
  int mid=(l+r)>>1;
  if(i<=mid) change(now<<1,l,mid,i,j,c);
  if(j>mid) change(now<<1|1,mid+1,r,i,j,c);
  tree[now].num=tree[now<<1].num+tree[now<<1|1].num;
}
int seartch(int now,int l,int r,int i,int j){
  if(i<=l&&r<=j){
    return tree[now].num;
  }
  int ans=0;
  update(now,r-1+1);
  int mid=(l+r)>>1;
  if(i<=mid) ans+=seartch(now<<1,l,mid,i,j);
  if(j>mid) ans+=seartch(now<<1|1,mid+1,r,i,j);
  return ans;
}
int main(){
  int T,t=1;
  int l,r,k;
  int n,m;
  scanf("%d", &T);
  while(T--){
    scanf("%d %d", &n, &m);
    build(1,1,n);
    while(m--){
      scanf("%d %d %d", &l, &r, &k);
      change(1,1,n,l,r,k);
    }
    printf("Case %d: The total value of the hook is %d.\n", t++, seartch(1,1,n,1,n));
  }
  return 0;
}
