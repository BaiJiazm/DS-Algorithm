//今日头条面试手写代码就是此题，当时竟然写的不好，sad,今天一遍过。
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
	public:
		void connect(TreeLinkNode *root) {
			if(root) {
				TreeLinkNode* nextRoot=NULL, *nextPre=NULL;
				for(TreeLinkNode* p=root; p; p=p->next) {
					if(p->left) {
						if(!nextRoot)
							nextRoot=p->left;
						if(!nextPre)
							nextPre=p->left;
						else
							nextPre->next=p->left, nextPre=p->left;
					}
					if(p->right) {
						if(!nextRoot)
							nextRoot=p->right;
						if(!nextPre)
							nextPre=p->right;
						else
							nextPre->next=p->right, nextPre=p->right;
					}
				}
				connect(nextRoot);
			}
		}
};

class Solution {
	public:
		void connect(TreeLinkNode *root) {
			TreeLinkNode *now, *tail, *head;

			now = root;
			head = tail = NULL;
			while(now) {
				if (now->left)
					if (tail) tail = tail->next =now->left;
					else head = tail = now->left;
				if (now->right)
					if (tail) tail = tail->next =now->right;
					else head = tail = now->right;
				if(!(now = now->next)) {
					now = head;
					head = tail=NULL;
				}
			}
		}
};
