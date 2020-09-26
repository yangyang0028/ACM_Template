#include <bits/stdc++.h>
using namespace std;
#define maxn 1000000
#define ll long long
#define INF 0x3f3f3f3f
struct node{
  int u,v,w;
  int next;
}edge[maxn];
int head[maxn];
ll dis[maxn];
int cnt,n,t;
void init(){
  memset(head,-1,sizeof head);
  memset(dis,INF,sizeof dis);
  cnt=0;
}
void add(int u, int v, int w, node edge[], int  &cnt, int *head){
  edge[cnt].u=u;
  edge[cnt].v=v;
  edge[cnt].w=w;
  edge[cnt].next=head[u];
  head[u]=cnt++;
}
void spfa(int st, ll *dis, int *head, node edge[]){
  dis[st]=0;
  queue<int> q;
  q.push(st);
  while(!q.empty()){
    int u=q.front();
    q.pop();
    for(int i = head[u]; ~i; i = edge[i].next ){
      int v=edge[i].v;
      if(dis[v] > dis[u] + (ll)edge[i].w){
        dis[v] = dis[u] + (ll)edge[i].w;
        q.push(v);
      }
    }
  }
  return ;
}
int main(){
  while(~scanf("%d %d", &t, &n)){
    init();
    int u,v,w;
    for(int i=0;i<t;i++){
      scanf("%d %d %d", &u, &v, &w);
      add(u, v, w, edge, cnt, head);
      add(v, u, w, edge, cnt, head);
    }
    spfa(1, dis, head, edge);
    cout<<dis[n]<<endl;
  }
  return 0;
}
