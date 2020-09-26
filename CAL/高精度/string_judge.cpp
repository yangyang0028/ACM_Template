#include <bits/stdc++.h>
using namespace std;
string a,b;
int judge(string a,string b){
  int lena=a.size();
  int lenb=b.size();
  if(lena>lenb) return 1;
  if(lena<lenb) return -1;
  if(a>b) return 1;
  if(a==b) return 0;
  if(a<b) return -1;
}
int main(){
  while(cin>>a>>b){
      cout<<judge(a,b)<<endl;
  }
  return 0;
}
