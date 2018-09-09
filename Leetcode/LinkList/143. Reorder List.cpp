#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
		void reorderList(ListNode* head) {
			if(head==NULL||head->next==NULL)
				return ;
			ListNode* p1, *p2, *pt;
			ListNode preHead(0);
			preHead.next=head;
			for(p1=&preHead, p2=&preHead; p2&&p2->next; ) {
				p1=p1->next;
				p2=p2->next->next;
			}

			for(pt=p1->next; p2=pt->next; ) {
				pt->next=p2->next;
				p2->next=p1->next;
				p1->next=p2;
			}

			p2=p1->next;
			p1->next=NULL;
			pt=&preHead;
			for(p1=head; p1&&p2; ) {
				pt->next=p1;
				p1=p1->next;
				pt->next->next=p2;
				pt=p2;
				p2=p2->next;
			}
			if(p1)
				pt->next=p1;

			return ;
		}
};

int main() {
	vector<int>v= {1,2,3,4};
	ListNode head(0), *p=&head;
	for(auto &a:v) {
		p->next=new ListNode(a);
		p=p->next;
	}
	p->next=NULL;
	Solution s;
	s.reorderList(head.next);
	for(p=head.next; p; p=p->next) {
		cout<<p->val<<" ";
	}
	return 0;
}
