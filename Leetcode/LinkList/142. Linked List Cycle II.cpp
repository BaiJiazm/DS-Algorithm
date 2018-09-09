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
		ListNode *detectCycle(ListNode *head) {
			ListNode* p1=head, *p2=head;
			for(; p2&&p2->next;) {
				p1=p1->next;
				p2=p2->next->next;
				if(p1==p2) {
					p1=head;
					while(p1!=p2) {
						p1=p1->next;
						p2=p2->next;
					}
					return p1;
				}
			}
			return NULL;
		}
};
