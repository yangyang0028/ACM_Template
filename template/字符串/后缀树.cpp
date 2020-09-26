#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define maxn 10005
char c[maxn];
struct SAM{
  struct Node{
    int ch[26];
    int f,len;
    void init(){
      f=-1;
      len=0;
      memset(ch,-1,sizeof ch);
    }
  };
  Node sn[maxn<<1];
  int idx,last;
  void init(){
    idx=last=0;
    sn[idx++].init();
  }
  int newnode(){
    sn[idx].init();
    return idx++;
  }
  void add(int c){
    int end=newnode();
    int tmp=last;
    sn[end].len=sn[last].len+1;
    for(;tmp!=-1&&sn[tmp].ch[c]==-1;tmp=sn[tmp].f){
      sn[tmp].ch[c]=end;
    }
    if(tmp==-1) sn[end].f=0;
    else{
      int nxt=sn[tmp].ch[c];
      if(sn[tmp].len+1==sn[nxt].len){
        sn[end].f=nxt;
      }else{
        int  np=newnode();
        sn[np]=sn[nxt];
        sn[np].len=sn[tmp].len+1;
        sn[end].f=sn[nxt].f=np;
        for(;tmp!=-1&&sn[tmp].ch[c]==nxt;tmp=sn[tmp].f){
          sn[tmp].ch[c]=np;
        }
      }
    }
    last=end;
  }
};
SAM sam;
int main(){
  int T;
  cin>>T;
  while(T--){
    sam.init();
    cin>>c;
    int len=strlen(c);
    for(int i=0;i<len*2;i++){
      sam.add(c[i%len]-'a');
    }
    int p = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < 26; ++j) {
            if (sam.sn[p].ch[j] != -1) {
                p = sam.sn[p].ch[j];
                break;
            }
        }
    }
    cout<<sam.sn[p].len-len+1<<endl;
  }
  return 0;
}
