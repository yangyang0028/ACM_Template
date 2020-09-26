/*
Ryuji doesn't want to study
ACM-ICPC 2018 徐州赛区网络预赛 H.
https://nanti.jisuanke.com/t/A2007
题面：多组询问 [l, r]  a[l] * L + a[l+1] * (L-1) + …… + a[r-1] * 2 + a[r] 以及 单点修改
解法：两棵线段树
一颗维护num[i]
另一颗维护num[i]*(n-i+1)
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 101000
#define ll long long
ll tree1[maxn<<2];
ll tree2[maxn<<2];
ll num1[maxn];
ll num2[maxn];
int n,m;
void update1(int now){
	tree1[now]=tree1[now<<1]+tree1[now<<1|1];
}
void update2(int now){
	tree2[now]=tree2[now<<1]+tree2[now<<1|1];
}
void build1(int l, int r, int now){
	if(l==r){
		tree1[now]=num1[l];
		return ;
	}
	int mid=(l+r)/2;
	build1(l, mid, now<<1);
	build1(mid+1, r, now<<1|1);
	update1(now);
}
void build2(int l, int r, int now){
	if(l==r){
		tree2[now]=num2[l];
		return ;
	}
	int mid=(l+r)/2;
	build2(l, mid, now<<1);
	build2(mid+1, r, now<<1|1);
	update2(now);
}
void change1(int l, int r, int now, int x, ll c){
	if(l==r){
		tree1[now]=c;
		return;
	}
	int mid=(l+r)/2;
	if(x<=mid) change1(l, mid, now<<1, x, c);
	else change1(mid+1, r, now<<1|1, x, c);
	update1(now);
}
void change2(int l, int r, int now, int x, ll c){
	if(l==r){
		tree2[now]=c;
		return;
	}
	int mid=(l+r)/2;
	if(x<=mid) change2(l, mid, now<<1, x, c);
	else change2(mid+1, r, now<<1|1, x, c);
	update2(now);
}
ll seartch1(int l, int r, int now, int i, int j){
	if(i<=l&&r<=j) return tree1[now];
	ll ans=0;
	int mid=(l+r)/2;
	if(i<=mid) ans+=seartch1(l, mid, now<<1, i, j);
	if(j>mid) ans+=seartch1(mid+1, r, now<<1|1, i, j);
	return ans;
}
ll seartch2(int l, int r, int now, int i, int j){
	if(i<=l&&r<=j) return tree2[now];
	ll ans=0;
	int mid=(l+r)/2;
	if(i<=mid) ans+=seartch2(l, mid, now<<1, i, j);
	if(j>mid) ans+=seartch2(mid+1, r, now<<1|1, i, j);
	return ans;
}
int main(){
		scanf("%d %d",  &n, &m);
		for(int i=1;i<=n;i++){
			scanf("%lld",  &num1[i]);
			num2[i]=num1[i]*(ll)(n-i+1);
		}
		build1(1, n, 1);
		build2(1, n, 1);
		long long a, b, c;
		while(m--){
			cin>>c>>a>>b;
			if(c==1){
				cout<<seartch2(1, n, 1, (int)a, (int)b)-(ll)(n-b)*seartch1(1, n, 1, (int)a, (int)b)<<endl;
			}else{
				change1(1, n, 1, (int)a, b);
				change2(1, n, 1, (int)a, b*(ll)(n-a+1));
			}
		}
	return 0;
}
