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
		ListNode* deleteDuplicates(ListNode* head) {
			ListNode* cur = head, *pt;
			while(cur) {
				while(cur->next && cur->val == cur->next->val) {
					pt=cur->next;
					cur->next=pt->next;
					delete pt;
				}
				cur = cur->next;
			}
			return head;
		}
};
