ll num_mod(char a[],ll b){//大数模小数
	ll yu=0;
	int len=strlen(a);
	for(int i=0;i<len;i++){
		yu=yu*10+(a[i]-'0');
		yu=yu%b;
	}
	return yu;
}
