#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstring>
#include<stack>
using namespace std;

#define MMAX 100

void printStack(stack<int>&ans)
{
	stack<int>tem;
	while (!ans.empty()){
		tem.push(ans.top());
		ans.pop();
	}
	printf("%d", tem.top());
	tem.pop();
	while (!tem.empty()) {
		printf(" %d", tem.top());
		tem.pop();
	}
}
int main()
{
	//freopen("dataIn.txt", "r", stdin);
	//freopen("dataOut.txt", "w", stdout);

	int N, M;
	int v[MMAX + 1];

	int value;
	while (scanf("%d %d", &N, &M) != EOF) {
		memset(v, 0, sizeof(v));
		while (N--) {
			scanf("%d", &value);
			v[value]++;
		}

		stack<int>ans;
		int sum = 0;
		int i = 1;
		bool flag = false;

		for (; i <= M&&!v[i]; ++i)
			;

		while (!ans.empty() || i <= M / 2) {
			if (i + sum < M) {
				ans.push(i);
				--v[i];
				sum += i;
			}
			else if (i + sum == M) {
				flag = true;
				ans.push(i);
				break;
			}
			else {
				i = ans.top();
				ans.pop();
				sum -= i;
				++v[i++];
			}

			for (; i <= M&&!v[i]; ++i)
				;
		}

		if (flag)
			printStack(ans);
		else if (v[M])
			printf("%d", M);
		else
			printf("No Solution");
		printf("\n");
	}
	return 0;
}


//������	��̬�滮
//http://blog.csdn.net/xyt8023y/article/details/47255241

//#include <iostream>  
//#include <fstream>  
//#include <algorithm>  
//#include <cstring>  
//#include <vector>  
//using namespace std;
//
//#define MAXTOTAL    10001  
//#define MAXAMOUNT   101  
//
//int f[MAXTOTAL][MAXAMOUNT];         //f[n][m]��ʾ ǰn������ �ó��� ��ӽ�m ��ֵ  
//bool has[MAXTOTAL][MAXAMOUNT];      //has[n][m]��ʾ��ǰn�����еó���ӽ�m��ֵʱ �Ƿ��õ�c[n]  
//int* c = NULL;
//
//int calcClosestSum(int n, int m)
//{
//	memset(f, 0, sizeof(int)*MAXTOTAL*MAXAMOUNT);
//	memset(has, false, sizeof(bool)*MAXTOTAL*MAXAMOUNT);
//	int i, j;
//	int sec; // ��ʾ����c[i]���ֵ  
//	for (i = 1; i<n + 1; i++)
//	{
//		for (j = 1; j <= m; j++)
//		{
//			if (j - c[i]<0) sec = 0; // ���������С�ڵ���j����˵��������ǷǷ�ֵ����������Ϊ0����ʾ��ֵ��Ч��  
//			else sec = f[i - 1][j - c[i]] + c[i]; // ��������¼������c[i]��ֵ��  
//			if (f[i - 1][j] > sec)
//			{
//				f[i][j] = f[i - 1][j];
//			}
//			else
//			{
//				f[i][j] = sec;
//				has[i][j] = true;     //�õ�c[i]�� ��has[i][j]Ϊtrue  
//			}
//		}
//	}
//	return f[n][m];
//}
//
//bool cmp(const int& A, const int& B)
//{
//	return A>B;
//}
//
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	c = new int[n + 1];
//	memset(c, 0, sizeof(int)*(n + 1));
//
//	int i;
//	for (i = 0; i < n; i++)
//	{
//		cin >> c[i + 1];
//	}
//	sort(&c[1], &c[n + 1], cmp);     //�Ӵ�С����  
//
//	int res = calcClosestSum(n, m);
//	if (res == m)                   //�н�  
//	{
//		vector<int> v;
//		while (m)
//		{
//			while (!has[n][m])
//				n--;
//			v.push_back(c[n]);
//			m = m - c[n];
//			n--;
//		}
//		for (i = 0; i < v.size() - 1; i++)
//			cout << v[i] << ' ';
//		cout << v[i] << endl;
//	}
//	else                        //�޽�  
//		cout << "No Solution" << endl;
//	return 0;
//}