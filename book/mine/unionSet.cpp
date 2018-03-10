/*���鼯һ�����ڶԶ�̬��ͨ�Ե��жϣ���ҪӦ�����ж�����Ԫ���Ƿ�ͬ���ϣ�
 *�Ƿ���ͨ����Ӻ��ѵ��жϡ��ж�ͼ�Ƿ���ͨ���Ƿ��л���
 *���鼯��Ϊ��Ȩ�Ͳ���Ȩ
 */

//����Ȩ���鼯���ϲ�ʱ�����С����Ϊfa����������ֱ������
void init(vector<int>&fa,int n) {
	for (int i=0; i<n; ++i)
		fa[i]=i;
}

int findFather(vector<int>&fa,int r) {
	if (fa[r]!=r)
		fa[r]=findFather(fa,fa[r]);
	return fa[r];
}

void Union (vector<int>&fa,int u,int v) {
	int ufa=findFather(fa,u);
	int vfa=findFather(fa,v);
	if (ufa<vfa)
		fa[v]=fa[vfa]=ufa;
	else
		fa[u]=fa[ufa]=vfa;
}

/*��Ȩ���鼯���ϲ�ʱҪ�����ȣ�
  ��Ȩ���鼯����ͨ���鼯�����������ڴ�Ȩ���鼯�ϲ����ǿ��������
ϵ�ĵ�ļ��ϣ�����ͨ�������е�һ����ֵ֪�����������������Ԫ�ص�
ֵ������һ�㲢�鼯�ϲ�����ͼ�������Ԫ������������ϡ���Ȩ���鼯�൱
�ڰѡ����ڡ��Ķ�����չ��һ�£���չΪ�й�ϵ�ļ��ϡ�
  ������rank[x]��¼x��x����Զ�����ȵĹ�ϵ�� ���ﶨ��rank[x]=0��ʾx��
x��������ͬ�ࡣrank[x]==1��ʾx��x�����ȡ�rank[x]==2��ʾx�����ȳ�x����
������������Ŀ���������ݵ�D��ϵ������(D-1)�Ϳ��Ա�ʾx��y�Ĺ�ϵ����
���Ϳ�������������ʽȥ�ƹ�ϵ�Ĺ�ʽ�ˡ�������f(x,father[x])��ʾrank[x]��ֵ��
*/
int fa[50005]= {0};
int rank[50005]= {0};
int n;

void initial() {
	for(int i=1; i<=n; i++) {
		fa[i]=i;
		rank[i]=0;
	}
}

int getfather(int x) {
	if(x==fa[x])  return x;
	int oldfa = fa[x];
	fa[x]=getfather(fa[x]);
	rank[x]=(rank[x]+rank[oldfa])%3;  //����������ʽ�ܿ�Ϳ��Կ�����
	return fa[x];
}

void unionset(int r,int x,int y) {
	int fx,fy;
	fx=getfather(x);
	fy=getfather(y);
	if(fx==fy) return;
	fa[fx]=fy;
	rank[fx]=(rank[y]+r-rank[x]+3)%3;
	// ����ͬ���������������ƹ�ʽ��������Ҫע����ǣ�����ֻ������fx��rankֵ����fx�Ķ��ӵ�rankֵ��û�и��»᲻�������⡣
	//��ʵ�����£���������ÿ������һ���������Ƕ���x��y������getfather�Ĳ�����x>n || y>n ����)�ĳ��⡣
	//��ִ��getfather�Ĳ���ʱ���ڻ��ݵĹ����оͻ��fx�Ķ��ӵ�rankֵ�������ˡ�
	return ;
}

int istrue(int d,int x,int y) {
	int fx,fy,r;
	if(x>n || y>n || ((x==y)&&(d==2)) )
		return 0;
	fx=getfather(x);
	fy=getfather(y);
	if(fx!=fy)  return 1;
	else {
		if(rank[x]==((d-1)+rank[y])%3) return 1;
		// �����ʽ�������������ƣ������ f(x,y) + f(y,father[y]����% 3 == f(x,father[x]) ������ȷ�ģ������Ǵ�ġ�
		//�����ʽ��������������ʾ�������ж���������ӷ��Բ���   x--->y + y---> fx(fy) �Ƿ����  x--->fx(fy)
		else  return 0;
	}
}

int main() {
	int k,i,x,y,d;
	int ans=0;
	scanf("%d%d",&n,&k);
	initial();
	for(i=1; i<=k; i++) {
		scanf("%d%d%d",&d,&x,&y);
		if( !istrue(d,x,y) )
			ans++;
		else
			unionset(d-1,x,y);
	}
	printf("%d\n",ans);
	return 0;
}
