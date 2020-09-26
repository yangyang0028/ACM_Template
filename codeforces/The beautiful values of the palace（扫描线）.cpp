/*
The beautiful values of the palace
The Preliminary Contest for ICPC Asia Nanjing 2019 A.
https://nanti.jisuanke.com/t/41298
题意： 有一个n*n（n为奇数）的矩阵，沿着方阵中心螺旋下降，有m个地方是要建宫殿的，
      宫殿的价值是土地价值的数字总和  例如：123213（1+2+3+2+1+3=12）
      p次询问 问一个区间的所以宫殿价值总和
样例输入：
      1
      3 4 4
      1 1
      2 2
      3 3
      2 3
      1 1 1 1
      2 2 3 3
      1 1 3 3
      1 2 2 3
样例输出：
      5
      18
      23
      17
解法；因为n比较大，所以只能用数学方法计算出要建宫殿的地方的价值
    然后因为p比较大，所以要用到扫描线来处理
*/
#include <bits/stdc++.h>
using namespace std;
#define maxn 1000100
#define ll long long
int n,m,p,cnt;
int tree[maxn];
int sum[maxn],res[maxn];
struct node{
  int f,L,R,h,id;
  int val;
}edge[maxn];
int get(int x, int y){
  long long centre = (long long)n*n;
  long long cen = n/2+1;
  long long val;
  if (x==cen && y==cen){
    int ans=0;
    val=centre;
    while(val){
      ans+=val%10;
      val=val/10;
    }
    return ans;
  }
  long long Max = max(abs(x-cen), abs(y-cen));
  val = centre - Max * (4*Max +1);
  if((y == (cen-Max) && x >= cen) || x == cen + Max) val -= (x-cen) + (y-cen+Max);
  else {
  	if(y != (cen-Max)) val += (x-cen + Max) + (y-cen + Max) + Max;
  	else val += cen - x;
  }
  int ans=0;
  while(val){
    ans+=val%10;
    val=val/10;
  }
  return ans;
}
bool cmp(node a,node b){
  if(a.h==b.h){
    if((a.f==1&&b.f==0)||(b.f==1&&a.f==0)) return a.f>b.f;
    else return a.f<b.f;
  }
  return a.h<b.h;
}
void update(int pow,int val){
  while(pow<maxn){
    tree[pow]+=val;
    pow+=(-pow)&pow;
  }
}
int query(int pow){
  int ans=0;
  while(pow>0){
    ans+=tree[pow];
    pow-=(-pow)&pow;
  }
  return ans;
}
int main(){
  int T;
  int x1,x2,y1,y2,x,y;
  cin>>T;
  while(T--){
    scanf("%d %d %d", &n, &m, &p);
    cnt=0;
    memset(tree,0,sizeof tree);
    while(m--){
      scanf("%d %d", &x, &y);
      edge[cnt++]=(node){0,x,0,y,0,get(x,y)};
    }
    for(int i=1;i<=p;i++){
      scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
      edge[cnt++]=(node){1,x1,x2,y1,i,0};
      edge[cnt++]=(node){2,x1,x2,y2,i,0};
    }
    sort(edge,edge+cnt,cmp);
    for(int i=0;i<cnt;i++){
      if(edge[i].f==0) update(edge[i].L,edge[i].val);
      else if(edge[i].f==1) sum[edge[i].id]=query(edge[i].R)-query(edge[i].L-1);
      else res[edge[i].id]=query(edge[i].R)-query(edge[i].L-1)-sum[edge[i].id];
    }
    for(int i=1;i<=p;i++){
      printf("%d\n", res[i]);
    }
  }
  return 0;
}
