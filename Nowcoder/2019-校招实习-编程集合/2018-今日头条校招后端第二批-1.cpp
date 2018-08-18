/*
为了不断优化推荐效果，今日头条每天要存储和处理海量数据。假设有这样一种场景：我们对用户按照它们的注册时间先后来标号，对于一类文章，每个用户都有不同的喜好值，我们会想知道某一段时间内注册的用户（标号相连的一批用户）中，有多少用户对这类文章喜好值为k。因为一些特殊的原因，不会出现一个查询的用户区间完全覆盖另一个查询的用户区间(不存在L1<=L2<=R2<=R1)。
输入描述:
输入： 第1行为n代表用户的个数 第2行为n个整数，第i个代表用户标号为i的用户对某类文章的喜好度 第3行为一个正整数q代表查询的组数  第4行到第（3+q）行，每行包含3个整数l,r,k代表一组查询，即标号为l<=i<=r的用户中对这类文章喜好值为k的用户的个数。 数据范围n <= 300000,q<=300000 k是整型
输出描述:
输出：一共q行，每行一个整数代表喜好值为k的用户的个数

输入例子1:
5
1 2 3 3 5
3
1 2 1
2 4 5
3 5 3

输出例子1:
1
0
2

例子说明1:
样例解释:
有5个用户，喜好值为分别为1、2、3、3、5，
第一组询问对于标号[1,2]的用户喜好值为1的用户的个数是1
第二组询问对于标号[2,4]的用户喜好值为5的用户的个数是0
第三组询问对于标号[3,5]的用户喜好值为3的用户的个数是2
*/

//链接：https://blog.csdn.net/flushhip/article/details/79416715 
//评价：难度2的题目，算是比较好的写法，
//知识：C++STL equal_range lower_bound upper_bound的运用 

#include <bits/stdc++.h>

using namespace std;

bool sort_cmp(const pair<int, int> &A, const pair<int, int> &B) {
	return A.first == B.first ? A.second < B.second :
	       A.first < B.first;
}

struct find_first_cmp {
	bool operator()(const pair<int, int> &P, int k) const {
		return P.first < k;
	}

	bool operator()(int k, const pair<int, int> &P) const {
		return k < P.first;
	}
};

struct find_second_cmp {
	bool operator()(const pair<int, int> &P, int k) const {
		return P.second < k;
	}

	bool operator()(int k, const pair<int, int> &P) const {
		return k < P.second;
	}
};

int main() {
	int n, q;
	while (EOF != scanf("%d", &n)) {
		vector<pair<int, int> > arr;
		for (int i = 0, x; i < n; cin >> x, arr.emplace_back(x, ++i)) {}
		sort(arr.begin(), arr.end(), sort_cmp);

		for (scanf("%d", &q); q--;) {
			int L, R, k;
			scanf("%d%d%d", &L, &R, &k);
			pair<vector<pair<int, int> >::iterator, vector<pair<int, int> >::iterator> sd =
			    equal_range(arr.begin(), arr.end(), k, find_first_cmp {});
			printf("%d\n", upper_bound(sd.first, sd.second, R, find_second_cmp {}) -
			       lower_bound(sd.first, sd.second, L, find_second_cmp {}));
		}
	}
	return 0;
}
