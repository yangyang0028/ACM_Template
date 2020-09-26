#include <iostream>
#include <set>
using namespace std;
void print(set<int> s){
  cout<<s.size()<<":";
  for(set<int>::iterator it=s.begin();it!=s.end();it++){
    cout<<" "<<(*it);
  }
  cout<<endl;
}
int main(){
  multiset<int,greater<int>> mul;
  s.insert(8);
  s.insert(1);
  s.insert(7);
  s.insert(4);
  s.insert(8);
  s.insert(4);

  print(s);//4: 1 4 7 8
  s.erase(7);
  print(s);//3: 1 4 8
  s.insert(2);
  print(s);//4: 1 2 4 8
  return 0;
}
// size()
// clear()
// begin()
// end()
// insert(key) 向set中添加元素key
// erase(key) 删除含key的元素
// find(key) 搜索与key一致的元素，并返回指向该元素的迭代器::若没有，则返回末尾end()
