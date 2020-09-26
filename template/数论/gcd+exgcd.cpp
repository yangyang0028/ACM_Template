#include <cstdio>
#include <iostream>
using namespace std;
int gcd(int a,int b){
  return b==0?a:gcd(b,a%b);
}
int exgcd(int a,int b,int &x, int &y){
  if(b==0){ x=1,y=0;return a;}
  int t=exgcd(b,a%b,x,y);
  int x0=x,y0=y;
  x=y0,y=x0-(a/b)*y0;
  return t;
}
