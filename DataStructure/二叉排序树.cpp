#include <iostream>
using namespace std;

struct node {
	int val;
	node *lch, *rch;
};
//ɾ����ֵx(�ǵݹ�)
node *remove(node *T, int x) {
	node *p = new node;
	node *f = new node;
	p = T; f = NULL;
	while (p) {//�ҵ�Ҫɾ���Ľڵ� 
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
	/*����������3�������*p��������������Ϊ�ա�������������������
	������������������������ȥ
	������������������������ȥ
	�������������У��������������Ľڵ�����ȥ��Ҳ���������������ߵ���ͷ�Ľڵ㣩
	*/
	if ((p->lch) && (p->rch)) {//����Ϊ�� 
		node *s = new node;
		s = p->lch;
		while (s->rch) {
			q = s;
			s = s->rch;
		}
		p->val = s->val;
		if (q != p) {//�Ƚϸ��ӣ�����ͼ����һ�� 
			q->rch = s->lch;
		}
		else {
			q->lch = s->lch;
		}
		delete s;
	}
	else if (!p->rch) {//������Ϊ�� 
		p = p->lch;
	}
	else if (!p->lch) {//������Ϊ�� 
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
//������ֵx(�ݹ�ʵ�ֱȽϼ�)
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
//������ֵx�Ƿ����(�ǵݹ�)
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
		cout << "����";
	}
	else {
		cout << "������";
	}
	p = remove(p, 2);
	if (find(p, 2)) {
		cout << "����";
	}
	else {
		cout << "������";
	}
	return 0;
}
