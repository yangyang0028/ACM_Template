#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define maxn 20
int mp[maxn][maxn];
int mp_1[maxn][maxn];
int ans_mp[maxn][maxn];
int ans_1[maxn][maxn];
int n,m;
int solve(){
	int cnt=0;
	int x=0;
	for(int y=0;y<m;y++){
		if(ans_1[x][y]==1){
			cnt++;
			if(y-1>=0) mp[x][y-1]=!mp[x][y-1];
			if(y+1<m) mp[x][y+1]=!mp[x][y+1];
			if(x+1<n) mp[x+1][y]=!mp[x+1][y];
			mp[x][y]=!mp[x][y];
		}
	}
	while(x<n){
			x++;
		for(int y=0;y<m;y++){
			if(mp[x-1][y]==1){
				ans_1[x][y]=1;
				cnt++;
				mp[x-1][y]=0;
				if(x+1<n) mp[x+1][y]=!mp[x+1][y];
				if(y-1>=0) mp[x][y-1]=!mp[x][y-1];
				if(y+1<m) mp[x][y+1]=!mp[x][y+1];
				mp[x][y]=!mp[x][y];
			}
		}
	}
	for(int i=0;i<m;i++){
		if(mp[n][i]==1)
		return -1;
	}
	return cnt;
}
int main(){
	while(~scanf("%d %d", &n, &m)){
		int ans=0x3f3f3f;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				scanf("%d", &mp_1[i][j]);
			}
		}
		int l=1<<m;
		for(int i=0;i<l;i++){
			memcpy(mp,mp_1,sizeof mp_1);
			memset(ans_1,0,sizeof ans_1);
			for(int j=0;j<m;j++) ans_1[0][n-1-j]=(i>>j)&1;
			int a=solve();
			//cout<<ans<<endl;
			if(a!=-1&&ans>a){
				memcpy(ans_mp,ans_1,sizeof ans_1);
				ans=a;
			}
		}
		if(ans==0x3f3f3f) printf("IMPOSSIBLE\n");
		else{
			for(int i=0;i<n;i++){
        printf("%d", ans_mp[i][0]);
        for(int j=1;j<m;j++){
          printf(" %d", ans_mp[i][j]);
        }
        printf("\n");
      }
		}
	}
	return 0;
}
