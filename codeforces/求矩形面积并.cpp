/*
Atlantis
POJ - 1151
https://vjudge.net/problem/POJ-1151
题面：
    求矩阵面积并
Sample Input
    2
    10 10 20 20
    15 15 25 25.5
    0
Sample Output
    Test case #1
    Total explored area: 180.00

*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define maxn 50010
struct edge_{
  int ss;
  double l,r,h;
  edge_(int ss1=0,double l1=0,double r1=0,double h1=0){
		l=l1;
		r=r1;
		h=h1;
		ss=ss1;
	}
}edge[maxn<<1];
struct node{
  double add,num;
}tree[maxn<<2];
double color[maxn<<1];
int cnt;
double ans;
void init(){
  memset(tree,0,sizeof tree);
  ans=0;
  cnt=0;
}
bool cmp(edge_ a,edge_ b){
  return a.h<b.h;
}
void update(int now,int l,int r){
  if(tree[now].add) tree[now].num=color[r+1]-color[l];
  else if(l==r) tree[now].num=0;
  else tree[now].num=tree[now<<1].num+tree[now<<1|1].num;
}
void change(int now,int l,int r,int i,int j,int val){
  if(i<=l&&r<=j){
    tree[now].add+=val;
    update(now,l,r);
    return ;
  }
  int mid=(l+r)>>1;
  if(i<=mid) change(now<<1,l,mid,i,j,val);
  if(j>mid) change(now<<1|1,mid+1,r,i,j,val);
  update(now,l,r);
}
int main(){
  int n,t=0;
  double x_1,y_1,x_2,y_2;
  while(cin>>n&&n){
    init();
    for(int i=0;i<n;i++){
      scanf("%lf %lf %lf %lf", &x_1, &y_1, &x_2, &y_2);
      color[cnt]=x_1;
      edge[cnt++]=edge_(1,x_1,x_2,y_1);
      color[cnt]=x_2;
      edge[cnt++]=edge_(-1,x_1,x_2,y_2);
    }
    sort(color, color+cnt);
    sort(edge,edge+cnt,cmp);
    int k=unique(color,color+cnt)-color;
    for(int i=0;i<cnt-1;i++){
      int l=lower_bound(color,color+k,edge[i].l)-color;
      int r=lower_bound(color,color+k,edge[i].r)-color-1;
      change(1,0,k-1,l,r,edge[i].ss);
      ans+=(tree[1].num*(edge[i+1].h-edge[i].h));
    }
    printf("Test case #%d\n", ++t);
    printf("Total explored area: %.2lf\n\n", ans);
  }
  return 0;
}
