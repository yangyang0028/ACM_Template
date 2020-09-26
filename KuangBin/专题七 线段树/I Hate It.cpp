//递归版
/*
I Hate It
HDU - 1754
https://cn.vjudge.net/problem/HDU-1754
题面：线段树裸题(记录的是最大的)
输入：	连续输入 学生数目和操作数目
			学生成绩
			操作 Q 询问 U更新成绩
样例输入：
			5 6
			1 2 3 4 5
			Q 1 5
			U 3 6
			Q 3 4
			Q 4 5
			U 2 9
			Q 1 5
样例输出：
			5
			6
			5
			9
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 200000
#define ll long long
ll tree[maxn<<2];
ll num[maxn];
char c[10];
int n,m;
void update(int now){
	tree[now]=max(tree[now<<1],tree[now<<1|1]);
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
		tree[now]=c;
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
	if(i<=mid) ans=max(ans,seartch(l, mid, now<<1, i, j));
	if(j>mid) ans=max(ans,seartch(mid+1, r, now<<1|1, i, j));
	return ans;
}
int main(){
	while(~scanf("%d %d", &n, &m)){
		for(int i=1;i<=n;i++){
			scanf("%lld",  &num[i]);
		}
		build(1,n,1);
		ll a, b;
		while(m--){
			scanf("%s", c);
			scanf("%lld %lld",  &a,  &b);
			if(c[0]=='U') change(1, n, 1, (int)a, b);
			if(c[0]=='Q') printf("%lld\n",  seartch(1, n, 1, (int)a, (int)b));
		}
	}
	return 0;
}


//递推版
/*
I Hate It
HDU - 1754
https://cn.vjudge.net/problem/HDU-1754
题面：线段树裸题(记录的是最大的)
输入：	连续输入 学生数目和操作数目
			学生成绩
			操作 Q 询问 U更新成绩
样例输入：
			5 6
			1 2 3 4 5
			Q 1 5
			U 3 6
			Q 3 4
			Q 4 5
			U 2 9
			Q 1 5
样例输出：
			5
			6
			5
			9
*/
#include <cstring>
#include <cstdio>
#include <iostream>
#define maxn 200000
using namespace std;
int num[maxn];
int tree[maxn << 2];
int n,m,N;
void build(){
  N = 1;
  while(N <= n + 1) N <<= 1;
  for(int i = 1; i <= n; i++) tree[N+i]=num[i];
  for(int i = N - 1; i>0; i--){
    tree[i]= max(tree[i<<1], tree[i<<1|1]);
  }
}
void change(int L, int C){
  int s=N+L;
  tree[s] = C;
  s >>= 1;
  for(; s; s >>= 1){
    tree[s] = max(tree[s<<1], tree[s<<1|1]);
  }
}
int query(int L,int R){
  int ANS=0;
  for(int s = N + L - 1, t = N + R + 1; s ^ t ^ 1; s >>= 1,t >>= 1){
    if(~ s & 1) ANS = max(ANS, tree[s ^ 1]);
    if(t & 1) ANS = max(ANS, tree[t ^ 1]);
  }
  return ANS;
}
int main(){
	while(~scanf("%d %d", &n, &m)){
		for(int i=1;i<=n;i++){
			scanf("%lld",  &num[i]);
		}
		build();
		int a, b;
    char c[10];
		while(m--){
			scanf("%s", c);
			scanf("%d %d",  &a,  &b);
			if(c[0]=='U') change(a, b);
			if(c[0]=='Q') printf("%d\n",  query(a, b));
		}
	}
	return 0;
}
