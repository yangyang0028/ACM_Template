#include <bits/stdc++.h>
using namespace std;
int main(){
  freopen("1.txt", "w", stdout);
  int n=500;
  char a='a';
  srand(time(NULL));
  for(int i=0;i<n;i++){
    cout<<a;
    a=((a-'a')+1)%26+'a';
  }
  cout<<endl;
  for(int i=0;i<n;i++){
    cout<<a;
    a=(rand())%26+'a';
  }
  cout<<endl;
  n=10000;

  for(int i=0;i<n;i++){
    cout<<a;
    a=(rand())%26+'a';
  }

  return 0;
}
