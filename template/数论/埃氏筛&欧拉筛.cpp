#include <algorithm>
#include <stdio.h>
#include <string.h>
#define maxn 10000010
using namespace std;
bool u[maxn];
int su[maxn];
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
void Is(int n){
  memset(u,true,sizeof(u));
  for(int i=2;i<n;i++){
    if(u[i]){
      su[num++]=i;
      for(int j=i+i;j<n;j+=i){
        u[j]=false;
      }
    }
  }
}
