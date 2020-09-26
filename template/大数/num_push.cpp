void num_plus(char *a,char *b){
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
	strrev(aa);
	printf("%s\n", aa);
	return ;
}
