#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
int MAX_N = 10;
vector<int> heap(10);
int sz = 0;
void push(int x){
	int i = sz++;
	while(i>0){
		int p = (i-1)/2;//������Բ���һ��(1-1)/2=0	(2-1)/2=0
		if(heap[p]<=x){
			break;
		}
		heap[i] = heap[p];
		i=p;
	}
	heap[i]=x;
}
int pop(){
	int ret = heap[0];//�����ڵ�Ҳ������С��һ���ڵ�ȡ���� 
	int x = heap[--sz];//ȡ�����һ���ڵ�
	int i = 0;
	while(i*2+1<sz){
		int a = i*2+1;
		int b = i*2+2;
		if(b<sz&&heap[b]<heap[a]){	//b<sz�����ͣ������һ��Ҷ�ӽڵ��ᵽ���ڵ���ȥ�����һ��Ҷ�ӽڵ㱾��
									//��û�иı䣬a��b���ڵ����Ƚ�û�����壬ֱ�ӽ���ڵ��ᵽ���ڵ��ϼ���
									//�ڶ�����Ϊ���ҵ��ӽڵ��еĽ�Сֵ�� 
			a=b;
		}
		heap[i]=heap[a];
		i=a;
	}
	heap[i]=x;
	return ret;
}

int main() {
	for(int i = 0;i<MAX_N;i++){
		int x;
		cin>>x;
		push(x);
	}
	int ret;
	ret = pop();
	cout<<ret<<endl;
	cout<<sz<<endl;
	for(int i = 0;i<sz;i++){
		cout<<heap[i]<<" ";
	}
	return 0;
}
//priority_queue����������ȶ��в�ͬ��ȡ���������ֵ�� 
//#include<iostream>
//#include<stdio.h>
//#include<queue>
//#include<cstdio>
//using namespace std;
//int main(){
//	priority_queue<int> pque;
//	pque.push(3);
//	pque.push(5);
//	pque.push(1);
//	
//	while(!pque.empty()){
//		cout<<pque.top()<<endl;
//		pque.pop();
//	}
//	return 0;
//} 
