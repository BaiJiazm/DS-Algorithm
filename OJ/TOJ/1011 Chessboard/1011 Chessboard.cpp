#include<cstdio>
int main() {
	int L,W;
	while(~scanf("%d %d",&L,&W)) {
		if ((L&1)^(W&1))
			printf("God save the pig!\n");
		else
			printf("My God!\n");
	}
	return 0;
}
