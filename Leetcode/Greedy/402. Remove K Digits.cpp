#include<iostream>
#include<string>
using namespace std;

/*
	首先还是来回顾一下思考过程方法。
	思考的过程不是盯着题目数字和描述发呆。而是从不同的角度去观察，切入。
	一般我们都从最简单的一些情况入手，删掉k个数字最小，首先得删掉一个数字最小，然后再考虑是否是局部最优到全局最优解。这是贪心算法的一般思考过程。 
	一般有些性质比较难证明，但是可以猜测。 
	注意：
	1.再次提醒，平时尽量使自己思考的更为全面一些，否则以后考试会吃大亏。 
	2.多跳出思维想想额外情况。 
*/ 
class Solution {
	public:
		string removeKdigits(string num, int k) {
			string res;
			int i;
			for(i=0; i<num.length()&&k>0; --k) {
				while(i<num.length()&&(res.empty()||res.back()<=num[i]))
					res.push_back(num[i++]);
				res.pop_back();
				if(res.empty()) {
					while(i<num.length()&&num[i]=='0')
						++i;
				}
			}
			res+=num.substr(i);
			return k>=res.length()?"0":res.substr(0,res.length()-k);
		}
};

int main() {
	string num="11111000";
	Solution s;
	cout<<s.removeKdigits(num,3)<<endl;
	return 0;
}
