#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct cmp{
  bool operator()(int x,int y){
    return x>y;
  }
};
struct node{
	int x,y;
	friend bool operator<(node a,node b)
	{
		return a.x>b.x;//按x从小到大排
	}
};
int main(){
  priority_queue<int> p;//默认最大的元素优先级最高
  priority_queue<int, vector<int>, cmp> q;    //定义方法
  priority_queue<node> q_node;
  return 0;
}
//empty() 　　
//pop()　　　　
//push() 　　
//size()
//top() 　　　
