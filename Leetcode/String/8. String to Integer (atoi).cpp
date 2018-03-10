#include<iostream>
using namespace std;

/*
	要考虑非常全面的题目。值的收藏！ 
	卡在了三个地方：1	+1		 9223372036854775809（>long long）
	在平时要让代码更简洁一点，但是并不意味着就能够一行代码代表很多情况，一般是不现实的，而且肯定会出错，
	在考试时，最好按照逻辑来，将一个一个case逐次过滤，清晰准确才是最重要的。 
*/ 
class Solution {
	public:
		int myAtoi(string str) {
			int pos=0;
			int len=str.length();
			long long ans=0;
			int sign=1;
			for (; pos<len&&str[pos]==' '; ++pos)
				;
			if (pos==len&&(pos==0||str[pos]==' '))
				return 0;
			if (str[pos]=='-') {
				sign=-1;
				++pos;
			} else if (str[pos]=='+')
				++pos;
			for (; pos<len&&str[pos]>='0'&&str[pos]<='9'; ++pos) {
				ans=ans*10+str[pos]-'0';
				if (ans>INT_MAX)
					return sign==1?INT_MAX:INT_MIN;
			}
			return sign*ans;
		}
};

int main() {
	Solution s;
	cout<<s.myAtoi("9223372036854775809")<<endl;
	return 0;
}
