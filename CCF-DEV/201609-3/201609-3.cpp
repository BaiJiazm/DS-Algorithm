#include<iostream>
using namespace std;

struct node {
	int attack;
	int health;
	struct node *next;
};

void init(struct node *&pHead) {
	pHead=new node;
	pHead->attack=0;
	pHead->next=new node;
	*(pHead->next)= {0,30,NULL};
	return ;
}

void add(struct node *pHead,int pos,int atk,int hth) {
	struct node*p=pHead;
	struct node*q=new node;
	*q= {atk,hth,NULL};

	int i;
	for (i=1; i<=pos; ++i) {
		p=p->next;
	}
	q->next=p->next;
	p->next=q;

	pHead->attack++;
}

void attacking(node *pa,node*pd,int numA,int numD) {
	node *qa=pa;
	node *qd=pd;
	node *temq;

	int i,j;
	for (i=0; i<numA; ++i)
		qa=qa->next;
	for (i=0; i<numD; ++i)
		qd=qd->next;
	int ha=(qa->next->health-=qd->next->attack);
	int hb=(qd->next->health-=qa->next->attack);

	if (numA&&ha<=0) {
		temq=qa->next;
		qa->next=temq->next;
		delete temq;
		pa->attack--;
	}

	if (numD&&hb<=0) {
		temq=qd->next;
		qd->next=temq->next;
		delete temq;
		pd->attack--;
	}
}

void outPut(node*pHead) {
	printf("%d\n",pHead->next->health);
	node *q=pHead->next->next;
	int i=pHead->attack;
	printf("%d",i);
	for (int j=0; j<i; ++j) {
		printf(" %d",q->health);
		q=q->next;
	}
	printf("\n");
}

int main() {
	int n;
	while(scanf("%d",&n)!=EOF) {
		node *pFirst,*pSecond,*pCur;
		init(pFirst);
		init(pSecond);
		pCur=pFirst;

		int i;
		string action;
		int pos,health,attack;
		int atker,defer;
		for (i=0; i<n; ++i) {
			cin>>action;
			if (action[0]=='s') {
				scanf("%d %d %d",&pos,&attack,&health);
				add(pCur,pos,attack,health);
			} else if (action[0]=='a') {
				scanf("%d %d",&atker,&defer);
				if (pCur==pFirst)
					attacking(pFirst,pSecond,atker,defer);
				else
					attacking(pSecond,pFirst,atker,defer);
			} else
				pCur=pCur==pFirst?pSecond:pFirst;
		}

		int h1=pFirst->next->health;
		int h2=pSecond->next->health;
		if (h2<=0)
			printf("1\n");
		else if (h1<=0)
			printf("-1\n");
		else
			printf("0\n");
		outPut(pFirst);
		outPut(pSecond);
	}

	return 0;
}
