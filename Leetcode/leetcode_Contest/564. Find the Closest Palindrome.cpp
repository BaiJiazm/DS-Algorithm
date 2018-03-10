#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main1() {
	unsigned long maxull=(0-1);
	long maxll=maxull>>1;
	string str;
	stringstream ss;
	ss<<maxull<<" "<<maxll;
	ss>>str;
	cout<<"maxull="<<str<<", length="<<str.length()<<endl;

	ss>>str;
	cout<<"maxll="<<str<<", length="<<str.length()<<endl;

	return 0;
}

/*
	此题不需要什么算法，但是contest时候没有做出来！！！
	看来还是太naive了，不要把自己约束在一些下意识中。第一，绝对不可能是暴力，到这个时候，如果第一反应还是暴力，就真的太弱了。
	一个字符串，当然是考虑前半串长度，转为long进行运算，考虑不同情况的完备性 
*/ 
class Solution {
	public:
		string nearestPalindromic(string n) {
			int len=n.length();
			set<long long >candidates;
			candidates.insert((long long)(pow(10,len)+1));
			candidates.insert((long long)(pow(10,len-1)-1));
			long long prefix=stol(n.substr(0,(len+1)>>1));
			for (int i=-1; i<=1; ++i) {
				string p=to_string(prefix+i);
				string pp=p+string(p.rbegin()+(len&1),p.rend());
				candidates.insert(stol(pp));
			}
			long long num=stol(n);
			long long minDiff=LONG_MAX,diff,minVal;
			candidates.erase(num);
			for(set<long long>::iterator it=candidates.begin(); it!=candidates.end(); ++it) {
				long long val=*it;
				diff=abs(val-num);
				if(diff<minDiff) {
					minDiff=diff;
					minVal=val;
				} else if(diff=minDiff)
					minVal=min(minVal,val);
			}
			return to_string(minVal);
		}
};

