class Solution {
	public:
		bool detectCapitalUse(string word) {
			if(word.length()<2)
				return true;
			int Upper=word[0]>='a'?0:word[1]>='a'?0:1;
			for (int i=1; i<word.length(); ++i)
				if (Upper&&word[i]>='a'||!Upper&&word[i]<='Z')
					return false;
			return true;
		}
};
