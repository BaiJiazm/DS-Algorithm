#include<iostream>
#include<queue>
using namespace std;

********************************����һ
struct Node {
	int x,y;
	bool operator <(Node a) const  {	//�����const
		return y < a.y;
	}
	bool operator >(Node a) const  {	//�����const
		return y > a.y;
	}
};
//	priority_queue<Node> A;   //Ĭ��	�����
priority_queue<Node, vector<Node>, less<Node>>A;	//�����
priority_queue<Node, vector<Node>, greater<Node> > B;    //С����

********************************���Ʒ�ʽ��һ
struct Node {
	int x;
	int y;
	friend  bool operator<(const Node &a,const Node &b) {
		return  a.x < b.x;	//�󶥶�
	}
	friend  bool operator>(const Node &a,const Node &b) {
		return  a.x > b.x;	//С����
	}
};

priority_queue<Node> A;   //Ĭ��	�����
priority_queue<Node, vector<Node>, greater<Node> > B;    //С����

********************************��������
struct Node {
	int x;
	int y;
};

bool operator<(const Node &a, const Node &b) {
	return a.x<b.x;			 //�󶥶�
}

bool operator>(const Node &a, const Node &b) {
	return a.x>b.x;			//С����
}

priority_queue<Node,vector<Node>,less<Node> > A;   	//�����
priority_queue<Node, vector<Node>, greater<Node> > B;    //С����


//********************************��������
struct Node {
	int x;
	int y;
};

struct cmp {
	bool operator()(Node a,Node b) {
		return  a.x > b.x;	//С����
	}
};

struct cmp1 {
	bool operator()(Node a,Node b) {
		return  a.x < b.x;	//�󶥶�
	}
};

priority_queue<Node,vector<Node>,cmp1 > A;   	//�����
priority_queue<Node, vector<Node>, cmp > B;    //С����


//�����нڵ���ָ��ʱ���÷���ͬ
struct Node {
	int x;
	int y;
};
struct cmp {
	bool operator () (Node const *n1, Node const *n2) {
		return n1->x<n2->x;		//����
	}
};
struct cmp1 {
	bool operator () (Node const *n1, Node const *n2) {
		return n1->x>n2->x;		//С����
	}
};

priority_queue<Node*, vector<Node*>, cmp > A;	//�����
priority_queue<Node*, vector<Node*>, cmp1 > B;  //С����






ostream & operator <<(ostream &out,const struct Node& n) {
	out<<"n.x="<<n.x<<"    n.y="<<n.y<<endl;
	return out;
}

const vector<Node>tn= {{1,1},{2,2},{3,3},{4,4},{5,5}};

void test() {
	for (auto &a:tn) {
		A.push(a);
		B.push(a);
	}

	cout<<"A:"<<endl;
	while(!A.empty()) {
		cout<<A.top();
		A.pop();
	}

	cout<<"B:"<<endl;
	while(!B.empty()) {
		cout<<B.top();
		B.pop();
	}
}

int main() {
	test();
	return 0;
}
