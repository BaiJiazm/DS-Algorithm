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
//bool operator<(const Node &a, const Node &b) {
//	return a.x<b.x;			 //�󶥶�
//}
//
//bool operator>(const Node &a, const Node &b) {
//	return a.x>b.x;			//С����
//}
//
//priority_queue<Node,vector<Node>,less<Node> > A;   	//�����
//priority_queue<Node, vector<Node>, greater<Node> > B;    //С����
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

