#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define NMAX 40

struct node {
	int val;
	node*left;
	node*right;
};
int level[NMAX];
int inOrder[NMAX];
int pos[NMAX];

void findPos(node*&r,int i) {
	int inval=level[i];
	if (!r) {
		r=new node;
		*r= (node){inval,NULL,NULL};
		return ;
	}
	if (pos[inval]<pos[r->val])
		findPos(r->left,i);
	else
		findPos(r->right,i);
}
void preOrder(node*r,int &i) {
	if (!r)
		return ;
	i++?printf(" %d",r->val):printf("%d",r->val);
	preOrder(r->left,i);
	preOrder(r->right,i);
}
void postOrder(node*r,int &i) {
	if (!r)
		return ;
	postOrder(r->left,i);
	postOrder(r->right,i);
	i++?printf(" %d",r->val):printf("%d",r->val);
}

int main() {
	int N;
	while(~scanf("%d",&N)) {
		memset(level,0,sizeof (level));
		memset(inOrder,0,sizeof (inOrder));
		int i;
		for (i=1; i<=N; ++i)
			scanf("%d",level+i);
		for (i=1; i<=N; ++i) {
			scanf("%d",inOrder+i);
			pos[inOrder[i]]=i;
		}
		node *root=NULL;
		for (i=1; i<=N; ++i)
			findPos(root,i);
		int count=0;
		preOrder(root,count);
		printf("\n");
		count=0;
		postOrder(root,count);
		printf("\n");
	}
	return 0;
}
