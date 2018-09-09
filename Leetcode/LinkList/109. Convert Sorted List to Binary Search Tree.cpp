/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
	public:
		TreeNode* sortedListToBST(ListNode* head) {
			if(head==NULL)
				return NULL;
			if(head->next==NULL) {
				return new TreeNode(head->val);
			}
			ListNode* p1=head, *p2=head->next->next;
			while(p2&&p2->next) {
				p1=p1->next;
				p2=p2->next->next;
			}
			p2=p1->next;
			p1->next=NULL;
			TreeNode* root=new TreeNode(p2->val);
			root->left=sortedListToBST(head);
			root->right=sortedListToBST(p2->next);
			return root;
		}
};

class Solution {
	public:
		ListNode *list;
		int count(ListNode *node) {
			int size = 0;
			while (node) {
				++size;
				node = node->next;
			}
			return size;
		}

		TreeNode *generate(int n) {
			if (n == 0)
				return NULL;
			TreeNode *node = new TreeNode(0);
			node->left = generate(n / 2);
			node->val = list->val;
			list = list->next;
			node->right = generate(n - n / 2 - 1);
			return node;
		}

		TreeNode *sortedListToBST(ListNode *head) {
			this->list = head;
			return generate(count(head));
		}
};
