/*
	��Ŀ���壺���ַ������������������ֵ��е����е��ʵ�����λ��
	ע�⣺��Ŀû��ǿ��words�е����ݲ����ظ������Գ�������״����"wordgoodgoodgoodbestword"	["word","good","best","good"]	Expected:[8]
	����һ�������ⷨ������hash���м�¼����μ��顣
*/
class Solution {
	public:
		vector<int> findSubstring(string s, vector<string>& words) {
			unordered_map<string, int> counts;
			for (string word : words)
				counts[word]++;
			int n = s.length(), num = words.size(), len = words[0].length();
			vector<int> indexes;
			for (int i = 0; i < n - num * len + 1; i++) {
				unordered_map<string, int> seen;
				int j = 0;
				for (; j < num; j++) {
					string word = s.substr(i + j * len, len);
					if (counts.find(word) != counts.end()) {
						seen[word]++;
						if (seen[word] > counts[word])
							break;
					} else break;
				}
				if (j == num) indexes.push_back(i);
			}
			return indexes;
		}
};


/*
	�����Ŀһ��ʼû����Ϊ��Ŀ����û����ȷwords���Ƿ����ظ��ַ��������Խⷨ��һ��������˼·����ȷ�ġ�

	�ٴ������Լ�����Ҫ��������ν��ԭ�Ӳ����Ķ��ټ�ʱ�俼���ж�̫�
	ÿ��hashû�й�ϵ�����ж�û�й�ϵ�����˺ܶ�/*%û�й�ϵ����Щ������Ҫ��ֻҪ�㷨Ч�ʸߣ�˼·�����������������Ǿ���������
*/

class Solution {
	public:
		vector<int> findSubstring(string s, vector<string>& words) {
			unordered_map<string,int>dicts;
			for(auto&a:words)
				++dicts[a];
			vector<int>ans;
			int count=0,len=words[0].length(),begin;
			for(int i=0; i<len; ++i) {
				unordered_map<string,int>seen;
				count=words.size();
				begin=i;
				for(int j=i; j<=(int)s.length()-len; j+=len) {
					string str=s.substr(j,len);
					if(dicts.count(str)) {
						if(++seen[str]<=dicts[str])
							--count;
						else {
							while(seen[str]>dicts[str]) {
								string temstr=s.substr(begin,len);
								if(--seen[temstr]<dicts[temstr])
									++count;
								begin+=len;
							}
						}
						if(count==0)
							ans.push_back(begin);
					} else {
						seen.clear();
						count=words.size();
						begin=j+len;
					}
				}
			}
			return ans;
		}
};


//���ϱ�һ����discuss���ⷨ
class Solution {
	public:

// travel all the words combinations to maintain a window
// there are wl(word len) times travel
// each time, n/wl words, mostly 2 times travel for each word
// one left side of the window, the other right side of the window
// so, time complexity O(wl * 2 * N/wl) = O(2N)
		vector<int> findSubstring(string S, vector<string> &L) {
			vector<int> ans;
			int n = S.size(), cnt = L.size();
			if (n <= 0 || cnt <= 0) return ans;

			// init word occurence
			unordered_map<string, int> dict;
			for (int i = 0; i < cnt; ++i) dict[L[i]]++;

			// travel all sub string combinations
			int wl = L[0].size();
			for (int i = 0; i < wl; ++i) {
				int left = i, count = 0;
				unordered_map<string, int> tdict;
				for (int j = i; j <= n - wl; j += wl) {
					string str = S.substr(j, wl);
					// a valid word, accumulate results
					if (dict.count(str)) {
						tdict[str]++;
						if (tdict[str] <= dict[str])
							count++;
						else {
							// a more word, advance the window left side possiablly
							while (tdict[str] > dict[str]) {
								string str1 = S.substr(left, wl);
								tdict[str1]--;
								if (tdict[str1] < dict[str1]) count--;
								left += wl;
							}
						}
						// come to a result
						if (count == cnt) {
							ans.push_back(left);
							// advance one word
							tdict[S.substr(left, wl)]--;
							count--;
							left += wl;
						}
					}
					// not a valid word, reset all vars
					else {
						tdict.clear();
						count = 0;
						left = j + wl;
					}
				}
			}

			return ans;
		}
};
