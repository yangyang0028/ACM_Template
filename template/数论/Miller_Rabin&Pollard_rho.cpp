#include <algorithm>
#include <cstdio>
#include <cstring>
#define maxn 10000
using namespace std;
typedef long long ll;
ll prime[10]={2,3,5,7,11,13,17,19,23,29};
ll factor[maxn];
ll tot;
ll mulit(ll a,ll b,ll c){//龟速乘
    ll ans=0;
    ll res=a;
    while(b){
      if(b&1)
        ans=(ans+res)%c;
      res=(res+res)%c;
      b>>=1;
    }
    return ans;
}
ll pow(ll x,ll n,ll mod){//快速幂
    ll res=1;
	while(n>0){
	   if(n%2==1){
	   	 res=mulit(res,x,mod);
	   }
	   x=mulit(x,x,mod);
	   n>>=1;
	}
	return res;
}
bool Miller_Rabin(ll x)     //判断素数
{
    ll i,j,k;
    ll s=0,t=x-1;
    if(x==2)  return true;   //2是素数
    if(x<2||!(x&1))  return false;     //如果x是偶数或者是0,1，那它不是素数
    while(!(t&1)){  //将x分解成(2^s)*t的样子
        s++;
        t>>=1;
    }
    for(i=0;i<10&&prime[i]<x;++i){      //随便选一个素数进行测试
        ll a=prime[i];
        ll b=pow(a,t,x);      //先算出a^t
        for(j=1;j<=s;++j){    //然后进行s次平方
            k=mulit(b,b,x);   //求b的平方
            if(k==1&&b!=1&&b!=x-1)     //用二次探测判断
              return false;
            b=k;
        }
        if(b!=1)  return false;   //用费马小定律判断
    }
    return true;   //如果进行多次测试都是对的，那么x就很有可能是素数
}
ll gcd(ll a,ll b){
    if(a==0)return 1;
    if(a<0) return gcd(-a,b);
    while(b){
        long long t=a%b;
        a=b;
        b=t;
    }
    return a;
}
ll Pollard_rho(ll x,ll c){
    ll i=1,k=2;
    ll x0=rand()%x;
    ll y=x0;
    while(1){
        i++;
        x0=(mulit(x0,x0,x)+c)%x;
        long long d=gcd(y-x0,x);
        if(d!=1&&d!=x) return d;
        if(y==x0) return x;
        if(i==k){
            y=x0;
            k+=k;
        }
    }
}
void findfac(ll n){
    if(Miller_Rabin(n)){
        factor[tot++]=n;
        return;
    }
    ll p=n;
    while(p>=n) p=Pollard_rho(p,rand()%(n-1)+1);
    findfac(p);
    findfac(n/p);
}
int main(){
  ll t,n;
  scanf("%lld", &t);
  while(t--){
    scanf("%lld", &n);
    if(Miller_Rabin(n)){
      printf("Prime\n");
      continue;
    }
    tot=0;
    findfac(n);
    ll ans=factor[0];
    for(int i=1; i<tot; i++)
        if(factor[i]<ans)
            ans=factor[i];
    printf("%lld\n",ans);
  }

  return 0;
}
