/*
What a Ridiculous Election
UVALive - 7672
https://cn.vjudge.net/problem/UVALive-7672
解法； BFS
Sample Input
    12435
    99999
    12374
Sample Output
    1
    -1
    3
注意 1+1=2, 1*2=2,这两种要分开记录，否则会影响接下来的bfs
    所有必须开三维数组来存，
*/
#include <bits/stdc++.h>
using namespace std;
struct node{
  int num,add,mul;
};
int has[100000][4][3];
char c[6];
char cc;
int pp[10]={10000,1000,100,10,1,0};
int num,numm;
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
int solve(){
	int ans=0;
	for(int i=0;i<5;i++){
		ans=ans*10+c[i]-'0';
	}
	return ans;
}
void bfs(){
  queue<node> q;
  q.push(node{12345,0,0});
  has[12345][0][0]=1;
  while(!q.empty()){
    node us=q.front();
    q.pop();
    int u=us.num;
    int ua=us.add;
    int um=us.mul;
    int uu=u;
		for(int i=0;i<5;i++){
			c[i]=uu%10+'0';
			uu=uu/10;
		}
		strrev(c);
    for(int i=1;i<5;i++){
			if(c[i]!=c[i-1]){
				cc=c[i];
				c[i]=c[i-1];
				c[i-1]=cc;
				num=solve();
				if(has[num][ua][um]==0){
					has[num][ua][um]=has[u][ua][um]+1;
					q.push(node{num,ua,um});
				}
				cc=c[i];
				c[i]=c[i-1];
				c[i-1]=cc;
			}
		}
    for(int i=0;i<5;i++){
      num=solve()-(c[i]-'0')*pp[i];
      numm=((c[i]-'0'+1)%10)*pp[i];
      num+=numm;
      if(ua+1<4&&has[num][ua+1][um]==0){
        has[num][ua+1][um]=has[u][ua][um]+1;
        q.push(node{num,ua+1,um});
      }
      num=solve()-(c[i]-'0')*pp[i];
      numm=(((c[i]-'0')*2)%10)*pp[i];
      num+=numm;
      if(um+1<3&&has[num][ua][um+1]==0){
        has[num][ua][um+1]=has[u][ua][um]+1;
        q.push(node{num,ua,um+1});
      }
    }
  }
}
int main(){
  int n;
  bfs();
  while(~scanf("%d", &n)){
    int ans=0x3f3f3f3f;
    for(int i=0;i<4;i++){
      for(int j=0;j<3;j++){
        if(has[n][i][j]!=0)
        ans=min(has[n][i][j],ans);
      }
    }
    if(ans==0x3f3f3f3f) ans=0;
    printf("%d\n", ans-1);
  }
  return 0;
}
