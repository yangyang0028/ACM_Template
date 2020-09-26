#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 100000
int ans[maxn];
string num;
string num_mul(string a,string b){
  memset(ans,0,sizeof ans);
  num.clear();
  int lena=a.size();
  int lenb=b.size();
  reverse(a.begin(),a.end());
  reverse(b.begin(),b.end());
  for(int i=0;i<lena;i++){
    for(int j=0;j<lenb;j++){
      ans[i+j]+=(a[i]-'0')*(b[j]-'0');
    }
  }
  int yu=0;
  int i;
  int len=lena+lenb-1;
  for(i=0;;i++){
    if(i<len||yu!=0){
      yu=ans[i]+yu;
      ans[i]=yu%10;
      yu=yu/10;
    }else break;
  }
  while(i--){
    num+=ans[i]+'0';
  }
  return num;
}
string a,b;
int main(){
  while(cin>>a>>b){
    cout<<num_mul(a,b)<<endl;
  }
  return 0;
}
