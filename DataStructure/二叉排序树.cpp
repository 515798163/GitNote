#include <iostream>
using namespace std;

struct node {
	int val;
	node *lch, *rch;
};
//删除数值x(非递归)
node *remove(node *T, int x) {
	node *p = new node;
	node *f = new node;
	p = T; f = NULL;
	while (p) {//找到要删除的节点 
		if (p->val == x) {
			break;
		}
		f = p;
		if (x<p->val) {
			p = p->lch;
		}
		else {
			p = p->rch;
		}
	}
	node *q = new node;
	q = p;
	/*接下来讨论3种情况：*p的左右子树均不为空、无左子树、无右子树
	①无左子树：把右子树提上去
	②无右子树：把左子树提上去
	③左右子树都有：把左子树上最大的节点提上去（也就是左子树往右走到尽头的节点）
	*/
	if ((p->lch) && (p->rch)) {//均不为空 
		node *s = new node;
		s = p->lch;
		while (s->rch) {
			q = s;
			s = s->rch;
		}
		p->val = s->val;
		if (q != p) {//比较复杂，画个图测试一下 
			q->rch = s->lch;
		}
		else {
			q->lch = s->lch;
		}
		delete s;
	}
	else if (!p->rch) {//左子树为空 
		p = p->lch;
	}
	else if (!p->lch) {//右子树为空 
		p = p->rch;
	}
	if (!f) {
		T = p;
	}
	else if (q == f->lch) {
		f->lch = p;
	}
	else {
		f->rch = p;
	}
	delete q;
	return T;
}
//插入数值x(递归实现比较简单)
node *insert(node *p, int x) {
	if (p == NULL) {
		node *q = new node;
		q->val = x;
		q->lch = q->rch = NULL;
		return q;
	}
	else {
		if (x < p->val) {
			p->lch = insert(p->lch, x);
		}
		else {
			p->rch = insert(p->rch, x);
		}
		return p;
	}
}
//查找数值x是否存在(非递归)
bool find(node *p, int x) {
	while (p) {
		if (p->val == x) {
			return true;
		}
		else if (x<p->val) {
			p = p->lch;
		}
		else if (x>p->val) {
			p = p->rch;
		}
	}
	return false;
}
int main() {
	node *p = new node;
	p = NULL;
	p = insert(p, 3);
	p = insert(p, 2);
	p = insert(p, 4);
	p = insert(p, 5);
	p = insert(p, 1);
	if (find(p, 3)) {
		cout << "存在";
	}
	else {
		cout << "不存在";
	}
	p = remove(p, 2);
	if (find(p, 2)) {
		cout << "存在";
	}
	else {
		cout << "不存在";
	}
	return 0;
}
