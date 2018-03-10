#include <iostream>
#include <deque>
#include <queue>
using namespace std;

#define MARK 0xffffff

deque<int>rs;
queue<int>cmp;
queue<int>temrs;
queue<int >emptyq;
int Np;
int Ng;

int *w;
int *n;

int main()
{
	cin >> Np >> Ng;

	w = new int[Np];
	n = new int[Np];

	int i;
	for (i = 0; i < Np; ++i)
		cin >> w[i];
	int t;
	for (i = 0; i < Np; ++i)
	{
		cin >> t;
		temrs.push(t);
	}
	
	int max;
	while (temrs.size() != 1)
	{
		rs.push_front(MARK);
		cmp = temrs;
		temrs = emptyq;
		while (!cmp.empty())
		{
			i = 0;
			max = cmp.front();
			cmp.pop();
			for (++i; i < Ng&&!cmp.empty(); ++i)
			{
				t = cmp.front();
				cmp.pop();
				if (w[t] > w[max])
				{
					rs.push_front(max);
					max = t;
				}
				else
					rs.push_front(t);
			}
			temrs.push(max);
		}
	}
	rs.push_front(MARK);
	rs.push_front(max);

	int j;
	for (i = 1,j=1; !rs.empty();)
	{  
		t = rs.front();
		rs.pop_front();
		if (t == MARK)
			i=j;
		else
		{
			n[t] = i;
			++j;
		}
	}

	for (i = 0; i < Np; ++i)
		if (i == 0)
			cout << n[i];
		else
			cout << " " << n[i];

	return 0;
}