#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<stack>
using namespace std;

//void CrieDir(string& path)
//{
//	stack<int>pos;
//	string ans;
//	int i;
//	int pathLength = (int)path.length();
//
//	for (i = 0; i < pathLength; ++i) {
//		if (path[i] == '/') {
//			if (pos.empty() || pos.top() != ans.length()) {
//				ans += '/';
//				pos.push(ans.length());
//			}
//
//			if (i + 2 < pathLength&&path.substr(i + 1, 2) == "./")
//				i++;
//			else if (i + 3 < pathLength&&path.substr(i + 1, 3) == "../") {
//				if (pos.size() != 1) {
//					pos.pop();
//					while ((int)ans.length() > pos.top())
//						ans.erase(ans.end() - 1);
//				}
//				i += 2;
//			}
//		}
//		else
//			ans += path[i];
//	}
//
//	if (ans.length() == pos.top() && pos.top() != 1)
//		ans.erase(ans.end() - 1);
//
//	cout << ans << endl;
//	return;
//}

void CrieDir(string& path)
{
	string ans;
	int i;
	int pathLength = (int)path.length();

	for (i = 0; i < pathLength; ++i) {
		if (path[i] == '/') {
			if (ans.empty() || ans.back()!= '/')
				ans += '/';
			if (i + 2 < pathLength&&path.substr(i + 1, 2) == "./")
				i++;
			else if (i + 3 < pathLength&&path.substr(i + 1, 3) == "../") {
				if (ans.length() != 1) {
					ans.erase(ans.end() - 1);
					while (ans.back() != '/')
						ans.erase(ans.end() - 1);
				}
				i += 2;
			}
		}
		else
			ans += path[i];
	}
	
	if (ans.length() != 1 && ans.back()== '/')
		ans.erase(ans.end() - 1);

	cout << ans << endl;
	return;
}

int main()
{
	//freopen("test.txt", "r", stdin);
	int P;
	string curDir;
	string path;
	while (scanf("%d", &P) != EOF) {
		getchar();			//注意有一个换行符
		getline(cin,curDir);
		int i;
		for (i = P; i--;) {
			getline(cin,path);
			if (path[0] != '/')
				path = curDir + '/' + path;
			CrieDir(path);
		}
	}
	return 0;
}