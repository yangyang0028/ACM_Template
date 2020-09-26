#include <bits/stdc++.h>
using namespace std;
#define maxn 205
#define INF 0x3f3f3f3f
#define ll long long
int B[maxn][maxn];
ll n,mod;
ll det(){
  ll ans=1;
  for(int i=1;i<=n;i++){
    for(int j=i+1;j<=n;j++){
      while(B[j][i]){
        ll t=B[i][i]/B[j][i];
        for(int k=i;k<=n;k++){
          B[i][k]=(B[i][k]-B[j][k]*t%mod+mod)%mod;
          swap(B[i][k],B[j][k]);
        }
        ans=-ans;
      }
    }
    if(B[i][i]==0) return 0;
    ans=(ans*B[i][i])%mod;
  }
  return (ans+mod)%mod;
}
int main(){
  while(~scanf("%lld %lld", &n, &mod)){
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        scanf("%lld", &B[i][j]);
        B[i][j]%=mod;
      }
    }
    printf("%lld\n", det());
  }
}
