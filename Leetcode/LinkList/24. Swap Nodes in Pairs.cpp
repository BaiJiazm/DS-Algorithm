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
		ListNode* swapPairs(ListNode* head) {
			if(head==NULL||head->next==NULL)
				return head;
			ListNode *p1=head->next;
			head->next=swapPairs(p1->next);
			p1->next=head;
			return p1;
		}
};
