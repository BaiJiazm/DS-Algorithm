//#include<iostream>
//#include<queue>
//using namespace std;
//
////方法一
//struct Node {
//	int x,y;
//	bool operator <(Node a) const  {	//必须加const
//		return y < a.y;
//	}
//	bool operator >(Node a) const  {	//必须加const
//		return y > a.y;
//	}
//};
//
//ostream & operator <<(ostream &out,const struct Node& n) {
//	out<<"n.x="<<n.x<<"    n.y="<<n.y<<endl;
//	return out;
//}
//
//const vector<Node>tn= {{1,1},{2,2},{3,3},{4,4},{5,5}};
//
//void test1() {
////	priority_queue<Node> A;   //默认	大根堆
//	priority_queue<Node, vector<Node>, less<Node>>A;	//大根堆
//	priority_queue<Node, vector<Node>, greater<Node> > B;    //小根堆
//
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
//	test1();
//	return 0;
//}
