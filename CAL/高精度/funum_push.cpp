#include <bits/stdc++.h>
using namespace std;
#define maxn 100000
void num_plus(char *a,char *b,int num){
	char aa[maxn];
	memset(aa,0,sizeof aa);
  int lena=strlen(a);
  int lenb=strlen(b);
  strrev(a);
  strrev(b);
	int len=max(lena,lenb);
	int yu=0;
	int i=0;
	while(1){
		if(i<lena&&i<lenb){
			yu=(a[i]-'0')+(b[i]-'0')+yu;
			aa[i]=yu%10+'0';
			yu=yu/10;
		}else if(i<lena){
			yu=(a[i]-'0')+yu;
			aa[i]=yu%10+'0';
			yu=yu/10;
		}else if(i<lenb){
			yu=(b[i]-'0')+yu;
			aa[i]=yu%10+'0';
			yu=yu/10;
		}else if(yu!=0){
			aa[i]=yu%10+'0';
			yu=yu/10;
		}else break;
		++i;
	}
  int s;
  for(s=0;s<num;s++){
    if(aa[s]!='0'){
      break;
    }
  }
  num-=s;
  i-=s+1;
  num=i-num;
	strrev(aa);
  for(int j=0;j<=i;j++){
    printf("%c", aa[j]);
    if(j==num&&num!=i) printf(".");
  }
	printf("\n");
	return ;
}

void funum_plus(char *a, char *b){
  char aa[maxn],bb[maxn];
  memset(aa,0,sizeof aa);
  memset(bb,0,sizeof bb);
  int lena=strlen(a);
  int lenb=strlen(b);
  int fua=lena,fub=lenb;//行寻找小数点，要是找到记录位置，否则末尾添加小数点
  for(int i=0;i<lena;i++){
    if(a[i]=='.'){
      fua=i;
      break;
    }
  }
  for(int i=0;i<lenb;i++){
    if(b[i]=='.'){
      fub=i;
      break;
    }
  }
  if(fua==lena) a[lena]='.',lena++;
  if(fub==lenb) b[lenb]='.',lenb++;
  int j=0;//将小数点后面的位数填0，使小数点后面位数相同
  while(1){
    j++;
    if(fua+j<lena&&fub+j<lenb){
      continue;
    }else if(fua+j<lena){
      b[fub+j]='0';
    }else if(fub+j<lenb){
      a[fua+j]='0';
    }else break;
  }
  lena+=j;
  lenb+=j;
  int la=0,lb=0;
  for(int i=0;i<lena;i++){
    if(i!=fua) aa[la++]=a[i];
  }
  for(int i=0;i<lenb;i++){
    if(i!=fub) bb[lb++]=b[i];
  }
  num_plus(aa,bb,j-1);
}

char a[maxn],b[maxn];
int main(){
    while(~scanf("%s %s", a, b)){
      funum_plus(a,b);
      memset(a,0,sizeof a);
      memset(b,0,sizeof b);
    }
  return 0;
}
