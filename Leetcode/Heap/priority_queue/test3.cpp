//#include<iostream>
//#include<queue>
//using namespace std;
//
////方法三：
//struct Node {
//	int x;
//	int y;
//};
//
//bool operator<(const Node &a, const Node &b) {
//	return a.x<b.x;			 //大顶堆
//}
//
//bool operator>(const Node &a, const Node &b) {
//	return a.x>b.x;			//小顶堆
//}
//
//priority_queue<Node,vector<Node>,less<Node> > A;   	//大根堆
//priority_queue<Node, vector<Node>, greater<Node> > B;    //小根堆
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

