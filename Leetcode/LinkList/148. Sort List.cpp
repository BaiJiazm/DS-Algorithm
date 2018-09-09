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
		ListNode* sortList(ListNode* head) {
			if(head==NULL||head->next==NULL)
				return head;
			ListNode* p1, *p2;
			ListNode H(0);
			H.next=head;
			for(p1=p2=&H; p2&&p2->next; ) {
				p1=p1->next;
				p2=p2->next->next;
			}
			p2=p1->next;
			p1->next=NULL;
			p1=sortList(head);
			p2=sortList(p2);

			ListNode* pt=&H;
			while(p1&&p2) {
				if(p1->val<p2->val) {
					pt->next=p1;
					pt=p1;
					p1=p1->next;
				} else {
					pt->next=p2;
					pt=p2;
					p2=p2->next;
				}
			}
			if(p1)
				pt->next=p1;
			if(p2)
				pt->next=p2;
			return H.next;
		}
};

class Solution {
	public:
		ListNode* sortList(ListNode* head) {
			if (head == NULL || head->next == NULL)
				return head;

			ListNode* slow = head;
			ListNode* fast = head->next;

			while (fast != NULL && fast->next != NULL) {
				slow = slow->next;
				fast = fast->next->next;
			}
			//divide the list into two parts
			fast = slow->next;
			slow->next = NULL;

			return merge(sortList(head), sortList(fast));
		}

		ListNode* merge(ListNode* l1, ListNode* l2) {
			ListNode dump(0);
			ListNode* cur = &dump;

			while (l1 != NULL && l2 != NULL) {
				if (l1->val < l2->val) {
					cur->next = l1;
					l1 = l1->next;
				} else {
					cur->next = l2;
					l2 = l2->next;
				}

				cur = cur->next;
			}

			if (l1 != NULL)
				cur->next = l1;
			else
				cur->next = l2;

			return dump.next;
		}
};
