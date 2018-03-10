#include <iostream>
#include <cstring>
using namespace std;
#define inf 100000000
int state[5][5],chess,xi,xj;
char ch;
int minfind(int,int,int);
int maxfind(int,int,int);
bool over(int x,int y) {
	bool flag = false;
	int row[5],col[5];
	memset(row,0,sizeof(row));
	memset(col,0,sizeof(col));
	for (int i=0; i<4; i++)
		for (int j=0; j<4; j++) {
			if (state[i][j]=='x') {
				row[i]++;
				col[j]++;
			}
			if (state[i][j]=='o') {
				row[i]--;
				col[j]--;
			}
		}
	if (row[x]==-4 || row[x]==4 || col[y]==-4 || col[y]==4)
		flag = true;
	int tot1 = 0, tot2 = 0;
	for (int i=0; i<4; i++) {
		if (state[i][i]=='x') tot1++;
		if (state[i][3-i]=='x') tot2++;
		if (state[i][i]=='o') tot1--;
		if (state[i][3-i]=='o') tot2--;
	}
	if ((tot1==4 || tot1==-4) && x==y) flag = true;
	if ((tot2==4 || tot2==-4) && x==3-y) flag = true;
	return flag;
}
int maxfind(int x,int y,int mini) {
	int tmp, maxi = -inf;
	if (over(x,y)) return maxi;
	if (chess==16) return 0;
	for (int i=0; i<4; i++)
		for (int j=0; j<4; j++)
			if (state[i][j]=='.') {
				state[i][j]='x';
				chess++;
				tmp = minfind(i,j,maxi);
				chess--;
				state[i][j]='.';
				maxi = max(maxi, tmp);
				if (maxi>=mini) return maxi;
			}
	return maxi;
}
int minfind(int x,int y,int maxi) {
	int tmp, mini = inf;
	if (over(x,y)) return mini;
	if (chess==16) return 0;
	for (int i=0; i<4; i++)
		for (int j=0; j<4; j++)
			if (state[i][j]=='.') {
				state[i][j]='o';
				chess++;
				tmp = maxfind(i,j,mini);
				chess--;
				state[i][j]='.';
				mini = min(mini, tmp);
				if (mini<=maxi) return mini;
			}
	return mini;
}
bool tryit() {
	int tmp, maxi = -inf;
	for (int i=0; i<4; i++)
		for (int j=0; j<4; j++)
			if (state[i][j]=='.') {
				state[i][j] = 'x';
				chess++;
				tmp = minfind(i,j,maxi);
				chess--;
				state[i][j] = '.';
				if (tmp>=maxi) {
					maxi = tmp;
					xi = i;
					xj = j;
				}
				if (maxi==inf) return true;
			}
	return false;
}
int main() {
	while (scanf("%c",&ch)) {
		if (ch=='$') break;
		scanf("%c",&ch);
		chess = -4;
		for (int i=0; i<4; i++)
			for (int j=0; j<5; j++) {
				scanf("%c",&state[i][j]);
				chess += state[i][j]!='.';
			}
		if (chess<=4) { //Ç¿Á¦¼ôÖ¦
			printf("#####\n");
			continue;
		}
		if (tryit()) printf("(%d,%d)\n",xi,xj);
		else printf("#####\n");
	}
	return 0;
}
