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
	���ⲻ��Ҫʲô�㷨������contestʱ��û��������������
	��������̫naive�ˣ���Ҫ���Լ�Լ����һЩ����ʶ�С���һ�����Բ������Ǳ����������ʱ�������һ��Ӧ���Ǳ����������̫���ˡ�
	һ���ַ�������Ȼ�ǿ���ǰ�봮���ȣ�תΪlong�������㣬���ǲ�ͬ������걸�� 
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

