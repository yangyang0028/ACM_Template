/*
A Simple Problem with Integers
POJ - 3468
https://cn.vjudge.net/problem/POJ-3468
题面：线段树裸题(区间更改)
输入：	连续输入 n m
			n个数
			m次操作 Q 询问区间和  U区间+c
样例输入：
			10 5
			1 2 3 4 5 6 7 8 9 10
			Q 4 4
			Q 1 10
			Q 2 4
			C 3 6 3
			Q 2 4
样例输出：
			4
			55
			9
			15
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 110000
#define ll long long
ll tree[maxn<<2];
ll num[maxn];
ll lazy[maxn<<2];
char c[10];
int n,m;
void update(int now){
	tree[now]=tree[now<<1]+tree[now<<1|1];
}
void update_lazy(int now,int d){
	if(lazy[now]!=0){
		tree[now<<1]+=lazy[now]*(d-d/2);
		tree[now<<1|1]+=lazy[now]*(d/2);
		lazy[now<<1]+=lazy[now];
		lazy[now<<1|1]+=lazy[now];
		lazy[now]=0;
	}
}
void build(int l, int r, int now){
	if(l==r){
		tree[now]=num[l];
		return ;
	}
	int mid=(l+r)/2;
	build(l, mid, now<<1);
	build(mid+1, r, now<<1|1);
	update(now);
}
void change(int l, int r, int now, int x, ll c){
	if(l==r){
		tree[now]+=c;
		return;
	}
	int mid=(l+r)/2;
	if(x<=mid) change(l, mid, now<<1, x, c);
	else change(mid+1, r, now<<1|1, x, c);
	update(now);
}
void change_lazy(int l, int r, int now, int i, int j, ll c){
	if(i<=l&&r<=j){
		tree[now]+=c*(r-l+1);
		lazy[now]+=c;
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
	scanf("%d %d",  &n, &m);
	for(int i=1;i<=n;i++){
		scanf("%lld",  &num[i]);
	}
	build(1, n, 1);
	ll a, b, d;
	while(m--){
		scanf("%s",  c);
		if(c[0]=='Q'){
			scanf("%lld %lld",  &a,  &b);
			printf("%lld\n",  seartch(1, n, 1, (int)a, (int)b));
		}else {
			scanf("%lld %lld %lld",  &a,  &b, &d);
			change_lazy(1, n, 1, (int)a, (int)b, d);
		}
	}
	return 0;
}


#include <cstring>
#include <cstdio>
#include <iostream>
#define maxn 110000
#define ll long long
using namespace std;
int num[maxn];
ll tree[maxn << 2];
ll lazy[maxn << 2];
int n,m,N;
void build(){
  N = 1;
  while(N <= n + 1) N <<= 1;
  for(int i = 1; i <= n; i++) tree[N+i]=num[i];
  for(int i = N - 1; i>0; i--){
    tree[i] = tree[i<<1]+ tree[i<<1|1];
    lazy[i] = 0;
  }
}
void change(int L, int R, ll C){
  int s, t, ln = 0, rn = 0, x = 1;
  for(s = N + L - 1, t = N + R + 1; s ^ t ^ 1; s >>= 1,t >>= 1,x <<= 1){
    tree[s] += C * ln;
    tree[t] += C * rn;
    if( ~ s & 1) lazy[s ^ 1] += C, tree[s ^ 1] += C * x, ln += x;
    if(   t & 1) lazy[t ^ 1] += C, tree[t ^ 1] += C * x, rn += x;
 }
 for(; s; s >>= 1, t >>= 1){
   tree[s] += C * ln;
   tree[t] += C * rn;
 }
}
ll query(int L,int R){
  int s, t, ln = 0, rn = 0, x = 1;
  ll ANS = 0;
  for(s = N + L - 1, t = N + R + 1; s ^ t ^ 1; s >>= 1,t >>= 1,x <<= 1){
    if(lazy[s]) ANS += lazy[s] * ln;
    if(lazy[t]) ANS += lazy[t] * rn;
    if(~ s & 1) ANS += tree[s ^ 1], ln += x;
    if(  t & 1) ANS += tree[t ^ 1], rn += x;
  }
  for(; s; s >>= 1, t >>= 1){
    ANS += lazy[s] * ln;
    ANS += lazy[t] * rn;
  }
  return ANS;
}
int main(){
	scanf("%d %d",  &n, &m);
	for(int i=1;i<=n;i++){
		scanf("%lld",  &num[i]);
	}
	build();
	int a, b;
  ll d;
  char c[10];
	while(m--){
		scanf("%s",  c);
		if(c[0]=='Q'){
			scanf("%d %d",  &a,  &b);
			printf("%lld\n",  query(a, b));
		}else {
			scanf("%d %d %lld",  &a,  &b, &d);
			change(a, b, d);
		}
	}
	return 0;
}
