/*
�����������ǣ�
1�������������printf("1\n%d", N); ��Ϊ1���㡣
2, �����������������û�����������˻���ʽ�����ӣ���printf("1\n%d", x)������x ��N����С��1�����ӡ�
3�������������˻���ʽ�����ӣ����������Ǹ����������ж�����������С���Ǹ����ӡ�

�������һ��ʼ������ʱ�򣬺ܾ��ţ�2 ^ 31�����������ص�����ٰ��������뵽������31�����������Ļ���30����29�������ҵ����ġ�����������������Ȼ�����㡣�ٺ������뵽���Դ�2~Nѭ������ѭ������ÿ������31�����ˣ���ѭ��������һ�ξ����Լ�, i���ڶ���Ϊi*(i + 1)��������Ϊi*(i + 1)*(i + 2)�������������һ��������N�����ӣ����˳���������һ����ѭ��, ���򣬸��ݺ�max�Ƚϣ������Ƿ��¼i, �����˴���time��
�����Ǵ��룬������������������
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
