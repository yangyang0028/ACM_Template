#include <bits/stdc++.h>
using namespace std;
#define maxn 100000
char a[maxn],b[maxn];
int judge(char *a, char *b){
  int lena=strlen(a);
  int lenb=strlen(b);
  if(lena>lenb) return 1;
  if(lena<lenb) return -1;
  return strcmp(a,b);
}
int main(){
  while(cin>>a>>b){
      cout<<judge(a,b)<<endl;
  }
  return 0;
}
