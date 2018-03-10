//含1的数字的个数
//#define _CRT_SECURE_NO_WARNINGS
//
//#include<iostream>
//#include<cmath>
//using namespace std;
//
//int unitOne[10];
//int digit[10];
//
//void countUnit()
//{
//	int i;
//	for (i = 1, unitOne[0] = 1; i <= 9; ++i)
//		unitOne[i] = (int)pow(10, i) + 9 * unitOne[i - 1];
//
//	//for (i = 0; i <= 9; ++i)
//	//	cout << unitOne[i] << endl;
//}
//
//void split(int N)
//{
//	int i;
//	for (i = 1; i <= 10; ++i) {
//		digit[i] = N % 10;
//		N /= 10;
//	}
//}
//
//int main()
//{
//	int N;
//	int ans;
//	countUnit();
//	
//	while (scanf("%d", &N) != EOF) {
//		//split(N);
//		int i, k;
//		int integer;
//		for (i = 9, ans = 0; i >=0; --i) {
//			k = (int)pow(10, i);
//			integer = N / k;
//			N %= k;
//
//			if (integer == 1) {
//				ans += unitOne[i - 1] + N + 1;
//				break;
//			}
//			else if (integer > 1) 
//				ans += (integer - 1)*unitOne[i - 1];
//		}
//		printf("%d\n", ans);
//	}
//	return 0;
//}

//求1的个数
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cmath>
using namespace std;

int unitOne[10];
int digit[10];

void countUnit()
{
	int i;
	for (i = 1, unitOne[0] = 0; i <= 9; ++i)
		unitOne[i] = (int)pow(10, i - 1) + 10 * unitOne[i - 1];
}

int main()
{
	int N;
	int ans;
	countUnit();

	while (scanf("%d", &N) != EOF) {
		int i, k;
		int quotient;
		for (i = 10, ans = 0; i >0; --i) {
			k = (int)pow(10, i - 1);
			quotient = N / k;
			N %= k;

			if (quotient == 1)
				ans += unitOne[i - 1] + N + 1;
			else if (quotient > 1)
				ans += (int)pow(10, i - 1) + quotient*unitOne[i - 1];
		}
		printf("%d\n", ans);
	}
	return 0;
}
