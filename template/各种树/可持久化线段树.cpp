#include <bits/stdc++.h>
using namespace std;
#define maxn 1000005
int n,m,tot;
int a[maxn],root[maxn];
struct node{
  int l,r,v;
}tree[maxn<<5];
void up(int now){
	tree[now].v=tree[tree[now].l].v+tree[tree[now].r].v;
}
int build_tree(int l,int r){
  int pos=++tot;
  if(l==r){
    tree[pos].v=a[l];
    return pos;
  }
  int mid=l+(r-l)/2;
  tree[pos].l=build_tree(l,mid);
  tree[pos].r=build_tree(mid+1,r);
  up(pos);
  return pos;
}
int update(int now,int l,int r,int tar,int v){
  int pos=++tot;
  if(l==r){
    tree[pos].v=v;
    return pos;
  }
  int mid=l+(r-l)/2;
  tree[pos].l=tree[now].l;
  tree[pos].r=tree[now].r;
  up(pos);
  if(tar<=mid) tree[pos].l=update(tree[now].l,l,mid,tar,v);
  else tree[pos].r=update(tree[now].r,mid+1,r,tar,v);
  return pos;
}
int query(int now,int l,int r,int q){
  if(l==r){
    return now;
  }
  int mid=l+(r-l)/2;
  if(q<=mid) return query(tree[now].l,l,mid,q);
  else return query(tree[now].r,mid+1,r,q);
}
int main(){
  int n,m;
  while(~scanf("%d %d", &n, &m)){
    tot=0;
    for(int i=1;i<=n;i++){
      scanf("%d", &a[i]);
    }
    root[0]=build_tree(1,n);
    int u,v,l,k;
    for(int i=1;i<=m;i++){
      scanf("%d %d %d", &u, &k, &l);
      if(k==1){
        scanf("%d", &v);
        root[i]=update(root[u],1,n,l,v);
      }else{
        printf("%d\n", tree[query(root[u],1,n,l)].v);
        root[i]=root[u];
      }
    }
  }
  return 0;
}
