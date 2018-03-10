#include"headFile"

//解法一：二维排序降为一维，求最大子序列。采用DP,算法时间复杂度为O（n^2）
bool cmp (pair<int, int> i, pair<int, int> j) {
	if (i.first == j.first)
		return j.second < i.second;     //好处在于可以将first==first情况过滤掉
	return i.first < j.first;
}

class Solution {
	public:
		int maxEnvelopes(vector<pair<int, int>>& envelopes) {
			int N = envelopes.size();
			vector<int> dp(N, 1);
			int mx = (N == 0) ? 0 : 1;
			sort(envelopes.begin(), envelopes.end(), cmp);
			for (int i = 0; i < N; i++) {
				for (int j = i - 1; j >= 0; j--) {
					if (envelopes[i].second > envelopes[j].second) {
						dp[i] = max(dp[i], dp[j] + 1);
						mx = max(dp[i], mx);
					}
				}
			}
			return mx;
		}
};

/*	解法二：二维排序降为一维，求最大子序列。采用DP+二分搜索,算法时间复杂度为O（nlogn）
	二分搜索DP思想为：以元素个数表示序列长度，dp[i]值表示长度为i+1时所需最小高度。
	方法为：如果递增则添加元素，否则替换掉长度相同时的最小高度。
*/
class Solution {
	public:
		int maxEnvelopes(vector<pair<int, int>>& envelopes) {
			auto cmp = [](pair<int, int> a, pair<int, int> b) {
				return a.first==b.first?a.second>b.second:a.first<b.first;
			};
			sort(envelopes.begin(), envelopes.end(), cmp);
			vector<int> dp;
			for(auto val: envelopes) {
				if(dp.size()==0 || val.second>dp.back()) dp.push_back(val.second);
				else {
					int left = 0, right = dp.size()-1;
					while(left <= right) {
						int mid = (left+right)/2;
						if(dp[mid] < val.second) left = mid+1;
						else right = mid-1;
					}
					dp[left] = val.second;
				}
			}
			return dp.size();
		}
};


bool cmpPair(const pair<int,int>&p1,const pair<int,int>&p2) {
	return p1.first==p2.first?p1.second<p2.second:p1.first<p2.first;
}

void testSortPair() {
	vector<pair<int, int>>vct;
	vct.push_back({3,3});
	vct.push_back({1,1});
	vct.push_back({2,1});
	vct.push_back({1,2});
	vct.push_back({3,1});
	vct.push_back({2,2});

	for(auto a:vct) {
		cout<<a.first<<" "<<a.second<<endl;
	}

	cout<<endl;

	//对pair<int,int>两者一样
	sort(vct.begin(),vct.end());
	sort(vct.begin(),vct.end(),cmpPair);

	for(auto a:vct) {
		cout<<a.first<<" "<<a.second<<endl;
	}

	cout<<endl;
}

int main() {
//	testSortPair();
	vector<pair<int, int> > envelopes;
	envelopes.push_back({5,4});
	envelopes.push_back({6,4});
	envelopes.push_back({6,7});
	envelopes.push_back({2,3});
	Solution s;
	cout<<s.maxEnvelopes(envelopes)<<endl;
	return 0;
}
