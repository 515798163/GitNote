/*
观察一下，这道题的过程就是把一块木板锯成两半，把一块木板锯成两半的开销就是两块木板的长度和。
这样，我们就可以画一棵二叉树，通过观察，开销实际上就是整棵二叉树的非叶子结点的和。
非叶子结点的和=二叉树的带全路径长度。求最小的开销就是求最小的带全路径长度，所以这道题就转化成了
哈夫曼树的问题。用优先队列实现。 
①取出拆分木板集合中最短的两块木板相加 
②将第一步得到的结果插入到集合中，并删去两块木板的长度 
③重复①②两步，直到集合中只剩下一块木板 
④将第一步得到的值相加得出结果 
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






