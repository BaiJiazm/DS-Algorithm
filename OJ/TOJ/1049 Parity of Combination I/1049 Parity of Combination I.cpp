#include<cstdio>
#include<cstring>

bool s[1005][1005];
void init() {
	int i,j,k;
	for(i=0; i<=1000; ++i) {
		s[i][0]=false;
		for (j=1; j<i; ++j)
			s[i][j]=s[i-1][j-1]==s[i-1][j];
	}
}

int main() {
	memset(s,0,sizeof (s));
	int T,N,M;
	init();
	while(~scanf("%d",&T)) {
		while(T--) {
			scanf("%d %d",&N,&M);
			if (s[N][M])
				printf("even\n");
			else
				printf("odd\n");
		}
	}
	return 0;
}
