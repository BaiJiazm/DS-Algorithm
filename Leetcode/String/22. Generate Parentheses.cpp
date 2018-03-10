#include<iostream>
#include<string>
#include<vector>
using namespace std;
//�Լ�д�ķǵݹ��㷨��n<=3ʱ��ȷ�������Ǵ���Ĵ𰸡�û�о����ϸ��֤������������
//�������	( (()) () )	��������Σ�
class Solution1 {
	public:
		vector<string> generateParenthesis(int n) {
			vector<vector<string> >strs(n+2);
			strs[1].push_back("()");
			for (int i=1; i<n; ++i)
				for (int j=0; j<strs[i].size(); ++j) {
					int pos=0;
					while(1) {
						strs[i+1].push_back('('+strs[i][j].substr(0,pos)+')'+strs[i][j].substr(pos,strs[i][j].length()-pos));
						pos=strs[i][j].find_first_not_of(')',pos);
						if (pos==string::npos)
							break;
						pos=strs[i][j].find_first_of(')',pos);
					}
				}
			return strs[n];
		}
};

//�����������������Ŀ��һ���ǿ��ǵݹ�+����
//�ݹ������Ŀ���ݹ�д��

class Solution {
	public:
		vector<string> generateParenthesis(int n) {
			vector<string> res;
			addingpar(res, "", n, 0);
			return res;
		}
		void addingpar(vector<string> &v, string str, int n, int m) {
			if(n==0 && m==0) {
				v.push_back(str);
				cout<<str<<endl;
				return;
			}
			//˳����Խ���
			if(n > 0) {
				addingpar(v, str+"(", n-1, m+1);
			}
			if(m > 0) {
				addingpar(v, str+")", n, m-1);
			}
		}
};

int main() {
	Solution s;
	vector<string>strs=s.generateParenthesis(4);
	return 0;
}
