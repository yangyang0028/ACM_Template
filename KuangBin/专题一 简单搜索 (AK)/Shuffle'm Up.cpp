#include <iostream>
#include <map>
#include <string>
using namespace std;
string a,b,c,e;
int d,num;
map<string,int> m;
int main(){
  int t;
  cin>>t;
  for(int s=1;s<=t;s++){
    m.clear();
    num=0;
    cin>>d;
    cin>>a>>b>>c;
    e=c;
    int n=d*2-1;
    while(1){
      num++;
      for(int i=1;i<=n;i+=2){
        e[i]=a[i/2];
      }
      for(int i=0;i<=n;i+=2){
        e[i]=b[i/2];
      }
      if(e==c) break;
      if(m[e]){
        num=-1;
        break;
      }
      m[e]=1;
      for(int i=0;i<d;i++){
        a[i]=e[i];
      }
      for(int i=d;i<=n;i++){
        b[i-d]=e[i];
      }
    }
    cout<<s<<" "<<num<<endl;
  }
  return 0;
}
