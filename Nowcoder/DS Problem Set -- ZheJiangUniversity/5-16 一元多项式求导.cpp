//#define  _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	int c, i;
//	int flag = 0;
//
//	while (scanf("%d%d", &c, &i) != EOF)
//		if (i)
//			if (!flag)
//			{
//				printf("%d %d", c*i, i - 1);
//				flag = 1;
//			}
//			else
//				printf(" %d %d", c*i, i - 1);
//	
//	if (!flag)
//		printf("0 0");
//
//	return 0;
//}


#include <string.h>
#include <iostream>

using namespace std;

int main()
{
	int a, b;
	int flag = 0;
	b = 1;
	
	while (cin >> a >> b)
		if (flag == 0)
		{
			cout << a*b << ' ' << b - 1;
			flag = 1;
		}
		else
			cout << ' ' << a*b << ' ' << b - 1;

	if (flag == 0)
		cout << "0 0";
	
	return 0;
}
