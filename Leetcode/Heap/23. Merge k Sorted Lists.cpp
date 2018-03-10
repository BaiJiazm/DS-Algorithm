#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//�ҵĶѷ���
struct cmp {
	//ע��priority_queue��Ԫ��Ϊָ��ʱ��cmp������д��
	bool operator ()(ListNode const *l1,ListNode const * l2) const {
		return l1->val>l2->val;
	}
};

class Solution {
	public:
		ListNode* mergeKLists(vector<ListNode*>& lists) {
			priority_queue<ListNode*,vector<ListNode*>,cmp>q;
			for(auto l:lists)
				if(l)
					q.push(l);
			ListNode *headList=NULL,*pTail=NULL;
			while(!q.empty()) {
				ListNode*qn=q.top();
				q.pop();
				if(!headList) {
					headList=qn;
					pTail=qn;
				} else {
					pTail->next=qn;
					pTail=qn;
				}
				if(qn->next)
					q.push(qn->next);
			}
			if(pTail)
				pTail->next=NULL;
			return headList;
		}
};

#include<typeinfo>
void testAuto() {
	int a[9];
	auto j = a;
	cout<<typeid(j).name()<<endl; // This will print int*

	auto& k = a;
	cout<<typeid(k).name()<<endl; // This will print int [9]
}

int main() {
	testAuto();
	vector<ListNode*>lists= {NULL,NULL};
	Solution s;
	s.mergeKLists(lists);
	return 0;
}

//�򵥵ı���vector�ϲ�����List����
class Solution {
	public:
		ListNode *mergeKLists(vector<ListNode *> &lists) {
			if(lists.empty()) {
				return nullptr;
			}
			while(lists.size() > 1) {
				lists.push_back(mergeTwoLists(lists[0], lists[1]));
				lists.erase(lists.begin());
				lists.erase(lists.begin());
			}
			return lists.front();
		}
		ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
			if(l1 == nullptr) {
				return l2;
			}
			if(l2 == nullptr) {
				return l1;
			}
			if(l1->val <= l2->val) {
				l1->next = mergeTwoLists(l1->next, l2);
				return l1;
			} else {
				l2->next = mergeTwoLists(l1, l2->next);
				return l2;
			}
		}
};
