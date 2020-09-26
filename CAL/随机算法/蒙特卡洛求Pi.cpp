#include <bits/stdc++.h>
using namespace std;
#define MAX_ITERS 10000000
double Rand(double l,double r){
  return l+(r-l)*rand()*1.0/RAND_MAX;
}
double GetPi(){
  srand(time(NULL));
  int num=0;
  for(int i=0;i<MAX_ITERS;i++){
    double x=Rand(0,1.0);
    double y=Rand(0,1.0);
    if(x*x+y*y<1.0) num++;
  }
  return num*4.0/MAX_ITERS;
}
int main(){
    for(int i=0;i<10;i++)
    cout<<GetPi()<<endl;
  return 0;
}
