#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <limits.h>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define maxn 100000
int a,b,c;
struct  Test
{
	int x;
	int y;
	bool operator < (const Test &o) const{
		return x < o.x || y < o.y;
	}
}mm;
struct node{
  int x;
  int y;
  int l,f;
}mp[maxn];
map<Test,int> m;
queue<int> q;
int num=0;
void init(){
  num=0;
  while(!q.empty()) q.pop();
  memset(mp,0,sizeof(mp));

}
char ans[7][10]={"0","FILL(1)","FILL(2)","DROP(1)","DROP(2)","POUR(2,1)","POUR(1,2)"};
stack<int> S;
int anss;
int bfs(){
  node d;
  int i;
  mp[0].x=0,mp[0].y=0,mp[0].l=0,mp[0].f=0;
  mm={0,0};
  m[mm]=1;
  q.push(0);
  while(!q.empty()){
    i=q.front();
    q.pop();
    d=mp[i];
    if(d.x==c||d.y==c) {
      anss=i;
      return 1;
    }
    mm={a,d.y};
    if(d.x<a&&m[mm]==0){
      m[mm]=1;
      num++;
      mp[num]=d;
      mp[num].x=a;
      mp[num].f=i;
      mp[num].l=1;
      q.push(num);
    }
    mm={d.x,b};
    if(d.y<b&&m[mm]==0){
      m[mm]=1;
      num++;
      mp[num]=d;
      mp[num].y=b;
      mp[num].f=i;
      mp[num].l=2;
      q.push(num);
    }
    mm={0,d.y};
    if(d.x>0&&m[mm]==0){
      m[mm]=1;
      num++;
      mp[num]=d;
      mp[num].x=0;
      mp[num].f=i;
      mp[num].l=3;
      q.push(num);
    }
    mm={d.x,0};
    if(d.y>0&&m[mm]==0){
      m[mm]=1;
      num++;
      mp[num]=d;
      mp[num].y=0;
      mp[num].f=i;
      mp[num].l=4;
      q.push(num);
    }
    if(d.x+d.y<a){
      mm={d.x+d.y,0};
      if(d.x<a&&m[mm]==0){
        m[mm]=1;
        num++;
        mp[num]=d;
        mp[num].x=d.x+d.y;
        mp[num].y=0;
        mp[num].f=i;
        mp[num].l=5;
        q.push(num);
      }
    }
    if(d.x+d.y<b){
      mm={0,d.x+d.y};
      if(d.y<b&&m[mm]==0){
        m[mm]=1;
        num++;
        mp[num]=d;
        mp[num].y=d.x+d.y;
        mp[num].x=0;
        mp[num].f=i;
        mp[num].l=6;
        q.push(num);
      }
    }
    if(d.x+d.y>=a){
      mm={a,d.x+d.y-a};
      if(d.x<a&&m[mm]==0){
        m[mm]=1;
        num++;
        mp[num]=d;
        mp[num].x=a;
        mp[num].y=d.x+d.y-a;
        mp[num].f=i;
        mp[num].l=5;
        q.push(num);
      }
    }
    if(d.x+d.y>=b){
      mm={d.x+d.y-b,b};
      if(d.y<b&&m[mm]==0){
        m[mm]=1;
        num++;
        mp[num]=d;
        mp[num].y=b;
        mp[num].x=d.x+d.y-b;
        mp[num].f=i;
        mp[num].l=6;
        q.push(num);
      }
    }
  }
  return 0;
}
int main(){
  scanf("%d %d %d", &a, &b, &c);
    init();
    if(bfs()==1){
      int i=anss;
      node a=mp[i];
      while(i!=0){
        S.push(mp[i].l);
        i=mp[i].f;
      }
      printf("%d\n", S.size());
      while(!S.empty()){
        printf("%s\n", ans[S.top()]);
        S.pop();
      }
    }else {
      printf("impossible\n");
    }
    return 0;
}
