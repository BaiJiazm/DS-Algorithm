#define _CRT_SECURE_NO_WARNINGS
/* 仍然有一个case 过不去，不知道哪里错了，可能复制粘贴时修改错了*/
#include <stdio.h>
#include<string.h>

struct num {
	int sign;
	char str[65];
};
struct num n1, n2, n3, n4;

void addadd()
{
	int len1, len2;
	len1 = strlen(n1.str);
	len2 = strlen(n2.str);
	int len3 = len1 > len2 ? len1 : len2;
	int carry = 0, radus;
	int s;

	for (n3.str[len3--] = 0, --len1, --len2; len1 >= 0 && len2 >= 0; --len1, --len2, --len3) {
		s = n1.str[len1] + n2.str[len2] - '0' * 2 + carry;
		carry = s / 10;
		radus = s % 10;
		n3.str[len3] = radus + '0';
	}
	for (; len1 >= 0; --len1)
		if (carry) {
			s = carry + n1.str[len1] - '0';
			carry = s / 10;
			radus = s % 10;
			n3.str[len1] = radus + '0';
		}
		else
			n3.str[len1] = n1.str[len1];
	for (; len2 >= 0; --len2)
		if (carry) {
			s = carry + n2.str[len2] - '0';
			carry = s / 10;
			radus = s % 10;
			n3.str[len2] = radus + '0';
		}
		else
			n3.str[len2] = n2.str[len2];
	n3.str[0] += carry;
}
void sub(struct num*n1,struct num*n2)
{
	int len1 =strlen(n1->str);
	int len2 = strlen(n2->str);
	int len3 = len1 > len2 ? len1 : len2;
	n3.str[len3] = 0;
	--len1, --len2, --len3;
	while (len1 >= 0 && len2 >= 0) {
		n3.str[len3] = n1->str[len1] - n2->str[len2];
		if (n3.str[len3] < 0) {
			--n1->str[len1 - 1];
			n3.str[len3] += 10;
		}
		n3.str[len3] += '0';
		--len1, --len2, --len3;
	}
	while (len1 >= 0) {
		if (n1->str[len1] < '0') {
			n1->str[len1] += 10;
			--n1->str[len1 - 1];
		}
		n3.str[len3--] = n1->str[len1--];
	}
	while (len2 >= 0) {
		if (n2->str[len2] < '0') {
			n2->str[len2] += 10;
			--n2->str[len2 - 1];
		}
		n3.str[len3--] = n2->str[len2--];
	}
}
void add()
{
	n1.str[0] = n2.str[0] = '0';
	if (n1.str[1] == '-'){
		n1.sign = 1;
		strcpy(n1.str + 1, n1.str + 2);
	}
	else
		n1.sign = 0;

	if (n2.str[1] == '-') {
		n2.sign = 1;
		strcpy(n2.str + 1, n2.str + 2);
	}
	else
		n2.sign = 0;
	
	if (n1.sign == n2.sign) {
		n3.sign = n1.sign;
		addadd();
	}
	else if (strlen(n1.str) > strlen(n2.str)) {
		n3.sign = n1.sign;
		sub(&n1, &n2);
	}
	else if (strlen(n1.str) < strlen(n2.str)) {
		n3.sign = n2.sign;
		sub(&n2, &n1);
	}
	else if (strcmp(n1.str, n2.str) > 0) {
		n3.sign = n1.sign;
		sub(&n1, &n2);
	}
	else if (strcmp(n1.str, n2.str) < 0) {
		n3.sign = n2.sign;
		sub(&n2, &n1);
	}
	else {
		n3.sign = 0;
		strcpy(n3.str, "0");
	}
	printf("sum= %c%s\n", n3.sign ? '-' : ' ', n3.str);
}
int compare()
{
	if (n4.str[0] == '-') {
		n4.sign = 1;
		strcpy(n4.str, n4.str + 1);
	}
	else
		n4.sign = 0;
	
	if (n3.sign != n4.sign)
		return n4.sign - n3.sign;
	int i;
	for (i = 0; n3.str[i] && n3.str[i] == '0'; ++i)
		;
	int len3, len4;
	len3 = strlen(n3.str + i);
	len4 = strlen(n4.str);
	if (len3 != len4)
		return n3.sign ? len4 - len3 : len3 - len4;
	else
		return n3.sign ? strcmp(n4.str, n3.str + i) : strcmp(n3.str + i, n4.str);
}
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) {
		scanf("%s %s %s", n1.str + 1, n2.str + 1, n4.str);
		add();
		printf("Case #%d: %s\n", i, compare() > 0 ? "true" : "false");
	}
	return 0;
}

//#include <stdio.h>
//
//int main()
//{
//	long long int a, b, c;
//	int N;
//	scanf("%d", &N);
//	for (int i = 1; i <= N; ++i) {
//		scanf("%lld %lld %lld", &a, &b, &c);
//		long long int sum = a + b;
//		bool res = true;
//		if (a < 0 && b < 0 && sum>=0)
//			res = false;
//		else if (a>0 && b > 0 && sum <= 0)
//			res = true;
//		else if (sum <= c)
//			res = false;
//		printf("Case #%d: %s\n", i, res ? "true" : "false");
//	}
//	return 0;
//}