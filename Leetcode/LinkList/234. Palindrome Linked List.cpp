/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
	public:
		ListNode* temp;
		bool isPalindrome(ListNode* head) {
			temp = head;
			return check(head);
		}

		bool check(ListNode* p) {
			if (NULL == p) return true;
			bool isPal = check(p->next) & (temp->val == p->val);
			temp = temp->next;
			return isPal;
		}
};
