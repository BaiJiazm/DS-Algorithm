class Solution {
	public:
		int nextGreaterElement(int n) {
			string str=to_string(n);
			next_permutation(str.begin(),str.end());
			long long ans=stoll(str);
			return ans>INT_MAX||ans<=n ? -1:(int)ans;
		}
};
