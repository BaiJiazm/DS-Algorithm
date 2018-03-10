#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*	
	这个题目差一点就做出来了，方向还是算对的，看了一点思路提示后，靠自己完全解决了。
	要怎样思考着一类的题目呢？首先暴力是不可能的，数据量太大；所以我们肯定应该去分析此题的特性，就是其字符串的重复性。
	但是要怎样转换成一个小规模问题，或者数学方法，光看是不能解决问题的，还要用一些实例从小处思考，启发，归纳。
	考虑到每找一个s1，其第一个要找的s2中的字符是什么，不会超过100种情况，用鸽巢原理分析出答案。 
	
	注意两点：
	1.本题不是求公共子序列，而是贪心的求包含个数。
	2.当遇到内存越界报错时，首先应该看看是不是变量写错或写反了。
*/ 
class Solution {
	public:
		int getMaxRepetitions(string s1, int n1, string s2, int n2) {
			vector<int>nextIndex(105,0);
			vector<int>cover(105,0);
			int i,j,ni;
			for(i=1,ni=0; i<=n1&&!nextIndex[ni]; ++i) {
				nextIndex[ni]=i;
				cover[i]=cover[i-1];
				for(j=0; j<s1.length(); ++j) {
					if(s1[j]==s2[ni])
						++ni;
					if(ni==s2.length()) {
						ni=0;
						++cover[i];
					}
				}
			}
			int covers2;
			if(!nextIndex[ni])
				covers2=cover[i-1];
			else {
				int units1=cover[i-1]-cover[nextIndex[ni]-1];
				int unitLen=i-nextIndex[ni];
				int segNum=(n1-nextIndex[ni]+1)/unitLen;
				int leave=n1-segNum*unitLen;
				covers2=segNum*units1+cover[leave];
			}
			return covers2/n2;
		}
};

int main() {
	Solution s;
	string s1="lovelive";
	string s2=s1;
	cout<<s.getMaxRepetitions(s1,1000,s2,1);
	return 0;
}
