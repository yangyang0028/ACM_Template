#include <vector>
using namespace std;
int main(){
  vector<int> v;
  v.size();//返回向量的元素数     O(1)
  v.push_back(x);//在向量末尾添加元素x     O(1)
  v.pop_back();//删除向量的最后一个元素     O(1)
  v.begin();//返回指向向量开头的迭代器     O(1)
  v.end();//返回指向向量末尾（最后一个元素的后一个位置）     O(1)
  v.insert(v.begin()+p,x);//在向量的位置p处插入元素x     O(n)
  v.erase(v.begin()+p);//删除向量中位置p的元素     O(n)
  v.clear();//删除向量中所有元素     O(n)
}
