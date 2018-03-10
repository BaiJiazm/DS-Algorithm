/* ********************************
题目来源：https://www.nowcoder.com/questionTerminal/fe30a13b5fb84b339cb6cb3f70dca699 
题目描述：
	牛牛和 15 个朋友来玩打土豪分田地的游戏，牛牛决定让你来分田地，地主的田地可以
	看成是一个矩形，每个位置有一个价值。分割田地的方法是横竖各切三刀，分成 16 份
	，作为领导干部，牛牛总是会选择其中总价值最小的一份田地， 作为牛牛最好的朋友，
	你希望牛牛取得的田地的价值和尽可能大，你知道这个值最大可以是多少吗？ 

输入描述:
	每个输入包含 1 个测试用例。每个测试用例的第一行包含两个整数 n 和 m（1 <= n, 
	m <= 75），表示田地的大小，接下来的 n 行，每行包含 m 个 0-9 之间的数字，表示
	每块位置的价值。

输出描述:
	输出一行表示牛牛所能取得的最大的价值。

输入例子:
4 4
3332
3233
3332
2323

输出例子:
2
* ********************************/

/* ********************************
摘自：http://blog.csdn.net/chavo0/article/details/52205105 
分析：二分 + 枚举。二分答案判断可行性。
二分范围：0至所有田地价值和
可行性判断（关键）：假定二分值为mid。暴力枚举竖切的位置（三重循环），然后看横切
	能切多少刀。枚举横切时，当这部分的4个矩形（新的一横与上面一横之间被竖着的边
	界以及竖切三刀形成的四个矩形）的价值都大于等于mid，说明这一刀切得合理，从这
	个位置开始继续往下枚举横切。如果最终横切的刀数大于等于4，那么说明这个值mid是
	合理的，否则不合理。通过这样的不断压缩区间，最终必然能够得到答案。
	其中如何巧妙计算每个小矩形的和，也是可以通过预处理然后得到的。具体可见代码。
* ********************************/

/* ********************************
个人总结：二分搜索在处理很多枚举范围问题有着非常好的效果，特别适用于要求解的答案
	在某个范围之中，利用二分+枚举是不错的解法。 
	 
* ********************************/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 75 + 5;

int n, m;
char str[maxn];
int a[maxn][maxn];
int sum[maxn][maxn];

void input() {

	for(int i = 1; i <= n; ++i) {
		scanf("%s", str + 1);
		for(int j = 1; j <= m; ++j) {
			a[i][j] = str[j] - '0';
		}
	}
}

int getArea(int x1, int y1, int x2, int y2) {
	return (sum[x2][y2] - sum[x2][y1] - sum[x1][y2] + sum[x1][y1]);
}

bool judge(int mid) {

	for(int j1 = 1; j1 <= m - 3; ++j1) {
		for(int j2 = j1 + 1; j2 <= m - 2; ++j2) {
			for(int j3 = j2 + 1; j3 <= m - 1; ++j3) {

				int prei = 0, cnt = 0;
				for(int i = 1; i <= n; ++i) {

					int cube1 = getArea(prei, 0, i, j1);
					int cube2 = getArea(prei, j1, i, j2);
					int cube3 = getArea(prei, j2, i, j3);
					int cube4 = getArea(prei, j3, i, m);

					if(cube1 >= mid && cube2 >= mid && cube3 >= mid && cube4 >= mid) {
						prei = i;
						cnt += 1;
					}
				}

				if(cnt >= 4) return true;
			}
		}
	}
	return false;
}

void solve() {

	memset(sum, 0, sizeof(sum));

	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
		}
	}

	int l = 0, r = sum[n][m], mid;
	int ans = 0;

	while(l <= r) {

		mid = (l + r) >> 1;
		if(judge(mid)) {
			l = mid + 1;
			ans = mid;
		} else {
			r = mid - 1;
		}
	}

	printf("%d\n", ans);
}

int main() {

	while(scanf("%d%d", &n, &m) != EOF) {
		input();
		solve();
	}
	return 0;
}
