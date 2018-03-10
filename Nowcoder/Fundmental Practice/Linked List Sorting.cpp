//测试case太坑。。可能有节点不在链表上，还要注意链表可能为空

//方案一：静态链表模拟。样例通过，但是有问题？，运行超时

#define _CRT_SECURE_NO_WARNINGS
//
//#include<iostream>
//using namespace std;
//
//#define MAXADDR 99999
//#define MAXKEY 100000
//struct Node {
//	int key;
//	int next;
//};
//
//int main()
//{
//	freopen("dataIn.txt", "r", stdin);
//	freopen("dataOut.txt", "w", stdout);
//
//	int N;
//	struct Node L[MAXADDR + 1 + 1];
//	int head;
//	while (scanf("%d %d", &N, &head)!=EOF) {
//		int i;
//		int addr, next, key;
//		for (i = N; i--;) {
//			scanf("%d %d %d", &addr, &key, &next);
//			L[addr] = { key,next };
//		}
//		L[0].next = head;
//
//		int p, pre, q, r;
//		for (i = N, q = MAXADDR + 1; i--;) {
//			for (pre = 0, key = MAXKEY + 1; (p = L[pre].next) != -1; pre = p, p = L[p].next)
//				if (L[p].key < key) {
//					r = pre;
//					key = L[p].key;
//				}
//
//			L[q].next = L[r].next;
//			q = L[q].next;
//			L[r].next = L[L[r].next].next;
//		}
//		L[q].next = -1;
//
//		p = L[MAXADDR + 1].next;
//		printf("%d %05d\n", N, p);
//		for (i = N - 1; i--; p = L[p].next)
//			printf("%05d %d %05d\n", p, L[p].key, L[p].next);
//		printf("%05d %d %d\n", p, L[p].key, L[p].next);
//	}
//	return 0;
//}

////测试 pass
//#include <stdio.h>  
//#include <algorithm>  
//using namespace std;
//struct LList {
//	int address;
//	int key;
//	int next;
//	bool operator < (const LList &b) const
//	{
//		return key < b.key;
//	}
//};
//LList a[100000], b[100000];
//int main()
//{
//	int n, x;
//	while (scanf("%d%d", &n, &x) != EOF)
//	{
//		int p, q, r;
//		for (int i = 0; i < n; i++)
//		{
//			scanf("%d%d%d", &p, &q, &r);
//			a[p].address = p;
//			a[p].key = q;
//			a[p].next = r;
//		}
//		if (x == -1)
//		{
//			printf("0 -1\n");
//			continue;
//		}
//		int index = 0;
//		while (x != -1)
//		{
//			b[index].address = a[x].address;
//			b[index].key = a[x].key;
//			b[index].next = a[x].next;
//			x = a[x].next;
//			++index;
//		}
//		sort(b, b + index);
//		printf("%d %05d\n", index, b[0].address);
//		for (int i = 0; i < index - 1; i++)
//			printf("%05d %d %05d\n", b[i].address, b[i].key, b[i + 1].address);
//		printf("%05d %d -1\n", b[index - 1].address, b[index - 1].key);
//	}
//	return 0;
//}

//思路同上，实现全部C++
#include<iostream>  
#include <set>  
#include <vector>  
#include <map>  
#include <queue>  
#include <stack>  
#include <string>  
#include <string.h>  
#include <algorithm>  
using namespace std;

typedef struct Node
{
	int curAdress, key, nextAdress;
	bool exist;
	Node() { exist = false; }
	bool operator < (const Node& orh) const
	{
		return key < orh.key;
	}
}Node;
#define MAX 1000000  
int main()
{
	int n, root;
	scanf("%d%d", &n, &root);
	vector<Node> nodeMap(MAX);
	for (int i = 0; i < n; ++i)
	{
		Node tmp;
		scanf("%d%d%d", &tmp.curAdress, &tmp.key, &tmp.nextAdress);
		tmp.exist = true;
		if (tmp.curAdress >= 0 && tmp.curAdress < MAX)
			nodeMap[tmp.curAdress] = tmp;//vector随机访问
	}
	//process  
	vector<Node> nodeList;
	int curID = root;
	while (curID >= 0 && curID < MAX && nodeMap[curID].exist)
	{
		nodeList.push_back(nodeMap[curID]);
		curID = nodeMap[curID].nextAdress;
	}
	//output  
	if (nodeList.empty())
	{
		if (root == -1)
			printf("0 -1\n");
		else printf("0 %05d\n", root);
	}
	else
	{
		sort(nodeList.begin(), nodeList.end());//algorithm的sort函数
		printf("%d %05d\n", nodeList.size(), nodeList[0].curAdress);
		for (int i = 0; i < (int)nodeList.size(); ++i)
		{
			if (i != nodeList.size() - 1)
				printf("%05d %d %05d\n", nodeList[i].curAdress, nodeList[i].key, nodeList[i + 1].curAdress);
			else printf("%05d %d -1\n", nodeList[i].curAdress, nodeList[i].key);
		}
	}
	return 0;
}