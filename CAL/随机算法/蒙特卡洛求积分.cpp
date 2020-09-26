#include <bits/stdc++.h>
using namespace std;
#define MAX_ITERS 10000000
double Rand(double l,double r){
  return l+(r-l)*rand()*1.0/RAND_MAX;
}
double GetCal(){
  srand(time(NULL));
  int num=0;
  for(int i=0;i<MAX_ITERS;i++){
    double x=Rand(1.0,2.0);
    double y=Rand(0,1.0);
    if(1/x>=y) num++;
  }
  return num*1.0/MAX_ITERS;
}
int main(){
    cout<<"ln2 = "<<log(2)<<endl;
    for(int i=0;i<10;i++)
    cout<<GetCal()<<endl;
  return 0;
}
