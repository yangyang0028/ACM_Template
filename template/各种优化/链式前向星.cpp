#include<bits/stdc++.h>
using namespace std;
#define MAXN 100501
struct NODE{
	int w;
	int e;
	int next; //next[i]表示与第i条边同起点的上一条边的储存位置
}edge[MAXN];
int cnt;
int head[MAXN];
void add(int u,int v,int w){
	edge[cnt].w=w;
	edge[cnt].e=v;    //edge[i]表示第i条边的终点
	edge[cnt].next=head[u]; //head[i]表示以i为起点的最后一条边的储存位置
	head[u]=cnt++;
}
int main(){
	memset(head,0,sizeof(head));
	cnt=1;
	int n;
	cin>>n;
	int a,b,c;
	while(n--){
		cin>>a>>b>>c;
		add(a,b,c);
	}
	int start;
	cin>>start;
	for(int i=head[start];i!=0;i=edge[i].next)
	   cout<<start<<"->"<<edge[i].e<<" "<<edge[i].w<<endl;
	return 0;
}
