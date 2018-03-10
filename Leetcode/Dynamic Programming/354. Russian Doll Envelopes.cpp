#include"headFile"

//�ⷨһ����ά����Ϊһά������������С�����DP,�㷨ʱ�临�Ӷ�ΪO��n^2��
bool cmp (pair<int, int> i, pair<int, int> j) {
	if (i.first == j.first)
		return j.second < i.second;     //�ô����ڿ��Խ�first==first������˵�
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

/*	�ⷨ������ά����Ϊһά������������С�����DP+��������,�㷨ʱ�临�Ӷ�ΪO��nlogn��
	��������DP˼��Ϊ����Ԫ�ظ�����ʾ���г��ȣ�dp[i]ֵ��ʾ����Ϊi+1ʱ������С�߶ȡ�
	����Ϊ��������������Ԫ�أ������滻��������ͬʱ����С�߶ȡ�
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

	//��pair<int,int>����һ��
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
