/*
Mayor's posters
POJ - 2528
https://cn.vjudge.net/problem/POJ-2528#author=_PI_
题意： 贴海报，会覆盖掉之前的点
输入： T组样例 贴海报的次数 海报范围
样例输入：
			1
			5
			1 4
			2 6
			8 10
			3 4
			7 10
样例输出：
			4
解法：
离散化+区间修改
*/
#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 100000
struct node {
	int l;
	int r;
} num[maxn];
int tree[maxn<<2];
int color[maxn<<1];
int has[10000010];
bool vis[maxn<<1];
int cnt;
void init(){
  memset(tree, 0, sizeof tree);
	memset(vis, false, sizeof vis);
	cnt = 0;
}
void updown(int now){
	if(tree[now] != -1){
		tree[now << 1] = tree[now << 1 | 1] = tree[now];
		tree[now] = -1;
	}
}
void change(int l, int r, int now, int i, int j, int c){
	if(i <= l && r <= j){
		tree[now] = c;
		return ;
	}
	updown(now);
	int mid = (l + r) / 2;
	if(i <= mid) change(l, mid, now<<1, i, j, c);
	if(j > mid) change(mid+1, r, now<<1|1, i, j, c);
}
void seartch(int l, int r, int now, int i, int j){
	if(tree[now] != -1){
		vis[tree[now]] = true;
		return;
	}
	int mid = (l + r) / 2;
	if(i <= mid) seartch(l, mid, now<<1, i, j);
	if(j > mid) seartch(mid+1, r, now<<1|1, i, j);
}
int main() {
	int T, n;
	scanf("%d", &T);
	while(T--){
		init();
		scanf("%d", &n);
		for(int i = 0; i < n; i++) {
			scanf("%d %d", &num[i].l, &num[i].r);
			color[cnt++] = num[i].l;
			color[cnt++] = num[i].r;
		}
		sort(color, color + cnt);
		cnt = unique(color, color + cnt) - color;
		for(int i = 1; i <= cnt; i++) {
			has[color[i - 1]] = i;
		}
		for(int i = 1; i <= n; i++) {
			change(1, cnt, 1, has[num[i - 1].l], has[num[i - 1].r], i);
		}
		seartch(1, cnt, 1, 1, cnt);
		int ans = 0;
		for(int i = 1; i <= n; i++) {
			if(vis[i]){
				ans++;
				//cout<<i<<endl;
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}



/*
Mayor's posters
POJ - 2528
https://cn.vjudge.net/problem/POJ-2528#author=_PI_
题意： 贴海报，会覆盖掉之前的点
输入： T组样例 贴海报的次数 海报范围
样例输入：
			1
			5
			1 4
			2 6
			8 10
			3 4
			7 10
样例输出：
			4
解法：
离散化+区间修改
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define maxn 100000
using namespace std;
struct TREE{
  int l,r;
  bool v;
}tree[maxn<<2];
struct node{
  int l,r;
}num[maxn];
int Hash[10000010];
int color[maxn<<1];
int n;
void build(int l,int r,int now){
  tree[now].l=l;
  tree[now].r=r;
  tree[now].v=false;
  if(l==r) return ;
  int mid=(l+r)>>1;
  build(l,mid,now<<1);
  build(mid+1,r,now<<1|1);
}
bool update(int l,int r,int now){
  if(tree[now].v) return false;
  if(tree[now].l==l&&tree[now].r==r){
    tree[now].v=true;
    return true;
  }
  int temp;
  int mid=(tree[now].l+tree[now].r)>>1;
  if(r<=mid) temp=update(l,r,now<<1);
  else if(l>mid) temp=update(l,r,now<<1|1);
  else{
    bool t1=update(l,mid,now<<1);
    bool t2=update(mid+1,r,now<<1|1);
    temp=t1||t2;
  }
  tree[now].v=tree[now<<1].v&&tree[now<<1|1].v;
  return temp;
}
void init(){
  int cnt=0;
  scanf("%d", &n);
  for(int i=0;i<n;i++){
    scanf("%d %d", &num[i].l, &num[i].r);
    color[cnt++]=num[i].l;
    color[cnt++]=num[i].r;
  }
  sort(color, color+cnt);
  cnt=unique(color,color+cnt)-color;
  
  build(1,cnt,1);
  int ans=0;
  for(int i=n-1;i>=0;i--){
    int l=num[i].l, r=num[i].r;
    if(update(Hash[l], Hash[r], 1)) ans++;
  }
  printf("%d\n", ans);
}
int main(){
  int T;
  scanf("%d", &T);
  while(T--){
    init();
  }
  return 0;
}
