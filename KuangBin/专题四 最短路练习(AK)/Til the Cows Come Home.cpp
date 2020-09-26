/*
Til the Cows Come Home
POJ - 2387
https://cn.vjudge.net/problem/POJ-2387
题意：最短路裸题
输入：点 边
      u -> v w
样例输入：
      5 5
      1 2 20
      2 3 30
      3 4 20
      4 5 20
      1 5 100
样例输出：
      90
解法：
      SPFA
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<iostream>
using namespace std;
#define INF 0x3f3f3f
#define maxn 10010
struct node{
  int u;
  int v;
  int w;
  int next;
}edge[maxn],uedge[maxn];
int cnt,ucnt;
int t,n;
int head[maxn],uhead[maxn];
int dis[maxn], udis[maxn];
void init(){
  memset(head,0,sizeof head);
  memset(dis,INF,sizeof dis);
  cnt=1;
}
void add(int u, int v, int w, node edge[], int &cnt,int *head){
  edge[cnt].w=w;
  edge[cnt].u=u;
  edge[cnt].v=v;
  edge[cnt].next=head[u];
  head[u]=cnt++;
}
void spfa(int st,int dis[],int head[],node edge[]) {
	dis[st] = 0;
	queue<int>q;
	q.push(st);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = head[u]; i!=0; i = edge[i].next) {
			int v = edge[i].v;
			if (dis[v] > dis[u] + edge[i].w) {
				dis[v] = dis[u] +  edge[i].w;
				q.push(v);
			}
		}
	}
	return;
}
int main(){
  while(~scanf("%d %d", &t, &n)){
    init();
    int u,v,w;
    for(int i=0;i<t;i++){
      scanf("%d %d %d", &u, &v, &w);
      add(u, v, w, edge, cnt, head);
      add(v, u, w, edge, cnt, head);
      //add(v, u, w, uedge, ucnt, uhead);
    }
    spfa(1, dis, head, edge);
    cout<<dis[n]<<endl;
  }
  return 0;
}
