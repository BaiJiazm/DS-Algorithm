//#include<iostream>
//#include<queue>
//using namespace std;
//
////��������
//struct Node {
//	int x;
//	int y;
//};
//
//struct cmp {
//	bool operator()(Node a,Node b) {
//		return  a.x > b.x;	//С����
//	}
//};
//
//struct cmp1 {
//	bool operator()(Node a,Node b) {
//		return  a.x < b.x;	//�󶥶�
//	}
//};
//
//priority_queue<Node,vector<Node>,cmp1 > A;   	//�����
//priority_queue<Node, vector<Node>, cmp > B;    //С����
//
//ostream & operator <<(ostream &out,const struct Node& n) {
//	out<<"n.x="<<n.x<<"    n.y="<<n.y<<endl;
//	return out;
//}
//
//const vector<Node>tn= {{1,1},{2,2},{3,3},{4,4},{5,5}};
//
//void test2() {
//	for (auto &a:tn) {
//		A.push(a);
//		B.push(a);
//	}
//
//	cout<<"A:"<<endl;
//	while(!A.empty()) {
//		cout<<A.top();
//		A.pop();
//	}
//
//	cout<<"B:"<<endl;
//	while(!B.empty()) {
//		cout<<B.top();
//		B.pop();
//	}
//}
//
//int main() {
//	test2();
//	return 0;
//}
