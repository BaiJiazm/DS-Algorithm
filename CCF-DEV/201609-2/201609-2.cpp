#include<iostream>
#include<cstring>
using namespace std;

bool ticheckt[101];

void sell(int p) {
	int i,j,t;
	for (i=1; i<100; i+=5) {
		for (j=i,t=0; j<i+5&&t<p; ++j)
			t=ticheckt[j]?0:t+1;
		if (t>=p) {
			int start=j-p;
			for (j=0; j<p; ++j) {
				j?printf(" %d",start+j):printf("%d",start+j);
				ticheckt[start+j]=true;
			}
			printf("\n");
			return ;
		}
	}

	//注：90原因有两点，不要以为简单就理所当然，编程需要一定细心
	//1.i<=100不是i<100
	//2.忘记++j;
	for (i=1,j=0; i<=100&&j<p; ++i)
		if (!ticheckt[i]) {
			ticheckt[i]=true;
			j?printf(" %d",i):printf("%d",i);
			++j;
		}
	printf("\n");
}

int main() {
	int n;
	while(scanf("%d",&n)!=EOF) {
		memset(ticheckt,false,sizeof(ticheckt));

		int i,p;
		for (i=0; i<n; ++i) {
			scanf("%d",&p);
			sell(p);
		}
	}
	return 0;
}
