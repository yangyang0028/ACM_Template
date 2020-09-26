/*
敌兵布阵
HDU - 1166
https://cn.vjudge.net/problem/HDU-1166
题面：线段树裸题
输入：	T组数据 N个工兵营地 N个第i个开始有多少人
			有四种命令 到end结束
			Add i j, i和j为正整数, 表示第i个营地增加j个人（j不超过30）
			Sub i j , i和j为正整数, 表示第i个营地减少j个人（j不超过30）;
			Query i j , i和j为正整数, i<=j，表示询问第i到第j个营地的总人数;
样例输入：
			1
			10
			1 2 3 4 5 6 7 8 9 10
			Query 1 3
			Add 3 6
			Query 2 7
			Sub 10 2
			Add 6 3
			Query 3 10
			End
样例输出：
			Case 1:
			6
			33
			59
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 100000
#define ll long long
ll tree[maxn<<2];
ll num[maxn];
char c[10];
int n;
void update(int now){
	tree[now]=tree[now<<1]+tree[now<<1|1];
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
ll seartch(int l, int r, int now, int i, int j){
	if(i<=l&&r<=j) return tree[now];
	ll ans=0;
	int mid=(l+r)/2;
	if(i<=mid) ans+=seartch(l, mid, now<<1, i, j);
	if(j>mid) ans+=seartch(mid+1, r, now<<1|1, i, j);
	return ans;
}
int main(){
	int T;
	scanf("%d",  &T);
	for(int s=1;s<=T;s++){
		printf("Case %d:\n", s);
		scanf("%d",  &n);
		for(int i=1;i<=n;i++){
			scanf("%lld",  &num[i]);
		}
		build(1, n, 1);
		ll a, b;
		while(~scanf("%s",  c)){
			if(c[0]=='E') break;
			scanf("%lld %lld",  &a,  &b);
			if(c[0]=='A') change(1, n, 1, (int)a, b);
			if(c[0]=='S') change(1, n, 1, (int)a, -b);
			if(c[0]=='Q') printf("%lld\n",  seartch(1, n, 1, (int)a, (int)b));
		}
	}
	return 0;
}


//递推版
/*
敌兵布阵
HDU - 1166
https://cn.vjudge.net/problem/HDU-1166
题面：线段树裸题
输入：	T组数据 N个工兵营地 N个第i个开始有多少人
			有四种命令 到end结束
			Add i j, i和j为正整数, 表示第i个营地增加j个人（j不超过30）
			Sub i j , i和j为正整数, 表示第i个营地减少j个人（j不超过30）;
			Query i j , i和j为正整数, i<=j，表示询问第i到第j个营地的总人数;
样例输入：
			1
			10
			1 2 3 4 5 6 7 8 9 10
			Query 1 3
			Add 3 6
			Query 2 7
			Sub 10 2
			Add 6 3
			Query 3 10
			End
样例输出：
			Case 1:
			6
			33
			59
*/
#include <cstring>
#include <cstdio>
#include <iostream>
#define maxn 100000
using namespace std;
int num[maxn];
int tree[maxn << 2];
int n,N;
void build(){
  N = 1;
  while(N <= n + 1) N <<= 1;
  for(int i = 1; i <= n; i++) tree[N+i]=num[i];
  for(int i = N - 1; i>0; i--){
    tree[i]=tree[i<<1]+tree[i<<1|1];
  }
}
void change(int L, int C){
  for(int s = N + L; s; s >>= 1){
    tree[s] += C;
  }
}
int query(int L,int R){
  int ANS=0;
  for(int s = N + L - 1, t = N + R + 1; s ^ t ^ 1; s >>= 1,t >>= 1){
    if(~ s & 1) ANS += tree[s ^ 1];
    if(t & 1) ANS += tree[t ^ 1];
  }
  return ANS;
}
int main(){
  int T;
	scanf("%d",  &T);
	for(int s=1;s<=T;s++){
		printf("Case %d:\n", s);
		scanf("%d",  &n);
		for(int i=1;i<=n;i++){
			scanf("%d",  &num[i]);
		}
		build();
		int a, b;
    char c[10];
		while(~scanf("%s",  c)){
			if(c[0]=='E') break;
			scanf("%d %d",  &a,  &b);
			if(c[0]=='A') change(a, b);
			if(c[0]=='S') change(a, -b);
			if(c[0]=='Q') printf("%d\n",  query(a, b));
		}
	}
	return 0;
}
