/*
Network
UVA - 315
https://vjudge.net/problem/UVA-315
割点模板题
*/
#include <bits/stdc++.h>
using namespace std;
#define maxn 1000100
struct node{
	int u,v;
	int next;
}edge[maxn];
int dfn[maxn],low[maxn];
int head[maxn];
int cnt,total;
bool ans[maxn];
void init(){
	memset(head,-1,sizeof head);
  memset(ans,false,sizeof ans);
  memset(dfn,0,sizeof dfn);
  memset(low,0,sizeof low);
	cnt=total=0;
}
void add(int u,int v){
	edge[cnt].u=u;
	edge[cnt].v=v;
	edge[cnt].next=head[u];
	head[u]=cnt++;
}
void tarjan(int u,int fa){
	dfn[u]=low[u]=++total;
	int k=0;
	for(int i=head[u];~i;i=edge[i].next){
		int v=edge[i].v;
		if(!dfn[v]){
			k++;
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
			if((u!=fa&&dfn[u]<=low[v])||(u==fa&&k>1)){
				ans[u]=true;
			}
		}else if(fa!=v){
			low[u]=min(low[u],dfn[v]);
		}
	}
}
int n;
int main(){
  int u,v;
  while(~scanf("%d", &n)&&n){
    int num=0;
    init();
    while(scanf("%d", &u)&&u){
      while(getchar()!='\n'){
        scanf("%d", &v);
        add(u,v);
    		add(v,u);
      }
    }
  	for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i,i);
    for(int i=1;i<=n;i++) if(ans[i]) num++;
    printf("%d\n", num);
  }
	return 0;
}
