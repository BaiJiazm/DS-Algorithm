#include <iostream>
using namespace std;

typedef int TreePtr;
typedef char TreeElemType;
const int null = -1;
const int MAXLEN = 10;
struct TreeNode
{
	TreeElemType data;
	TreePtr l;
	TreePtr r;
};
TreeNode Tree1[MAXLEN];
TreeNode Tree2[MAXLEN];

int BuildTree(TreeNode *t)
{
	int n, i, j;
	char  l, r;
	int root = null;
	int b[MAXLEN];
	for (i = 0; i < MAXLEN; i++)
		b[i] = 0;
	cin >> n;
	for (j = 0; j < n; j++)
	{
		cin >> t[j].data >> l >> r;
		t[j].l = l == '-' ? null : l - '0';
		t[j].r = r == '-' ? null : r - '0';
		if (l != '-')
			b[l - '0'] = 1;
		if (r != '-')
			b[r - '0'] = 1;
	}
	for (i = 0; i < n; i++)
		if (!b[i])
			root = i;
	return root;
}
bool IsSameTree(int r1, int r2)
{
	if (r1 == null&&r2 == null)
		return 1;
	if (r1 == null&&r2 != null || r1 != null&&r2 == null)
		return 0;
	if (Tree1[r1].data != Tree2[r2].data)
		return 0;
	return (IsSameTree(Tree1[r1].l, Tree2[r2].l) && IsSameTree(Tree1[r1].r, Tree2[r2].r)) + (IsSameTree(Tree1[r1].l, Tree2[r2].r) && IsSameTree(Tree1[r1].r, Tree2[r2].l));
}

int main()
{
	int r1, r2;
	r1 = BuildTree(Tree1);
	r2 = BuildTree(Tree2);
	if (IsSameTree(r1, r2))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}