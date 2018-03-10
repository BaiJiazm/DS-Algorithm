class Solution {
	public:
		bool judgeSquareSum(int c) {
			int begin=0;
			int end=(int)sqrt(c);
			for(; begin<=end; ++begin) {
				int t1=begin*begin;
				int t2=(int)sqrt(c-t1);
				if(t1+t2*t2==c)
					return true;
			}
			return false;
		}
};
