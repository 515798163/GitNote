#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	//声明(int为键,const char*为值)
	map<int,const char*> m;
	
	//插入元素
	m.insert(make_pair(1,"one"));
	m.insert(make_pair(10,"ten"));
	m[100] = "hundred";			//其他写法
	
	//查找元素
	map<int,const char*>::iterator ite;
	ite = m.find(1);
	puts(ite->second);
	
	ite = m.find(2);
	if(ite == m.end()){
		cout<<"not found";
	}else{
		cout<<ite->second;
	}
	puts(m[10]);	//其他写法
	//删除元素
	m.erase(10);
	
	//遍历所有元素
	for(ite = m.begin();ite != m.end();++ite){
		cout<<ite->first<<","<<ite->second<<endl;
	} 
	return 0;
}
