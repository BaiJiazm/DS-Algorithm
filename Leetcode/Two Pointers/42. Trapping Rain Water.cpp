class Solution {
	public:
		int trap(vector<int>& height) {
			if (height.size()<3)
				return 0;
			int ans=0;
			vector<int>::iterator left=height.begin(),right=height.end()-1;
			while(left+1<right) {
				if (*left<=*right) {
					ans+=max(*left-*(left+1),0);
					*(left+1)=max(*left,*(left+1));
					++left;
				} else {
					ans+=max(*right-*(right-1),0);
					*(right-1)=max(*right,*(right-1));
					--right;
				}
			}
			return ans;
		}
};
