//http://codeforces.com/contest/1182/problem/E
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;
struct matrix{//矩阵快速幂
	ll m[5][5];
};
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
matrix matrix_pow(matrix a,matrix b,ll n)
{
	while(n>0)
	{
		if(n&1) b=matrix_multi(a,b);
		a=matrix_multi(a,a);
		n>>=1;
	}
	return b;
}

ll ff3(ll f3, ll n){
	if(n==4) return pow(f3,1,MOD);
	if(n==5) return pow(f3,2,MOD);
	if(n==6) return pow(f3,4,MOD);
  matrix a,b;
	memset(a.m,0,sizeof a.m);
	memset(b.m,0,sizeof b.m);
	a.m[0][0]=1; a.m[0][1]=1; a.m[0][2]=1;
	a.m[1][0]=1; a.m[1][1]=0; a.m[1][2]=0;
	a.m[2][0]=0; a.m[2][1]=1; a.m[2][2]=0;

	b.m[0][0]=4; b.m[0][1]=0; b.m[0][2]=0;
	b.m[1][0]=2; b.m[1][1]=0; b.m[1][2]=0;
	b.m[2][0]=1; b.m[2][1]=0; b.m[2][2]=0;

	matrix ans=matrix_pow(a,b,n-6);
	return pow(f3,ans.m[0][0],MOD);
}

ll ff2(ll f2,ll n){
	if(n==4) return pow(f2,1,MOD);
	if(n==5) return pow(f2,2,MOD);
	if(n==6) return pow(f2,3,MOD);
	matrix a,b;
	memset(a.m,0,sizeof a.m);
	memset(b.m,0,sizeof b.m);
	a.m[0][0]=1; a.m[0][1]=1; a.m[0][2]=1;
	a.m[1][0]=1; a.m[1][1]=0; a.m[1][2]=0;
	a.m[2][0]=0; a.m[2][1]=1; a.m[2][2]=0;

	b.m[0][0]=3; b.m[0][1]=0; b.m[0][2]=0;
  b.m[1][0]=2; b.m[1][1]=0; b.m[1][2]=0;
  b.m[2][0]=1; b.m[2][1]=0; b.m[2][2]=0;

	matrix ans=matrix_pow(a,b,n-6);
	return pow(f2,ans.m[0][0],MOD);

}

ll ff1(ll f1,ll n){
	if(n==4) return pow(f1,1,MOD);
	if(n==5) return pow(f1,1,MOD);
	if(n==6) return pow(f1,2,MOD);
	matrix a,b;
	memset(a.m,0,sizeof a.m);
	memset(b.m,0,sizeof b.m);
	a.m[0][0]=1; a.m[0][1]=1; a.m[0][2]=1;
	a.m[1][0]=1; a.m[1][1]=0; a.m[1][2]=0;
	a.m[2][0]=0; a.m[2][1]=1; a.m[2][2]=0;

	b.m[0][0]=2; b.m[0][1]=0; b.m[0][2]=0;
	b.m[1][0]=1; b.m[1][1]=0; b.m[1][2]=0;
	b.m[2][0]=1; b.m[2][1]=0; b.m[2][2]=0;

	matrix ans=matrix_pow(a,b,n-6);
	return pow(f1,ans.m[0][0],MOD);

}

ll cc(ll c,ll n){

  if(n==4) return  pow(c,2,MOD);
  if(n==5) return  pow(c,6,MOD);
  if(n==6) return  pow(c,14,MOD);
  matrix a,b;
	memset(a.m,0,sizeof a.m);
	memset(b.m,0,sizeof b.m);
  b.m[0][0]=14;
  b.m[1][0]=6;
  b.m[2][0]=2;
  b.m[3][0]=7;
  b.m[4][0]=1;

  a.m[0][0]=1; a.m[0][1]=1; a.m[0][2]=1; a.m[0][3]=2; a.m[0][4]=-6;
  a.m[1][0]=1; a.m[1][1]=0; a.m[1][2]=0; a.m[1][3]=0; a.m[1][4]=0;
  a.m[2][0]=0; a.m[2][1]=1; a.m[2][2]=0; a.m[2][3]=0; a.m[2][4]=0;
  a.m[3][0]=0; a.m[3][1]=0; a.m[3][2]=0; a.m[3][3]=1; a.m[3][4]=1;
  a.m[4][0]=0; a.m[4][1]=0; a.m[4][2]=0; a.m[4][3]=0; a.m[4][4]=1;

  matrix ans=matrix_pow(a,b,n-6);
	return pow(c,ans.m[0][0],MOD);

}

void solve(){
	ll n,f1,f2,f3,c;
	scanf("%lld %lld %lld %lld %lld", &n, &f1, &f2, &f3, &c);
	if(n==1){
    printf("%lld\n", f1);
    return ;
  }
  if(n==2){
    printf("%lld\n", f2);
    return ;
  }
  if(n==3){
    printf("%lld\n", f3);
    return ;
  }
	ll anss=1;
	 anss=( anss * ff1(f1,n))%MOD;
	 anss=( anss * ff2(f2,n))%MOD;
	 anss=( anss * ff3(f3,n))%MOD;
	 anss=( anss * cc(c,n))%MOD;
  printf("%lld\n", anss);
	return ;
}
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		solve();
	}
  return 0;
}
