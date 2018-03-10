#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MAXNODENUM 100
struct Node {
	int weight;
	vector<int>child;
};

vector<vector<int>>ans;
vector<int>tem;
int N, M, S;
int w;
struct Node tree[MAXNODENUM];

//sort	方法一
struct myclass {
	bool operator () (const vector<int>&v1, const vector<int>&v2)
	{
		int i = 0;
		int size1 = (int)v1.size();
		int size2 = (int)v2.size();

		while (i < size1 && i < size2 && v1[i] == v2[i])
			++i;
		if (i == size1 || i == size2)
			return size1>size2;
		else
			return v1[i] > v2[i];
	}
}myobject;

//sort	方法二
bool cmp(const vector<int>&v1, const vector<int>&v2)
{
	int i = 0;
	int size1 = (int)v1.size();
	int size2 = (int)v2.size();

	while (i < size1 && i < size2 && v1[i] == v2[i])
		++i;

	/*
	10 3 3 6 2
	10 3 3 6 2
	*/

	/*自己与自己比较既能返回true,也能返回false
	错误原因值得思考，具体参考	http://en.cppreference.com/w/cpp/concept/Compare

	Expression	Return type	Requirements
	comp(a, b)	implicitly convertible to bool	Establishes strict weak ordering relation with the following properties
	For all a, comp(a,a)==false
	If comp(a,b)==true then comp(b,a)==false
	if comp(a,b)==true and comp(b,c)==true then comp(a,c)==true

	/*	错误代码：
	if (i == size2)
	return true;
	else if (i == size1)
	return false;
	else
	return v1[i] > v2[i];
	*/

	//正确代码
	if (i == size1 || i == size2)
		return size1 > size2;
	else
		return v1[i] > v2[i];
}

void preOrder(const struct Node &t)
{
	int i;

	tem.push_back(t.weight);
	w += t.weight;

	if (w == S&&t.child.empty())
		ans.push_back(tem);
	else if (w < S)
		for (i = 0; i < (int)t.child.size(); ++i)
			preOrder(tree[t.child[i]]);

	tem.pop_back();
	w -= t.weight;
}

int main()
{
	int i, j;
	int nodeNo, childNum, child;

	while (scanf("%d %d %d", &N, &M, &S) != EOF) {
		for (i = 0; i < N; ++i)
			scanf("%d", &tree[i].weight);
		for (i = 0; i < M; ++i) {
			scanf("%d %d", &nodeNo, &childNum);
			while (childNum--) {
				scanf("%d", &child);
				tree[nodeNo].child.push_back(child);
			}
		}

		w = 0;
		tem.clear();
		preOrder(tree[0]);
		
		sort(ans.begin(), ans.end(),cmp);			//方法一
		//sort(ans.begin(), ans.end(),myobject);	//方法二
		//sort(ans.begin(), ans.end());		//默认升序排列

		for (i = 0; i < (int)ans.size(); ++i) {
			for (j = 0; j < (int)ans[i].size(); ++j)
				j ? printf(" %d", ans[i][j]) : printf("%d", ans[i][j]);
			printf("\n");
		}
		ans.clear();
	}
	return 0;
}