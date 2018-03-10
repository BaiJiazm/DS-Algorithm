#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


class Solution {
	public:
		typedef unordered_map<string, int> ItemType;

		unordered_map<string, int>varIntMap;

		static bool myCompare(const pair<string, int>& p1, const pair<string, int>& p2) {
			string s1=p1.first, s2=p2.first;
			vector<string>v1=split(s1, "*");
			vector<string>v2=split(s2, "*");
			return v1.size()>v2.size() || v1.size()==v2.size()&& v1<v2;
		}

		vector<string> basicCalculatorIV(string expression, vector<string>& evalvars, vector<int>& evalints) {
			for (int i=0; i<evalvars.size(); ++i) {
				varIntMap[evalvars[i]]=evalints[i];
			}
			int pos=0;
			ItemType ret=solveOneItem(expression, pos);
			vector<pair<string, int>>res(ret.begin(), ret.end());
			sort(res.begin(), res.end(), myCompare);
			vector<string> ans;
			for (auto &a: res) {
				if(a.second!=0) {
					ans.push_back(to_string(a.second));
					if(a.first!="") {
						ans.back()+="*";
						ans.back()+=a.first;
					}
				}
			}
			return ans;
		}

		ItemType solveOneItem(const string& exp, int& pos) {
			vector<ItemType>operands;
			vector<char>operators= {'+'};
			const int expLen=exp.length();

			for (; ;) {
				if(exp[pos]=='(') {
					operands.push_back(solveOneItem(exp, ++pos));
					++pos;
				} else {
					string tstr;
					int pos2=exp.find_first_of(" )", pos);
					tstr=exp.substr(pos, pos2-pos);
					pos=pos2;
					ItemType tem;
					if(isdigit(tstr[0])) {
						tem[""]+=stoi(tstr);
					} else if(varIntMap.count(tstr)) {
						tem[""]+=varIntMap[tstr];
					} else {
						tem[tstr]=1;
					}
					operands.push_back(tem);
				}
				if(pos==-1||pos>=expLen||exp[pos]==')') {
					break;
				}
				operators.push_back(exp[++pos]);
				pos=pos+2;
			}
//			cout<<endl<<"begin calcu:"<<endl;
//			for (auto &a:operators) {
//				cout<<" |"<<a<<"| ";
//			}
//			cout<<endl;
//			for (auto &a:operands) {
//				cout<<" |";
//				for (auto&aa: a) {
//					cout<<" "<<aa.second<<aa.first<<" ";
//				}
//				cout<<"| "<<endl;
//			}
			return calcuItem(operands, operators);
		}

		ItemType calcuItem(vector<ItemType>& operands, vector<char>& operators) {
			ItemType ans;
			for (int i=operators.size()-1; i>=0; --i) {
				ItemType tem=operands[i];
				for(; operators[i]=='*'; --i) {
					tem=multiItem(operands[i-1], tem);
				}
				int sign= operators[i] =='+'? 1 : -1;
				for (auto& a:tem) {
					ans[a.first]+=a.second*sign;
				}
			}
//			cout<<endl<<"calcu ans:"<<endl;
//			for (auto &a:ans) {
//				cout<<" "<<a.second<<a.first<<" ";
//			}
//			cout<<endl;
			return ans;
		}

		ItemType multiItem(ItemType& leftOp, ItemType& rightOp) {
			ItemType ans;
			for(auto &al: leftOp) {
				for (auto &ar: rightOp) {
					string s1=al.first, s2=ar.first;
					ans[combine(s1, s2)]+=al.second*ar.second;
				}
			}
			return ans;
		}

		string combine(string& a, string& b) {
			if(a=="")
				return b;
			if(b=="")
				return a;
			vector<string>vstr=split(a, "*");
			for (auto &ab: split(b, "*")) {
				vstr.push_back(ab);
			}
			sort(vstr.begin(), vstr.end());
			string res;
			for (auto &avstr: vstr)
				res+=avstr+'*';
			res.pop_back();
			return res;
		}

		static vector<string> split(string &str, string sep) {
			vector<string>res;
			int pos1=0,pos2=0;
			for (; pos1<str.length()&&pos2!=string::npos; pos1=pos2+1) {
				pos2=str.find(sep, pos1);
				res.push_back(str.substr(pos1, pos2-pos1));
			}
			return res;
		}
};

int main() {
	Solution s;
	string expression = "((a - b) * (b - c) + (c - a)) * ((a - b) + (b - c) * (c - a))";
	vector<string>evalvars;
	vector<int>evalints;
	vector<string>ans=s.basicCalculatorIV(expression, evalvars, evalints);

	cout<<endl<<"ans"<<endl;
	for (auto &a: ans) {
		cout<<a<<" ";
	}
	return 0;
}
