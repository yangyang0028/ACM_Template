/*
https://www.luogu.org/problem/P3375
P3375
【模板】KMP字符串匹配
*/
#include<iostream>
#include<cstdio>
#include<queue>
#include<stack>
#include<cstring>
using namespace std;
#define maxn 1000005
char s[maxn];
char p[maxn];
int ans[maxn];
int next_[maxn];
int cnt;
int lens,lenp;
void build(){
  next_[0]=-1;
  int k=-1;
  for(int i=1;i<lenp;i++){
    while(k!=-1&&p[k+1]!=p[i]) k=next_[k];
    if(p[k+1]==p[i]) k++;
    next_[i]=k;
  }
}
void kmp(){
  cnt=0;
  lenp=strlen(p);
  lens=strlen(s);
  build();
  int j=-1;
  for(int i=0;i<lens;i++){
    while(j!=-1&&p[j+1]!=s[i]) j=next_[j];
    if(p[j+1]==s[i]) j++;
    if(j==lenp-1){
      ans[cnt++]=i-lenp+2;
      j=next_[j];
    }
  }
}
int main(){
  scanf("%s%s", s, p);
  kmp();
  for(int i=0;i<cnt;i++){
    printf("%d\n", ans[i]);
  }
  for(int i=0;i<lenp;i++){
    printf("%d ", next_[i]+1);
  }
  return 0;
}
