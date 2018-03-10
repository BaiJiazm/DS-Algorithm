#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<string.h>
//struct digit {
//	char tail[110];
//	int index;
//};
//struct digit n1, n2;
//int signif;
//
//void convert(struct digit*pn,char *str)
//{
//	int i, j;
//	for (i = 0; str[i] == '0'; ++i)
//		;
//	if (i)
//		if (str[i] != '.')
//			strcpy(str, str + i);
//		else
//			strcpy(str, str + i - 1);
//	for (i = 0; str[i] && str[i] != '.'; ++i)
//		;
//	if (str[i] == '.')
//		if (str[0] != '0')
//		{
//			pn->index = i;
//			strcpy(str + i, str + i + 1);
//		}
//		else
//		{
//			for (j = i + 1; str[j] && str[j] == '0'; ++j)
//				;
//			pn->index = str[j] ? i - j + 1 : 0;
//			strcpy(str, str + j);
//		}
//	else
//		pn->index = str[0] != '0' ? i : 0;
//	    
//	for (i = 0; str[i] && i < signif; ++i)
//		pn->tail[i] = str[i];
//	for (; i < signif; ++i)
//		pn->tail[i] = '0';
//	pn->tail[i] = '\0';
//}
//int compare()
//{
//	if (n1.index != n2.index)
//		return n1.index - n2.index;
//	return strcmp(n1.tail, n2.tail);
//}
//
//void formOut(struct digit *pn)
//{
//	printf(" 0.%s*10^%d", pn->tail, pn->index);
//}
//int main()
//{
//	scanf("%d", &signif);
//
//	char str[120];
//	scanf("%s", str);
//	convert(&n1, str);
//	scanf("%s", str);
//	convert(&n2, str);
//
//	if (compare() == 0) {
//		printf("YES");
//		formOut(&n1);
//	}
//	else {
//		printf("NO");
//		formOut(&n1);
//		formOut(&n2);
//	}
//
//	return 0;
//}




#include<stdio.h>
#include<string.h>
struct digit {
	char tail[110];
	int index;
}n[2];
int signif;

void convert(struct digit*pn, char *str)
{
	int firstPos = -1, pointPos = -1;
	int i, j;
	for (i = 0, j = 0; str[i]; ++i) {
		if (firstPos == -1 && str[i] == '0')
			continue;
		else if (str[i] == '.')
			pointPos = i;
		else {
			if (firstPos == -1)
				firstPos = i;
			pn->tail[j++] = str[i];
		}
	}
	if (firstPos == -1)
		pn->index = 0;
	else if (pointPos == -1)
		pn->index = strlen(str) - firstPos;
	else if (firstPos < pointPos)
		pn->index = pointPos - firstPos;
	else
		pn->index = pointPos - firstPos + 1;
	for (pn->tail[signif] = 0; j < signif; ++j)
		pn->tail[j] = '0';
}
int compare(struct digit*n1,struct digit*n2)
{
	if (n1->index != n2->index)
		return n1->index - n2->index;
	return strcmp(n1->tail, n2->tail);
}

void formOut(struct digit *pn)
{
	printf(" 0.%s*10^%d", pn->tail, pn->index);
}
int main()
{
	scanf("%d ", &signif);

	int i;
	char str[120];
	for (i = 0; i < 2; ++i) {
		scanf("%s", str);
		convert(n + i, str);
	}
	if (compare(n, n + 1) == 0) {
		printf("YES");
		formOut(n);
	}
	else {
		printf("NO");
		formOut(n);
		formOut(n + 1);
	}

	return 0;
}