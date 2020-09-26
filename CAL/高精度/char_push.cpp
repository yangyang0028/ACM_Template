#include <stdio.h>
#include <string.h>
#define maxn 10000500
char *strrev(char *str){
      char *p1, *p2;
      if (! str || ! *str){
            return str;
      }
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2){
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}
const char *num_plus(char *a,char *b){
  char ans[maxn];
  memset(ans,0,sizeof ans);
	int lena=strlen(a);
	int lenb=strlen(b);
  char *as=ans;
	strrev(a);
	strrev(b);
	int yu=0;
  for(int i=0;;i++){
    if(i<lena&&i<lenb){
      ans[i]=(yu+a[i]-'0'+b[i]-'0')%10+'0';
      yu=(yu+a[i]-'0'+b[i]-'0')/10;
    }else if(i<lena){
      ans[i]=(yu+a[i]-'0')%10+'0';
      yu=(yu+a[i]-'0')/10;
    }else if(i<lenb){
      ans[i]=(yu+b[i]-'0')%10+'0';
      yu=(yu+b[i]-'0')/10;
    }else if(yu!=0){
      ans[i]=yu%10+'0';
      yu=yu/10;
    }else break;
  }
	strrev(ans);
	return as;
}
char a[maxn],b[maxn];
char ans[maxn];
int main(){
	while(~scanf("%s %s", a, b)){
    strcpy(ans,num_plus(a,b));
    printf("%s\n", ans);
  }
  return 0;
}
