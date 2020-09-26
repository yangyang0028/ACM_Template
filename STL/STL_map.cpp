#include <map>
#include <iostream>

struct  Test{
	int x;
	int y;
	bool operator < (const Test &o) const{
		return x < o.x || y < o.y;
	}
};
int main()
{
	std::map<Test, std::string> mapTest;
  int a=1,b=2;
	Test test = { a, b };
	mapTest[test] = "Test1";

	for (auto it = mapTest.begin(); it != mapTest.end();it++)
	{
		std::cout << it->first.x << " " << it->first.y << " " << it->second.c_str() << std::endl;
	}

	return 0;
}
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <map>
#include <string>
using namespace std;
void print(map<string, int> T){
  map<string, int>::iterator it;
  cout<<T.size()<<endl;
  for(it=T.begin();it!=T.end();it++){
    pair<string, int> itam=*it;
    cout<<itam.first<<"-->"<<itam.second<<endl;
  }
}
int main(){
  map<string, int> T;
  T["red"] = 32;
  T["blue"] = 688;
  T["yellow"] = 122;
  T["blue"] = 312;
  print(T);//3
          //blue-->312
          //red-->32
          //yellow-->122

  T.insert(make_pair("zebra", 101010));
  T.insert(make_pair("white", 0));
  T.erase("yellow");
  print(T);//4
          //blue-->312
          //red-->32
          //white-->0
          //zebra-->101010
  pair<string, int> target = *T.find("red");
  cout<<target.first<<"-->"<<target.second<<endl;
}
//size()
//clear()
//begin()
//end()
//insert(key,vel)//向map中插入元素（key， val）
//erase(key)//删除含有key的元素
//find(key)//搜索与key一致的元素，并返回该元素的迭代器，没有一致的元素，则返回末尾end（）
