/*
	sweep line类型的题目和运用堆或红黑树方法一般性经典题目。
	这种具有平行对偶信息的题目，一般都是有记录和擦除记录的过程。在这过程中得到相应答案。
	通过x坐标排序后，逐次扫描，先后将矩形高度加入到一个有序结构（multset、heap、mutlimap等）和从其中删除。 
*/
class Solution {
	public:
		vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
			vector<pair<int,int>>height;
			for(auto &b:buildings) {
				height.push_back({b[0],-b[2]});
				height.push_back({b[1],b[2]});
			}
			sort(height.begin(),height.end());
			vector<pair<int,int>>ans;
			multiset<int>mset;
			mset.insert(0);
			int pre=0,cur=0;
			for(auto &b:height) {
				if(b.second<0)
					mset.insert(-b.second);
				else
					mset.erase(mset.find(b.second));
				cur=*mset.rbegin();
				if(cur!=pre) {
					ans.push_back({b.first,cur});
					pre=cur;
				}
			}
			return ans;
		}
};
