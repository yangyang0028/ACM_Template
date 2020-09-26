#include <cstdio>
#include <string.h>
using namespace std;
int f[10000];
int g[10000];
int n,m,ans;
void bl(int n){
	int s=n;
	int d=s/1000;
	s=s%1000;
	int c=s/100;
	s=s%100;
	int b=s/10;
	s=s%10;
	int a=s;
	//printf("%d\n", n);
	int e=n;
	for(int i=0;i<=9;i++){
		e=d*1000+c*100+b*10+i;
		if(f[e]==0&&g[e]==0)
			g[e]=ans+1;
	}
	e=n;
	for(int i=0;i<=9;i++){
		e=d*1000+c*100+a+i*10;
		if(f[e]==0&&g[e]==0)
			g[e]=ans+1;
	}
	e=n;
	for(int i=0;i<=9;i++){
		e=d*1000+b*10+a+i*100;
		if(f[e]==0&&g[e]==0)
			g[e]=ans+1;
	}
	e=n;
	for(int i=0;i<=9;i++){
		e=c*100+b*10+a+i*1000;
		if(f[e]==0&&g[e]==0)
			g[e]=ans+1;
	}
}
int bfs(){
	if(g[m]!=0){
		return ans;
	}
	ans++;
	for(int i=1000;i<10000;i++){
		if(g[i]==ans){
			bl(i);
		}
	}
	bfs();
}
int main() {
	for(int i=2;i<10000;i++){
		for(int j=i+i;j<10000;j+=i){
			f[j]=1;
		}
	}
	int s;
	scanf("%d", &s);
	while(s--){
		ans=0;
		memset(g,0,sizeof(g));
		scanf("%d %d", &n, &m);
		g[n]=1;
		printf("%d\n",bfs());
	}
	return 0;
}
