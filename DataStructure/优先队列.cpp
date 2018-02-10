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
		int p = (i-1)/2;//这里可以测试一下(1-1)/2=0	(2-1)/2=0
		if(heap[p]<=x){
			break;
		}
		heap[i] = heap[p];
		i=p;
	}
	heap[i]=x;
}
int pop(){
	int ret = heap[0];//将根节点也就是最小的一个节点取出来 
	int x = heap[--sz];//取出最后一个节点
	int i = 0;
	while(i*2+1<sz){
		int a = i*2+1;
		int b = i*2+2;
		if(b<sz&&heap[b]<heap[a]){	//b<sz语句解释：将最后一个叶子节点提到根节点上去，最后一个叶子节点本身
									//并没有改变，a、b两节点做比较没有意义，直接将左节点提到父节点上即可
									//第二句是为了找到子节点中的较小值。 
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
//priority_queue与上面的优先队列不同，取出的是最大值。 
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
