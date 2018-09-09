//非递归解法 
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
		ListNode* reverseKGroup(ListNode* head, int k) {
			ListNode* newHead=NULL, *newLast=NULL;
			ListNode* kHead, *nextKHead;
			int i;
			while(head) {
				nextKHead=head;
				for(i=0; i<k&&nextKHead; ++i) {
					nextKHead=nextKHead->next;
				}
				if(i<k) {
					if(newLast) {
						newLast->next=head;
					} else {
						newHead=head;
					}
					return newHead;
				}
				ListNode* p1=head, *p2;
				kHead=NULL;
				for(i=0; i<k; ++i) {
					p2=p1->next;
					p1->next=kHead;
					kHead=p1;
					p1=p2;
				}
				head->next=NULL;
				if(newLast==NULL) {
					newHead=kHead;
				} else {
					newLast->next=kHead;
				}
				newLast=head;
				head=nextKHead;
			}
			return newHead;
		}
};

//递归解法
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
		ListNode* reverseKGroup(ListNode* head, int k) {
			if(head == NULL || head->next == NULL || k < 2) return head;
			ListNode *p, *q, *t;
			p = head;
			int tmp = k;
			while (--tmp && head != NULL) {
				head = head->next;
			}
			if (head == NULL) return p;
			q = reverseKGroup(head->next, k);
			head->next = NULL;
			while (p != NULL) {
				t = p->next;
				p->next = q;
				q = p;
				p = t;
			}
			return head;
		}
};
