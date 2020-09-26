/*
a%b，在整数除法下它等价于a − a/b × b

*/
#define ll long long
inline ll mulit(ll x,ll y,ll mod)//O1快速乘
{
    return (x*y-(ll)((long double)x/mod*y)*mod+mod)%mod;
}
//////////////////////////////////////////////////////////
ll mulit(ll a,ll b,ll c)//龟速乘
{
    ll ans=0;
    a%=c;
    while(b)
    {
        if(b&1)
        {
         ans+=a;
         if(ans>c){ans-=c;}//大于减c
        }
        a<<=1;
        if(a>=c)a-=c;
        b>>=1;
    }
    return ans;
}
//////////////////////////////////////////////////////////
typedef long long ll;
ll pow(ll x,ll n,ll mod)//快速幂
{
    ll res=1;
	while(n>0)
	{
	   if(n%2==1)
	   {
	   	 res=res*x;
	   	 res=res%mod;
	   }
	   x=x*x;
	   x=x%mod;
	   n>>=1;
	}
	return res;
}
//////////////////////////////////////////////////////////
struct matrix{//矩阵快速幂
	long m[2][2];
}ans;
matrix base={1,1,1,0};
matrix multi(matrix a,matrix b)
{
	matrix tmp;
	for(int i=0;i<2;i++)
	for(int j=0;j<2;j++)
	{
		tmp.m [i][j]=0;
		for(int k=0;k<2;k++)
			tmp.m [i][j]=(tmp.m [i][j]+a.m [i][k]*b.m [k][j])%MOD;
	}return tmp;
}
int matrix_pow(matrix a,int n)
{
	ans.m [0][0]=ans.m [1][1]=1;
	ans.m [0][1]=ans.m [1][0]=0;
	while(n)
	{
		if(n&1)ans=multi(ans,a);
		a=multi(a,a);
		n>>=1;
	}
	return ans.m [0][1];
 }

/////////////////////////////////////////////
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
////////////////////////////////////////
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
