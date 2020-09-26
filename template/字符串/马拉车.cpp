/*
最长回文
HDU - 3068
https://cn.vjudge.net/problem/HDU-3068
题面：最长回文长度
解法：马拉车算法
*/
#include <bits/stdc++.h>
using namespace std;
#define maxn 300005
int radius[maxn];
char s[maxn];
char s_new[maxn];
int init(){
  int len=strlen(s);
  s_new[0]='$';
  s_new[1]='#';
  int j=2;
  for(int i=0;i<len;i++){
    s_new[j++]=s[i];
    s_new[j++]='#';
  }
  s_new[j]='\0';
  return j;
}
int Manacher(){
  int len=init();
  int ans=-1;
  int id;
  int mx=0;
  for(int i=1;i<len;i++){
    if(i<mx) radius[i]=min(radius[2 * id - i], mx - i);
    else radius[i]=1;
    while(s_new[i-radius[i]]==s_new[i+radius[i]]){
      radius[i]++;
    }
    if(mx<i+radius[i]){
      id=i;
      mx=i+radius[i];
    }
    ans=max(ans,radius[i]-1);
  }
  return ans;
}
int main(){
  while(~scanf("%s", s)){
    printf("%d\n", Manacher());
  }
}
