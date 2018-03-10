class Solution {
	public:
		bool isScramble(string s1, string s2) {
			int len1=s2.length();
			int len2=s2.length();
			if (len1!=len2)
				return false;
			if (len1==0||len1==1&&s1[0]==s2[0])
				return true;
			if (len1==1&&s1[0]!=s2[0])
				return false;
			this->s1=s1;
			this->s2=s2;
			int mid1=len1/2,mid2=len2/2;
			return isSrab(0,mid1-1,0,mid2-1)&&isSrab(mid1,len1-1,mid2,len2-1)
			       ||isSrab(0,mid1,mid2,len2-1)&&isSrab(mid1+1,len1-1,0,mid2-1);
		}
	private:
		string s1;
		string s2;
		bool isSrab(int index11,int index12,int index21,int index22) {
			if (index11==index12&&s1[index11]==s2[index21])
				return true;
			int mid1=(index11+index12)/2;
			int mid2=(index21+index22)/2;
			return isSrab(index11,mid1,index21,mid2)&&isSrab(mid1+1,index12,mid2+1,index22)
			       ||isSrab(index11,mid1-1,mid2+1,index22)&&isSrab(mid1,index12,mid2,index22);
		}
};
