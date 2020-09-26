/*
string s1;
默认构造函数，s1位空串
string s2(s1);	将s2初始化为s1的一个副本
string s3("value");	将s3初始化为一个字符串字面值副本
string s4(n,'c')	将s4初始化为字符'c'的n个副本
/----------------------------------------------------------------------------------/
s.empty()	如果s为空串，则返回true，否则返回false
s.size()	返回s 中字符的字符个数
s[n]
返回s中位置为n的字符，位置从0开始计数

s1+s2	把s1和s2链接成一个新的字符串，返回新生成的字符串
s1=s2	把s1内容替换为s2的副本
v1==v2	判断v1与v2的内容，相等则返回true，否则返回false
!=, <, <=, >, >=	保持这些操作的惯有含义
/----------------------------------------------------------------------------------/
isalnum(c)	如果c是字母或数字，则为true
isalpha(c)	如果c是字母，则为true
isdigit(c)	如果c是数字，则为true
islower(c)	如果c是小写字母，则为ture
isupper(c)	如果c是大写字母，则为true
isspace(c)	如果c是空白字符，则为true
ispunct(c)	如果c是标点符号，则为true
iscntrl(c)	如果c是控制字符，则为true
isgraph(c)	如果c不是空格，但是可打印，则为true
isprint(c)	如果c是可打印的字符，则为true
isxdigit(c)	如果c是十六进制数，则为true
tolower(c)	如果c是大写字母，则返回其小写字母形式，否则直接返回c
toupper(c)	如果c是小写字母，则返回其大写字母形式，否则直接返回c
/----------------------------------------------------------------------------------/
string s(cp,n)	创建一个string对象，它被初始化为cp所指向数组的前n个元素副本
string s(s2,pos2)	创建一个string对象，它被初始化为一个已存在的string对象s2中从下标pos2开始的字符的副本
                  如果pos2>s.size()则该操作未定义
string s(s2,pos2,len2)
创建一个string对象，它被初始化为s2中从下标pos2开始的len2个字符的副本
如果pos2>s2.size(),则该操作未定义
无论len2的值是多少，最多只能复制s2.size()-pos2个字符
/----------------------------------------------------------------------------------/
s.insert(p,t)	在迭代器p指向的元素之前插入一个值为t的新元素。返回指向新插入元素的迭代器
s.insert(p,n,t)	在迭代器p指向的元素之前插入n个值为t的新元素。返回void
s.insert(p,b,e)	在迭代器p指向的元素之前插入b和e标记范围内所有的元素，返回void
s.assign(b,e)	用迭代器b和e标记范围内的元素替换s。对于string类型，该操作返回s，对于容器类型，则返回void
s.assign(n,t)	用值为t的n个副本替换s。对于string类型，该操作返回s，对于容器类型，返回void
s.erase(p)	删除迭代器p指向的元素，返回一个迭代器，指向被删除元素后面的元素
s.erase(b,e)	删除迭代器b和e标记范围内所有的元素，返回一个迭代器，指向被删除元素段后面的第一个元素
reverse(b,e)	把迭代器b和e标记范围内的所有元素反转
/----------------------------------------------------------------------------------/
s.insert(pos,n,c)	在下表pos的元素之前插入n个字符c
s.insert(pos,s2)
在下标为pos的元素之前插入string对象s2的副本
s.insert(pos,s2,pos2,len)
在下标为pos的元素之前插入s2中从下标pos2开始len个字符
s.insert(pos,cp,len)	在下标为pos的元素之前插入s2中从下标pos2开始的len个字符
s.insert(pos,cp)	在下标为pos的元素之前插入cp所指向的以空字符结束的字符串副本
s.assign(s2)	用s2的副本替换s
s.assign(s2,pos2,len)	用s2中从下标pos2开始的len个字符副本替换s
s.assign(cp,len)	用cp所指向数组的前len个字符副本替换s
s.assign(cp)	用cp所指向的以空字符结束的字符串副本替换s
s.erase(pos,len)
删除从下标pos开始的len个字符
/----------------------------------------------------------------------------------/
s.substr(pos,n)	返回一个string类型的字符串，它包含s中从下标pos开始的n个字符
s.substr(pos)	返回一个string类型的字符串，它包含从下标pos开始到s末为的所有字符
s.substr()	返回s的副本
/----------------------------------------------------------------------------------/
s.find(args)	在s中查找args的第一次出现
s.rfind(args)	在s中查找args的最后一次出现
s.find_first_of(args)	在s中查args的任意字符的第一次出现
s.find_last_of(args)	在s中查找args的任意字符的最后一次出现
s.find_first_not_of(args)	在s中查找第一个不属于args的字符
s.find_last_not_of(args)	在s中查找最后一个不属于args的字符
/----------------------------------------------------------------------------------/
s.compare(s2)	比较s和s2
s.compare(pos1,n1,s2)
让s中从pos下标位置开始的n1个字符与s2做比较
s.compare(pos1,n1,s2,pos2,n2)	让s中从pos1下标位置开始的n1个字符与s2中从pos2下标位置开始的n2个字符做比较
s.compare(cp)	比较s和cp所指向的以空字符结束的字符串
s.compare(pos1,n1,cp)	让s从pos1下标位置开始的n1个字符与cp所指向的字符串做比较
s.compare(pos1,n1,cp,n2)
让s中从pos1下标位置开始的n1个字符与cp所指向字符串的前n2个字符做比较
*/
