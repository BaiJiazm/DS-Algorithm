/*并查集一般用于对动态连通性的判断，主要应用于判断两个元素是否同集合，
 *是否连通，间接好友的判断。判断图是否连通，是否有环。
 *并查集分为带权和不带权
 */

//不带权并查集，合并时将序号小的作为fa，大多数情况直接套用
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

/*带权并查集，合并时要处理秩！
  带权并查集和普通并查集最大的区别在于带权并查集合并的是可以推算关
系的点的集合（可以通过集合中的一个已知值推算这个集合中其他元素的
值）。而一般并查集合并的意图在于这个元素属于这个集合。带权并查集相当
于把“属于”的定义拓展了一下，拓展为有关系的集合。
  本题用rank[x]记录x与x的最远的祖先的关系。 这里定义rank[x]=0表示x与
x的祖先是同类。rank[x]==1表示x吃x的祖先。rank[x]==2表示x的祖先吃x；这
样定义后就与题目中输入数据的D联系起来，(D-1)就可以表示x与y的关系。这
样就可以用向量的形式去推关系的公式了。我们用f(x,father[x])表示rank[x]的值；
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
	rank[x]=(rank[x]+rank[oldfa])%3;  //用向量的形式很快就可以看出来
	return fa[x];
}

void unionset(int r,int x,int y) {
	int fx,fy;
	fx=getfather(x);
	fy=getfather(y);
	if(fx==fy) return;
	fa[fx]=fy;
	rank[fx]=(rank[y]+r-rank[x]+3)%3;
	// 这里同样可以用向量来推公式。另外需要注意的是，这里只更新了fx的rank值，而fx的儿子的rank值都没有更新会不会有问题。
	//其实不碍事，由于我们每次输入一组数据我们都对x和y进行了getfather的操作（x>n || y>n ……)的除外。
	//在执行getfather的操作时，在回溯的过程中就会把fx的儿子的rank值都更新了。
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
		// 这个公式可以用向量来推：如果（ f(x,y) + f(y,father[y]））% 3 == f(x,father[x]) 则是正确的，否则是错的。
		//这个形式可以用向量来表示，就是判断这个向量加法对不对   x--->y + y---> fx(fy) 是否等于  x--->fx(fy)
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
