#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define INF 100000000
int carry[] = { 29,17,INF };

int main()
{
	int a[3];
	int b[3];
	int ans[3];
	scanf("%d.%d.%d %d.%d.%d", a + 2, a + 1, a, b + 2, b + 1, b);

	int i;
	int c = 0;
	for (i = 0; i < 3; ++i)
	{
		c += a[i];
		c += b[i];
		ans[i] = c%carry[i];
		c /= carry[i];
	}
	printf("%d.%d.%d", ans[2], ans[1], ans[0]);
	return 0;
}

