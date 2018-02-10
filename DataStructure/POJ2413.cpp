/*
思路：变换一下思路，到达加油站i时，接下来的路程中，就有了无论在什么时候都有把加油站i的油加入到油箱
的权利。接下来的路程油不够了需要加油的话，只需把优先队列里的最大的油量加入到油箱。 
*/ 
#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
int L,P,N;
vector<int> A;
vector<int> B;
int main() {
	//N加油站数量,L终点距离,P油箱初始化油量 
	cin>>N>>L>>P;
	for(int i = 0;i<N;i++){
		int element1;
		int element2;
		cin>>element1>>element2;
		A.push_back(element1);
		B.push_back(element2);
	}
	priority_queue<int> que;
	//cnt加油次数，dis行驶距离，cub油箱中的油量 
	int cnt = 0,dis = 0,cub = P;
	for(int i = 0 ;i<N;i++){
		int d = A[i] - dis;
		while(cub - d < 0 ){//判断油箱里的油能不能行驶完接下来的距离，如果不能，也就是cub-d<0，
							//油不够了，需要加油，这时候，就需要判断优先队列里有没有存货了， 
			if(que.empty()){//如果没有，那没办法了，到不了终点直接输出-1,不用算了。 
				cout<<"-1";	//如果有，那就加油继续上路，把优先队列里的数弹出来，加到剩余油量里。 
				return 0;	//这里不需要考虑万一加上油，还是到不了下一个加油站怎么办？如果出现这种 
			}				//情况，循环外的第一条语句cub-=d;就会考虑到这种情况，这时候，cub会变成 
			cub += que.top();//负值，在接下来的循环中，也会输出"-1"，结束计算 
			que.pop();
			cnt++;
		}
		cub -= d;			//计算油箱行驶完接下来的路程后的剩余油量 
		dis = A[i];			//行驶完了接下来的路程，肯定要更新一下当前距离 
		que.push(B[i]);		//行驶到了下一个加油站，就需要把这个加油站可加的油量加入优先队列 
	}
	cout<<cnt<<endl;
	return 0;
}
/*测试数据 
4 25 10
10 10
14 5
20 2
21 4
输出2 
*/
