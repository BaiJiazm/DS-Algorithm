#include<iostream>
using namespace std;

/*
	Ҫ���Ƿǳ�ȫ�����Ŀ��ֵ���ղأ� 
	�����������ط���1	+1		 9223372036854775809��>long long��
	��ƽʱҪ�ô�������һ�㣬���ǲ�����ζ�ž��ܹ�һ�д������ܶ������һ���ǲ���ʵ�ģ����ҿ϶������
	�ڿ���ʱ����ð����߼�������һ��һ��case��ι��ˣ�����׼ȷ��������Ҫ�ġ� 
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
