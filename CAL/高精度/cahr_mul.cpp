#include <stdio.h>
#include <string.h>
using namespace std;
#define maxn 500000
int ans[maxn];
char num[maxn];
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
char* num_mul(char *a, char *b){
  memset(ans,0,sizeof ans);
  memset(num,0,sizeof num);
  char *as=num;
  int nu=0;
  memset(ans,0,sizeof ans);
  int lena=strlen(a);
  int lenb=strlen(b);
  strrev(a);
  strrev(b);
  for(int i=0;i<lena;i++){
    for(int j=0;j<lenb;j++){
        ans[i+j]+=(a[i]-'0')*(b[j]-'0');
    }
  }
  int i;
  int yu=0;
  int len=lena+lenb-1;
  for(i=0;;i++){
    if(i<len||yu!=0){
      yu=ans[i]+yu;
      ans[i]=yu%10;
      yu=yu/10;
    }else break;
  }
  while(i--){
    num[nu++]=ans[i]+'0';
  }
  return num;
}
char a[maxn],b[maxn];
int main(){
  while(~scanf("%s %s", a, b)){
    if(strcmp(a,"0")==0) printf("0\n");
    else if(strcmp(b,"0")==0) printf("0\n");
    else printf("%s\n", num_mul(a,b));
  }
  return 0;
}
