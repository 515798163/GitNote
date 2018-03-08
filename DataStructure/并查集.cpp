//并查集
/*
	1.作用：用来管理元素分组情况的数据结构。可高效执行如下操作。但只可合并，不可分割。 
		①查询元素a和元素b是否属于同一组
		②合并元素a和元素b所在的组 
	2.结构：树形结构，但不是二叉树。每个元素对应一个节点，每个组对应一棵树。整体组成树形结构即可。
	3.查询：沿着树往上走，若找到同样的根，则属于同一组，否则不属于同一组。
	4.合并：将一个组的根与另一个组的根连起来，则两个组就合并为一个组。
			技巧：为了提高效率，当两个组的高度(rank)一样时，两个组的根连起来即可，并将选作为根的rank加
			1。 当两个组的高度不同时，将rank小的根连到rank大的根上面，且rank不变。对于每个节点，在查询
			时直接连到根节点上。 
*/ 
#include <iostream>
#include <vector> 
using namespace std;
int par[10];
int rank[10];

void init(int n){//初始化 
	for (int i = 0 ;i<n;i++){
		par[i] = i;
		rank[i] = 0;
	}
}
int find(int x){//查询 
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
//判断x和y是否属于同一组
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
