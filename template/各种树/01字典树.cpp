/*
Chip Factory
ACM/ICPC 2015 Changchun（Trie）
https://nanti.jisuanke.com/t/A1941
题面：
有一个数组，让你选取三个数，使其中两个数相加异或上另外一个数值最大。
很明显的异或最大要用01字典树，问题是要选取三个数。我们可以提前把所有的数字插入到01字典树上，
每次枚举其中两个数时，先在字典树上面删除这两个数，然后再查询。问题又来了，我们怎么删除了，因为我们用的是公共前缀，
所以我们可以对01字典树上的边进行计数，每次插入 +1，删除 -1，如此就可以完成删除操作了。
样例输入：
      2
      3
      1 2 3
      3
      100 200 300
样例输出：
      6
      400
*/
#include <bits/stdc++.h>
using namespace std;
#define maxn 1000
#define ll long long
int tol;
ll val[30*maxn];
int ch[30*maxn][2];
int nn[30*maxn][2];
void init(){
  tol=1;
  memset(nn,0,sizeof nn);
  ch[0][0]=ch[0][1]=0;
}
void insert(ll x){
  int u=0;
  for(int i=30;i>=0;i--){
    int v=(x>>i)&1;
    nn[u][v]++;
    if(!ch[u][v]){
      ch[tol][0]=ch[tol][1]=0;
      val[tol]=0;
      ch[u][v]=tol++;
    }
    u=ch[u][v];
  }
  val[u]=x;
}
ll query(ll x){
  int u=0;
  for(int i=30;i>=0;i--){
    int v=(x>>i)&1;
			if(ch[u][v^1]&&nn[u][v^1]) u=ch[u][v^1];
			else u=ch[u][v];
  }
  return val[u];
}
void pp(){
	for(int i=0;i<tol;i++){
		cout<<i<<"  "<<nn[i][0]<<"  "<<nn[i][1]<<endl;
	}
}
ll solve(ll x,ll y){
	ll xx=x,yy=y;
	ll num=x+y;
	ll u=0;
  for(int i=30;i>=0;i--){
		int v=(x>>i)&1;
		nn[u][v]--;
		u=ch[u][v];
	}
	u=0;
	for(int i=30;i>=0;i--){
		int v=(y>>i)&1;
		nn[u][v]--;
		u=ch[u][v];
	}
	ll ans=num^query(num);
	u=0;
	for(int i=30;i>=0;i--){
		int v=(xx>>i)&1;
		nn[u][v]++;
		u=ch[u][v];
	}
	u=0;
	for(int i=30;i>=0;i--){
		int v=(yy>>i)&1;
		nn[u][v]++;
		u=ch[u][v];
	}
	return ans;
}
ll a[maxn];
int main(){
  int T,n,m;
  scanf("%d",&T);
  while(T--){
    init();
    scanf("%d", &n);
    for(int i=0;i<n;i++){
      scanf("%lld", &a[i]);
      insert(a[i]);
    }
		int ans=0,num;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				num=solve(a[i],a[j]);
				if(ans<num) ans=num;
			}
		}
		cout<<ans<<endl;
  }
}
