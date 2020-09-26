#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
#define maxn 500010
int n;
int a[maxn];
int t[maxn*4];
struct node{
	int x;
	int id;
}f[maxn];
bool cmp(node a, node b){
	return a.x<b.x;
}
void update(int x,int val){
	while(x<=n){
		t[x]+=val;
		x+=x&(-x);
	}
}
int sum(int x){
	int ans=0;
	while(x>=1){
		ans+=t[x];
		x-=x&(-x);
	}
	return ans;
}
int main(){
	while(~scanf("%d", &n),n){
		for(int i=1;i<=n;i++){
			scanf("%d", &f[i].x);
			f[i].id=i;
		}
		sort(f+1,f+n+1,cmp);
		for(int i=1;i<=n;i++) a[i]=f[i].id;
		memset(t,0,sizeof(t));
		long long ans=0;
		for(int i=1;i<=n;i++){
			update(a[i],1);
			ans+=(i-sum(a[i]));
		}
		printf("%lld\n", ans);
	}
	return 0;
}
