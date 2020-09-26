/*
Overlapping Rectangles
2017 ACM-ICPC 亚洲区（南宁赛区）网络赛
https://nanti.jisuanke.com/t/A1282
题面：
      n个矩形，给出左下角的坐标和右上角的坐标，算出n个矩形所覆盖的面积
输入：
      2
      0 0 2 2
      1 1 3 3
      3
      0 0 1 1
      2 2 3 3
      4 4 5 5
      0
输出：
      7
      3
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
#define maxn 5010
struct node{
	int ss;
	double l,r,h;
	node(double l1=0,double r1=0,double h1=0,int ss1=0){
		l=l1;
		r=r1;
		h=h1;
		ss=ss1;
	}
}edge[maxn<<2];
int add[maxn];
double x[maxn<<2],sum[maxn<<2];
bool cmp(node a,node b){
	return a.h<b.h;
}
void pushup(int now,int l,int r){
	if(add[now]) sum[now]=x[r+1]-x[l];
	else if(l==r) sum[now]=0;
	else sum[now]=sum[now<<1]+sum[now<<1|1];
}
void update(int now,int L,int R,int val,int l,int r){
	if(L<=l&&r<=R){
		add[now]+=val;
		pushup(now,l,r);
		return ;
	}
	int mid=(l+r)>>1;
	if(L<=mid) update(now<<1,L,R,val,l,mid);
	if(R>mid) update(now<<1|1,L,R,val,mid+1,r);
	pushup(now,l,r);
}
int main(){
	int n;
	double x1,x2,y1,y2,ans;
	while(cin>>n && n){
		ans=0;
		int top=0,l,r;
		for(int i=0;i<n;i++){
			cin>>x1>>y1>>x2>>y2;
			x[top]=x1;
			edge[top++]=node(x1,x2,y1,1);
			x[top]=x2;
			edge[top++]=node(x1,x2,y2,-1);
		}
		sort(x,x+top);
		sort(edge,edge+top,cmp);
		int k = 1;
		for(int i=1; i<top; i++)
		{
				if(x[i] != x[i-1])
						x[k++] = x[i];
		}
		memset(add,0,sizeof(add));
		memset(sum,0,sizeof(sum));
		for(int i=0; i<top-1; i++){
			l=lower_bound(x,x+k,edge[i].l)-x;
			r=lower_bound(x,x+k,edge[i].r)-x-1;
			update(1,l,r,edge[i].ss,0,k-1);
			ans+=(sum[1]*(edge[i+1].h-edge[i].h));
		}
		cout<<(int)ans<<endl;
	}
	cout<<"*"<<endl;
	return 0;
}

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
