//我的递归写法
const string charmap[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
class Solution {
	public:
		vector<string> letterCombinations(string digits) {
			if(digits.empty())
				return {};
			vector<string>res;
			string path;
			combin(res,path,digits,0);
			return res;
		}
		void combin(vector<string>&res,string &path,const string &digits,int index) {
			if(index==digits.length()) {
				res.push_back(path);
				return ;
			}
			for(auto &a:charmap[digits[index]-'0']) {
				path.push_back(a);
				combin(res,path,digits,index+1);
				path.pop_back();
			}
		}
};


//非递归迭代写法
class Solution {
	public:
		vector<string> letterCombinations(string digits) {
			if(digits.empty())
				return {};
			vector<string> res;
			string charmap[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
			res.push_back("");
			for (int i = 0; i < digits.size(); i++) {
				vector<string> tempres;
				string chars = charmap[digits[i] - '0'];
				for (int c = 0; c < chars.size(); c++)
					for (int j = 0; j < res.size(); j++)
						tempres.push_back(res[j]+chars[c]);
				res = tempres;
			}
			return res;
		}
};
