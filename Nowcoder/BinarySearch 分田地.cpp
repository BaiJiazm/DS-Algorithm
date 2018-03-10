/* ********************************
��Ŀ��Դ��https://www.nowcoder.com/questionTerminal/fe30a13b5fb84b339cb6cb3f70dca699 
��Ŀ������
	ţţ�� 15 �������������������ص���Ϸ��ţţ��������������أ���������ؿ���
	������һ�����Σ�ÿ��λ����һ����ֵ���ָ���صķ����Ǻ��������������ֳ� 16 ��
	����Ϊ�쵼�ɲ���ţţ���ǻ�ѡ�������ܼ�ֵ��С��һ����أ� ��Ϊţţ��õ����ѣ�
	��ϣ��ţţȡ�õ���صļ�ֵ�;����ܴ���֪�����ֵ�������Ƕ����� 

��������:
	ÿ��������� 1 ������������ÿ�����������ĵ�һ�а����������� n �� m��1 <= n, 
	m <= 75������ʾ��صĴ�С���������� n �У�ÿ�а��� m �� 0-9 ֮������֣���ʾ
	ÿ��λ�õļ�ֵ��

�������:
	���һ�б�ʾţţ����ȡ�õ����ļ�ֵ��

��������:
4 4
3332
3233
3332
2323

�������:
2
* ********************************/

/* ********************************
ժ�ԣ�http://blog.csdn.net/chavo0/article/details/52205105 
���������� + ö�١����ִ��жϿ����ԡ�
���ַ�Χ��0��������ؼ�ֵ��
�������жϣ��ؼ������ٶ�����ֵΪmid������ö�����е�λ�ã�����ѭ������Ȼ�󿴺���
	���ж��ٵ���ö�ٺ���ʱ�����ⲿ�ֵ�4�����Σ��µ�һ��������һ��֮�䱻���ŵı�
	���Լ����������γɵ��ĸ����Σ��ļ�ֵ�����ڵ���mid��˵����һ���еú�������
	��λ�ÿ�ʼ��������ö�ٺ��С�������պ��еĵ������ڵ���4����ô˵�����ֵmid��
	����ģ����򲻺���ͨ�������Ĳ���ѹ�����䣬���ձ�Ȼ�ܹ��õ��𰸡�
	��������������ÿ��С���εĺͣ�Ҳ�ǿ���ͨ��Ԥ����Ȼ��õ��ġ�����ɼ����롣
* ********************************/

/* ********************************
�����ܽ᣺���������ڴ���ܶ�ö�ٷ�Χ�������ŷǳ��õ�Ч�����ر�������Ҫ���Ĵ�
	��ĳ����Χ֮�У����ö���+ö���ǲ���Ľⷨ�� 
	 
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
