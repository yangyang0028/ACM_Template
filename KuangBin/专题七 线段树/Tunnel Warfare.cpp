/*
Tunnel Warfare
HDU - 1540
https://vjudge.net/problem/HDU-1540
题面：
    一条线上的点，D x是破坏这个点，Q x是表示查询以x所在的最长的连续的点的个数，R是恢复上一次破坏的点。
Sample Input
    7 9
    D 3
    D 6
    D 5
    Q 4
    Q 5
    R
    Q 4
    R
    Q 4
Sample Output
    1
    0
    2
    4
解法：
    线段树+区间更新
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
#define maxn 501000
struct node{
  int num;
  int ll,rr;
}tree[maxn<<2];
int n,m;
void update(int now,int len){
  if(tree[now<<1].ll==len-(len>>1)) tree[now].ll=tree[now<<1].ll+tree[now<<1|1].ll;
  else tree[now].ll=tree[now<<1].ll;
  if(tree[now<<1|1].rr==len>>1) tree[now].rr=tree[now<<1|1].rr+tree[now<<1].rr;
  else tree[now].rr=tree[now<<1|1].rr;
  tree[now].num=max(max(tree[now<<1].num,tree[now<<1|1].num),tree[now<<1].rr+tree[now<<1|1].ll);
}
void build(int now,int l,int r){
  if(l==r){
    tree[now].num=1;
    tree[now].ll=1;
    tree[now].rr=1;
    return ;
  }
  int mid=(l+r)>>1;
  build(now<<1,l,mid);
  build(now<<1|1,mid+1,r);
  update(now,r-l+1);
}
void change(int now,int l,int r,int x,int c){
  if(l==r){
    tree[now].num=c;
    tree[now].ll=c;
    tree[now].rr=c;
    return ;
  }
  int mid=(l+r)>>1;
  if(x<=mid) change(now<<1,l,mid,x,c);
  else change(now<<1|1,mid+1,r,x,c);
  update(now,r-l+1);
}
int query(int now,int l,int r,int q){
  if(tree[now].num==(r-l+1)||l==r||tree[now].num==0) return tree[now].num;
  int mid=(l+r)>>1;
  if(q<=mid){
    if(q>=mid-tree[now<<1].rr+1) return tree[now<<1].rr+tree[now<<1|1].ll;
    else return query(now<<1,l,mid,q);
  } else {
    if(q<=mid+tree[now<<1|1].ll) return tree[now<<1].rr+tree[now<<1|1].ll;
    else return query(now<<1|1,mid+1,r,q);
  }
}
stack <int> st;
int main(){
  char q[10];
  int c;
  while(~scanf("%d %d", &n, &m)){
    while(!st.empty()) st.pop();
    build(1,1,n);
    while(m--){
      scanf("%s", q);
      if(q[0]=='D'){
        scanf("%d", &c);
        st.push(c);
        change(1,1,n,c,0);
      }else if(q[0]=='R'){
        change(1,1,n,st.top(),1);
        st.pop();
      }else{
        scanf("%d", &c);
        cout<<query(1,1,n,c)<<endl;
      }
    }
  }
  return 0;
}
