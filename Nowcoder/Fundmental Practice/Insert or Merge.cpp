#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;
#define NMAX 100

int insert(int*A, int size, int* inputOrder)
{
	int i, j, k;
	int flag = 1;
	int value;
	for (i = 2; i <= size&&flag; ++i) {
		if (A[i] < A[i - 1]) {
			for (j = i, value = A[0] = A[j]; value < A[j - 1]; --j)
				A[j] = A[j - 1];
			A[j] = value;
		}
		for (k = 1; k <= size&&A[k] == inputOrder[k]; ++k)
			;
		if (k > size)
			flag = 0;
	}
	if (!flag&&A[i] < A[i - 1]) {
		for (j = i, value = A[0] = A[j]; value < A[j - 1]; --j)
			A[j] = A[j - 1];
		A[j] = value;
	}

	return !flag;
}

void merge(int*A, int size, int* inputOrder)
{
	int i, j, k, l, n;
	int flag = 1;
	int value;

	for (n = 1; n < size&&flag; n *= 2) {
		for (i = 1; i < size; i += n * 2)
			for (j = i + n, k = 0; j <= size&&k < n; ++j, ++k) {
				if (A[j] < A[j - 1]) {
					for (value = A[j], l = j; l > i && value < A[l - 1]; --l)
						A[l] = A[l - 1];
					A[l] = value;
				}
			}

		for (k = 1; k <= size&&A[k] == inputOrder[k]; ++k)
			;
		if (k > size)
			flag = 0;
	}
	for (i = 1; i < size; i += n * 2)
		for (j = i + n, k = 0; j <= size&&k < n; ++j, ++k) {
			if (A[j] < A[j - 1]) {
				for (value = A[j], l = j; l > i && value < A[l - 1]; --l)
					A[l] = A[l - 1];
				A[l] = value;
			}
		}
}

int main()
{
	int N;
	int oriArray[NMAX + 1];
	int ori2[NMAX + 1];
	int inputOrder[NMAX + 1];
	while (scanf("%d", &N) != EOF) {
		int i;
		for (i = 1; i <= N; ++i)
			scanf("%d", oriArray + i);
		memcpy(ori2, oriArray, sizeof(oriArray));

		for (i = 1; i <= N; ++i)
			scanf("%d", inputOrder + i);

		int *ans = ori2;
		if (!insert(ori2, N, inputOrder)) {
			merge(oriArray, N, inputOrder);
			ans = oriArray;
			printf("Merge Sort\n");
		}
		else
			printf("Insertion Sort\n");
		for (i = 1; i <= N; ++i)
			i == 1 ? printf("%d", ans[i]) : printf(" %d", ans[i]);
	}
	return 0;
}


///////////////////////////////////////////////////////////////////
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	// 读入数据
	int N; cin >> N;
	vector<int> startState(N), midState(N);
	for (int i = 0; i<N; i++) {
		cin >> startState[i];
	}
	for (int i = 0; i<N; i++) {
		cin >> midState[i];
	}

	// 判断哪种排序
	bool isInsertion = true; int idx = N - 1;
	while (midState[idx] == startState[idx]) { idx--; }
	while (idx>0) {
		if (midState[idx] < midState[idx - 1]) {
			isInsertion = false; break;
		}
		idx--;
	}

	// 获取下一状态
	if (isInsertion) {
		for (idx = 1; idx <= N; idx++) {
			sort(startState.begin(), startState.begin() + idx);
			if (startState == midState) { break; }
		}
		for (idx++; idx <= N; idx++) {
			sort(startState.begin(), startState.begin() + idx);
			if (startState != midState) { break; }
		}
		cout << "Insertion Sort" << endl;
	}
	else {
		for (idx = 1; idx <= N; idx *= 2) {
			int i = 0;
			for (; i + idx <= N; i += idx) {
				sort(startState.begin() + i, startState.begin() + i + idx);
			}
			if (i<N) sort(startState.begin() + i, startState.end());
			if (startState == midState) break;
		}
		for (idx *= 2; idx <= N; idx *= 2) {
			int i = 0;
			for (; i + idx <= N; i += idx) {
				sort(startState.begin() + i, startState.begin() + i + idx);
			}
			if (i<N) sort(startState.begin() + i, startState.end());
			if (startState != midState) break;
		}
		cout << "Merge Sort" << endl;
	}
	for (int i = 0; i<N; i++) {
		if (i) cout << " ";
		cout << startState[i];
	}
	return 0;
}
