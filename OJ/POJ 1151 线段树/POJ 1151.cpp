#include <algorithm>
#include <iostream>
using namespace std;

#define L(x) ( x << 1 )
#define R(x) ( x << 1 | 1 )

double y[1000];

struct Line {
	double x, y1, y2;
	int flag;
} line[300];

struct Node {
	int l, r, cover;
	double lf, rf, len;
} node[1000];

bool cmp ( Line a, Line b ) {
	return a.x < b.x;
}

void length ( int u ) {
	if ( node[u].cover > 0 ) {
		node[u].len = node[u].rf - node[u].lf;
		return;
	} else if ( node[u].l + 1 == node[u].r )
		node[u].len = 0; /* 叶子节点，len 为 0 */
	else
		node[u].len = node[L(u)].len + node[R(u)].len;
}

void build ( int u, int l, int r ) {
	node[u].l = l;
	node[u].r = r;
	node[u].lf = y[l];
	node[u].rf = y[r];
	node[u].len = node[u].cover = 0;
	if ( l + 1 == r ) return;
	int mid = ( l + r ) / 2;
	build ( L(u), l, mid );
	build ( R(u), mid, r );
}

void update ( int u, Line e ) {
	if ( e.y1 == node[u].lf && e.y2 == node[u].rf ) {
		node[u].cover += e.flag;
		length ( u );
		return;
	}
	if ( e.y1 >= node[R(u)].lf )
		update ( R(u), e );
	else if ( e.y2 <= node[L(u)].rf )
		update ( L(u), e );
	else {
		Line temp = e;
		temp.y2 = node[L(u)].rf;
		update ( L(u), temp );
		temp = e;
		temp.y1 = node[R(u)].lf;
		update ( R(u), temp );
	}
	length ( u );
}

int main() {
	//freopen("a.txt","r",stdin);
	int n, t, i, Case = 0;
	double  x1, y1, x2, y2, ans;
	while ( scanf("%d",&n) && n ) {
		for ( i = t = 1; i <= n; i++, t++ ) {
			scanf("%lf%lf%lf%lf",&x1, &y1, &x2, &y2 );
			line[t].x = x1;
			line[t].y1 = y1;
			line[t].y2 = y2;
			line[t].flag = 1;
			y[t] = y1;
			t++;
			line[t].x = x2;
			line[t].y1 = y1;
			line[t].y2 = y2;
			line[t].flag = -1;
			y[t] = y2;
		}

		sort ( line + 1, line + t, cmp );
		sort ( y + 1, y + t );
		build ( 1, 1, t-1 );
		update ( 1, line[1] );

		ans = 0;
		for ( i = 2; i < t; i++ ) {
			ans += node[1].len * ( line[i].x - line[i-1].x );
			update ( 1, line[i] );
		}
		printf ( "Test case #%d\n", ++Case );
		printf ( "Total explored area: %.2lf\n\n", ans );
	}
	return 0;
}
