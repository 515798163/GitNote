#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	//����(intΪ��,const char*Ϊֵ)
	map<int,const char*> m;
	
	//����Ԫ��
	m.insert(make_pair(1,"one"));
	m.insert(make_pair(10,"ten"));
	m[100] = "hundred";			//����д��
	
	//����Ԫ��
	map<int,const char*>::iterator ite;
	ite = m.find(1);
	puts(ite->second);
	
	ite = m.find(2);
	if(ite == m.end()){
		cout<<"not found";
	}else{
		cout<<ite->second;
	}
	puts(m[10]);	//����д��
	//ɾ��Ԫ��
	m.erase(10);
	
	//��������Ԫ��
	for(ite = m.begin();ite != m.end();++ite){
		cout<<ite->first<<","<<ite->second<<endl;
	} 
	return 0;
}
