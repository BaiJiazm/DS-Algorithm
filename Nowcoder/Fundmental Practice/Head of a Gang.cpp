#include <iostream>  
#include <vector>  
#include <map>  
#include <set>  
#include <string>  
#include <algorithm>  
using namespace std;

typedef struct Node
{
	int weight, parent;
}Node;
typedef struct Call
{
	string a, b;
	int t;
}Call;
typedef struct Gang
{
	int head, num, sum, maxw;
	Gang() { head = -1; num = 0; sum = 0; maxw = -1; }
};
vector<Node> p;//disjoint set  
vector<Call> call;
map<string, int> name2id;
map<int, string> id2name;
set<string> name;
int n, k;
int realn;//number of distinct node  
void InitSet()
{
	p.resize(realn);
	for (int i = 0; i < realn; ++i)
	{
		p[i].parent = i; p[i].weight = 0;
	}
}
void CompressSet(int top, int x)
{
	if (top != p[x].parent)
	{
		CompressSet(top, p[x].parent);
		p[x].parent = top;
	}
}
int FindSet(int x)
{
	if (x != p[x].parent)
	{
		int top = FindSet(p[x].parent);
		CompressSet(top, x);
	}
	return p[x].parent;
}
void UnionSet(int x, int y)
{
	int a = FindSet(x);
	int b = FindSet(y);
	p[a].parent = b;
}
int main()
{
	while (scanf("%d%d", &n, &k) != EOF)
	{
		call.resize(n);
		name.clear();
		for (int i = 0; i < n; ++i)
		{
			cin >> call[i].a; cin >> call[i].b; cin >> call[i].t;
			name.insert(call[i].a); name.insert(call[i].b);
		}
		//get the person number  
		realn = name.size();
		name2id.clear();
		id2name.clear();
		set<string>::iterator it1;
		int id = 0;
		for (it1 = name.begin(); it1 != name.end(); it1++, ++id)
			name2id[*it1] = id, id2name[id] = *it1;
		//build disjoint set  
		InitSet();
		for (int i = 0; i < call.size(); ++i)
		{
			int u = name2id[call[i].a]; int v = name2id[call[i].b]; int t = call[i].t;
			//printf("%d %d %d\n", u, v, t);  
			p[u].weight += t; p[v].weight += t;
			UnionSet(u, v);
		}
		//collect all set  
		map<int, Gang> allSet;//father and weight of set  
		map<int, Gang>::iterator it;
		for (int i = 0; i < realn; ++i)
		{
			int top = FindSet(i);
			it = allSet.find(top);
			if (it != allSet.end())
			{
				allSet[top].sum += p[i].weight;
				allSet[top].num++;
				if (p[i].weight > allSet[top].maxw)
				{
					allSet[top].head = i;
					allSet[top].maxw = p[i].weight;
				}

			}
			else
			{
				Gang tmp;
				tmp.head = i; tmp.maxw = p[i].weight;
				tmp.num = 1;  tmp.sum = p[i].weight;
				allSet[top] = tmp;
			}
		}
		//threthold gang  
		std::vector<Gang> gang;
		for (it = allSet.begin(); it != allSet.end(); it++)
			if (it->second.sum > k * 2 && it->second.num > 2)
				gang.push_back(it->second);
		//output  
		vector<pair<string, int>> head;
		for (int i = 0; i < gang.size(); ++i)
			head.push_back(make_pair(id2name[gang[i].head], gang[i].num));
		sort(head.begin(), head.end());
		printf("%d\n", head.size());
		for (int i = 0; i < head.size(); ++i)
			cout << head[i].first << " " << head[i].second << endl;
	}
	return 0;
}