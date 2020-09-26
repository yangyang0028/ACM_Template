#include <bits/stdc++.h>
using namespace std;
#define maxn 100000
string ans;
int judge(string a,string b){
  int lena=a.size();
  int lenb=b.size();
  if(lena>lenb) return 1;
  if(lena<lenb) return -1;
  if(a>b) return 1;
  if(a==b) return 0;
  if(a<b) return -1;
}
string num_mul(string a,string b){
  string aa,bb;
  aa.clear();
  bb.clear();
  ans.clear();
  bool bo;
  int cnt=judge(a,b);
  if(cnt>0){
    aa=a;
    bb=b;
    bo=false;
  }else if(cnt<0){
    aa=b;
    bb=a;
    bo=true;
  }else if(cnt==0){
    ans+='0';
    return ans;
  }
  reverse(aa.begin(),aa.end());
  reverse(bb.begin(),bb.end());
  int lena=aa.size();
  int lenb=bb.size();
  int i;
  for(i=0;;i++){
    if(i<lena&&i<lenb){
      if(aa[i]>=bb[i]){
        ans+=aa[i]-bb[i]+'0';
      }else{
        ans+=aa[i]-bb[i]+10+'0';
        for(int j=i+1;;j++){
          if(aa[j]=='0') aa[j]='9';
          else {
            aa[j]--;
            break;
          }
        }
      }
    }else if(i<lena){
      ans+=aa[i];
    }else if(i<lenb){
      ans+=bb[i];
    }else break;
  }
  while(i--){
    if(ans[i]-'0'>0){
      break;
    }
  }
  ans.erase(i+1,lena-i);
  if(bo) ans+='-';
  reverse(ans.begin(),ans.end());
  return ans;
}
string a,b;
int main(){
  while(cin>>a>>b){
      cout<<num_mul(a,b)<<endl;
  }
  return 0;
}
