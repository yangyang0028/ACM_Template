/*
食物链
POJ - 1182
https://vjudge.net/problem/POJ-1182
模板 种类并查集
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define maxn 1000010
struct node{
  int pre;
  int relation;//p[i].relation 表示的是i的根节点到i的有向偏移量
}p[maxn];
int n,k;
int ans;
void init(){
  for(int i=0;i<=n;i++){
    p[i].pre=i;
    p[i].relation=0;
  }
  ans=0;
}
int find(int x){
  if(x==p[x].pre) return x;
  int temp=p[x].pre;
  p[x].pre=find(temp);
  p[x].relation=(p[x].relation+p[temp].relation)%3;//因为换了根节点，所以偏移量就要跟着转换
  return p[x].pre;
}
void unite(int x,int y,int c){
  int root1=find(x);
  int root2=find(y);
  if(root1!=root2){
    p[root2].pre=root1;
    p[root2].relation=(3+p[x].relation-p[y].relation+(c-1))%3;//这里的偏移量就是有方向的
  }else{
    if(c==1&&p[x].relation!=p[y].relation){
      ans++;
      return ;
    }
    if(c==2&&(3-p[x].relation+p[y].relation)%3!=1){
      ans++;
      return ;
    }
  }
  return ;
}
int main(){
  int x,y,c;
  scanf("%d %d", &n, &k);
  init();
  for(int i=1;i<=k;i++){
    scanf("%d %d %d", &c, &x, &y);
    if(x>n||y>n){
      ans++;
      continue;
    }
    if(x==y&&c==2){
      ans++;
      continue;
    }
    unite(x,y,c);
  }
  cout<<ans<<endl;
  return 0;
}
