#include <iostream>
#include <set>
using namespace std;
int main() {
	//���� 
	set<int> s;
	
	//����Ԫ��
	s.insert(1);
	s.insert(3);
	s.insert(5);
	
	//����Ԫ��
	set<int>::iterator ite;
	
	ite = s.find(1);//find����ָ���Ԫ�صĵ��������������ڣ��򷵻�ָ�����һ��Ԫ�صĵ����� 
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
	
	//ɾ��Ԫ��
	s.erase(3);
	
	//��������Ԫ�صķ���
	if(s.count(3) != 0){//���ص�ǰ�����ĳ��Ԫ�صĸ��� 
		puts("found");
	}else{
		puts("not found");
	}
	
	//��������Ԫ��
	for(ite = s.begin();ite != s.end();++ite){
		cout<<*ite<<endl;
	} 
	return 0;
}
