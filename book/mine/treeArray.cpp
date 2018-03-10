/*��״�������ڲ�ѯ������λ��Ԫ�غͣ�ÿ��ֻ���޸�һ��Ԫ�ص�ֵ��������
 *һ���������״�����ܽ���������߶������ܽ������֮���С�
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

//��ȫ����ģ��
//ע��c��Ԫ��λ�ô�1��ʼ
int c[N];
int lowbit(int x) {
	return x & (-x);
}
void update(int x,int add) { 	//һά
	while(x<=n) {	//nΪԪ�ظ��� ����MAXN��ͬ��xΪλ��
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

void modify(int x,int y,int data) { //��ά
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
	for (int i = 1; i <= n; ++i) c[i] = 0;   //��ʼ����״����
	sort(node + 1, node + n + 1, cmp);   //����
	for (int i = 1; i <= n; ++i) reflect[node[i].pos] = i;   //��ɢ��
	long long ans = 0;
	for (int i = 1; i <= n; ++i) {
		update(reflect[i],1);
		ans += i - getsum(reflect[i]);	//����˼�����ܸ���-С�ڵ��ڵ�Ԫ�ظ���=������ĸ���
	}
	printf("%lld\n", ans);
	return 0;
}
