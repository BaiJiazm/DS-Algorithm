#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
struct TreeNode {
	ElemType data;
	struct TreeNode*left;
	struct TreeNode *right;
	int height;
};
int height(struct TreeNode *r)
{
	return r ? r->height : 0;
}
int max(int m1, int m2)
{
	return m1 > m2 ? m1 : m2;
}
int GetHeight(struct TreeNode *r)
{
	if (r == NULL)
		return 0;
	return max(GetHeight(r->left), GetHeight(r->right)) + 1;
}
struct TreeNode*insertAVLTree(struct TreeNode *root,ElemType e)
{
	if (root == NULL) {
		root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
		root->data = e;
		root->left = root->right = NULL;
		root->height = 1;
	}
	else {
		struct TreeNode * pLeft = root->left;
		struct TreeNode * pRight = root->right;
		if (e < root->data)
			root->left = insertAVLTree(root->left, e);
		else
			root->right = insertAVLTree(root->right, e);
		int leftHeight = height(pLeft) + 1;
		int rightHeight = height(pRight) + 1;

		root->height = leftHeight>rightHeight ? leftHeight : rightHeight;
		
		if (leftHeight - rightHeight>1) {
			if (pLeft->left&&height(pLeft->left) == rightHeight) {
				root->left = pLeft->right;
				pLeft->right = root;
				root->height = GetHeight(root);
				root = pLeft;
			}
			else {
				struct TreeNode *newRoot = pLeft->right;
				root->left = newRoot->right;
				newRoot->right = root;
				pLeft->right = newRoot->left;
				newRoot->left = pLeft;
				newRoot->height += 1;
				pLeft->height -= 1;
				root->height -= 2;
				/*newRoot->height = GetHeight(newRoot);
				pLeft->height = GetHeight(pLeft);
				root->height =GetHeight(root);*/
				root = newRoot;
			}
		}
		else if (rightHeight - leftHeight>1){
			if (pRight->right&&height(pRight->right) == leftHeight) {
				root->right = pRight->left;
				pRight->left = root;
				root->height =GetHeight(root);
				root = pRight;
			}
			else {
				struct TreeNode *newRoot = pRight->left;
				root->right = newRoot->left;
				newRoot->left = root;
				pRight->left = newRoot->right;
				newRoot->right= pRight;
				newRoot->height += 1;
				pRight->height -= 1;
				root->height -= 2;
				/*newRoot->height =GetHeight(newRoot);
				pRight->height =GetHeight(pRight);
				root->height = GetHeight(root);*/
				root = newRoot;
			}
		}
	}
	root->height = GetHeight(root);
	return root;
}

void preOrder(struct TreeNode *r)
{
	if (r)
	{
		printf("Öµ£º%d	¸ß¶È£º%d\n", r->data, r->height);
		preOrder(r->left);
		preOrder(r->right);
	}
}
int main()
{
	int N;
	TreeNode *T = NULL;
	scanf("%d", &N);
	int e;
	while (N--) {
		scanf("%d", &e);
		T = insertAVLTree(T, e);
		/*preOrder(T);
		printf("\n\n");*/
	}
	
	printf("%d", T->data);
	return 0;
}