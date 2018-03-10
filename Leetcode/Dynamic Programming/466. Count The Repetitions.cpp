#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*	
	�����Ŀ��һ����������ˣ���������Եģ�����һ��˼·��ʾ�󣬿��Լ���ȫ����ˡ�
	Ҫ����˼����һ�����Ŀ�أ����ȱ����ǲ����ܵģ�������̫���������ǿ϶�Ӧ��ȥ������������ԣ��������ַ������ظ��ԡ�
	����Ҫ����ת����һ��С��ģ���⣬������ѧ�������⿴�ǲ��ܽ������ģ���Ҫ��һЩʵ����С��˼�������������ɡ�
	���ǵ�ÿ��һ��s1�����һ��Ҫ�ҵ�s2�е��ַ���ʲô�����ᳬ��100��������ø볲ԭ��������𰸡� 
	
	ע�����㣺
	1.���ⲻ���󹫹������У�����̰�ĵ������������
	2.�������ڴ�Խ�籨��ʱ������Ӧ�ÿ����ǲ��Ǳ���д���д���ˡ�
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
