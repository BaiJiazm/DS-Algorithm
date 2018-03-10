/*树状数组用于查询任意两位间元素和，每次只能修改一个元素的值，代码简洁
 *一般情况下树状数组能解决的问题线段树都能解决，反之不行。
 */
const int N = 500005;
struct Node {
	int val;
	int pos;
};
Node node[N];
int reflect[N], n;
bool cmp(const Node& a, const Node& b) {
	return a.val < b.val;
}

//完全功能模板
//注意c中元素位置从1开始
int c[N];
int lowbit(int x) {
	return x & (-x);
}
void update(int x,int add) { 	//一维
	while(x<=n) {	//n为元素个数 ，与MAXN不同，x为位置
		a[x]+=add;
		x+=lowbit(x);
	}
}
int getsum(int x) {
	int sum = 0;
	while (x > 0) {
		sum += c[x];
		x -= lowbit(x);
	}
	return sum;
}

void modify(int x,int y,int data) { //二维
	for(int i=x; i<MAXN; i+=lowbit(i))
		for(int j=y; j<MAXN; j+=lowbit(j))
			a[i][j]+=data;
}
int get_sum(int x,int y) {
	int res=0;
	for(int i=x; i>0; i-=lowbit(i))
		for(int j=y; j>0; j-=lowbit(j))
			res+=a[i][j];
	return res;
}

int main() {
	for (int i = 1; i <= n; ++i) c[i] = 0;   //初始化树状数组
	sort(node + 1, node + n + 1, cmp);   //排序
	for (int i = 1; i <= n; ++i) reflect[node[i].pos] = i;   //离散化
	long long ans = 0;
	for (int i = 1; i <= n; ++i) {
		update(reflect[i],1);
		ans += i - getsum(reflect[i]);	//反面思考，总个数-小于等于的元素个数=比他大的个数
	}
	printf("%lld\n", ans);
	return 0;
}
