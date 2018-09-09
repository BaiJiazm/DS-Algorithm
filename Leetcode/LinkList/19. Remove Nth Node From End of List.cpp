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
		ListNode* removeNthFromEnd(ListNode* head, int n) {
			ListNode* ph=new ListNode(0);
			ph->next=head;
			ListNode* p1=ph, *p2=ph;
			for(int i=n; i>=0; --i) {
				p2=p2->next;
			}
			for(; p2; p2=p2->next) {
				p1=p1->next;
			}
			if(p1->next) {
				p2=p1->next;
				p1->next=p2->next;
				delete p2;
			}
			p1=ph->next;
			delete ph;
			return p1;
		}
};
