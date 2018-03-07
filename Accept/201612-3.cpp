#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;

#define PMAX 100
#define RMAX 100
#define UMAX 100

int cm[PMAX+1];
map<string, int>p;

map<int, int>rc[RMAX+1];
map<string, int>r;

vector<int>ur[UMAX+1];
map<string, int>u;

int main()
{
	int P, R, U, q;

	while (scanf("%d", &P) != EOF) {
		int i;
		string str;
		std::size_t pos;

		for (i = 1; i <= P; ++i) {
			cin >> str;
			pos = str.find(':');
			if (pos != string::npos) {
				p[str.substr(0, pos)] = i;
				cm[i] = str[pos + 1] - '0';
			}
			else {
				p[str] = i;
				cm[i] = -1;
			}
		}

		scanf("%d", &R);
		int s;
		string role;

		for (i = 1; i <= R; ++i) {
			cin >> role >> s;
			r[role] = i;
			while (s--) {
				cin >> str;
				pos = str.find(':');

				if (pos != string::npos) {
					map<int, int>::iterator rcIt = rc[i].find(p[str.substr(0, pos)]);
					if (rcIt == rc[i].end())
						rc[i][p[str.substr(0, pos)]] = str[pos + 1] - '0';
					else if (str[pos + 1] - '0' > rcIt->second)
						rcIt->second = str[pos + 1] - '0';
				}
				else
					rc[i][p[str]] = -1;
			}
		}

		scanf("%d", &U);
		string user;

		for (i = 1; i <= U; ++i) {
			cin >> user >> s;
			u[user] = i;
			while (s--) {
				cin >> role;
				ur[i].push_back(r[role]);
			}
		}

		scanf("%d", &q);
		int useri, ci, level;

		for (i = 0; i < q; ++i) {
			cin >> user >> str;
			useri = u[user];

			pos = str.find(':');
			if (pos != string::npos) {
				ci = p[str.substr(0, pos)];
				level = str[pos + 1] - '0';
			}
			else {
				ci = p[str];
				level = -1;
			}

			if (!useri || !ci) {
				printf("false\n");
				continue;
			}

			vector<int>::iterator pur;
			map<int, int>::iterator prc;
			int flag = -2;

			for (pur = ur[useri].begin(); pur < ur[useri].end(); ++pur) {
				prc = rc[*pur].find(ci);
				if (prc != rc[*pur].end()) {
					if (level == -1) {
						if (cm[prc->first] == -1) {
							flag = -1;
							break;
						}
						else if (flag < prc->second)
							flag = prc->second;
					}
					else if (prc->second >= level) {
						flag = -1;
						break;
					}
				}
			}
			flag == -2 ? printf("false\n") : flag == -1 ? printf("true\n") : printf("%d\n", flag);
		}
	}
	return 0;
}