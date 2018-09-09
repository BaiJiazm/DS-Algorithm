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
		ListNode* reverseBetween(ListNode* head, int m, int n) {
			if(head==NULL||head->next==NULL||m==n)
				return head;
			ListNode* ph=new ListNode(0);
			ph->next=head;
			ListNode* pl=ph, *pm, *pn, *pt;
			for(int i=1; i<m; ++i) {
				pl=pl->next;
			}
			pm=pl->next;
			pn=pm->next;
			for(int i=0; i<n-m; ++i) {
				pt=pn->next;
				pn->next=pl->next;
				pl->next=pn;
				pn=pt;
			}
			pm->next=pt;
			head=ph->next;
			delete ph;
			return head;
		}
};

class Solution {
	public:
		ListNode *reverseBetween(ListNode *head, int m, int n) {
			if(m==n)
				return head;
			n-=m;
			ListNode prehead(0);
			prehead.next=head;
			ListNode* pre=&prehead;
			while(--m)
				pre=pre->next;
			ListNode* pstart=pre->next;
			while(n--) {
				ListNode *p=pstart->next;
				pstart->next=p->next;
				p->next=pre->next;
				pre->next=p;
			}
			return prehead.next;
		}
};
