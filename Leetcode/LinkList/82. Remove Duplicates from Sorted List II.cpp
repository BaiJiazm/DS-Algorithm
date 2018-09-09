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
			ListNode* ph=new ListNode(0);
			ListNode* last=ph, *cur, *next;
			for(cur=head; cur; ) {
				ListNode* next=cur->next;
				if(next==NULL||cur->val!=next->val) {
					last->next=cur;
					last=cur;
					cur=next;
					continue;
				}
				int val=cur->val;
				while(cur&&cur->val==val) {
					next=cur->next;
					delete cur;
					cur=next;
				}
			}
			last->next=NULL;
			head=ph->next;
			delete ph;
			return head;
		}
};

class Solution {
	public:
		ListNode *deleteDuplicates(ListNode *head) {
			ListNode **runner = &head;

			if(!head || !head->next)
				return head;

			while(*runner) {
				if((*runner)->next && (*runner)->next->val == (*runner)->val) {
					ListNode *temp = *runner;
					while(temp && (*runner)->val == temp->val)
						temp = temp->next;

					*runner = temp;
				} else
					runner = &((*runner)->next);
			}

			return head;
		}
};
