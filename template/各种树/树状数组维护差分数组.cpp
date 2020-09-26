/*
【模板】树状数组 2
P3368
https://www.luogu.org/problem/P3368
解法： 树状数组维护差分数组
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 1000000
ll a[maxn];
ll tree[maxn<<1];
ll n,m;
inline long long read()//快读
{
    long long x=0,f=1;char c=getchar();
    while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
    while(isdigit(c)){x=x*10+c-48;c=getchar();}
    return x*f;
}
void update(int x,int val){
	while(x<=n){
		tree[x]+=val;
		x+=x&(-x);
	}
}
long long sum(long long x){
	long long ans=0;
	while(x>=1){
		ans+=tree[x];
		x-=x&(-x);
	}
	return ans;
}
int main(){
  int s,l,r,x;
  n=read();
  m=read();
  memset(tree,0,(n+1)*sizeof (ll));
  for(int i=1;i<=n;i++){
    a[i]=read();
    update(i,a[i]-a[i-1]);
  }
  while(m--){
    s=read();
    if(s==2){
      x=read();
      printf("%lld\n", sum(x));
    }else{
      l=read();
      r=read();
      x=read();
      update(l,x);
      update(r+1,-x);
    }
  }
}
