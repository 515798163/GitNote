/*
�۲�һ�£������Ĺ��̾��ǰ�һ��ľ�������룬��һ��ľ��������Ŀ�����������ľ��ĳ��Ⱥ͡�
���������ǾͿ��Ի�һ�ö�������ͨ���۲죬����ʵ���Ͼ������ö������ķ�Ҷ�ӽ��ĺ͡�
��Ҷ�ӽ��ĺ�=�������Ĵ�ȫ·�����ȡ�����С�Ŀ�����������С�Ĵ�ȫ·�����ȣ�����������ת������
�������������⡣�����ȶ���ʵ�֡� 
��ȡ�����ľ�弯������̵�����ľ����� 
�ڽ���һ���õ��Ľ�����뵽�����У���ɾȥ����ľ��ĳ��� 
���ظ��٢�������ֱ��������ֻʣ��һ��ľ�� 
�ܽ���һ���õ���ֵ��ӵó���� 
*/
#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std; 
int N; 
int main() {
	cin>>N;
	int sum = 0;
	priority_queue< int,vector<int>,greater<int> > que;
	for(int i = 0;i<N;i++){
		int element;
		cin>>element;
		que.push(element);
	}
	while(que.size()>1){
		int a,b;
		a=que.top();
		que.pop();
		b=que.top();
		que.pop();
		sum+=a+b;
		que.push(a+b);
	}
	cout<<sum<<endl;
	return 0;
}






