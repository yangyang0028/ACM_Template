#include <bits/stdc++.h>
using namespace std;
void bag01(int c,int v){
	for(int i=W;i>=c;i--){
		dp[i]=max(dp[i],dp[i-c]+v);
	}
}
void bagall(int c,int v){
	for(int i=c;i<=W;i++){
		dp[i]=max(dp[i],dp[i-c]+v);
	}
}
void bagmul(int c,int v,int n)
{
	if(n*c>W){
		bagall(c,v);
		return;
	}
	int k=1;
	while(n){
		if(n<k)break;
		bag01(c*k,v*k);
		n-=k;
		k<<=1;
	}
	bag01(c*n,v*n);
}
int main(){

  return 0;
}
