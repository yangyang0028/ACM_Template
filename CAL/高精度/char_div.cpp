#include <bits/stdc++.h>
using namespace std;
#define maxn 1000
char anss[maxn];
char ans[maxn];
char *strrev(char *str)
{
      char *p1, *p2;
      if (! str || ! *str)
      {
            return str;
      }
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}
int judge(char *a, char *b){
  int lena=strlen(a);
  int lenb=strlen(b);
  if(lena>lenb) return 1;
  if(lena<lenb) return -1;
  return strcmp(a,b);
}
const char *num_sub(char *a, char *b){
  char aa[maxn],bb[maxn];
  memset(aa,0,sizeof aa);
  memset(bb,0,sizeof bb);
  memset(ans,0,sizeof ans);
  char *as=ans;
  int cnt=judge(a,b);
  bool bo=false;
  if(cnt>0){
    strcpy(aa,a);
    strcpy(bb,b);
    bo=false;
  }else if(cnt<0){
    strcpy(aa,b);
    strcpy(bb,a);
    bo=true;
  }else{
    ans[0]='0';
    return as;
  }
  int lena=strlen(aa);
  int lenb=strlen(bb);
  strrev(aa);
  strrev(bb);
  int i;
  for(i=0;;i++){
    if(i<lena&&i<lenb){
      if(aa[i]>=bb[i]){
        ans[i]=aa[i]-bb[i]+'0';
      }else {
        ans[i]=aa[i]-bb[i]+10+'0';
        for(int j=i+1;;j++){
          if(aa[j]=='0') aa[j]='9';
          else{
            aa[j]--;
            break;
          }
        }
      }
    }else if(i<lena){
      ans[i]=aa[i];
    }else if(i<lenb){
      ans[i]=bb[i];
    }else break;
  }
  while(i--){
    ans[i+1]='\0';
    if(ans[i]-'0'>0){
      break;
    }
  }
  if(bo) ans[i+1]='-';
  strrev(ans);
  return as;
}
char *num_div(char *a, char *b){
  memset(anss,0,sizeof anss);
  int nu=0;
  int lena=strlen(a);
  int lenb=strlen(b);
  for(int i=lenb;i<lena;i++){
    b[i]='0';
  }
  while(lena-->=lenb){
    int i=0;
    while(judge(a,b)>=0){
      i++;
      strcpy(a,num_sub(a,b));
    }
    anss[nu++]=i+'0';
    b[lena]='\0';
  }
  if(anss[0]=='\0'){
    anss[0]='0';
    return anss;
  }
  if(anss[0]=='0')
  return anss+1;
  return anss;
}
char a[maxn],b[maxn];
int main(){
  while(~scanf("%s %s", a, b)){
    printf("%s\n", num_div(a,b));
    cout<<a<<endl;
  }
}
