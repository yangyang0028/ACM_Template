#include <bits/stdc++.h>
using namespace std;
#define maxn 200010
int n,m,tot;
int a[maxn],b[maxn],root[maxn];
struct node{
  int l,r,v;
}tree[maxn<<5];
int build_tree(int l,int r){
  int pos=++tot;
  tree[pos].v=0;
  if(l==r){
    return pos;
  }
  int mid=l+(r-l)/2;
  tree[pos].l=build_tree(l,mid);
  tree[pos].r=build_tree(mid+1,r);
  return pos;
}
int update(int now,int tar,int l,int r){
  int pos=++tot;
  if(l==r){
    tree[pos].v=tree[now].v+1;
    return pos;
  }
  int mid=l+(r-l)/2;
  tree[pos].l=tree[now].l;
  tree[pos].r=tree[now].r;
  if(tar<=mid) tree[pos].l=update(tree[now].l,tar,l,mid);
  else tree[pos].r=update(tree[now].r,tar,mid+1,r);
  tree[pos].v=tree[tree[pos].l].v+tree[tree[pos].r].v;
  return pos;
}
int query(int now,int last,int k,int l,int r){
  if(l==r){
    return l;
  }
  int mid=l+(r-l)/2;
  int cnt=tree[tree[now].l].v-tree[tree[last].l].v;
  if(k<=cnt) return query(tree[now].l,tree[last].l,k,l,mid);
  else return query(tree[now].r,tree[last].r,k-cnt,mid+1,r);
}
int main(){
  int n,m;
  while(~scanf("%d %d", &n, &m)){
    tot=0;
    for(int i=1;i<=n;i++){
      scanf("%d", &a[i]);
      b[i]=a[i];
    }
    sort(b+1,b+1+n);
    int res=unique(b+1,b+n+1)-(b+1);
    for(int i=1;i<=n;i++){
      a[i]=lower_bound(b+1,b+1+res,a[i])-b;
    }
    root[0]=build_tree(1,res);
    for(int i=1;i<=n;i++){
      root[i]=update(root[i-1],a[i],1,res);
    }
    int l,r,k;
    while(m--){
      scanf("%d %d %d", &l, &r, &k);
      printf("%d\n", b[query(root[r],root[l-1],k,1,res)]);
    }
  }
  return 0;
}
