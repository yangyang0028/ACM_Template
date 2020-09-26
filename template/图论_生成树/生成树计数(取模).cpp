/*
Lightning
HDU - 4305
https://vjudge.net/problem/HDU-4305
生成树计数取模+判点在线上
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MOD 10007
struct Point{
    int x,y;
    Point(int _x = 0,int _y = 0){
        x = _x,y = _y;
    }
    Point operator - (const Point &b)const{
        return Point(x-b.x,y-b.y);
    }
    int operator ^(const Point &b)const{
        return x*b.y - y*b.x;
    }
    void input(){
        scanf("%d%d",&x,&y);
    }
}p[310];
struct Line{
    Point s,e;
    Line(){}
    Line(Point _s,Point _e){
        s = _s;
        e = _e;
    }
};
long long K[330][330];
long long A[330][330];
int n,R;
bool onSeg(Point P,Line L){
    return
    ((L.s-P)^(L.e-P)) == 0 &&
    (P.x-L.s.x)*(P.x-L.e.x) <= 0 &&
    (P.y-L.s.y)*(P.y-L.e.y) <= 0;
}
int sqdis(Point a,Point b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
bool check(int k1,int k2){
    if(sqdis(p[k1],p[k2]) > R*R)return false;
    for(int i = 0;i < n;i++)
        if(i!=k1 && i!=k2)
            if(onSeg(p[i],Line(p[k1],p[k2])))
                return false;
    return true;
}
int exgcd(int a,int b,int &x,int &y){
    if(a%b==0){
        x=0;y=1;
        return b;
    }
    int v,tx,ty;
    v=exgcd(b,a%b,tx,ty);
    x=ty;
    y=tx-a/b*ty;
    return v;
}

int inv(int a,int p){
    if(!a) return 0;
    int x,y;
    exgcd(a,p,x,y);
    x=(x%p+p)%p;
    return x;
}
int det(int n){
  int ans=1;
  for(int i=1;i<=n;i++){
    for(int j=i+1;j<=n;j++){
      while(K[j][i]){
        int t=(K[i][i]*inv(K[j][i],MOD))%MOD;
        for(int k=i;k<=n;k++){
          K[i][k]=(K[i][k]-K[j][k]*t%MOD+MOD)%MOD;
          swap(K[i][k],K[j][k]);
        }
        ans=-ans;
      }
    }
    if(K[i][i]==0) return -1;
    ans=(ans*K[i][i])%MOD;
  }
  return (ans+MOD)%MOD;
}
int main(){
  int T;
  scanf("%d", &T);
  while(T--){
    scanf("%d %d", &n, &R);
    for(int i=0;i<n;i++){
      p[i].input();
    }
    memset(K,0,sizeof K);
    for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
        if(check(i,j)) {
          int x=i+1,y=j+1;
          K[x][y]=K[y][x]=-1;
          K[x][x]++;
          K[y][y]++;
        }
      }
    }
    printf("%d\n", det(n-1));
  }
}
