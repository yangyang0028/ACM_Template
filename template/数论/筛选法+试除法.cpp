#include <bits/stdc++.h>
using namespace std;
#define maxn 11000
bool u[maxn];
int su[maxn];
int a[maxn];
long long s[maxn];
int num=1;
void Es(int n){
  int i,j;
  memset(u,true,sizeof(u));
  for(i=2;i<n;i++){
    if(u[i]) su[num++]=i;
    for(j=1;j<num;j++){
      if(i*su[j]>n) break;
      u[i*su[j]]=false;
      if(i%su[j]==0) break;
    }
  }
}
bool pri(long long n){
  if(n<10000){
    return u[n];
  }else{
    for(int i=1;i<num;i++){
      if(n%su[i]==0) return false;
    }
    return true;
  }
}
