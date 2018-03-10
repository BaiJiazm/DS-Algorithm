/*
这道题题意就是：
1，如果是素数，printf("1\n%d", N); 因为1不算。
2, ，如果不是素数但是没有连续整数乘积形式的因子，则printf("1\n%d", x)，其中x 是N的最小非1的因子。
3，有连续整数乘积形式的因子，则输出最长的那个，如果最长的有多个，则输出最小的那个因子。

这道题我一开始看到的时候，很惊慌，2 ^ 31的数，这来回得算多少啊！后来想到可以算31个连续整数的积，30个，29个。。找到最大的。。但是这样处理显然不方便。再后来，想到可以从2~N循环（外循环），每个数做31次连乘（内循环），第一次就是自己, i，第二次为i*(i + 1)，第三次为i*(i + 1)*(i + 2)。。。如果遇到一个积不是N的因子，则退出，继续下一个外循环, 否则，根据和max比较，决定是否记录i, 和连乘次数time。
以下是代码，请结合上述叙述来看。
*/

#include<stdio.h>  
#include<math.h>  

int main() {
	int i, j, time, max, start;

	long long N;
	max = 1;
	start = N;

	bool flag = false;
	scanf("%lld", &N);
	int n;
	n = (int)sqrt((double)N) + 2;

	for (i = 2; i <= n; i++) {
		long long res = 1;
		j = i;
		for (time = 1; time <= 31; time++) {
			res = res*((long long)(j));
			j++;
			if (res > N || N%res != 0)break;
			if (N%res == 0) {
				if (!flag || time > max) {
					max = time;
					start = i;
					flag = true;
				}
			}
		}
	}

	if (!flag) {
		printf("1\n%d", N);
		return 0;
	}

	printf("%d\n", max);

	for (i = 0; i < max; i++) {
		if (i == 0) {
			printf("%d", start);
		}
		else {
			printf("*%d", start + i);
		}
	}
	return 0;

}
