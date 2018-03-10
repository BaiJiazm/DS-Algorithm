#include<cstdio>
#include<cstring>

int main(){
	int n;
	bool c[410];
	while(~scanf("%d",&n)&&n){
		memset(c,0,sizeof(c));
		int i,k;
		for (i=0;i<n;++i){
			scanf("%d",&k);
			c[k]=true;
		}
		for (i=0;i<=400;++i)
			if(c[i])
				printf("%d ",i);
		printf("\n"); 
	}
	return 0;
}
