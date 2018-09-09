/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
	public:
		RandomListNode *copyRandomList(RandomListNode *head) {
			RandomListNode *p1, *pt;
			for(p1=head; p1; p1=pt->next) {
				pt=new RandomListNode(p1->label);
				pt->next=p1->next;
				p1->next=pt;
			}

			for(p1=head; p1; p1=pt->next) {
				pt=p1->next;
				pt->random=p1->random?p1->random->next:NULL;
			}

			RandomListNode* newHead=NULL, *pn;
			for(p1=head; p1; p1=pt->next) {
				pt=p1->next;
				p1->next=pt->next;
				if(!newHead) {
					newHead=pt;
				} else {
					pn->next=pt;
				}
				pn=pt;
			}
			return newHead;
		}
};
