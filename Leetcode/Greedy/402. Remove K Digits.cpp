#include<iostream>
#include<string>
using namespace std;

/*
	���Ȼ������ع�һ��˼�����̷�����
	˼���Ĺ��̲��Ƕ�����Ŀ���ֺ��������������ǴӲ�ͬ�ĽǶ�ȥ�۲죬���롣
	һ�����Ƕ�����򵥵�һЩ������֣�ɾ��k��������С�����ȵ�ɾ��һ��������С��Ȼ���ٿ����Ƿ��Ǿֲ����ŵ�ȫ�����Ž⡣����̰���㷨��һ��˼�����̡� 
	һ����Щ���ʱȽ���֤�������ǿ��Բ²⡣ 
	ע�⣺
	1.�ٴ����ѣ�ƽʱ����ʹ�Լ�˼���ĸ�Ϊȫ��һЩ�������Ժ��Ի�Դ���� 
	2.������˼ά������������ 
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
