/*
	˼����һ�����д�������㷨����Ȼ����259/286��case��������Ȼ�Ǵ���ġ����磺cbacdcbc
	��ʼ�����룬���һ�����������ƾ�о�ȥ���㷨�����������пյ�С¹��ײ��������ȥ�������ġ�
	˼������һ�������߼��ģ�һ��Ҫ��Ϊʲô����˼����

	�������ȵ�˼·�����ڳ��ֵ�һ���ַ����ض��������ж���е�һ��������󣬵���Ҫ��ô�����أ����������������ȻҪ����С������ַ�˼��������һ����
	���Ƿ������������������в�ͨ�ġ��ı�˼·�����մ����ҵ�˳���������
	���ݴ�����Ҫ�����ǿ���˼���������ǰ�ַ����滹����֣���ô����ɾ�����������һ������ô���뱣����Ҫ�����ֵ�����С����ô�ض�Ҫʹ��������ǰ���п���ɾ���ұȵ�ǰ
	����ַ�ȥ����
*/
class Solution {
	public:
		string removeDuplicateLetters(string s) {
			vector<vector<int>>m(26);
			vector<int>pos;
			int i,maxpos=-1;
			for(i=0; i<s.length(); ++i)
				m[s[i]-'a'].push_back(i);
			for(i=0; i<26; ++i)
				if(!m[i].empty()) {
					auto it=upper_bound(m[i].begin(),m[i].end(),maxpos);
					if(it==m[i].end())
						--it;
					else
						maxpos=*it;
					pos.push_back(*it);
				}
			sort(pos.begin(),pos.end());
			string res;
			for(auto &a:pos)
				res+=s[a];
			return res;
		}
};


class Solution {
	public:
		string removeDuplicateLetters(string s) {
			vector<int> cand(256, 0);
			vector<bool> visited(256, false);
			for (char c : s)
				cand[c]++;
			string result = "0";
			for (char c : s) {
				cand[c]--;
				if (visited[c]) continue;
				while (c < result.back() && cand[result.back()]) {
					visited[result.back()] = false;
					result.pop_back();
				}
				result += c;
				visited[c] = true;
			}
			return result.substr(1);
		}
};
