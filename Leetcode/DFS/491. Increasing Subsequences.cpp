/*
    深度优先+回溯算法，但是没有考虑重复序列。错误
*/
class Solution {
	public:
		vector<vector<int>> findSubsequences(vector<int>& nums) {
			vector<vector<int>>ans;
			vector<int>sequence;
			findSub(ans,nums,0,sequence);
			return ans;
		}
		void findSub(vector<vector<int>>&ans,vector<int>&nums,int index,vector<int>&sequence) {
			int size=nums.size();
			for (; index<size; ++index) {
				if (sequence.empty()||sequence.back()<=nums[index]) {
					sequence.push_back(nums[index]);
					if (sequence.size()>=2)
						ans.push_back(sequence);
					findSub(ans,nums,index+1,sequence);
					sequence.pop_back();
				} else
					findSub(ans,nums,index+1,sequence);
			}
		}
};

/*
    深度优先+回溯算法，利用set<vector<int>>插入时可以忽略掉重复的，所以正确。
*/
class Solution {
	public:
		vector<vector<int>> findSubsequences(vector<int>& nums) {
			set<vector<int>> res;
			vector<int> seq;
			helper(nums, seq, res, 0);

			return vector<vector<int>>(res.begin(), res.end());
		}

		void helper(vector<int> &nums, vector<int>& seq, set<vector<int>>& result, int index) {
			if (seq.size() >= 2)
				result.insert(seq);

			for (int i=index; i<nums.size(); ++i) {
				if (seq.size() == 0 || nums[i] >= seq.back()) {
					seq.push_back(nums[i]);
					helper(nums, seq, result, i+1);
					seq.pop_back();
				}
			}
		}
};

/*
    方法同上，由于STL中没有对vector<int>的Hash函数，所以上述方法只能用set，不能用unordered_set，下述方法转为string
*/
class Solution {
	public:
		vector<vector<int>> findSubsequences(vector<int>& nums) {
			vector<vector<int> > result;
			unordered_set<string> hash;
			string path = "";
			dfs(result, hash, path, nums, INT_MIN, 0);
			return result;
		}

	private:
		void dfs(vector<vector<int> >& result, unordered_set<string>& hash, string& path, vector<int>& nums, int prev, int pos) {
			if(path.find_first_of(' ') != string::npos && !hash.count(path)) {
				hash.insert(path);
				vector<int> values;
				parse(path, values);
				result.push_back(values);
			}
			if(pos == nums.size()) return;
			if(nums[pos] >= prev) {
				string temp = (path.empty() ? "" : " ") + to_string(nums[pos]);
				path += temp;
				dfs(result, hash, path, nums, nums[pos], pos+1);
				path.erase(path.size()-temp.size());
			}
			dfs(result, hash, path, nums, prev, pos+1);
		}

		void parse(string& path, vector<int>& values) {
			istringstream is(path);
			for(int num; is >> num; )
				values.push_back(num);
		}
};

/*
    最好的算法，time:212ms    beats 99.99%
*/
class Solution {
	public:
		vector<vector<int>> ret;
		vector<int> prev;
		vector<int> subSeq;
		
		void dfs(vector<int>& nums, int idx) {
			if(subSeq.size() > 1)ret.push_back(subSeq);
			for (int i = idx; i < nums.size(); i++) {
				//1. The first condition is about duplication.
				//if prev[i] is in the avail range[idx, nums.size()), i should be ignored
				//2. other conditions are about increasement.
				//idx 表示当前的序列中最后一个元素的位置，idx<=prev[i]说明前面已经加入过等于这个数字的情况
				if ((idx > prev[i]) && (subSeq.size() == 0 || subSeq[subSeq.size() - 1] <= nums[i])) {
					subSeq.push_back(nums[i]);
					dfs(nums, i + 1);
					subSeq.pop_back();
				}
			}
		}
		
		vector<vector<int>> findSubsequences(vector<int>& nums) {
			int subSeq = 0;
			prev = vector<int>(nums.size(), -1);
			vector<int> last(201,-1);

			/*
				标记每一个位置前面相同数字的位置
			*/
			for (int i = 0 ; i < nums.size() ; i++) {
				prev[i] = last[nums[i] + 100];
				last[nums[i] + 100] = i;
			}
			dfs(nums,  0);
			return ret;
		}
};
