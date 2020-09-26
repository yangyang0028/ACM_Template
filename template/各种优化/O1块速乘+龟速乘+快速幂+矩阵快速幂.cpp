/*
a%b，在整数除法下它等价于a − a/b × b

*/
#define ll long long
inline ll mulit(ll x,ll y,ll mod)//O1快速乘
{
    return (x*y-(ll)((long double)x/mod*y)*mod+mod)%mod;
}
//////////////////////////////////////////////////////////
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
//////////////////////////////////////////////////////////
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
//////////////////////////////////////////////////////////
struct matrix{//矩阵快速幂
	ll m[5][5];
};
matrix matrix_multi(matrix a,matrix b){
	matrix tmp;
	for(int i=0;i<5;i++)
	for(int j=0;j<5;j++){
		tmp.m[i][j]=0;
		for(int k=0;k<5;k++)
			tmp.m[i][j]=((tmp.m[i][j])% (MOD-1) + (a.m[i][k]*b.m[k][j]+MOD-1)% (MOD-1)) % (MOD-1);
	}
	return tmp;
}
matrix matrix_pow(matrix a,matrix b,ll n){
	while(n>0){
		if(n&1) b=matrix_multi(a,b);
		a=matrix_multi(a,a);
		n>>=1;
	}
	return b;
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
