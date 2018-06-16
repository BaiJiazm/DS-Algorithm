class Solution {
	public:
		string longestPalindrome(string s) {
			// Dynamic programming?
			vector<vector<bool>> isPalindrome = vector<vector<bool>>(s.size(), vector<bool>(s.size(), false));
			string result;

			// Initialize if palindrome string is size 1
			for( int i = 0; i < s.size(); i++ ) {
				isPalindrome[i][i] = true;
				result = s.substr(i, 1);
			}

			// Initialize if palindrome string is size 2
			for( int i = 0; i < s.size()-1; i++ ) {
				isPalindrome[i][i+1] = (s[i] == s[i+1]);
				if( s[i] == s[i+1] )
					result = s.substr(i, 2);
			}

			// Find if the rest is a palindrome
			for( int length = 2; length < s.size(); length++ ) {
				for( int i = 0; i < s.size() - length; i++ ) {
					if( isPalindrome[i+1][i+length-1]) {
						isPalindrome[i][i+length] = (s[i] == s[i+length]);
						if(s[i] == s[i+length])
							result = s.substr(i, length+1);
					}
				}
			}
			return result;
		}
};
