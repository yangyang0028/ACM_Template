/*
Strongly connected
HDU - 4635
https://vjudge.net/problem/HDU-4635
有向图，给定若干个连通图，求最多还能添加几条边，添完边后，图仍然要满足
没有重边或者自环并且不是有向强连通图

这是一个单向图，如果强连通的话，他最多应该有n*(n-1)条边，
假设有a个强连通块，任取其中一个强连通块,
假设取出的这个强连通块里有x个点，
剩下的（n-a）个点看成一个强连通块，
如果让这两个强连通块之间不联通，
肯定是这两个只有一个方向的边,
最多就会有x*(n-x)条边
所以最多加n*(n-1)-x*x(n-x)-m边。
所以当x最小是式子最大。
*/
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
using namespace std;
#define maxm 2000010
#define maxn 100010
#define ll long long
struct Edge{
	int v,next;
}edge[maxm];
int head[maxn];
int dfn[maxn],low[maxn];
int belong[maxn];
int block_num[maxn];
int vis[maxn];
int du[maxn];
int cnt,total,block,top;
int in[maxn],out[maxn];
int st[maxn];
void add(int u,int v){
	edge[cnt].v=v;
	edge[cnt].next=head[u];
	head[u]=cnt++;
}
void init(int n){
	memset(head,-1,sizeof head);
	memset(dfn,0,sizeof dfn);
	memset(low,0,sizeof low);
	memset(belong,0,sizeof belong);
  memset(in,0,sizeof in);
  memset(out,0,sizeof out);
  memset(block_num,0,sizeof block_num);
  memset(st,0,sizeof st);
  memset(vis,false,sizeof vis);
	cnt=total=block=top=0;
}
void tarjan(int u){
	dfn[u]=low[u]=++total;
  vis[u]=true;
	st[top++]=u;
	for(int i=head[u];~i;i=edge[i].next){
		int v=edge[i].v;
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}else if(vis[v]){
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(low[u]==dfn[u]){
		block++;
			while(1){
					int t=st[--top];
					belong[t]=block;
          block_num[block]++;
          vis[t]=false;
					if(t==u) break;
			}
	}
}
void solve(int n,int m){
  for(int i=1;i<=n;i++){
      if(!dfn[i]) tarjan(i);
  }
  if(block==1){
    printf("-1\n");
    return ;
  }
  for(int u=1;u<=n;u++){
    for(int i=head[u];~i;i=edge[i].next){
      int uu=belong[u];
      int vv=belong[edge[i].v];
      if(uu!=vv){
        in[vv]++;
        out[uu]++;
      }
    }
  }
  ll ans=(ll)n*(n-1)-m;
  int minn=0x3f3f3f3f;
  for(int i=1;i<=block;i++){
    if(!in[i]||!out[i]){
      minn=min(minn,block_num[i]);
    }
  }
  ans-=(ll)(minn)*(n-minn);
  cout<<ans<<endl;
}
int main(){
	int n,m;
	int u,v;
  int T,t=0;
  scanf("%d", &T);
  while(T--){
    scanf("%d %d", &n, &m);
    init(n);
    for(int i=0;i<m;i++){
      scanf("%d %d", &u, &v);
      add(u,v);
    }
    printf("Case %d: ", ++t);
    solve(n,m);
	}
	return 0;
}
