//http://codeforces.com/contest/1191/problem/B
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int mp[3][4];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	memset(mp,0,sizeof mp);
	int a;
	char b;
	for(int i=0;i<3;i++){
		scanf("%d%c", &a, &b);
		if(b=='m') mp[0][++mp[0][0]]=a;
		if(b=='p') mp[1][++mp[1][0]]=a;
		if(b=='s') mp[2][++mp[2][0]]=a;
	}
	sort(mp[0]+1,mp[0]+4,cmp);
	sort(mp[1]+1,mp[1]+4,cmp);
	sort(mp[2]+1,mp[2]+4,cmp);
	if(mp[0][0]==3){
		if(mp[0][1]==mp[0][2]&&mp[0][2]==mp[0][3]){
			printf("0\n");
			return 0;
		}else if(mp[0][1]-mp[0][2]==1&&mp[0][2]-mp[0][3]==1){
			printf("0\n");
			return 0;
		}else if(mp[0][1]-mp[0][2]==1||mp[0][2]-mp[0][3]==1){
			printf("1\n");
			return 0;
		}else if(mp[0][1]-mp[0][2]==0||mp[0][2]-mp[0][3]==0){
			printf("1\n");
			return 0;
		}else if(mp[0][1]-mp[0][2]==2||mp[0][2]-mp[0][3]==2){
			printf("1\n");
			return 0;
		}else{
			printf("2\n");
			return 0;
		}
	}else if(mp[1][0]==3){
		if(mp[1][1]==mp[1][2]&&mp[1][2]==mp[1][3]){
			printf("0\n");
			return 0;
		}else if(mp[1][1]-mp[1][2]==1&&mp[1][2]-mp[1][3]==1){
			printf("0\n");
			return 0;
		}else if(mp[1][1]-mp[1][2]==1||mp[1][2]-mp[1][3]==1){
			printf("1\n");
			return 0;
		}else if(mp[1][1]-mp[1][2]==0||mp[1][2]-mp[1][3]==0){
			printf("1\n");
			return 0;
		}else if(mp[1][1]-mp[1][2]==2||mp[1][2]-mp[1][3]==2){
			printf("1\n");
			return 0;
		}else{
			printf("2\n");
			return 0;
		}
	}else if(mp[2][0]==3){
		if(mp[2][1]==mp[2][2]&&mp[2][2]==mp[2][3]){
			printf("0\n");
			return 0;
		}else if(mp[2][1]-mp[2][2]==1&&mp[2][2]-mp[2][3]==1){
			printf("0\n");
			return 0;
		}else if(mp[2][1]-mp[2][2]==1||mp[2][2]-mp[2][3]==1){
			printf("1\n");
			return 0;
		}else if(mp[2][1]-mp[2][2]==0||mp[2][2]-mp[2][3]==0){
			printf("1\n");
			return 0;
		}else if(mp[2][1]-mp[2][2]==2||mp[2][2]-mp[2][3]==2){
			printf("1\n");
			return 0;
		}else{
			printf("2\n");
			return 0;
		}
	}else if(mp[0][0]==2){
		if(mp[0][1]==mp[0][2]){
			printf("1\n");
			return 0;
		}else if(mp[0][1]-mp[0][2]==1){
			printf("1\n");
			return 0;
		}else if(mp[0][1]-mp[0][2]==2){
			printf("1\n");
			return 0;
		}else{
			printf("2\n");
			return 0;
		}
	}else if(mp[1][0]==2){
		if(mp[1][1]==mp[1][2]){
			printf("1\n");
			return 0;
		}else if(mp[1][1]-mp[1][2]==1){
			printf("1\n");
			return 0;
		}else if(mp[1][1]-mp[1][2]==2){
			printf("1\n");
			return 0;
		}else {
			printf("2\n");
			return 0;
		}
	}else if(mp[2][0]==2){
		if(mp[2][1]==mp[2][2]){
			printf("1\n");
			return 0;
		}else if(mp[2][1]-mp[2][2]==1){
			printf("1\n");
			return 0;
		}else if(mp[2][1]-mp[2][2]==2){
			printf("1\n");
			return 0;
		}else {
			printf("2\n");
			return 0;
		}
	}else{
		printf("2\n");
		return 0;
	}
	return 0;
}
