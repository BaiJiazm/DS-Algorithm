class Solution {
	public:
		string reverseVowels(string s) {
			int right=s.length()-1;
			int left=0;
			while(left<right) {
				while(left<right&&!isVowel(s[left]))
					++left;
				while(right>left&&!isVowel(s[right]))
					--right;
				if (left<right) {
					char temch=s[left];
					s[left++]=s[right];
					s[right--]=temch;
				}
			}
			return s;
		}
		bool isVowel(char ch) {
			return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'
			       ||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U';
		}
};

class Solution {
	public:
		string reverseVowels(string s) {
			int dict[256] = {0};
			dict['a'] = 1, dict['A'] = 1;
			dict['e'] = 1, dict['E'] = 1;
			dict['i'] = 1, dict['I'] = 1;
			dict['o'] = 1, dict['O'] = 1;
			dict['u'] = 1, dict['U'] = 1;
			int start = 0, end = (int)s.size() - 1;
			while(start < end) {
				while(start < end && dict[s[start]] == 0) start++;
				while(start < end && dict[s[end]] == 0) end--;
				swap(s[start],s[end]);
				start++;
				end--;
			}
			return s;
		}
};

class Solution {
	public:
		string reverseVowels(string s) {
			int i=0,j=s.length()-1;
			while(i<j) {
				i=s.find_first_of("aeiouAEIOU",i);
				j=s.find_last_of("aeiouAEIOU",j);
				if (i<j)
					swap(s[i++],s[j--]);
			}
			return s;
		}
};
