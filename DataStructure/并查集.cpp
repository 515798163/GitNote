//���鼯
/*
	1.���ã���������Ԫ�ط�����������ݽṹ���ɸ�Чִ�����²�������ֻ�ɺϲ������ɷָ 
		�ٲ�ѯԪ��a��Ԫ��b�Ƿ�����ͬһ��
		�ںϲ�Ԫ��a��Ԫ��b���ڵ��� 
	2.�ṹ�����νṹ�������Ƕ�������ÿ��Ԫ�ض�Ӧһ���ڵ㣬ÿ�����Ӧһ����������������νṹ���ɡ�
	3.��ѯ�������������ߣ����ҵ�ͬ���ĸ���������ͬһ�飬��������ͬһ�顣
	4.�ϲ�����һ����ĸ�����һ����ĸ�����������������ͺϲ�Ϊһ���顣
			���ɣ�Ϊ�����Ч�ʣ���������ĸ߶�(rank)һ��ʱ��������ĸ����������ɣ�����ѡ��Ϊ����rank��
			1�� ��������ĸ߶Ȳ�ͬʱ����rankС�ĸ�����rank��ĸ����棬��rank���䡣����ÿ���ڵ㣬�ڲ�ѯ
			ʱֱ���������ڵ��ϡ� 
*/ 
#include <iostream>
#include <vector> 
using namespace std;
int par[10];
int rank[10];

void init(int n){//��ʼ�� 
	for (int i = 0 ;i<n;i++){
		par[i] = i;
		rank[i] = 0;
	}
}
int find(int x){//��ѯ 
	if(par[x] == x){
		return x;
	}else{
		return par[x] = find(par[x]);
	}
}

void unite(int x,int y){
	x = find(x);
	y = find(y);
	if(x == y){
		return;
	}
	if(rank[x] < rank[y]){
		par[x] = y;
	}else{
		par[y] = x;
		if(rank[x] == rank[y]){
			rank[x]++;
		}
	}
}
//�ж�x��y�Ƿ�����ͬһ��
bool same(int x,int y){
	return find(x) == find(y);
} 

int main() {
	int n;
	cin>>n;
	init(n);
	unite(2,3);
	unite(3,4);
	if(same(2,3)){
		cout<<"Yes"<<endl; 
	}else{
		cout<<"No"<<endl;
	}
	if(same(1,2)){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	return 0;
}
