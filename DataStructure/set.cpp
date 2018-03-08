#include <iostream>
#include <set>
using namespace std;
int main() {
	//声明 
	set<int> s;
	
	//插入元素
	s.insert(1);
	s.insert(3);
	s.insert(5);
	
	//查找元素
	set<int>::iterator ite;
	
	ite = s.find(1);//find返回指向该元素的迭代器，若不存在，则返回指向最后一个元素的迭代器 
	if(ite == s.end()){
		puts("not found");
	}else{
		puts("found");
	}
	
	ite = s.find(2);
	if(ite == s.end()){
		puts("not found");
	}else{
		puts("found");
	}
	
	//删除元素
	s.erase(3);
	
	//其他查找元素的方法
	if(s.count(3) != 0){//返回当前结合中某个元素的个数 
		puts("found");
	}else{
		puts("not found");
	}
	
	//遍历所有元素
	for(ite = s.begin();ite != s.end();++ite){
		cout<<*ite<<endl;
	} 
	return 0;
}
