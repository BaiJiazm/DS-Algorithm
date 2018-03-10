/*
链接：https://www.nowcoder.com/questionTerminal/0385945b7d834a99bc0010e67f892e38
来源：牛客网
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;

int n,m;
int direction[55][2];
int dcnt;
char ground[55][55];
int dis[55][55];

struct Point {
	int x,y;
	Point() {}
	Point(int _x,int _y):x(_x),y(_y) {}
	Point go(int idx) {
		return Point(x+direction[idx][0],y+direction[idx][1]);
	}
	bool isOK() {
		return x>=0&&y>=0&&x<n&&y<m&&ground[x][y]=='.';
	}
};

int main() {
	scanf("%d%d",&n,&m);
	for(int i=0; i<n; i++) {
		scanf("%s",ground[i]);
	}
	Point start;
	scanf("%d%d",&start.x,&start.y);
	scanf("%d",&dcnt);
	for(int i=0; i<dcnt; i++) {
		scanf("%d%d",&direction[i][0],&direction[i][1]);
	}
	fill(dis[0],dis[54]+55,INT_MAX);
	dis[start.x][start.y]=0;

	queue<Point> q;
	q.push(start);
	while(!q.empty()) {
		Point x=q.front();
		q.pop();
		for(int i=0; i<dcnt; ++i) {
			Point y=x.go(i);
			if(y.isOK()) {
				if(dis[y.x][y.y]>dis[x.x][x.y]+1) {
					dis[y.x][y.y]=dis[x.x][x.y]+1;
					q.push(y);
				}
			}
		}
	}

	int answer=0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(ground[i][j]=='.') answer=max(answer,dis[i][j]);
		}
	}
	printf("%d\n",answer==INT_MAX?-1:answer);
	return 0;
}
