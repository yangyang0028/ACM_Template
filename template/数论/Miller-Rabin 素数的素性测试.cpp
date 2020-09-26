#include <bits/stdc++.h>
using namespace std;
int prime[10]={2,3,5,7,11,13,17,19,23,29};
typedef long long ll;
ll pow(ll x,ll n,ll mod){//快速幂
    ll res=1;
	while(n>0){
	   if(n%2==1){
	   	 res=res*x;
	   	 res=res%mod;
	   }
	   x=x*x;
	   x=x%mod;
	   n>>=1;
	}
	return res;
}
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
bool Miller_Rabin(int x)     //判断素数
{
    int i,j,k;
    int s=0,t=x-1;
    if(x==2)  return true;   //2是素数
    if(x<2||!(x&1))  return false;     //如果x是偶数或者是0,1，那它不是素数
    while(!(t&1))  //将x分解成(2^s)*t的样子
    {
        s++;
        t>>=1;
    }
    for(i=0;i<10&&prime[i]<x;++i)      //随便选一个素数进行测试
    {
        int a=prime[i];
        int b=pow(a,t,x);      //先算出a^t
        for(j=1;j<=s;++j)    //然后进行s次平方
        {
            k=mulit(b,b,x);   //求b的平方
            if(k==1&&b!=1&&b!=x-1)     //用二次探测判断
              return false;
            b=k;
        }
        if(b!=1)  return false;   //用费马小定律判断
    }
    return true;   //如果进行多次测试都是对的，那么x就很有可能是素数
}
int main()
{
    int x;
    scanf("%d",&x);
    if(Miller_Rabin(x))  printf("Yes");
    else  printf("No");
    return 0;
}
