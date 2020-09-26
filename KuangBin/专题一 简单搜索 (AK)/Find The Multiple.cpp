#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <limits.h>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
int n,bo;
void dfs(int k,long long ans){
  if(k==19||bo) return ;
  if(ans%n==0){
    printf("%lld\n", ans);
    bo=1;
    return ;
  }
  dfs(k+1,ans*10+0);
  dfs(k+1,ans*10+1);
}
int main(){
  while(~scanf("%d", &n),n){
    bo=0;
    dfs(0,1);
  }
  return 0;
}
