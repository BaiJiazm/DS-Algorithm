class Solution {
	public:
		bool isValid(string s) {
			string left="({[";
			string right=")}]";
			stack<char>stk;
			for (int i=0; i<s.length(); ++i)
				if (left.find(s[i])!=-1)
					stk.push(s[i]);
				else if (stk.empty()||left.find(stk.top())^right.find(s[i]))
					return false;
				else
					stk.pop();
			return stk.empty();
		}
};
