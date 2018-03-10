/*
    要求必须在O(n)时间内求解，必须使用hash方法
    方法一：浪费空间，扩展  time:13ms
*/
class Solution {
	public:
		int longestConsecutive(vector<int> &num) {
			unordered_map<int, int> m;
			int r = 0;
			for (int i : num) {
				if (m[i]) continue;
				r = max(r, m[i] = m[i + m[i + 1]] = m[i - m[i - 1]] = m[i + 1] + m[i - 1] + 1);
			}
			return r;
		}
};

//方法二：删除法，  time:9ms
class Solution {
	public:
		int longestConsecutive(vector<int>& nums) {

			unordered_set<int> theSet;
			for (int i = 0 ; i < nums.size(); i++) {
				theSet.insert(nums[i]);
			}

			int longest = 0;
			while (theSet.size() > 0 ) {

				int tmp = *theSet.begin();
				theSet.erase(tmp);

				int cnt = 1;

				int tmpR = tmp + 1;
				while (theSet.count(tmpR)) {
					cnt++;
					theSet.erase(tmpR);
					tmpR++;
				}

				int tmpL = tmp - 1;
				while (theSet.count(tmpL)) {
					cnt++;
					theSet.erase(tmpL);
					tmpL--;
				}

				longest = max( longest, cnt);

			}

			return longest;
		}
};
